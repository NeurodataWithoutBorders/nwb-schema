.. _sec-SpatialSeries:

SpatialSeries
^^^^^^^^^^^^^

**Extends:** :ref:`TimeSeries <sec-TimeSeries>`

**Source Specification:** see :numref:`sec-SpatialSeries-src`

**Overview:** Direction, e.g., of gaze or travel, or position. The TimeSeries::data field is a 2D array storing position or direction relative to some reference frame. Array structure: [num measurements] [num dimensions]. Each SpatialSeries has a text dataset reference_frame that indicates the zero-position, or the zero-axes for direction. For example, if representing gaze direction, "straight-ahead" might be a specific pixel on the monitor, or some other point in space. For position data, the 0,0 point might be the top-left corner of an enclosure, as viewed from the tracking camera. The unit of data will indicate how to interpret SpatialSeries values.


``SpatialSeries`` extends ``TimeSeries`` (see :numref:`sec-TimeSeries`) and includes all elements of :ref:`TimeSeries <sec-TimeSeries>` with the following additions or changes.



.. figure:: ./_format_auto_docs/SpatialSeries.*
    :alt: SpatialSeries




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-SpatialSeries-data:

.. table:: Datasets, Links, and Attributes contained in <SpatialSeries>
    :class: longtable

    +--------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | Id                 | Type        | Description                                                                                                                                                                                                                    |
    +====================+=============+================================================================================================================================================================================================================================+
    | <SpatialSeries>    | group       | Top level group for <SpatialSeries>                                                                                                                                                                                            |
    +--------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .help              | attribute   | Value is 'Stores points in space over time. The data[] array structure is [num samples][num spatial dimensions]'                                                                                                               |
    |                    |             |                                                                                                                                                                                                                                |
    |                    |             | - **Data Type:** text                                                                                                                                                                                                          |
    |                    |             | - **Value:** Stores points in space over time. The data[] array structure is [num samples][num spatial dimensions]                                                                                                             |
    |                    |             |                                                                                                                                                                                                                                |
    +--------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .data              | dataset     | 2-D array storing position or direction relative to some reference frame.                                                                                                                                                      |
    |                    |             |                                                                                                                                                                                                                                |
    |                    |             | - **Data Type:** number                                                                                                                                                                                                        |
    |                    |             | - **Dimensions:** ['num_times', 'num_features']                                                                                                                                                                                |
    |                    |             | - **Shape:** [None, None]                                                                                                                                                                                                      |
    |                    |             |                                                                                                                                                                                                                                |
    +--------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..unit             | attribute   | The base unit of measure used to store data. This should be in the SI unit.                                                                                                                                                    |
    |                    |             |                                                                                                                                                                                                                                |
    |                    |             | **Comment:**  This is the SI unit (when appropriate) of the stored data, such as Volts. If the actual data is stored in millivolts, the field 'conversion' below describes how to convert the data to the specified SI unit.   |
    |                    |             |                                                                                                                                                                                                                                |
    |                    |             | - **Data Type:** text                                                                                                                                                                                                          |
    |                    |             | - **Reuqired:** False                                                                                                                                                                                                          |
    |                    |             | - **Default Value:** meter                                                                                                                                                                                                     |
    |                    |             |                                                                                                                                                                                                                                |
    +--------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .reference_frame   | dataset     | Description defining what exactly 'straight-ahead' means.                                                                                                                                                                      |
    |                    |             |                                                                                                                                                                                                                                |
    |                    |             | - **Quantity** 0 or 1                                                                                                                                                                                                          |
    |                    |             | - **Data Type:** text                                                                                                                                                                                                          |
    |                    |             |                                                                                                                                                                                                                                |
    +--------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+



