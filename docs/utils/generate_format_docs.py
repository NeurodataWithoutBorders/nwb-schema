"""
Generate figures and RST documents from the NWB YAML specification for the format specification documentation
"""

# TODO In the type hierarchy section add a section to order types by based on which YAML file they appear in
# TODO In the sections describing the different types add the name of the source YAML file


#from pynwb.spec import SpecCatalog
from form.spec.spec import GroupSpec, DatasetSpec, LinkSpec, AttributeSpec
from pynwb.spec import NWBGroupSpec, NWBDatasetSpec, NWBNamespace
from form.spec.namespace import NamespaceCatalog
from collections import OrderedDict
import warnings
import os
import sys
try:
    from utils.render import RSTDocument, RSTTable, SpecFormatter
except ImportError:
    from render import RSTDocument, RSTTable, SpecFormatter
except ImportError:
    sys.path.append(os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), "../")))
    from utils.render import RSTDocument, RSTTable, SpecFormatter
    warnings.warn("The import path for utils/render may not be set properly")

# Import settings from the configuration file
try:
    from conf_doc_autogen import spec_show_yaml_src, \
        spec_show_json_src, \
        spec_generate_src_file, \
        spec_show_hierarchy_plots, \
        spec_file_per_type, \
        spec_show_subgroups_in_seperate_table, \
        spec_appreviate_main_object_doc_in_tables, \
        spec_show_title_for_tables, \
        spec_table_depth_char, \
        spec_add_latex_clearpage_after_ndt_sections, \
        spec_resolve_type_inc, \
        spec_output_dir, \
        spec_input_spec_dir, \
        spec_output_doc_filename, \
        spec_output_src_filename, \
        spec_output_master_filename, \
        spec_output_doc_type_hierarchy_filename, \
        spec_input_namespace_filename, \
        spec_input_default_namespace
except ImportError:
    print("Could not import SPHINX conf_doc_autogen.py file. Please add the PYTHONPATH to the source directory where the conf.py file is located")
    exit(0)

try:
    from matplotlib import pyplot as plt
    import networkx
    try:
        from utils.render import NXGraphHierarchyDescription, HierarchyDescription
    except ImportError:
        from render import NXGraphHierarchyDescription, HierarchyDescription
    except ImportError:
        sys.path.append(os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), "../")))
        from utils.render import NXGraphHierarchyDescription, HierarchyDescription
        warnings.warn("The import path for utils/render may not be set properly")

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


CUSTOM_LATEX_TABLE_COLUMNS = "|p{4cm}|p{1cm}|p{10cm}|"

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


class NeurodataTypeDict(dict):
    """Dict used to describe a neurodata type"""
    def __init__(self, neurodata_type, spec, ancestry, subtypes):
        self['neurodata_type'] = neurodata_type
        self['spec'] = spec
        self['ancestry'] = ancestry
        self['subtypes'] = subtypes


def clean_doc(doc_str, add_prefix=None, add_postifix=None, rst_format='**', remove_html_tags=True):
    """
    Replace COMMENT, NOTE, MORE_INFO etc. qualifieres from the original spec
    with RST-style
    :param doc_str: The documentation string to be processed
    :param add_prefix: Prefix string to be added before Comment, Note, etc. substrings.
                    Useful, e.g., to add newlines before the different sections of the doc string.
    :param rst_format: RST formatting to be used for Comment, Note et.c headings. Default='**' for bold text.
    :param remove_html_tags: Boolean indicating whether the function should try to replace html tags with rst
                             tags if possible
    :return: New rst string
    """
    prefix = ' ' if add_prefix is None else add_prefix
    temp_str = doc_str
    if remove_html_tags:
        # temp_str = re.sub('<[^<]+?>', '', temp_str)
        temp_str = temp_str.replace('&lt;', '<')
        temp_str = temp_str.replace('&gt;', '>')
        temp_str = temp_str.replace('<b>', ' **')
        temp_str = temp_str.replace('</b>', '** ')
        temp_str = temp_str.replace('<i>', ' *')
        temp_str = temp_str.replace('</i>', '* ')
        temp_str = temp_str.replace(':blue:', '')

    temp_str = temp_str.replace('COMMENT:', '%s%sComment:%s ' % (prefix, rst_format, rst_format))
    temp_str = temp_str.replace('MORE_INFO:','%s%sAdditional Information:%s ' % (prefix, rst_format, rst_format))
    temp_str = temp_str.replace('NOTE:', '%s %sAdditional Information:%s '% (prefix, rst_format, rst_format))
    if add_postifix is not None:
        temp_str += add_postifix
    return temp_str


