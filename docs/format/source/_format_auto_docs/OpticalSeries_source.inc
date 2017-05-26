.. _sec-OpticalSeries-src:

OpticalSeries
^^^^^^^^^^^^^

**Extends:** :ref:`ImageSeries <sec-ImageSeries>`

**Description:** see :numref:`sec-OpticalSeries`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Value is 'Time-series image stack for optical recording or stimulus'
      dtype: text
      name: help
      value: Time-series image stack for optical recording or stimulus
    datasets:
    - doc: Description of image relative to some reference frame (e.g., which way is up).
        Must also specify frame of reference.
      dtype: text
      name: orientation
      quantity: '?'
    - doc: Distance from camera/monitor to target/eye.
      dtype: float32
      name: distance
      quantity: '?'
    - dims:
      - - width|height
        - width|height|depth
      doc: Width, height and depto of image, or imaged area (meters).
      dtype: float32
      name: field_of_view
      quantity: '?'
      shape:
      - 2
    doc: Image data that is presented or recorded. A stimulus template movie will be stored
      only as an image. When the image is presented as stimulus, additional data is required,
      such as field of view (eg, how much of the visual field the image covers, or how
      what is the area of the target being imaged). If the OpticalSeries represents acquired
      imaging data, orientation is also important.
    neurodata_type_def: OpticalSeries
    neurodata_type_inc: ImageSeries


