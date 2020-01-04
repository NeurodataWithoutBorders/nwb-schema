**Overview**

The documentation for NWB:N consists of a series of documents describing the various components of NWB:N:

* ``docs/language`` with the documentation for the NWB:N specification language
* ``docs/format`` with the documentation of the NWB:N data format
* ``docs/storage`` with the documentation of the NWB:N storage component
* The documentation of the PyNWB API is managed in the PyNWB git repo

**Building Documentation**

The documentation uses Sphinx and can be compiled using the provided Makefiles in the respective documentation
directories. The build process for the different documents is further described in the respective Readme.md files
in the corresponding documentation directories. In general, if you want to rebuild the full HTML and PDF versions
of the specification documents, simply use the ``make fulldoc`` option, e.g.,

```
    cd docs/format
    make fulldoc
```

**Where are my documents?**

The compiled documents are then located in the corresponding ``_build`` folders, e.g.:

* ``format/_build/html`` and ``format/_build/latex`` for the HTML and PDF of the format specification
* ``language/_build/html`` and ``language/_build/latex`` for the HTML and PDF of the specification language
* ``storage/_build/html`` and ``storage/_build/latex`` for the HTML and PDF of the storage
