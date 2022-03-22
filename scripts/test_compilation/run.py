import argparse
from collections import OrderedDict
from enum import Enum
import json
import logging
import os
import re
import statistics
import subprocess
import time
from typing import List


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
    def __init__(self, compiler, bindings, unity):
        self.compiler = compiler
        self.bindings = bindings
        self.unity = unity

    @property
    def name(self):
        return '{}-{}{}'.format(self.compiler.name, self.bindings.name, '-Unity' if self.unity else '')


class Settings:
    def __init__(self, keep_build_results: bool,compiler_options: List[str], bindings_options: List[str],
                 unity_options: List[bool], count: int, cmake_root: str, build_directory: str,
                 report_root_directory: str, report_filename: str, merged_trace_filename: str,
                 symbols_filename: str, compilation_object: str, symbols_object: str):
        self.keep_build_results = keep_build_results
        self.count = count
        self.cmake_root = cmake_root
        self.build_directory = build_directory
        self.report_root_directory = report_root_directory
        self.report_filename = report_filename
        self.merged_trace_filename = merged_trace_filename
        self.symbols_filename = symbols_filename
        self.compilation_object = compilation_object
        self.symbols_object = symbols_object

        self.configurations: List[BuildConfiguration] = []
        for unity in unity_options:
            for compiler_str in compiler_options:
                for bindings_str in bindings_options:
                    compiler = Compiler[compiler_str.upper()]
                    bindings = Bindings[bindings_str.upper()]
                    self.configurations.append(BuildConfiguration(compiler, bindings, unity))


class DurationStats:
    def __init__(self, durations):
        self.mean = statistics.mean(durations)
        self.median = statistics.median(durations)
        self.min = min(durations)
        self.max = max(durations)

class ProfilingResults:
    def __init__(self, compilation_stats: DurationStats, linking_stats: DurationStats, symbols_count: int, trace_stats):
        self.compilation_stats = compilation_stats
        self.linking_stats = linking_stats
        self.symbols_count = symbols_count
        self.trace_stats = trace_stats


