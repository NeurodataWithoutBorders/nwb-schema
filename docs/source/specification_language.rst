Specification language used for Neurodata Without Borders (NWB) format
**********************************************************************

Specification Language Version: 1.2a (Mar. 23, 2017) [1]_

Author Note: The original version (1.1c) of the specification language was created by Jeff Teeters (UCB).


**# TODO This document needs to be updated to reflect changes made in version 1.2a**

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

1.1 Schema Id (or ‘namespace’)
-----------------------------

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

1.2 Top level components
------------------------

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

    "description": “<description of the specification>”

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

1.3 Schema specification
------------------------

The schema specification consist of a Python dictionary where each key
has the following form:

.. code-block:: python

    [ *absolute\_path* ] *identifier* [*quantity-flag*]

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

*quantity\_flag* is optional. It is used to indicate the quantity. If
present, it is a single character, one of: “?”, “!”, “^”, “+” or “\*”.
These mean:

! – Required (this is the default)

? – Optional

^ – Recommended

+ - One or more instances of variable-named identifier required

\* - Zero or more instances of variable-named identifier allowed

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

With quantities:

    foo? – dataset, name is “foo”. Is optional

    foo/^ – group, name is “foo”. Is recommended

    <foo>\* – dataset, variable name, zero or more allowed

    <foo>/+ – group, variable name, at least one required

When an absolute path is specified (or if the identifier is for the root
group) the identifier is “anchored” to the specified location. If there
is no absolute path, then the group or dataset associated with the
identifier can be incorporated into other groups using the “include” or
“merge” directives that are described below.

1.4. Extensions
---------------

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

2. Specification of groups
==========================

2.1 Overall form
----------------

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

2.2 Group specification keys
----------------------------

The following sections describes the first six keys in the illustrated
group specification above (“description”, “\_description”, “attributes”,
“merge”, “include”, “link”).

2.2.1 description
-----------------

The value of the group specification “description” key is a string
describing the group.

2.2.2 \_description
-------------------

The key “\_description” (has an underscore in front) is used in place of
“description” in case the key “description” is used to specify a dataset
in the group named “description”.

2.2.3 \_required
----------------

The <required specification> is a dictionary with each key an identifier
associated with some condition, and each value a list of tuples. First
element of each tuple is a string (called the “condition string”) that
contains a logical expression that has variables matching members of the
group. The condition string specifies which combinations of group
members are required. The second element of each tuple is an error
message that is displayed if the requirements of the condition string
are not met. An example required specification is shown below:

.. code-block:: python

    { "start\_time" :

    ["starting\_time XOR timestamps",

    "Either starting\_time or timestamps must be present, but not both."],

    "control":

    ["(control AND control\_description) OR

    (NOT control AND NOT control\_description)",

    ("If either control or control\_description are present, then "

    "both must be present.")]}

2.2.4 Exclude\_in specification
-------------------------------

The exclude\_in specification is used to specify locations in the HDF5
file under which particular members of this group should not be present
(or be optional). It has the form:

.. code-block:: python

    {"/path1": ["id1", "id2", "id3", ...], "/path2": [<ids for path2], ... }

Each id is the id of a member group or dataset. The id in the list can
be followed by characters "!”, "^”, "?” to respectively indicate that
the id must not be present, should not be present or is optional under
the specified path. If the last character is not “!”, “^” or “?” then
“!” is assumed. An example is:

.. code-block:: python

    "\_exclude\_in": {

    "/stimulus/templates":

    [ "starting\_time!","timestamps!", "num\_samples?"] },

2.2.5 Properties specification
------------------------------

The “\_properties” specification is optional. If present, the value must
be a dictionary containing any combination of the keys: “abstract”,
“closed” and “create”. The value of included key must be type boolean
(True or False). “abstract” has value True indicates that this group is
“abstract” (must be subclassed via the “merge” directive). “closed” is
True indicates that ” additional members (groups and datasets beyond
what are defined in the specification) are not allowed in this group.
“create” is True to indicate that an API should automatically create
this group if the group is specified as being required.

2.2.6 attributes
----------------

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

2.2.7 merge
-----------

The merge specification is used to merge the specification of other
groups into the current group. It consists of a Python list of the
groups (identifiers described in section 1.3) to merge. (Each element of
the list must have a trailing slash since they all must be groups).

2.2.8 “merge+”
--------------

