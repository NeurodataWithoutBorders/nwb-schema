.. _sec-OptogeneticSeries-src:

OptogeneticSeries
^^^^^^^^^^^^^^^^^

**Extends:** :ref:`TimeSeries <sec-TimeSeries>`

**Description:** see :numref:`sec-OptogeneticSeries`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Value is Optogenetic stimulus
      dtype: text
      name: help
      value: Optogenetic stimulus
    datasets:
    - attributes:
      - doc: Value is watt
        dtype: text
        name: unit
        value: watt
      dims:
      - num_times
      doc: Applied power for optogenetic stimulus.
      dtype: float32
      name: data
      shape:
      - null
    doc: Optogenetic stimulus.  The data[] field is in unit of watts.
    links:
    - doc: link to OptogeneticStimulusSite group that describes the site to which this
        stimulus was applied
      name: site
      target_type: OptogeneticStimulusSite
    neurodata_type_def: OptogeneticSeries
    neurodata_type_inc: TimeSeries


