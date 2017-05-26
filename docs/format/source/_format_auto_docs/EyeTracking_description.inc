.. _sec-EyeTracking:

EyeTracking
^^^^^^^^^^^

**Extends:** :ref:`Interface <sec-Interface>`

**Source Specification:** see :numref:`sec-EyeTracking-src`

**Overview:** Eye-tracking data, representing direction of gaze.


``EyeTracking`` extends ``Interface`` (see :numref:`sec-Interface`) and includes all elements of :ref:`Interface <sec-Interface>` with the following additions or changes.



.. figure:: ./_format_auto_docs/EyeTracking.*
    :alt: EyeTracking




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-EyeTracking-data:

.. table:: Datasets, Links, and Attributes contained in <EyeTracking>
    :class: longtable

    +---------------+-------------+------------------------------------------------------------------+
    | Id            | Type        | Description                                                      |
    +===============+=============+==================================================================+
    | EyeTracking   | group       | Top level group for EyeTracking                                  |
    +---------------+-------------+------------------------------------------------------------------+
    | .help         | attribute   | Value is 'Eye-tracking data, representing direction of gaze'     |
    |               |             |                                                                  |
    |               |             | - **Data Type:** text                                            |
    |               |             | - **Value:** Eye-tracking data, representing direction of gaze   |
    |               |             |                                                                  |
    +---------------+-------------+------------------------------------------------------------------+




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-EyeTracking-groups:

.. table:: Groups contained in <EyeTracking>
    :class: longtable

    +-----------------------------------------------+---------+--------------------------------------------------------------------+
    | Id                                            | Type    | Description                                                        |
    +===============================================+=========+====================================================================+
    | EyeTracking                                   | group   | Top level group for EyeTracking                                    |
    +-----------------------------------------------+---------+--------------------------------------------------------------------+
    | .<:ref:`SpatialSeries <sec-SpatialSeries>`>   | group   | SpatialSeries object containing data measuring direction of gaze   |
    |                                               |         |                                                                    |
    |                                               |         | - **Quantity** 0 or more                                           |
    |                                               |         | - **Extends:** :ref:`SpatialSeries <sec-SpatialSeries>`            |
    |                                               |         |                                                                    |
    +-----------------------------------------------+---------+--------------------------------------------------------------------+


Groups: <SpatialSeries>
"""""""""""""""""""""""

SpatialSeries object containing data measuring direction of gaze



- **Quantity** 0 or more
- **Extends:** :ref:`SpatialSeries <sec-SpatialSeries>`

