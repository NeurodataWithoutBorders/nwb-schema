Overview
========

Time Series
-----------

The file format is designed around a data structure called a
*TimeSeries* which stores time-varying data. A *TimeSeries* is a
superset of several INCF types, including signal events, image stacks
and experimental events. To account for different storage requirements
and different modalities, a *TimeSeries* is defined in a minimal form
and it can be extended, or subclassed, to account for different
modalities and data storage requirements. When a *TimeSeries* is
extended, it means that the 'subclassed' instance maintains or changes
each of the components (eg, groups and datasets) of its parent and may
have new groups and/or datasets of its own. The *TimeSeries* makes this
process of defining such pairs more hierarchical.

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

.. note::

    # TODO Add documentation to describe the concept of interfaces


Definitions
-----------

.. note::
    **#TODO Add description of all definition needed to understand the format specification**


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
This method is simple but does not include a consistant way to describe
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

