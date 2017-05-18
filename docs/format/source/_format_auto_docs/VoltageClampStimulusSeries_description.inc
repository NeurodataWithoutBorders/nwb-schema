.. _sec-VoltageClampStimulusSeries:

VoltageClampStimulusSeries
^^^^^^^^^^^^^^^^^^^^^^^^^^

**Extends:** :ref:`PatchClampSeries <sec-PatchClampSeries>`

**Source Specification:** see :numref:`sec-VoltageClampStimulusSeries-src`

**Overview:** Aliases to standard PatchClampSeries. Its functionality is to better tag PatchClampSeries for machine (and human) readability of the file.


``VoltageClampStimulusSeries`` extends ``PatchClampSeries`` (see :numref:`sec-PatchClampSeries`) and includes all elements of :ref:`PatchClampSeries <sec-PatchClampSeries>` with the following additions or changes.




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-VoltageClampStimulusSeries-data:

.. table:: Datasets, Links, and Attributes contained in <VoltageClampStimulusSeries>
    :class: longtable

    +--------------------------------+-------------+------------------------------------------------------------------------+
    | Id                             | Type        | Description                                                            |
    +================================+=============+========================================================================+
    | <VoltageClampStimulusSeries>   | group       | Top level group for <VoltageClampStimulusSeries>                       |
    +--------------------------------+-------------+------------------------------------------------------------------------+
    | .help                          | attribute   | Value is Stimulus voltage applied during voltage clamp recording       |
    |                                |             |                                                                        |
    |                                |             | - **Data Type:** text                                                  |
    |                                |             | - **Value:** Stimulus voltage applied during voltage clamp recording   |
    |                                |             |                                                                        |
    +--------------------------------+-------------+------------------------------------------------------------------------+



