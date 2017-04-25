.. _specification_language:

**************************
NWB Specification Language
**************************

Version: |release| |today| [1]_

Introduction
============

In order to support the formal and verifiable specification of neurodata
file formats, NWB-N defines and uses the NWB specification language.
The specification language is defined in YAML (or optionally JSON) and defines formal
structures for describing the organization of complex data using basic
concepts, e.g., Groups, Datasets, Attributes, and Links.
Data publishers can use the specification language to extend
the format in order to store types of data not supported by the NWB core format.

Namespaces / Schema
===================

.. attention::

    TODO: Update this section describing the definition and use of namespaces

Schema Id: ``namespace``
------------------------

The top-level of a format specification has the following form:

.. code-block:: python

    {"fs": {

    "ns1": <specification for ns1 namespace>,

    "ns2": <specification for ns2 namespace>,

    "ns3": <specification for ns3 namespace>, ... }


The top level variable must be “fs”. (This stands for “format
specification”). The value of variable “fs” is a dictionary with each
key the “namespace” or “schema-id” of a format specification that is
associated with that namespace. The namespace identifier can be any
valid Python identifier (the identifiers are *not* restricted to start
with ‘ns’). One of the namespaces is designated as the “default”
namespace and it is associated with the core format. Other namespaces
(schema-ids) are associated with extensions to the core format.
Information indicating where to obtain the specifications (usually names
of files containing the specifications) and the default namespace
identifier are passed into the API software when the software is
initialized.

Top level components
^^^^^^^^^^^^^^^^^^^^

The specification associated with each schema-id is a Python dictionary
with three keys: info, schema, and doc. e.g.:

.. code-block:: python

    { "info": <info specification>,

    "schema": <schema specification>,

    "doc": <auxiliary documentation>,

    }


“info” and “schema” are required. “doc” is optional. <info
specification> has the following form:

.. code-block:: python

    {

    "name": "<Name of specification>",

    "version": "<version number>",

    "date": "<date last modified or released>",

    "author": "<author name>",

    "contact": "<author email or other contact info>",

    "description": "<description of the specification>"

    },

The schema specification section defines the groups, datasets and
relationship that make up the format. This is the main part of the
format specification. It is described in the following sections.

The <auxiliary documentation> section is for text that is added to
documentation about the format that is generated from the format
specification, using the “make\_docs.py” tool. This is not described
further in this document, but the structure and operation can be deduced
by examining this part of the NWB format specification (e.g. file
“nwb\_core.py”) and the generated documentation for the NWB format.

Schema specification
--------------------

The schema specification consist of a list of Group specifications.
Schema may be distributed across multiple YAML files to improve
readability and to support logical organization of types.

Extensions
----------

.. note::

    **TODO** Update the description of how extensions are managed

As mentioned, extensions to the core format are specified using
``schema_ids`` that are different from the ``schema_id`` used for the core
format. The way that extensions are implemented is very simple: The
schema specified in extensions are simply “merged” into the schema
specified in the core format based on having the same absolute path (if
given) and the same identifier. For example, if the core format schema
includes key “<foo>/” (specifying a group with a variable name “foo”)
and an extension also includes a key “<foo>/”, the value associated with
both of these (which must be a dictionary) are combined to form the
specification of the core format and the extension. While it’s possible
to define multiple extensions in the same file (as illustrated in
section 1.1) normally, the specification associated with each schema\_id
will be in a separate file as illustrated below:

File containing specification for core format:

.. code-block:: python

    {"fs": {

    "core": <specification for core format>

    }


File containing specification for extension 1:

.. code-block:: python

    {"fs": {

    "ex1": <specification for extension ex1>

    }


File containing specification for extension 2:

.. code-block:: python

    {"fs": {

    "ex2": <specification for extension ex2>

    }

.. _sec-group-spec:

Groups
======

Groups are specified as part of the top-level list or via lists stored in the key
``groups``. The specification of a group is described in YAML as follows:

.. code-block:: yaml


    # Group specification
    -   name: Optional fixed name for the group. A group must either have a unique neurodata_type or a unique, fixed name.
        doc: Required description of the group
        neurodata_type_def: Optional new neurodata_type for the group
        neurodata_type: Optional neurodata_type the group should inherit from
        quantity: Optional quantity identifier for the group (default=1).
        linkable: Boolean indicating whether the group is linkable (default=True)
        attributes: Optional list of attribute specifications describing the attributes of the group
        datasets: Optional list of dataset specifications desribing the datasets contained in the group
        links: Optional list of link specification describing the links contained in the group
        groups: Optional list of group specifciations describing the sub-groups contained in the group

The key/value pairs that make up a group specification are described in more detail next in Section :numref:`sec-group-spec-keys`.

.. _sec-group-spec-keys:

Group specification keys
------------------------

``name``
^^^^^^^^

String with the optional fixed name for the group.

.. note::

    Every group must have either a unique fixed ``name`` or a unique ``neurodata_type`` to enable the unique
    identification of groups when stored on disk.

``doc``
^^^^^^^

The value of the group specification ``doc`` key is a string
describing the group. The ``doc`` key is required.

.. note::

    In earlier versions (before version 1.2a) this key was called ``description``

.. _sec-neurodata-type:

``neurodata_type`` and ``neurodata_type_def``
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The concept of a neurodata_type is similar to the concept of Class in object-oriented programming.
A neurodata_type is a unique identifier for a specific type of group (or dataset) in a specfication.
By assigning a neurodata_type to a group (or dataset) enables others to reuse that type by inclusion or
inheritance (*Note:* only groups (or datasets) with a specified type can be reused).

- ```neurodata_type_def```: This key is used to define (i.e, create) a new neurodata_type and to assign that type to
  the current group (or dataset).

- ```neurodata_type```: The value of the ``neurodata_type`` key describes the base type
  of a group (or dataset). The value must be an existing type.

Both ```neurodata_type_def``` and ```neurodata_type``` are optional keys.
To enable the unique identification, every group (and dataset) must either have a fixed name and/or a
unique neurodata_type. This means, any group (or dataset) with a variable name must have a unique neurodata_type.


**Reusing existing neurodata_types**

The combination of ```neurodata_type``` and ```neurodata_type_def``` provides an easy-to-use mechanism for
reuse of type specifications via inheritance (i.e., merge and extension of specifications) and inclusion (i.e,
embedding of an existing type as a component, such as a subgroup, of a new specification). Here an overview
of all relevant cases:

+--------------------+------------------------+------------------------------------------------------------------------+
| ``neurodata_type`` | ``neurodata_type_def`` |  Description                                                           |
+====================+========================+========================================================================+
|not set             | not set                |  define a standard dataset or group without a type                     |
+--------------------+------------------------+------------------------------------------------------------------------+
|not set             | set                    |  create a new neurodata_type from scratch                              |
+--------------------+------------------------+------------------------------------------------------------------------+
|set                 | not set                |  include (reuse) neurodata_type without creating a new one (include)   |
+--------------------+------------------------+------------------------------------------------------------------------+
|set                 | set                    |  merge/extend neurodata_type and create a new type (inheritance/merge) |
+--------------------+------------------------+------------------------------------------------------------------------+

**Example: Reuse by inheritance**

.. code-block:: yaml

    # Abbreviated YAML specification
    -   neurodata_type_def: Series
        datasets:
        - name: A

    -   neurodata_type_def: MySeries
        neurodata_type: Series
        datasets:
        - name: B

The result of this is that ``MySeries`` inherits dataset ``A`` from ``Series`` and adds its own dataset ``B``, i.e.,
if we resolve the inheritance, then the above is equivalent to:

.. code-block:: yaml

    # Result:
    -   neurodata_type_def: MySeries
        datasets:
        - name: A
        - name: B

**Example: Reuse by inclusion**


.. code-block:: yaml

    # Abbreviated YAML specification
    -   neurodata_type_def: Series
        datasets:
        - name: A

    -   neurodata_type_def: MySeries
        groups:
        - neurodata_type: Series


The result of this is that ``MySeries`` now includes a group of type ``Series``, i.e., the above is equivalent to:

.. code-block:: yaml

   -  neurodata_type_def: MySeries
      groups:
      - neurodata_type: Series
        datasets:
          - name: A

.. note::

    The keys ```neurodata_type_def`` and  ```neurodata_type``` were introduced in version 1.2a to
    simplify the concepts of  inclusion and merging of specifications and replaced the
    keys ```include``` and ```merge```(and ```merge+```).


.. _sec-quantity:

``quantity``
^^^^^^^^^^^^

The ``quantity`` describes how often the corresponding group (or dataset) can appear. The ``quantity``
indicates both minimum and maximum number of instances. Hence, if the minimum number of instances is ``0``
then the group (or dataset) is optional and otherwise it is required.

+---------------------------------+-------------------+------------------+--------------------------+
| value                           |  minimum quantity | maximum quantity |  Comment                 |
+=================================+===================+==================+==========================+
|  ```zero_or_more``` or ```*```  |      ``0``        | ``unlimited``    |  Zero or more instances  |
+---------------------------------+-------------------+------------------+--------------------------+
|  ```one_or_more``` or ```+```   |     ``1``         | ``unlimited``    |  One or more instances   |
+---------------------------------+-------------------+------------------+--------------------------+
|  ```zero_or_one``` or ```?```   |     ``0``         |  ``1``           |  Zero or one instances   |
+---------------------------------+-------------------+------------------+--------------------------+
|  ```1```, ```2```, ```3```, ... |     ``n``         |  ``n``           |  Exactly ``n`` instances |
+---------------------------------+-------------------+------------------+--------------------------+

.. note::

    The ``quantity`` key was added in version 1.2a of the specification language as a replacement of the
    ```quantity_flag``` that was used to encode quantity information via a regular expression as part of the
    main key of the group.

``linkable``
^^^^^^^^^^^^

Boolean describing whether the this group can be linked.


``attributes``
^^^^^^^^^^^^^^

List of attribute specifications describing the attributes of the group. See Section :ref:`attribute-spec` for details.

.. code-block:: yaml

    attributes:
    - ...

``links``
^^^^^^^^^

List of link specifications describing all links to be stored as part of this group.

.. code-block:: yaml

    links:
    - doc: Link to target type
      name: link name
      target_type: type of target
    - ...

``datasets``
^^^^^^^^^^^^

List of dataset specifications describing all datasets to be stored as part of this group.

.. code-block:: yaml

    datasets:
    - name: data1
      doc: My data 1
      type: number
      quantity: 'zero_or_one'
    - name: data2
      doc: My data 2
      type: text
      attributes:
      - ...
    - ...

``groups``
^^^^^^^^^^

List of group specifications describing all groups to be stored as part of this group

.. code-block:: yaml

    groups:
    - name: group1
      quantity: 'zero_or_one'
    - ...


.. _attribute-spec:


``\_required``
^^^^^^^^^^^^^^

.. attention::

   TODO: The ``\_required`` key has been removed in version 1.2.x and later. An improved version will be added again in later version of the specification language.


.. _sec-attributes-spec:

Attributes
==========

.. attention::

    TODO Need to update the description of the specification of attributes

Attributes are specified as part of lists stored in the key
``attributes`` as part of the specifications of ``groups`` and ``datasets``.
Attributes are typically used to further characterize or store metadata about
the  group, dataset, or link they are associated with. Similar to datasets, attributes
can define arbitrary n-dimensional arrays, but are typcially used to store smaller data.
The specification of an attributes is described in YAML as follows:


.. code-block:: yaml

    ...
    attributes:
    - name: Required string describing the name of the attribute
      doc: Required string with the description of the attribute
      dtype: Required string describing the data type of the attribute
      dims: Optional list describing the names of the dimensions of the data array stored by the attribute (default=None)
      shape: Optional list describing the allowed shape(s) of the data array stored by the attribute (default=None)
      required: Optional boolean indicating whether the attribute is required (default=True)
      value: Optional constant, fixed value for the attribute.
    -



If the attribute stores an array, the <dimensions list> specifies the
list of dimensions. The format for this is the same as the <dimensions
list> for data sets which is described in section 3.2.3. If no
<dimension list> is given, the attribute stores a scalar value.

The description is a text string describing the attribute. The value is
the value to store in the attribute. If a value is specified and
“const”:True is specified,, then the value is treated as a constant and
cannot be changed by the API. The autogen specification is described in
Section 4.

The references specification and the *<dimension specification>* are the
same as that used for datasets. They are respectively described in
sections 3.2.5 and 3.3.

Attribute specification keys
----------------------------

.. attention::

    TODO Need to add the description of all attribute keys

``name``
^^^^^^^^

String with the name for the attribute. The ``name`` key is required and must
specify a unique attribute on the current parent object (e.g., group or dataset)


``doc``
^^^^^^^

``doc`` specifies the documentation string for the attribute  and should describe the
purpose and use of the attribute data. The ``doc`` key is required.

.. _sec-dtype:

``dtype``
^^^^^^^^^

String specifying the data type of the attribute. Allowable values are:

- ``float`` – indicates a floating point number
- ``int`` – indicates an integer
- ``uint`` – unsigned integer
- ``number`` – indicates either a floating point or an integer
- ``text`` – a text string

For all of the above types (except number and text), a default size (in bits) can
be specified by appending the size to the type, e.g., int32. If “!” is
appended to the default size, e.g. “float64!”, then the default size is
also the required minimum size.

.. attention::

    - **TODO** Check that the list of allowable dtypes is complete
    - **TODO** Check that the behavior described for type bit lengths is current

.. _sec-dims:

``dims``
^^^^^^^^

Optional key describing the names of the dimensions of the array stored as value of the attribute.
In case there is only one option for naming the dimensions, the key defines
a single list of strings:

.. code-block:: yaml

    ...
    dims:
    - dim1
    - dim2

In case that the attribute may have different forms, this will be a list of lists:

.. code-block:: yaml

    ...
    dims:
    - - num_times
    - - num_times
      - num_channels

Each entry in the list defines an identifier/name of the corresponding dimension
of the array data.

.. _sec-shape:

``shape``
^^^^^^^^^

Optional key describing the shape of the array stored as the valye of the attribute.
The description of ``shape`` must match the description of dimensions in so far as
if we name two dimensions in ``dims`` than we must also specify the ``shape`` for
two dimensions. We may specify ``null`` in case that the length of a dimension is not
restricted. E.g.:

.. code-block:: yaml

    ...
    shape:
    - null
    - 3

Similar to ``dims`` shape may also be a list of lists in case that the attribute
may have multiple valid shape options, e.g,:

.. code-block:: yaml

    ...
    shape:
    - - 5
    - - null
      - 5


``required``
^^^^^^^^^^^^

Optional boolean key describing whether the attribute is required. Default value is True.


``value``
^^^^^^^^^

Optional key specifying a fixed, constant value for the attribute. Default value is None, i.e.,
the attribute has a variable value to be determined by the user (or API) in accordance with
the current data.


.. _sec-link-spec:

Links
=====

The link specification is used to specify links to other groups or datasets.
In HDF5 it is recommended that links be stored a soft links. The link specification
is a dictionary with the following form:

.. code-block:: yaml

    links:
    - doc: Link to target type
      name: link name
      target_type: type of target

Link specification keys
------------------------

``target_type``
^^^^^^^^^^^^^^^

``target_type`` specifies the key for a group in the top level structure
of a namespace. It is used to indicate that the link must be to an
instance of that structure.

``doc``
^^^^^^^

``doc`` specifies the documentation string for the link and  should describe the
purpose and use of the linked data. The ``doc`` key is required.

``name``
^^^^^^^^

Optional key specifying the ``name`` of the link.


.. _sec-dataset-spec:

Datasets
========


Datasets are specified as part of lists stored in the key ``datasets`` as part of group specifications.
The specification of a datasets is described in YAML as follows:

.. code-block:: yaml

    - datasets:
      - name: of the dataset
        doc: Required description of the dataset
        neurodata_type_def: Optional new neurodata_type for the group
        neurodata_type: Optional neurodata_type the group should inherit from
        quantity: Optional quantity identifier for the group (default=1).
        linkable: Boolean indicating whether the group is linkable (default=True)
        dtype: Required string describing the data type of the dataset
        dims: Optional list describing the names of the dimensions of the dataset
        shape: Optional list describing the shape (or possibel shapes) of the dataset
        attributes: Optional list of attribute specifications describing the attributes of the group

The specification of datasets looks quite similar to attributes and groups. Similar to
attributes, datasets describe the storage of arbitrary n-dimensional array data.
However, in conrast to attributes, datasets are not associated with a specific parent
group or dataset object but are (similar to groups) primary data objects (and as such
typically manage larger data than attributes).
The key/value pairs that make up a dataset specification are described in more detail next in Section
:numref:`sec-dataset-spec-keys`.


.. _sec-dataset-spec-keys:

Dataset specification keys
--------------------------


``name``
^^^^^^^^

String with the optional fixed name for the dataset

.. note::

    Every dataset must have either a unique fixed ``name`` or a unique ``neurodata_type`` to enable the unique
    identification of datasets when stored on disk.

``doc``
^^^^^^^

The value of the dataset specification ``doc`` key is a string
describing the dataset. The ``doc`` key is required.

.. note::

    In earlier versions (before version 1.2a) this key was called ``description``

``neurodata_type`` and ``neurodata_type_def``
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Same as for groups. See :numref:`sec-neurodata-type` for details.


``quantity``
^^^^^^^^^^^^

Same as for groups. See :numref:`sec-quantity` for details.

``linkable``
^^^^^^^^^^^^

Boolean describing whether the this group can be linked.

``dtype``
^^^^^^^^^

String describing the data type of the dataset. Same as for attributes. See :numref:`sec-dtype` for details.

``shape``
^^^^^^^^^

List describing the shape of the dataset. Same as for attributes. See :numref:`sec-shape` for details.

``dims``
^^^^^^^^

List describing the names of the dimensions of the dataset. Same as for attributes. See :numref:`sec-dims` for details.


``attributes``
^^^^^^^^^^^^^^

List of attribute specifications describing the attributes of the group. See Section :ref:`attribute-spec` for details.

.. code-block:: yaml

    attributes:
    - ...

Relationships
=============

.. note::

    Future versions will add explicit concepts for modeling of relationships, to replace the
    implicit relationships encoded via shared dimension descriptions and implicit references in
    datasets in previous versions of the specification language.


.. [1]
   The version number given here is for the specification language and
   is independent of the version number for the NWB format. The date
   after the version number is the last modification date of this
   document.

