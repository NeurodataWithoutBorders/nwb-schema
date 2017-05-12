*************************************************
Neurodata Without Borders: Neurophysiolgy (NWB-N)
*************************************************

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

.. _fig-project-components:

.. figure:: figures/project_components.*
   :scale: 65 %
   :alt: Components of NWB:Neurophysiology

   Main components of NWB-N


:numref:`fig-project-components` provides a high-level overview of the main
components of NWB-N. The following subsection provide a high-level overview of the
problem, approach, description, and function of these components. Further details
about the specific components are provided in the corresponding documentations.

Specification Language
----------------------

**Problem:** How to formally define neuroscience data standards?

**Approach:** In order to support the formal and verifiable specification of neurodata
file formats, NWB-N defines and uses the NWB specification
language.

**Description:** The specification language is
defined in YAML (or JSON). The specification language defines formal
structures for describing the organization of complex data using basic
concepts, e.g., Groups, Datasets, Attributes, and Links.
Data publishers can use the specification language to extend
the format in order to store types of data not managed by the base format.

**Function:** The primary function of the specification language is to enable
the formal specification of data organizations.

**Documentation:** http://schema-language.readthedocs.io

Format Specification:
---------------------
**Problem:** How to organize complex collections of neuroscience data?

**Approach:** Organize data hierarchically using easy-to-use primitives, e.g.,
Groups (similar to Folders), Datasets (n-D Arrays), Attributes (Metadata objects on Groups and Datasets),
and Links (links to Groups and Datasets).

**Description:** The NWB format standard is governed by a formal format specification,
the NWB-N schema that is formally specified using the NWB specification language.
A new schema file will be published for each revision of the NWB format
standard. Developers can use the schema to validate NWB files or create
advanced APIs for NWB data.

**Function:** The primary function of the format specification is to formally specify
the NWB format describing the organization of neuroscience data. The format specification
provides a verifiable, computer and human readable document that governs the NWB format.
The format specification is, hence, central to support development of API's and codes
compliant with the NWB format and extension of the NWB format.

**Documentation:** http://nwb-schema.readthedocs.io


Data Storage
------------

**Problem:** How to store large collections of neuroscience data?

**Approach:** NWB-N format currently uses the `Hierarchical Data Format (HDF5) <https://www.hdfgroup.org/HDF5/>`_
as primary storage mechanism.

**Description:** HDF5 was selected for the NWB format because it met several of the project's
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

**Function:** A primary function of the data storage is to map
NWB-N primitives (Groups, Datasets, Attributes, Links etc.) to storage.
In the case of HDF5 this is currently a 1-to-1 mapping as the NWB
primitives match HDF5 primitives.

**Documentation:** http://nwb-storage.readthedocs.io


Data API(s)
-----------

**Problem:** How to efficiently interact with neuroscience data?

**Approach:** The PyNWB API provides users easy-to-use representations of
NWB-N types for programmatic use and enables the mapping of these representations
to/from data storage based using the NWB-N format specification.

**Description:** PyNWB provides critical functionality neede to read, write, use, and
analyse data stored in NWB-N. PyNWB provides users an easy-to-use interface and abstractions
for integrating NWB types with their codes while insulating them from implementation
details with respect to specification language, format, and storage.

**Function:** The role of data API(s) is to facilitate efficient interaction
with neuroscience data stored in the NWB-N data format
(e.g,. for reading, writing, querying, and analyzing neuroscience data).
A main funcion of an API is provide users a stable and usable interface
for programmatic use and development of new applications. As such, a
central function of the API is also to insulate developers and users from
implementation details regarding the specifciation language, format specification,
and data storage.

**Documentation:** http://pynwb.readthedocs.io





