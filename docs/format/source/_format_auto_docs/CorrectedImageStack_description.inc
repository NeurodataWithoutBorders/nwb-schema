.. _sec-CorrectedImageStack:

CorrectedImageStack
^^^^^^^^^^^^^^^^^^^

**Source Specification:** see :numref:`sec-CorrectedImageStack-src`

**Overview:** One of possibly many.  Name should be informative.




- **Quantity** 1 or more


.. figure:: ./_format_auto_docs/CorrectedImageStack.*
    :alt: CorrectedImageStack




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-CorrectedImageStack-data:

.. table:: Datasets, Links, and Attributes contained in <CorrectedImageStack>
    :class: longtable

    +-------------------------+-----------+----------------------------------------------------------+
    | Id                      | Type      | Description                                              |
    +=========================+===========+==========================================================+
    | <CorrectedImageStack>   | group     | Top level group for <CorrectedImageStack>                |
    +-------------------------+-----------+----------------------------------------------------------+
    | .original_path          | dataset   | Path to linked original timeseries                       |
    |                         |           |                                                          |
    |                         |           | - **Data Type:** text                                    |
    |                         |           |                                                          |
    +-------------------------+-----------+----------------------------------------------------------+
    | .original               | link      | HDF5 Link to image series that is being registered.      |
    |                         |           |                                                          |
    |                         |           | - **Target Type** :ref:`ImageSeries <sec-ImageSeries>`   |
    |                         |           |                                                          |
    +-------------------------+-----------+----------------------------------------------------------+




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-CorrectedImageStack-groups:

.. table:: Groups contained in <CorrectedImageStack>
    :class: longtable

    +-------------------------------------------+---------+----------------------------------------------------------------------------------------------------------------------------------------+
    | Id                                        | Type    | Description                                                                                                                            |
    +===========================================+=========+========================================================================================================================================+
    | <CorrectedImageStack>                     | group   | Top level group for <CorrectedImageStack>                                                                                              |
    +-------------------------------------------+---------+----------------------------------------------------------------------------------------------------------------------------------------+
    | .original                                 | link    | HDF5 Link to image series that is being registered.                                                                                    |
    |                                           |         |                                                                                                                                        |
    |                                           |         | - **Target Type** :ref:`ImageSeries <sec-ImageSeries>`                                                                                 |
    |                                           |         |                                                                                                                                        |
    +-------------------------------------------+---------+----------------------------------------------------------------------------------------------------------------------------------------+
    | .<:ref:`ImageSeries <sec-ImageSeries>`>   | group   | Image stack with frames shifted to the common coordinates.                                                                             |
    |                                           |         |                                                                                                                                        |
    |                                           |         | - **Extends:** :ref:`ImageSeries <sec-ImageSeries>`                                                                                    |
    |                                           |         |                                                                                                                                        |
    +-------------------------------------------+---------+----------------------------------------------------------------------------------------------------------------------------------------+
    | .<:ref:`TimeSeries <sec-TimeSeries>`>     | group   | Stores the x,y delta necessary to align each frame to the common coordinates, for example, to align each frame to a reference image.   |
    |                                           |         |                                                                                                                                        |
    |                                           |         | - **Extends:** :ref:`TimeSeries <sec-TimeSeries>`                                                                                      |
    |                                           |         |                                                                                                                                        |
    +-------------------------------------------+---------+----------------------------------------------------------------------------------------------------------------------------------------+


Groups: <ImageSeries>
"""""""""""""""""""""

Image stack with frames shifted to the common coordinates.



- **Extends:** :ref:`ImageSeries <sec-ImageSeries>`

Groups: <TimeSeries>
""""""""""""""""""""

Stores the x,y delta necessary to align each frame to the common coordinates, for example, to align each frame to a reference image.



- **Extends:** :ref:`TimeSeries <sec-TimeSeries>`

