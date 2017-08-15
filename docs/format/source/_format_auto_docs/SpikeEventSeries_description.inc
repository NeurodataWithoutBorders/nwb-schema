.. _sec-SpikeEventSeries:

SpikeEventSeries
^^^^^^^^^^^^^^^^

**Extends:** :ref:`ElectricalSeries <sec-ElectricalSeries>`

**Source Specification:** see :numref:`sec-SpikeEventSeries-src`

**Overview:** Stores "snapshots" of spike events (i.e., threshold crossings) in data. This may also be raw data, as reported by ephys hardware. If so, the TimeSeries::description field should describing how events were detected. All SpikeEventSeries should reside in a module (under EventWaveform interface) even if the spikes were reported and stored by hardware. All events span the same recording channels and store snapshots of equal duration. TimeSeries::data array structure: `[num events] [num channels] [num samples] (or [num events] [num samples] for single electrode)`.


``SpikeEventSeries`` extends ``ElectricalSeries`` (see :numref:`sec-ElectricalSeries`) and includes all elements of :ref:`ElectricalSeries <sec-ElectricalSeries>` with the following additions or changes.



.. figure:: ./_format_auto_docs/SpikeEventSeries.*
    :alt: SpikeEventSeries




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-SpikeEventSeries-data:

.. table:: Datasets, Links, and Attributes contained in <SpikeEventSeries>
    :class: longtable

    +----------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | Id                   | Type        | Description                                                                                                                                                                                                                    |
    +======================+=============+================================================================================================================================================================================================================================+
    | <SpikeEventSeries>   | group       | Top level group for <SpikeEventSeries>                                                                                                                                                                                         |
    +----------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .help                | attribute   | Value is 'Snapshots of spike events from data.'                                                                                                                                                                                |
    |                      |             |                                                                                                                                                                                                                                |
    |                      |             | - **Data Type:** text                                                                                                                                                                                                          |
    |                      |             | - **Value:** Snapshots of spike events from data.                                                                                                                                                                              |
    |                      |             |                                                                                                                                                                                                                                |
    +----------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .data                | dataset     | Spike waveforms.                                                                                                                                                                                                               |
    |                      |             |                                                                                                                                                                                                                                |
    |                      |             | - **Data Type:** float32                                                                                                                                                                                                       |
    |                      |             | - **Dimensions:** [['num_events', 'num_samples'], ['num_events', 'num_channels', 'num_samples']]                                                                                                                               |
    |                      |             | - **Shape:** [[None, None], [None, None, None]]                                                                                                                                                                                |
    |                      |             |                                                                                                                                                                                                                                |
    +----------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..unit               | attribute   | The base unit of measure used to store data. This should be in the SI unit.                                                                                                                                                    |
    |                      |             |                                                                                                                                                                                                                                |
    |                      |             | **Comment:**  This is the SI unit (when appropriate) of the stored data, such as Volts. If the actual data is stored in millivolts, the field 'conversion' below describes how to convert the data to the specified SI unit.   |
    |                      |             |                                                                                                                                                                                                                                |
    |                      |             | - **Data Type:** text                                                                                                                                                                                                          |
    |                      |             | - **Reuqired:** False                                                                                                                                                                                                          |
    |                      |             | - **Default Value:** volt                                                                                                                                                                                                      |
    |                      |             |                                                                                                                                                                                                                                |
    +----------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+



