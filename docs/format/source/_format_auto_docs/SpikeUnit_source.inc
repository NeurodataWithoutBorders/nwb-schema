.. _sec-SpikeUnit-src:

SpikeUnit
^^^^^^^^^

**Description:** see :numref:`sec-SpikeUnit`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    datasets:
    - doc: Description of the unit (eg, cell type).
      dtype: text
      name: unit_description
    - doc: Name, path or description of where unit times originated. This is necessary
        only if the info here differs from or is more fine-grained than the interface's
        source field
      dtype: text
      name: source
      quantity: '?'
    - dims:
      - num_events
      doc: Spike time for the units (exact or estimated)
      dtype: float64!
      name: times
      shape:
      - null
    doc: Group storing times for &lt;unit_N&gt;.
    neurodata_type_def: SpikeUnit
    quantity: +


