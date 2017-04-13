Overview
========

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

