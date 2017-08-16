.. _sec-CompassDirection:

CompassDirection
^^^^^^^^^^^^^^^^

**Extends:** :ref:`NWBContainer <sec-NWBContainer>`

**Source Specification:** see :numref:`sec-CompassDirection-src`

**Overview:** With a CompassDirection interface, a module publishes a SpatialSeries object representing a floating point value for theta. The SpatialSeries::reference_frame field should indicate what direction corresponds to 0 and which is the direction of rotation (this should be clockwise). The si_unit for the SpatialSeries should be radians or degrees.


``CompassDirection`` extends ``NWBContainer`` (see :numref:`sec-NWBContainer`) and includes all elements of :ref:`NWBContainer <sec-NWBContainer>` with the following additions or changes.



- **Default Name:** CompassDirection


.. figure:: ./_format_auto_docs/CompassDirection.*
    :alt: CompassDirection




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-CompassDirection-data:

.. table:: Datasets, Links, and Attributes contained in <CompassDirection>
    :class: longtable

    +----------------------+-------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | Id                   | Type        | Description                                                                                                                                                                      |
    +======================+=============+==================================================================================================================================================================================+
    | <CompassDirection>   | group       | Top level group for <CompassDirection>                                                                                                                                           |
    +----------------------+-------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .help                | attribute   | Value is 'Direction as measured radially. Spatial series reference frame should indicate which direction corresponds to zero and what is the direction of positive rotation'     |
    |                      |             |                                                                                                                                                                                  |
    |                      |             | - **Data Type:** text                                                                                                                                                            |
    |                      |             | - **Value:** Direction as measured radially. Spatial series reference frame should indicate which direction corresponds to zero and what is the direction of positive rotation   |
    |                      |             |                                                                                                                                                                                  |
    +----------------------+-------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-CompassDirection-groups:

.. table:: Groups contained in <CompassDirection>
    :class: longtable

    +-----------------------------------------------+---------+------------------------------------------------------------+
    | Id                                            | Type    | Description                                                |
    +===============================================+=========+============================================================+
    | <CompassDirection>                            | group   | Top level group for <CompassDirection>                     |
    +-----------------------------------------------+---------+------------------------------------------------------------+
    | .<:ref:`SpatialSeries <sec-SpatialSeries>`>   | group   | SpatialSeries object containing direction of gaze travel   |
    |                                               |         |                                                            |
    |                                               |         | - **Quantity** 0 or more                                   |
    |                                               |         | - **Extends:** :ref:`SpatialSeries <sec-SpatialSeries>`    |
    |                                               |         |                                                            |
    +-----------------------------------------------+---------+------------------------------------------------------------+


Groups: <SpatialSeries>
"""""""""""""""""""""""

SpatialSeries object containing direction of gaze travel



- **Quantity** 0 or more
- **Extends:** :ref:`SpatialSeries <sec-SpatialSeries>`

