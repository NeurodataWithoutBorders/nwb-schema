.. _sec-CorrectedImageStack-src:

CorrectedImageStack
^^^^^^^^^^^^^^^^^^^

**Extends:** :ref:`NWBContainer <sec-NWBContainer>`

**Description:** see :numref:`sec-CorrectedImageStack`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Value is 'Reuslts from motion correction of an image stack'
      dtype: text
      name: help
      value: Reuslts from motion correction of an image stack
    doc: One of possibly many.  Name should be informative.
    groups:
    - doc: Image stack with frames shifted to the common coordinates.
      name: corrected
      neurodata_type_inc: ImageSeries
    - doc: Stores the x,y delta necessary to align each frame to the common coordinates,
        for example, to align each frame to a reference image.
      name: xy_translation
      neurodata_type_inc: TimeSeries
    links:
    - doc: HDF5 Link to image series that is being registered.
      name: original
      target_type: ImageSeries
    neurodata_type_def: CorrectedImageStack
    neurodata_type_inc: NWBContainer
    quantity: +


