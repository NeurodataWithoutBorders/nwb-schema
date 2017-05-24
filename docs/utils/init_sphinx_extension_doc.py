from subprocess import check_call, CalledProcessError
import argparse
import os
from generate_format_docs import PrintCol

THEME_OVERWRITES = \
"""
/* override table width restrictions */
@media screen and (min-width: 767px) {

   .wy-table-responsive table td {
      /* !important prevents the common CSS stylesheets from overriding
         this as on RTD they are loaded after this stylesheet */
      white-space: normal !important;
   }

   .wy-table-responsive {
      overflow: visible !important;
   }
}

"""

CUSTOM_SETTINGS = \
"""
############################################################################
#  CUSTOM CONFIGURATIONS ADDED BY THE NWB TOOL FOR GENERATING FORMAT DOCS
###########################################################################

import sphinx_rtd_theme

# -- Customize sphinx settings
numfig = True
autoclass_content = 'both'
autodoc_docstring_signature = True
autodoc_member_order = 'bysource'
add_function_parentheses = False


# -- HTML sphinx options
html_theme = "sphinx_rtd_theme"
html_theme_path = [sphinx_rtd_theme.get_html_theme_path()]

# LaTeX Sphinx options
latex_elements = {
# The paper size ('letterpaper' or 'a4paper').
'papersize': 'letterpaper',

# The font size ('10pt', '11pt' or '12pt').
'pointsize': '10pt',

# Additional stuff for the LaTeX preamble.
'preamble':
'''
\setcounter{tocdepth}{3}
\setcounter{secnumdepth}{6}
\\usepackage{enumitem}
\setlistdepth{100}''',
}

def setup(app):
   app.add_stylesheet("theme_overrides.css")  # overrides for wide tables in RTD theme

# -- Options for the generation of the documentation from source ----------------

# Should the YAML sources be included for the different modules
spec_show_yaml_src = True

# Should the JSON sources be included for the different modules
spec_show_json_src = False

# Show figure of the hierarchy of objects defined by the spec
spec_show_hierarchy_plots = True

# Should the sources of the neurodata_types (JSON/YAML) be rendered in a separate section (True) or
# in the same location as the base documentation
spec_generate_src_file = True

# Should separate .inc reStructuredText files be generated for each neurodata_type (True)
# or should all text be added to the main file
spec_file_per_type = True

# Should top-level subgroups be listed in a seperate table or as part of the main dataset and attributes table
spec_show_subgroups_in_seperate_table = True

# Appreviate the documentation of the main object for which a table is rendered in the table.
# This is commonly set to True as doc of the main object is alrready rendered as the main intro for the
# section describing the object
spec_appreviate_main_object_doc_in_tables = True

# Show a title for the tables
spec_show_title_for_tables = True

# Char to be used as prefix to indicate the depth of an object in the specification hierarchy
spec_table_depth_char = '.' # '→' '.'

# Add a LaTeX clearpage after each main section describing a neurodata_type. This helps in LaTeX to keep the ordering
# of figures, tables, and code blocks consistent in particular when the hierarchy_plots are included
spec_add_latex_clearpage_after_ndt_sections = True

# Resolve includes to always show the full list of objects that are part of a type (True)
# or to show only the parts that are actually new to a current type while only linking to base types
spec_resolve_type_inc = False

"""


def define_cl_args():
    """
    Create the argument parser for the script
    :return: argparse.ArgumentParser
    """

    parser = argparse.ArgumentParser(description='Create format specification SPHINX documenation for an NWB extension.',
                                     add_help=True,
                                     epilog="\n Copyright: Lawrence Berkeley National Laboratory: 2017")
    parser.add_argument('--project', dest='project', action='store', type=str, required=True, help='Name of the project')
    parser.add_argument('--author', dest='author', action='store', type=str, required=True, help='Name of the author(s). Enclose in "..." if contains whitespaces')
    parser.add_argument('--version', dest='version', action='store', type=str, required=True, help='Version of the project/docs')
    parser.add_argument('--release', dest='release', action='store', type=str, required=True, help='Release of the project/docs')
    parser.add_argument('--language', dest='language', action='store', type=str, required=False, help='Document language', default='English')
    parser.add_argument('--master', dest='master', action='store', type=str, required=False, help='Master document name', default='index')
    parser.add_argument('--output', dest='output', action='store', type=str, required=True, help='Project directory for the project')
    return parser

def init_sphinx(project, author, version, release, language, master, output):

    command = ['sphinx-quickstart',
               '--quiet',
               '--sep',
               '-p',
               project,
               '-a',
               author,
               '-v',
               version,
               '-r',
               release,
               '-l',
               language,
               '--master',
               master,
               '--ext-ifconfig',
               '--ext-autodoc',
               '--no-makefile',
               output]
    try:
        check_call(command, shell=False)
    except CalledProcessError:
        exit(0)

def write_custom_conf(output):
    # Write the custom settings file
    outfilename = os.path.join(output, 'source/conf.py')
    outfile = open(outfilename, 'a')
    outfile.write(CUSTOM_SETTINGS)
    outfile.close()

def write_theme_overwrites(output):
    static_path = os.path.join(output, 'source/_static')
    if not os.path.exists(static_path):
        os.mkdir(static_path)
    outfilename = os.path.join(static_path, 'theme_overrides.css')
    outfile = open(outfilename, 'w')
    outfile.write(THEME_OVERWRITES)
    outfile.close()




def main():
    parser = define_cl_args()
    clargs = vars(parser.parse_args())
    clargs['output'] = os.path.abspath(clargs['output'])
    init_sphinx(project=clargs['project'],
                author=clargs['author'],
                version=clargs['version'],
                release=clargs['release'],
                language=clargs['language'],
                master=clargs['master'],
                output=clargs['output'])
    write_theme_overwrites(output=clargs['output'])
    write_custom_conf(output=clargs['output'])

if __name__ == "__main__":
    main()

#sphinx-quickstart --quiet --sep -p projectname -a author -v version -r release -l language --master masterdocname --ext-ifconfig --ext-autodoc --no-makefile myproject
