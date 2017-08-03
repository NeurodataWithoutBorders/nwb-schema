.. _sec-VoltageClampStimulusSeries-src:

VoltageClampStimulusSeries
^^^^^^^^^^^^^^^^^^^^^^^^^^

**Extends:** :ref:`PatchClampSeries <sec-PatchClampSeries>`

**Description:** see :numref:`sec-VoltageClampStimulusSeries`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Value is 'Stimulus voltage applied during voltage clamp recording'
      dtype: text
      name: help
      value: Stimulus voltage applied during voltage clamp recording
    doc: Aliases to standard PatchClampSeries. Its functionality is to better tag PatchClampSeries
      for machine (and human) readability of the file.
    neurodata_type_def: VoltageClampStimulusSeries
    neurodata_type_inc: PatchClampSeries


