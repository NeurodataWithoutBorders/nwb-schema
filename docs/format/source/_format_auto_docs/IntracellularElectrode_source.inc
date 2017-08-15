.. _sec-IntracellularElectrode-src:

IntracellularElectrode
^^^^^^^^^^^^^^^^^^^^^^

**Extends:** :ref:`NWBContainer <sec-NWBContainer>`

**Description:** see :numref:`sec-IntracellularElectrode`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Value is 'Metadata about an intracellular electrode'
      dtype: text
      name: help
      value: Metadata about an intracellular electrode
    datasets:
    - doc: 'Recording description, description of electrode (e.g.,  whole-cell, sharp,
        etc)COMMENT: Free-form text (can be from Methods)'
      dtype: text
      name: description
    - doc: Name(s) of devices in general/devices
      dtype: text
      name: device
      quantity: '?'
    - doc: Electrode specific filtering.
      dtype: text
      name: filtering
      quantity: '?'
    - doc: Initial access resistance
      dtype: text
      name: initial_access_resistance
      quantity: '?'
    - doc: Area, layer, comments on estimation, stereotaxis coordinates (if in vivo, etc)
      dtype: text
      name: location
      quantity: '?'
    - doc: 'Electrode resistance COMMENT: unit: Ohm'
      dtype: text
      name: resistance
      quantity: '?'
    - doc: Information about seal used for recording
      dtype: text
      name: seal
      quantity: '?'
    - doc: Information about slice used for recording
      dtype: text
      name: slice
      quantity: '?'
    doc: 'One of possibly many. COMMENT: Name should be informative.'
    neurodata_type_def: IntracellularElectrode
    neurodata_type_inc: NWBContainer


