.. _sec-ElectrodeGroup-src:

ElectrodeGroup
^^^^^^^^^^^^^^

**Extends:** :ref:`NWBContainer <sec-NWBContainer>`

**Description:** see :numref:`sec-ElectrodeGroup`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Value is 'A physical grouping of channels'
      dtype: str
      name: help
      value: A physical grouping of channels
    datasets:
    - dims:
      - num_channels
      doc: array with description for each channel
      dtype: text
      name: channel_description
      shape:
      - null
    - dims:
      - num_channels
      doc: array with location description for each channel e.g. "CA1"
      dtype: text
      name: channel_location
      shape:
      - null
    - dims:
      - num_channels
      doc: array with description of filtering applied to each channel
      dtype: text
      name: channel_filtering
      shape:
      - null
    - dims:
      - num_channels
      - dimensions
      doc: xyz-coordinates for each channel. use NaN for unknown dimensions
      dtype: text
      name: channel_coordinates
      shape:
      - null
      - 3
    - dims:
      - num_channels
      doc: float array with impedance used on each channel. Can be 2D matrix to store
        a range
      dtype: text
      name: channel_impedance
      shape:
      - null
    - doc: description of this electrode group
      dtype: text
      name: description
    - doc: description of location of this electrode group
      dtype: text
      name: location
    doc: One of possibly many groups, one for each electrode group.
    links:
    - doc: the device that was used to record from this electrode group
      name: device
      quantity: '?'
      target_type: Device
    neurodata_type_def: ElectrodeGroup
    neurodata_type_inc: NWBContainer


