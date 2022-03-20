import argparse
import copy
from enum import Enum
import json
import logging
import os
import statistics
import subprocess
import time
from typing import Dict
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
    def __init__(self, keep_build_results: bool, compiler_options: List[str], bindings_options: List[str], unity_options: List[bool], count: int, cmake_root: str, build_directory: str, report_file: str, merged_trace_file: str, compilation_object: str):
        self.keep_build_results = keep_build_results
        self.count = count
        self.cmake_root = cmake_root
        self.build_directory = build_directory
        self.report_file = report_file
        self.merged_trace_file = merged_trace_file
        self.compilation_object = compilation_object

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

    def __str__(self):
        return str(self.__dict__)

class ProfilingResults:
    def __init__(self, compilation_stats: DurationStats, linking_stats: DurationStats, symbols_count: int):
        self.compilation_stats = compilation_stats
        self.linking_stats = linking_stats
        self.symbols_count = symbols_count


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


def execute_db_command(compilation_commands, output_file_ending):
    if isinstance(output_file_ending, str):
        entry_filter = lambda entry: entry['output'].endswith(output_file_ending)
    else:
        entry_filter = lambda entry: any([entry['output'].endswith(ending) for ending in output_file_ending])

    entry = next(filter(entry_filter, compilation_commands), None)
    assert entry is not None
    _, duration = execute_command(entry['command'], entry['directory'])
    return duration, entry


def prepare_configuration(configuration: BuildConfiguration):
    build_dir = os.path.join(settings.build_directory, configuration.name)

    params = {
        'root': settings.cmake_root,
        'build_dir': build_dir,
        'unity': '-DCMAKE_UNITY_BUILD=ON' if configuration.unity else '',
        'bindings': BINDINGS_CMD_ARGUMENTS[configuration.bindings],
    }

    cmake_command = 'cmake -B "{build_dir}" -DCOIL_EXAMPLES=OFF -DCOIL_COMPILE_TIME=ON -DCOIL_COMPILE_TIME_TRACE=ON {bindings} {unity} -GNinja "{root}"'.format(**params)

    if configuration.compiler == Compiler.CLANG:
        os.environ['CC'] = 'clang-cl'
        os.environ['CXX'] = 'clang-cl'
    
    logger.info('Running CMake...')
    execute_command(cmake_command)

    logger.info('Running the first build...')
    execute_command('ninja -d keeprsp', cwd=build_dir)

    logger.info('Generating compilation commands...')
    compilation_commands_json, _ = execute_command('ninja -t compdb', cwd=build_dir)
    with open(os.path.join(build_dir, 'compilation_commands.json'), 'w') as f:
        f.write(compilation_commands_json)
    compilation_commands = json.loads(compilation_commands_json)

    logger.info('Compiling PCH...')
    execute_db_command(compilation_commands, 'cmake_pch.cxx.obj')

    return compilation_commands


def merge_traces(traces):
    reference_result = traces[0]
    
    for trace in traces:
        if len(trace) != len(reference_result):
            print('Mismatched number of trace events')
            return

    merged_trace = []

    for i in range(len(reference_result)):
        begin_ts = []
        end_ts = []
        
        reference_event = reference_result[i]

        merged_event = reference_event
        
        if 'name' in reference_event and reference_event['name'].startswith('Total '):
            continue

        if reference_event['ph'] == 'X':
            for trace in traces:
                event = trace[i]

                if 'name' not in event:
                    print('ERROR! No name in event {}'.format(i))
                    return

                if ('args' in event) != ('args' in reference_event):
                    print('ERROR! Args presence varies in event {}'.format(i))
                    return

                if event['name'] != reference_event['name']:
                    print('ERROR! Mismatched event name')
                    return
                
                if 'args' in event and event['args'] != reference_event['args']:
                    print('ERROR! Mismatched event args')
                    return

                ts = event['ts']
                dur = event['dur']

                begin_ts.append(ts)
                end_ts.append(ts + dur)

            merged_event = copy.deepcopy(reference_event)
            ts = statistics.median(begin_ts)
            dur = statistics.median(end_ts) - ts
            merged_event['ts'] = int(ts)
            merged_event['dur'] = int(dur)

        merged_trace.append(merged_event)
    
    return merged_trace


def profile_compilation_command(compilation_commands):
    durations = []
    traces = []
    for _ in range(settings.count):
        duration, entry = execute_db_command(compilation_commands, settings.compilation_object)
        durations.append(duration)
        object_file = os.path.join(entry['directory'], entry['output'])
        trace_file = object_file.replace('.obj', '.json')

        logger.debug('Using trace file: {}'.format(trace_file))
        with open(trace_file, 'r') as f:
            trace = json.load(f)['traceEvents']
            logger.debug('Found {} events'.format(len(trace)))
            traces.append(trace)

    logger.info('Merging traces...')
    merge_traces(traces)

    logger.info('Saving trace file...')
    with open(settings.merged_trace_file, 'w') as f:
        json.dump(trace, f)
            
    return DurationStats(durations)


def profile_linking_command(compilation_commands, output_file_ending):
    durations = []
    for _ in range(settings.count):
        duration, _ = execute_db_command(compilation_commands, output_file_ending)
        durations.append(duration)
    return DurationStats(durations)


def run_configuration(configuration: BuildConfiguration):
    logger.info('Profiling configuration {}'.format(configuration.name))

    compilation_commands = prepare_configuration(configuration)

    logger.info('Profiling compilation...')
    compilation_stats = profile_compilation_command(compilation_commands)
    logger.info(compilation_stats)

    logger.info('Profiling linking...')
    linking_stats = profile_linking_command(compilation_commands, 'compilation_performance.exe')
    logger.info(linking_stats)

    symbols_count = 42 # TODO

    return ProfilingResults(compilation_stats, linking_stats, symbols_count)


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

        def update_relative_path(name, ensure_exists=False):
            fields[name] = os.path.join(settings_dir, fields[name])
            if ensure_exists:
                os.makedirs(os.path.split(fields[name])[0], exist_ok=True)

        update_relative_path('cmake_root')
        update_relative_path('build_directory')
        update_relative_path('report_file', ensure_exists=True)
        update_relative_path('merged_trace_file', ensure_exists=True)

        settings = Settings(**fields, keep_build_results=args.keep_build_results)

    if 'vsinstalldir' not in os.environ:
        raise RuntimeError("Visual Studio environment isn't set up")

    logger.info('Configurations found: {}'.format(len(settings.configurations)))

    results: Dict[ProfilingResults] = {}

    for configuration in settings.configurations:
        results[configuration.name] = run_configuration(configuration)

    with open(settings.report_file, 'w') as f:
        json.dump(results, f, default=lambda o: o.__dict__, indent=4)


if __name__ == '__main__':
    main()
