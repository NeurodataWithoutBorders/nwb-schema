.. _sec-Fluorescence:

Fluorescence
^^^^^^^^^^^^

**Extends:** :ref:`NWBContainer <sec-NWBContainer>`

**Source Specification:** see :numref:`sec-Fluorescence-src`

**Overview:** Fluorescence information about a region of interest (ROI). Storage hierarchy of fluorescence should be the same as for segmentation (ie, same names for ROIs and for image planes).


``Fluorescence`` extends ``NWBContainer`` (see :numref:`sec-NWBContainer`) and includes all elements of :ref:`NWBContainer <sec-NWBContainer>` with the following additions or changes.



.. figure:: ./_format_auto_docs/Fluorescence.*
    :alt: Fluorescence




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-Fluorescence-data:

.. table:: Datasets, Links, and Attributes contained in <Fluorescence>
    :class: longtable

    +----------------+-------------+----------------------------------------------------------------------------------------------------------------------+
    | Id             | Type        | Description                                                                                                          |
    +================+=============+======================================================================================================================+
    | Fluorescence   | group       | Top level group for Fluorescence                                                                                     |
    +----------------+-------------+----------------------------------------------------------------------------------------------------------------------+
    | .help          | attribute   | Value is 'Fluorescence over time of one or more ROIs. TimeSeries names should correspond to imaging plane names'     |
    |                |             |                                                                                                                      |
    |                |             | - **Data Type:** text                                                                                                |
    |                |             | - **Value:** Fluorescence over time of one or more ROIs. TimeSeries names should correspond to imaging plane names   |
    |                |             |                                                                                                                      |
    +----------------+-------------+----------------------------------------------------------------------------------------------------------------------+




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-Fluorescence-groups:

.. table:: Groups contained in <Fluorescence>
    :class: longtable

    +-------------------------------------------------------+---------+-------------------------------------------------------------------+
    | Id                                                    | Type    | Description                                                       |
    +=======================================================+=========+===================================================================+
    | Fluorescence                                          | group   | Top level group for Fluorescence                                  |
    +-------------------------------------------------------+---------+-------------------------------------------------------------------+
    | .<:ref:`RoiResponseSeries <sec-RoiResponseSeries>`>   | group   | RoiResponseSeries object containing fluorescence data for a ROI   |
    |                                                       |         |                                                                   |
    |                                                       |         | - **Quantity** 1 or more                                          |
    |                                                       |         | - **Extends:** :ref:`RoiResponseSeries <sec-RoiResponseSeries>`   |
    |                                                       |         |                                                                   |
    +-------------------------------------------------------+---------+-------------------------------------------------------------------+


Groups: <RoiResponseSeries>
"""""""""""""""""""""""""""

RoiResponseSeries object containing fluorescence data for a ROI



- **Quantity** 1 or more
- **Extends:** :ref:`RoiResponseSeries <sec-RoiResponseSeries>`

