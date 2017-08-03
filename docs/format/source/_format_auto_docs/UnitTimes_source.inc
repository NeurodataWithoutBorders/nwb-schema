.. _sec-UnitTimes-src:

UnitTimes
^^^^^^^^^

**Extends:** :ref:`Interface <sec-Interface>`

**Description:** see :numref:`sec-UnitTimes`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Value is 'Estimated spike times from a single unit'
      dtype: text
      name: help
      value: Estimated spike times from a single unit
    datasets:
    - dims:
      - num_units
      doc: List of units present.
      dtype: text
      name: unit_list
      shape:
      - null
    doc: Event times of observed units (e.g. cell, synapse, etc.). The UnitTimes group
      contains a group for each unit. The name of the group should match the value in
      the source module, if that is possible/relevant (e.g., name of ROIs from Segmentation
      module).
    groups:
    - datasets:
      - dims:
        - num_events
        doc: Spike time for the units (exact or estimated)
        dtype: float64!
        name: times
        shape:
        - null
      - doc: Name, path or description of where unit times originated. This is necessary
          only if the info here differs from or is more fine-grained than the interface's
          source field
        dtype: text
        name: source
        quantity: '?'
      - doc: Description of the unit (eg, cell type).
        dtype: text
        name: unit_description
      doc: Group storing times for &lt;unit_N&gt;.
      neurodata_type_def: SpikeUnit
      quantity: +
    name: UnitTimes
    neurodata_type_def: UnitTimes
    neurodata_type_inc: Interface


