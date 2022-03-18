import json
import re
import sys


symbol_name_regex = re.compile(r'         COMDAT; sym= (.*)')


def main():
    names = []
    for line in sys.stdin:
        m = symbol_name_regex.match(line)
        if m:
            names.append(m.group(1))

    names.sort()

    print(json.dumps({'count': len(names), 'names': names}))


if __name__ == '__main__':
    main()