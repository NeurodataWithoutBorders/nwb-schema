.. _sec-SpatialSeries-src:

SpatialSeries
^^^^^^^^^^^^^

**Extends:** :ref:`TimeSeries <sec-TimeSeries>`

**Description:** see :numref:`sec-SpatialSeries`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Value is 'Stores points in space over time. The data[] array structure is [num
        samples][num spatial dimensions]'
      dtype: text
      name: help
      value: Stores points in space over time. The data[] array structure is [num samples][num
        spatial dimensions]
    datasets:
    - doc: Description defining what exactly 'straight-ahead' means.
      dtype: text
      name: reference_frame
      quantity: '?'
    - attributes:
      - default_value: meter
        doc: "The base unit of measure used to store data. This should be in the SI unit.\
          \ COMMENT: This is the SI unit (when appropriate) of the stored data, such as\
          \ Volts. If the actual data is stored in millivolts, the field 'conversion'\
          \ below describes how to convert the data to the specified SI unit."
        dtype: text
        name: unit
      dims:
      - num_times
      - num_features
      doc: 2-D array storing position or direction relative to some reference frame.
      dtype: number
      name: data
      shape:
      - null
      - null
    doc: 'Direction, e.g., of gaze or travel, or position. The TimeSeries::data field
      is a 2D array storing position or direction relative to some reference frame. Array
      structure: [num measurements] [num dimensions]. Each SpatialSeries has a text dataset
      reference_frame that indicates the zero-position, or the zero-axes for direction.
      For example, if representing gaze direction, "straight-ahead" might be a specific
      pixel on the monitor, or some other point in space. For position data, the 0,0 point
      might be the top-left corner of an enclosure, as viewed from the tracking camera.
      The unit of data will indicate how to interpret SpatialSeries values.'
    neurodata_type_def: SpatialSeries
    neurodata_type_inc: TimeSeries


