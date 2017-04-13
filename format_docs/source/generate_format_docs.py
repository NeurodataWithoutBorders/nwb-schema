"""
Generate figures and RST documents from the NWB YAML specification
"""

#from pynwb.spec import SpecCatalog
from pynwb.spec.spec import SpecCatalog, GroupSpec
from collections import OrderedDict
from itertools import chain
import warnings
from conf import spec_show_yaml_src, spec_show_json_src, spec_generate_src_file, spec_show_hierarchy_plots, spec_file_per_type
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
    OKGREEN = '\033[32m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'
    ITALIC = '\33[1m'
    URL      = '\33[4m'
    BLINK    = '\33[5m'
    BLINK2   = '\33[6m'
    SELECTED = '\33[7m'

    @classmethod
    def print(cls, text, col, indent=0, indent_step='   '):
        """

        :param text: The text to be printed
        :param col: One of PrintCol.HEADER, OKBLUE etc.
        :return:
        """
        indent_str = indent_step * indent
        print(col + indent_str + text + cls.ENDC)

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

def render_type_hierarchy(type_hierarchy,
                          target_doc=None,
                          section_label='neurodata_type_hierarchy',
                          subsection_title='Type Hierarchy'):
    """
    Render the flattened type hierarhcy

    :param type_hierarchy The type hierarchy to rendered
    :param target_doc: Target RST document where the type hierarchy should be rendered or None if a new document
                       should be created.
    :param parent_doc: Document where the type hierarchy should be included (or None)
    :param section_label: String with the label for the section (or None if no label should be addded)
    :param subsection_title: String with the title for the secton (or None if no section should be added)

    :returns: RSTDocument with the type hierarchy
    """
    target_doc = RSTDocument() if target_doc is None else target_doc
    if section_label:
        target_doc.add_section_label(section_label)
    if subsection_title:
        target_doc.add_subsection(subsection_title)

    def add_sub_hierarchy(outdoc, type_hierarchy, depth=0, show_ancestry=False, indent_step='   '):
        """
        Helper function used to print a hierarchy of neurodata_types
        :param type_hierarchy: OrderedDict containtin for each type a dict with the 'spec' and OrderedDict of 'substype'
        :param depth: Recursion depth of the print used to indent the hierarchy
        """
        for k, v in type_hierarchy.items():
            type_list_item = indent_step*depth + '* '
            type_list_item += outdoc.get_reference(get_section_label(k), k)
            if show_ancestry:
                type_list_item += '      ancestry=' + str(v['ancestry'])
            type_list_item += outdoc.newline
            outdoc.add_text(type_list_item)
            if len(v['subtypes']) > 0:
                outdoc.add_text(outdoc.newline)
                add_sub_hierarchy(outdoc=outdoc,
                                  type_hierarchy=v['subtypes'],
                                  depth=depth+1,
                                  show_ancestry=show_ancestry,
                                  indent_step=indent_step)

    # Render the hierarchy
    add_sub_hierarchy(outdoc=target_doc,
                      type_hierarchy=type_hierarchy)
    target_doc.add_text(target_doc.newline + target_doc.newline)

    # return the document
    return target_doc


