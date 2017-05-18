.. _sec-PlaneSegmentation-src:

PlaneSegmentation
^^^^^^^^^^^^^^^^^

**Description:** see :numref:`sec-PlaneSegmentation`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    datasets:
    - doc: Description of image plane, recording wavelength, depth, etc
      dtype: text
      name: description
      quantity: '?'
    - dims:
      - num_rois
      doc: List of ROIs in this imaging plane
      dtype: text
      name: roi_list
      shape:
      - null
    doc: Group name is human-readable description of imaging plane
    groups:
    - doc: Stores image stacks segmentation mask apply to.
      groups:
      - doc: One or more image stacks that the masks apply to (can be one-element stack)
        neurodata_type_inc: ImageSeries
      name: reference_images
    - datasets:
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
      - dims:
        - num_x
        - num_y
        doc: ROI mask, represented in 2D ([y][x]) intensity image
        dtype: float32
        name: img_mask
        shape:
        - null
        - null
      doc: Name of ROI
      neurodata_type_def: ROI
      quantity: '*'
    links:
    - doc: link to ImagingPlane group from which this TimeSeries data was generated
      name: imaging_plane
      target_type: ImagingPlane
    neurodata_type_def: PlaneSegmentation
    quantity: '*'


