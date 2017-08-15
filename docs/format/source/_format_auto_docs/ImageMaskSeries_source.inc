.. _sec-ImageMaskSeries-src:

ImageMaskSeries
^^^^^^^^^^^^^^^

**Extends:** :ref:`ImageSeries <sec-ImageSeries>`

**Description:** see :numref:`sec-ImageMaskSeries`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Value is 'An alpha mask that is applied to a presented visual stimulus'
      dtype: text
      name: help
      value: An alpha mask that is applied to a presented visual stimulus
    doc: An alpha mask that is applied to a presented visual stimulus. The data[] array
      contains an array of mask values that are applied to the displayed image. Mask values
      are stored as RGBA. Mask can vary with time. The timestamps array indicates the
      starting time of a mask, and that mask pattern continues until it's explicitly changed.
    links:
    - doc: Link to ImageSeries that mask is applied to.
      name: masked_imageseries
      target_type: ImageSeries
    neurodata_type_def: ImageMaskSeries
    neurodata_type_inc: ImageSeries


