.. _specification_language:

**************************
NWB Specification Language
**************************

Version: |release| |today| [1]_

.. attention::

    TODO This document needs to be updated to reflect changes made in version 1.2a**

Introduction
============

Both the Python and MATLAB API for the NWB format are implemented using
a domain-independent specification language. The specification language
allows specifying a schema that defines a format. The API software
automatically provides a write-API based on the specification and also a
validator that is used validate that data files are consistent with the
format. The API currently uses HDF5 for storing the data, but other
storage methods are possible.

The specification language is written using a Python dictionary in a
JSON-like syntax, which can easily be converted to JSON. Python is used
rather than pure JSON because python allows inserting comments and also
provides more readable ways to include long strings.

Specification of a schema
=========================

.. attention::

    TODO: Update description of the use of namespaces

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

The schema specification consist of a Python dictionary where each key
has the following form:

.. code-block:: python

    [ *absolute\_path* ] *identifier*

*absolute\_path* is optional. If present, it starts with a slash, and
specifies the absolute location within an HDF5 file of the group or
dataset. For the root group, the absolute path is empty and the
identifier is “/”.

*identifier* is required. Identifiers that start with “<” and end with
“>” or “>/”, e.g. have surrounding angle brackets, indicate that the
name of the group or dataset is “variable” (that is, specified through
an API call when creating the group or dataset). If the identifier does
not have surrounding angle brackets, then the name is fixed and is the
same as the identifier. If the last character of the identifier is a
slash “/” (after any angle brackets), then the identifier is associated
with a group, otherwise a dataset.

Some example identifiers and their meaning are given below:

Unspecified location (no leading slash):

    foo – dataset, name is “foo”

    foo/ – group, name is “foo”

    <foo> – dataset, variable name

    <foo>/ – group, variable name

Specified location (has leading slash). Meaning same as above, but
location specified.

    /some/path/foo – dataset, name is “foo”, located at /some/path/

    /some/path/foo/ – group, name is “foo”, located at /some/path/

    /some/path/<foo> – dataset, variable name, located at /some/path/

    /some/path/<foo>/ – group, variable name, located at specified path

When an absolute path is specified (or if the identifier is for the root
group) the identifier is “anchored” to the specified location. If there
is no absolute path, then the group or dataset associated with the
identifier can be incorporated into other groups using the “include” or
“merge” directives that are described below.

Extensions
----------

As mentioned, extensions to the core format are specified using
schema\_ids that are different from the schema\_id used for the core
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

Specification of groups
=======================

Overall form
------------

The specification of a group (i.e. value of a schema specification
identifier that has a trailing slash) is a Python dictionary with the
following form:

.. code-block:: python

    {

    "description": "<description of group>",

    "\_description": "<description of group in case there is a dataset named
    description>",

    "\_required": "<required specification>",

    "\_exclude\_in": "<exclude\_in specification>",

    "\_properties": <properties specification>,

    "attributes": <attributes specification>,

    "merge": <list of groups to merge>,

    "merge+": <list of group (base class) to merge>,

    "include": <dictionary of structures to include>,

    "link": <link specification>,

    "dataset\_id[qty\_flag]": { <dataset specification> },

    "group\_id/[qty\_flag]": { <group specification> }

    }

None of the key-value pairs are required. All but the last two are
described in the next section “Group specification keys”. The last two
("dataset\_id", and "group\_id/") are used to specify a group or dataset
inside the group. The specification for them is the same as the
specification for top-level groups (described in this section) and for
top-level datasets (describe later). There can be any number of groups
or datasets specified inside a group. The quantity-flag can be specified
for the groups and datasets and has the same possible values and meaning
as described in section 1.3.

Group specification keys
------------------------

The following sections describes the first six keys in the illustrated
group specification above (“description”, “\_description”, “attributes”,
“merge”, “include”, “link”).

``description``
^^^^^^^^^^^^^^^

The value of the group specification “description” key is a string
describing the group.

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


``\_required``
^^^^^^^^^^^^^^

.. attention::

   TODO: The ``\_required`` or an improved version, thereof, will be added agai.


``attributes``
^^^^^^^^^^^^^^

List of attribute specifications describing the attributes of the group. See Section :ref:`attribute-spec` for details.

.. code-block:: yaml

    attributes:
    - ...


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

List of dataset specification describing all datasets to be stored as part of this group.

.. code-block:: yaml

    datasets:
    - name: data1
      type: number
      quantity: 'zero_or_one'
    - name: data2
      type: text
      attributes:
      - ...
    - ...


.. _attribute-spec:

Specification of Attributes
===========================

.. attention::

    TODO Need to update the description of the specification of attributes


The value of the group specification “attributes” key is a Python
dictionary of the following form:

.. code-block:: python

    {

    "attribute\_name\_1[qty\_flag]": <specification for attribute\_name\_1>,

    "attribute\_name\_2[qty-flag]": <specification for attribute\_name\_2>,

    ... }

The keys are the attribute names, optionally followed by a “qty\_flag.”
The ‘qty\_flag’ (stands for ‘quantity flag’ is similar to that for
groups and data sets. It specifies if the attribute is required (“!”) –
the default, optional (“?”) or recommended (“^”). The value of each key
is the specification for that attribute. Each attribute specification
has the following form:

.. code-block:: python

    {

    "data\_type": <float, int, number, or text>,

    "dimensions": <dimensions list>,

    "description": "<description of attribute>",

    "value": <value to store>,

    "const": <True or False>,

    "autogen": <autogen specification>,

    "references": <reference specification>,

    "dim1": *<dimension specification>*,

    "dim2": *<dimension specification>*

    }

Only data\_type is required. The value for data\_type is a string
specifying the data\_type of the attribute. Allowable values are:

float – indicates a floating point number

int – indicates an integer

uint – unsigned integer

number – indicates either a floating point or an integer

text – a text string

For all of the above types except number, a default size (in bits) can
be specified by appending the size to the type, e.g., int32. If “!” is
appended to the default size, e.g. “float64!”, then the default size is
also the required minimum size.

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


Specification of links
======================

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

``target\_type`` specifies the key for a group in the top level structure
of a namespace. It is used to indicate that the link must be to an
instance of that structure.

``doc``
^^^^^^^

``doc`` specifies the documenation string for the link and  should describe the
purpose and use of the linked data.

``name``
^^^^^^^^

Optional key specfying the ``name`` of the link.


Specification of datasets
=========================

Overall form
------------

The specification of a dataset (i.e. value associated with an identifier
described in section 1.3 that does not have a trailing slash) is a
Python dictionary with the following form:

.. code-block:: python

    {

    "description": "*<description>*",

    "data\_type": ("int", "float", "number", or "text"), # required

    "dimensions": <dimensions list>, # required if not scalar

    "attributes": <attributes specification>,

    "references": "<*reference target specification*>",

    "link": <link specification>,

    "autogen": <autogen specification>,

    "dim1": *<dimension specification>*,

    "dim2": *<dimension specification>*,

    ...

    }

Either the data\_type or link property must be present All others are
optional. If the dataset is specified and is an array (not scalar) than
the dimensions property is required. The autogen specification is
described in Section 4. Others are described below.

Dataset specification keys
--------------------------

``description``
^^^^^^^^^^^^^^^

A string describing the dataset.

``data\_type``
^^^^^^^^^^^^^^

A string indicating the type of data stored. This is the same as the
data type for attributes, described in section 2.2.6.

``dimensions``
^^^^^^^^^^^^^^

.. note::

    Describe the ```dims``` and ```shape``` keys

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

