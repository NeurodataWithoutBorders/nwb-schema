.. _sec-PupilTracking-src:

PupilTracking
^^^^^^^^^^^^^

**Extends:** :ref:`NWBContainer <sec-NWBContainer>`

**Description:** see :numref:`sec-PupilTracking`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Value is 'Eye-tracking data, representing pupil size'
      dtype: text
      name: help
      value: Eye-tracking data, representing pupil size
    doc: Eye-tracking data, representing pupil size.
    groups:
    - doc: TimeSeries object containing time series data on pupil size
      neurodata_type_inc: TimeSeries
      quantity: +
    name: PupilTracking
    neurodata_type_def: PupilTracking
    neurodata_type_inc: NWBContainer


