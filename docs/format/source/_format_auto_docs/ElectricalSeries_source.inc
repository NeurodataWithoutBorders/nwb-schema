.. _sec-ElectricalSeries-src:

ElectricalSeries
^^^^^^^^^^^^^^^^

**Extends:** :ref:`TimeSeries <sec-TimeSeries>`

**Description:** see :numref:`sec-ElectricalSeries`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Value is 'Stores acquired voltage data from extracellular recordings'
      dtype: text
      name: help
      value: Stores acquired voltage data from extracellular recordings
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


