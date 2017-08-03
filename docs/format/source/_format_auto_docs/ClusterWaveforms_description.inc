.. _sec-ClusterWaveforms:

ClusterWaveforms
^^^^^^^^^^^^^^^^

**Extends:** :ref:`Interface <sec-Interface>`

**Source Specification:** see :numref:`sec-ClusterWaveforms-src`

**Overview:** The mean waveform shape, including standard deviation, of the different clusters. Ideally, the waveform analysis should be performed on data that is only high-pass filtered. This is a separate module because it is expected to require updating. For example, IMEC probes may require different storage requirements to store/display mean waveforms, requiring a new interface or an extension of this one.


``ClusterWaveforms`` extends ``Interface`` (see :numref:`sec-Interface`) and includes all elements of :ref:`Interface <sec-Interface>` with the following additions or changes.



.. figure:: ./_format_auto_docs/ClusterWaveforms.*
    :alt: ClusterWaveforms




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-ClusterWaveforms-data:

.. table:: Datasets, Links, and Attributes contained in <ClusterWaveforms>
    :class: longtable

    +------------------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | Id                           | Type        | Description                                                                                                                                                                                                                                                       |
    +==============================+=============+===================================================================================================================================================================================================================================================================+
    | ClusterWaveforms             | group       | Top level group for ClusterWaveforms                                                                                                                                                                                                                              |
    +------------------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .help                        | attribute   | Value is 'Mean waveform shape of clusters. Waveforms should be high-pass filtered (ie, not the same bandpass filter used waveform analysis and clustering)'                                                                                                       |
    |                              |             |                                                                                                                                                                                                                                                                   |
    |                              |             | - **Data Type:** text                                                                                                                                                                                                                                             |
    |                              |             | - **Value:** Mean waveform shape of clusters. Waveforms should be high-pass filtered (ie, not the same bandpass filter used waveform analysis and clustering)                                                                                                     |
    |                              |             |                                                                                                                                                                                                                                                                   |
    +------------------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .waveform_sd                 | dataset     | Stdev of waveforms for each cluster, using the same indices as in mean                                                                                                                                                                                            |
    |                              |             |                                                                                                                                                                                                                                                                   |
    |                              |             | - **Data Type:** float32                                                                                                                                                                                                                                          |
    |                              |             | - **Dimensions:** ['num_clusters', 'num_samples']                                                                                                                                                                                                                 |
    |                              |             | - **Shape:** [None, None]                                                                                                                                                                                                                                         |
    |                              |             |                                                                                                                                                                                                                                                                   |
    +------------------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .waveform_filtering          | dataset     | Filtering applied to data before generating mean/sd                                                                                                                                                                                                               |
    |                              |             |                                                                                                                                                                                                                                                                   |
    |                              |             | - **Data Type:** text                                                                                                                                                                                                                                             |
    |                              |             |                                                                                                                                                                                                                                                                   |
    +------------------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .clustering_interface_path   | dataset     | Path to linked clustering interface                                                                                                                                                                                                                               |
    |                              |             |                                                                                                                                                                                                                                                                   |
    |                              |             | - **Data Type:** text                                                                                                                                                                                                                                             |
    |                              |             |                                                                                                                                                                                                                                                                   |
    +------------------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .waveform_mean               | dataset     | The mean waveform for each cluster, using the same indices for each wave as cluster numbers in the associated Clustering module (i.e, cluster 3 is in array slot [3]). Waveforms corresponding to gaps in cluster sequence should be empty (e.g., zero- filled)   |
    |                              |             |                                                                                                                                                                                                                                                                   |
    |                              |             | - **Data Type:** float32                                                                                                                                                                                                                                          |
    |                              |             | - **Dimensions:** ['num_clusters', 'num_samples']                                                                                                                                                                                                                 |
    |                              |             | - **Shape:** [None, None]                                                                                                                                                                                                                                         |
    |                              |             |                                                                                                                                                                                                                                                                   |
    +------------------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .clustering_interface        | link        | HDF5 link to Clustering interface that was the source of the clustered data                                                                                                                                                                                       |
    |                              |             |                                                                                                                                                                                                                                                                   |
    |                              |             | - **Target Type** :ref:`Clustering <sec-Clustering>`                                                                                                                                                                                                              |
    |                              |             |                                                                                                                                                                                                                                                                   |
    +------------------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-ClusterWaveforms-groups:

.. table:: Groups contained in <ClusterWaveforms>
    :class: longtable

    +-------------------------+---------+-------------------------------------------------------------------------------+
    | Id                      | Type    | Description                                                                   |
    +=========================+=========+===============================================================================+
    | ClusterWaveforms        | group   | Top level group for ClusterWaveforms                                          |
    +-------------------------+---------+-------------------------------------------------------------------------------+
    | .clustering_interface   | link    | HDF5 link to Clustering interface that was the source of the clustered data   |
    |                         |         |                                                                               |
    |                         |         | - **Target Type** :ref:`Clustering <sec-Clustering>`                          |
    |                         |         |                                                                               |
    +-------------------------+---------+-------------------------------------------------------------------------------+


