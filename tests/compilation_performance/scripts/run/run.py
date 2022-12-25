import argparse
from collections import OrderedDict
from enum import Enum
import json
import logging
import os
import re
import shutil
import statistics
import subprocess
import time
from typing import List
from distutils.version import StrictVersion


MIN_NINJA_VERSION = StrictVersion('1.10.0')


logger = logging.getLogger(__name__)

handler = logging.StreamHandler()
handler.setFormatter(logging.Formatter('[%(levelname)s] %(message)s'))
logger.addHandler(handler)


class Compiler(Enum):
    CLANG = 0,
    MSVC = 1,


class Bindings(Enum):
    NONE = 0,
    MANUAL = 1,
    COIL = 2,


class BuildConfiguration:
    def __init__(self, compiler, bindings, unity, pch, extern):
        self.compiler = compiler
        self.bindings = bindings
        self.unity = unity
        self.pch = pch
        self.extern = extern

    @property
    def name(self):
        return '{}-{}{}{}{}'.format(self.compiler.name, self.bindings.name, '-Unity' if self.unity else '', '-PCH' if self.pch else '', '-Extern' if self.extern else '')


class Options:
    def __init__(self, trace: bool, compilation: bool, clean_build: bool, full_build: bool):
        self.trace = trace
        self.compilation = compilation
        self.clean_build = clean_build
        self.full_build = full_build


class Settings:
    def __init__(self, options: Options, compiler_options: List[str], bindings_options: List[str],
                 unity_options: List[bool], pch_options: List[bool], extern_options: List[bool], count: int, full_build_count: int, cmake_root: str, build_directory: str,
                 report_root_directory: str, report_filename: str, merged_trace_filename: str,
                 symbols_filename: str, compilation_object: str):
        self.options = options
        self.count = count
        self.full_build_count = full_build_count
        self.cmake_root = cmake_root
        self.build_directory = build_directory
        self.report_root_directory = report_root_directory
        self.report_filename = report_filename
        self.merged_trace_filename = merged_trace_filename
        self.symbols_filename = symbols_filename
        self.compilation_object = compilation_object

        self.configurations: List[BuildConfiguration] = []
        for unity in unity_options:
            for pch in pch_options:
                for extern in extern_options:
                    for compiler_str in compiler_options:
                        for bindings_str in bindings_options:
                            compiler = Compiler[compiler_str.upper()]
                            bindings = Bindings[bindings_str.upper()]
                            self.configurations.append(BuildConfiguration(compiler, bindings, unity, pch, extern))


class DurationStats:
    def __init__(self, durations):
        self.mean = statistics.mean(durations)
        self.median = statistics.median(durations)
        self.min = min(durations)
        self.max = max(durations)

class ProfilingResults:
    def __init__(self, compilation_stats: DurationStats, full_build_stats:DurationStats, symbols_count: int, trace_stats):
        self.compilation_stats = compilation_stats
        self.full_build_stats = full_build_stats
        self.symbols_count = symbols_count
        self.trace_stats = trace_stats


BINDINGS_CMD_ARGUMENTS = {
    Bindings.NONE: '',
    Bindings.MANUAL: '-DCOIL_COMPILATION_TIME_BENCHMARK_WITH_MANUAL=ON',
    Bindings.COIL: '-DCOIL_COMPILATION_TIME_BENCHMARK_WITH_COIL=ON',
}


settings: Settings = None


def execute_command(command: str, cwd: str = None):
    if cwd:
        logger.debug('Executing "{}" in "{}"'.format(command, cwd))
    else:
        logger.debug('Executing "{}"'.format(command))

    start_time = time.time()
    process = subprocess.Popen(command, cwd=cwd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, universal_newlines=True)
    stdout, stderr = process.communicate()
    end_time = time.time()

    duration = end_time - start_time
    logger.debug('Command finished in {} seconds'.format(duration))

    if process.returncode != 0:
        for line in stdout.splitlines():
            logger.critical(line)
        for line in stderr.splitlines():
            logger.critical(line)

        raise RuntimeError('Command finished with error code {}'.format(process.returncode))
    
    return stdout, duration


def find_db_entry(compilation_commands, output_file_ending):
    if isinstance(output_file_ending, str):
        entry_filter = lambda entry: entry['output'].endswith(output_file_ending)
    else:
        entry_filter = lambda entry: any([entry['output'].endswith(ending) for ending in output_file_ending])

    entry = next(filter(entry_filter, compilation_commands), None)
    assert entry is not None
    return entry


def execute_db_command(entry):
    _, duration = execute_command(entry['command'], entry['directory'])
    return duration


