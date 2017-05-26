.. _sec-BehavioralEvents:

BehavioralEvents
^^^^^^^^^^^^^^^^

**Extends:** :ref:`Interface <sec-Interface>`

**Source Specification:** see :numref:`sec-BehavioralEvents-src`

**Overview:** TimeSeries for storing behavioral events. See description of <a href="#BehavioralEpochs">BehavioralEpochs</a> for more details.


``BehavioralEvents`` extends ``Interface`` (see :numref:`sec-Interface`) and includes all elements of :ref:`Interface <sec-Interface>` with the following additions or changes.



.. figure:: ./_format_auto_docs/BehavioralEvents.*
    :alt: BehavioralEvents




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-BehavioralEvents-data:

.. table:: Datasets, Links, and Attributes contained in <BehavioralEvents>
    :class: longtable

    +--------------------+-------------+-------------------------------------------------------------------+
    | Id                 | Type        | Description                                                       |
    +====================+=============+===================================================================+
    | BehavioralEvents   | group       | Top level group for BehavioralEvents                              |
    +--------------------+-------------+-------------------------------------------------------------------+
    | .help              | attribute   | Value is 'Position data, whether along the x, xy or xyz axis'     |
    |                    |             |                                                                   |
    |                    |             | - **Data Type:** text                                             |
    |                    |             | - **Value:** Position data, whether along the x, xy or xyz axis   |
    |                    |             |                                                                   |
    +--------------------+-------------+-------------------------------------------------------------------+




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-BehavioralEvents-groups:

.. table:: Groups contained in <BehavioralEvents>
    :class: longtable

    +-----------------------------------------+---------+------------------------------------------------------------+
    | Id                                      | Type    | Description                                                |
    +=========================================+=========+============================================================+
    | BehavioralEvents                        | group   | Top level group for BehavioralEvents                       |
    +-----------------------------------------+---------+------------------------------------------------------------+
    | .<:ref:`TimeSeries <sec-TimeSeries>`>   | group   | TimeSeries object containing irregular behavioral events   |
    |                                         |         |                                                            |
    |                                         |         | - **Quantity** 0 or more                                   |
    |                                         |         | - **Extends:** :ref:`TimeSeries <sec-TimeSeries>`          |
    |                                         |         |                                                            |
    +-----------------------------------------+---------+------------------------------------------------------------+


Groups: <TimeSeries>
""""""""""""""""""""

TimeSeries object containing irregular behavioral events



- **Quantity** 0 or more
- **Extends:** :ref:`TimeSeries <sec-TimeSeries>`