The merge+ specification (“+” character after the word “merge”) is used
to merge the specification of a single group (or subclass of it) into
the current group. The group merged is either the group given in the
list, or a subclass of that group (where subclasses are defined as a
group that merges the parent group). In the API call to make the group,
a subclass is specified by appending a dash then the subclass name after
the identifier used to make the group. For example, in the NWB format,
if the group name is “corrected” and the base class (in the “merge+”
specification) is <image-series>, then the call to create a subclass
(such as <TwoPhotonSeries>) would be:

make\_group("corrected-<TwoPhotonSeries>")

2.2.9 include
-------------

The include specification is used to include the specification of a
group or dataset inside the current group. The format is a Python
dictionary, in which each key is the key associated with a group or
dataset to include and the values are a dictionary used to specify
properties and values that are merged into the included structure and
also options for the include. The key that designate the group or
dataset to include may have a final character that specifies a quantity
(same as described in section 2.2). Options for the include are
specified by key “\_options”. Currently, there is only one option:
“subclasses” which has value True to indicate that “subclasses” of the
included group should also be included. Subclasses of a group are groups
that inherit from a base group using the “merge” directive (described in
the next section). Some examples of the include directive are shown
below:

# include with subclasses

"include": { "<TimeSeries>/\*":{"\_options": {"subclasses": True}}}

# include without subclasses

"include": {"<TimeSeries>/\*": {}}

2.2.10 merge vs. include
------------------------

The merge operation implements a type of subclassing because properties
of the merged in groups (the superclasses) are included, but overridden
by properties in the group specifying the merge if there are conflicts.
The include specification implements a type of reuse. The merge and
include operations are illustrated by the following diagram:

+-----------------------------+--------------------------+
| Merge – (for subclassing)   | Include – for reuse      |
|                             |                          |
| "A/": {                     | "A/": {                  |
|                             |                          |
| "x": ...,                   | "x": ...,                |
|                             |                          |
| "y": ...,                   | "y": ...,                |
|                             |                          |
| }                           | }                        |
|                             |                          |
| "B/": {                     | "B/": {                  |
|                             |                          |
| "merge": ["A/",],           | "include": {"A/": {}},   |
|                             |                          |
| "m": ...,                   | "m": ...,                |
|                             |                          |
| "n": ...,                   | "n": ...,                |
|                             |                          |
| }                           | }                        |
|                             |                          |
| Result:                     | Result:                  |
|                             |                          |
| "B/": {                     | "B/": {                  |
|                             |                          |
| "x": ...,                   | "m": ...,                |
|                             |                          |
| "y": ...,                   | "n": ...,                |
|                             |                          |
| "m": ...,                   | "A/": {                  |
|                             |                          |
| "n": ...,                   | "x": ...,                |
|                             |                          |
| }                           | "y": ...,                |
|                             |                          |
|                             | }                        |
|                             |                          |
|                             | }                        |
+-----------------------------+--------------------------+

2.11 link
---------

The link specification is used to indicate that the group must be hdf5
link to another group. (Hard or Soft links can be used, but Soft links
are recommended). The link specification is a Python dictionary. It has
the following form:

.. code-block:: python

    {

    "target\_type": "*<type\_of\_target>*",

    "allow\_subclasses": <True or False>,

    }

“target\_type” specifies the key for a group in the top level structure
of a namespace. It is used to indicate that the link must be to an
instance of that structure. “allow\_subclasses” is set to True to
indicate the link can be to subclasses of the target structure.
Subclasses are structures that include the target using a “merge”
specification. Neither of the keys are required. The default value for
“allow\_subclasses” is “False”. If target type is not specified, then
the link can be to any group.

3. Specification of datasets
============================

3.1 Overall form
----------------

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

3.2.1 description
-----------------

A string describing the dataset.

3.2.2 data\_type
----------------

A string indicating the type of data stored. This is the same as the
data type for attributes, described in section 2.2.6.

3.2.3 dimensions
----------------

If present, <dimension\_list> is either a list of named dimensions,
e.g.: [“dim1”, “dim2”, ...], or a list of lists of named dimensions,
e.g.: [[“dim1”], [“dim1”, “dim2”]]. The first form is used if there is
only one possibility for the number of dimensions. The second form is
used if there are multiple possible number of dimensions. Each dimension
name is an identifier (giving a dimension name) or a integer (specifying
the size of the dimension). Dimensions names are used both for
specifying properties of dimensions (as described below) and for
specifying relationships between datasets.

