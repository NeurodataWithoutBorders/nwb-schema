.. _sec-ElectrodeGroup:

ElectrodeGroup
^^^^^^^^^^^^^^

**Extends:** :ref:`NWBContainer <sec-NWBContainer>`

**Source Specification:** see :numref:`sec-ElectrodeGroup-src`

**Overview:** One of possibly many groups, one for each electrode group.


``ElectrodeGroup`` extends ``NWBContainer`` (see :numref:`sec-NWBContainer`) and includes all elements of :ref:`NWBContainer <sec-NWBContainer>` with the following additions or changes.



.. figure:: ./_format_auto_docs/ElectrodeGroup.*
    :alt: ElectrodeGroup




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-ElectrodeGroup-data:

.. table:: Datasets, Links, and Attributes contained in <ElectrodeGroup>
    :class: longtable

    +------------------------+-------------+--------------------------------------------------------------------------------------+
    | Id                     | Type        | Description                                                                          |
    +========================+=============+======================================================================================+
    | <ElectrodeGroup>       | group       | Top level group for <ElectrodeGroup>                                                 |
    +------------------------+-------------+--------------------------------------------------------------------------------------+
    | .help                  | attribute   | Value is 'A physical grouping of channels'                                           |
    |                        |             |                                                                                      |
    |                        |             | - **Data Type:** str                                                                 |
    |                        |             | - **Value:** A physical grouping of channels                                         |
    |                        |             |                                                                                      |
    +------------------------+-------------+--------------------------------------------------------------------------------------+
    | .channel_description   | dataset     | array with description for each channel                                              |
    |                        |             |                                                                                      |
    |                        |             | - **Data Type:** text                                                                |
    |                        |             | - **Dimensions:** ['num_channels']                                                   |
    |                        |             | - **Shape:** [None]                                                                  |
    |                        |             |                                                                                      |
    +------------------------+-------------+--------------------------------------------------------------------------------------+
    | .channel_location      | dataset     | array with location description for each channel e.g. "CA1"                          |
    |                        |             |                                                                                      |
    |                        |             | - **Data Type:** text                                                                |
    |                        |             | - **Dimensions:** ['num_channels']                                                   |
    |                        |             | - **Shape:** [None]                                                                  |
    |                        |             |                                                                                      |
    +------------------------+-------------+--------------------------------------------------------------------------------------+
    | .channel_filtering     | dataset     | array with description of filtering applied to each channel                          |
    |                        |             |                                                                                      |
    |                        |             | - **Data Type:** text                                                                |
    |                        |             | - **Dimensions:** ['num_channels']                                                   |
    |                        |             | - **Shape:** [None]                                                                  |
    |                        |             |                                                                                      |
    +------------------------+-------------+--------------------------------------------------------------------------------------+
    | .channel_coordinates   | dataset     | xyz-coordinates for each channel. use NaN for unknown dimensions                     |
    |                        |             |                                                                                      |
    |                        |             | - **Data Type:** text                                                                |
    |                        |             | - **Dimensions:** ['num_channels', 'dimensions']                                     |
    |                        |             | - **Shape:** [None, 3]                                                               |
    |                        |             |                                                                                      |
    +------------------------+-------------+--------------------------------------------------------------------------------------+
    | .channel_impedance     | dataset     | float array with impedance used on each channel. Can be 2D matrix to store a range   |
    |                        |             |                                                                                      |
    |                        |             | - **Data Type:** text                                                                |
    |                        |             | - **Dimensions:** ['num_channels']                                                   |
    |                        |             | - **Shape:** [None]                                                                  |
    |                        |             |                                                                                      |
    +------------------------+-------------+--------------------------------------------------------------------------------------+
    | .description           | dataset     | description of this electrode group                                                  |
    |                        |             |                                                                                      |
    |                        |             | - **Data Type:** text                                                                |
    |                        |             |                                                                                      |
    +------------------------+-------------+--------------------------------------------------------------------------------------+
    | .location              | dataset     | description of location of this electrode group                                      |
    |                        |             |                                                                                      |
    |                        |             | - **Data Type:** text                                                                |
    |                        |             |                                                                                      |
    +------------------------+-------------+--------------------------------------------------------------------------------------+
    | .device                | link        | the device that was used to record from this electrode group                         |
    |                        |             |                                                                                      |
    |                        |             | - **Target Type** :ref:`Device <sec-Device>`                                         |
    |                        |             |                                                                                      |
    +------------------------+-------------+--------------------------------------------------------------------------------------+




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-ElectrodeGroup-groups:

.. table:: Groups contained in <ElectrodeGroup>
    :class: longtable

    +--------------------+---------+----------------------------------------------------------------+
    | Id                 | Type    | Description                                                    |
    +====================+=========+================================================================+
    | <ElectrodeGroup>   | group   | Top level group for <ElectrodeGroup>                           |
    +--------------------+---------+----------------------------------------------------------------+
    | .device            | link    | the device that was used to record from this electrode group   |
    |                    |         |                                                                |
    |                    |         | - **Target Type** :ref:`Device <sec-Device>`                   |
    |                    |         |                                                                |
    +--------------------+---------+----------------------------------------------------------------+


