.. _sec-CompassDirection:

CompassDirection
^^^^^^^^^^^^^^^^

**Extends:** :ref:`Interface <sec-Interface>`

**Source Specification:** see :numref:`sec-CompassDirection-src`

**Overview:** With a CompassDirection interface, a module publishes a SpatialSeries object representing a floating point value for theta. The SpatialSeries::reference_frame field should indicate what direction corresponds to 0 and which is the direction of rotation (this should be clockwise). The si_unit for the SpatialSeries should be radians or degrees.


``CompassDirection`` extends ``Interface`` (see :numref:`sec-Interface`) and includes all elements of :ref:`Interface <sec-Interface>` with the following additions or changes.



.. figure:: ./_format_auto_docs/CompassDirection.*
    :alt: CompassDirection




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-CompassDirection-data:

.. table:: Datasets, Links, and Attributes contained in <CompassDirection>
    :class: longtable

    +--------------------+-------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | Id                 | Type        | Description                                                                                                                                                                      |
    +====================+=============+==================================================================================================================================================================================+
    | CompassDirection   | group       | Top level group for CompassDirection                                                                                                                                             |
    +--------------------+-------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .help              | attribute   | Value is Direction as measured radially. Spatial series reference frame should indicate which direction corresponds to zero and what is the direction of positive rotation       |
    |                    |             |                                                                                                                                                                                  |
    |                    |             | - **Data Type:** text                                                                                                                                                            |
    |                    |             | - **Value:** Direction as measured radially. Spatial series reference frame should indicate which direction corresponds to zero and what is the direction of positive rotation   |
    |                    |             |                                                                                                                                                                                  |
    +--------------------+-------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-CompassDirection-groups:

.. table:: Groups contained in <CompassDirection>
    :class: longtable

    +-----------------------------------------------+---------+------------------------------------------------------------+
    | Id                                            | Type    | Description                                                |
    +===============================================+=========+============================================================+
    | CompassDirection                              | group   | Top level group for CompassDirection                       |
    +-----------------------------------------------+---------+------------------------------------------------------------+
    | .<:ref:`SpatialSeries <sec-SpatialSeries>`>   | group   | SpatialSeries object containing direction of gaze travel   |
    |                                               |         |                                                            |
    |                                               |         | - **Extends:** :ref:`SpatialSeries <sec-SpatialSeries>`    |
    |                                               |         |                                                            |
    +-----------------------------------------------+---------+------------------------------------------------------------+


Groups: <SpatialSeries>
"""""""""""""""""""""""

SpatialSeries object containing direction of gaze travel



- **Extends:** :ref:`SpatialSeries <sec-SpatialSeries>`

