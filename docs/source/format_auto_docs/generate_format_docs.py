#from pynwb.spec import SpecCatalog
from pynwb.spec.spec import SpecCatalog, GroupSpec
from pynwb.spec.tools import RSTDocument, SpecFormatter
from itertools import chain
import warnings

try:
    from matplotlib import pyplot as plt
    import networkx
    from pynwb.spec.tools import NXGraphHierarchyDescription, HierarchyDescription
    INCLUDE_GRAPHS = True
except ImportError:
    INCLUDE_GRAPHS = False
    warnings.warn('DISABLING RENDERING OF SPEC GRAPHS DUE TO IMPORT ERROR')

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

# Overwrite the output rst file
doc =  RSTDocument()
doc.add_section("Format Specification")

# Add a clearpage command for latex to avoid possible troubles with figure placement outside of the current section
doc.add_latex_clearpage()
for rt in sorted(registered_types):
    print("BUILDING %s" % rt)
    # Get the spec
    rt_spec = spec_catalog.get_spec(rt)
    doc.add_subsection(rt)
    doc.add_text('**Overview**' + doc.newline + doc.newline)
    # Render the graph for the spec if necessary
    if True: #try:
        temp = HierarchyDescription.from_spec(rt_spec)
        temp_graph = NXGraphHierarchyDescription(temp)
        if len(temp_graph.graph.nodes(data=False)) > 2:
            fig = temp_graph.draw(show_plot=False, figsize=None, label_font_size=10)
            plt.savefig(os.path.join(file_dir, '%s.pdf' % rt), format='pdf')
            plt.savefig(os.path.join(file_dir, '%s.png' % rt), format='png')
            plt.close()
            doc.add_figure(img='./format_auto_docs/'+rt+".*",
                           alt=rt)
        else:
           print("    " + rt + '-- SKIPPED RENDER HIERARCHY')
    else: # except:
        warnings.warn(rt + '-- RENDER HIERARCHY FAILED')
        break
    # Add the YAML for the current spec
    doc.add_text('**YAML Specification**' + doc.newline + doc.newline)
    doc.add_spec(rt_spec, show_json=False, show_yaml=True)
    # Add the JSON for the current spec
    doc.add_text('**JSON Specification**' + doc.newline + doc.newline)
    doc.add_spec(rt_spec, show_json=True, show_yaml=False)
    # Add a clearpage command for latex to avoid possible troubles with figure placement outside of the current section
    doc.add_latex_clearpage()

doc.add_sidebar('this is an awesome sidebar' , 'My sidebar', "and more")
doc.write(filename=output_filename, mode='w')

