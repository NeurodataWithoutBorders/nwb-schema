Overview
========

The NWB format is designed to store general optical and electrical physiology data in a way that
is both understandable to humans as well as accesible to programmatic interpretation. The format is
designed to be friendly to and usable by software tools and analysis
scripts, and to impose few priori assumptions about data
representation and analysis. Metadata required to understand the data
itself (core metadata) is generally stored with the data. Information
required to interpret the experiment (general metadata) is stored in the
group ``general``. Most general metadata is stored in free-form text
fields. Machine-readable metadata is stored as attributes on these
free-form text fields.

Top Level Data Organization
---------------------------

The high-level data organization of NWB files is described in detail in :numref:`sec-NWBFile`.
The top-level organization of data into groups is described in :numref:`table-NWBFile-groups`
and the top-level datasets and attributes are described in :numref:`table-NWBFile-data`.

The NWB format is based on the concept of *TimeSeries* for storing complex temporal series of data
and *Modules* for defining collections of processed data from common data processing steps where each
processing step is represented by an *Interface*. All datasets and groups in the format can be
uniquely identified by either their name and/or their *neurodata_type*. The *neurodata_type* of an
object is similar to the concept of a Class in object-oriented design, and is used to both uniquly
identify an object as well to enable the reuse of types. In the following we first define these basics concepts
in more detail. The NWB format is then described in detail in :numref:`nwb-type-specifications`.

neurodata_type
--------------

The concept of a ```neurodata_type``` is similar to the concept of a Class in object-oriented programming.
In the NWB format, groups or datasets may be given a unique ```neurodata_type```. The ```neurodata_type```
allows the unique identification of the type of objects in the format and also endable the reuse of
types through the concept of inheritance. A group or dataset may, hence, define a new ```neurodata_type```
while extending an existing type. E.g., ```AbstractFeatureSeries``` defines a new type that
inherits from ```TimeSeries```.


Time Series
-----------

The file format is designed around a data structure called a
*TimeSeries* which stores time-varying data. A *TimeSeries* is a
superset of several INCF types, including signal events, image stacks
and experimental events. To account for different storage requirements
and different modalities, a *TimeSeries* is defined in a minimal form
and it can be extended, or subclassed, to account for different
modalities and data storage requirements. When a *TimeSeries* is
extended, it means that the subclass maintains all components
(e.g., groups, datasets, and attributes) of its parent while it may modify
existing components as well as add new ones.

Each *TimeSeries* has its own HDF5 group, and all datasets belonging to
a *TimeSeries* are in that group. The group contains time and data
components and users are free to add additional fields as necessary.
There are two time objects represented. The first, *timestamps*, stores
time information that is corrected to the experiment's time base (i.e.,
aligned to a master clock, with time-zero aligned to the starting time
of the experiment). This field is used for data processing and
subsequent scientific analysis. The second, *sync*, is an optional group
that can be used to store the sample times as reported by the
acquisition/stimulus hardware, before samples are converted to a common
timebase and corrected relative to the master clock. This approach
allows the NWB format to support streaming of data directly from
hardware sources.

When data is streamed from experiment hardware it should be stored in an
HDF5 dataset having the same attributes as *data*, with time information
stored as necessary. This allows the raw data files to be separate
file-system objects that can be set as read-only once the experiment is
complete. *TimeSeries* objects in /acquisition will link to the *data*
field in the raw time series. Hardware-recorded time data must be
corrected to a common time base (e.g., timestamps from all hardware
sources aligned) before it can be included in *timestamps*. The
uncorrected time can be stored in the *sync* group.

The group holding the *TimeSeries* can be used to store additional
information (HDF5 datasets) beyond what is required by the
specification. I.e., an end user is free to add additional key/value
pairs as necessary for their needs. It should be noted that such
lab-specific extensions may not be recognized by analysis tools/scripts
existing outside the lab. Extensions are described in section (see :ref:`sec-extending-the-format`).

