.. _sec-BehavioralTimeSeries:

BehavioralTimeSeries
^^^^^^^^^^^^^^^^^^^^

**Extends:** :ref:`NWBContainer <sec-NWBContainer>`

**Source Specification:** see :numref:`sec-BehavioralTimeSeries-src`

**Overview:** TimeSeries for storing Behavoioral time series data.See description of <a href="#BehavioralEpochs">BehavioralEpochs</a> for more details.


``BehavioralTimeSeries`` extends ``NWBContainer`` (see :numref:`sec-NWBContainer`) and includes all elements of :ref:`NWBContainer <sec-NWBContainer>` with the following additions or changes.



.. figure:: ./_format_auto_docs/BehavioralTimeSeries.*
    :alt: BehavioralTimeSeries




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-BehavioralTimeSeries-data:

.. table:: Datasets, Links, and Attributes contained in <BehavioralTimeSeries>
    :class: longtable

    +------------------------+-------------+------------------------------------------------------------------------------------+
    | Id                     | Type        | Description                                                                        |
    +========================+=============+====================================================================================+
    | BehavioralTimeSeries   | group       | Top level group for BehavioralTimeSeries                                           |
    +------------------------+-------------+------------------------------------------------------------------------------------+
    | .help                  | attribute   | Value is 'General container for storing continuously sampled behavioral data.'     |
    |                        |             |                                                                                    |
    |                        |             | - **Data Type:** text                                                              |
    |                        |             | - **Value:** General container for storing continuously sampled behavioral data.   |
    |                        |             |                                                                                    |
    +------------------------+-------------+------------------------------------------------------------------------------------+




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-BehavioralTimeSeries-groups:

.. table:: Groups contained in <BehavioralTimeSeries>
    :class: longtable

    +-----------------------------------------+---------+-----------------------------------------------------------+
    | Id                                      | Type    | Description                                               |
    +=========================================+=========+===========================================================+
    | BehavioralTimeSeries                    | group   | Top level group for BehavioralTimeSeries                  |
    +-----------------------------------------+---------+-----------------------------------------------------------+
    | .<:ref:`TimeSeries <sec-TimeSeries>`>   | group   | TimeSeries object containing continuous behavioral data   |
    |                                         |         |                                                           |
    |                                         |         | - **Quantity** 0 or more                                  |
    |                                         |         | - **Extends:** :ref:`TimeSeries <sec-TimeSeries>`         |
    |                                         |         |                                                           |
    +-----------------------------------------+---------+-----------------------------------------------------------+


Groups: <TimeSeries>
""""""""""""""""""""

TimeSeries object containing continuous behavioral data



- **Quantity** 0 or more
- **Extends:** :ref:`TimeSeries <sec-TimeSeries>`

