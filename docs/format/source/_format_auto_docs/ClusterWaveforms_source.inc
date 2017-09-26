.. _sec-ClusterWaveforms-src:

ClusterWaveforms
^^^^^^^^^^^^^^^^

**Extends:** :ref:`NWBContainer <sec-NWBContainer>`

**Description:** see :numref:`sec-ClusterWaveforms`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Value is 'Mean waveform shape of clusters. Waveforms should be high-pass filtered
        (ie, not the same bandpass filter used waveform analysis and clustering)'
      dtype: text
      name: help
      value: Mean waveform shape of clusters. Waveforms should be high-pass filtered (ie,
        not the same bandpass filter used waveform analysis and clustering)
    datasets:
    - doc: Filtering applied to data before generating mean/sd
      dtype: text
      name: waveform_filtering
    - dims:
      - num_clusters
      - num_samples
      doc: The mean waveform for each cluster, using the same indices for each wave as
        cluster numbers in the associated Clustering module (i.e, cluster 3 is in array
        slot [3]). Waveforms corresponding to gaps in cluster sequence should be empty
        (e.g., zero- filled)
      dtype: float32
      name: waveform_mean
      shape:
      - null
      - null
    - dims:
      - num_clusters
      - num_samples
      doc: Stdev of waveforms for each cluster, using the same indices as in mean
      dtype: float32
      name: waveform_sd
      shape:
      - null
      - null
    default_name: ClusterWaveforms
    doc: The mean waveform shape, including standard deviation, of the different clusters.
      Ideally, the waveform analysis should be performed on data that is only high-pass
      filtered. This is a separate module because it is expected to require updating.
      For example, IMEC probes may require different storage requirements to store/display
      mean waveforms, requiring a new interface or an extension of this one.
    links:
    - doc: HDF5 link to Clustering interface that was the source of the clustered data
      name: clustering_interface
      target_type: Clustering
    neurodata_type_def: ClusterWaveforms
    neurodata_type_inc: NWBContainer


