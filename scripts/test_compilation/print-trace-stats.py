import argparse
import json


def main():
    parser = argparse.ArgumentParser(description='Print stats of the clang trace file')
    parser.add_argument('input', metavar='PATH', type=str, help='Input clang trace file')
    args = parser.parse_args()

    events = None
    with open(args.input) as fp:
        events = json.load(fp)['traceEvents']

    stats = {}

    for event in events:
        if event['ph'] != 'X':
            continue

        name = event['name']
        if name not in stats:
            stats[name] = []
        stats[name].append(event['dur'])

    result = []
    for name, values in stats.items():
        total = sum(values)

        entry = {
            'name': name,
            'total': total,
        }
        result.append(entry)

    result.sort(key=lambda e: e['total'], reverse=True)

    print(json.dumps(result))


if __name__ == '__main__':
    main()