def render_specs(neurodata_types,
                 spec_catalog,
                 desc_doc,
                 src_doc,
                 file_dir,
                 show_hierarchy_plots=True,
                 show_json_src=True,
                 show_yaml_src=True,
                 file_per_type=False):
    """
    Render the documentation for a set of neurodata_types defined in a spec_catalog

    :param neurodata_types: List of string with the names of types that should be rendered
    :param spec_catalog: Catalog of specifications
    :param desc_doc: RSTDocument where the descriptions of the documents should be rendered
    :param src_doc: RSTDocument where the YAML/JSON sources of the neurodata_types should be rendered. Set to None
                    if sources should be rendered in the desc_doc directly.
    :param file_dir: Directory where figures should be stored
    :param show_hierarchy_plots: Create figures showing the hierarchy defined by the spec
    :param show_json_src: Boolean indicating that we should render the JSON source in the src_doc
    :param show_yaml_src: Boolean indicating that we should render the YAML source in the src_doc
    :param file_per_type: Generate a seperate rst files for each neurodata_type and include them
                          in the src_doc and desc_doc (True). If set to False then write the
                          contents to src_doc and desc_doc directly.

    """
    if src_doc is None:
        seperate_src_file = False
        src_doc = desc_doc
    else:
        seperate_src_file = True

    for rt in neurodata_types:
        print("BUILDING %s" % rt)
        # Get the spec
        rt_spec = spec_catalog.get_spec(rt)
        # Check if the spec extends another spec
        extend_type =   rt_spec.get('neurodata_type', None)
        # Define the docs we need to write to
        type_desc_doc = desc_doc if not file_per_type else RSTDocument()
        type_src_doc  = src_doc if not file_per_type else RSTDocument()

        #######################################################
        #  Create the base documentation for the current type
        #######################################################
        # Create the section heading and label
        type_desc_doc.add_section_label(get_section_label(rt))
        section_heading = rt # if extend_type is None else "%s extends %s" % (rt, type_desc_doc.get_reference(get_section_label(extend_type), extend_type))
        type_desc_doc.add_subsection(section_heading)
        if extend_type is not None:
            type_desc_doc.add_text('**Extends:** %s' % type_desc_doc.get_reference(get_section_label(extend_type), extend_type) + type_desc_doc.newline + type_desc_doc.newline)

        type_desc_doc.add_text('**Overview**' + type_desc_doc.newline + type_desc_doc.newline)
        # Add the document string for the neurodata_type to the document
        type_desc_doc.add_text(rt_spec['doc'])
        type_desc_doc.add_text(type_desc_doc.newline + type_desc_doc.newline)
        # Add note if necessary to indicate that the following documentation only shows changes to the parent class
        if extend_type is not None:
            extend_type =  rt_spec['neurodata_type']
            type_desc_doc.add_text("``%s`` extends ``%s`` and includes all elements of %s with the following additions or changes." %
                         (rt,
                          extend_type,
                          type_desc_doc.get_reference(get_section_label(extend_type), extend_type)))
            type_desc_doc.add_text(type_desc_doc.newline + type_desc_doc.newline)

        # Render the graph for the spec if necessary
        try:
            if show_hierarchy_plots:
                temp = HierarchyDescription.from_spec(rt_spec)
                temp_graph = NXGraphHierarchyDescription(temp)
                if len(temp_graph.graph.nodes(data=False)) > 2:
                    fig = temp_graph.draw(show_plot=False, figsize=None, label_font_size=10)
                    plt.savefig(os.path.join(file_dir, '%s.pdf' % rt), format='pdf')
                    plt.savefig(os.path.join(file_dir, '%s.png' % rt), format='png')
                    plt.close()
                    type_desc_doc.add_figure(img='./format_auto_docs/'+rt+".*",
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
        if seperate_src_file:
            # Add a section to the file for the sources
            src_sec_lable = get_src_section_label(rt)
            type_src_doc.add_section_label(src_sec_lable)
            type_src_doc.add_subsection(section_heading)
            if extend_type is not None:
                type_src_doc.add_text('**Extends:** %s' % type_src_doc.get_reference(get_section_label(extend_type), extend_type) + type_src_doc.newline + type_src_doc.newline)
            # Add a link to the source to the main document
            type_desc_doc.add_text(type_desc_doc.get_reference(label=src_sec_lable, link_title="%s specification sources" % rt) + type_desc_doc.newline + type_desc_doc.newline)

        # Add the YAML for the current spec
        if show_yaml_src:
            type_src_doc.add_text('**YAML Specification**' + type_src_doc.newline + type_src_doc.newline)
            type_src_doc.add_spec(rt_spec, show_json=False, show_yaml=True)
        # Add the JSON for the current spec
        if show_json_src:
            type_src_doc.add_text('**JSON Specification**' + type_src_doc.newline + type_src_doc.newline)
            type_src_doc.add_spec(rt_spec, show_json=True, show_yaml=False)

        # Add includes for the type-specific inc files if necessary
        if file_per_type:
            # Write the files for the source and description
            type_src_filename = os.path.join(file_dir, '%s_source.inc' % rt)
            type_desc_filename = os.path.join(file_dir, '%s_description.inc' % rt)
            type_desc_doc.write(type_desc_filename, 'w')
            PrintCol.print("    " + rt + '-- WRITE DESCRIPTION DOC OK.', PrintCol.OKGREEN)
            type_src_doc.write(type_src_filename, 'w')
            PrintCol.print("    " + rt + '-- WRITE SOURCE DOC OK.', PrintCol.OKGREEN)
            # Include the files in the main documents
            desc_doc.add_include(os.path.basename(file_dir) + "/" + os.path.basename(type_desc_filename))
            src_doc.add_include(os.path.basename(file_dir) + "/" + os.path.basename(type_src_filename))

        # Add a clearpage command for latex to avoid possible troubles with figure placement outside of the current section
        if seperate_src_file:
            src_doc.add_latex_clearpage()
        desc_doc.add_latex_clearpage()

def sort_and_group_specs(spec_catalog):
    """
    Sort and group specifications so that they can be rendered in different sections

    :param spec_catalog: The catalog of specifications to be rendered

    :return:
    """
    registered_types = sorted(spec_catalog.get_registered_types())
    type_hierarchy = OrderedDict()
    # spec_yaml = {rt: SpecFormatter.spec_to_yaml(spec_catalog.get_spec(rt)) for rt in registered_types}
    #
    # def embedded_in(spec_yaml, neurodata_type):
    #     """
    #     Determine whether the given neurodata_type is embedded in any other type, i.e.,
    #     the type is specified in only one location and appears in appears in the YAML specification of that type.
    #
    #     :param neurodata_type:
    #     :param spec_yaml
    #     :return:
    #     """
    #     embedded = []
    #     nt_spec = spec_yaml[neurodata_type]
    #     for rt in registered_types:
    #         rt_spec = spec_yaml[rt]
    #         if nt_spec in rt_spec and nt_spec != rt_spec:
    #             embedded.append(rt)
    #     return embedded

    def find_subtypes(spec_catalog, registered_types, neurodata_type, ancestry):
        """
        Find all types that inherit from the given type
        """
        subtypes = OrderedDict()
        for rt in registered_types:
            rt_spec = spec_catalog.get_spec(rt)
            if rt_spec.neurodata_type == neurodata_type  and rt_spec.neurodata_type_def != neurodata_type:
                subtypes[rt] = {'spec': rt_spec,
                                'ancestry': ancestry,
                                'subtypes': find_subtypes(spec_catalog,
                                                          registered_types,
                                                          rt,
                                                          ancestry + [rt,])}

        return subtypes

    for rt in registered_types:
        rt_spec = spec_catalog.get_spec(rt)
        if rt_spec.neurodata_type == rt:  # This is a primary type not a derived type
            type_hierarchy[rt] = {'spec': spec_catalog.get_spec(rt),
                                  'ancestry': [],
                                  'subtypes': find_subtypes(spec_catalog, registered_types, rt, [rt])}


    def flatten_hierarchy(type_hierarchy, flat_type__hierarchy):
        """
        Take the object hierarchy and flatten it to dict with a single level

        :param type_hierarchy:
        :param flat_type__hierarchy:
        :return:
        """
        for k, v in type_hierarchy.items():
            flat_type__hierarchy[k] = v
            flatten_hierarchy(v['subtypes'], flat_type__hierarchy)
        return flat_type__hierarchy

    flat_type_hierarchy = flatten_hierarchy(type_hierarchy, OrderedDict())

    # Check that we actually included all the types. If the above code is correct, we should have captured all types.
    for rt in registered_types:
        if rt not in flat_type_hierarchy:
            PrintCol.print('ERROR -- Type missing in type hierarchy: %s' %k , PrintCol.FAIL)
            type_hierarchy[rt] = {'spec': spec_catalog.get_spec(rt),
                                  'ancestry': [],
                                  'subtypes': {}}

    return type_hierarchy, flat_type_hierarchy


def print_type_hierarchy(type_hierarchy, depth=0, show_ancestry=False):
    """
    Helper function used to print a hierarchy of neurodata_types
    :param type_hierarchy: OrderedDict containtin for each type a dict with the 'spec' and OrderedDict of 'substype'
    :param depth: Recursion depth of the print used to indent the hierarchy
    """
    for k, v in type_hierarchy.items():
        msg = k
        if show_ancestry and len(v['ancestry']) > 0:
            msg += '      ancestry=' + str(v['ancestry'])
        PrintCol.print(msg, PrintCol.OKBLUE+PrintCol.BOLD if depth==0 else PrintCol.OKBLUE, depth)
        print_type_hierarchy(v['subtypes'], depth=depth+1, show_ancestry=show_ancestry)


def main():

    # Set path to the NWB core spec
    file_dir = os.path.join(os.path.dirname(os.path.abspath(__file__)), "format_auto_docs")
    spec_dir = os.path.abspath(file_dir+'/../../../core')
    doc_filename = os.path.join(file_dir, 'format_spec_doc.inc')  # Name of the file where the main documentation goes
    srcdoc_filename = os.path.join(file_dir, 'format_spec_sources.inc') if spec_generate_src_file else None  # Name fo the file where the source YAML/JSON of the specifications go
    master_filename = os.path.join(file_dir, 'format_spec_main.inc')
    type_hierarchy_doc_filename = os.path.join(file_dir, 'format_spec_type_hierarchy.inc')

    # Generate the spec catalog
    exts = ['yaml', 'json']
    glob_str = os.path.join(spec_dir, "*.%s")
    spec_files = list(chain(*[iglob(glob_str % ext) for ext in exts]))
    spec_catalog = SpecFormatter.spec_from_file(spec_files)

    # Generate the hierarchy of types
    print("BUILDING TYPE HIERARCHY")
    registered_types = spec_catalog.get_registered_types()
    type_hierarchy, flat_type_hierarchy = sort_and_group_specs(spec_catalog)
    print_type_hierarchy(type_hierarchy)

    # Create the documentation RST file
    desc_doc =  RSTDocument()

    # Create type hierarchy document
    print("RENDERING TYPE HIERARCHY")
    desc_doc.add_section("Type Overview")
    type_hierarchy_doc = render_type_hierarchy(type_hierarchy=type_hierarchy)
    type_hierarchy_doc.write(type_hierarchy_doc_filename, 'w')
    desc_doc.add_include(os.path.basename(file_dir) + "/" + os.path.basename(type_hierarchy_doc_filename))

    # Create the section for the format specification
    print("RENDERING TYPE SPECIFICATIONS")
    desc_doc.add_latex_clearpage() # Add a clearpage command for latex to avoid possible troubles with figure placement outside of the current section
    desc_doc.add_section("Format Specification")

    # Create the RST file for source files or use the main document in case sources should be included in the main doc directly
    if spec_generate_src_file:
        src_doc = RSTDocument()
        src_doc.add_section("Format Specification: Sources")
    else:
        src_doc = None

    # Create the master doc
    masterdoc = RSTDocument()
    masterdoc.add_include(os.path.basename(file_dir) + "/" + os.path.basename(doc_filename))
    if src_doc is not None:
        masterdoc.add_include(os.path.basename(file_dir) + "/" + os.path.basename(srcdoc_filename))

    # Render all registered documents
    render_specs(neurodata_types=sorted(registered_types),
                 spec_catalog=spec_catalog,
                 desc_doc=desc_doc,
                 src_doc=src_doc,
                 file_dir=file_dir,
                 show_hierarchy_plots=spec_show_hierarchy_plots,
                 show_json_src=spec_show_json_src,
                 show_yaml_src=spec_show_yaml_src,
                 file_per_type=spec_file_per_type)

    #######################################
    #  Write the RST documents to file
    #######################################
    def write_rst_doc(document, filename, mode='w'):
        if document is not None and filename is not None:
            document.write(filename=filename, mode=mode)
            PrintCol.print("Write %s" % filename, PrintCol.OKGREEN)
    write_rst_doc(desc_doc, doc_filename)     # Write the descritpion RST document
    write_rst_doc(src_doc, srcdoc_filename)   # Write the source RST document
    write_rst_doc(masterdoc, master_filename) # Write the master RST document


if __name__ == "__main__":
    main()

