.. _sec-MotionCorrection:

MotionCorrection
^^^^^^^^^^^^^^^^

**Extends:** :ref:`NWBContainer <sec-NWBContainer>`

**Source Specification:** see :numref:`sec-MotionCorrection-src`

**Overview:** An image stack where all frames are shifted (registered) to a common coordinate system, to account for movement and drift between frames. Note: each frame at each point in time is assumed to be 2-D (has only x & y dimensions).


``MotionCorrection`` extends ``NWBContainer`` (see :numref:`sec-NWBContainer`) and includes all elements of :ref:`NWBContainer <sec-NWBContainer>` with the following additions or changes.



- **Default Name:** MotionCorrection


.. figure:: ./_format_auto_docs/MotionCorrection.*
    :alt: MotionCorrection




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-MotionCorrection-data:

.. table:: Datasets, Links, and Attributes contained in <MotionCorrection>
    :class: longtable

    +----------------------+-------------+-----------------------------------------------------------------------------------------------+
    | Id                   | Type        | Description                                                                                   |
    +======================+=============+===============================================================================================+
    | <MotionCorrection>   | group       | Top level group for <MotionCorrection>                                                        |
    |                      |             |                                                                                               |
    |                      |             | - **Extends:** :ref:`NWBContainer <sec-NWBContainer>`                                         |
    |                      |             | - **Neurodata Type:** :ref:`MotionCorrection <sec-MotionCorrection>`                          |
    |                      |             | - **Default Name:** MotionCorrection                                                          |
    |                      |             |                                                                                               |
    +----------------------+-------------+-----------------------------------------------------------------------------------------------+
    | .help                | attribute   | Value is 'Image stacks whose frames have been shifted (registered) to account for motion'     |
    |                      |             |                                                                                               |
    |                      |             | - **Data Type:** text                                                                         |
    |                      |             | - **Value:** Image stacks whose frames have been shifted (registered) to account for motion   |
    |                      |             | - **Name:** help                                                                              |
    |                      |             |                                                                                               |
    +----------------------+-------------+-----------------------------------------------------------------------------------------------+




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-MotionCorrection-groups:

.. table:: Groups contained in <MotionCorrection>
    :class: longtable

    +--------------------------+---------+------------------------------------------------------------------------------+
    | Id                       | Type    | Description                                                                  |
    +==========================+=========+==============================================================================+
    | <MotionCorrection>       | group   | Top level group for <MotionCorrection>                                       |
    |                          |         |                                                                              |
    |                          |         | - **Extends:** :ref:`NWBContainer <sec-NWBContainer>`                        |
    |                          |         | - **Neurodata Type:** :ref:`MotionCorrection <sec-MotionCorrection>`         |
    |                          |         | - **Default Name:** MotionCorrection                                         |
    |                          |         |                                                                              |
    +--------------------------+---------+------------------------------------------------------------------------------+
    | .<CorrectedImageStack>   | group   | One of possibly many.  Name should be informative.                           |
    |                          |         |                                                                              |
    |                          |         | - **Quantity** 1 or more                                                     |
    |                          |         | - **Extends:** :ref:`NWBContainer <sec-NWBContainer>`                        |
    |                          |         | - **Neurodata Type:** :ref:`CorrectedImageStack <sec-CorrectedImageStack>`   |
    |                          |         |                                                                              |
    +--------------------------+---------+------------------------------------------------------------------------------+
    | ..original               | link    | HDF5 Link to image series that is being registered.                          |
    |                          |         |                                                                              |
    |                          |         | - **Target Type** :ref:`ImageSeries <sec-ImageSeries>`                       |
    |                          |         | - **Name:** original                                                         |
    |                          |         |                                                                              |
    +--------------------------+---------+------------------------------------------------------------------------------+


