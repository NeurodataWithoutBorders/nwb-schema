.. _sec-PatchClampSeries:

PatchClampSeries
^^^^^^^^^^^^^^^^

**Extends:** :ref:`TimeSeries <sec-TimeSeries>`

**Source Specification:** see :numref:`sec-PatchClampSeries-src`

**Overview:** Stores stimulus or response current or voltage. Superclass definition for patch-clamp data (this class should not be instantiated directly).


``PatchClampSeries`` extends ``TimeSeries`` (see :numref:`sec-TimeSeries`) and includes all elements of :ref:`TimeSeries <sec-TimeSeries>` with the following additions or changes.



.. figure:: ./_format_auto_docs/PatchClampSeries.*
    :alt: PatchClampSeries




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-PatchClampSeries-data:

.. table:: Datasets, Links, and Attributes contained in <PatchClampSeries>
    :class: longtable

    +----------------------+-------------+---------------------------------------------------------------------------------------------------------------+
    | Id                   | Type        | Description                                                                                                   |
    +======================+=============+===============================================================================================================+
    | <PatchClampSeries>   | group       | Top level group for <PatchClampSeries>                                                                        |
    |                      |             |                                                                                                               |
    |                      |             | - **Extends:** :ref:`TimeSeries <sec-TimeSeries>`                                                             |
    |                      |             | - **Neurodata Type:** :ref:`PatchClampSeries <sec-PatchClampSeries>`                                          |
    |                      |             |                                                                                                               |
    +----------------------+-------------+---------------------------------------------------------------------------------------------------------------+
    | .help                | attribute   | Value is 'Superclass definition for patch-clamp data'                                                         |
    |                      |             |                                                                                                               |
    |                      |             | - **Data Type:** text                                                                                         |
    |                      |             | - **Value:** Superclass definition for patch-clamp data                                                       |
    |                      |             | - **Name:** help                                                                                              |
    |                      |             |                                                                                                               |
    +----------------------+-------------+---------------------------------------------------------------------------------------------------------------+
    | .data                | dataset     | Recorded voltage or current.                                                                                  |
    |                      |             |                                                                                                               |
    |                      |             | - **Data Type:** number                                                                                       |
    |                      |             | - **Dimensions:** ['num_times']                                                                               |
    |                      |             | - **Shape:** [None]                                                                                           |
    |                      |             | - **Name:** data                                                                                              |
    |                      |             |                                                                                                               |
    +----------------------+-------------+---------------------------------------------------------------------------------------------------------------+
    | .gain                | dataset     | Units: Volt/Amp (v-clamp) or Volt/Volt (c-clamp)                                                              |
    |                      |             |                                                                                                               |
    |                      |             | - **Quantity** 0 or 1                                                                                         |
    |                      |             | - **Data Type:** float                                                                                        |
    |                      |             | - **Name:** gain                                                                                              |
    |                      |             |                                                                                                               |
    +----------------------+-------------+---------------------------------------------------------------------------------------------------------------+
    | .electrode           | link        | link to IntracellularElectrode group that describes th electrode that was used to apply or record this data   |
    |                      |             |                                                                                                               |
    |                      |             | - **Target Type** :ref:`IntracellularElectrode <sec-IntracellularElectrode>`                                  |
    |                      |             | - **Name:** electrode                                                                                         |
    |                      |             |                                                                                                               |
    +----------------------+-------------+---------------------------------------------------------------------------------------------------------------+




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-PatchClampSeries-groups:

.. table:: Groups contained in <PatchClampSeries>
    :class: longtable

    +----------------------+---------+---------------------------------------------------------------------------------------------------------------+
    | Id                   | Type    | Description                                                                                                   |
    +======================+=========+===============================================================================================================+
    | <PatchClampSeries>   | group   | Top level group for <PatchClampSeries>                                                                        |
    |                      |         |                                                                                                               |
    |                      |         | - **Extends:** :ref:`TimeSeries <sec-TimeSeries>`                                                             |
    |                      |         | - **Neurodata Type:** :ref:`PatchClampSeries <sec-PatchClampSeries>`                                          |
    |                      |         |                                                                                                               |
    +----------------------+---------+---------------------------------------------------------------------------------------------------------------+
    | .electrode           | link    | link to IntracellularElectrode group that describes th electrode that was used to apply or record this data   |
    |                      |         |                                                                                                               |
    |                      |         | - **Target Type** :ref:`IntracellularElectrode <sec-IntracellularElectrode>`                                  |
    |                      |         | - **Name:** electrode                                                                                         |
    |                      |         |                                                                                                               |
    +----------------------+---------+---------------------------------------------------------------------------------------------------------------+


