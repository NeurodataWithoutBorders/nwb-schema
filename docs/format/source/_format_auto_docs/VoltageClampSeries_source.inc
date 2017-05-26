.. _sec-VoltageClampSeries-src:

VoltageClampSeries
^^^^^^^^^^^^^^^^^^

**Extends:** :ref:`PatchClampSeries <sec-PatchClampSeries>`

**Description:** see :numref:`sec-VoltageClampSeries`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Value is 'Current recorded from cell during voltage-clamp recording'
      dtype: text
      name: help
      value: Current recorded from cell during voltage-clamp recording
    datasets:
    - attributes:
      - default_value: Farad
        doc: "The base unit of measure used to store data. This should be in the SI unit.\
          \ COMMENT: This is the SI unit (when appropriate) of the stored data, such as\
          \ Volts. If the actual data is stored in millivolts, the field 'conversion'\
          \ below describes how to convert the data to the specified SI unit."
        dtype: text
        name: unit
      doc: 'Unit: Farad'
      dtype: float32
      name: whole_cell_capacitance_comp
      quantity: '?'
    - attributes:
      - default_value: pecent
        doc: "The base unit of measure used to store data. This should be in the SI unit.\
          \ COMMENT: This is the SI unit (when appropriate) of the stored data, such as\
          \ Volts. If the actual data is stored in millivolts, the field 'conversion'\
          \ below describes how to convert the data to the specified SI unit."
        dtype: text
        name: unit
      doc: 'Unit: %'
      dtype: float32
      name: resistance_comp_prediction
      quantity: '?'
    - attributes:
      - default_value: pecent
        doc: "The base unit of measure used to store data. This should be in the SI unit.\
          \ COMMENT: This is the SI unit (when appropriate) of the stored data, such as\
          \ Volts. If the actual data is stored in millivolts, the field 'conversion'\
          \ below describes how to convert the data to the specified SI unit."
        dtype: text
        name: unit
      doc: 'Unit: %'
      dtype: float32
      name: resistance_comp_correction
      quantity: '?'
    - attributes:
      - default_value: Ohm
        doc: "The base unit of measure used to store data. This should be in the SI unit.\
          \ COMMENT: This is the SI unit (when appropriate) of the stored data, such as\
          \ Volts. If the actual data is stored in millivolts, the field 'conversion'\
          \ below describes how to convert the data to the specified SI unit."
        dtype: text
        name: unit
      doc: 'Unit: Ohm'
      dtype: float32
      name: whole_cell_series_resistance_comp
      quantity: '?'
    - attributes:
      - default_value: Hz
        doc: "The base unit of measure used to store data. This should be in the SI unit.\
          \ COMMENT: This is the SI unit (when appropriate) of the stored data, such as\
          \ Volts. If the actual data is stored in millivolts, the field 'conversion'\
          \ below describes how to convert the data to the specified SI unit."
        dtype: text
        name: unit
      doc: 'Unit: Hz'
      dtype: float32
      name: resistance_comp_bandwidth
      quantity: '?'
    - attributes:
      - default_value: Farad
        doc: "The base unit of measure used to store data. This should be in the SI unit.\
          \ COMMENT: This is the SI unit (when appropriate) of the stored data, such as\
          \ Volts. If the actual data is stored in millivolts, the field 'conversion'\
          \ below describes how to convert the data to the specified SI unit."
        dtype: text
        name: unit
      doc: 'Unit: Farad'
      dtype: float32
      name: capacitance_fast
      quantity: '?'
    - attributes:
      - default_value: Farad
        doc: "The base unit of measure used to store data. This should be in the SI unit.\
          \ COMMENT: This is the SI unit (when appropriate) of the stored data, such as\
          \ Volts. If the actual data is stored in millivolts, the field 'conversion'\
          \ below describes how to convert the data to the specified SI unit."
        dtype: text
        name: unit
      doc: 'Unit: Farad'
      dtype: float32
      name: capacitance_slow
      quantity: '?'
    doc: Stores current data recorded from intracellular voltage-clamp recordings. A corresponding
      VoltageClampStimulusSeries (stored separately as a stimulus) is used to store the
      voltage injected.
    neurodata_type_def: VoltageClampSeries
    neurodata_type_inc: PatchClampSeries


