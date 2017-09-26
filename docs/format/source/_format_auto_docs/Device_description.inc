.. _sec-Device:

Device
^^^^^^

**Extends:** :ref:`NWBContainer <sec-NWBContainer>`

**Source Specification:** see :numref:`sec-Device-src`

**Overview:** One of possibly many. Information about device and device description.


``Device`` extends ``NWBContainer`` (see :numref:`sec-NWBContainer`) and includes all elements of :ref:`NWBContainer <sec-NWBContainer>` with the following additions or changes.




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-Device-data:

.. table:: Datasets, Links, and Attributes contained in <Device>
    :class: longtable

    +------------+-------------+---------------------------------------------------------+
    | Id         | Type        | Description                                             |
    +============+=============+=========================================================+
    | <Device>   | group       | Top level group for <Device>                            |
    |            |             |                                                         |
    |            |             | - **Extends:** :ref:`NWBContainer <sec-NWBContainer>`   |
    |            |             | - **Neurodata Type:** :ref:`Device <sec-Device>`        |
    |            |             |                                                         |
    +------------+-------------+---------------------------------------------------------+
    | .help      | attribute   | Value is 'A recording device e.g. amplifier'            |
    |            |             |                                                         |
    |            |             | - **Data Type:** str                                    |
    |            |             | - **Value:** A recording device e.g. amplifier          |
    |            |             | - **Name:** help                                        |
    |            |             |                                                         |
    +------------+-------------+---------------------------------------------------------+



