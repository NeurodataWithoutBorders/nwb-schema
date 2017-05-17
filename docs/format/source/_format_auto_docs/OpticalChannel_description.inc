.. _sec-OpticalChannel:

OpticalChannel
^^^^^^^^^^^^^^

**Source Specification:** see :numref:`sec-OpticalChannel-src`

**Overview:** One of possibly many groups storing channel-specific data 

**Comment:**  Name is arbitrary but should be meaningful




.. figure:: ./_format_auto_docs/OpticalChannel.*
    :alt: OpticalChannel




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-OpticalChannel-data:

.. table:: Datasets, Links, and Attributes contained in <OpticalChannel>
    :class: longtable

    +--------------------+-----------+-------------------------------------------+
    | Id                 | Type      | Description                               |
    +====================+===========+===========================================+
    | <OpticalChannel>   | group     | Top level group for <OpticalChannel>      |
    +--------------------+-----------+-------------------------------------------+
    | .description       | dataset   | Any notes or comments about the channel   |
    |                    |           |                                           |
    |                    |           | - **Data Type:** text                     |
    |                    |           |                                           |
    +--------------------+-----------+-------------------------------------------+
    | .emission_lambda   | dataset   | Emission lambda for channel               |
    |                    |           |                                           |
    |                    |           | - **Data Type:** text                     |
    |                    |           |                                           |
    +--------------------+-----------+-------------------------------------------+



