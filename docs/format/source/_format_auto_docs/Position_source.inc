.. _sec-Position-src:

Position
^^^^^^^^

**Extends:** :ref:`Interface <sec-Interface>`

**Description:** see :numref:`sec-Position`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Value is Position data, whether along the x, xy or xyz axis
      dtype: text
      name: help
      value: Position data, whether along the x, xy or xyz axis
    doc: Position data, whether along the x, x/y or x/y/z axis.
    groups:
    - doc: SpatialSeries object containing position data
      neurodata_type_inc: SpatialSeries
    name: Position
    neurodata_type_def: Position
    neurodata_type_inc: Interface


