.. _sec-BehavioralEpochs-src:

BehavioralEpochs
^^^^^^^^^^^^^^^^

**Extends:** :ref:`Interface <sec-Interface>`

**Description:** see :numref:`sec-BehavioralEpochs`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Value is General container for storing behavorial epochs
      dtype: text
      name: help
      value: General container for storing behavorial epochs
    doc: TimeSeries for storing behavoioral epochs.  The objective of this and the other
      two Behavioral interfaces (e.g. BehavioralEvents and BehavioralTimeSeries) is to
      provide generic hooks for software tools/scripts. This allows a tool/script to take
      the output one specific interface (e.g., UnitTimes) and plot that data relative
      to another data modality (e.g., behavioral events) without having to define all
      possible modalities in advance. Declaring one of these interfaces means that one
      or more TimeSeries of the specified type is published. These TimeSeries should reside
      in a group having the same name as the interface. For example, if a BehavioralTimeSeries
      interface is declared, the module will have one or more TimeSeries defined in the
      module sub-group "BehavioralTimeSeries". BehavioralEpochs should use IntervalSeries.
      BehavioralEvents is used for irregular events. BehavioralTimeSeries is for continuous
      data.
    groups:
    - doc: IntervalSeries object containing start and stop times of epochs
      neurodata_type_inc: IntervalSeries
    name: BehavioralEpochs
    neurodata_type_def: BehavioralEpochs
    neurodata_type_inc: Interface


