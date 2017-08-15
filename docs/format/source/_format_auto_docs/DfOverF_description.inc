.. _sec-DfOverF:

DfOverF
^^^^^^^

**Extends:** :ref:`NWBContainer <sec-NWBContainer>`

**Source Specification:** see :numref:`sec-DfOverF-src`

**Overview:** dF/F information about a region of interest (ROI). Storage hierarchy of dF/F should be the same as for segmentation (ie, same names for ROIs and for image planes).


``DfOverF`` extends ``NWBContainer`` (see :numref:`sec-NWBContainer`) and includes all elements of :ref:`NWBContainer <sec-NWBContainer>` with the following additions or changes.



.. figure:: ./_format_auto_docs/DfOverF.*
    :alt: DfOverF




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-DfOverF-data:

.. table:: Datasets, Links, and Attributes contained in <DfOverF>
    :class: longtable

    +-----------+-------------+--------------------------------------------------------------------------------------------------------------+
    | Id        | Type        | Description                                                                                                  |
    +===========+=============+==============================================================================================================+
    | DfOverF   | group       | Top level group for DfOverF                                                                                  |
    +-----------+-------------+--------------------------------------------------------------------------------------------------------------+
    | .help     | attribute   | Value is 'Df/f over time of one or more ROIs. TimeSeries names should correspond to imaging plane names'     |
    |           |             |                                                                                                              |
    |           |             | - **Data Type:** text                                                                                        |
    |           |             | - **Value:** Df/f over time of one or more ROIs. TimeSeries names should correspond to imaging plane names   |
    |           |             |                                                                                                              |
    +-----------+-------------+--------------------------------------------------------------------------------------------------------------+




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-DfOverF-groups:

.. table:: Groups contained in <DfOverF>
    :class: longtable

    +-------------------------------------------------------+---------+-------------------------------------------------------------------+
    | Id                                                    | Type    | Description                                                       |
    +=======================================================+=========+===================================================================+
    | DfOverF                                               | group   | Top level group for DfOverF                                       |
    +-------------------------------------------------------+---------+-------------------------------------------------------------------+
    | .<:ref:`RoiResponseSeries <sec-RoiResponseSeries>`>   | group   | RoiResponseSeries object containing dF/F for a ROI                |
    |                                                       |         |                                                                   |
    |                                                       |         | - **Quantity** 0 or more                                          |
    |                                                       |         | - **Extends:** :ref:`RoiResponseSeries <sec-RoiResponseSeries>`   |
    |                                                       |         |                                                                   |
    +-------------------------------------------------------+---------+-------------------------------------------------------------------+


Groups: <RoiResponseSeries>
"""""""""""""""""""""""""""

RoiResponseSeries object containing dF/F for a ROI



- **Quantity** 0 or more
- **Extends:** :ref:`RoiResponseSeries <sec-RoiResponseSeries>`

