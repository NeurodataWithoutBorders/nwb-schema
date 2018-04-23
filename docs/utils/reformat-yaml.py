#!/usr/bin/env python3

import sys
import ruamel.yaml
from pathlib import Path


def main():
    """ Helper script to round trip schema yaml files
        Pass in a folder with YAML files as argument. """

    basedir = Path(sys.argv[1])

    yaml = ruamel.yaml.YAML()
    yaml.preserve_quotes = True
    yaml.default_style = None
    yaml.default_flow_style = None
    yaml.width = 80

    for f in Path(basedir).glob('*.yaml'):
        h = f.open()
        data = yaml.load(h)
        h.close()
        yaml.dump(data, f)


if __name__ == "__main__":
    main()
