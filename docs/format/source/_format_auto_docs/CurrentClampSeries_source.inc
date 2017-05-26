.. _sec-CurrentClampSeries-src:

CurrentClampSeries
^^^^^^^^^^^^^^^^^^

**Extends:** :ref:`PatchClampSeries <sec-PatchClampSeries>`

**Description:** see :numref:`sec-CurrentClampSeries`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Value is 'Voltage recorded from cell during current-clamp recording'
      dtype: text
      name: help
      value: Voltage recorded from cell during current-clamp recording
    datasets:
    - doc: 'Unit: Farad'
      dtype: float32
      name: capacitance_compensation
      quantity: '?'
    - doc: 'Unit: Ohm'
      dtype: float32
      name: bridge_balance
      quantity: '?'
    - doc: 'Unit: Amp'
      dtype: float32
      name: bias_current
      quantity: '?'
    doc: Stores voltage data recorded from intracellular current-clamp recordings. A corresponding
      CurrentClampStimulusSeries (stored separately as a stimulus) is used to store the
      current injected.
    neurodata_type_def: CurrentClampSeries
    neurodata_type_inc: PatchClampSeries


