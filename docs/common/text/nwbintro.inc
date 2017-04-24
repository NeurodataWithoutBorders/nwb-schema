*****************************************
Neurodata Without Borders: Neurophysiolgy
*****************************************

Mission
=======

Neurodata Without Borders: Neurophysiology (NWB-N) is a project to develop a
unified data format for cellular-based neurophysiology data, focused on
the dynamics of groups of neurons measured under a large range of
experimental conditions. Participating labs provided use cases and
critical feedback to the effort. The design goals for the NWB format
included:

- Compatibility
    -  Cross-platform
    -  Support for tool makers
- Usability
    -  Quickly develop a basic understanding of an experiment and its data
    -  Review an experiment's details without programming knowledge
- Flexibility
    -  Accommodate an experiment's raw and processed data
    -  Encapsulate all of an experiment's data, or link to external data
       source when necessary
- Extensibility
    -  Accommodate future experimental paradigms without sacrificing
       backwards compatibility.
    -  Support custom extensions when the standard is lacking
- Longevity
    -  Data published in the format should be accessible for decades


Project Components
==================


.. figure:: ../../common/figures/project_components.*
   :scale: 65 %
   :alt: Components of NWB:Neurophysiology

   Main components of Neurodata Without Borders: Neurophysiolgy (NWB-N).

Data Storage
------------

The NWB format currently uses HDF5 as primary storage mechanism.
`Hierarchical Data Format (HDF) <https://www.hdfgroup.org/HDF5/>`__ was
selected for the NWB format because it met several of the project's
requirements. First, it is a mature data format standard with libraries
available in multiple programming languages. Second, the format's
hierarchical structure allows data to be grouped into logical
self-documenting sections. Its structure is analogous to a file system
in which its "groups" and "datasets" correspond to directories and
files. Groups and datasets can have attributes that provide additional
details, such as authorities' identifiers. Third, its linking feature
enables data stored in one location to be transparently accessed from
multiple locations in the hierarchy. The linked data can be external to
the file. Fourth, HDF5 is widley supported across programming languages
(e.g., C, C++, Python, MATLAB, R among others) and tools, such as,
`HDFView <https://www.hdfgroup.org/products/java/hdfview/>`__, a free,
cross-platform application, can be used to open a file and browse data.
Finally, ensuring the ongoing accessibility of HDF-stored data is the
mission of The HDF Group, the nonprofit that is the steward of the
technology.

Specification Language
----------------------

In order to support the formal and verifiable specification of neurodata
file formats, NWB-N defines and uses the NWB specification
language (see :ref:`specification_language`). The specification language is
defined in YAML (or JSON). The specification language defines formal
structures for describing the organization of complex data using basic
concepts, e.g., Groups, Datasets, Attributes, and Links.
Data publishers can use the specification language to extend
the format in order to store types of data not managed by the base format.

Format Specification / Schema
-----------------------------

The NWB format standard is governed by a formal format specification,
the NWB-N schema (see :ref:`nwb_format`m). The schema is formally
specified using the NWB specification language (see :ref:`specification_language`).
A new schema file will be published for each revision of the NWB format
standard. Developers can use the schema to validate NWB files or create
advanced APIs for NWB data.

Data API(s)
-----------

The role of data API(s) is to facilitate efficient interaction
with neuroscience data stored in the NWB-N data format
(e.g,. for reading, writing, querying, and analyzing neuroscience data).




