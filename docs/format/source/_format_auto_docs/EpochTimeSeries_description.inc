.. _sec-EpochTimeSeries:

EpochTimeSeries
^^^^^^^^^^^^^^^

**Source Specification:** see :numref:`sec-EpochTimeSeries-src`

**Overview:** One of possibly many input or output streams recorded during epoch. 

**Comment:**  Name is arbitrary and does not have to match the TimeSeries that it refers to.




- **Quantity** 0 or more


.. figure:: ./_format_auto_docs/EpochTimeSeries.*
    :alt: EpochTimeSeries




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-EpochTimeSeries-data:

.. table:: Datasets, Links, and Attributes contained in <EpochTimeSeries>
    :class: longtable

    +---------------------+-----------+----------------------------------------------------------------------------------------+
    | Id                  | Type      | Description                                                                            |
    +=====================+===========+========================================================================================+
    | <EpochTimeSeries>   | group     | Top level group for <EpochTimeSeries>                                                  |
    +---------------------+-----------+----------------------------------------------------------------------------------------+
    | .count              | dataset   | Number of data samples available in this time series, during this epoch.               |
    |                     |           |                                                                                        |
    |                     |           | - **Data Type:** int32                                                                 |
    |                     |           |                                                                                        |
    +---------------------+-----------+----------------------------------------------------------------------------------------+
    | .idx_start          | dataset   | Epoch's start index in TimeSeries data[] field.                                        |
    |                     |           |                                                                                        |
    |                     |           | **Comment:**  This can be used to calculate location in TimeSeries timestamp[] field   |
    |                     |           |                                                                                        |
    |                     |           | - **Data Type:** int32                                                                 |
    |                     |           |                                                                                        |
    +---------------------+-----------+----------------------------------------------------------------------------------------+
    | .timeseries         | link      | Link to TimeSeries.  An HDF5 soft-link should be used.                                 |
    |                     |           |                                                                                        |
    |                     |           | - **Target Type** :ref:`TimeSeries <sec-TimeSeries>`                                   |
    |                     |           |                                                                                        |
    +---------------------+-----------+----------------------------------------------------------------------------------------+




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-EpochTimeSeries-groups:

.. table:: Groups contained in <EpochTimeSeries>
    :class: longtable

    +---------------------+---------+----------------------------------------------------------+
    | Id                  | Type    | Description                                              |
    +=====================+=========+==========================================================+
    | <EpochTimeSeries>   | group   | Top level group for <EpochTimeSeries>                    |
    +---------------------+---------+----------------------------------------------------------+
    | .timeseries         | link    | Link to TimeSeries.  An HDF5 soft-link should be used.   |
    |                     |         |                                                          |
    |                     |         | - **Target Type** :ref:`TimeSeries <sec-TimeSeries>`     |
    |                     |         |                                                          |
    +---------------------+---------+----------------------------------------------------------+


