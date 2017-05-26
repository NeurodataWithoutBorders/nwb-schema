.. _sec-AnnotationSeries-src:

AnnotationSeries
^^^^^^^^^^^^^^^^

**Extends:** :ref:`TimeSeries <sec-TimeSeries>`

**Description:** see :numref:`sec-AnnotationSeries`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Value is 'Time-stamped annotations about an experiment'
      dtype: text
      name: help
      value: Time-stamped annotations about an experiment
    datasets:
    - attributes:
      - doc: Value is 'float('NaN')'
        dtype: None
        name: conversion
        value: NaN
      - doc: Value is 'n/a'
        dtype: None
        name: unit
        value: n/a
      - doc: Value is 'float('NaN')'
        dtype: None
        name: resolution
        value: NaN
      dims:
      - num_times
      doc: Annotations made during an experiment.
      dtype: text
      name: data
      shape:
      - null
    doc: Stores, eg, user annotations made during an experiment. The TimeSeries::data[]
      field stores a text array, and timestamps are stored for each annotation (ie, interval=1).
      This is largely an alias to a standard TimeSeries storing a text array but that
      is identifiable as storing annotations in a machine-readable way.
    neurodata_type_def: AnnotationSeries
    neurodata_type_inc: TimeSeries


