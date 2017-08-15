.. _sec-ProcessingModule-src:

ProcessingModule
^^^^^^^^^^^^^^^^

**Extends:** :ref:`NWBContainer <sec-NWBContainer>`

**Description:** see :numref:`sec-ProcessingModule`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Description of Module
      dtype: text
      name: description
    - doc: Value is 'A collection of analysis outputs from processing of data'
      dtype: text
      name: help
      value: A collection of analysis outputs from processing of data
    doc: Module.  Name should be descriptive. Stores a collection of related data organized
      by contained interfaces.  Each interface is a contract specifying content related
      to a particular type of data.
    groups:
    - doc: Interface objects containing data output from processing steps
      neurodata_type_inc: NWBContainer
      quantity: '*'
    neurodata_type_def: ProcessingModule
    neurodata_type_inc: NWBContainer


