.. _sec-CurrentClampStimulusSeries:

CurrentClampStimulusSeries
^^^^^^^^^^^^^^^^^^^^^^^^^^

**Extends:** :ref:`PatchClampSeries <sec-PatchClampSeries>`

**Source Specification:** see :numref:`sec-CurrentClampStimulusSeries-src`

**Overview:** Aliases to standard PatchClampSeries. Its functionality is to better tag PatchClampSeries for machine (and human) readability of the file.


``CurrentClampStimulusSeries`` extends ``PatchClampSeries`` (see :numref:`sec-PatchClampSeries`) and includes all elements of :ref:`PatchClampSeries <sec-PatchClampSeries>` with the following additions or changes.




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-CurrentClampStimulusSeries-data:

.. table:: Datasets, Links, and Attributes contained in <CurrentClampStimulusSeries>
    :class: longtable

    +--------------------------------+-------------+--------------------------------------------------------------------------------------------+
    | Id                             | Type        | Description                                                                                |
    +================================+=============+============================================================================================+
    | <CurrentClampStimulusSeries>   | group       | Top level group for <CurrentClampStimulusSeries>                                           |
    |                                |             |                                                                                            |
    |                                |             | - **Extends:** :ref:`PatchClampSeries <sec-PatchClampSeries>`                              |
    |                                |             | - **Neurodata Type:** :ref:`CurrentClampStimulusSeries <sec-CurrentClampStimulusSeries>`   |
    |                                |             |                                                                                            |
    +--------------------------------+-------------+--------------------------------------------------------------------------------------------+
    | .help                          | attribute   | Value is 'Stimulus current applied during current clamp recording'                         |
    |                                |             |                                                                                            |
    |                                |             | - **Data Type:** text                                                                      |
    |                                |             | - **Value:** Stimulus current applied during current clamp recording                       |
    |                                |             | - **Name:** help                                                                           |
    |                                |             |                                                                                            |
    +--------------------------------+-------------+--------------------------------------------------------------------------------------------+