def spec_prop_doc(spec, newline='\n', ignore_props=None):
    """
    Create a list with the properties from the spec rendered as RST
    :param spec: The GroupSpec, DatasetSpec, AttributeSpec, or LinkSpec object
    :param newline:
    :param ignore_props: List of strings of property keys we should ignore
    :return:
    """

    spec_prop_list = []
    ignore_keys = [] if ignore_props is None else ignore_props
    # Add link properties
    if isinstance(spec, LinkSpec):
        spec_prop_list.append('**Target Type** %s' % RSTDocument.get_reference(get_section_label(spec['target_type']), spec['target_type']))
    # Add dataset properties
    if isinstance(spec, DatasetSpec):
        if spec.get('quantity', None) is not None and 'quantity' not in ignore_keys:
            spec_prop_list.append('**Quantity** %s' % quantity_to_string(spec['quantity']))
        if spec.get('dtype', None) is not None and 'dtype' not in ignore_keys:
            spec_prop_list.append('**Data Type:** %s' % str(spec['dtype']))
        if spec.get('dims', None) is not None and 'dims' not in ignore_keys:
            spec_prop_list.append('**Dimensions:** %s' % str(spec['dims']))
        if spec.get('shape', None) is not None  and 'shape' not in ignore_keys:
            spec_prop_list.append('**Shape:** %s' % str(spec['shape']))
        if spec.get('linkable', None) is not None  and 'linnkable' not in ignore_keys:
            spec_prop_list.append('**Linkable:** %s' % str(spec['linkable']))
        if spec.get('neurodata_type_inc', None) is not None and 'neurodata_type_inc' not in ignore_keys:
            extend_type = str(spec['neurodata_type_inc'])
            spec_prop_list.append('**Extends:** %s' %  RSTDocument.get_reference(get_section_label(extend_type), extend_type))
        if spec.get('neurodata_type_def', None) is not None and 'neurodata_type_def' not in ignore_keys:
            spec_prop_list.append('**Neurodata Type:** %s' % str(spec['neurodata_type_def']))
    # Add group properties
    if isinstance(spec, GroupSpec):
        if spec.get('quantity', None) is not None and 'quantity' not in ignore_keys:
            spec_prop_list.append('**Quantity** %s' % quantity_to_string(spec['quantity']))
        if spec.get('linkable', None) is not None and 'linkable' not in ignore_keys:
            spec_prop_list.append('**Linkable:** %s' % str(spec['linkable']))
        if spec.get('neurodata_type_inc', None) is not None and 'neurodata_type_inc' not in ignore_keys:
            extend_type = str(spec['neurodata_type_inc'])
            spec_prop_list.append('**Extends:** %s' %  RSTDocument.get_reference(get_section_label(extend_type), extend_type))
        if spec.get('neurodata_type_def', None) is not None and 'neurodata_type_def' not in ignore_keys:
            ntype = str(spec['neurodata_type_def'])
            spec_prop_list.append('**Neurodata Type:** %s' % RSTDocument.get_reference(get_section_label(ntype), ntype))
    # Add attribute spec properites
    if isinstance(spec, AttributeSpec):
        if spec.get('dtype', None) is not None and 'dtype' not in ignore_keys:
            spec_prop_list.append('**Data Type:** %s' % str(spec['dtype']))
        if spec.get('dims', None) is not None  and 'dims' not in ignore_keys:
            spec_prop_list.append('**Dimensions:** %s' % str(spec['dims']))
        if spec.get('shape', None) is not None  and 'shape' not in ignore_keys:
            spec_prop_list.append('**Shape:** %s' % str(spec['shape']))
        if spec.get('required', None) is not None and 'required' not in ignore_keys:
            spec_prop_list.append('**Reuqired:** %s' % str(spec['required']))
        if spec.get('value', None) is not None and 'value' not in ignore_keys:
            spec_prop_list.append('**Value:** %s' % str(spec['value']))
        if spec.get('default_value', None) is not None and 'default_value' not in ignore_keys:
            spec_prop_list.append('**Default Value:** %s' % str(spec['default_value']))

    # Add common properties
    if spec.get('default_name', None) is not None:
            spec_prop_list.append('**Default Name:** %s' % str(spec['default_name']))
    if spec.get('name', None) is not None:
        spec_prop_list.append('**Name:** %s' % str(spec['name']))

    # Render the sepecification propoerties list
    spec_doc = ''
    if len(spec_prop_list) > 0:
        spec_doc += newline
        for dp in spec_prop_list:
            spec_doc += newline + '- ' + dp
        spec_doc += newline
    # Return the rendered list
    return spec_doc


def quantity_to_string(quantity):
    """
    Helper function to convert a quantity identifier to a consisten string for the documentation
    :param quantity: Quantity used in the format specification
    :return: String describing the quantity
    """
    qdict = {
        '*'            : '0 or more',
        'zero_or_more' : '0 or more',
        '+'            : '1 or more',
        'one_or_more'  : '1 or more',
        '?'            : '0 or 1',
        'zero_or_one'  : '0 or 1'
    }
    if isinstance(quantity, int):
        return str(quantity)
    else:
        return qdict[quantity]



class NeurodataTypeSection(dict):
        """
        Dict describing a set of neurodata_types that should be grouped in a section in the documentation
        """
        def __init__(self, title, neurodata_types=None, intro=None):
            """

            :param title: String with the title of the section
            :param neurodata_types: None or OrderedDict where the keys are neurodata_types and the values
                                    are NeurodataTypeDict
            :param intro: None or RSTDocument with introductory text for the section.
            """
            self['title'] = title
            self['neurodata_types'] = OrderedDict() if neurodata_types is None else neurodata_types
            self['intro'] = intro


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

def get_group_table_label(parent):
    """
    Get the name of the reference for the table listing all subgroups for the parent
    """
    return 'table-'+parent+'-groups'

def get_data_table_label(parent):
    """
    Get the name of the reference for the table listing all data for the parent
    """
    return 'table-'+parent+'-data'

