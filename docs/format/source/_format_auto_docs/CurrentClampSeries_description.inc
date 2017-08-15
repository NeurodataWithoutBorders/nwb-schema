.. _sec-CurrentClampSeries:

CurrentClampSeries
^^^^^^^^^^^^^^^^^^

**Extends:** :ref:`PatchClampSeries <sec-PatchClampSeries>`

**Source Specification:** see :numref:`sec-CurrentClampSeries-src`

**Overview:** Stores voltage data recorded from intracellular current-clamp recordings. A corresponding CurrentClampStimulusSeries (stored separately as a stimulus) is used to store the current injected.


``CurrentClampSeries`` extends ``PatchClampSeries`` (see :numref:`sec-PatchClampSeries`) and includes all elements of :ref:`PatchClampSeries <sec-PatchClampSeries>` with the following additions or changes.



.. figure:: ./_format_auto_docs/CurrentClampSeries.*
    :alt: CurrentClampSeries




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-CurrentClampSeries-data:

.. table:: Datasets, Links, and Attributes contained in <CurrentClampSeries>
    :class: longtable

    +-----------------------------+-------------+--------------------------------------------------------------------------+
    | Id                          | Type        | Description                                                              |
    +=============================+=============+==========================================================================+
    | <CurrentClampSeries>        | group       | Top level group for <CurrentClampSeries>                                 |
    +-----------------------------+-------------+--------------------------------------------------------------------------+
    | .help                       | attribute   | Value is 'Voltage recorded from cell during current-clamp recording'     |
    |                             |             |                                                                          |
    |                             |             | - **Data Type:** text                                                    |
    |                             |             | - **Value:** Voltage recorded from cell during current-clamp recording   |
    |                             |             |                                                                          |
    +-----------------------------+-------------+--------------------------------------------------------------------------+
    | .bias_current               | dataset     | Unit: Amp                                                                |
    |                             |             |                                                                          |
    |                             |             | - **Quantity** 0 or 1                                                    |
    |                             |             | - **Data Type:** float32                                                 |
    |                             |             |                                                                          |
    +-----------------------------+-------------+--------------------------------------------------------------------------+
    | .bridge_balance             | dataset     | Unit: Ohm                                                                |
    |                             |             |                                                                          |
    |                             |             | - **Quantity** 0 or 1                                                    |
    |                             |             | - **Data Type:** float32                                                 |
    |                             |             |                                                                          |
    +-----------------------------+-------------+--------------------------------------------------------------------------+
    | .capacitance_compensation   | dataset     | Unit: Farad                                                              |
    |                             |             |                                                                          |
    |                             |             | - **Quantity** 0 or 1                                                    |
    |                             |             | - **Data Type:** float32                                                 |
    |                             |             |                                                                          |
    +-----------------------------+-------------+--------------------------------------------------------------------------+



