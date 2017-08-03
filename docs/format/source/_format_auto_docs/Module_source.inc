.. _sec-Module-src:

Module
^^^^^^

**Description:** see :numref:`sec-Module`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Description of Module
      dtype: text
      name: description
    - dims:
      - num_interfaces
      doc: 'Names of the data interfaces offered by this module. COMMENT: E.g., [0]="EventDetection",
        [1]="Clustering", [2]="FeatureExtraction"'
      dtype: text
      name: interfaces
      shape:
      - null
    doc: Module.  Name should be descriptive. Stores a collection of related data organized
      by contained interfaces.  Each interface is a contract specifying content related
      to a particular type of data.
    groups:
    - doc: Interface objects containing data output from processing steps
      neurodata_type_inc: Interface
      quantity: '*'
    neurodata_type_def: Module


