.. _sec-IntracellularElectrode:

IntracellularElectrode
^^^^^^^^^^^^^^^^^^^^^^

**Extends:** :ref:`NWBContainer <sec-NWBContainer>`

**Source Specification:** see :numref:`sec-IntracellularElectrode-src`

**Overview:** One of possibly many. 

**Comment:**  Name should be informative.


``IntracellularElectrode`` extends ``NWBContainer`` (see :numref:`sec-NWBContainer`) and includes all elements of :ref:`NWBContainer <sec-NWBContainer>` with the following additions or changes.



.. figure:: ./_format_auto_docs/IntracellularElectrode.*
    :alt: IntracellularElectrode




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-IntracellularElectrode-data:

.. table:: Datasets, Links, and Attributes contained in <IntracellularElectrode>
    :class: longtable

    +------------------------------+-------------+------------------------------------------------------------------------------------+
    | Id                           | Type        | Description                                                                        |
    +==============================+=============+====================================================================================+
    | <IntracellularElectrode>     | group       | Top level group for <IntracellularElectrode>                                       |
    |                              |             |                                                                                    |
    |                              |             | - **Extends:** :ref:`NWBContainer <sec-NWBContainer>`                              |
    |                              |             | - **Neurodata Type:** :ref:`IntracellularElectrode <sec-IntracellularElectrode>`   |
    |                              |             |                                                                                    |
    +------------------------------+-------------+------------------------------------------------------------------------------------+
    | .help                        | attribute   | Value is 'Metadata about an intracellular electrode'                               |
    |                              |             |                                                                                    |
    |                              |             | - **Data Type:** text                                                              |
    |                              |             | - **Value:** Metadata about an intracellular electrode                             |
    |                              |             | - **Name:** help                                                                   |
    |                              |             |                                                                                    |
    +------------------------------+-------------+------------------------------------------------------------------------------------+
    | .description                 | dataset     | Recording description, description of electrode (e.g.,  whole-cell, sharp, etc)    |
    |                              |             |                                                                                    |
    |                              |             | **Comment:**  Free-form text (can be from Methods)                                 |
    |                              |             |                                                                                    |
    |                              |             | - **Data Type:** text                                                              |
    |                              |             | - **Name:** description                                                            |
    |                              |             |                                                                                    |
    +------------------------------+-------------+------------------------------------------------------------------------------------+
    | .device                      | dataset     | Name(s) of devices in general/devices                                              |
    |                              |             |                                                                                    |
    |                              |             | - **Quantity** 0 or 1                                                              |
    |                              |             | - **Data Type:** text                                                              |
    |                              |             | - **Name:** device                                                                 |
    |                              |             |                                                                                    |
    +------------------------------+-------------+------------------------------------------------------------------------------------+
    | .filtering                   | dataset     | Electrode specific filtering.                                                      |
    |                              |             |                                                                                    |
    |                              |             | - **Quantity** 0 or 1                                                              |
    |                              |             | - **Data Type:** text                                                              |
    |                              |             | - **Name:** filtering                                                              |
    |                              |             |                                                                                    |
    +------------------------------+-------------+------------------------------------------------------------------------------------+
    | .initial_access_resistance   | dataset     | Initial access resistance                                                          |
    |                              |             |                                                                                    |
    |                              |             | - **Quantity** 0 or 1                                                              |
    |                              |             | - **Data Type:** text                                                              |
    |                              |             | - **Name:** initial_access_resistance                                              |
    |                              |             |                                                                                    |
    +------------------------------+-------------+------------------------------------------------------------------------------------+
    | .location                    | dataset     | Area, layer, comments on estimation, stereotaxis coordinates (if in vivo, etc)     |
    |                              |             |                                                                                    |
    |                              |             | - **Quantity** 0 or 1                                                              |
    |                              |             | - **Data Type:** text                                                              |
    |                              |             | - **Name:** location                                                               |
    |                              |             |                                                                                    |
    +------------------------------+-------------+------------------------------------------------------------------------------------+
    | .resistance                  | dataset     | Electrode resistance                                                               |
    |                              |             |                                                                                    |
    |                              |             | **Comment:**  unit: Ohm                                                            |
    |                              |             |                                                                                    |
    |                              |             | - **Quantity** 0 or 1                                                              |
    |                              |             | - **Data Type:** text                                                              |
    |                              |             | - **Name:** resistance                                                             |
    |                              |             |                                                                                    |
    +------------------------------+-------------+------------------------------------------------------------------------------------+
    | .seal                        | dataset     | Information about seal used for recording                                          |
    |                              |             |                                                                                    |
    |                              |             | - **Quantity** 0 or 1                                                              |
    |                              |             | - **Data Type:** text                                                              |
    |                              |             | - **Name:** seal                                                                   |
    |                              |             |                                                                                    |
    +------------------------------+-------------+------------------------------------------------------------------------------------+
    | .slice                       | dataset     | Information about slice used for recording                                         |
    |                              |             |                                                                                    |
    |                              |             | - **Quantity** 0 or 1                                                              |
    |                              |             | - **Data Type:** text                                                              |
    |                              |             | - **Name:** slice                                                                  |
    |                              |             |                                                                                    |
    +------------------------------+-------------+------------------------------------------------------------------------------------+



