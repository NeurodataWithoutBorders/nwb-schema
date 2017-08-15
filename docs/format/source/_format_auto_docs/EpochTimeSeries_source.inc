.. _sec-EpochTimeSeries-src:

EpochTimeSeries
^^^^^^^^^^^^^^^

**Extends:** :ref:`NWBContainer <sec-NWBContainer>`

**Description:** see :numref:`sec-EpochTimeSeries`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Value is 'Data on how an epoch applies to a time series'
      dtype: text
      name: help
      value: Data on how an epoch applies to a time series
    datasets:
    - doc: Number of data samples available in this time series, during this epoch.
      dtype: int32
      name: count
    - doc: "Epoch's start index in TimeSeries data[] field. COMMENT: This can be used\
        \ to calculate location in TimeSeries timestamp[] field"
      dtype: int32
      name: idx_start
    doc: 'One of possibly many input or output streams recorded during epoch. COMMENT:
      Name is arbitrary and does not have to match the TimeSeries that it refers to.'
    links:
    - doc: Link to TimeSeries.  An HDF5 soft-link should be used.
      name: timeseries
      target_type: TimeSeries
    neurodata_type_def: EpochTimeSeries
    neurodata_type_inc: NWBContainer
    quantity: '*'


