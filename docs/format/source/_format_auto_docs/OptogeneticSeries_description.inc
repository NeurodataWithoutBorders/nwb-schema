.. _sec-OptogeneticSeries:

OptogeneticSeries
^^^^^^^^^^^^^^^^^

**Extends:** :ref:`TimeSeries <sec-TimeSeries>`

**Source Specification:** see :numref:`sec-OptogeneticSeries-src`

**Overview:** Optogenetic stimulus.  The data[] field is in unit of watts.


``OptogeneticSeries`` extends ``TimeSeries`` (see :numref:`sec-TimeSeries`) and includes all elements of :ref:`TimeSeries <sec-TimeSeries>` with the following additions or changes.



.. figure:: ./_format_auto_docs/OptogeneticSeries.*
    :alt: OptogeneticSeries




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-OptogeneticSeries-data:

.. table:: Datasets, Links, and Attributes contained in <OptogeneticSeries>
    :class: longtable

    +-----------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | Id                    | Type        | Description                                                                                                                                                                                                                    |
    +=======================+=============+================================================================================================================================================================================================================================+
    | <OptogeneticSeries>   | group       | Top level group for <OptogeneticSeries>                                                                                                                                                                                        |
    +-----------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .help                 | attribute   | Value is 'Optogenetic stimulus'                                                                                                                                                                                                |
    |                       |             |                                                                                                                                                                                                                                |
    |                       |             | - **Data Type:** text                                                                                                                                                                                                          |
    |                       |             | - **Value:** Optogenetic stimulus                                                                                                                                                                                              |
    |                       |             |                                                                                                                                                                                                                                |
    +-----------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .data                 | dataset     | Applied power for optogenetic stimulus.                                                                                                                                                                                        |
    |                       |             |                                                                                                                                                                                                                                |
    |                       |             | - **Data Type:** float32                                                                                                                                                                                                       |
    |                       |             | - **Dimensions:** ['num_times']                                                                                                                                                                                                |
    |                       |             | - **Shape:** [None]                                                                                                                                                                                                            |
    |                       |             |                                                                                                                                                                                                                                |
    +-----------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..unit                | attribute   | The base unit of measure used to store data. This should be in the SI unit.                                                                                                                                                    |
    |                       |             |                                                                                                                                                                                                                                |
    |                       |             | **Comment:**  This is the SI unit (when appropriate) of the stored data, such as Volts. If the actual data is stored in millivolts, the field 'conversion' below describes how to convert the data to the specified SI unit.   |
    |                       |             |                                                                                                                                                                                                                                |
    |                       |             | - **Data Type:** text                                                                                                                                                                                                          |
    |                       |             | - **Default Value:** watt                                                                                                                                                                                                      |
    |                       |             |                                                                                                                                                                                                                                |
    +-----------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .site                 | link        | link to OptogeneticStimulusSite group that describes the site to which this stimulus was applied                                                                                                                               |
    |                       |             |                                                                                                                                                                                                                                |
    |                       |             | - **Target Type** :ref:`OptogeneticStimulusSite <sec-OptogeneticStimulusSite>`                                                                                                                                                 |
    |                       |             |                                                                                                                                                                                                                                |
    +-----------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-OptogeneticSeries-groups:

.. table:: Groups contained in <OptogeneticSeries>
    :class: longtable

    +-----------------------+---------+----------------------------------------------------------------------------------------------------+
    | Id                    | Type    | Description                                                                                        |
    +=======================+=========+====================================================================================================+
    | <OptogeneticSeries>   | group   | Top level group for <OptogeneticSeries>                                                            |
    +-----------------------+---------+----------------------------------------------------------------------------------------------------+
    | .site                 | link    | link to OptogeneticStimulusSite group that describes the site to which this stimulus was applied   |
    |                       |         |                                                                                                    |
    |                       |         | - **Target Type** :ref:`OptogeneticStimulusSite <sec-OptogeneticStimulusSite>`                     |
    |                       |         |                                                                                                    |
    +-----------------------+---------+----------------------------------------------------------------------------------------------------+


