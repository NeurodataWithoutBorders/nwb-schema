.. _sec-FeatureExtraction:

FeatureExtraction
^^^^^^^^^^^^^^^^^

**Extends:** :ref:`NWBContainer <sec-NWBContainer>`

**Source Specification:** see :numref:`sec-FeatureExtraction-src`

**Overview:** Features, such as PC1 and PC2, that are extracted from signals stored in a SpikeEvent TimeSeries or other source.


``FeatureExtraction`` extends ``NWBContainer`` (see :numref:`sec-NWBContainer`) and includes all elements of :ref:`NWBContainer <sec-NWBContainer>` with the following additions or changes.



- **Default Name:** FeatureExtraction


.. figure:: ./_format_auto_docs/FeatureExtraction.*
    :alt: FeatureExtraction




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-FeatureExtraction-data:

.. table:: Datasets, Links, and Attributes contained in <FeatureExtraction>
    :class: longtable

    +-----------------------+-------------+---------------------------------------------------------------------------+
    | Id                    | Type        | Description                                                               |
    +=======================+=============+===========================================================================+
    | <FeatureExtraction>   | group       | Top level group for <FeatureExtraction>                                   |
    |                       |             |                                                                           |
    |                       |             | - **Extends:** :ref:`NWBContainer <sec-NWBContainer>`                     |
    |                       |             | - **Neurodata Type:** :ref:`FeatureExtraction <sec-FeatureExtraction>`    |
    |                       |             | - **Default Name:** FeatureExtraction                                     |
    |                       |             |                                                                           |
    +-----------------------+-------------+---------------------------------------------------------------------------+
    | .help                 | attribute   | Value is 'Container for salient features of detected events'              |
    |                       |             |                                                                           |
    |                       |             | - **Data Type:** text                                                     |
    |                       |             | - **Value:** Container for salient features of detected events            |
    |                       |             | - **Name:** help                                                          |
    |                       |             |                                                                           |
    +-----------------------+-------------+---------------------------------------------------------------------------+
    | .description          | dataset     | Description of features (eg, "PC1") for each of the extracted features.   |
    |                       |             |                                                                           |
    |                       |             | - **Data Type:** text                                                     |
    |                       |             | - **Dimensions:** ['num_features']                                        |
    |                       |             | - **Shape:** [None]                                                       |
    |                       |             | - **Name:** description                                                   |
    |                       |             |                                                                           |
    +-----------------------+-------------+---------------------------------------------------------------------------+
    | .features             | dataset     | Multi-dimensional array of features extracted from each event.            |
    |                       |             |                                                                           |
    |                       |             | - **Data Type:** float32                                                  |
    |                       |             | - **Dimensions:** ['num_events', 'num_channels', 'num_features']          |
    |                       |             | - **Shape:** [None, None, None]                                           |
    |                       |             | - **Name:** features                                                      |
    |                       |             |                                                                           |
    +-----------------------+-------------+---------------------------------------------------------------------------+
    | .times                | dataset     | Times of events that features correspond to (can be a link).              |
    |                       |             |                                                                           |
    |                       |             | - **Data Type:** float64!                                                 |
    |                       |             | - **Dimensions:** ['num_events']                                          |
    |                       |             | - **Shape:** [None]                                                       |
    |                       |             | - **Name:** times                                                         |
    |                       |             |                                                                           |
    +-----------------------+-------------+---------------------------------------------------------------------------+
    | .electrode_group      | link        | link to ElectrodeGroup group that generated this TimeSeries data          |
    |                       |             |                                                                           |
    |                       |             | - **Target Type** :ref:`ElectrodeGroup <sec-ElectrodeGroup>`              |
    |                       |             | - **Name:** electrode_group                                               |
    |                       |             |                                                                           |
    +-----------------------+-------------+---------------------------------------------------------------------------+




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-FeatureExtraction-groups:

.. table:: Groups contained in <FeatureExtraction>
    :class: longtable

    +-----------------------+---------+--------------------------------------------------------------------------+
    | Id                    | Type    | Description                                                              |
    +=======================+=========+==========================================================================+
    | <FeatureExtraction>   | group   | Top level group for <FeatureExtraction>                                  |
    |                       |         |                                                                          |
    |                       |         | - **Extends:** :ref:`NWBContainer <sec-NWBContainer>`                    |
    |                       |         | - **Neurodata Type:** :ref:`FeatureExtraction <sec-FeatureExtraction>`   |
    |                       |         | - **Default Name:** FeatureExtraction                                    |
    |                       |         |                                                                          |
    +-----------------------+---------+--------------------------------------------------------------------------+
    | .electrode_group      | link    | link to ElectrodeGroup group that generated this TimeSeries data         |
    |                       |         |                                                                          |
    |                       |         | - **Target Type** :ref:`ElectrodeGroup <sec-ElectrodeGroup>`             |
    |                       |         | - **Name:** electrode_group                                              |
    |                       |         |                                                                          |
    +-----------------------+---------+--------------------------------------------------------------------------+


