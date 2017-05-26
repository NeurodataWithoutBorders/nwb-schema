.. _sec-SpikeEventSeries-src:

SpikeEventSeries
^^^^^^^^^^^^^^^^

**Extends:** :ref:`ElectricalSeries <sec-ElectricalSeries>`

**Description:** see :numref:`sec-SpikeEventSeries`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Value is 'Snapshots of spike events from data.'
      dtype: text
      name: help
      value: Snapshots of spike events from data.
    datasets:
    - attributes:
      - default_value: volt
        doc: "The base unit of measure used to store data. This should be in the SI unit.\
          \ COMMENT: This is the SI unit (when appropriate) of the stored data, such as\
          \ Volts. If the actual data is stored in millivolts, the field 'conversion'\
          \ below describes how to convert the data to the specified SI unit."
        dtype: text
        name: unit
      dims:
      - - num_events
        - num_samples
      - - num_events
        - num_channels
        - num_samples
      doc: Spike waveforms.
      dtype: float32
      name: data
      shape:
      - - null
        - null
      - - null
        - null
        - null
    doc: 'Stores "snapshots" of spike events (i.e., threshold crossings) in data. This
      may also be raw data, as reported by ephys hardware. If so, the TimeSeries::description
      field should describing how events were detected. All SpikeEventSeries should reside
      in a module (under EventWaveform interface) even if the spikes were reported and
      stored by hardware. All events span the same recording channels and store snapshots
      of equal duration. TimeSeries::data array structure: :blue:`[num events] [num channels]
      [num samples] (or [num events] [num samples] for single electrode)`.'
    neurodata_type_def: SpikeEventSeries
    neurodata_type_inc: ElectricalSeries


