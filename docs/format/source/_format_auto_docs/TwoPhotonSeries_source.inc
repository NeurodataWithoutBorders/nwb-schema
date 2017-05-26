.. _sec-TwoPhotonSeries-src:

TwoPhotonSeries
^^^^^^^^^^^^^^^

**Extends:** :ref:`ImageSeries <sec-ImageSeries>`

**Description:** see :numref:`sec-TwoPhotonSeries`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Value is 'Image stack recorded from 2-photon microscope'
      dtype: text
      name: help
      value: Image stack recorded from 2-photon microscope
    datasets:
    - doc: Photomultiplier gain
      dtype: float32
      name: pmt_gain
      quantity: '?'
    - dims:
      - width|height|depth
      doc: Width, height and depth of image, or imaged area (meters).
      dtype: float32
      name: field_of_view
      quantity: '?'
      shape:
      - 3
    - doc: Lines imaged per second. This is also stored in /general/optophysiology but
        is kept here as it is useful information for analysis, and so good to be stored
        w/ the actual data.
      dtype: float32
      name: scan_line_rate
      quantity: '?'
    doc: A special case of optical imaging.
    links:
    - doc: link to ImagingPlane group from which this TimeSeries data was generated
      name: imaging_plane
      target_type: ImagingPlane
    neurodata_type_def: TwoPhotonSeries
    neurodata_type_inc: ImageSeries