The *data* element in the *TimeSeries* will typically be an array of any
valid HDF5 data type (e.g., a multi-dimentsional floating point array).
The data stored can be in any unit. The attributes of the data field
must indicate the SI unit that the data relates to (or appropriate
counterpart, such as color-space) and the multiplier necessary to
convert stored values to the specified SI unit.

Extending Time Series
^^^^^^^^^^^^^^^^^^^^^

The *TimeSeries* is a data structure/object. It can be "subclassed" (or
extended) to represent more narrowly focused modalities (e.g.,
electrical versus optical physiology) as well as new modalities (eg,
video tracking of whisker positions). When it a *TimeSeries* is
subclassed, new datasets can be added while all datasets of parent
classes are either preserved as specified in the parent class or
replaced by a new definition (changed). In the tables that follow,
identifiers in the "Id" column that change the definition in the parent
class are underlined. An initial set of subclasses are described here.
Users are free to define subclasses for their particular requirements.
This can be done by creating an extension to the format defining a new
*TimeSeries* subclass (see :ref:`sec-extending-the-format`)


All datasets that are defined to be part of TimeSeries have the text
attribute 'unit' that stores the unit specified in the documentation.


Data Processing
---------------

Modules
^^^^^^^

NWB uses *modules* to store data for—and represent the results of—common
data processing steps, such as spike sorting and image segmentation,
that occur before scientific analysis of the data. Modules store the
data used by software tools to calculate these intermediate results.
Each module provides a list of the data it makes available, and it is
free to provide whatever additional data that the module generates.
Additional documentation is required for data that goes beyond standard
definitions. All modules are stored directly under group
`/processing <#/processing>`__. The name of each module is chosen by the
data provider (i.e. modules have a "variable" name). The particular data
within each module is specified by one or more *interfaces*, which are
groups residing directly within a module. Each interface extends
(contains the attributes in) group `*<Interface>* <#%3CInterface%3E>`__
and has a fixed name (e.g. *ImageSegmentation*) that suggests the type
of data it contains. The names of the interfaces within a given module
are listed in the "interfaces" attribute for the module. The different
types of Interfaces are described below.

Interfaces
^^^^^^^^^^

*Interface* is used in the format as a common base class for analyses stored in
*Modules*.


.. _sec-extending-the-format:

Extending the format
--------------------

The data organization presented in this document constitutes the *core*
NWB format. Extensibility is handled by allowing users to store
additional data as necessary using new datasets, attributes or groups.
There are two ways to document these additions. The first is to add an
attribute "neurodata\_type" with value the string "Custom" to the
additional groups or datasets, and provide documentation to describe the
extra data if it is not clear from the context what the data represent.
This method is simple but does not include a consistent way to describe
the additions. The second method is to write an *extension* to the
format. With this method, the additions are describe by the extension
and attribute "schema\_id" is set to the schema\_id associated with the
extension. Extensions to the format are written using the same
specification language that is used to define the core format. Creating
an extension allows adding the new data to the file through the API,
validating files containing extra data, and also generating
documentation for the additions. Popular extensions can be proposed and
added to the official format specification. Writing and using extensions
are described in the API documentation. Both methods allow extensibility
without breaking backward compatibility.


Comments and Definitions
========================

Notation
--------

The description of the format in :numref:`nwb-type-specifications` is
divided into subsection based on ```neurodata_type```. Each ```neurodata_type``` section includes:

* A basic description of the type
* An optional figure describing the organization of data within the type
* A set of tables describing the datasets, attributes and groups contained in the type.
* An optional set of further subsections describing the content of subgroups contained in the given ```neurdata_type```.

In the tables we use the following notation to uniquely identify datasets, groups, attributes:

* ```name``` desribes the unique name of an object
* ```<neurodata_type>``` describes the ```neurodata_type``` of the object in case that the object does not have a unique name
* ```...``` prefix is used to indicate the depth of the object in the hierarchy to allow identification of the parent of the object. E.g., an object with a ```..``` prefix will belong to the previous object with a `.` prefix.

