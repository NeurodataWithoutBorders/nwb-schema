Design notes
============

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
