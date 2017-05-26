.. _sec-PatchClampSeries-src:

PatchClampSeries
^^^^^^^^^^^^^^^^

**Extends:** :ref:`TimeSeries <sec-TimeSeries>`

**Description:** see :numref:`sec-PatchClampSeries`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Value is 'Superclass definition for patch-clamp data'
      dtype: text
      name: help
      value: Superclass definition for patch-clamp data
    datasets:
    - doc: 'Units: Volt/Amp (v-clamp) or Volt/Volt (c-clamp)'
      dtype: float
      name: gain
      quantity: '?'
    - dims:
      - num_times
      doc: Recorded voltage or current.
      dtype: number
      name: data
      shape:
      - null
    doc: Stores stimulus or response current or voltage. Superclass definition for patch-clamp
      data (this class should not be instantiated directly).
    links:
    - doc: link to IntracellularElectrode group that describes th electrode that was used
        to apply or record this data
      name: electrode
      target_type: IntracellularElectrode
    neurodata_type_def: PatchClampSeries
    neurodata_type_inc: TimeSeries


