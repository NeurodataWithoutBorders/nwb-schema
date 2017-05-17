.. _sec-ElectricalSeries-src:

ElectricalSeries
^^^^^^^^^^^^^^^^

**Extends:** :ref:`TimeSeries <sec-TimeSeries>`

**Description:** see :numref:`sec-ElectricalSeries`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Value is Stores acquired voltage data from extracellular recordings
      dtype: text
      name: help
      value: Stores acquired voltage data from extracellular recordings
    datasets:
    - attributes:
      - doc: Value is volt
        dtype: text
        name: unit
        value: volt
      dims:
      - - num_times
      - - num_times
        - num_channels
      doc: Recorded voltage data.
      dtype: number
      name: data
      shape:
      - - null
      - - null
        - null
    doc: 'Stores acquired voltage data from extracellular recordings. The data field of
      an ElectricalSeries is an int or float array storing data in Volts. TimeSeries::data
      array structure: :blue:`[num times] [num channels] (or [num_times] for single electrode).`'
    links:
    - doc: link to ElectrodeGroup group that generated this TimeSeries data
      name: electrode_group
      target_type: ElectrodeGroup
    neurodata_type_def: ElectricalSeries
    neurodata_type_inc: TimeSeries


