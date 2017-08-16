.. _sec-EyeTracking:

EyeTracking
^^^^^^^^^^^

**Extends:** :ref:`NWBContainer <sec-NWBContainer>`

**Source Specification:** see :numref:`sec-EyeTracking-src`

**Overview:** Eye-tracking data, representing direction of gaze.


``EyeTracking`` extends ``NWBContainer`` (see :numref:`sec-NWBContainer`) and includes all elements of :ref:`NWBContainer <sec-NWBContainer>` with the following additions or changes.



- **Default Name:** EyeTracking


.. figure:: ./_format_auto_docs/EyeTracking.*
    :alt: EyeTracking




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-EyeTracking-data:

.. table:: Datasets, Links, and Attributes contained in <EyeTracking>
    :class: longtable

    +-----------------+-------------+------------------------------------------------------------------+
    | Id              | Type        | Description                                                      |
    +=================+=============+==================================================================+
    | <EyeTracking>   | group       | Top level group for <EyeTracking>                                |
    |                 |             |                                                                  |
    |                 |             | - **Extends:** :ref:`NWBContainer <sec-NWBContainer>`            |
    |                 |             | - **Neurodata Type:** :ref:`EyeTracking <sec-EyeTracking>`       |
    |                 |             | - **Default Name:** EyeTracking                                  |
    |                 |             |                                                                  |
    +-----------------+-------------+------------------------------------------------------------------+
    | .help           | attribute   | Value is 'Eye-tracking data, representing direction of gaze'     |
    |                 |             |                                                                  |
    |                 |             | - **Data Type:** text                                            |
    |                 |             | - **Value:** Eye-tracking data, representing direction of gaze   |
    |                 |             | - **Name:** help                                                 |
    |                 |             |                                                                  |
    +-----------------+-------------+------------------------------------------------------------------+




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-EyeTracking-groups:

.. table:: Groups contained in <EyeTracking>
    :class: longtable

    +-----------------------------------------------+---------+--------------------------------------------------------------------+
    | Id                                            | Type    | Description                                                        |
    +===============================================+=========+====================================================================+
    | <EyeTracking>                                 | group   | Top level group for <EyeTracking>                                  |
    |                                               |         |                                                                    |
    |                                               |         | - **Extends:** :ref:`NWBContainer <sec-NWBContainer>`              |
    |                                               |         | - **Neurodata Type:** :ref:`EyeTracking <sec-EyeTracking>`         |
    |                                               |         | - **Default Name:** EyeTracking                                    |
    |                                               |         |                                                                    |
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

