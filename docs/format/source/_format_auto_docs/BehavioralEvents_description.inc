.. _sec-BehavioralEvents:

BehavioralEvents
^^^^^^^^^^^^^^^^

**Extends:** :ref:`NWBContainer <sec-NWBContainer>`

**Source Specification:** see :numref:`sec-BehavioralEvents-src`

**Overview:** TimeSeries for storing behavioral events. See description of <a href="#BehavioralEpochs">BehavioralEpochs</a> for more details.


``BehavioralEvents`` extends ``NWBContainer`` (see :numref:`sec-NWBContainer`) and includes all elements of :ref:`NWBContainer <sec-NWBContainer>` with the following additions or changes.



- **Default Name:** BehavioralEvents


.. figure:: ./_format_auto_docs/BehavioralEvents.*
    :alt: BehavioralEvents




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-BehavioralEvents-data:

.. table:: Datasets, Links, and Attributes contained in <BehavioralEvents>
    :class: longtable

    +----------------------+-------------+------------------------------------------------------------------------+
    | Id                   | Type        | Description                                                            |
    +======================+=============+========================================================================+
    | <BehavioralEvents>   | group       | Top level group for <BehavioralEvents>                                 |
    |                      |             |                                                                        |
    |                      |             | - **Extends:** :ref:`NWBContainer <sec-NWBContainer>`                  |
    |                      |             | - **Neurodata Type:** :ref:`BehavioralEvents <sec-BehavioralEvents>`   |
    |                      |             | - **Default Name:** BehavioralEvents                                   |
    |                      |             |                                                                        |
    +----------------------+-------------+------------------------------------------------------------------------+
    | .help                | attribute   | Value is 'Position data, whether along the x, xy or xyz axis'          |
    |                      |             |                                                                        |
    |                      |             | - **Data Type:** text                                                  |
    |                      |             | - **Value:** Position data, whether along the x, xy or xyz axis        |
    |                      |             | - **Name:** help                                                       |
    |                      |             |                                                                        |
    +----------------------+-------------+------------------------------------------------------------------------+




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-BehavioralEvents-groups:

.. table:: Groups contained in <BehavioralEvents>
    :class: longtable

    +-----------------------------------------+---------+------------------------------------------------------------------------+
    | Id                                      | Type    | Description                                                            |
    +=========================================+=========+========================================================================+
    | <BehavioralEvents>                      | group   | Top level group for <BehavioralEvents>                                 |
    |                                         |         |                                                                        |
    |                                         |         | - **Extends:** :ref:`NWBContainer <sec-NWBContainer>`                  |
    |                                         |         | - **Neurodata Type:** :ref:`BehavioralEvents <sec-BehavioralEvents>`   |
    |                                         |         | - **Default Name:** BehavioralEvents                                   |
    |                                         |         |                                                                        |
    +-----------------------------------------+---------+------------------------------------------------------------------------+
    | .<:ref:`TimeSeries <sec-TimeSeries>`>   | group   | TimeSeries object containing irregular behavioral events               |
    |                                         |         |                                                                        |
    |                                         |         | - **Quantity** 0 or more                                               |
    |                                         |         | - **Extends:** :ref:`TimeSeries <sec-TimeSeries>`                      |
    |                                         |         |                                                                        |
    +-----------------------------------------+---------+------------------------------------------------------------------------+


Groups: <TimeSeries>
""""""""""""""""""""

TimeSeries object containing irregular behavioral events



- **Quantity** 0 or more
- **Extends:** :ref:`TimeSeries <sec-TimeSeries>`

