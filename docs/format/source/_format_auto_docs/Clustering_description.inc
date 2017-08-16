.. _sec-Clustering:

Clustering
^^^^^^^^^^

**Extends:** :ref:`NWBContainer <sec-NWBContainer>`

**Source Specification:** see :numref:`sec-Clustering-src`

**Overview:** Clustered spike data, whether from automatic clustering tools (e.g., klustakwik) or as a result of manual sorting.


``Clustering`` extends ``NWBContainer`` (see :numref:`sec-NWBContainer`) and includes all elements of :ref:`NWBContainer <sec-NWBContainer>` with the following additions or changes.



- **Default Name:** Clustering


.. figure:: ./_format_auto_docs/Clustering.*
    :alt: Clustering




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-Clustering-data:

.. table:: Datasets, Links, and Attributes contained in <Clustering>
    :class: longtable

    +------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------+
    | Id               | Type        | Description                                                                                                                    |
    +==================+=============+================================================================================================================================+
    | <Clustering>     | group       | Top level group for <Clustering>                                                                                               |
    +------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------+
    | .help            | attribute   | Value is 'Clustered spike data, whether from automatic clustering tools (eg, klustakwik) or as a result of manual sorting'     |
    |                  |             |                                                                                                                                |
    |                  |             | - **Data Type:** text                                                                                                          |
    |                  |             | - **Value:** Clustered spike data, whether from automatic clustering tools (eg, klustakwik) or as a result of manual sorting   |
    |                  |             |                                                                                                                                |
    +------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------+
    | .description     | dataset     | Description of clusters or clustering, (e.g. cluster 0 is noise, clusters curated using Klusters, etc)                         |
    |                  |             |                                                                                                                                |
    |                  |             | - **Data Type:** text                                                                                                          |
    |                  |             |                                                                                                                                |
    +------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------+
    | .num             | dataset     | Cluster number of each event                                                                                                   |
    |                  |             |                                                                                                                                |
    |                  |             | - **Data Type:** int32                                                                                                         |
    |                  |             | - **Dimensions:** ['num_events']                                                                                               |
    |                  |             | - **Shape:** [None]                                                                                                            |
    |                  |             |                                                                                                                                |
    +------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------+
    | .peak_over_rms   | dataset     | Maximum ratio of waveform peak to RMS on any channel in the cluster (provides a basic clustering metric).                      |
    |                  |             |                                                                                                                                |
    |                  |             | - **Data Type:** float32                                                                                                       |
    |                  |             | - **Dimensions:** ['num_clusters']                                                                                             |
    |                  |             | - **Shape:** [None]                                                                                                            |
    |                  |             |                                                                                                                                |
    +------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------+
    | .times           | dataset     | Times of clustered events, in seconds. This may be a link to times field in associated FeatureExtraction module.               |
    |                  |             |                                                                                                                                |
    |                  |             | - **Data Type:** float64!                                                                                                      |
    |                  |             | - **Dimensions:** ['num_events']                                                                                               |
    |                  |             | - **Shape:** [None]                                                                                                            |
    |                  |             |                                                                                                                                |
    +------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------+



