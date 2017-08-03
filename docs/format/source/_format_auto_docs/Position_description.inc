.. _sec-Position:

Position
^^^^^^^^

**Extends:** :ref:`Interface <sec-Interface>`

**Source Specification:** see :numref:`sec-Position-src`

**Overview:** Position data, whether along the x, x/y or x/y/z axis.


``Position`` extends ``Interface`` (see :numref:`sec-Interface`) and includes all elements of :ref:`Interface <sec-Interface>` with the following additions or changes.



.. figure:: ./_format_auto_docs/Position.*
    :alt: Position




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-Position-data:

.. table:: Datasets, Links, and Attributes contained in <Position>
    :class: longtable

    +------------+-------------+-------------------------------------------------------------------+
    | Id         | Type        | Description                                                       |
    +============+=============+===================================================================+
    | Position   | group       | Top level group for Position                                      |
    +------------+-------------+-------------------------------------------------------------------+
    | .help      | attribute   | Value is 'Position data, whether along the x, xy or xyz axis'     |
    |            |             |                                                                   |
    |            |             | - **Data Type:** text                                             |
    |            |             | - **Value:** Position data, whether along the x, xy or xyz axis   |
    |            |             |                                                                   |
    +------------+-------------+-------------------------------------------------------------------+




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-Position-groups:

.. table:: Groups contained in <Position>
    :class: longtable

    +-----------------------------------------------+---------+-----------------------------------------------------------+
    | Id                                            | Type    | Description                                               |
    +===============================================+=========+===========================================================+
    | Position                                      | group   | Top level group for Position                              |
    +-----------------------------------------------+---------+-----------------------------------------------------------+
    | .<:ref:`SpatialSeries <sec-SpatialSeries>`>   | group   | SpatialSeries object containing position data             |
    |                                               |         |                                                           |
    |                                               |         | - **Quantity** 1 or more                                  |
    |                                               |         | - **Extends:** :ref:`SpatialSeries <sec-SpatialSeries>`   |
    |                                               |         |                                                           |
    +-----------------------------------------------+---------+-----------------------------------------------------------+


Groups: <SpatialSeries>
"""""""""""""""""""""""

SpatialSeries object containing position data



- **Quantity** 1 or more
- **Extends:** :ref:`SpatialSeries <sec-SpatialSeries>`