def render_namespace(namespace_catalog,
                     namespace_name=None,
                     desc_doc=None,
                     src_doc=None,
                     show_json_src=True,
                     show_yaml_src=True,
                     file_dir=None,
                     file_per_type=False,
                     type_hierarchy_include=None,
                     type_hierarchy_include_in_html_only=True):
    """
    Render the description of the namespace

    :param namespace_catalog: NamespaceCatalog object with the namespaces
    :param desc_doc: RSTDocument where the description should be rendered. Set to None to not render a description.
    :param src_doc: RSTDocument where the sources of the namespace should be rendered. Set to None to not render a namepsace.
    :param namespace_name: Name of the namespace to be rendered. Set to None if the default namespace should be used
    :param show_json_src: Boolean indicating that we should render the JSON source in the src_doc
    :param show_yaml_src: Boolean indicating that we should render the YAML source in the src_doc
    :param file_dir: Directory where output RST docs should be stored. Required if file_per_type is True.
    :param file_per_type: Generate a seperate rst files for each neurodata_type and include them
                          in the src_doc and desc_doc (True). If set to False then write the
                          contents to src_doc and desc_doc directly.
    :param type_hierarchy_include: Optional include file with the hierarchy of types in the namespace
    :param type_hierarchy_include_in_html_only: Add type hierarchy to html only, e.g., to avoid too deeply nested
                          errors in the context of LaTeX builds.

    """
    # Determine file settings
    if src_doc is None:
        seperate_src_file = False
        if show_json_src or show_yaml_src:
            src_doc = desc_doc
    else:
        seperate_src_file = True

    # Create target RST files if necessary
    ns_desc_doc = desc_doc if not file_per_type else RSTDocument()
    ns_src_doc  = src_doc if not file_per_type else RSTDocument()
    ns_desc_label = "nwb-type-namespace-doc"
    ns_src_label = "nwb-type-namespace-src"
    # Create the target doc
    namespace_name = namespace_name if namespace_name is None else namespace_catalog.default_namespace
    curr_namespace = namespace_catalog.get_namespace(namespace_name)
    # Section heading
    sec_heading = "Namespace: %s" % curr_namespace['full_name'] if 'full_name' in curr_namespace else curr_namespace['name']
    # Render the description of the namespace
    if desc_doc:
        # Add a subsection for the Namespace
        ns_desc_doc.add_label(ns_desc_label)
        ns_desc_doc.add_section(sec_heading)
        # Add a link to the source specification
        if seperate_src_file:
            ns_src_doc.add_text('**Source Specification:** see %s %s %s' % (ns_src_doc.get_numbered_reference(ns_src_label),
                                                                            ns_src_doc.newline,
                                                                            ns_src_doc.newline))
        # Create a list with further details about the namespace, e.g., name, version, authors etc.
        desc_list = []
        if 'doc' in curr_namespace:
            desc_list.append('**Description:** %s' % str(curr_namespace['doc']))
        if 'name' in curr_namespace:
            desc_list.append('**Name:** %s' % str(curr_namespace['name']))
        if 'full_name' in curr_namespace:
            desc_list.append('**Full Name:** %s' % str(curr_namespace['full_name']))
        if 'version' in curr_namespace:
            desc_list.append('**Version:** %s' % str(curr_namespace['version']))
        if 'date' in curr_namespace:
            desc_list.append('**Date:** %s' % str(curr_namespace['date']))
        if 'author' in curr_namespace:
            if isinstance(curr_namespace['author'], list):
                desc_list.append('**Authors:**')
                desc_list.append(curr_namespace['author'])
            else:
                desc_list.append('**Author:** %s' % str(curr_namespace['author']))
        if 'contact' in curr_namespace:
            if isinstance(curr_namespace['contact'], list):
                desc_list.append('**Contacts:**')
                desc_list.append(curr_namespace['contact'])
            else:
                desc_list.append('**Contact:** %s' % str(curr_namespace['contact']))
        if 'schema' in curr_namespace:
            desc_list.append('**Schema:**')
            schema_list =[]
            for s in curr_namespace['schema']:
                curr_str = ""
                if isinstance(s, dict):
                    for k,v in s.items():
                        curr_str += '**%s:** %s ' %(str(k), str(v))
                else:
                    curr_str = str(s)
                schema_list.append(curr_str)
            desc_list.append(schema_list)
        # Render the list with the descripiton of the namespace
        if len(desc_list) > 0:
            ns_desc_doc.add_list(desc_list,
                                 item_symbol='-'
                                 )
    # Include the type hierarchy document if requested
    if type_hierarchy_include:
        if type_hierarchy_include_in_html_only:
            ns_desc_doc.add_text('.. only:: html %s%s' % (ns_desc_doc.newline, ns_desc_doc.newline))
            ns_desc_doc.add_include(type_hierarchy_include, indent='    ')
            ns_desc_doc.add_text(ns_desc_doc.newline)
        else:
            ns_desc_doc.add_include(type_hierarchy_include)

    if src_doc:
        if seperate_src_file:
            ns_src_doc.add_label(ns_src_label)
            ns_src_doc.add_subsection(sec_heading)
            ns_src_doc.add_text('**Description:** see %s' % ns_src_doc.get_numbered_reference(ns_desc_label) + ns_src_doc.newline + ns_src_doc.newline)

        if show_json_src:
            ns_src_doc.add_text('**JSON Specification:**' + ns_src_doc.newline + ns_src_doc.newline)
            ns_src_doc.add_spec(curr_namespace, show_json=True, show_yaml=False)
        if show_yaml_src:
            ns_src_doc.add_text('**YAML Specification:**' + ns_src_doc.newline + ns_src_doc.newline)
            ns_src_doc.add_spec(curr_namespace, show_json=False, show_yaml=True)

    # Save the output files if necessary
    if file_per_type and file_dir is not None:
        # Write the files for the source and description
        ns_src_filename = os.path.join(file_dir, '%s_namespace_source.inc' % namespace_name)
        ns_desc_filename = os.path.join(file_dir, '%s_namespace_description.inc' % namespace_name)
        if desc_doc:
            ns_desc_doc.write(ns_desc_filename, 'w')
            PrintCol.print("    " + namespace_name + '-- WRITE NAMESPACE DESCRIPTION DOC OK.', PrintCol.OKGREEN)
            # Include the files in the main documents
            desc_doc.add_include(os.path.basename(file_dir) + "/" + os.path.basename(ns_desc_filename))
        if src_doc:
            ns_src_doc.write(ns_src_filename, 'w')
            PrintCol.print("    " + namespace_name + '-- WRITE NAMESPACE SOURCE DOC OK.', PrintCol.OKGREEN)
            # Include the files in the main documents
            src_doc.add_include(os.path.basename(file_dir) + "/" + os.path.basename(ns_src_filename))


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
        target_doc.add_label(section_label)
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

