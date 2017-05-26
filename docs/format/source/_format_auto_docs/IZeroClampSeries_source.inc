.. _sec-IZeroClampSeries-src:

IZeroClampSeries
^^^^^^^^^^^^^^^^

**Extends:** :ref:`CurrentClampSeries <sec-CurrentClampSeries>`

**Description:** see :numref:`sec-IZeroClampSeries`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Value is 'Voltage from intracellular recordings when all current and amplifier
        settings are off'
      dtype: text
      name: help
      value: Voltage from intracellular recordings when all current and amplifier settings
        are off
    doc: Stores recorded voltage data from intracellular recordings when all current and
      amplifier settings are off (i.e., CurrentClampSeries fields will be zero). There
      is no CurrentClampStimulusSeries associated with an IZero series because the amplifier
      is disconnected and no stimulus can reach the cell.
    neurodata_type_def: IZeroClampSeries
    neurodata_type_inc: CurrentClampSeries


