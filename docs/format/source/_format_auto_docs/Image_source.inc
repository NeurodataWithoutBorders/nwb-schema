.. _sec-Image-src:

Image
^^^^^

**Description:** see :numref:`sec-Image`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: 'Format of the image.  COMMENT: eg, jpg, png, mpeg'
      dtype: text
      name: format
    - doc: 'Human description of image. COMMENT: If image is of slice data, include slice
        thickness and orientation, and reference to appropriate entry in /general/slices'
      dtype: text
      name: description
    doc: 'Photograph of experiment or experimental setup (video also OK). COMMENT: Name
      is arbitrary.  Data is stored as a single binary object (HDF5 opaque type).'
    dtype: binary
    neurodata_type_def: Image
    quantity: '*'