def create_spec_table(spec,
                      rst_table=None,
                      depth=0,
                      show_subattributes=True,
                      show_subdatasets=True,
                      show_sublinks=True,
                      show_subgroups=False,
                      recursive=False,
                      appreviate_main_object_doc=True):
    """
    Create and RSTTable with an overview of the specification for the given spec

    :param spec: The specification to be rendered
    :param rst_table: The RSTTable to be expanded (usually None). This argument is used to recursively fill the table.
    :param depth: The depth at which the current spec should appear in the table. This argument is used to
                  recursively fill the table and will typically left as 0 when called externally.
    :param show_subgroups: Boolean indicating whether to recursively include subgroups (default=False)
    :return: RSTTable that can be rendered into and RSTDocuement via the RSTTable.render(...) function.
    """
    # Create a new table if necessary
    rst_table = rst_table if rst_table is not None else RSTTable(cols=['Id', 'Type', 'Description']) #, ' Quantity'])

    ###########################################
    #  Render the row for the current object
    ###########################################
    # Determine the type of the object
    spec_type = 'group' if isinstance(spec, GroupSpec) else \
                'dataset'if isinstance(spec, DatasetSpec) else \
                'attribute' if isinstance(spec, AttributeSpec) else \
                'link'
    # Determine the name of the object
    depth_str = spec_table_depth_char * depth
    if spec.get('name', None) is not None:
        spec_name = depth_str + spec.name
    elif spec.get('neurodata_type_def',None) is not None:
        spec_name = depth_str +  '<%s>' % spec.neurodata_type_def
    elif spec_type == 'link':
        spec_name = depth_str +  '<%s>' % RSTDocument.get_reference(get_section_label(spec.data_type_inc), spec.data_type_inc)
    elif spec.get('neurodata_type_inc', None) is not None:
        spec_name = depth_str +  '<%s>' % RSTDocument.get_reference(get_section_label(spec.neurodata_type_inc), spec.neurodata_type_inc)
    else:
        spec_name = depth_str +  '<%s>' % RSTDocument.get_reference(get_section_label(spec.neurodata_type), spec.neurodata_type)
    spec_quantity = quantity_to_string(spec.quantity) \
                    if not (isinstance(spec, AttributeSpec) or isinstance(spec, LinkSpec)) \
                    else ""

    # Create the doc description of the spec
    if appreviate_main_object_doc and depth==0:
        # Create the appreviated descripiton of the main object
        spec_doc = "Top level %s for %s" % (spec_type, spec_name.lstrip(depth_str))
        spec_doc += spec_prop_doc(spec, rst_table.newline)
    else:
        # Create the description for the object
        spec_doc = clean_doc(spec.doc, add_prefix=rst_table.newline+rst_table.newline)
        # Create the list of additonal object properties to be added as a list ot the doc
        spec_doc += spec_prop_doc(spec, rst_table.newline)

    # Render the object to the table
    rst_table.add_row(row_values=[spec_name, spec_type, spec_doc], #, spec_quantity],
                      replace_none='',
                      convert_to_str=True)

    ###########################################
    #  Recursively add the subobject if requested
    ###########################################
    # Recursively add all attributes of the current spec
    if (isinstance(spec, DatasetSpec) or isinstance(spec, GroupSpec)) and show_subattributes:
        for a in spec.attributes:
            create_spec_table(a, rst_table, depth=depth+1)
    # Recursively add all Datasets of the current spec
    if isinstance(spec, GroupSpec) and show_subdatasets:
        for d in spec.datasets:
            create_spec_table(d, rst_table, depth=depth+1)
    # Recursively add all Links for the current spec
    if isinstance(spec,GroupSpec) and show_sublinks:
        for l in spec.links:
            create_spec_table(l, rst_table, depth=depth+1)
    # Recursively add all subgroups if requested
    if show_subgroups and isinstance(spec, GroupSpec):
        if recursive:
            for g in spec.groups:
                create_spec_table(g,
                                  rst_table,
                                  depth=depth+1,
                                  show_subgroups=show_subgroups,
                                  show_subdatasets=show_subdatasets,
                                  show_subattributes=show_subattributes)
        else:
            for g in spec.groups:
                create_spec_table(g, rst_table,
                                  depth=depth+1,
                                  recursive=recursive,
                                  show_subgroups=False,
                                  show_subattributes=False,
                                  show_subdatasets=False)
    # Return the created table
    return rst_table


