.. _sec-EyeTracking-src:

EyeTracking
^^^^^^^^^^^

**Extends:** :ref:`NWBContainer <sec-NWBContainer>`

**Description:** see :numref:`sec-EyeTracking`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Value is 'Eye-tracking data, representing direction of gaze'
      dtype: text
      name: help
      value: Eye-tracking data, representing direction of gaze
    default_name: EyeTracking
    doc: Eye-tracking data, representing direction of gaze.
    groups:
    - doc: SpatialSeries object containing data measuring direction of gaze
      neurodata_type_inc: SpatialSeries
      quantity: '*'
    neurodata_type_def: EyeTracking
    neurodata_type_inc: NWBContainer


