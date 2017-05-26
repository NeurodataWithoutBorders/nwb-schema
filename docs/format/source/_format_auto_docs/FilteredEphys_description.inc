.. _sec-FilteredEphys:

FilteredEphys
^^^^^^^^^^^^^

**Extends:** :ref:`Interface <sec-Interface>`

**Source Specification:** see :numref:`sec-FilteredEphys-src`

**Overview:** Ephys data from one or more channels that has been subjected to filtering. Examples of filtered data include Theta and Gamma (LFP has its own interface). FilteredEphys modules publish an ElectricalSeries for each filtered channel or set of channels. The name of each ElectricalSeries is arbitrary but should be informative. The source of the filtered data, whether this is from analysis of another time series or as acquired by hardware, should be noted in each's TimeSeries::description field. There is no assumed 1::1 correspondence between filtered ephys signals and electrodes, as a single signal can apply to many nearby electrodes, and one electrode may have different filtered (e.g., theta and/or gamma) signals represented.


``FilteredEphys`` extends ``Interface`` (see :numref:`sec-Interface`) and includes all elements of :ref:`Interface <sec-Interface>` with the following additions or changes.



.. figure:: ./_format_auto_docs/FilteredEphys.*
    :alt: FilteredEphys




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-FilteredEphys-data:

.. table:: Datasets, Links, and Attributes contained in <FilteredEphys>
    :class: longtable

    +-----------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | Id              | Type        | Description                                                                                                                                                                                                        |
    +=================+=============+====================================================================================================================================================================================================================+
    | FilteredEphys   | group       | Top level group for FilteredEphys                                                                                                                                                                                  |
    +-----------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .help           | attribute   | Value is 'Ephys data from one or more channels that is subjected to filtering, such as for gamma or theta oscillations (LFP has its own interface). Filter properties should be noted in the ElectricalSeries'     |
    |                 |             |                                                                                                                                                                                                                    |
    |                 |             | - **Data Type:** text                                                                                                                                                                                              |
    |                 |             | - **Value:** Ephys data from one or more channels that is subjected to filtering, such as for gamma or theta oscillations (LFP has its own interface). Filter properties should be noted in the ElectricalSeries   |
    |                 |             |                                                                                                                                                                                                                    |
    +-----------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-FilteredEphys-groups:

.. table:: Groups contained in <FilteredEphys>
    :class: longtable

    +-----------------------------------------------------+---------+----------------------------------------------------------------------+
    | Id                                                  | Type    | Description                                                          |
    +=====================================================+=========+======================================================================+
    | FilteredEphys                                       | group   | Top level group for FilteredEphys                                    |
    +-----------------------------------------------------+---------+----------------------------------------------------------------------+
    | .<:ref:`ElectricalSeries <sec-ElectricalSeries>`>   | group   | ElectricalSeries object containing filtered electrophysiology data   |
    |                                                     |         |                                                                      |
    |                                                     |         | - **Quantity** 1 or more                                             |
    |                                                     |         | - **Extends:** :ref:`ElectricalSeries <sec-ElectricalSeries>`        |
    |                                                     |         |                                                                      |
    +-----------------------------------------------------+---------+----------------------------------------------------------------------+


Groups: <ElectricalSeries>
""""""""""""""""""""""""""

ElectricalSeries object containing filtered electrophysiology data



- **Quantity** 1 or more
- **Extends:** :ref:`ElectricalSeries <sec-ElectricalSeries>`

