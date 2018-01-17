.. _sec_getting_started:

***************
Getting Started
***************

How to get started
------------------

I am scientist/developer in a neuroscience lab and want to start using NWB:N
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

For end-users, the main entry point into the world of NWB:N is usually the PyNWB Python API.
For more details see here: `http://readthedocs.org/projects/pynwb/downloads/pdf/latest <http://readthedocs.org/projects/pynwb/downloads/pdf/latest/>`_

For Matlab users, MatNWB also provides a Matlab API for NWB:N 2.  For more details see here:
`https://github.com/NeurodataWithoutBorders/matnwb <https://github.com/NeurodataWithoutBorders/matnwb>`_

I want to get an overview of all the aspects of NWB:N
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

A general overview an pointers to all relevant documents are available as part of the
`General Overview <http://nwb-overview.readthedocs.io>`_ docs. For a more broader overview
of the NeurodataWithoutBorders project see also http://www.nwb.org .


Getting Help
------------

Detailed documentation of the various aspects of the NWB:N project are available here:

* **Main Project Site** http://www.nwb.org/nwb-neurophysiology/
* **General Overview (this documentation)** : http://nwb-overview.readthedocs.io
* **Specification Language:** http://schema-language.readthedocs.io
* **Format Specification:** http://nwb-schema.readthedocs.io
* **Data Storage:** http://nwb-storage.readthedocs.io
* **PyNWB (APIs):** http://pynwb.readthedocs.io

The documents are also available in PDF and zipped HTML form for print and offline browsing:

* **PDF**:
    * **General Overview** : http://readthedocs.org/projects/nwb-overview/downloads/pdf/latest/
    * **Specification Language:** http://readthedocs.org/projects/schema-language/downloads/pdf/latest/
    * **Format Specification:** http://readthedocs.org/projects/nwb-schema/downloads/pdf/latest/
    * **Data Storage:** http://readthedocs.org/projects/nwb-storage/downloads/pdf/latest/
    * **PyNWB (APIs):** http://readthedocs.org/projects/pynwb/downloads/pdf/latest/
* **HTML Zip**:
    * **General Overview** : http://readthedocs.org/projects/nwb-overview/downloads/htmlzip/latest/
    * **Specification Language:** http://readthedocs.org/projects/schema-language/downloads/htmlzip/latest/
    * **Format Specification:** http://readthedocs.org/projects/nwb-schema/downloads/htmlzip/latest/
    * **Data Storage:** http://readthedocs.org/projects/nwb-storage/downloads/htmlzip/latest/
    * **PyNWB (APIs):** http://readthedocs.org/projects/pynwb/downloads/htmlzip/latest/

Sources
-------

The sources for the API, format specification, and all documents are available here:

* **PyNWB (Python Data API):** https://github.com/NeurodataWithoutBorders/pynwb .
    * This repository includes all sources of the PyNWB and FORM APIs as well as
      corresponding documentation and test infrastructure.

* **NWB Schema:** https://github.com/NeurodataWithoutBorders/nwb-schema .
    * The nwb-schema repository includes among others:
        * ``core`` : YAML specification of the NWB core format
        * ``docs/general`` : Sphinx sources for the general overview documentation
        * ``docs/language`` : Sphinx sources for the specification language documention
        * ``docs/format`` : Sphinx sources for the format specification documentation
        * ``docs/storage`` : Sphinx sources for the data storage documention
        * ``docs/utils`` : Python utilities used for generation of the format documentation from the YAML specification.
          This includes convenient helper functions for rendering specification hierarchies and for generating RST docs.

* **MatNWB** https://github.com/NeurodataWithoutBorders/matnwb
    * This respository includes all sources of the MatNWB Matlab API.

Code of Conduct
---------------

The PyNWB and nwb-schema projects and everyone participating in it are governed by our
`code of conduct <https://github.com/NeurodataWithoutBorders/pynwb/blob/dev/docs/CODE_OF_CONDUCT.rst>`_ guidelines .
By participating, you are expected to uphold this code.

Reporting Issues and Contributing
---------------------------------

For details on how to contribute to PyNWB and nwb-schema projects see
our `contribution guidelines <https://github.com/NeurodataWithoutBorders/pynwb/blob/dev/docs/CONTRIBUTING.rst>`_ .
