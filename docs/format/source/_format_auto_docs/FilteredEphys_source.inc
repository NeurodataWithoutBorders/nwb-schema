.. _sec-FilteredEphys-src:

FilteredEphys
^^^^^^^^^^^^^

**Extends:** :ref:`Interface <sec-Interface>`

**Description:** see :numref:`sec-FilteredEphys`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Value is Ephys data from one or more channels that is subjected to filtering,
        such as for gamma or theta oscillations (LFP has its own interface). Filter properties
        should be noted in the ElectricalSeries
      dtype: text
      name: help
      value: Ephys data from one or more channels that is subjected to filtering, such
        as for gamma or theta oscillations (LFP has its own interface). Filter properties
        should be noted in the ElectricalSeries
    doc: Ephys data from one or more channels that has been subjected to filtering. Examples
      of filtered data include Theta and Gamma (LFP has its own interface). FilteredEphys
      modules publish an ElectricalSeries for each filtered channel or set of channels.
      The name of each ElectricalSeries is arbitrary but should be informative. The source
      of the filtered data, whether this is from analysis of another time series or as
      acquired by hardware, should be noted in each's TimeSeries::description field. There
      is no assumed 1::1 correspondence between filtered ephys signals and electrodes,
      as a single signal can apply to many nearby electrodes, and one electrode may have
      different filtered (e.g., theta and/or gamma) signals represented.
    groups:
    - doc: ElectricalSeries object containing filtered electrophysiology data
      neurodata_type_inc: ElectricalSeries
    name: FilteredEphys
    neurodata_type_def: FilteredEphys
    neurodata_type_inc: Interface


