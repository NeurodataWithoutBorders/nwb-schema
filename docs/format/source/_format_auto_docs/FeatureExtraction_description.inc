.. _sec-FeatureExtraction:

FeatureExtraction
^^^^^^^^^^^^^^^^^

**Extends:** :ref:`Interface <sec-Interface>`

**Source Specification:** see :numref:`sec-FeatureExtraction-src`

**Overview:** Features, such as PC1 and PC2, that are extracted from signals stored in a SpikeEvent TimeSeries or other source.


``FeatureExtraction`` extends ``Interface`` (see :numref:`sec-Interface`) and includes all elements of :ref:`Interface <sec-Interface>` with the following additions or changes.



.. figure:: ./_format_auto_docs/FeatureExtraction.*
    :alt: FeatureExtraction




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-FeatureExtraction-data:

.. table:: Datasets, Links, and Attributes contained in <FeatureExtraction>
    :class: longtable

    +---------------------+-------------+---------------------------------------------------------------------------+
    | Id                  | Type        | Description                                                               |
    +=====================+=============+===========================================================================+
    | FeatureExtraction   | group       | Top level group for FeatureExtraction                                     |
    +---------------------+-------------+---------------------------------------------------------------------------+
    | .help               | attribute   | Value is 'Container for salient features of detected events'              |
    |                     |             |                                                                           |
    |                     |             | - **Data Type:** text                                                     |
    |                     |             | - **Value:** Container for salient features of detected events            |
    |                     |             |                                                                           |
    +---------------------+-------------+---------------------------------------------------------------------------+
    | .times              | dataset     | Times of events that features correspond to (can be a link).              |
    |                     |             |                                                                           |
    |                     |             | - **Data Type:** float64!                                                 |
    |                     |             | - **Dimensions:** ['num_events']                                          |
    |                     |             | - **Shape:** [None]                                                       |
    |                     |             |                                                                           |
    +---------------------+-------------+---------------------------------------------------------------------------+
    | .description        | dataset     | Description of features (eg, "PC1") for each of the extracted features.   |
    |                     |             |                                                                           |
    |                     |             | - **Data Type:** text                                                     |
    |                     |             | - **Dimensions:** ['num_features']                                        |
    |                     |             | - **Shape:** [None]                                                       |
    |                     |             |                                                                           |
    +---------------------+-------------+---------------------------------------------------------------------------+
    | .features           | dataset     | Multi-dimensional array of features extracted from each event.            |
    |                     |             |                                                                           |
    |                     |             | - **Data Type:** float32                                                  |
    |                     |             | - **Dimensions:** ['num_events', 'num_channels', 'num_features']          |
    |                     |             | - **Shape:** [None, None, None]                                           |
    |                     |             |                                                                           |
    +---------------------+-------------+---------------------------------------------------------------------------+
    | .electrode_group    | link        | link to ElectrodeGroup group that generated this TimeSeries data          |
    |                     |             |                                                                           |
    |                     |             | - **Target Type** :ref:`ElectrodeGroup <sec-ElectrodeGroup>`              |
    |                     |             |                                                                           |
    +---------------------+-------------+---------------------------------------------------------------------------+




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-FeatureExtraction-groups:

.. table:: Groups contained in <FeatureExtraction>
    :class: longtable

    +---------------------+---------+--------------------------------------------------------------------+
    | Id                  | Type    | Description                                                        |
    +=====================+=========+====================================================================+
    | FeatureExtraction   | group   | Top level group for FeatureExtraction                              |
    +---------------------+---------+--------------------------------------------------------------------+
    | .electrode_group    | link    | link to ElectrodeGroup group that generated this TimeSeries data   |
    |                     |         |                                                                    |
    |                     |         | - **Target Type** :ref:`ElectrodeGroup <sec-ElectrodeGroup>`       |
    |                     |         |                                                                    |
    +---------------------+---------+--------------------------------------------------------------------+


