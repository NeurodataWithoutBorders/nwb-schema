"""
Generate figures and RST documents from the NWB YAML specification
"""

#from pynwb.spec import SpecCatalog
from pynwb.spec.spec import SpecCatalog, GroupSpec
from itertools import chain
import warnings
from conf import spec_show_yaml_src, spec_show_json_src, spec_generate_src_file, spec_show_hierarchy_plots
import os
import sys
sys.path.append(os.path.abspath(os.path.dirname(os.path.abspath(__file__)) + '/../../'))
from utils.render import RSTDocument, SpecFormatter


try:
    from matplotlib import pyplot as plt
    import networkx
    from utils.render import NXGraphHierarchyDescription, HierarchyDescription
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


class PrintCol:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'

    @classmethod
    def print(cls, text, col):
        """

        :param text: The text to be printed
        :param col: One of PrintCol.HEADER, OKBLUE etc.
        :return:
        """
        print(col + text + cls.ENDC)

def get_section_label(neurodata_type):
    """Get the lable of the section with the documenation for the given neurodata_type"""
    return 'sec-' + neurodata_type

def get_src_section_label(neurodata_type):
    """Get the label for the section with the source YAML/JSON of the given neurodata_type.

    :return: String with the section lable or None in case no sources are included as part of the documentation
    """
    if spec_generate_src_file:
        return 'sec-' + neurodata_type + "-src"
    elif spec_show_json_src or spec_show_yaml_src:
        return get_section_label(neurodata_type)
    else:
        None

# Set path to the NWB core spec
file_dir = os.path.join(os.path.dirname(os.path.abspath(__file__)), "format_auto_docs")
spec_dir = os.path.abspath(file_dir+'/../../../core')
doc_filename = os.path.join(file_dir, 'format_spec_doc.inc')  # Name of the file where the main documentation goes
srcdoc_filename = os.path.join(file_dir, 'format_spec_sources.inc') if spec_generate_src_file else None  # Name fo the file where the source YAML/JSON of the specifications go
master_filename = os.path.join(file_dir, 'format_spec_main.inc')

# Generate the spec catalog
exts = ['yaml', 'json']
glob_str = os.path.join(spec_dir, "*.%s")
spec_files = list(chain(*[iglob(glob_str % ext) for ext in exts]))
spec_catalog = SpecFormatter.spec_from_file(spec_files)

# Generate the rst file
registered_types = spec_catalog.get_registered_types()

# Create the documentation RST file
doc =  RSTDocument()
doc.add_section("Format Specification")

# Create the RST file for source files or use the main document in case sources should be included in the main doc directly
if spec_generate_src_file:
    srcdoc = RSTDocument()
    srcdoc.add_section("Format Specification: Sources")
else:
    srcdoc = doc

# Create the master doc
masterdoc = RSTDocument()

# Add a clearpage command for latex to avoid possible troubles with figure placement outside of the current section
doc.add_latex_clearpage()
for rt in sorted(registered_types):
    print("BUILDING %s" % rt)
    # Get the spec
    rt_spec = spec_catalog.get_spec(rt)
    # Check if the spec extends another spec
    extend_type =   rt_spec.get('neurodata_type', None)

    #######################################################
    #  Create the base documentation for the current type
    #######################################################
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
    # Add note if necessary to indicate that the following documentation only shows changes to the parent class
    if extend_type is not None:
        extend_type =  rt_spec['neurodata_type']
        doc.add_text("``%s`` extends ``%s`` and includes all elements of %s with the following additions or changes." %
                     (rt,
                      extend_type,
                      doc.get_reference(get_section_label(extend_type), extend_type)))
        doc.add_text(doc.newline+doc.newline)

    # Render the graph for the spec if necessary
    try:
        if spec_show_hierarchy_plots:
            temp = HierarchyDescription.from_spec(rt_spec)
            temp_graph = NXGraphHierarchyDescription(temp)
            if len(temp_graph.graph.nodes(data=False)) > 2:
                fig = temp_graph.draw(show_plot=False, figsize=None, label_font_size=10)
                plt.savefig(os.path.join(file_dir, '%s.pdf' % rt), format='pdf')
                plt.savefig(os.path.join(file_dir, '%s.png' % rt), format='png')
                plt.close()
                doc.add_figure(img='./format_auto_docs/'+rt+".*",
                               alt=rt)
                PrintCol.print("    " + rt + '-- RENDER OK.', PrintCol.OKGREEN)
            else:
               PrintCol.print("    " + rt + '-- SKIPPED RENDER HIERARCHY. TWO OR FEWER NODES.', PrintCol.OKBLUE)
        else:
            PrintCol.print("    " + rt + '-- SKIPPED RENDER HIERARCHY. See conf.py', PrintCol.OKBLUE)
    except:
         PrintCol.print(rt + '-- RENDER HIERARCHY FAILED', PrintCol.FAIL)

    ####################################################################
    #  Add the YAML and/or JSON sources to the document if requested
    ####################################################################
    # If the JSON/YAML are shown in a seperate chapter than add section headings
    if spec_generate_src_file:
        # Add a section to the file for the sources
        src_sec_lable = get_src_section_label(rt)
        srcdoc.add_section_label(src_sec_lable)
        srcdoc.add_subsection(section_heading)
        if extend_type is not None:
            srcdoc.add_text('**Extends:** %s' % srcdoc.get_reference(get_section_label(extend_type), extend_type) + srcdoc.newline + srcdoc.newline)
        # Add a link to the source to the main document
        doc.add_text(doc.get_reference(label=src_sec_lable, link_title="%s specification sources" % rt) + doc.newline + doc.newline)

    # Add the YAML for the current spec
    srcdoc.add_text('**YAML Specification**' + srcdoc.newline + srcdoc.newline)
    srcdoc.add_spec(rt_spec, show_json=False, show_yaml=True)
    # Add the JSON for the current spec
    srcdoc.add_text('**JSON Specification**' + srcdoc.newline + srcdoc.newline)
    srcdoc.add_spec(rt_spec, show_json=True, show_yaml=False)
    # Add a clearpage command for latex to avoid possible troubles with figure placement outside of the current section
    srcdoc.add_latex_clearpage()

# Write the documenation file
doc.write(filename=doc_filename, mode='w')
PrintCol.print("Write %s" % doc_filename, PrintCol.OKGREEN)

# Write the file with the YAML/JSON sources if requested
if srcdoc_filename is not None:
    srcdoc.write(filename=srcdoc_filename, mode='w')
    PrintCol.print("Write %s" % srcdoc_filename, PrintCol.OKGREEN)

# Generate and write the master file that includes the generated sources in order
masterdoc.add_text(".. include:: %s" % "format_auto_docs/format_spec_doc.inc" + masterdoc.newline )
if srcdoc_filename is not None:
    masterdoc.add_text(".. include:: %s" % "format_auto_docs/format_spec_sources.inc" + masterdoc.newline )
masterdoc.write(filename=master_filename, mode='w')
PrintCol.print("Write %s" % master_filename, PrintCol.OKGREEN)



