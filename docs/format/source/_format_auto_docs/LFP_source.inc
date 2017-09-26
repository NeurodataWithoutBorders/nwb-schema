.. _sec-LFP-src:

LFP
^^^

**Extends:** :ref:`NWBContainer <sec-NWBContainer>`

**Description:** see :numref:`sec-LFP`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Value is 'LFP data from one or more channels. Filter properties should be noted
        in the ElectricalSeries'
      dtype: text
      name: help
      value: LFP data from one or more channels. Filter properties should be noted in
        the ElectricalSeries
    default_name: LFP
    doc: LFP data from one or more channels. The electrode map in each published ElectricalSeries
      will identify which channels are providing LFP data. Filter properties should be
      noted in the ElectricalSeries description or comments field.
    groups:
    - doc: ElectricalSeries object containing LFP data for one or channels
      neurodata_type_inc: ElectricalSeries
      quantity: +
    neurodata_type_def: LFP
    neurodata_type_inc: NWBContainer


