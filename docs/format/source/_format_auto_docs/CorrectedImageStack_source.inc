.. _sec-CorrectedImageStack-src:

CorrectedImageStack
^^^^^^^^^^^^^^^^^^^

**Description:** see :numref:`sec-CorrectedImageStack`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    datasets:
    - doc: Path to linked original timeseries
      dtype: text
      name: original_path
    doc: One of possibly many.  Name should be informative.
    groups:
    - doc: Stores the x,y delta necessary to align each frame to the common coordinates,
        for example, to align each frame to a reference image.
      neurodata_type_inc: TimeSeries
    - doc: Image stack with frames shifted to the common coordinates.
      neurodata_type_inc: ImageSeries
    links:
    - doc: HDF5 Link to image series that is being registered.
      name: original
      target_type: ImageSeries
    neurodata_type_def: CorrectedImageStack
    quantity: +


