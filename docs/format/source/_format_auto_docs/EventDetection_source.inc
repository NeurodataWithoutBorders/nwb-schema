.. _sec-EventDetection-src:

EventDetection
^^^^^^^^^^^^^^

**Description:** see :numref:`sec-EventDetection`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    datasets:
    - doc: Path to linked ElectricalSeries.
      dtype: text
      name: source_electricalseries_path
    - doc: Description of how events were detected, such as voltage threshold, or dV/dT
        threshold, as well as relevant values.
      dtype: text
      name: detection_method
    - dims:
      - num_events
      doc: Indices (zero-based) into source ElectricalSeries::data array corresponding
        to time of event. Module description should define what is meant by time of event
        (e.g., .25msec before action potential peak, zero-crossing time, etc). The index
        points to each event from the raw data
      dtype: int32
      name: source_idx
      shape:
      - null
    - attributes:
      - doc: Value is Seconds
        dtype: text
        name: unit
        value: Seconds
      dims:
      - num_events
      doc: Timestamps of events, in Seconds
      dtype: float64!
      name: times
      shape:
      - null
    doc: Detected spike events from voltage trace(s).
    links:
    - doc: HDF5 link to ElectricalSeries that this data was calculated from. Metadata
        about electrodes and their position can be read from that ElectricalSeries so
        it's not necessary to mandate that information be stored here
      name: source_electricalseries
      target_type: ElectricalSeries
    name: EventDetection
    neurodata_type_def: EventDetection


