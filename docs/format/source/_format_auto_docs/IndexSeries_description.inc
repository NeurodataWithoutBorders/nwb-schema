.. _sec-IndexSeries:

IndexSeries
^^^^^^^^^^^

**Extends:** :ref:`TimeSeries <sec-TimeSeries>`

**Source Specification:** see :numref:`sec-IndexSeries-src`

**Overview:** Stores indices to image frames stored in an ImageSeries. The purpose of the ImageIndexSeries is to allow a static image stack to be stored somewhere, and the images in the stack to be referenced out-of-order. This can be for the display of individual images, or of movie segments (as a movie is simply a series of images). The data field stores the index of the frame in the referenced ImageSeries, and the timestamps array indicates when that image was displayed.


``IndexSeries`` extends ``TimeSeries`` (see :numref:`sec-TimeSeries`) and includes all elements of :ref:`TimeSeries <sec-TimeSeries>` with the following additions or changes.



.. figure:: ./_format_auto_docs/IndexSeries.*
    :alt: IndexSeries




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-IndexSeries-data:

.. table:: Datasets, Links, and Attributes contained in <IndexSeries>
    :class: longtable

    +-----------------------+-------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | Id                    | Type        | Description                                                                                                                                                                      |
    +=======================+=============+==================================================================================================================================================================================+
    | <IndexSeries>         | group       | Top level group for <IndexSeries>                                                                                                                                                |
    +-----------------------+-------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .help                 | attribute   | Value is 'A sequence that is generated from an existing image stack. Frames can be presented in an arbitrary order. The data[] field stores frame number in reference stack'     |
    |                       |             |                                                                                                                                                                                  |
    |                       |             | - **Data Type:** text                                                                                                                                                            |
    |                       |             | - **Value:** A sequence that is generated from an existing image stack. Frames can be presented in an arbitrary order. The data[] field stores frame number in reference stack   |
    |                       |             |                                                                                                                                                                                  |
    +-----------------------+-------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .data                 | dataset     | Index of the frame in the referenced ImageSeries.                                                                                                                                |
    |                       |             |                                                                                                                                                                                  |
    |                       |             | - **Data Type:** int                                                                                                                                                             |
    |                       |             | - **Dimensions:** ['num_times']                                                                                                                                                  |
    |                       |             | - **Shape:** [None]                                                                                                                                                              |
    |                       |             |                                                                                                                                                                                  |
    +-----------------------+-------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .indexed_timeseries   | link        | HDF5 link to TimeSeries containing images that are indexed.                                                                                                                      |
    |                       |             |                                                                                                                                                                                  |
    |                       |             | - **Target Type** :ref:`ImageSeries <sec-ImageSeries>`                                                                                                                           |
    |                       |             |                                                                                                                                                                                  |
    +-----------------------+-------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-IndexSeries-groups:

.. table:: Groups contained in <IndexSeries>
    :class: longtable

    +-----------------------+---------+---------------------------------------------------------------+
    | Id                    | Type    | Description                                                   |
    +=======================+=========+===============================================================+
    | <IndexSeries>         | group   | Top level group for <IndexSeries>                             |
    +-----------------------+---------+---------------------------------------------------------------+
    | .indexed_timeseries   | link    | HDF5 link to TimeSeries containing images that are indexed.   |
    |                       |         |                                                               |
    |                       |         | - **Target Type** :ref:`ImageSeries <sec-ImageSeries>`        |
    |                       |         |                                                               |
    +-----------------------+---------+---------------------------------------------------------------+


