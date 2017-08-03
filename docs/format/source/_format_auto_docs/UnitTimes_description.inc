.. _sec-UnitTimes:

UnitTimes
^^^^^^^^^

**Extends:** :ref:`Interface <sec-Interface>`

**Source Specification:** see :numref:`sec-UnitTimes-src`

**Overview:** Event times of observed units (e.g. cell, synapse, etc.). The UnitTimes group contains a group for each unit. The name of the group should match the value in the source module, if that is possible/relevant (e.g., name of ROIs from Segmentation module).


``UnitTimes`` extends ``Interface`` (see :numref:`sec-Interface`) and includes all elements of :ref:`Interface <sec-Interface>` with the following additions or changes.



.. figure:: ./_format_auto_docs/UnitTimes.*
    :alt: UnitTimes




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-UnitTimes-data:

.. table:: Datasets, Links, and Attributes contained in <UnitTimes>
    :class: longtable

    +--------------+-------------+---------------------------------------------------------+
    | Id           | Type        | Description                                             |
    +==============+=============+=========================================================+
    | UnitTimes    | group       | Top level group for UnitTimes                           |
    +--------------+-------------+---------------------------------------------------------+
    | .help        | attribute   | Value is 'Estimated spike times from a single unit'     |
    |              |             |                                                         |
    |              |             | - **Data Type:** text                                   |
    |              |             | - **Value:** Estimated spike times from a single unit   |
    |              |             |                                                         |
    +--------------+-------------+---------------------------------------------------------+
    | .unit_list   | dataset     | List of units present.                                  |
    |              |             |                                                         |
    |              |             | - **Data Type:** text                                   |
    |              |             | - **Dimensions:** ['num_units']                         |
    |              |             | - **Shape:** [None]                                     |
    |              |             |                                                         |
    +--------------+-------------+---------------------------------------------------------+




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-UnitTimes-groups:

.. table:: Groups contained in <UnitTimes>
    :class: longtable

    +----------------+---------+----------------------------------------------------------+
    | Id             | Type    | Description                                              |
    +================+=========+==========================================================+
    | UnitTimes      | group   | Top level group for UnitTimes                            |
    +----------------+---------+----------------------------------------------------------+
    | .<SpikeUnit>   | group   | Group storing times for <unit_N>.                        |
    |                |         |                                                          |
    |                |         | - **Quantity** 1 or more                                 |
    |                |         | - **Neurodata Type:** :ref:`SpikeUnit <sec-SpikeUnit>`   |
    |                |         |                                                          |
    +----------------+---------+----------------------------------------------------------+


Groups: <SpikeUnit>
"""""""""""""""""""

Group storing times for <unit_N>.



- **Quantity** 1 or more
- **Neurodata Type:** :ref:`SpikeUnit <sec-SpikeUnit>`


.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. table:: Datasets, Links, and Attributes contained in ``<SpikeUnit>``
    :class: longtable

    +---------------------+-----------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | Id                  | Type      | Description                                                                                                                                                                |
    +=====================+===========+============================================================================================================================================================================+
    | <SpikeUnit>         | group     | Top level group for <SpikeUnit>                                                                                                                                            |
    +---------------------+-----------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .times              | dataset   | Spike time for the units (exact or estimated)                                                                                                                              |
    |                     |           |                                                                                                                                                                            |
    |                     |           | - **Data Type:** float64!                                                                                                                                                  |
    |                     |           | - **Dimensions:** ['num_events']                                                                                                                                           |
    |                     |           | - **Shape:** [None]                                                                                                                                                        |
    |                     |           |                                                                                                                                                                            |
    +---------------------+-----------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .source             | dataset   | Name, path or description of where unit times originated. This is necessary only if the info here differs from or is more fine-grained than the interface's source field   |
    |                     |           |                                                                                                                                                                            |
    |                     |           | - **Quantity** 0 or 1                                                                                                                                                      |
    |                     |           | - **Data Type:** text                                                                                                                                                      |
    |                     |           |                                                                                                                                                                            |
    +---------------------+-----------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .unit_description   | dataset   | Description of the unit (eg, cell type).                                                                                                                                   |
    |                     |           |                                                                                                                                                                            |
    |                     |           | - **Data Type:** text                                                                                                                                                      |
    |                     |           |                                                                                                                                                                            |
    +---------------------+-----------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+


