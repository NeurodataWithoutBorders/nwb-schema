.. _sec-IntervalSeries:

IntervalSeries
^^^^^^^^^^^^^^

**Extends:** :ref:`TimeSeries <sec-TimeSeries>`

**Source Specification:** see :numref:`sec-IntervalSeries-src`

**Overview:** Stores intervals of data. The timestamps field stores the beginning and end of intervals. The data field stores whether the interval just started (>0 value) or ended (<0 value). Different interval types can be represented in the same series by using multiple key values (eg, 1 for feature A, 2 for feature B, 3 for feature C, etc). The field data stores an 8-bit integer. This is largely an alias of a standard TimeSeries but that is identifiable as representing time intervals in a machine-readable way.


``IntervalSeries`` extends ``TimeSeries`` (see :numref:`sec-TimeSeries`) and includes all elements of :ref:`TimeSeries <sec-TimeSeries>` with the following additions or changes.



.. figure:: ./_format_auto_docs/IntervalSeries.*
    :alt: IntervalSeries




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-IntervalSeries-data:

.. table:: Datasets, Links, and Attributes contained in <IntervalSeries>
    :class: longtable

    +--------------------+-------------+-----------------------------------------------------------+
    | Id                 | Type        | Description                                               |
    +====================+=============+===========================================================+
    | <IntervalSeries>   | group       | Top level group for <IntervalSeries>                      |
    +--------------------+-------------+-----------------------------------------------------------+
    | .help              | attribute   | Value is 'Stores the start and stop times for events'     |
    |                    |             |                                                           |
    |                    |             | - **Data Type:** text                                     |
    |                    |             | - **Value:** Stores the start and stop times for events   |
    |                    |             |                                                           |
    +--------------------+-------------+-----------------------------------------------------------+
    | .data              | dataset     | >0 if interval started, <0 if interval ended.             |
    |                    |             |                                                           |
    |                    |             | - **Data Type:** int8                                     |
    |                    |             | - **Dimensions:** ['num_times']                           |
    |                    |             | - **Shape:** [None]                                       |
    |                    |             |                                                           |
    +--------------------+-------------+-----------------------------------------------------------+
    | ..conversion       | attribute   | Value is 'float('NaN')'                                   |
    |                    |             |                                                           |
    |                    |             | - **Data Type:** None                                     |
    |                    |             | - **Value:** NaN                                          |
    |                    |             |                                                           |
    +--------------------+-------------+-----------------------------------------------------------+
    | ..resolution       | attribute   | Value is 'float('NaN')'                                   |
    |                    |             |                                                           |
    |                    |             | - **Data Type:** None                                     |
    |                    |             | - **Value:** NaN                                          |
    |                    |             |                                                           |
    +--------------------+-------------+-----------------------------------------------------------+
    | ..unit             | attribute   | Value is 'n/a'                                            |
    |                    |             |                                                           |
    |                    |             | - **Data Type:** None                                     |
    |                    |             | - **Value:** n/a                                          |
    |                    |             |                                                           |
    +--------------------+-------------+-----------------------------------------------------------+



