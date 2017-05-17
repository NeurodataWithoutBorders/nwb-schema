.. _sec-BehavioralEpochs:

BehavioralEpochs
^^^^^^^^^^^^^^^^

**Extends:** :ref:`Interface <sec-Interface>`

**Source Specification:** see :numref:`sec-BehavioralEpochs-src`

**Overview:** TimeSeries for storing behavoioral epochs.  The objective of this and the other two Behavioral interfaces (e.g. BehavioralEvents and BehavioralTimeSeries) is to provide generic hooks for software tools/scripts. This allows a tool/script to take the output one specific interface (e.g., UnitTimes) and plot that data relative to another data modality (e.g., behavioral events) without having to define all possible modalities in advance. Declaring one of these interfaces means that one or more TimeSeries of the specified type is published. These TimeSeries should reside in a group having the same name as the interface. For example, if a BehavioralTimeSeries interface is declared, the module will have one or more TimeSeries defined in the module sub-group "BehavioralTimeSeries". BehavioralEpochs should use IntervalSeries. BehavioralEvents is used for irregular events. BehavioralTimeSeries is for continuous data.


``BehavioralEpochs`` extends ``Interface`` (see :numref:`sec-Interface`) and includes all elements of :ref:`Interface <sec-Interface>` with the following additions or changes.



.. figure:: ./_format_auto_docs/BehavioralEpochs.*
    :alt: BehavioralEpochs




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-BehavioralEpochs-data:

.. table:: Datasets, Links, and Attributes contained in <BehavioralEpochs>
    :class: longtable

    +--------------------+-------------+----------------------------------------------------------------+
    | Id                 | Type        | Description                                                    |
    +====================+=============+================================================================+
    | BehavioralEpochs   | group       | Top level group for BehavioralEpochs                           |
    +--------------------+-------------+----------------------------------------------------------------+
    | .help              | attribute   | Value is General container for storing behavorial epochs       |
    |                    |             |                                                                |
    |                    |             | - **Data Type:** text                                          |
    |                    |             | - **Value:** General container for storing behavorial epochs   |
    |                    |             |                                                                |
    +--------------------+-------------+----------------------------------------------------------------+




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-BehavioralEpochs-groups:

.. table:: Groups contained in <BehavioralEpochs>
    :class: longtable

    +-------------------------------------------------+---------+-------------------------------------------------------------------+
    | Id                                              | Type    | Description                                                       |
    +=================================================+=========+===================================================================+
    | BehavioralEpochs                                | group   | Top level group for BehavioralEpochs                              |
    +-------------------------------------------------+---------+-------------------------------------------------------------------+
    | .<:ref:`IntervalSeries <sec-IntervalSeries>`>   | group   | IntervalSeries object containing start and stop times of epochs   |
    |                                                 |         |                                                                   |
    |                                                 |         | - **Extends:** :ref:`IntervalSeries <sec-IntervalSeries>`         |
    |                                                 |         |                                                                   |
    +-------------------------------------------------+---------+-------------------------------------------------------------------+


Groups: <IntervalSeries>
""""""""""""""""""""""""

IntervalSeries object containing start and stop times of epochs



- **Extends:** :ref:`IntervalSeries <sec-IntervalSeries>`

