from subprocess import check_call, CalledProcessError
import argparse
import os
from generate_format_docs import PrintCol

# TODO Customize the CUSTOM_SETTINGS to include the user settings
# TODO Need to make the conf import customizable in generate_format_docs or we need to set a PYTHONPATH before we run it

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

def get_custom_settings():
    return  \
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

def get_makefile(utilsdir):

    return \
"""
# Makefile for Sphinx documentation
#

# You can set these variables from the command line.
SPHINXOPTS     =
SPHINXBUILD    = sphinx-build
SPHINXAPIDOC   = sphinx-apidoc
PAPER          =
BUILDDIR       = _build
GENUTILSDIR    = %s
SRCDIR         = ../src
RSTDIR         = source
PKGNAME        = pynwb
""" % utilsdir + \
'''

# Internal variables.
PAPEROPT_a4     = -D latex_paper_size=a4
PAPEROPT_letter = -D latex_paper_size=letter
ALLSPHINXOPTS   = -d $(BUILDDIR)/doctrees $(PAPEROPT_$(PAPER)) $(SPHINXOPTS) source
# the i18n builder cannot share the environment and doctrees with the others
I18NSPHINXOPTS  = $(PAPEROPT_$(PAPER)) $(SPHINXOPTS) .

.PHONY: help clean html dirhtml singlehtml pickle json htmlhelp qthelp devhelp epub latex latexpdf text man changes linkcheck doctest gettext fulldoc allclean

help:
	@echo "To update documentation sources from the format specification please use \`make apidoc'"
	@echo ""
	@echo "To build the documenation please use \`make <target>' where <target> is one of"
	@echo "  fulldoc    to rebuild the apidoc, html, and latexpdf all at once"
	@echo "  html       to make standalone HTML files"
	@echo "  dirhtml    to make HTML files named index.html in directories"
	@echo "  singlehtml to make a single large HTML file"
	@echo "  pickle     to make pickle files"
	@echo "  json       to make JSON files"
	@echo "  htmlhelp   to make HTML files and a HTML help project"
	@echo "  qthelp     to make HTML files and a qthelp project"
	@echo "  devhelp    to make HTML files and a Devhelp project"
	@echo "  epub       to make an epub"
	@echo "  latex      to make LaTeX files, you can set PAPER=a4 or PAPER=letter"
	@echo "  latexpdf   to make LaTeX files and run them through pdflatex"
	@echo "  text       to make text files"
	@echo "  man        to make manual pages"
	@echo "  texinfo    to make Texinfo files"
	@echo "  info       to make Texinfo files and run them through makeinfo"
	@echo "  gettext    to make PO message catalogs"
	@echo "  changes    to make an overview of all changed/added/deprecated items"
	@echo "  linkcheck  to check all external links for integrity"
	@echo "  doctest    to run all doctests embedded in the documentation (if enabled)"
	@echo "  apidoc     to to build RST from source code"
	@echo "  clean      to clean all documents built by Sphinx in _build"
	@echo "  allclean   to clean all autogenerated documents both from Sphinx and apidoc"

allclean:
	-rm -rf $(BUILDDIR)/* $(RSTDIR)/$(PKGNAME)* $(RSTDIR)/modules.rst
	-rm $(RSTDIR)/_format_auto_docs/*.png
	-rm $(RSTDIR)/_format_auto_docs/*.pdf
	-rm $(RSTDIR)/_format_auto_docs/*.rst
	-rm $(RSTDIR)/_format_auto_docs/*.inc

clean:
	-rm -rf $(BUILDDIR)/* $(RSTDIR)/$(PKGNAME)* $(RSTDIR)/modules.rst

html:
	$(SPHINXBUILD) -b html $(ALLSPHINXOPTS) $(BUILDDIR)/html
	@echo
	@echo "Build finished. The HTML pages are in $(BUILDDIR)/html."

dirhtml:
	$(SPHINXBUILD) -b dirhtml $(ALLSPHINXOPTS) $(BUILDDIR)/dirhtml
	@echo
	@echo "Build finished. The HTML pages are in $(BUILDDIR)/dirhtml."

singlehtml:
	$(SPHINXBUILD) -b singlehtml $(ALLSPHINXOPTS) $(BUILDDIR)/singlehtml
	@echo
	@echo "Build finished. The HTML page is in $(BUILDDIR)/singlehtml."

pickle:
	$(SPHINXBUILD) -b pickle $(ALLSPHINXOPTS) $(BUILDDIR)/pickle
	@echo
	@echo "Build finished; now you can process the pickle files."

json:
	$(SPHINXBUILD) -b json $(ALLSPHINXOPTS) $(BUILDDIR)/json
	@echo
	@echo "Build finished; now you can process the JSON files."

htmlhelp:
	$(SPHINXBUILD) -b htmlhelp $(ALLSPHINXOPTS) $(BUILDDIR)/htmlhelp
	@echo
	@echo "Build finished; now you can run HTML Help Workshop with the" \
	      ".hhp project file in $(BUILDDIR)/htmlhelp."

qthelp:
	$(SPHINXBUILD) -b qthelp $(ALLSPHINXOPTS) $(BUILDDIR)/qthelp
	@echo
	@echo "Build finished; now you can run "qcollectiongenerator" with the" \
	      ".qhcp project file in $(BUILDDIR)/qthelp, like this:"
	@echo "# qcollectiongenerator $(BUILDDIR)/qthelp/sample.qhcp"
	@echo "To view the help file:"
	@echo "# assistant -collectionFile $(BUILDDIR)/qthelp/sample.qhc"

devhelp:
	$(SPHINXBUILD) -b devhelp $(ALLSPHINXOPTS) $(BUILDDIR)/devhelp
	@echo
	@echo "Build finished."
	@echo "To view the help file:"
	@echo "# mkdir -p $$HOME/.local/share/devhelp/sample"
	@echo "# ln -s $(BUILDDIR)/devhelp $$HOME/.local/share/devhelp/sample"
	@echo "# devhelp"

epub:
	$(SPHINXBUILD) -b epub $(ALLSPHINXOPTS) $(BUILDDIR)/epub
	@echo
	@echo "Build finished. The epub file is in $(BUILDDIR)/epub."

latex:
	$(SPHINXBUILD) -b latex $(ALLSPHINXOPTS) $(BUILDDIR)/latex
	@echo
	@echo "Build finished; the LaTeX files are in $(BUILDDIR)/latex."
	@echo "Run \`make' in that directory to run these through (pdf)latex" \
	      "(use \`make latexpdf' here to do that automatically)."

latexpdf:
	$(SPHINXBUILD) -b latex $(ALLSPHINXOPTS) $(BUILDDIR)/latex
	@echo "Running LaTeX files through pdflatex..."
	$(MAKE) -C $(BUILDDIR)/latex all-pdf
	@echo "pdflatex finished; the PDF files are in $(BUILDDIR)/latex."

text:
	$(SPHINXBUILD) -b text $(ALLSPHINXOPTS) $(BUILDDIR)/text
	@echo
	@echo "Build finished. The text files are in $(BUILDDIR)/text."

man:
	$(SPHINXBUILD) -b man $(ALLSPHINXOPTS) $(BUILDDIR)/man
	@echo
	@echo "Build finished. The manual pages are in $(BUILDDIR)/man."

texinfo:
	$(SPHINXBUILD) -b texinfo $(ALLSPHINXOPTS) $(BUILDDIR)/texinfo
	@echo
	@echo "Build finished. The Texinfo files are in $(BUILDDIR)/texinfo."
	@echo "Run \`make' in that directory to run these through makeinfo" \
	      "(use \`make info' here to do that automatically)."

info:
	$(SPHINXBUILD) -b texinfo $(ALLSPHINXOPTS) $(BUILDDIR)/texinfo
	@echo "Running Texinfo files through makeinfo..."
	make -C $(BUILDDIR)/texinfo info
	@echo "makeinfo finished; the Info files are in $(BUILDDIR)/texinfo."

gettext:
	$(SPHINXBUILD) -b gettext $(I18NSPHINXOPTS) $(BUILDDIR)/locale
	@echo
	@echo "Build finished. The message catalogs are in $(BUILDDIR)/locale."

changes:
	$(SPHINXBUILD) -b changes $(ALLSPHINXOPTS) $(BUILDDIR)/changes
	@echo
	@echo "The overview file is in $(BUILDDIR)/changes."

linkcheck:
	$(SPHINXBUILD) -b linkcheck $(ALLSPHINXOPTS) $(BUILDDIR)/linkcheck
	@echo
	@echo "Link check complete; look for any errors in the above output " \
	      "or in $(BUILDDIR)/linkcheck/output.txt."

doctest:
	$(SPHINXBUILD) -b doctest $(ALLSPHINXOPTS) $(BUILDDIR)/doctest
	@echo "Testing of doctests in the sources finished, look at the " \
	      "results in $(BUILDDIR)/doctest/output.txt."

apidoc:
	python $(GENUTILSDIR)/generate_format_docs.py
	@echo
	@echo "Generate rst source files from NWB spec."

fulldoc:
	$(MAKE) allclean
	@echo
	@echo "Rebuilding apidoc, html, latexpdf"
	$(MAKE) apidoc
	$(MAKE) html
	$(MAKE) latexpdf
'''


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
    parser.add_argument('--utilsdir', dest='utilsdir', action='store', type=str, required=False, help='Specify where the tool for generating the sources from the YAML files is located.', default="utils")
    parser.add_argument('--no-copy-utils', dest='no_utils_copy', action='store_true', required=False, help="Disable copying of the utils folder from nwb-schema. If set then --utildir should be specified.")
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
    outfile.write(get_custom_settings())
    outfile.close()