def run_cmake(configuration: BuildConfiguration, clean: bool, trace: bool):
    build_dir = os.path.join(settings.build_directory, configuration.name)

    if clean and os.path.exists(build_dir):
        shutil.rmtree(build_dir)

    params = {
        'root': settings.cmake_root,
        'build_dir': build_dir,
        'unity': '-DCMAKE_UNITY_BUILD=ON' if configuration.unity else '',
        'pch': '-DCOIL_COMPILATION_TIME_BENCHMARK_PCH=ON' if configuration.pch else '',
        'extern': '-DCOIL_COMPILATION_TIME_BENCHMARK_EXTERN_TEMPLATES=ON' if configuration.extern else '',
        'bindings': BINDINGS_CMD_ARGUMENTS[configuration.bindings],
        'trace': '-DCOIL_COMPILATION_TIME_BENCHMARK_TRACE=ON' if trace else '-DCOIL_COMPILATION_TIME_BENCHMARK_TRACE=OFF'
    }

    cmake_command = 'cmake -B "{build_dir}" -DCOIL_COMPILATION_TIME_BENCHMARK=ON {trace} {bindings} {unity} {pch} {extern} -GNinja "{root}"'.format(**params)

    COMPILER_IDS = {
        Compiler.MSVC: 'cl',
        Compiler.CLANG: 'clang-cl',
    }

    os.environ['CC'] = COMPILER_IDS[configuration.compiler]
    os.environ['CXX'] = COMPILER_IDS[configuration.compiler]
    
    execute_command(cmake_command)


def merge_traces(traces):
    if not traces:
        return None, None

    merged_trace = traces[0] # no copy
    
    for trace in traces:
        if len(trace) != len(merged_trace):
            print('Mismatched number of trace events')
            return

    stats = {}

    for i in range(len(merged_trace)):
        begin_ts = []
        end_ts = []

        merged_event = merged_trace[i]
        
        if 'name' in merged_event and merged_event['name'].startswith('Total '):
            continue

        if merged_event['ph'] == 'X':
            for trace in traces:
                event = trace[i]

                if 'name' not in event:
                    print('ERROR! No name in event {}'.format(i))
                    return

                if ('args' in event) != ('args' in merged_event):
                    print('ERROR! Args presence varies in event {}'.format(i))
                    return

                if event['name'] != merged_event['name']:
                    print('ERROR! Mismatched event name')
                    return
                
                if 'args' in event and event['args'] != merged_event['args']:
                    print('ERROR! Mismatched event args')
                    return

                ts = event['ts']
                dur = event['dur']

                begin_ts.append(ts)
                end_ts.append(ts + dur)

            ts = statistics.median(begin_ts)
            dur = statistics.median(end_ts) - ts
            merged_event['ts'] = int(ts)
            merged_event['dur'] = int(dur)
            
            name = merged_event['name']
            if name not in stats:
                stats[name] = []
            stats[name].append(merged_event['dur'])

    for name, values in stats.items():
        stats[name] = sum(values)
    
    stats = OrderedDict(sorted(stats.items()))
    
    return merged_trace, stats


SYMBOL_NAME_REGEX = re.compile(r'.*SECT.*notype.*External.*\| (.*)')


def find_symbols(compilation_commands):
    entry = find_db_entry(compilation_commands, settings.compilation_object)
    object_file = os.path.join(entry['directory'], entry['output'])
    output, _ = execute_command('dumpbin /symbols "{}"'.format(object_file))

    symbols = []
    for line in output.splitlines():
        m = SYMBOL_NAME_REGEX.match(line)
        if m:
            symbols.append(m.group(1))

    symbols.sort()
    logger.debug('Found {} symbols'.format(len(symbols)))

    return symbols


def profile_compilation_command(compilation_commands, configuration: BuildConfiguration):
    durations = []
    traces = []

    execute_db_command(find_db_entry(compilation_commands, 'ClassWithBindings0.h')) # generate classes

    if configuration.pch:
        execute_db_command(find_db_entry(compilation_commands, 'cmake_pch.cxx.obj'))

    entry = find_db_entry(compilation_commands, settings.compilation_object)
    
    object_file = os.path.join(entry['directory'], entry['output'])
    trace_file = object_file.replace('.obj', '.json')
    logger.debug('Using trace file: {}'.format(trace_file))

    for _ in range(settings.count):
        duration = execute_db_command(entry)
        durations.append(duration)
        if settings.options.trace and os.path.exists(trace_file):
            with open(trace_file, 'r') as f:
                trace = json.load(f)['traceEvents']
                logger.debug('Found {} events'.format(len(trace)))
                traces.append(trace)

    logger.info('    Merging traces...')
    merged_trace, trace_stats = merge_traces(traces)

    return DurationStats(durations), merged_trace, trace_stats


