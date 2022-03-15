import enum
import json
import os
import copy
import argparse
import statistics


class Mode(enum.Enum):
    Mean = 'Mean'
    Median = 'Median'

    def __str__(self):
        return self.value


def main():
    parser = argparse.ArgumentParser(description='Merge clang time trace into one')
    parser.add_argument('--input', required=True, type=str, help='Input folder which contains json traces')
    parser.add_argument('--output', required=True, type=str, help='Filename for the resulting json trace')
    parser.add_argument('--mode', type=Mode, choices=list(Mode), default=Mode.Mean, help='Algorithm used to compute the resulting trace')
    args = parser.parse_args()

    input_path = args.input
    output_file = args.output
    algorithm_func = None
    if args.mode == Mode.Mean:
        algorithm_func = statistics.mean
    elif args.mode == Mode.Median:
        algorithm_func = statistics.median

    results = []
    print('Loading traces from "{}"...'.format(input_path))
    for (dirpath, _, filenames) in os.walk(input_path):
        for filename in filenames:
            if os.path.splitext(filename)[1] == '.json':
                print('Loading "{}"...'.format(filename), end='')
                with open(os.path.join(dirpath, filename)) as fp:
                    result = json.load(fp)['traceEvents']
                    print(' found {} events'.format(len(result)))
                    results.append(result)

    count = len(results)
    print('Processing {} results...'.format(count))

    if count == 0:
        return

    reference_result = results[0]
    
    for result in results:
        if len(result) != len(reference_result):
            print('Mismatched number of trace events')
            return

    output_events = []

    for i in range(len(reference_result)):
        begin_ts = []
        end_ts = []
        
        reference_event = reference_result[i]

        output_event = reference_event
        
        if 'name' in reference_event and reference_event['name'].startswith('Total '):
            continue

        if reference_event['ph'] == 'X':
            for result in results:
                event = result[i]

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

            output_event = copy.deepcopy(reference_event)
            ts = algorithm_func(begin_ts)
            dur = algorithm_func(end_ts) - ts
            output_event['ts'] = int(ts)
            output_event['dur'] = int(dur)

        output_events.append(output_event)

    print('Processed {} events in {} files'.format(len(output_events), count))
    print('Writing results to "{}"...'.format(output_file))
    with open(output_file, 'w') as fp:
        json.dump({'traceEvents': output_events, 'beginningOfTime': 0}, fp, separators=(',', ':'))

if __name__ == '__main__':
    main()