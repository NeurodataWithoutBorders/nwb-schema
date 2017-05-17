.. _sec-LFP:

LFP
^^^

**Extends:** :ref:`Interface <sec-Interface>`

**Source Specification:** see :numref:`sec-LFP-src`

**Overview:** LFP data from one or more channels. The electrode map in each published ElectricalSeries will identify which channels are providing LFP data. Filter properties should be noted in the ElectricalSeries description or comments field.


``LFP`` extends ``Interface`` (see :numref:`sec-Interface`) and includes all elements of :ref:`Interface <sec-Interface>` with the following additions or changes.



.. figure:: ./_format_auto_docs/LFP.*
    :alt: LFP




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-LFP-data:

.. table:: Datasets, Links, and Attributes contained in <LFP>
    :class: longtable

    +---------+-------------+--------------------------------------------------------------------------------------------------------------+
    | Id      | Type        | Description                                                                                                  |
    +=========+=============+==============================================================================================================+
    | LFP     | group       | Top level group for LFP                                                                                      |
    +---------+-------------+--------------------------------------------------------------------------------------------------------------+
    | .help   | attribute   | Value is LFP data from one or more channels. Filter properties should be noted in the ElectricalSeries       |
    |         |             |                                                                                                              |
    |         |             | - **Data Type:** text                                                                                        |
    |         |             | - **Value:** LFP data from one or more channels. Filter properties should be noted in the ElectricalSeries   |
    |         |             |                                                                                                              |
    +---------+-------------+--------------------------------------------------------------------------------------------------------------+




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-LFP-groups:

.. table:: Groups contained in <LFP>
    :class: longtable

    +-----------------------------------------------------+---------+-------------------------------------------------------------------+
    | Id                                                  | Type    | Description                                                       |
    +=====================================================+=========+===================================================================+
    | LFP                                                 | group   | Top level group for LFP                                           |
    +-----------------------------------------------------+---------+-------------------------------------------------------------------+
    | .<:ref:`ElectricalSeries <sec-ElectricalSeries>`>   | group   | ElectricalSeries object containing LFP data for one or channels   |
    |                                                     |         |                                                                   |
    |                                                     |         | - **Extends:** :ref:`ElectricalSeries <sec-ElectricalSeries>`     |
    |                                                     |         |                                                                   |
    +-----------------------------------------------------+---------+-------------------------------------------------------------------+


Groups: <ElectricalSeries>
""""""""""""""""""""""""""

ElectricalSeries object containing LFP data for one or channels



- **Extends:** :ref:`ElectricalSeries <sec-ElectricalSeries>`

