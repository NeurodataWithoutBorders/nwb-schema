.. _sec-SpikeUnit:

SpikeUnit
^^^^^^^^^

**Extends:** :ref:`NWBContainer <sec-NWBContainer>`

**Source Specification:** see :numref:`sec-SpikeUnit-src`

**Overview:** Group storing times for <unit_N>.


``SpikeUnit`` extends ``NWBContainer`` (see :numref:`sec-NWBContainer`) and includes all elements of :ref:`NWBContainer <sec-NWBContainer>` with the following additions or changes.



- **Quantity** 1 or more


.. figure:: ./_format_auto_docs/SpikeUnit.*
    :alt: SpikeUnit




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-SpikeUnit-data:

.. table:: Datasets, Links, and Attributes contained in <SpikeUnit>
    :class: longtable

    +---------------------+-------------+-------------------------------------------------------+
    | Id                  | Type        | Description                                           |
    +=====================+=============+=======================================================+
    | <SpikeUnit>         | group       | Top level group for <SpikeUnit>                       |
    +---------------------+-------------+-------------------------------------------------------+
    | .help               | attribute   | Store times for a particulare UnitTime                |
    |                     |             |                                                       |
    |                     |             | - **Data Type:** text                                 |
    |                     |             | - **Value:** Times for a particular UnitTime object   |
    |                     |             |                                                       |
    +---------------------+-------------+-------------------------------------------------------+
    | .times              | dataset     | Spike time for the units (exact or estimated)         |
    |                     |             |                                                       |
    |                     |             | - **Data Type:** float64!                             |
    |                     |             | - **Dimensions:** ['num_events']                      |
    |                     |             | - **Shape:** [None]                                   |
    |                     |             |                                                       |
    +---------------------+-------------+-------------------------------------------------------+
    | .unit_description   | dataset     | Description of the unit (eg, cell type).              |
    |                     |             |                                                       |
    |                     |             | - **Data Type:** text                                 |
    |                     |             |                                                       |
    +---------------------+-------------+-------------------------------------------------------+