3.2.4 Attributes
----------------

Dataset attributes are specified in the same was as group attributes,
described in Section 2.2.6.

3.2.5 references
----------------

The references property is used to indicate that the values stored in
the dataset are referencing groups, datasets or parts of other datasets
in the file. The value of the references property is a reference target
specification. This has one of the following four forms:

a. <path\_to\_dataset>.dimension

b. <path\_to\_dataset>.dimension.component

c. <path\_to\_group>/<variable\_node\_id>

d. /

“<path\_to\_dataset>” and “<path\_to\_group>” are respectively a path to
a group or dataset in the file. The path can be absolute (starting with
“/”) or a relative (not starting with “/”). A relative path references a
node that is a child of the group containing the references
specification.

The first form (a) specifies a reference to a particular dimension of a
dataset. In this case all values in the referencing dataset should be
integers that are equal to one of the indices in the referenced dataset
dimension.

The second form (b) specifies a reference to a particular component of a
structured dimension. Structured dimensions are described in the section
about dimension specifications. In this case each value in the
referencing dataset should be equal to a value in the referenced
component of the referenced dataset and the values of the component in
the referenced dataset should all be unique. This case corresponds to
foreign key references in relational databases with the referenced
component being a column in the referenced table satisfying a uniqueness
constraint.

The third form (c) allows referencing variable named groups or datasets.
In this case all values of the referencing dataset should be names of
groups or datasets that are created with the name specified in the call
to the API. The value of the reference target specification should
contain the name of the group or dataset in angle brackets (since the
name is variable) and have a trailing slash if it is a group (since
groups are designated by a slash after the name).

The forth form (d) is a single slash. This form is to indicate that the
values in the referencing dataset must link to a group or dataset
somewhere in the file, but there are no other constraints.

3.2.6 link
----------

The link specification is used to indicate that the dataset must be
implemented using a hdf5 link. Either hard or soft links can be used,
but soft links are recommended because they indicate the source and
target of the link). The link specification is a Python dictionary. It
has the following form:

.. code-block:: python

    {

    "target\_type": "*<type\_of\_target>*"

    }

“target\_type” specifies the identifier for a dataset in the top level
structure of a namespace. It is used to indicate that the link must be
to an instance of that structure. If target type is not specified, then
the link can be to any dataset id.

3.3 dimension specification
---------------------------

Within a dataset specification, there are two types of dimension
specifications. The first, described in section 3.2.3, provides a list
of the names of all dimensions in the dataset. The second (described in
this section) provides a way to describe the properties of each
dimension. It is not necessary to include the specification for all
dimensions. Only those dimensions that have structured components (which
are described below) need to be specified. These dimension
specifications have a key equal to the name of the dimension, and the
value is the specification of the properties of the dimension. The
following format is used:

.. code-block:: python

    {

    "type": "structure",

    # for dimension type structure:

    "components": [

    { "alias": "var1",

    "unit": "<unit>",

    ' "references": "<*reference target specification*>"},

    { "alias": "var2", ... }, ... ]

    }

The type specifies the type of dimension. Currently there is only one
type implemented, named “structure”. Type structure is a structure type
which allows storing different types of data into a single array similar
to columns in a spreadsheet or fields in a relational data base table.
This is also similar to the “metaarray” described in the SciPy cookbook:
http://wiki.scipy.org/Cookbook/MetaArray and also Pandas DataFrame:
http://pandas.pydata.org/pandas-docs/dev/index.html).

The different components are specified using a list of dictionaries, (or
a list of lists of dictionaries if there are more than one possible
structure) with each dictionary specifying the properties of the
corresponding component. The “alias” specifies the component name that
can be referenced in a <*reference target specification>*

(reference type “b” in section 3.2.5). “unit” allows specifying the unit
of measure for numeric values. “references” allows specifying that the
values in the component reference another part of the file using any of
the methods described in section 3.2.5.

4. Autogen
==========

The autogen specification is used to indicate data that are can be
derived from the structure of the hdf5 file and automatically filled in
by the API. An API may use the autogen specification to automatically
generate the values when creating a file, and to ensure that correct
values are stored when validating a file. The autogen specification has
the following form:

.. code-block:: python

    { "type": <type of autogen, one of: "links", "link\_path", "names",
    "values",

    "length", "create", "missing">

    "target": <path\_to\_target>,

    ‘trim’: True or False, default ‘False’

    ‘allow\_others’: True or False, default ‘False’

    ‘qty’: <Either ‘!’ – exactly one, or “\*” – zero or more. Default “\*”.

    ‘tsig’: <Signature of target>

    ‘include\_empty’: True or False. Default False,

    ‘sort’: True or False. Default True

    ‘format’: <link\_path\_format>

    }

The type is the type of autogen. They are described below. For all
types, except ‘create’ and ‘missing’ the “target” is required. All
others are optional. For all types except “create”, “<path\_to\_target>”
is a path of identifiers that specifies one or more groups or datasets
that are descendant of the group that most directly contains the autogen
specification). To specify multiple members the target path would have
one or more variable-named id’s (enclosed in <>). In addition, the
target “<\*>” indicates any group or dataset. If include\_empty is true,
then if no values are found that would be used to fill the autogen, the
value is set to an empty list. Otherwise, the container for the autogen
values (attribute or dataset) is not created. The “tsig” value is a
“target signature” which is used to specify properties that must be
satisfied for matching target(s). It is used to filter the nodes found
at the target path to only those for which the autogen should apply. The
format of tsig is:

