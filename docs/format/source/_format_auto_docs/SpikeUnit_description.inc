.. _sec-SpikeUnit:

SpikeUnit
^^^^^^^^^

**Source Specification:** see :numref:`sec-SpikeUnit-src`

**Overview:** Group storing times for <unit_N>.




- **Quantity** 1 or more


.. figure:: ./_format_auto_docs/SpikeUnit.*
    :alt: SpikeUnit




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-SpikeUnit-data:

.. table:: Datasets, Links, and Attributes contained in <SpikeUnit>
    :class: longtable

    +---------------------+-----------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | Id                  | Type      | Description                                                                                                                                                                |
    +=====================+===========+============================================================================================================================================================================+
    | <SpikeUnit>         | group     | Top level group for <SpikeUnit>                                                                                                                                            |
    +---------------------+-----------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .unit_description   | dataset   | Description of the unit (eg, cell type).                                                                                                                                   |
    |                     |           |                                                                                                                                                                            |
    |                     |           | - **Data Type:** text                                                                                                                                                      |
    |                     |           |                                                                                                                                                                            |
    +---------------------+-----------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .source             | dataset   | Name, path or description of where unit times originated. This is necessary only if the info here differs from or is more fine-grained than the interface's source field   |
    |                     |           |                                                                                                                                                                            |
    |                     |           | - **Quantity** 0 or 1                                                                                                                                                      |
    |                     |           | - **Data Type:** text                                                                                                                                                      |
    |                     |           |                                                                                                                                                                            |
    +---------------------+-----------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .times              | dataset   | Spike time for the units (exact or estimated)                                                                                                                              |
    |                     |           |                                                                                                                                                                            |
    |                     |           | - **Data Type:** float64!                                                                                                                                                  |
    |                     |           | - **Dimensions:** ['num_events']                                                                                                                                           |
    |                     |           | - **Shape:** [None]                                                                                                                                                        |
    |                     |           |                                                                                                                                                                            |
    +---------------------+-----------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+



