.. _sec-RoiResponseSeries:

RoiResponseSeries
^^^^^^^^^^^^^^^^^

**Extends:** :ref:`TimeSeries <sec-TimeSeries>`

**Source Specification:** see :numref:`sec-RoiResponseSeries-src`

**Overview:** ROI responses over an imaging plane. Each row in data[] should correspond to the signal from one ROI.


``RoiResponseSeries`` extends ``TimeSeries`` (see :numref:`sec-TimeSeries`) and includes all elements of :ref:`TimeSeries <sec-TimeSeries>` with the following additions or changes.



.. figure:: ./_format_auto_docs/RoiResponseSeries.*
    :alt: RoiResponseSeries




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-RoiResponseSeries-data:

.. table:: Datasets, Links, and Attributes contained in <RoiResponseSeries>
    :class: longtable

    +--------------------------------+-------------+---------------------------------------------------------------------------------------------------------------------+
    | Id                             | Type        | Description                                                                                                         |
    +================================+=============+=====================================================================================================================+
    | <RoiResponseSeries>            | group       | Top level group for <RoiResponseSeries>                                                                             |
    +--------------------------------+-------------+---------------------------------------------------------------------------------------------------------------------+
    | .help                          | attribute   | Value is ROI responses over an imaging plane. Each row in data[] should correspond to the signal from one ROI       |
    |                                |             |                                                                                                                     |
    |                                |             | - **Data Type:** text                                                                                               |
    |                                |             | - **Value:** ROI responses over an imaging plane. Each row in data[] should correspond to the signal from one ROI   |
    |                                |             |                                                                                                                     |
    +--------------------------------+-------------+---------------------------------------------------------------------------------------------------------------------+
    | .roi_names                     | dataset     | List of ROIs represented, one name for each row of data[].                                                          |
    |                                |             |                                                                                                                     |
    |                                |             | - **Data Type:** text                                                                                               |
    |                                |             | - **Dimensions:** ['num_ROIs']                                                                                      |
    |                                |             | - **Shape:** [None]                                                                                                 |
    |                                |             |                                                                                                                     |
    +--------------------------------+-------------+---------------------------------------------------------------------------------------------------------------------+
    | .data                          | dataset     | Signals from ROIs                                                                                                   |
    |                                |             |                                                                                                                     |
    |                                |             | - **Data Type:** float32                                                                                            |
    |                                |             | - **Dimensions:** ['num_times', 'num_ROIs']                                                                         |
    |                                |             | - **Shape:** [None, None]                                                                                           |
    |                                |             |                                                                                                                     |
    +--------------------------------+-------------+---------------------------------------------------------------------------------------------------------------------+
    | .segmentation_interface_path   | dataset     | Path to segmentation module.                                                                                        |
    |                                |             |                                                                                                                     |
    |                                |             | - **Data Type:** text                                                                                               |
    |                                |             |                                                                                                                     |
    +--------------------------------+-------------+---------------------------------------------------------------------------------------------------------------------+
    | .segmentation_interface        | link        | HDF5 link to image segmentation module defining ROIs.                                                               |
    |                                |             |                                                                                                                     |
    |                                |             | - **Target Type** :ref:`ImageSegmentation <sec-ImageSegmentation>`                                                  |
    |                                |             |                                                                                                                     |
    +--------------------------------+-------------+---------------------------------------------------------------------------------------------------------------------+




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-RoiResponseSeries-groups:

.. table:: Groups contained in <RoiResponseSeries>
    :class: longtable

    +---------------------------+---------+----------------------------------------------------------------------+
    | Id                        | Type    | Description                                                          |
    +===========================+=========+======================================================================+
    | <RoiResponseSeries>       | group   | Top level group for <RoiResponseSeries>                              |
    +---------------------------+---------+----------------------------------------------------------------------+
    | .segmentation_interface   | link    | HDF5 link to image segmentation module defining ROIs.                |
    |                           |         |                                                                      |
    |                           |         | - **Target Type** :ref:`ImageSegmentation <sec-ImageSegmentation>`   |
    |                           |         |                                                                      |
    +---------------------------+---------+----------------------------------------------------------------------+


