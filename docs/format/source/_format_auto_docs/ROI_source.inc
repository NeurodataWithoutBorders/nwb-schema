.. _sec-ROI-src:

ROI
^^^

**Description:** see :numref:`sec-ROI`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    datasets:
    - dims:
      - num_x
      - num_y
      doc: ROI mask, represented in 2D ([y][x]) intensity image
      dtype: float32
      name: img_mask
      shape:
      - null
      - null
    - dims:
      - num_pixels
      - '2'
      doc: List of pixels (x,y) that compose the mask
      dtype: uint16
      name: pix_mask
      shape:
      - null
      - null
    - dims:
      - num_pixels
      doc: Weight of each pixel listed in pix_mask
      dtype: float32
      name: pix_mask_weight
      shape:
      - null
    - doc: Description of this ROI.
      dtype: text
      name: roi_description
    doc: Name of ROI
    neurodata_type_def: ROI
    quantity: '*'


