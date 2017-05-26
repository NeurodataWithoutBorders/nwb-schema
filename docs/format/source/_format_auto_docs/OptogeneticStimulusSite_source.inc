.. _sec-OptogeneticStimulusSite-src:

OptogeneticStimulusSite
^^^^^^^^^^^^^^^^^^^^^^^

**Description:** see :numref:`sec-OptogeneticStimulusSite`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    datasets:
    - doc: Name of device in /general/devices
      dtype: text
      name: device
    - doc: Location of stimulation site
      dtype: text
      name: location
    - doc: Description of site
      dtype: text
      name: description
    - doc: Excitation wavelength
      dtype: text
      name: excitation_lambda
    doc: 'One of possibly many groups describing an optogenetic stimuluation site. COMMENT:
      Name is arbitrary but should be meaningful. Name is referenced by OptogeneticSeries'
    neurodata_type_def: OptogeneticStimulusSite
    quantity: '*'


