#from pynwb.spec import SpecCatalog
from pynwb.spec.spec import SpecCatalog, GroupSpec
from pynwb.spec.tools import RSTDocument, SpecFormatter
from itertools import chain
import warnings

try:
    import ruamel.yaml as yaml
except ImportError:
    import yaml
from glob import iglob
import os

# Set path to the NWB core spec
file_dir = os.path.dirname(os.path.abspath(__file__))
spec_dir = os.path.abspath(file_dir+'/../../../core')
output_filename = os.path.join(file_dir, 'format_spec_doc.rst')

# Generate the spec catalog
exts = ['yaml', 'json']
glob_str = os.path.join(spec_dir, "*.%s")
spec_files = list(chain(*[iglob(glob_str % ext) for ext in exts]))
spec_catalog = SpecFormatter.spec_from_file(spec_files)

# Generate the rst file
registered_types = spec_catalog.get_registered_types()
print(registered_types)

# Overwrite the output rst file
doc =  RSTDocument()
doc.add_section("Format Specification")

for rt in sorted(registered_types):
    # Get the spec
    rt_spec = spec_catalog.get_spec(rt)
    """
    # Define the title for the subsection
    rt_title = "Undefined"
    if rt_spec.name is not None and rt_spec.neurodata_type is not None:
        rt_title = rt_spec.name + ": " + rt_spec.neurodata_type
    elif rt_spec.neurodata_type is not None:
        rt_title = rt_spec.neurodata_type
    elif rt_spec.name is not None:
        rt_title = rt_spec.name
    doc.add_subsection(rt_title)"""
    doc.add_subsection(rt)
    # Add the description of the current spec
    doc.add_spec(rt_spec, show_json=True)
doc.write(filename=output_filename, mode='w')

