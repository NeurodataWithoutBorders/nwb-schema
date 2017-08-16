.. _sec-IZeroClampSeries:

IZeroClampSeries
^^^^^^^^^^^^^^^^

**Extends:** :ref:`CurrentClampSeries <sec-CurrentClampSeries>`

**Source Specification:** see :numref:`sec-IZeroClampSeries-src`

**Overview:** Stores recorded voltage data from intracellular recordings when all current and amplifier settings are off (i.e., CurrentClampSeries fields will be zero). There is no CurrentClampStimulusSeries associated with an IZero series because the amplifier is disconnected and no stimulus can reach the cell.


``IZeroClampSeries`` extends ``CurrentClampSeries`` (see :numref:`sec-CurrentClampSeries`) and includes all elements of :ref:`CurrentClampSeries <sec-CurrentClampSeries>` with the following additions or changes.




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-IZeroClampSeries-data:

.. table:: Datasets, Links, and Attributes contained in <IZeroClampSeries>
    :class: longtable

    +----------------------+-------------+------------------------------------------------------------------------------------------------------+
    | Id                   | Type        | Description                                                                                          |
    +======================+=============+======================================================================================================+
    | <IZeroClampSeries>   | group       | Top level group for <IZeroClampSeries>                                                               |
    |                      |             |                                                                                                      |
    |                      |             | - **Extends:** :ref:`CurrentClampSeries <sec-CurrentClampSeries>`                                    |
    |                      |             | - **Neurodata Type:** :ref:`IZeroClampSeries <sec-IZeroClampSeries>`                                 |
    |                      |             |                                                                                                      |
    +----------------------+-------------+------------------------------------------------------------------------------------------------------+
    | .help                | attribute   | Value is 'Voltage from intracellular recordings when all current and amplifier settings are off'     |
    |                      |             |                                                                                                      |
    |                      |             | - **Data Type:** text                                                                                |
    |                      |             | - **Value:** Voltage from intracellular recordings when all current and amplifier settings are off   |
    |                      |             | - **Name:** help                                                                                     |
    |                      |             |                                                                                                      |
    +----------------------+-------------+------------------------------------------------------------------------------------------------------+



