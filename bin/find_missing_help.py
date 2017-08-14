import ruamel.yaml as yaml
import sys


missing = list()

curr_file = None
stack = list()

def find_missing_help(d):
    stack.append(d.get('neurodata_type_def', d.get('neurodata_type_inc', d.get('name'))))
    if d.get('neurodata_type_inc') == 'NWBContainer' and d.get('neurodata_type_def') is not None:
        found_help = False
        if 'attributes' in d:
            for attr in d['attributes']:
                if attr.get('name') == 'help' and attr.get('value') is not None:
                    found_help = True
        if not found_help:
            missing.append('%s: %s' % (curr_file, '/'.join(stack)))

    if 'groups' in d:
        for sub_d in d['groups']:
            find_missing_help(sub_d)
    stack.pop()


for curr_file in sys.argv[1:]:
    with open(curr_file) as fin:
        fd = yaml.safe_load(fin)
        for d in fd['groups']:
            find_missing_help(d)

if len(missing) > 0:
    print('The following types are missing help')
    for t in missing:
        print(t)
    sys.exit(1)