def write_theme_overwrites(output):
    static_path = os.path.join(output, 'source/_static')
    if not os.path.exists(static_path):
        os.mkdir(static_path)
    outfilename = os.path.join(static_path, 'theme_overrides.css')
    outfile = open(outfilename, 'w')
    outfile.write(THEME_OVERWRITES)
    outfile.close()

def write_makefile(output, utilsdir):
    outfilename = os.path.join(output, 'Makefile')
    outfile = open(outfilename, 'w')
    outfile.write(get_makefile(utilsdir))
    outfile.close()

def copy_utils(output):
    utilsdir = os.path.dirname(os.path.abspath(__file__))
    try:
        command = ['cp',
                   '-r',
                   utilsdir,
                   output]
        check_call(command, shell=False)
        command = ['cp',
               os.path.join(utilsdir, '../../Legal.txt'),
               os.path.join(output, 'utils')]
        check_call(command, shell=False)
        command = ['cp',
               os.path.join(utilsdir, '../../license.txt'),
               os.path.join(output, 'utils')]
        check_call(command, shell=False)
    except CalledProcessError:
        print("Copy of utils dir failed: " + str(command))

    except CalledProcessError:
        print("Copy of utils dir failed: " + str(command))

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
    write_makefile(output=clargs['output'], utilsdir=clargs['utilsdir'].rstrip('/'))
    if not clargs['no_utils_copy']:
        copy_utils(output=clargs['output'])

if __name__ == "__main__":
    main()

#sphinx-quickstart --quiet --sep -p projectname -a author -v version -r release -l language --master masterdocname --ext-ifconfig --ext-autodoc --no-makefile myproject
