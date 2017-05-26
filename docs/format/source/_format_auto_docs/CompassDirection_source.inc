.. _sec-CompassDirection-src:

CompassDirection
^^^^^^^^^^^^^^^^

**Extends:** :ref:`Interface <sec-Interface>`

**Description:** see :numref:`sec-CompassDirection`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Value is 'Direction as measured radially. Spatial series reference frame should
        indicate which direction corresponds to zero and what is the direction of positive
        rotation'
      dtype: text
      name: help
      value: Direction as measured radially. Spatial series reference frame should indicate
        which direction corresponds to zero and what is the direction of positive rotation
    doc: With a CompassDirection interface, a module publishes a SpatialSeries object
      representing a floating point value for theta. The SpatialSeries::reference_frame
      field should indicate what direction corresponds to 0 and which is the direction
      of rotation (this should be clockwise). The si_unit for the SpatialSeries should
      be radians or degrees.
    groups:
    - doc: SpatialSeries object containing direction of gaze travel
      neurodata_type_inc: SpatialSeries
      quantity: '*'
    name: CompassDirection
    neurodata_type_def: CompassDirection
    neurodata_type_inc: Interface


