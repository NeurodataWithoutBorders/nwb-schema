.. _sec-PupilTracking:

PupilTracking
^^^^^^^^^^^^^

**Extends:** :ref:`NWBContainer <sec-NWBContainer>`

**Source Specification:** see :numref:`sec-PupilTracking-src`

**Overview:** Eye-tracking data, representing pupil size.


``PupilTracking`` extends ``NWBContainer`` (see :numref:`sec-NWBContainer`) and includes all elements of :ref:`NWBContainer <sec-NWBContainer>` with the following additions or changes.



- **Default Name:** PupilTracking


.. figure:: ./_format_auto_docs/PupilTracking.*
    :alt: PupilTracking




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-PupilTracking-data:

.. table:: Datasets, Links, and Attributes contained in <PupilTracking>
    :class: longtable

    +-------------------+-------------+-----------------------------------------------------------+
    | Id                | Type        | Description                                               |
    +===================+=============+===========================================================+
    | <PupilTracking>   | group       | Top level group for <PupilTracking>                       |
    +-------------------+-------------+-----------------------------------------------------------+
    | .help             | attribute   | Value is 'Eye-tracking data, representing pupil size'     |
    |                   |             |                                                           |
    |                   |             | - **Data Type:** text                                     |
    |                   |             | - **Value:** Eye-tracking data, representing pupil size   |
    |                   |             |                                                           |
    +-------------------+-------------+-----------------------------------------------------------+




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-PupilTracking-groups:

.. table:: Groups contained in <PupilTracking>
    :class: longtable

    +-----------------------------------------+---------+---------------------------------------------------------------+
    | Id                                      | Type    | Description                                                   |
    +=========================================+=========+===============================================================+
    | <PupilTracking>                         | group   | Top level group for <PupilTracking>                           |
    +-----------------------------------------+---------+---------------------------------------------------------------+
    | .<:ref:`TimeSeries <sec-TimeSeries>`>   | group   | TimeSeries object containing time series data on pupil size   |
    |                                         |         |                                                               |
    |                                         |         | - **Quantity** 1 or more                                      |
    |                                         |         | - **Extends:** :ref:`TimeSeries <sec-TimeSeries>`             |
    |                                         |         |                                                               |
    +-----------------------------------------+---------+---------------------------------------------------------------+


Groups: <TimeSeries>
""""""""""""""""""""

TimeSeries object containing time series data on pupil size



- **Quantity** 1 or more
- **Extends:** :ref:`TimeSeries <sec-TimeSeries>`

