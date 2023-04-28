.. _sec-hdf5:

====
HDF5
====

The NWB format currently uses the `Hierarchical Data Format (HDF5) <https://www.hdfgroup.org/HDF5/>`_
as the primary mechanism for data storage. HDF5 was selected for the
NWB format because it met several of the project's
requirements. First, it is a mature data format standard with libraries
available in multiple programming languages. Second, the format's
hierarchical structure allows data to be grouped into logical
self-documenting sections. Its structure is analogous to a file system
in which its "groups" and "datasets" correspond to directories and
files. Groups and datasets can have attributes that provide additional
details, such as authorities' identifiers. Third, its linking feature
enables data stored in one location to be transparently accessed from
multiple locations in the hierarchy. The linked data can be external to
the file. Fourth, HDF5 is widely supported across programming languages
(e.g., C, C++, Python, MATLAB, R among others) and tools, such as,
`HDFView <https://www.hdfgroup.org/products/java/hdfview/>`__, a free,
cross-platform application, can be used to open a file and browse data.
Finally, ensuring the ongoing accessibility of HDF-stored data is the
mission of The HDF Group, the nonprofit that is the steward of the
technology.

Format Mapping
==============

Here we describe the mapping of NWB primitives (e.g., Groups, Datasets, Attributes, Links, etc.) used by
the NWB format and specification to HDF5 storage primitives. As the NWB format was designed with HDF5
in mind, the high-level mapping between the format specification and HDF5 is quite simple:

.. tabularcolumns:: |p{4cm}|p{11cm}|

.. table:: Mapping of groups
    :class: longtable

    =============  ===============================================
    NWB Primitive  HDF5 Primitive
    =============  ===============================================
    Group          Group
    Dataset        Dataset
    Attribute      Attribute
    Link           Soft Link or External Link
    =============  ===============================================


.. note::

    Using HDF5, NWB links are stored as HDF5 Soft Links or External Links. Hard Links are not used in NWB because
    the primary location and, hence, primary ownership and link path for secondary locations, cannot be determined
    for Hard Links.


Key Mapping
===========

Here we describe the mapping of keys from the specification language to HDF5 storage objects:

Groups
------

.. tabularcolumns:: |p{4cm}|p{11cm}|

.. table:: Mapping of groups
    :class: longtable

    ============================  ======================================================================================
    NWB Key                       HDF5
    ============================  ======================================================================================
    name                          Name of the Group in HDF5
    doc                           HDF5 attribute doc on the HDF5 group
    groups                        HDF5 groups within the HDF5 group
    datasets                      HDF5 datasets within the HDF5 group
    attributes                    HDF5 attributes on the HDF5 group
    links                         HDF5 SoftLinks within the HDF5 group
    linkable                      Not mapped; Stored in schema only
    quantity                      Not mapped; Number of appearances of the group
    neurodata_type                Attribute ``neurodata_type``
    namespace ID                  Attribute ``namespace``
    object ID                     Attribute ``object_id``
    ============================  ======================================================================================


Datasets
--------

.. tabularcolumns:: |p{4cm}|p{11cm}|

.. table:: Mapping of datasets
    :class: longtable

    ============================  ======================================================================================
    NWB Key                       HDF5
    ============================  ======================================================================================
    name                          Name of the dataset in HDF5
    doc                           HDF5 attribute doc on the HDF5 dataset
    dtype                         Data type of the HDF5 dataset (see `dtype mappings`_ table)
    shape                         Shape of the HDF5 dataset if the shape is fixed, otherwise shape defines the maxshape
    dims                          Not mapped
    attributes                    HDF5 attributes on the HDF5 dataset
    linkable                      Not mapped; Stored in schema only
    quantity                      Not mapped; Number of appearances of the dataset.
    neurodata_type                Attribute ``neurodata_type``
    namespace ID                  Attribute ``namespace``
    object ID                     Attribute ``object_id``
    ============================  ======================================================================================

.. note::

    * TODO Update mapping of dims


Attributes
----------

.. tabularcolumns:: |p{4cm}|p{11cm}|

.. table:: Mapping of attributes
    :class: longtable

    ============================  ======================================================================================
    NWB Key                       HDF5
    ============================  ======================================================================================
    name                          Name of the attribute in HDF5
    doc                           Not mapped; Stored in schema only
    dtype                         Data type of the HDF5 attribute
    shape                         Shape of the HDF5 dataset if the shape is fixed, otherwise shape defines the maxshape
    dims                          Not mapped; Reflected by the shape of the attribute data
    required                      Not mapped; Stored in schema only
    value                         Data value of the attribute
    ============================  ======================================================================================


