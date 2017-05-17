.. _sec-IntracellularElectrode:

IntracellularElectrode
^^^^^^^^^^^^^^^^^^^^^^

**Source Specification:** see :numref:`sec-IntracellularElectrode-src`

**Overview:** One of possibly many. 

**Comment:**  Name should be informative.




.. figure:: ./_format_auto_docs/IntracellularElectrode.*
    :alt: IntracellularElectrode




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-IntracellularElectrode-data:

.. table:: Datasets, Links, and Attributes contained in <IntracellularElectrode>
    :class: longtable

    +------------------------------+-----------+-----------------------------------------------------------------------------------+
    | Id                           | Type      | Description                                                                       |
    +==============================+===========+===================================================================================+
    | <IntracellularElectrode>     | group     | Top level group for <IntracellularElectrode>                                      |
    +------------------------------+-----------+-----------------------------------------------------------------------------------+
    | .initial_access_resistance   | dataset   | Initial access resistance                                                         |
    |                              |           |                                                                                   |
    |                              |           | - **Quantity** 0 or 1                                                             |
    |                              |           | - **Data Type:** text                                                             |
    |                              |           |                                                                                   |
    +------------------------------+-----------+-----------------------------------------------------------------------------------+
    | .description                 | dataset   | Recording description, description of electrode (e.g.,  whole-cell, sharp, etc)   |
    |                              |           |                                                                                   |
    |                              |           | **Comment:**  Free-form text (can be from Methods)                                |
    |                              |           |                                                                                   |
    |                              |           | - **Data Type:** text                                                             |
    |                              |           |                                                                                   |
    +------------------------------+-----------+-----------------------------------------------------------------------------------+
    | .location                    | dataset   | Area, layer, comments on estimation, stereotaxis coordinates (if in vivo, etc)    |
    |                              |           |                                                                                   |
    |                              |           | - **Quantity** 0 or 1                                                             |
    |                              |           | - **Data Type:** text                                                             |
    |                              |           |                                                                                   |
    +------------------------------+-----------+-----------------------------------------------------------------------------------+
    | .filtering                   | dataset   | Electrode specific filtering.                                                     |
    |                              |           |                                                                                   |
    |                              |           | - **Quantity** 0 or 1                                                             |
    |                              |           | - **Data Type:** text                                                             |
    |                              |           |                                                                                   |
    +------------------------------+-----------+-----------------------------------------------------------------------------------+
    | .slice                       | dataset   | Information about slice used for recording                                        |
    |                              |           |                                                                                   |
    |                              |           | - **Quantity** 0 or 1                                                             |
    |                              |           | - **Data Type:** text                                                             |
    |                              |           |                                                                                   |
    +------------------------------+-----------+-----------------------------------------------------------------------------------+
    | .resistance                  | dataset   | Electrode resistance                                                              |
    |                              |           |                                                                                   |
    |                              |           | **Comment:**  unit: Ohm                                                           |
    |                              |           |                                                                                   |
    |                              |           | - **Quantity** 0 or 1                                                             |
    |                              |           | - **Data Type:** text                                                             |
    |                              |           |                                                                                   |
    +------------------------------+-----------+-----------------------------------------------------------------------------------+
    | .device                      | dataset   | Name(s) of devices in general/devices                                             |
    |                              |           |                                                                                   |
    |                              |           | - **Quantity** 0 or 1                                                             |
    |                              |           | - **Data Type:** text                                                             |
    |                              |           |                                                                                   |
    +------------------------------+-----------+-----------------------------------------------------------------------------------+
    | .seal                        | dataset   | Information about seal used for recording                                         |
    |                              |           |                                                                                   |
    |                              |           | - **Quantity** 0 or 1                                                             |
    |                              |           | - **Data Type:** text                                                             |
    |                              |           |                                                                                   |
    +------------------------------+-----------+-----------------------------------------------------------------------------------+



