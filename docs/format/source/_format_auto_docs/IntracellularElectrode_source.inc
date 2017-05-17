.. _sec-IntracellularElectrode-src:

IntracellularElectrode
^^^^^^^^^^^^^^^^^^^^^^

**Description:** see :numref:`sec-IntracellularElectrode`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    datasets:
    - doc: Initial access resistance
      dtype: text
      name: initial_access_resistance
      quantity: '?'
    - doc: 'Recording description, description of electrode (e.g.,  whole-cell, sharp,
        etc)COMMENT: Free-form text (can be from Methods)'
      dtype: text
      name: description
    - doc: Area, layer, comments on estimation, stereotaxis coordinates (if in vivo, etc)
      dtype: text
      name: location
      quantity: '?'
    - doc: Electrode specific filtering.
      dtype: text
      name: filtering
      quantity: '?'
    - doc: Information about slice used for recording
      dtype: text
      name: slice
      quantity: '?'
    - doc: 'Electrode resistance COMMENT: unit: Ohm'
      dtype: text
      name: resistance
      quantity: '?'
    - doc: Name(s) of devices in general/devices
      dtype: text
      name: device
      quantity: '?'
    - doc: Information about seal used for recording
      dtype: text
      name: seal
      quantity: '?'
    doc: 'One of possibly many. COMMENT: Name should be informative.'
    neurodata_type_def: IntracellularElectrode


