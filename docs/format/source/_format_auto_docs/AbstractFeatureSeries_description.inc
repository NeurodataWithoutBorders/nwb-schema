.. _sec-AbstractFeatureSeries:

AbstractFeatureSeries
^^^^^^^^^^^^^^^^^^^^^

**Extends:** :ref:`TimeSeries <sec-TimeSeries>`

**Source Specification:** see :numref:`sec-AbstractFeatureSeries-src`

**Overview:** Abstract features, such as quantitative descriptions of sensory stimuli. The TimeSeries::data field is a 2D array, storing those features (e.g., for visual grating stimulus this might be orientation, spatial frequency and contrast). Null stimuli (eg, uniform gray) can be marked as being an independent feature (eg, 1.0 for gray, 0.0 for actual stimulus) or by storing NaNs for feature values, or through use of the TimeSeries::control fields. A set of features is considered to persist until the next set of features is defined. The final set of features stored should be the null set.


``AbstractFeatureSeries`` extends ``TimeSeries`` (see :numref:`sec-TimeSeries`) and includes all elements of :ref:`TimeSeries <sec-TimeSeries>` with the following additions or changes.



.. figure:: ./_format_auto_docs/AbstractFeatureSeries.*
    :alt: AbstractFeatureSeries




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-AbstractFeatureSeries-data:

.. table:: Datasets, Links, and Attributes contained in <AbstractFeatureSeries>
    :class: longtable

    +---------------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | Id                        | Type        | Description                                                                                                                                                                                                                    |
    +===========================+=============+================================================================================================================================================================================================================================+
    | <AbstractFeatureSeries>   | group       | Top level group for <AbstractFeatureSeries>                                                                                                                                                                                    |
    +---------------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .help                     | attribute   | Value is 'Features of an applied stimulus. This is useful when storing the raw stimulus is impractical'                                                                                                                        |
    |                           |             |                                                                                                                                                                                                                                |
    |                           |             | - **Data Type:** text                                                                                                                                                                                                          |
    |                           |             | - **Value:** Features of an applied stimulus. This is useful when storing the raw stimulus is impractical                                                                                                                      |
    |                           |             |                                                                                                                                                                                                                                |
    +---------------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .feature_units            | dataset     | Units of each feature.                                                                                                                                                                                                         |
    |                           |             |                                                                                                                                                                                                                                |
    |                           |             | - **Quantity** 0 or 1                                                                                                                                                                                                          |
    |                           |             | - **Data Type:** text                                                                                                                                                                                                          |
    |                           |             | - **Dimensions:** ['num_features']                                                                                                                                                                                             |
    |                           |             | - **Shape:** [None]                                                                                                                                                                                                            |
    |                           |             |                                                                                                                                                                                                                                |
    +---------------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .features                 | dataset     | Description of the features represented in TimeSeries::data.                                                                                                                                                                   |
    |                           |             |                                                                                                                                                                                                                                |
    |                           |             | - **Data Type:** text                                                                                                                                                                                                          |
    |                           |             | - **Dimensions:** ['num_features']                                                                                                                                                                                             |
    |                           |             | - **Shape:** [None]                                                                                                                                                                                                            |
    |                           |             |                                                                                                                                                                                                                                |
    +---------------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .data                     | dataset     | Values of each feature at each time.                                                                                                                                                                                           |
    |                           |             |                                                                                                                                                                                                                                |
    |                           |             | - **Data Type:** float32                                                                                                                                                                                                       |
    |                           |             | - **Dimensions:** ['num_times', 'num_features']                                                                                                                                                                                |
    |                           |             | - **Shape:** [None, None]                                                                                                                                                                                                      |
    |                           |             |                                                                                                                                                                                                                                |
    +---------------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..unit                    | attribute   | The base unit of measure used to store data. This should be in the SI unit.                                                                                                                                                    |
    |                           |             |                                                                                                                                                                                                                                |
    |                           |             | **Comment:**  This is the SI unit (when appropriate) of the stored data, such as Volts. If the actual data is stored in millivolts, the field 'conversion' below describes how to convert the data to the specified SI unit.   |
    |                           |             |                                                                                                                                                                                                                                |
    |                           |             | - **Data Type:** None                                                                                                                                                                                                          |
    |                           |             | - **Default Value:** see 'feature_units'                                                                                                                                                                                       |
    |                           |             |                                                                                                                                                                                                                                |
    +---------------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+



