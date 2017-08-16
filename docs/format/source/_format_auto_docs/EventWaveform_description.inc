.. _sec-EventWaveform:

EventWaveform
^^^^^^^^^^^^^

**Extends:** :ref:`NWBContainer <sec-NWBContainer>`

**Source Specification:** see :numref:`sec-EventWaveform-src`

**Overview:** Represents either the waveforms of detected events, as extracted from a raw data trace in /acquisition, or the event waveforms that were stored during experiment acquisition.


``EventWaveform`` extends ``NWBContainer`` (see :numref:`sec-NWBContainer`) and includes all elements of :ref:`NWBContainer <sec-NWBContainer>` with the following additions or changes.



- **Default Name:** EventWaveform


.. figure:: ./_format_auto_docs/EventWaveform.*
    :alt: EventWaveform




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-EventWaveform-data:

.. table:: Datasets, Links, and Attributes contained in <EventWaveform>
    :class: longtable

    +-------------------+-------------+---------------------------------------------------------------------------+
    | Id                | Type        | Description                                                               |
    +===================+=============+===========================================================================+
    | <EventWaveform>   | group       | Top level group for <EventWaveform>                                       |
    |                   |             |                                                                           |
    |                   |             | - **Extends:** :ref:`NWBContainer <sec-NWBContainer>`                     |
    |                   |             | - **Neurodata Type:** :ref:`EventWaveform <sec-EventWaveform>`            |
    |                   |             | - **Default Name:** EventWaveform                                         |
    |                   |             |                                                                           |
    +-------------------+-------------+---------------------------------------------------------------------------+
    | .help             | attribute   | Value is 'Waveform of detected extracellularly recorded spike events'     |
    |                   |             |                                                                           |
    |                   |             | - **Data Type:** text                                                     |
    |                   |             | - **Value:** Waveform of detected extracellularly recorded spike events   |
    |                   |             | - **Name:** help                                                          |
    |                   |             |                                                                           |
    +-------------------+-------------+---------------------------------------------------------------------------+




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-EventWaveform-groups:

.. table:: Groups contained in <EventWaveform>
    :class: longtable

    +-----------------------------------------------------+---------+---------------------------------------------------------------------+
    | Id                                                  | Type    | Description                                                         |
    +=====================================================+=========+=====================================================================+
    | <EventWaveform>                                     | group   | Top level group for <EventWaveform>                                 |
    |                                                     |         |                                                                     |
    |                                                     |         | - **Extends:** :ref:`NWBContainer <sec-NWBContainer>`               |
    |                                                     |         | - **Neurodata Type:** :ref:`EventWaveform <sec-EventWaveform>`      |
    |                                                     |         | - **Default Name:** EventWaveform                                   |
    |                                                     |         |                                                                     |
    +-----------------------------------------------------+---------+---------------------------------------------------------------------+
    | .<:ref:`SpikeEventSeries <sec-SpikeEventSeries>`>   | group   | SpikeEventSeries object containing detected spike event waveforms   |
    |                                                     |         |                                                                     |
    |                                                     |         | - **Quantity** 0 or more                                            |
    |                                                     |         | - **Extends:** :ref:`SpikeEventSeries <sec-SpikeEventSeries>`       |
    |                                                     |         |                                                                     |
    +-----------------------------------------------------+---------+---------------------------------------------------------------------+


Groups: <SpikeEventSeries>
""""""""""""""""""""""""""

SpikeEventSeries object containing detected spike event waveforms



- **Quantity** 0 or more
- **Extends:** :ref:`SpikeEventSeries <sec-SpikeEventSeries>`