def render_group_specs(group_spec, rst_doc, parent=None):

    parent = parent if parent is not None else ''
    group_name = ''
    if group_spec.get('name', None) is not None:
        group_name = group_spec.name
    elif group_spec.get('neurodata_type_def', None) is not None:
        group_name = "<%s>" % group_spec.neurodata_type_def
    elif group_spec.get('neurodata_type_inc', None) is not None:
        group_name =  "<%s>" % group_spec.neurodata_type_inc
    else:
        warnings.warn("Could not determine name for group %s" % str(group_spec))
    if group_name == '':
        raise ValueError('Could not determine name of group')
    rst_doc.add_paragraph("Groups: %s%s" % (parent,group_name))
    # Compile the documentation for the group
    gdoc = clean_doc(group_spec.doc,
                     add_prefix=rst_doc.newline+rst_doc.newline, #+' ',
                     add_postifix=rst_doc.newline,
                     rst_format='**')

    gdoc += rst_doc.newline
    gdoc += spec_prop_doc(group_spec, rst_doc.newline)
    # Add the group documentation to the RST document
    rst_doc.add_text(gdoc)
    rst_doc.add_text(rst_doc.newline)
    # Create the table with the dataset and attributes specifications for the group
    group_spec_data_table = create_spec_table(group_spec,
                                         show_subgroups=not spec_show_subgroups_in_seperate_table,
                                         appreviate_main_object_doc=spec_appreviate_main_object_doc_in_tables)
                                         #, table_class='longtable', widths=[15, 15, 60 ,10])
    # Add the table for the group spec only if there is more than one entry, i.e.,
    # only if there is additonal information in the table about the content of the group, rather
    # than just only the group itself in the table
    if group_spec_data_table.num_rows() > 1:
        group_spec_data_table_title = None
        if spec_show_title_for_tables:
            if not spec_show_subgroups_in_seperate_table:
                group_spec_data_table_title = "Groups, Datasets, and Attributes contained in ``%s%s``" % (parent,group_name)
            else:
                group_spec_data_table_title = "Datasets, Links, and Attributes contained in ``%s%s``" % (parent,group_name)
        rst_doc.add_table(rst_table=group_spec_data_table,
                          title=group_spec_data_table_title,
                          latex_tablecolumns=CUSTOM_LATEX_TABLE_COLUMNS)
                          # table_ref=get_data_table_label(group_name))

    # Add a table with all the subgroups of this group
    if spec_show_subgroups_in_seperate_table:
        group_spec_groups_table = create_spec_table(group_spec,
                                                    show_subattributes=False,
                                                    show_subdatasets=False,
                                                    show_subgroups=True,
                                                    recursive=False,
                                                    appreviate_main_object_doc=spec_appreviate_main_object_doc_in_tables)
        # Only show the subgroups if it contains additional information
        if group_spec_groups_table.num_rows() > 1:
            group_spec_groups_table_title = None
            if spec_show_title_for_tables:
                group_spec_groups_table_title = "Groups contained in <%s>" % group_name
            rst_doc.add_table(group_spec_groups_table,
                              title=group_spec_groups_table_title,
                              latex_tablecolumns=CUSTOM_LATEX_TABLE_COLUMNS)
                              # table_ref=get_group_table_label(group_name))


    # Recursively render paragraphs for all the subgroups of this group
    for sg in group_spec.groups:
        render_group_specs(sg, rst_doc, parent=parent+group_name+'/')


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

    :param neurodata_types: List of string with the names of types that should be rendered or OrderedDict where
                          the keys are neurodata_type strings and the values are NeurodataTypeDict
    :param spec_catalog: Catalog of specifications
    :param desc_doc: RSTDocument where the descriptions of the documents should be rendered
    :param src_doc: RSTDocument where the YAML/JSON sources of the neurodata_types should be rendered. Set to None
                    if sources should be rendered in the desc_doc directly.
    :param file_dir: Directory where figures and outpy RST docs should be stored
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
        extend_type =   rt_spec.get('neurodata_type_inc', None)
        # Define the docs we need to write to
        type_desc_doc = desc_doc if not file_per_type else RSTDocument()
        type_src_doc  = src_doc if not file_per_type else RSTDocument()

        #######################################################
        #  Create the base documentation for the current type
        #######################################################
        # Create the section heading and label
        type_desc_doc.add_label(get_section_label(rt))
        section_heading = rt # if extend_type is None else "%s extends %s" % (rt, type_desc_doc.get_reference(get_section_label(extend_type), extend_type))
        type_desc_doc.add_subsubsection(section_heading)
        if extend_type is not None:
            type_desc_doc.add_text('**Extends:** %s' % type_desc_doc.get_reference(get_section_label(extend_type), extend_type) + type_desc_doc.newline + type_desc_doc.newline)
        if seperate_src_file:
            # Add a link to the source to the main document
            type_desc_doc.add_text('**Source Specification:** see %s' %
                                   type_desc_doc.get_numbered_reference(label=get_src_section_label(rt)))
            type_desc_doc.add_text(type_desc_doc.newline + type_desc_doc.newline)

        type_desc_doc.add_text('**Overview:** ')# + type_desc_doc.newline + type_desc_doc.newline)
        # Add the document string for the neurodata_type to the document
        rt_clean_doc = clean_doc(rt_spec['doc'],
                                 add_prefix=type_desc_doc.newline+type_desc_doc.newline,
                                 add_postifix=type_desc_doc.newline,
                                 rst_format='**')
        type_desc_doc.add_text(rt_clean_doc)
        type_desc_doc.add_text(type_desc_doc.newline + type_desc_doc.newline)
        # Add note if necessary to indicate that the following documentation only shows changes to the parent class
        if extend_type is not None:
            extend_type =  rt_spec['neurodata_type_inc']
            sentence_end = " with the following additions or changes." \
                if not spec_resolve_type_inc \
                else ". The following is a description of the complete structure of ``%s`` including all inherited components." % rt
            type_desc_doc.add_text("``%s`` extends ``%s`` (see %s) and includes all elements of %s%s" %
                         (rt,
                          extend_type,
                          type_desc_doc.get_numbered_reference(get_section_label(extend_type)),
                          type_desc_doc.get_reference(get_section_label(extend_type), extend_type),
                          sentence_end))
            type_desc_doc.add_text(type_desc_doc.newline + type_desc_doc.newline)
        # Add the additional details about the doc
        type_desc_doc.add_text(spec_prop_doc(rt_spec,
                                             type_desc_doc.newline,
                                             ignore_props=['neurodata_type_inc', 'neurodata_type_def', 'default_name', 'name']))
        type_desc_doc.add_text(type_desc_doc.newline)

        ##################################################
        # Render the graph for the spec if necessary
        #################################################
        if INCLUDE_GRAPHS:
            try:
                if show_hierarchy_plots:
                    temp = HierarchyDescription.from_spec(rt_spec)
                    temp_graph = NXGraphHierarchyDescription(temp)
                    temp_figsize = temp_graph.suggest_figure_size()
                    temp_xlim = temp_graph.suggest_xlim()
                    temp_ylim = None # temp_graph.suggest_ylim()
                    if len(temp_graph.graph.nodes(data=False)) > 2:
                        fig = temp_graph.draw(show_plot=False,
                                              figsize=temp_figsize,
                                              xlim=temp_xlim,
                                              ylim=temp_ylim,
                                              label_font_size=10)
                        plt.savefig(os.path.join(file_dir, '%s.pdf' % rt),
                                    format='pdf',
                                    bbox_inches='tight',
                                    pad_inches = 0)
                        plt.savefig(os.path.join(file_dir, '%s.png' % rt),
                                    format='png', dpi=300,
                                    bbox_inches='tight',
                                    pad_inches = 0)
                        plt.close()
                        type_desc_doc.add_figure(img='./_format_auto_docs/'+rt+".*", alt=rt)
                        PrintCol.print("    " + rt + '-- RENDER OK.', PrintCol.OKGREEN)
                    else:
                       PrintCol.print("    " + rt + '-- SKIPPED RENDER HIERARCHY. TWO OR FEWER NODES.', PrintCol.OKBLUE)
                else:
                    PrintCol.print("    " + rt + '-- SKIPPED RENDER HIERARCHY. See conf.py', PrintCol.OKBLUE)
            except (KeyboardInterrupt, SystemExit):
                raise
            except:
                PrintCol.print(rt + '-- RENDER HIERARCHY FAILED', PrintCol.FAIL)
        else:
            if show_hierarchy_plots:
                PrintCol.print(rt + '-- RENDER HIERARCHY FAILED DUE TO MISSING PACKAGES', PrintCol.FAIL)

        ####################################################################
        #  Add the YAML and/or JSON sources to the document if requested
        ####################################################################
        # If the JSON/YAML are shown in a seperate chapter than add section headings
        if seperate_src_file:
            # Add a section to the file for the sources
            src_sec_lable = get_src_section_label(rt)
            type_src_doc.add_label(src_sec_lable)
            type_src_doc.add_subsubsection(section_heading)
            if extend_type is not None:
                type_src_doc.add_text('**Extends:** %s' % type_src_doc.get_reference(get_section_label(extend_type), extend_type) + type_src_doc.newline + type_src_doc.newline)
            type_src_doc.add_text('**Description:** see %s' % type_src_doc.get_numbered_reference(get_section_label(rt)) + type_src_doc.newline + type_src_doc.newline)

        # Add the YAML for the current spec
        if show_yaml_src:
            type_src_doc.add_text('**YAML Specification:**' + type_src_doc.newline + type_src_doc.newline)
            type_src_doc.add_spec(rt_spec, show_json=False, show_yaml=True)
        # Add the JSON for the current spec
        if show_json_src:
            type_src_doc.add_text('**JSON Specification:**' + type_src_doc.newline + type_src_doc.newline)
            type_src_doc.add_spec(rt_spec, show_json=True, show_yaml=False)

        #############################################################################
        #  Add table with dataset and attribute descriptions for the neurodata_type
        ############################################################################
        type_desc_doc.add_text(type_desc_doc.newline)
        rt_spec_data_table = create_spec_table(rt_spec,
                                               show_subgroups=not spec_show_subgroups_in_seperate_table,
                                               appreviate_main_object_doc=spec_appreviate_main_object_doc_in_tables)
        # Only show the datasets and attributes table if it contains additional information
        if rt_spec_data_table.num_rows() > 1:
            rt_spec_data_table_title = None
            if spec_show_title_for_tables:
                if not spec_show_subgroups_in_seperate_table:
                    rt_spec_data_table_title = "Groups, Datasets, Links, and Attributes contained in <%s>" % rt
                else:
                    rt_spec_data_table_title = "Datasets, Links, and Attributes contained in <%s>" % rt
            type_desc_doc.add_table(rt_spec_data_table,
                                    title=rt_spec_data_table_title,
                                    table_ref=get_data_table_label(rt),
                                    latex_tablecolumns=CUSTOM_LATEX_TABLE_COLUMNS)

        #############################################################################
        #  Add table with the main subgroups for the neurodata_type
        ############################################################################
        if spec_show_subgroups_in_seperate_table:
            type_desc_doc.add_text(type_desc_doc.newline)
            rt_spec_group_table = create_spec_table(rt_spec,
                                                   show_subattributes=False,
                                                   show_subdatasets=False,
                                                   show_subgroups=True,
                                                   recursive=False,
                                                   appreviate_main_object_doc=spec_appreviate_main_object_doc_in_tables)
            # Only show the datasets and attributes table if it contains additional information
            if rt_spec_group_table.num_rows() > 1:
                rt_spec_group_table_title = None
                if spec_show_title_for_tables:
                    rt_spec_group_table_title = "Groups contained in <%s>" % rt
                type_desc_doc.add_table(rt_spec_group_table,
                                        title=rt_spec_group_table_title,
                                        table_ref=get_group_table_label(rt),
                                        latex_tablecolumns=CUSTOM_LATEX_TABLE_COLUMNS)

        ######################################################
        # Add tables for all subgroups
        #####################################################
        if isinstance(rt_spec, GroupSpec):
            for g in rt_spec.groups:
                render_group_specs(group_spec=g, rst_doc=type_desc_doc, parent='' if rt != 'NWBFile' else '/')

        ########################################
        #  Write the type-sepcific files
        #########################################
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

        #####################################
        # Add a clearpage command for latex
        # ######################################
        # to avoid possible troubles with figure placement outside of the current section we add a new page in
        # LaTeX after each main section
        if spec_add_latex_clearpage_after_ndt_sections:
            if seperate_src_file:
                src_doc.add_latex_clearpage()
            desc_doc.add_latex_clearpage()

