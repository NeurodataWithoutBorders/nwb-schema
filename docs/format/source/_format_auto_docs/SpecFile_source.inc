.. _sec-SpecFile-src:

SpecFile
^^^^^^^^

**Description:** see :numref:`sec-SpecFile`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - default_value: Contents of format specification file.
      doc: A help statement
      dtype: text
      name: help
    - dims:
      - num_namespaces
      doc: Namespaces defined in the file
      dtype: text
      name: namespaces
      shape:
      - null
    doc: Dataset for storing contents of a specification file for either the core format
      or an extension.  Name should match name of file.`
    dtype: text
    neurodata_type_def: SpecFile
    quantity: '*'


