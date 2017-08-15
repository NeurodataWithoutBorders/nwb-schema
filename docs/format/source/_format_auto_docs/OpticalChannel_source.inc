.. _sec-OpticalChannel-src:

OpticalChannel
^^^^^^^^^^^^^^

**Extends:** :ref:`NWBContainer <sec-NWBContainer>`

**Description:** see :numref:`sec-OpticalChannel`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Value is 'Metadata about an optical channel used to record from an imaging
        plane'
      dtype: text
      name: help
      value: Metadata about an optical channel used to record from an imaging plane
    datasets:
    - doc: Any notes or comments about the channel
      dtype: text
      name: description
    - doc: Emission lambda for channel
      dtype: text
      name: emission_lambda
    doc: 'One of possibly many groups storing channel-specific data COMMENT: Name is arbitrary
      but should be meaningful'
    neurodata_type_def: OpticalChannel
    neurodata_type_inc: NWBContainer


