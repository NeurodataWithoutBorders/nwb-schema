.. _sec-ImageSeries-src:

ImageSeries
^^^^^^^^^^^

**Extends:** :ref:`TimeSeries <sec-TimeSeries>`

**Description:** see :numref:`sec-ImageSeries`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Value is Storage object for time-series 2-D image data
      dtype: text
      name: help
      value: Storage object for time-series 2-D image data
    datasets:
    - attributes:
      - dims:
        - num_files
        doc: Each entry is the frame number (within the full ImageSeries) of the first
          frame in the corresponding external_file entry. This serves as an index to what
          frames each file contains, allowing random access.Zero-based indexing is used.  (The
          first element will always be zero).
        dtype: int
        name: starting_frame
        shape:
        - null
      dims:
      - num_files
      doc: 'Path or URL to one or more external file(s). Field only present if format=external.
        NOTE: this is only relevant if the image is stored in the file system as one or
        more image file(s). This field should NOT be used if the image is stored in another
        HDF5 file and that file is HDF5 linked to this file.'
      dtype: text
      name: external_file
      quantity: '?'
      shape:
      - null
    - doc: Number of bit per image pixel.
      dtype: int32
      name: bits_per_pixel
      quantity: '?'
    - doc: Format of image. If this is 'external' then the field external_file contains
        the path or URL information to that file. For tiff, png, jpg, etc, the binary
        representation of the image is stored in data. If the format is raw then the fields
        bit_per_pixel and dimension are used. For raw images, only a single channel is
        stored (eg, red).
      dtype: text
      name: format
      quantity: '?'
    - dims:
      - rank
      doc: Number of pixels on x, y, (and z) axes.
      dtype: int32
      name: dimension
      quantity: '?'
      shape:
      - null
    - dims:
      - - x
        - y
      - - frame
        - y
        - x
      - - frame
        - z
        - y
        - x
      doc: Either binary data containing image or empty.
      dtype: number
      name: data
      shape:
      - - null
        - null
      - - null
        - null
        - null
      - - null
        - null
        - null
        - null
    doc: 'General image data that is common between acquisition and stimulus time series.
      Sometimes the image data is stored in the HDF5 file in a raw format while other
      times it will be stored as an external image file in the host file system. The data
      field will either be binary data or empty. TimeSeries::data array structure: [frame]
      [y][x] or [frame][z][y][x].'
    neurodata_type_def: ImageSeries
    neurodata_type_inc: TimeSeries


