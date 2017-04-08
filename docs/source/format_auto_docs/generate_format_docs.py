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

def get_section_label(neurodata_type):
    return 'sec-' + neurodata_type

# Set path to the NWB core spec
file_dir = os.path.dirname(os.path.abspath(__file__))
spec_dir = os.path.abspath(file_dir+'/../../../core')
output_filename = os.path.join(file_dir, 'format_spec_doc.inc')

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
    # Check if the spec extends another spec
    extend_type =   rt_spec.get('neurodata_type', None)
    # Create the section heading and label
    doc.add_section_label(get_section_label(rt))
    section_heading = rt # if extend_type is None else "%s extends %s" % (rt, doc.get_reference(get_section_label(extend_type), extend_type))
    doc.add_subsection(section_heading)
    if extend_type is not None:
        doc.add_text('**Extends:** %s' % doc.get_reference(get_section_label(extend_type), extend_type) + doc.newline + doc.newline)
    doc.add_text('**Overview**' + doc.newline + doc.newline)
    # Add the document string for the neurodata_type to the document
    doc.add_text(rt_spec['doc'])
    doc.add_text(doc.newline+doc.newline)
    # Add note if necessary to indicate that the followig documenation only shows changes to the parent class
    if extend_type is not None:
        extend_type =  rt_spec['neurodata_type']
        doc.add_text("``%s`` extends ``%s`` and includes all elements of %s with the following additions or changes." %
                     (rt,
                      extend_type,
                      doc.get_reference(get_section_label(extend_type), extend_type)))
        doc.add_text(doc.newline+doc.newline)

    # Render the graph for the spec if necessary
    try:
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
           print("    " + rt + '-- SKIPPED RENDER HIERARCHY. TWO OR FEWER NODES.')
    except:
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

doc.write(filename=output_filename, mode='w')

