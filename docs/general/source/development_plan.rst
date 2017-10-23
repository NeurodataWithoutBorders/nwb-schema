.. _dev-plan:

Development Plan
================

.. todo::

    This is a first draft. Check completeness and consistency of all items. Check and approbriateness of  timelines for the release.

.. todo::

    Check and complete list of contributors for the various items


The following sections provide an overview of various development targets for NWB:N and what they entail.

.. _dev-nwb2beta:

NWB:N 2.0 beta (11/10/2017)
---------------------------

This is a first public beta release of the new version NWB:N. The stability of all modules can't be ensured. Backward compatibility cannot be promised at this point yet. Further changes to the APIs as well as the format are still planed between this beta and the first full release of NWB 2.0 (see Section :ref:`dev-nwb2` for details). The intent of this beta release is to enable early adopters to start exploring the new format and software.


New features for this release:
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* **PyNWB:** A new advanced python API for the new version of NWB:N 2.0. PyNWB defines a new modular software architecture and API to enable users/developers to efficiently interact with the NWB:N data format, format files, and specifications. The new software architecture  decouples the various aspects of NWB:N (i.e. the specification language, format specification, storage, and API) to allow each to be used and maintained more independently. PyNWB also provides and API for interacting with NWB:N format specifications and provides mechanisms to easily create and use format extensions.

    * **Available online:** https://github.com/NeurodataWithoutBorders/pynwb

    * **Documentation:** http://pynwb.readthedocs.io

    * **Supported Languages** :
        * Python >2.7.x
        * Python >3.6.x

    * **Core features**:

        * Write NWB:N HDF5 files
        * Read NWB:N files (base round-trip read/write)
        * Validate NWB:N files
        * Create new format extensions
        * Read/Write data using extensions
        * Read legacy NWB 1.0x files from the Allen Institute for Brain Science

    * **Main contributors for this release** :

        * Andrew Tritt, Oliver Ruebel, David Camp, Kris Bouchard (LBNL) : Lead architects and development team
        * Nicholas Chain (Allen Institute for Brain Science) and Andrew Tritt (LBNL) : Port to Python 2 and legacy read for Allen data
        * Bug fixes, feedback and suggestions have also been contributed by numerous users and developers from the NWB:N community

* **PyNWB testing, continuous integration, deployment** We have developed an extensive set of unit tests for PyNWB. We have also created base infrastructure for integration tests to test end-to-end read/write of NWB:N files and data objects. While coverage of the tests is already quite good (>80%) coverage of the integration test suite is expected to be incomplete. We have also setup infrastructure for continuous integration to execute all tests on a broad range of platforms as well as defined software deployment paths (e.g., via PIP, CONDA)

    * **Available online:** For an overview of the various software health checks and tests being perfomred regulalary on PyNWB, see https://github.com/NeurodataWithoutBorders/pynwb

    * **Continuous integration** :

        * CircleCI (Linux, py27, py36)
        * Travis (MacOS, py27, py36)
        * AppVeyor (Windows, py27, py36)
        * Codecov.io

    * **Deployment**:
        * PIP (PyPI)
        * Conda (CondaCloud)

    * **Main contributors for this release**

        * Andrew Tritt (LBNL) : Lead for design and implementation of the Python test suites
        * Jean-Christophe Fillion-Robin, Doruk Ozturk, Chris Kotfila Michael Grauer, Will Schroeder (Kitware) : Lead development team for creation of continuous integration, testing, and deployment mechanisms


* **Specification Language** We have simplified and extended the specification language used to describe the NWB:N format to ease readability, interpretability and expressiveness.

    * **Documentation:** http://schema-language.readthedocs.io

    * **Release Notes:** http://schema-language.readthedocs.io/en/latest/specification_language_release_notes.html

    * **Main contributors for this release** :

        * Andrew Tritt, Oliver Ruebel, Kris Bouchard (LBNL) : Development leads
        * Changes to the specification language have also been reviewed and new changes have been proposed at a community hackathon at Janelia Farms HHMI in August 2017. Many users have also contributed via GitHub issues.


* **Format Specification** Changes to the format have focused mainly on improving the structure and usability of NWB:N rather than adding new features to the format itself. Updates to the NWB:N format include among others extensions to clarify and extend the concept of NWBContainer (previously Interface), avoid implicit links, and improve consistency and ease-of-use.

    * **Available online:** nwb-schema is available on GitHub at https://github.com/NeurodataWithoutBorders/nwb-schema

    * **Documentation:** http://nwb-schema.readthedocs.io

    * **Release Notes:** http://nwb-schema.readthedocs.io/en/latest/format.html#release-notes-nwb-format

    * **Main contributors for this release** :

        * Andrew Tritt, Oliver Ruebel (LBNL) : Implementation and documentation leads
        * Changes to the format specification have also been reviewed and new changes have been proposed at a community hackathon at Janelia Farms HHMI in August 2017. Many users have also contributed via GitHub issues.