def profile_full_build(build_dir):
    durations = []

    for _ in range(settings.full_build_count):
        execute_command('ninja clean', cwd=build_dir)
        _, duration = execute_command('ninja', cwd=build_dir)
        durations.append(duration)
    return DurationStats(durations)


def run_configuration(configuration: BuildConfiguration):
    build_dir = os.path.join(settings.build_directory, configuration.name)
    configuration_report_directory = os.path.join(settings.report_root_directory, configuration.name)
    
    os.makedirs(configuration_report_directory, exist_ok=True)

    logger.info('    Running CMake...')
    run_cmake(configuration, settings.options.clean_build, settings.options.trace)

    logger.info('    Cleaning...')
    execute_command('ninja clean', cwd=build_dir)

    logger.info('    Generating compilation commands...')
    compilation_commands_json, _ = execute_command('ninja -t compdb', cwd=build_dir)
    with open(os.path.join(build_dir, 'compilation_commands.json'), 'w') as f:
        f.write(compilation_commands_json)
    compilation_commands = json.loads(compilation_commands_json)
    
    compilation_stats, merged_trace, trace_stats = (None, None, None)
    symbols = None
    if settings.options.compilation:
        logger.info('    Profiling compilation...')
        compilation_stats, merged_trace, trace_stats = profile_compilation_command(compilation_commands, configuration)
        
        logger.info('    Finding symbols...')
        symbols = find_symbols(compilation_commands)

        logger.info('    Saving symbols...')
        with open(os.path.join(configuration_report_directory, settings.symbols_filename), 'w') as f:
            f.write('\n'.join(symbols) + '\n')

    full_build_stats = None
    if settings.options.full_build:
        logger.info('    Running CMake...')
        run_cmake(configuration, clean=False, trace=False)

        logger.info('    Profiling full build...')
        full_build_stats = profile_full_build(build_dir)

    logger.info('    Saving profiling results...')
    with open(os.path.join(configuration_report_directory, settings.report_filename), 'w') as f:
        results = ProfilingResults(compilation_stats, full_build_stats, len(symbols) if symbols else None, trace_stats)
        json.dump(results, f, default=lambda o: o.__dict__, indent=4)

    if merged_trace:
        logger.info('    Saving merged trace file...')
        with open(os.path.join(configuration_report_directory, settings.merged_trace_filename), 'w') as f:
            f.write(json.dumps(merged_trace))


def main():
    global settings

    parser = argparse.ArgumentParser(description='Run compilation performance tests')
    parser.add_argument('--settings', '-c', metavar='PATH', required=True, type=str, help='Path to the settings json file')
    parser.add_argument('--verbose', '-v', action='store_true', help='Verbose logs')
    parser.add_argument('--clean', action='store_true', help='Clean build directory before building')
    parser.add_argument('--no-trace', dest='trace', action='store_false', help='Disable trace generation')
    parser.add_argument('--no-compilation', dest='compilation', action='store_false', help='Disable compilation stats')
    parser.add_argument('--no-full-build', dest='full_build', action='store_false', help='Disable full build stats')
    args = parser.parse_args()

    logger.setLevel(logging.DEBUG if args.verbose else logging.INFO)

    options = Options(trace=args.trace, compilation=args.compilation, clean_build=args.clean, full_build=args.full_build)

    settings_dir = os.path.split(args.settings)[0]

    with open(args.settings, 'r') as f:
        fields = json.load(f)

        def update_relative_path(name):
            fields[name] = os.path.join(settings_dir, fields[name])

        update_relative_path('cmake_root')
        update_relative_path('build_directory')
        update_relative_path('report_root_directory')

        settings = Settings(**fields, options=options)

    if 'vsinstalldir' not in os.environ:
        raise RuntimeError("Visual Studio environment isn't set up")

    ninja_version = StrictVersion(execute_command('ninja --version')[0])
    if (ninja_version <= MIN_NINJA_VERSION):
        raise RuntimeError("Unsupported ninja: required min version '{}', found version '{}'".format(MIN_NINJA_VERSION, ninja_version))

    configurations_count = len(settings.configurations)
    logger.info('Configurations found: {}'.format(configurations_count))

    for i, configuration in enumerate(settings.configurations):
        logger.info('Profiling configuration {} ({}/{})'.format(configuration.name, i+1, configurations_count))
        run_configuration(configuration)


if __name__ == '__main__':
    main()
