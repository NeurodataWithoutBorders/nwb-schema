.. _sec-RoiResponseSeries-src:

RoiResponseSeries
^^^^^^^^^^^^^^^^^

**Extends:** :ref:`TimeSeries <sec-TimeSeries>`

**Description:** see :numref:`sec-RoiResponseSeries`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Value is 'ROI responses over an imaging plane. Each row in data[] should correspond
        to the signal from one ROI'
      dtype: text
      name: help
      value: ROI responses over an imaging plane. Each row in data[] should correspond
        to the signal from one ROI
    datasets:
    - dims:
      - num_ROIs
      doc: List of ROIs represented, one name for each row of data[].
      dtype: text
      name: roi_names
      shape:
      - null
    - doc: Path to segmentation module.
      dtype: text
      name: segmentation_interface_path
    - dims:
      - num_times
      - num_ROIs
      doc: Signals from ROIs
      dtype: float32
      name: data
      shape:
      - null
      - null
    doc: ROI responses over an imaging plane. Each row in data[] should correspond to
      the signal from one ROI.
    links:
    - doc: HDF5 link to image segmentation module defining ROIs.
      name: segmentation_interface
      target_type: ImageSegmentation
    neurodata_type_def: RoiResponseSeries
    neurodata_type_inc: TimeSeries


