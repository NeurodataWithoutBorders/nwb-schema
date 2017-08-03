.. _sec-ImageSegmentation-src:

ImageSegmentation
^^^^^^^^^^^^^^^^^

**Extends:** :ref:`Interface <sec-Interface>`

**Description:** see :numref:`sec-ImageSegmentation`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Value is 'Stores groups of pixels that define regions of interest from one
        or more imaging planes'
      dtype: text
      name: help
      value: Stores groups of pixels that define regions of interest from one or more
        imaging planes
    doc: Stores pixels in an image that represent different regions of interest (ROIs)
      or masks. All segmentation for a given imaging plane is stored together, with storage
      for multiple imaging planes (masks) supported. Each ROI is stored in its own subgroup,
      with the ROI group containing both a 2D mask and a list of pixels that make up this
      mask. Segments can also be used for masking neuropil. If segmentation is allowed
      to change with time, a new imaging plane (or module) is required and ROI names should
      remain consistent between them.
    groups:
    - datasets:
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
      - datasets:
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
      - doc: Stores image stacks segmentation mask apply to.
        groups:
        - doc: One or more image stacks that the masks apply to (can be one-element stack)
          neurodata_type_inc: ImageSeries
        name: reference_images
      links:
      - doc: link to ImagingPlane group from which this TimeSeries data was generated
        name: imaging_plane
        target_type: ImagingPlane
      neurodata_type_def: PlaneSegmentation
      quantity: '*'
    name: ImageSegmentation
    neurodata_type_def: ImageSegmentation
    neurodata_type_inc: Interface


