.. _sec-UnitTimes-src:

UnitTimes
^^^^^^^^^

**Extends:** :ref:`NWBContainer <sec-NWBContainer>`

**Description:** see :numref:`sec-UnitTimes`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Value is 'Estimated spike times from a single unit'
      dtype: text
      name: help
      value: Estimated spike times from a single unit
    doc: Event times of observed units (e.g. cell, synapse, etc.). The UnitTimes group
      contains a group for each unit. The name of the group should match the value in
      the source module, if that is possible/relevant (e.g., name of ROIs from Segmentation
      module).
    groups:
    - attributes:
      - doc: Store times for a particulare UnitTime
        dtype: text
        name: help
        value: Times for a particular UnitTime object
      datasets:
      - dims:
        - num_events
        doc: Spike time for the units (exact or estimated)
        dtype: float64!
        name: times
        shape:
        - null
      - doc: Description of the unit (eg, cell type).
        dtype: text
        name: unit_description
      doc: Group storing times for &lt;unit_N&gt;.
      neurodata_type_def: SpikeUnit
      neurodata_type_inc: NWBContainer
      quantity: +
    name: UnitTimes
    neurodata_type_def: UnitTimes
    neurodata_type_inc: NWBContainer


