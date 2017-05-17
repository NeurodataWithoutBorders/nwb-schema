.. _sec-VoltageClampSeries:

VoltageClampSeries
^^^^^^^^^^^^^^^^^^

**Extends:** :ref:`PatchClampSeries <sec-PatchClampSeries>`

**Source Specification:** see :numref:`sec-VoltageClampSeries-src`

**Overview:** Stores current data recorded from intracellular voltage-clamp recordings. A corresponding VoltageClampStimulusSeries (stored separately as a stimulus) is used to store the voltage injected.


``VoltageClampSeries`` extends ``PatchClampSeries`` (see :numref:`sec-PatchClampSeries`) and includes all elements of :ref:`PatchClampSeries <sec-PatchClampSeries>` with the following additions or changes.



.. figure:: ./_format_auto_docs/VoltageClampSeries.*
    :alt: VoltageClampSeries




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-VoltageClampSeries-data:

.. table:: Datasets, Links, and Attributes contained in <VoltageClampSeries>
    :class: longtable

    +--------------------------------------+-------------+--------------------------------------------------------------------------+
    | Id                                   | Type        | Description                                                              |
    +======================================+=============+==========================================================================+
    | <VoltageClampSeries>                 | group       | Top level group for <VoltageClampSeries>                                 |
    +--------------------------------------+-------------+--------------------------------------------------------------------------+
    | .help                                | attribute   | Value is Current recorded from cell during voltage-clamp recording       |
    |                                      |             |                                                                          |
    |                                      |             | - **Data Type:** text                                                    |
    |                                      |             | - **Value:** Current recorded from cell during voltage-clamp recording   |
    |                                      |             |                                                                          |
    +--------------------------------------+-------------+--------------------------------------------------------------------------+
    | .capacitance_slow                    | dataset     | Unit: Farad                                                              |
    |                                      |             |                                                                          |
    |                                      |             | - **Quantity** 0 or 1                                                    |
    |                                      |             | - **Data Type:** float32                                                 |
    |                                      |             |                                                                          |
    +--------------------------------------+-------------+--------------------------------------------------------------------------+
    | ..unit                               | attribute   | Value is Farad                                                           |
    |                                      |             |                                                                          |
    |                                      |             | - **Data Type:** text                                                    |
    |                                      |             | - **Value:** Farad                                                       |
    |                                      |             |                                                                          |
    +--------------------------------------+-------------+--------------------------------------------------------------------------+
    | .whole_cell_capacitance_comp         | dataset     | Unit: Farad                                                              |
    |                                      |             |                                                                          |
    |                                      |             | - **Quantity** 0 or 1                                                    |
    |                                      |             | - **Data Type:** float32                                                 |
    |                                      |             |                                                                          |
    +--------------------------------------+-------------+--------------------------------------------------------------------------+
    | ..unit                               | attribute   | Value is Farad                                                           |
    |                                      |             |                                                                          |
    |                                      |             | - **Data Type:** text                                                    |
    |                                      |             | - **Value:** Farad                                                       |
    |                                      |             |                                                                          |
    +--------------------------------------+-------------+--------------------------------------------------------------------------+
    | .capacitance_fast                    | dataset     | Unit: Farad                                                              |
    |                                      |             |                                                                          |
    |                                      |             | - **Quantity** 0 or 1                                                    |
    |                                      |             | - **Data Type:** float32                                                 |
    |                                      |             |                                                                          |
    +--------------------------------------+-------------+--------------------------------------------------------------------------+
    | ..unit                               | attribute   | Value is Farad                                                           |
    |                                      |             |                                                                          |
    |                                      |             | - **Data Type:** text                                                    |
    |                                      |             | - **Value:** Farad                                                       |
    |                                      |             |                                                                          |
    +--------------------------------------+-------------+--------------------------------------------------------------------------+
    | .resistance_comp_prediction          | dataset     | Unit: %                                                                  |
    |                                      |             |                                                                          |
    |                                      |             | - **Quantity** 0 or 1                                                    |
    |                                      |             | - **Data Type:** float32                                                 |
    |                                      |             |                                                                          |
    +--------------------------------------+-------------+--------------------------------------------------------------------------+
    | ..unit                               | attribute   | Value is pecent                                                          |
    |                                      |             |                                                                          |
    |                                      |             | - **Data Type:** text                                                    |
    |                                      |             | - **Value:** pecent                                                      |
    |                                      |             |                                                                          |
    +--------------------------------------+-------------+--------------------------------------------------------------------------+
    | .resistance_comp_bandwidth           | dataset     | Unit: Hz                                                                 |
    |                                      |             |                                                                          |
    |                                      |             | - **Quantity** 0 or 1                                                    |
    |                                      |             | - **Data Type:** float32                                                 |
    |                                      |             |                                                                          |
    +--------------------------------------+-------------+--------------------------------------------------------------------------+
    | ..unit                               | attribute   | Value is Hz                                                              |
    |                                      |             |                                                                          |
    |                                      |             | - **Data Type:** text                                                    |
    |                                      |             | - **Value:** Hz                                                          |
    |                                      |             |                                                                          |
    +--------------------------------------+-------------+--------------------------------------------------------------------------+
    | .resistance_comp_correction          | dataset     | Unit: %                                                                  |
    |                                      |             |                                                                          |
    |                                      |             | - **Quantity** 0 or 1                                                    |
    |                                      |             | - **Data Type:** float32                                                 |
    |                                      |             |                                                                          |
    +--------------------------------------+-------------+--------------------------------------------------------------------------+
    | ..unit                               | attribute   | Value is pecent                                                          |
    |                                      |             |                                                                          |
    |                                      |             | - **Data Type:** text                                                    |
    |                                      |             | - **Value:** pecent                                                      |
    |                                      |             |                                                                          |
    +--------------------------------------+-------------+--------------------------------------------------------------------------+
    | .whole_cell_series_resistance_comp   | dataset     | Unit: Ohm                                                                |
    |                                      |             |                                                                          |
    |                                      |             | - **Quantity** 0 or 1                                                    |
    |                                      |             | - **Data Type:** float32                                                 |
    |                                      |             |                                                                          |
    +--------------------------------------+-------------+--------------------------------------------------------------------------+
    | ..unit                               | attribute   | Value is Ohm                                                             |
    |                                      |             |                                                                          |
    |                                      |             | - **Data Type:** text                                                    |
    |                                      |             | - **Value:** Ohm                                                         |
    |                                      |             |                                                                          |
    +--------------------------------------+-------------+--------------------------------------------------------------------------+