Groups: <CorrectedImageStack>
"""""""""""""""""""""""""""""

One of possibly many.  Name should be informative.



- **Quantity** 1 or more
- **Extends:** :ref:`NWBContainer <sec-NWBContainer>`
- **Neurodata Type:** :ref:`CorrectedImageStack <sec-CorrectedImageStack>`


.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. table:: Datasets, Links, and Attributes contained in ``<CorrectedImageStack>``
    :class: longtable

    +-------------------------+-------------+------------------------------------------------------------------------------+
    | Id                      | Type        | Description                                                                  |
    +=========================+=============+==============================================================================+
    | <CorrectedImageStack>   | group       | Top level group for <CorrectedImageStack>                                    |
    |                         |             |                                                                              |
    |                         |             | - **Quantity** 1 or more                                                     |
    |                         |             | - **Extends:** :ref:`NWBContainer <sec-NWBContainer>`                        |
    |                         |             | - **Neurodata Type:** :ref:`CorrectedImageStack <sec-CorrectedImageStack>`   |
    |                         |             |                                                                              |
    +-------------------------+-------------+------------------------------------------------------------------------------+
    | .help                   | attribute   | Value is 'Reuslts from motion correction of an image stack'                  |
    |                         |             |                                                                              |
    |                         |             | - **Data Type:** text                                                        |
    |                         |             | - **Value:** Reuslts from motion correction of an image stack                |
    |                         |             | - **Name:** help                                                             |
    |                         |             |                                                                              |
    +-------------------------+-------------+------------------------------------------------------------------------------+
    | .original               | link        | HDF5 Link to image series that is being registered.                          |
    |                         |             |                                                                              |
    |                         |             | - **Target Type** :ref:`ImageSeries <sec-ImageSeries>`                       |
    |                         |             | - **Name:** original                                                         |
    |                         |             |                                                                              |
    +-------------------------+-------------+------------------------------------------------------------------------------+



.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. table:: Groups contained in <<CorrectedImageStack>>
    :class: longtable

    +-------------------------+---------+----------------------------------------------------------------------------------------------------------------------------------------+
    | Id                      | Type    | Description                                                                                                                            |
    +=========================+=========+========================================================================================================================================+
    | <CorrectedImageStack>   | group   | Top level group for <CorrectedImageStack>                                                                                              |
    |                         |         |                                                                                                                                        |
    |                         |         | - **Quantity** 1 or more                                                                                                               |
    |                         |         | - **Extends:** :ref:`NWBContainer <sec-NWBContainer>`                                                                                  |
    |                         |         | - **Neurodata Type:** :ref:`CorrectedImageStack <sec-CorrectedImageStack>`                                                             |
    |                         |         |                                                                                                                                        |
    +-------------------------+---------+----------------------------------------------------------------------------------------------------------------------------------------+
    | .original               | link    | HDF5 Link to image series that is being registered.                                                                                    |
    |                         |         |                                                                                                                                        |
    |                         |         | - **Target Type** :ref:`ImageSeries <sec-ImageSeries>`                                                                                 |
    |                         |         | - **Name:** original                                                                                                                   |
    |                         |         |                                                                                                                                        |
    +-------------------------+---------+----------------------------------------------------------------------------------------------------------------------------------------+
    | .corrected              | group   | Image stack with frames shifted to the common coordinates.                                                                             |
    |                         |         |                                                                                                                                        |
    |                         |         | - **Extends:** :ref:`ImageSeries <sec-ImageSeries>`                                                                                    |
    |                         |         | - **Name:** corrected                                                                                                                  |
    |                         |         |                                                                                                                                        |
    +-------------------------+---------+----------------------------------------------------------------------------------------------------------------------------------------+
    | .xy_translation         | group   | Stores the x,y delta necessary to align each frame to the common coordinates, for example, to align each frame to a reference image.   |
    |                         |         |                                                                                                                                        |
    |                         |         | - **Extends:** :ref:`TimeSeries <sec-TimeSeries>`                                                                                      |
    |                         |         | - **Name:** xy_translation                                                                                                             |
    |                         |         |                                                                                                                                        |
    +-------------------------+---------+----------------------------------------------------------------------------------------------------------------------------------------+


Groups: <CorrectedImageStack>/corrected
"""""""""""""""""""""""""""""""""""""""

Image stack with frames shifted to the common coordinates.



- **Extends:** :ref:`ImageSeries <sec-ImageSeries>`
- **Name:** corrected

Groups: <CorrectedImageStack>/xy_translation
""""""""""""""""""""""""""""""""""""""""""""

Stores the x,y delta necessary to align each frame to the common coordinates, for example, to align each frame to a reference image.



- **Extends:** :ref:`TimeSeries <sec-TimeSeries>`
- **Name:** xy_translation

