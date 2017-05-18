.. _sec-VoltageClampSeries-src:

VoltageClampSeries
^^^^^^^^^^^^^^^^^^

**Extends:** :ref:`PatchClampSeries <sec-PatchClampSeries>`

**Description:** see :numref:`sec-VoltageClampSeries`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Value is Current recorded from cell during voltage-clamp recording
      dtype: text
      name: help
      value: Current recorded from cell during voltage-clamp recording
    datasets:
    - attributes:
      - doc: Value is Farad
        dtype: text
        name: unit
        value: Farad
      doc: 'Unit: Farad'
      dtype: float32
      name: capacitance_slow
      quantity: '?'
    - attributes:
      - doc: Value is Farad
        dtype: text
        name: unit
        value: Farad
      doc: 'Unit: Farad'
      dtype: float32
      name: whole_cell_capacitance_comp
      quantity: '?'
    - attributes:
      - doc: Value is Farad
        dtype: text
        name: unit
        value: Farad
      doc: 'Unit: Farad'
      dtype: float32
      name: capacitance_fast
      quantity: '?'
    - attributes:
      - doc: Value is pecent
        dtype: text
        name: unit
        value: pecent
      doc: 'Unit: %'
      dtype: float32
      name: resistance_comp_prediction
      quantity: '?'
    - attributes:
      - doc: Value is Hz
        dtype: text
        name: unit
        value: Hz
      doc: 'Unit: Hz'
      dtype: float32
      name: resistance_comp_bandwidth
      quantity: '?'
    - attributes:
      - doc: Value is pecent
        dtype: text
        name: unit
        value: pecent
      doc: 'Unit: %'
      dtype: float32
      name: resistance_comp_correction
      quantity: '?'
    - attributes:
      - doc: Value is Ohm
        dtype: text
        name: unit
        value: Ohm
      doc: 'Unit: Ohm'
      dtype: float32
      name: whole_cell_series_resistance_comp
      quantity: '?'
    doc: Stores current data recorded from intracellular voltage-clamp recordings. A corresponding
      VoltageClampStimulusSeries (stored separately as a stimulus) is used to store the
      voltage injected.
    neurodata_type_def: VoltageClampSeries
    neurodata_type_inc: PatchClampSeries