Here a quick example:

.. table:: Example illustrating the description of the contents of ```neurodata_types```.

    +---------------------------+-------------+---------------------------------------------------------------------------------------------------------+-------------+
    | Name                      | Type        | Description                                                                                             |  Quantity   |
    +===========================+=============+=========================================================================================================+=============+
    | <MyTimeSeries>            | group       | Top level group for <MyTimeSeries>                                                                      | 1           |
    +---------------------------+-------------+---------------------------------------------------------------------------------------------------------+-------------+
    | .myattr                   | attribute   | Attribute defined on <MyTimeSeries>                                                                     |             |
    +---------------------------+-------------+---------------------------------------------------------------------------------------------------------+-------------+
    | .mydata                   | dataset     | Required dataset with a unique name contained in <MyTimeSeries>                                         | 1           |
    +---------------------------+-------------+---------------------------------------------------------------------------------------------------------+-------------+
    | ..unit                    | attribute   | Attribute unit defined on the dataset ..mydata                                                          |             |
    +---------------------------+-------------+---------------------------------------------------------------------------------------------------------+-------------+
    | .myotherdata              | dataset     | Optional dataset with a unique name contained in <MyTimeSeries>                                         | 0 or 1      |
    +---------------------------+-------------+---------------------------------------------------------------------------------------------------------+-------------+
    | .<ElectrialSeries>        | group       | Optional set of groups with the neurodata_type ElectricalSeries that is contained in <MyTimeSeries>     | 0 or more   |
    +---------------------------+-------------+---------------------------------------------------------------------------------------------------------+-------------+


Storing Time Values
-------------------

All times are stored in seconds using double precision (64 bit) floating
point values. A smaller floating point value, e.g. 32 bit, is **not**
permitted for storing times. This is because significant errors for time
can result from using smaller data sizes. Throughout this document,
sizes (number of bits) are provided for many datatypes (e.g. float32).
If the size is followed by "!" then the size is the minimum size,
otherwise it is the recommended size. For fields with a recommended
size, larger or smaller sizes can be used (and for integer types both
signed and unsigned), so long as the selected size encompasses the full
range of data, and for floats, without loss of significant precision.
Fields that have a minimum size can use larger, but not smaller sizes.

Link types
----------

In some instances, the specification refers to HDF5 links. When links
are made within the file, HDF5 soft-links (and not hard-links) should be
used. This is because soft-links distinguish between the link and the
target of the link, whereas hard-links cause multiple names (paths) to
be created for the target, and there is no way to determine which of
these names are preferable in a given situation. If the target of a soft
link is removed (or moved to another location in the HDF5 file)—both of
which can be done using the HDF5 API—then the soft link will "dangle,"
that is point to a target that no longer exists. For this reason, moving
or removing targets of soft links should be avoided unless the links are
updated to point to the new location.


Design notes
------------

The listed size of integers is the suggested size. What's important for
integers is simply that the integer is large enough to store the
required data, and preferably not larger. For floating point, double is
required for timestamps, while floating point is largely sufficient for
other uses. This is why doubles (float64) are stated in some places.
Because floating point sizes are provided, integer sizes are provided as
well.

**Why do timestamps\_link and data\_link record linking between
datasets, but links between epochs and timeseries are not recorded?**

Epochs have a hardlink to entire timeseries (ie, the HDF5 group). If 100
epochs link to a time series, there is only one time series. The data
and timestamps within it are not shared anywhere (at least from the
epoch linking). An epoch is an entity that is put in for convenience and
annotation so there isn't necessarily an important association between
what epochs link to what time series (all epochs could link to all time
series).

The timestamps\_link and data\_link fields refer to links made between
time series, such as if timeseries A and timeseries B, each having
different data (or time) share time (or data). This is much more
important information as it shows structural associations in the data.

