.. _sec-OptogeneticStimulusSite-src:

OptogeneticStimulusSite
^^^^^^^^^^^^^^^^^^^^^^^

**Extends:** :ref:`NWBContainer <sec-NWBContainer>`

**Description:** see :numref:`sec-OptogeneticStimulusSite`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Value is 'Metadata about an optogenetic stimulus site'
      dtype: text
      name: help
      value: Metadata about an optogenetic stimulus site
    datasets:
    - doc: Description of site
      dtype: text
      name: description
    - doc: Name of device in /general/devices
      dtype: text
      name: device
    - doc: Excitation wavelength
      dtype: text
      name: excitation_lambda
    - doc: Location of stimulation site
      dtype: text
      name: location
    doc: 'One of possibly many groups describing an optogenetic stimuluation site. COMMENT:
      Name is arbitrary but should be meaningful. Name is referenced by OptogeneticSeries'
    neurodata_type_def: OptogeneticStimulusSite
    neurodata_type_inc: NWBContainer
    quantity: '*'