* **Documentation** We have created dedicated online documentations for the various aspects of NWB:N. While the documents are quite extensive, completeness and consistency of the documents is not guaranteed for the beta release and examples, tutorials and release notes (i.e., changes), may be a bit out of date given pace of development.

    * **Available online**:
        * General overview of NWB:N and its various components: http://nwb-overview.readthedocs.io/en/latest/nwbintro.html
        * PyNWB API for NWB:N: http://pynwb.readthedocs.io
        * NWB:N data format specification: http://nwb-schema.readthedocs.io
        * Specification Language: http://schema-language.readthedocs.io
        * Data Storage: http://nwb-storage.readthedocs.io

    * **Format Documentation Tools** To ensure consistency between the NWB:N format specification and documentation we have developed a set of tools generate Sphinx RST documents from the YAML specification sources. The tools are available in `docs/utils` as part of the nwb-schema repository for Python 2/3.

    * **Main contributors for this release** :
        * Oliver Ruebel and Andrew Tritt (LBNL) : Documentation leads
        * Several of the documents have been ported from NWB:N 1.x, which were originally created by Jeff Teeters (UCB) et al.
        * Other teams have also contributed bug fixes

* **MatNWB** MatNWB is a Matlab API for NWB:N. MatNWB generates Matlab classes for representing NWB:N neurodata_type directly from the YAML specification.

    * **Core features**:

        * Write NWB:N HDF5 files
        * Read NWB:N HDF5 files
        * Read/Write data for custom extensions

    * **Main contributors for this release:**
        * Nathan Clack and Lawrence Niu (Vidriotech) : Software design and development lead
        * Karel Svoboda : Project Lead
        * Andrew Tritt and Oliver Ruebel : Review and discussion


Open GitHub Issues for this release
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* **PyNWB:** https://github.com/NeurodataWithoutBorders/pynwb/issues?q=is%3Aopen+is%3Aissue+milestone%3Asfn_release
* **nwb-schema:** https://github.com/NeurodataWithoutBorders/nwb-schema/issues?q=is%3Aopen+is%3Aissue+milestone%3Asfn_release


.. _dev-nwb2:

NWB:N 2.0 (~June 2018)
----------------------

The primary purpose of this targe release is to stabilize and complete development of NWB:N 2.0beta. This release will also include a number of changes to the format and APIs that have not made it into the beta release. Request for new features for this release has been frozen. Additional new features may be included in future NWB:N 2.x releases.

Planed new features (beyond NWB:N 2.0 beta)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* **NWB:N Format Specification (and PyNWB API)**

    * Support saving of NWB:N specifications in NWB:N HDF5 files as part of the ``/general/specifications``. Support use of these cached specification for data read.
    * Refactor ``/general/extracellular_ephys`` and ``ElectrodeGroup`` to use data tables via compound data types
    * Reorganize ``/general`` to ease additiona and management of custom, lab-specific metadata via extensions

* **NWB:N Specification Language (and PyNWB API)**

    * Add support for specification of compound data types
    * Add support for specification of references as part of data dtype

* **PyNWB**

    * Expand legacy read support to more sets of Allen data
    * Expand and refine existing features for read/write/specfication etc.

* **Testing, Continuous Integration, Deployment**

    * Add integration test cases to ensure broad coverage of intergration tests
    * Add further unit tests to ensure broad coverage
    * Define application test cases, i.e., sets of tests that implement select application test cases (e.g, convert of lab data to NWB:N).

* **Documentation**

    * Complete release notes describing the changes to the format, specification language etc.
    * Add more tutorials and examples
    * Move documentation tools to make them easier to access and reuse

* **Matlab API**

    * Ensure complete coverage and support for read and write of NWB:N HDF5 files
    * Ensure consistency between files generated by the Matlab and Python APIs
    * Add support for the above-described changes to the specification language and schema
    * Add further documentation

Open GitHub Issues for this release
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* **PyNWB:** https://github.com/NeurodataWithoutBorders/pynwb/issues?q=is%3Aopen+is%3Aissue+milestone%3A%22NWB+2.0+Full%22
* **nwb-schema:** https://github.com/NeurodataWithoutBorders/nwb-schema/issues?q=is%3Aopen+is%3Aissue+milestone%3A%22NWB+2.0+Full%22


NWB:N 2.x
---------

NWB:N 2.x refers to the next major feature release of NWB:N beyond the main release of NWB:N 2. The features to be included and target release date for NWB 2.x  will be decided on after the NWB 2.0 release is complete.

Open GitHub Issues for NWB:N 2.x
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* **PyNWB:** https://github.com/NeurodataWithoutBorders/pynwb/issues?q=is%3Aopen+is%3Aissue+milestone%3A%22NWB+2.x%22
* **nwb-schema:** https://github.com/NeurodataWithoutBorders/nwb-schema/issues?q=is%3Aopen+is%3Aissue+milestone%3A%22NWB+2.x%22

Open GitHub Issues for Future items
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* **PyNWB:** https://github.com/NeurodataWithoutBorders/pynwb/issues?q=is%3Aopen+is%3Aissue+milestone%3AFuture
* **nwb-schema:** https://github.com/NeurodataWithoutBorders/nwb-schema/issues?q=is%3Aopen+is%3Aissue+milestone%3AFuture




