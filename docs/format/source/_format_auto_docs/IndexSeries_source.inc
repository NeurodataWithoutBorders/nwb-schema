.. _sec-IndexSeries-src:

IndexSeries
^^^^^^^^^^^

**Extends:** :ref:`TimeSeries <sec-TimeSeries>`

**Description:** see :numref:`sec-IndexSeries`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Value is 'A sequence that is generated from an existing image stack. Frames
        can be presented in an arbitrary order. The data[] field stores frame number in
        reference stack'
      dtype: text
      name: help
      value: A sequence that is generated from an existing image stack. Frames can be
        presented in an arbitrary order. The data[] field stores frame number in reference
        stack
    datasets:
    - dims:
      - num_times
      doc: Index of the frame in the referenced ImageSeries.
      dtype: int
      name: data
      shape:
      - null
    - doc: Path to linked TimeSeries
      dtype: text
      name: indexed_timeseries_path
    doc: Stores indices to image frames stored in an ImageSeries. The purpose of the ImageIndexSeries
      is to allow a static image stack to be stored somewhere, and the images in the stack
      to be referenced out-of-order. This can be for the display of individual images,
      or of movie segments (as a movie is simply a series of images). The data field stores
      the index of the frame in the referenced ImageSeries, and the timestamps array indicates
      when that image was displayed.
    links:
    - doc: HDF5 link to TimeSeries containing images that are indexed.
      name: indexed_timeseries
      target_type: ImageSeries
    neurodata_type_def: IndexSeries
    neurodata_type_inc: TimeSeries


