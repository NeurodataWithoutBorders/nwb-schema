.. _sec-OpticalChannel-src:

OpticalChannel
^^^^^^^^^^^^^^

**Description:** see :numref:`sec-OpticalChannel`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

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


