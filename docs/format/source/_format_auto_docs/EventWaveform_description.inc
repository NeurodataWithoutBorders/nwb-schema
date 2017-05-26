.. _sec-EventWaveform:

EventWaveform
^^^^^^^^^^^^^

**Extends:** :ref:`Interface <sec-Interface>`

**Source Specification:** see :numref:`sec-EventWaveform-src`

**Overview:** Represents either the waveforms of detected events, as extracted from a raw data trace in /acquisition, or the event waveforms that were stored during experiment acquisition.


``EventWaveform`` extends ``Interface`` (see :numref:`sec-Interface`) and includes all elements of :ref:`Interface <sec-Interface>` with the following additions or changes.



.. figure:: ./_format_auto_docs/EventWaveform.*
    :alt: EventWaveform




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-EventWaveform-data:

.. table:: Datasets, Links, and Attributes contained in <EventWaveform>
    :class: longtable

    +-----------------+-------------+---------------------------------------------------------------------------+
    | Id              | Type        | Description                                                               |
    +=================+=============+===========================================================================+
    | EventWaveform   | group       | Top level group for EventWaveform                                         |
    +-----------------+-------------+---------------------------------------------------------------------------+
    | .help           | attribute   | Value is 'Waveform of detected extracellularly recorded spike events'     |
    |                 |             |                                                                           |
    |                 |             | - **Data Type:** text                                                     |
    |                 |             | - **Value:** Waveform of detected extracellularly recorded spike events   |
    |                 |             |                                                                           |
    +-----------------+-------------+---------------------------------------------------------------------------+




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-EventWaveform-groups:

.. table:: Groups contained in <EventWaveform>
    :class: longtable

    +-----------------------------------------------------+---------+---------------------------------------------------------------------+
    | Id                                                  | Type    | Description                                                         |
    +=====================================================+=========+=====================================================================+
    | EventWaveform                                       | group   | Top level group for EventWaveform                                   |
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

