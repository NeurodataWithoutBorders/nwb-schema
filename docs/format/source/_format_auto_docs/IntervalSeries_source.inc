.. _sec-IntervalSeries-src:

IntervalSeries
^^^^^^^^^^^^^^

**Extends:** :ref:`TimeSeries <sec-TimeSeries>`

**Description:** see :numref:`sec-IntervalSeries`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Value is Stores the start and stop times for events
      dtype: text
      name: help
      value: Stores the start and stop times for events
    datasets:
    - attributes:
      - doc: Value is float('NaN')
        dtype: None
        name: resolution
        value: NaN
      - doc: Value is n/a
        dtype: None
        name: unit
        value: n/a
      - doc: Value is float('NaN')
        dtype: None
        name: conversion
        value: NaN
      dims:
      - num_times
      doc: '>0 if interval started, <0 if interval ended.'
      dtype: int8
      name: data
      shape:
      - null
    doc: Stores intervals of data. The timestamps field stores the beginning and end of
      intervals. The data field stores whether the interval just started (>0 value) or
      ended (<0 value). Different interval types can be represented in the same series
      by using multiple key values (eg, 1 for feature A, 2 for feature B, 3 for feature
      C, etc). The field data stores an 8-bit integer. This is largely an alias of a standard
      TimeSeries but that is identifiable as representing time intervals in a machine-readable
      way.
    neurodata_type_def: IntervalSeries
    neurodata_type_inc: TimeSeries