BINDINGS_CMD_ARGUMENTS = {
    Bindings.NONE: '',
    Bindings.MANUAL: '-DCOIL_COMPILE_TIME_WITH_MANUAL=ON',
    Bindings.COIL: '-DCOIL_COMPILE_TIME_WITH_COIL=ON',
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


def prepare_configuration(configuration: BuildConfiguration):
    build_dir = os.path.join(settings.build_directory, configuration.name)

    params = {
        'root': settings.cmake_root,
        'build_dir': build_dir,
        'unity': '-DCMAKE_UNITY_BUILD=ON' if configuration.unity else '',
        'bindings': BINDINGS_CMD_ARGUMENTS[configuration.bindings],
    }

    cmake_command = 'cmake -B "{build_dir}" -DCOIL_EXAMPLES=OFF -DCOIL_COMPILE_TIME=ON -DCOIL_COMPILE_TIME_TRACE=ON {bindings} {unity} -GNinja "{root}"'.format(**params)

    os.environ['CC'] = 'clang-cl' if configuration.compiler == Compiler.CLANG else ''
    os.environ['CXX'] = 'clang-cl' if configuration.compiler == Compiler.CLANG else ''
    
    logger.info('    Running CMake...')
    execute_command(cmake_command)

    logger.info('    Running the first build...')
    execute_command('ninja -d keeprsp', cwd=build_dir)

    logger.info('    Generating compilation commands...')
    compilation_commands_json, _ = execute_command('ninja -t compdb', cwd=build_dir)
    with open(os.path.join(build_dir, 'compilation_commands.json'), 'w') as f:
        f.write(compilation_commands_json)
    compilation_commands = json.loads(compilation_commands_json)

    return compilation_commands


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
    entry = find_db_entry(compilation_commands, settings.symbols_object)
    object_file = os.path.join(entry['directory'], entry['output'])
    output, _ = execute_command('dumpbin /symbols "{}"'.format(object_file))

    symbols = []
    for line in output.splitlines():
        m = SYMBOL_NAME_REGEX.match(line)
        if m:
            symbols.append(m.group(1))

    logger.debug('Found {} symbols'.format(len(symbols)))

    return symbols


def profile_compilation_command(compilation_commands):
    durations = []
    traces = []

    entry = find_db_entry(compilation_commands, settings.compilation_object)
    
    object_file = os.path.join(entry['directory'], entry['output'])
    trace_file = object_file.replace('.obj', '.json')
    logger.debug('Using trace file: {}'.format(trace_file))

    for _ in range(settings.count):
        duration = execute_db_command(entry)
        durations.append(duration)
        if os.path.exists(trace_file):
            with open(trace_file, 'r') as f:
                trace = json.load(f)['traceEvents']
                logger.debug('Found {} events'.format(len(trace)))
                traces.append(trace)

    logger.info('    Merging traces...')
    merged_trace, trace_stats = merge_traces(traces)

    return DurationStats(durations), merged_trace, trace_stats


def profile_linking_command(compilation_commands, output_file_ending):
    durations = []

    entry = find_db_entry(compilation_commands, output_file_ending)

    for _ in range(settings.count):
        duration = execute_db_command(entry)
        durations.append(duration)
    return DurationStats(durations)


def run_configuration(configuration: BuildConfiguration):
    logger.info('Profiling configuration {}'.format(configuration.name))

    configuration_report_directory = os.path.join(settings.report_root_directory, configuration.name)
    os.makedirs(configuration_report_directory, exist_ok=True)

    compilation_commands = prepare_configuration(configuration)

    logger.info('    Finding symbols...')
    symbols = find_symbols(compilation_commands)
    symbols_count = len(symbols)

    logger.info('    Saving symbols...')
    with open(os.path.join(configuration_report_directory, settings.symbols_filename), 'w') as f:
        f.write('\n'.join(symbols) + '\n')

    logger.info('    Profiling compilation...')
    compilation_stats, merged_trace, trace_stats = profile_compilation_command(compilation_commands)

    logger.info('    Profiling linking...')
    linking_stats = profile_linking_command(compilation_commands, 'compilation_performance.exe')

    logger.info('    Saving profiling results...')
    with open(os.path.join(configuration_report_directory, settings.report_filename), 'w') as f:
        results = ProfilingResults(compilation_stats, linking_stats, symbols_count, trace_stats)
        json.dump(results, f, default=lambda o: o.__dict__, indent=4)

    if merged_trace:
        logger.info('    Saving merged trace file...')
        with open(os.path.join(configuration_report_directory, settings.merged_trace_filename), 'w') as f:
            f.write(json.dumps(merged_trace))


def main():
    global settings

    parser = argparse.ArgumentParser(description='Run compilation performance tests')
    parser.add_argument('--settings', '-c', metavar='PATH', required=True, type=str, help='Path to the settings json file')
    parser.add_argument('--keep-build-results', action='store_true', help='Keep build folder after tests')
    parser.add_argument('--verbose', '-v', action='store_true', help='Verbose logs')
    args = parser.parse_args()

    logger.setLevel(logging.DEBUG if args.verbose else logging.INFO)

    settings_dir = os.path.split(args.settings)[0]

    with open(args.settings, 'r') as f:
        fields = json.load(f)

        def update_relative_path(name):
            fields[name] = os.path.join(settings_dir, fields[name])

        update_relative_path('cmake_root')
        update_relative_path('build_directory')
        update_relative_path('report_root_directory')

        settings = Settings(**fields, keep_build_results=args.keep_build_results)

    if 'vsinstalldir' not in os.environ:
        raise RuntimeError("Visual Studio environment isn't set up")

    logger.info('Configurations found: {}'.format(len(settings.configurations)))

    for configuration in settings.configurations:
        run_configuration(configuration)


if __name__ == '__main__':
    main()