def compute_neurodata_type_hierarchy(spec_catalog):
    """
    Sort and group specifications based on their neurodata_type to compute the hiearchy of types

    :param spec_catalog: The catalog of specifications to be rendered

    :return:
        * `type_hierarchy` : Nested collection of OrderedDicts. The keys in the OrderedDicts are the
                             neurodata_type string. The values of are dicts with the following keys:
                             `spec` with the specification of the class, `ancestry` with a list of
                             types the object inherits from, and `subtypes` with a nested OrderedDict
                             describing the subtypes.
        * `flat_type_hiearchy` : Flattened type hierarchy. This is an OrderedDict containing all types
                             and their descriptions. This is the same as type_hierarchy, but instead of
                             a nested dict all types are part of the top-level dict.

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
            if rt_spec.get('neurodata_type_inc', None) == neurodata_type  and rt_spec.get('neurodata_type_def', None) != neurodata_type:
                subtypes[rt] = NeurodataTypeDict(neurodata_type=rt,
                                                 spec=rt_spec,
                                                 ancestry=ancestry,
                                                 subtypes=find_subtypes(spec_catalog,
                                                                        registered_types,
                                                                        rt,
                                                                        ancestry + [rt,]))
        return subtypes

    for rt in registered_types:
        rt_spec = spec_catalog.get_spec(rt)
        if rt_spec.get('neurodata_type_inc', None) is None:
            type_hierarchy[rt] = NeurodataTypeDict(neurodata_type=rt,
                                                   spec=spec_catalog.get_spec(rt),
                                                   ancestry=[],
                                                   subtypes=find_subtypes(spec_catalog, registered_types, rt, [rt]))

    def flatten_hierarchy(type_hierarchy, flat_type_hierarchy):
        """
        Take the object hierarchy and flatten it to dict with a single level

        :param type_hierarchy:
        :param flat_type_hierarchy:
        :return:
        """
        for k, v in type_hierarchy.items():
            flat_type_hierarchy[k] = v
            flatten_hierarchy(v['subtypes'], flat_type_hierarchy)
        return flat_type_hierarchy

    flat_type_hierarchy = flatten_hierarchy(type_hierarchy, OrderedDict())

    # Check that we actually included all the types. If the above code is correct, we should have captured all types.
    for rt in registered_types:
        if rt not in flat_type_hierarchy:
            PrintCol.print('ERROR -- Type missing in type hierarchy: %s' % rt , PrintCol.FAIL)
            type_hierarchy[rt] = NeurodataTypeDict(neurodata_type=rt,
                                                   spec=spec_catalog.get_spec(rt),
                                                   ancestry=[],
                                                   subtypes=OrderedDict())

    return type_hierarchy, flat_type_hierarchy


def sort_type_hierarchy_to_sections(type_hierarchy, registered_types):
    """
    From the type hierarchy create a list with descriptions of how to organize the types into sections

    :param type_hierarchy: The input type hierarchy as compute by compute_neurodata_type_hierarchy
    :return: List of NeurodataTypeSections


    """
    sections = []
    all_types = {k: False for k in registered_types}

    def get_list_of_subtypes(spec, subtypes=None, include_main_type=True, exclude=None):
        """Compile a list of all objects of a given type

        :param spec: Select spec computed via compute_neurodata_type_hierarchy(..)
        :param subtypes: OrderedDict with already detected subtypes. Used for recursive detection of types.
                         Usually just left as None.
        :param include_main_type: Boolean indicating whether the main type given by spec should be added to the list.
        :param exclude: List of strings with types to be excluded from the list.
        """
        if subtypes is None:
            subtypes = OrderedDict()
            if include_main_type:
                subtypes[spec['neurodata_type']] = spec
        for k, v in spec['subtypes'].items():
            if exclude is None or k not in exclude:
                subtypes[k] = v
                get_list_of_subtypes(spec=v , subtypes=subtypes, include_main_type=True, exclude=exclude)
        return subtypes

    # NWB-File gets its own section
    try:
        nwb_file_subtypes = get_list_of_subtypes(type_hierarchy['NWBContainer']['subtypes']['NWBFile'])
    except:
        nwb_file_subtypes = []
    if len(nwb_file_subtypes) > 0:
        sections.append(NeurodataTypeSection('Main Data File', nwb_file_subtypes))
        for k in nwb_file_subtypes.keys():
            all_types[k] = True

    # Time-series get their own section
    try:
        time_series_subtypes = get_list_of_subtypes(type_hierarchy['NWBContainer']['subtypes']['TimeSeries'])
    except:
        time_series_subtypes = []
    if len(time_series_subtypes) > 0:
        sections.append(NeurodataTypeSection('TimeSeries Types', time_series_subtypes))
        for k in time_series_subtypes.keys():
            all_types[k] = True

    # Analyse modules get their own section
    analysis_modules_section = NeurodataTypeSection('Data Processing')
    try:
        module_subtypes = get_list_of_subtypes(type_hierarchy['NWBContainer']['subtypes']['ProcessingModule'])
    except:
        module_subtypes = []
    if len(module_subtypes) > 0:
        for k, v in module_subtypes.items():
            analysis_modules_section['neurodata_types'][k] = v
            all_types[k] = True

    # NWB Containers get their own section
    try:
        interface_subtypes = get_list_of_subtypes(type_hierarchy['NWBContainer'],
                                                  include_main_type=False,
                                                  exclude=['Device', 'ElectrodeGroup', 'Epoch']) # 'IntracellularElectrode', 'Image', 'EpochTimeSeries', 'OpticalChannel', 'OptogeneticStimulusSite', 'ROI', 'CorrectedImageStack', 'SpecFile', 'PlaneSegmentation', 'Epoch', 'ImagePlane', 'SpikeUnit'])  # List those types under Others as they are not commonly part of ProcessingModules
    except:
        interface_subtypes = []
    if len(interface_subtypes) > 0:
        for k, v in interface_subtypes.items():
            if not all_types[k]:  # Avoid duplicate listing of types
                analysis_modules_section['neurodata_types'][k] = v
                all_types[k] = True
    sections.append(analysis_modules_section)

    # Section for all other neurodata types that have not been sorted into the hierarchy yet.
    other_types_section = NeurodataTypeSection('Other Types')
    for k, v in all_types.items():
        if not v:
            other_types_section['neurodata_types'][k] = v
    sections.append(other_types_section)

    return sections


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


def print_sections(type_sections):
    """
    Helper function to print sorting of neurodata_type to sections

    :param type_sections: OrderedDict of sections created by the function sort_type_hierarchy_to_sections(...)
    :return:
    """
    for sec in type_sections:
        PrintCol.print(sec['title'], PrintCol.OKBLUE+PrintCol.BOLD)
        PrintCol.print(str(list(sec['neurodata_types'].keys())), PrintCol.OKBLUE)


def load_nwb_namespace(namespace_file, default_namespace='core', resolve=spec_resolve_type_inc):
    """
    Load an nwb namespace from file
    :return:
    """
    namespace = NamespaceCatalog(default_namespace,
                                 group_spec_cls=NWBGroupSpec,
                                 dataset_spec_cls=NWBDatasetSpec,
                                 spec_namespace_cls=NWBNamespace)
    namespace.load_namespaces(namespace_file, resolve=resolve)
    default_spec_catalog = namespace.get_namespace('core').catalog
    return namespace, default_spec_catalog


def main():

    # Set the output path for the doc sources to be generated
    file_dir = spec_output_dir
    # Set the dir where the input YAML files are located
    spec_dir = spec_input_spec_dir
    # Set the names of the main output files
    doc_filename = os.path.join(file_dir, spec_output_doc_filename)  # Name of the file where the main documentation goes
    srcdoc_filename = os.path.join(file_dir, spec_output_src_filename ) if spec_generate_src_file else None  # Name fo the file where the source YAML/JSON of the specifications go
    master_filename = os.path.join(file_dir, spec_output_master_filename)
    type_hierarchy_doc_filename = os.path.join(file_dir, spec_output_doc_type_hierarchy_filename)
    core_namespace_file = os.path.join(spec_dir, spec_input_namespace_filename)

    # Create the ouptu directory if necessary
    if not os.path.exists(file_dir):
        PrintCol.print('Generating output directory: %s' % file_dir, col=PrintCol.OKGREEN)
        os.mkdir(file_dir)
    else:
        PrintCol.print('Output directory already exists: %s' % file_dir, col=PrintCol.OKGREEN)

    # Load the core namespace
    core_namespace, spec_catalog = load_nwb_namespace(namespace_file=core_namespace_file,
                                                      default_namespace=spec_input_default_namespace,
                                                      resolve=spec_resolve_type_inc)

    # Generate the hierarchy of types
    print("BUILDING TYPE HIERARCHY")
    registered_types = spec_catalog.get_registered_types()
    type_hierarchy, flat_type_hierarchy = compute_neurodata_type_hierarchy(spec_catalog)
    print_type_hierarchy(type_hierarchy, show_ancestry=False)

    # Sorting types into sections
    print("SORTING TYPES INTO SECTIONS")
    type_sections = sort_type_hierarchy_to_sections(type_hierarchy, registered_types)
    print_sections(type_sections)


    # Create the documentation RST file
    desc_doc =  RSTDocument()

    # Create the RST file for source files or use the main document in case sources should be included in the main doc directly
    if spec_generate_src_file:
        src_doc = RSTDocument()
        src_doc.add_label("nwb-type-specification-sources")
        src_doc.add_section("Sources")
    else:
        src_doc = None

     # Create the master doc
    masterdoc = RSTDocument()
    masterdoc.add_include(os.path.basename(file_dir) + "/" + os.path.basename(doc_filename))
    if src_doc is not None:
        masterdoc.add_include(os.path.basename(file_dir) + "/" + os.path.basename(srcdoc_filename))

    # Create type hierarchy document
    print("RENDERING TYPE HIERARCHY")
    #desc_doc.add_section("Type Overview")
    type_hierarchy_doc = render_type_hierarchy(type_hierarchy=type_hierarchy)
    type_hierarchy_doc.write(type_hierarchy_doc_filename, 'w')
    # desc_doc.add_include(os.path.basename(file_dir) + "/" + os.path.basename(type_hierarchy_doc_filename))

    print("RENDERING NAMESPACE SPECIFICATION")
    # Create the namespace document
    render_namespace(namespace_catalog=core_namespace,
                     namespace_name=spec_input_default_namespace,
                     desc_doc=desc_doc,
                     src_doc=src_doc,
                     show_json_src=spec_show_json_src,
                     show_yaml_src=spec_show_yaml_src,
                     file_dir=file_dir,
                     file_per_type=spec_file_per_type,
                     type_hierarchy_include=os.path.basename(file_dir) + "/" + os.path.basename(type_hierarchy_doc_filename),
                     type_hierarchy_include_in_html_only=True)

    # Create the section for the format specification
    print("RENDERING TYPE SPECIFICATIONS")
    desc_doc.add_latex_clearpage() # Add a clearpage command for latex to avoid possible troubles with figure placement outside of the current section
    desc_doc.add_label("nwb-type-specifications")
    desc_doc.add_section("Specifications")

    # Render all the sections with the different types
    sec_index = 0
    for sec in type_sections:
        if sec_index > 0:
            desc_doc.add_latex_clearpage()
        desc_doc.add_label(sec['title'].replace(' ', '_'))
        desc_doc.add_subsection(sec['title'])
        if src_doc is not None:
            src_doc.add_label(sec['title'].replace(' ', '_') + '_src')
            src_doc.add_subsection(sec['title'])

        # Render all registered documents for the current section
        render_specs(neurodata_types=sec['neurodata_types'],    #sorted(registered_types),
                     spec_catalog=spec_catalog,
                     desc_doc=desc_doc,
                     src_doc=src_doc,
                     file_dir=file_dir,
                     show_hierarchy_plots=spec_show_hierarchy_plots,
                     show_json_src=spec_show_json_src,
                     show_yaml_src=spec_show_yaml_src,
                     file_per_type=spec_file_per_type)
        sec_index += 1

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

