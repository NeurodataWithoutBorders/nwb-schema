.. _sec-CurrentClampStimulusSeries-src:

CurrentClampStimulusSeries
^^^^^^^^^^^^^^^^^^^^^^^^^^

**Extends:** :ref:`PatchClampSeries <sec-PatchClampSeries>`

**Description:** see :numref:`sec-CurrentClampStimulusSeries`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Value is Stimulus current applied during current clamp recording
      dtype: text
      name: help
      value: Stimulus current applied during current clamp recording
    doc: Aliases to standard PatchClampSeries. Its functionality is to better tag PatchClampSeries
      for machine (and human) readability of the file.
    neurodata_type_def: CurrentClampStimulusSeries
    neurodata_type_inc: PatchClampSeries