Links
-----

.. tabularcolumns:: |p{4cm}|p{11cm}|

.. table:: Mapping of links
    :class: longtable

    ============================  ======================================================================================
    NWB Key                       HDF5
    ============================  ======================================================================================
    name                          Name of the HDF5 Soft Link
    doc                           Not mapped; Stored in schema only
    target_type                   Not mapped. The target type is determined by the type of the target of the HDF5 link
    ============================  ======================================================================================


dtype mappings
--------------

The mappings of data types is as follows

    +--------------------------+----------------------------------+----------------+
    | ``dtype`` **spec value** | **storage type**                 | **size**       |
    +--------------------------+----------------------------------+----------------+
    |  * "float"               | single precision floating point  | 32 bit         |
    |  * "float32"             |                                  |                |
    +--------------------------+----------------------------------+----------------+
    |  * "double"              | double precision floating point  | 64 bit         |
    |  * "float64"             |                                  |                |
    +--------------------------+----------------------------------+----------------+
    |  * "long"                | signed 64 bit integer            | 64 bit         |
    |  * "int64"               |                                  |                |
    +--------------------------+----------------------------------+----------------+
    |  * "int"                 | signed 32 bit integer            | 32 bit         |
    |  * "int32"               |                                  |                |
    +--------------------------+----------------------------------+----------------+
    |  * "int16"               | signed 16 bit integer            | 16 bit         |
    +--------------------------+----------------------------------+----------------+
    |  * "int8"                | signed 8 bit integer             | 8 bit          |
    +--------------------------+----------------------------------+----------------+
    |  * "uint32"              | unsigned 32 bit integer          | 32 bit         |
    +--------------------------+----------------------------------+----------------+
    |  * "uint16"              | unsigned 16 bit integer          | 16 bit         |
    +--------------------------+----------------------------------+----------------+
    |  * "uint8"               | unsigned 8 bit integer           | 8 bit          |
    +--------------------------+----------------------------------+----------------+
    |  * "bool"                | boolean                          | 8 bit          |
    +--------------------------+----------------------------------+----------------+
    |  * "text"                | unicode                          | variable       |
    |  * "utf"                 |                                  |                |
    |  * "utf8"                |                                  |                |
    |  * "utf-8"               |                                  |                |
    +--------------------------+----------------------------------+----------------+
    |  * "ascii"               | ascii                            | variable       |
    |  * "str"                 |                                  |                |
    +--------------------------+----------------------------------+----------------+
    |  * "ref"                 | Reference to another group or    |                |
    |  * "reference"           | dataset                          |                |
    |  * "object"              |                                  |                |
    +--------------------------+----------------------------------+----------------+
    |  * region                | Reference to a region            |                |
    |                          | of another dataset               |                |
    +--------------------------+----------------------------------+----------------+
    |  * compound dtype        | HDF5 compound data type          |                |
    +--------------------------+----------------------------------+----------------+
    |  * "isodatetime"         | ASCII ISO8061 datetime string.   | variable       |
    |                          | For example                      |                |
    |                          | ``2018-09-28T14:43:54.123+02:00``|                |
    +--------------------------+----------------------------------+----------------+


Caching format specifications
=============================

In practice it is useful to cache the specification a file was created with (including extensions)
directly in the HDF5 file. Caching the specification in the file ensures that users can access
the specification directly if necessary without requiring external resources. However, the mechanisms for
caching format specifications is likely different for different storage backends and is not
part of the NWB format specification itself. For the HDF5 backend, caching of the schema is implemented as follows.

The HDF5 backend adds the reserved top-level group ``/specifications`` in which all format specifications (including
extensions) are cached. The ``/specifications`` group contains for each specification namespace a subgroup
``/specifications/<namespace-name>/<version>`` in which the specification for a particular version of a namespace
are stored (e.g., ``/specifications/core/2.0.1`` in the case of the NWB core namespace at version 2.0.1).
The actual specification data is then stored as a JSON string in scalar datasets with a binary, variable-length string
data type (e.g., ``dtype=special_dtype(vlen=binary_type)`` in Python). The specification of the namespace is stored in
``/specifications/<namespace-name>/<version>/namespace`` while additional source files are stored in
``/specifications/<namespace-name>/<version>/<source-filename>``. Here ``<source-filename>`` refers to the main name
of the source-file without file extension (e.g., the core namespace defines ``nwb.ephys.yaml`` as source which would
be stored in ``/specifications/core/2.0.1/nwb.ecephys``).
