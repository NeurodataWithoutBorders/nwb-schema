**Overview**

The documentation for NWB-N consists of a series of documents describing the various components of NWB-N:

* ``docs/language`` with the documentation for the NWB-N specification language
* ``docs/format`` with the documentation of the NWB-N data format
* ``doc/storage`` with the documentation of the NWB-N storage component
* The documentation of the PyNWB API is managed in the PyNWB git repo

In addition to the above folders, ``/docs`` contains the following additional components:

* ``docs/utils`` Python sources used for generating documentation
    * ``docs/utils/generate_format_docs.py`` is used by ``docs/format`` to auto-generate documentation for
      the NWB-N format from the YAML sources
    * ``docs/utils/render.py`` is used to generate figures of the hierarchies of NWB-N files and
      specifications as well as to help with the programmatic generation of reStructuredText (RST) documents
* ``docs/common/text`` Documentation text sources that are used in multiple documents (e.g., the introduction to NWB-N)
* ``docs/common/figures`` Figures that are being used in multiple documents (e.g., charts describing NWB-N)


**Building Documentation**

The documentation uses Sphinx and can be compiled using the provided Makefiles in the respective documentation
directories. The build process for the different documents is further described in the respective Readme.md files
in the corresponding documentation directories. In general, if you want to rebuilt the full HTML and PDF versions
of the specification documents, simply use the ``make fulldoc`` option, e.g.,

```
    cd docs/format
    make fulldoc
```

**Where are my documents?**

The compiled documents are then located in the corresponding ``_build`` folders, e.g.:

* ``format/_build/html`` and ``format/_build/latex`` for the HTML and PDF of the format specfication
* ``language/_build/html`` and ``language/_build/latex`` for the HTML and PDF of the specification language
* ``storage/_build/html`` and ``storage/_build/latex`` for the HTML and PDF of the storage