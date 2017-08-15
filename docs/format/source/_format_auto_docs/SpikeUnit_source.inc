.. _sec-SpikeUnit-src:

SpikeUnit
^^^^^^^^^

**Extends:** :ref:`NWBContainer <sec-NWBContainer>`

**Description:** see :numref:`sec-SpikeUnit`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
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


