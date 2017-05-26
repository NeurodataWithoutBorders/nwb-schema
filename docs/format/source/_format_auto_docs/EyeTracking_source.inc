.. _sec-EyeTracking-src:

EyeTracking
^^^^^^^^^^^

**Extends:** :ref:`Interface <sec-Interface>`

**Description:** see :numref:`sec-EyeTracking`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Value is 'Eye-tracking data, representing direction of gaze'
      dtype: text
      name: help
      value: Eye-tracking data, representing direction of gaze
    doc: Eye-tracking data, representing direction of gaze.
    groups:
    - doc: SpatialSeries object containing data measuring direction of gaze
      neurodata_type_inc: SpatialSeries
      quantity: '*'
    name: EyeTracking
    neurodata_type_def: EyeTracking
    neurodata_type_inc: Interface


