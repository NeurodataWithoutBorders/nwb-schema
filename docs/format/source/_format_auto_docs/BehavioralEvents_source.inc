.. _sec-BehavioralEvents-src:

BehavioralEvents
^^^^^^^^^^^^^^^^

**Extends:** :ref:`NWBContainer <sec-NWBContainer>`

**Description:** see :numref:`sec-BehavioralEvents`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Value is 'Position data, whether along the x, xy or xyz axis'
      dtype: text
      name: help
      value: Position data, whether along the x, xy or xyz axis
    doc: TimeSeries for storing behavioral events. See description of <a href="#BehavioralEpochs">BehavioralEpochs</a>
      for more details.
    groups:
    - doc: TimeSeries object containing irregular behavioral events
      neurodata_type_inc: TimeSeries
      quantity: '*'
    name: BehavioralEvents
    neurodata_type_def: BehavioralEvents
    neurodata_type_inc: NWBContainer


