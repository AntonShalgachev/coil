import json
from pathlib import Path
import os
import copy
import argparse


def main(root):
    parser = argparse.ArgumentParser(description='Merge clang time trace into one')
    parser.add_argument('--input', required=True, type=str, help='Input folder which contains json traces')
    parser.add_argument('--output', required=True, type=str, help='Filename for the resulting json trace')
    args = parser.parse_args()

    input_path = args.input
    output_file = args.output

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

    average_result = []

    for i in range(len(reference_result)):
        total_ts = 0
        total_dur = 0
        
        reference_event = reference_result[i]

        average_event = reference_event

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

                total_ts += event['ts']
                total_dur += event['dur']

            average_event = copy.deepcopy(reference_event)
            average_event['ts'] = total_ts // count
            average_event['dur'] = total_dur // count

        average_result.append(average_event)

    print('Processed {} events in {} files'.format(len(average_result), count))
    print('Writing results to "{}"...'.format(output_file))
    with open(output_file, 'w') as fp:
        json.dump({'traceEvents': average_result, 'beginningOfTime': 0}, fp, separators=(',', ':'))

if __name__ == '__main__':
    root = Path(__file__).parent.resolve()
    main(root)