.. code-block:: python

    { "type": <"group" or "dataset">,

    "attrs": { "key1": <value1>, "key2": <value2, ... },

    }

One of “type” or “attrs” is required (both may be present). “type”
specifies the type of the target node. If not included, either group or
dataset match. “attrs” specifies the attribute keys and values that can
be compared to attributes in the target to detect a match.

‘links’ indicates that the value of autogen is a list of paths that link
to the group or dataset specified. If “trim” is True then when the paths
are stored, if they all share the same trailing component of the path,
e.g. /foo/bar/baz, and /x/y/baz; both share final component “baz”), then
the common final component is trimmed from the paths before using them
to fill in the data. If “sort” is true, values must be sorted.

“link\_path” indicates that the value of the autogen is the path of a
link made from the referenced group or dataset. For example, if there is
a group “foo” that links to “bar”, and a dataset named “baz” at the same
level, defined by:

.. code-block:: python

    "baz": {"autogen": {"link\_path": "foo"}}

Then when the file is created by an API that implementing the autogen,
the value of baz to be the path to bar.

The “format” option allows specifying a formatting string used for
“link\_path”. It can include strings: “$s” to indicate the source of a
link and “$t” to indicate the target. If present, the format is used to
create the “link\_path” entries. Default format is: “$t” (include just
the target path). Another common format is “$s is $t” which will
generate strings like: “<source> is <target>. The ‘qty’ for “link\_path”
is currently not used.

“names” – specify that the names of groups and/or datasets referenced
are included as an array. If “sort” is True, the values must be sorted.

“values” – specify that values stored in each target data set are to be
listed as a set (no duplicates) --in sorted order (if sort is True). The
values in each data set must be an array of strings.

“length” – specifies that the value stored is the length of the target
which must be a dataset storing a 1-D array.

“create” – is only used within a group. If present, it specifies that if
the group is required and does not exist, it should be automatically
created by the API (without requiring an explicit call to create it).
This type of autogen has been depreciated. Instead, it is recommended to
use: the group “\_properties” specification containing: {“create”: True}
as described in section 2.2.5.

“missing” – returns a sorted list of all members within the group which
are specified as being required or recommended, but are missing. There
is no target specified. If “allow\_others” is True, then the list can
also include additional identifiers, as long as they are not present in
the group, whether or not they are defined in the specification as being
required or recommended. If present, such additional identifiers should
be indicated with a warning during validation.

5. Relationships
================

Relationships are specified in one of two ways:

1. By sharing a common dimension identifier. Two arrays that are in the
   same group which have a common dimension identifier are related to
   each through a direct mapping between the two dimensions. This is
   equivalent to each dimension being a foreign key to the other in a
   relational database.

2. Through references specifications in dataset specifications that are
   described in section 3.2.5.

6. Default custom location
==========================

An optional dataset named "\_\_custom" (two leading underscores) is used
as a flag in the format specification to indicate the location within
which custom groups and custom datasets are created by default (that if,
if the path is not specified in the API call).

.. [1]
   The version number given here is for the specification language and
   is independent of the version number for the NWB format. The date
   after the version number is the last modification date of this
   document.
