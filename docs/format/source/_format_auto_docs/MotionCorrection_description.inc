.. _sec-MotionCorrection:

MotionCorrection
^^^^^^^^^^^^^^^^

**Extends:** :ref:`Interface <sec-Interface>`

**Source Specification:** see :numref:`sec-MotionCorrection-src`

**Overview:** An image stack where all frames are shifted (registered) to a common coordinate system, to account for movement and drift between frames. Note: each frame at each point in time is assumed to be 2-D (has only x & y dimensions).


``MotionCorrection`` extends ``Interface`` (see :numref:`sec-Interface`) and includes all elements of :ref:`Interface <sec-Interface>` with the following additions or changes.



.. figure:: ./_format_auto_docs/MotionCorrection.*
    :alt: MotionCorrection




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-MotionCorrection-data:

.. table:: Datasets, Links, and Attributes contained in <MotionCorrection>
    :class: longtable

    +--------------------+-------------+-----------------------------------------------------------------------------------------------+
    | Id                 | Type        | Description                                                                                   |
    +====================+=============+===============================================================================================+
    | MotionCorrection   | group       | Top level group for MotionCorrection                                                          |
    +--------------------+-------------+-----------------------------------------------------------------------------------------------+
    | .help              | attribute   | Value is Image stacks whose frames have been shifted (registered) to account for motion       |
    |                    |             |                                                                                               |
    |                    |             | - **Data Type:** text                                                                         |
    |                    |             | - **Value:** Image stacks whose frames have been shifted (registered) to account for motion   |
    |                    |             |                                                                                               |
    +--------------------+-------------+-----------------------------------------------------------------------------------------------+




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-MotionCorrection-groups:

.. table:: Groups contained in <MotionCorrection>
    :class: longtable

    +--------------------------+---------+------------------------------------------------------------------------------+
    | Id                       | Type    | Description                                                                  |
    +==========================+=========+==============================================================================+
    | MotionCorrection         | group   | Top level group for MotionCorrection                                         |
    +--------------------------+---------+------------------------------------------------------------------------------+
    | .<CorrectedImageStack>   | group   | One of possibly many.  Name should be informative.                           |
    |                          |         |                                                                              |
    |                          |         | - **Quantity** 1 or more                                                     |
    |                          |         | - **Neurodata Type:** :ref:`CorrectedImageStack <sec-CorrectedImageStack>`   |
    |                          |         |                                                                              |
    +--------------------------+---------+------------------------------------------------------------------------------+
    | ..original               | link    | HDF5 Link to image series that is being registered.                          |
    |                          |         |                                                                              |
    |                          |         | - **Target Type** :ref:`ImageSeries <sec-ImageSeries>`                       |
    |                          |         |                                                                              |
    +--------------------------+---------+------------------------------------------------------------------------------+


Groups: <CorrectedImageStack>
"""""""""""""""""""""""""""""

One of possibly many.  Name should be informative.



- **Quantity** 1 or more
- **Neurodata Type:** :ref:`CorrectedImageStack <sec-CorrectedImageStack>`


.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. table:: Datasets, Links, and Attributes contained in ``<CorrectedImageStack>``
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
.. table:: Groups contained in <<CorrectedImageStack>>
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
    | .<:ref:`TimeSeries <sec-TimeSeries>`>     | group   | Stores the x,y delta necessary to align each frame to the common coordinates, for example, to align each frame to a reference image.   |
    |                                           |         |                                                                                                                                        |
    |                                           |         | - **Extends:** :ref:`TimeSeries <sec-TimeSeries>`                                                                                      |
    |                                           |         |                                                                                                                                        |
    +-------------------------------------------+---------+----------------------------------------------------------------------------------------------------------------------------------------+
    | .<:ref:`ImageSeries <sec-ImageSeries>`>   | group   | Image stack with frames shifted to the common coordinates.                                                                             |
    |                                           |         |                                                                                                                                        |
    |                                           |         | - **Extends:** :ref:`ImageSeries <sec-ImageSeries>`                                                                                    |
    |                                           |         |                                                                                                                                        |
    +-------------------------------------------+---------+----------------------------------------------------------------------------------------------------------------------------------------+


Groups: <CorrectedImageStack>/<TimeSeries>
""""""""""""""""""""""""""""""""""""""""""

Stores the x,y delta necessary to align each frame to the common coordinates, for example, to align each frame to a reference image.



- **Extends:** :ref:`TimeSeries <sec-TimeSeries>`

Groups: <CorrectedImageStack>/<ImageSeries>
"""""""""""""""""""""""""""""""""""""""""""

Image stack with frames shifted to the common coordinates.



- **Extends:** :ref:`ImageSeries <sec-ImageSeries>`

