.. _sec-UnitTimes:

UnitTimes
^^^^^^^^^

**Extends:** :ref:`NWBContainer <sec-NWBContainer>`

**Source Specification:** see :numref:`sec-UnitTimes-src`

**Overview:** Event times of observed units (e.g. cell, synapse, etc.). The UnitTimes group contains a group for each unit. The name of the group should match the value in the source module, if that is possible/relevant (e.g., name of ROIs from Segmentation module).


``UnitTimes`` extends ``NWBContainer`` (see :numref:`sec-NWBContainer`) and includes all elements of :ref:`NWBContainer <sec-NWBContainer>` with the following additions or changes.



.. figure:: ./_format_auto_docs/UnitTimes.*
    :alt: UnitTimes




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-UnitTimes-data:

.. table:: Datasets, Links, and Attributes contained in <UnitTimes>
    :class: longtable

    +-------------+-------------+---------------------------------------------------------+
    | Id          | Type        | Description                                             |
    +=============+=============+=========================================================+
    | UnitTimes   | group       | Top level group for UnitTimes                           |
    +-------------+-------------+---------------------------------------------------------+
    | .help       | attribute   | Value is 'Estimated spike times from a single unit'     |
    |             |             |                                                         |
    |             |             | - **Data Type:** text                                   |
    |             |             | - **Value:** Estimated spike times from a single unit   |
    |             |             |                                                         |
    +-------------+-------------+---------------------------------------------------------+




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
    |                |         | - **Extends:** :ref:`NWBContainer <sec-NWBContainer>`    |
    |                |         | - **Neurodata Type:** :ref:`SpikeUnit <sec-SpikeUnit>`   |
    |                |         |                                                          |
    +----------------+---------+----------------------------------------------------------+


Groups: <SpikeUnit>
"""""""""""""""""""

Group storing times for <unit_N>.



- **Quantity** 1 or more
- **Extends:** :ref:`NWBContainer <sec-NWBContainer>`
- **Neurodata Type:** :ref:`SpikeUnit <sec-SpikeUnit>`


.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. table:: Datasets, Links, and Attributes contained in ``<SpikeUnit>``
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


