.. _sec-NWBContainer-src:

NWBContainer
^^^^^^^^^^^^

**Description:** see :numref:`sec-NWBContainer`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Short description of what this type of NWBContainer contains.
      dtype: text
      name: help
    - doc: Path to the origin of the data represented in this NWBContainer data container.
      dtype: text
      name: source
    doc: Generic container for storing collections of data. NWBContainer serves as the
      base type for all main data containers of the core NWB data format. The properties
      defined by this type are inherited by all derived types.
    neurodata_type_def: NWBContainer


