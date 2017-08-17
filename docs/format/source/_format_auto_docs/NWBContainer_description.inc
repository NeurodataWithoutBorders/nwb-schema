.. _sec-NWBContainer:

NWBContainer
^^^^^^^^^^^^

**Source Specification:** see :numref:`sec-NWBContainer-src`

**Overview:** Generic container for storing collections of data. NWBContainer serves as the base type for all main data containers of the core NWB data format. The properties defined by this type are inherited by all derived types.




.. figure:: ./_format_auto_docs/NWBContainer.*
    :alt: NWBContainer




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-NWBContainer-data:

.. table:: Datasets, Links, and Attributes contained in <NWBContainer>
    :class: longtable

    +------------------+-------------+-----------------------------------------------------------------------------------+
    | Id               | Type        | Description                                                                       |
    +==================+=============+===================================================================================+
    | <NWBContainer>   | group       | Top level group for <NWBContainer>                                                |
    |                  |             |                                                                                   |
    |                  |             | - **Neurodata Type:** :ref:`NWBContainer <sec-NWBContainer>`                      |
    |                  |             |                                                                                   |
    +------------------+-------------+-----------------------------------------------------------------------------------+
    | .help            | attribute   | Short description of what this type of NWBContainer contains.                     |
    |                  |             |                                                                                   |
    |                  |             | - **Data Type:** text                                                             |
    |                  |             | - **Name:** help                                                                  |
    |                  |             |                                                                                   |
    +------------------+-------------+-----------------------------------------------------------------------------------+
    | .source          | attribute   | Path to the origin of the data represented in this NWBContainer data container.   |
    |                  |             |                                                                                   |
    |                  |             | - **Data Type:** text                                                             |
    |                  |             | - **Name:** source                                                                |
    |                  |             |                                                                                   |
    +------------------+-------------+-----------------------------------------------------------------------------------+



