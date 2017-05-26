.. _sec-AbstractFeatureSeries-src:

AbstractFeatureSeries
^^^^^^^^^^^^^^^^^^^^^

**Extends:** :ref:`TimeSeries <sec-TimeSeries>`

**Description:** see :numref:`sec-AbstractFeatureSeries`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Value is 'Features of an applied stimulus. This is useful when storing the
        raw stimulus is impractical'
      dtype: text
      name: help
      value: Features of an applied stimulus. This is useful when storing the raw stimulus
        is impractical
    datasets:
    - dims:
      - num_features
      doc: Units of each feature.
      dtype: text
      name: feature_units
      quantity: '?'
      shape:
      - null
    - dims:
      - num_features
      doc: Description of the features represented in TimeSeries::data.
      dtype: text
      name: features
      shape:
      - null
    - attributes:
      - default_value: see 'feature_units'
        doc: "The base unit of measure used to store data. This should be in the SI unit.\
          \ COMMENT: This is the SI unit (when appropriate) of the stored data, such as\
          \ Volts. If the actual data is stored in millivolts, the field 'conversion'\
          \ below describes how to convert the data to the specified SI unit."
        dtype: None
        name: unit
      dims:
      - num_times
      - num_features
      doc: Values of each feature at each time.
      dtype: float32
      name: data
      shape:
      - null
      - null
    doc: Abstract features, such as quantitative descriptions of sensory stimuli. The
      TimeSeries::data field is a 2D array, storing those features (e.g., for visual grating
      stimulus this might be orientation, spatial frequency and contrast). Null stimuli
      (eg, uniform gray) can be marked as being an independent feature (eg, 1.0 for gray,
      0.0 for actual stimulus) or by storing NaNs for feature values, or through use of
      the TimeSeries::control fields. A set of features is considered to persist until
      the next set of features is defined. The final set of features stored should be
      the null set.
    neurodata_type_def: AbstractFeatureSeries
    neurodata_type_inc: TimeSeries


