.. _sec-OpticalChannel:

OpticalChannel
^^^^^^^^^^^^^^

**Extends:** :ref:`NWBContainer <sec-NWBContainer>`

**Source Specification:** see :numref:`sec-OpticalChannel-src`

**Overview:** One of possibly many groups storing channel-specific data 

**Comment:**  Name is arbitrary but should be meaningful


``OpticalChannel`` extends ``NWBContainer`` (see :numref:`sec-NWBContainer`) and includes all elements of :ref:`NWBContainer <sec-NWBContainer>` with the following additions or changes.



.. figure:: ./_format_auto_docs/OpticalChannel.*
    :alt: OpticalChannel




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-OpticalChannel-data:

.. table:: Datasets, Links, and Attributes contained in <OpticalChannel>
    :class: longtable

    +--------------------+-------------+---------------------------------------------------------------------------------------+
    | Id                 | Type        | Description                                                                           |
    +====================+=============+=======================================================================================+
    | <OpticalChannel>   | group       | Top level group for <OpticalChannel>                                                  |
    |                    |             |                                                                                       |
    |                    |             | - **Extends:** :ref:`NWBContainer <sec-NWBContainer>`                                 |
    |                    |             | - **Neurodata Type:** :ref:`OpticalChannel <sec-OpticalChannel>`                      |
    |                    |             |                                                                                       |
    +--------------------+-------------+---------------------------------------------------------------------------------------+
    | .help              | attribute   | Value is 'Metadata about an optical channel used to record from an imaging plane'     |
    |                    |             |                                                                                       |
    |                    |             | - **Data Type:** text                                                                 |
    |                    |             | - **Value:** Metadata about an optical channel used to record from an imaging plane   |
    |                    |             | - **Name:** help                                                                      |
    |                    |             |                                                                                       |
    +--------------------+-------------+---------------------------------------------------------------------------------------+
    | .description       | dataset     | Any notes or comments about the channel                                               |
    |                    |             |                                                                                       |
    |                    |             | - **Data Type:** text                                                                 |
    |                    |             | - **Name:** description                                                               |
    |                    |             |                                                                                       |
    +--------------------+-------------+---------------------------------------------------------------------------------------+
    | .emission_lambda   | dataset     | Emission lambda for channel                                                           |
    |                    |             |                                                                                       |
    |                    |             | - **Data Type:** text                                                                 |
    |                    |             | - **Name:** emission_lambda                                                           |
    |                    |             |                                                                                       |
    +--------------------+-------------+---------------------------------------------------------------------------------------+



