.. _sec-CorrectedImageStack:

CorrectedImageStack
^^^^^^^^^^^^^^^^^^^

**Extends:** :ref:`NWBContainer <sec-NWBContainer>`

**Source Specification:** see :numref:`sec-CorrectedImageStack-src`

**Overview:** One of possibly many.  Name should be informative.


``CorrectedImageStack`` extends ``NWBContainer`` (see :numref:`sec-NWBContainer`) and includes all elements of :ref:`NWBContainer <sec-NWBContainer>` with the following additions or changes.



- **Quantity** 1 or more


.. figure:: ./_format_auto_docs/CorrectedImageStack.*
    :alt: CorrectedImageStack




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-CorrectedImageStack-data:

.. table:: Datasets, Links, and Attributes contained in <CorrectedImageStack>
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
.. _table-CorrectedImageStack-groups:

.. table:: Groups contained in <CorrectedImageStack>
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


Groups: corrected
"""""""""""""""""

Image stack with frames shifted to the common coordinates.



- **Extends:** :ref:`ImageSeries <sec-ImageSeries>`
- **Name:** corrected

Groups: xy_translation
""""""""""""""""""""""

Stores the x,y delta necessary to align each frame to the common coordinates, for example, to align each frame to a reference image.



- **Extends:** :ref:`TimeSeries <sec-TimeSeries>`
- **Name:** xy_translation

