.. _sec-BehavioralTimeSeries-src:

BehavioralTimeSeries
^^^^^^^^^^^^^^^^^^^^

**Extends:** :ref:`NWBContainer <sec-NWBContainer>`

**Description:** see :numref:`sec-BehavioralTimeSeries`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Value is 'General container for storing continuously sampled behavioral data.'
      dtype: text
      name: help
      value: General container for storing continuously sampled behavioral data.
    doc: TimeSeries for storing Behavoioral time series data.See description of <a href="#BehavioralEpochs">BehavioralEpochs</a>
      for more details.
    groups:
    - doc: TimeSeries object containing continuous behavioral data
      neurodata_type_inc: TimeSeries
      quantity: '*'
    name: BehavioralTimeSeries
    neurodata_type_def: BehavioralTimeSeries
    neurodata_type_inc: NWBContainer


