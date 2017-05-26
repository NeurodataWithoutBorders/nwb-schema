.. _sec-ImagingPlane-src:

ImagingPlane
^^^^^^^^^^^^

**Description:** see :numref:`sec-ImagingPlane`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    datasets:
    - doc: Name of device in /general/devices
      dtype: text
      name: device
    - doc: Description of &lt;image_plane_X&gt;
      dtype: text
      name: description
      quantity: '?'
    - attributes:
      - default_value: 1.0
        doc: Multiplier to get from stored values to specified unit (e.g., 1e-3 for millimeters)
        dtype: float
        name: conversion
      - default_value: Meter
        doc: Base unit that coordinates are stored in (e.g., Meters)
        dtype: text
        name: unit
      dims:
      - height
      - weight
      - x|y|z
      doc: 'Physical position of each pixel. COMMENT: "xyz" represents the position of
        the pixel relative to the defined coordinate space'
      dtype: float32
      name: manifold
      shape:
      - null
      - null
      - 3
    - doc: 'Describes position and reference frame of manifold based on position of first
        element in manifold. For example, text description of anotomical location or vectors
        needed to rotate to common anotomical axis (eg, AP/DV/ML). COMMENT: This field
        is necessary to interpret manifold. If manifold is not present then this field
        is not required'
      dtype: text
      name: reference_frame
    - doc: Calcium indicator
      dtype: text
      name: indicator
    - doc: Location of image plane
      dtype: text
      name: location
    - doc: Rate images are acquired, in Hz.
      dtype: text
      name: imaging_rate
    - doc: Excitation wavelength
      dtype: text
      name: excitation_lambda
    doc: 'One of possibly many groups describing an imaging plane. COMMENT: Name is arbitrary
      but should be meaningful. It is referenced by TwoPhotonSeries and also ImageSegmentation
      and DfOverF interfaces'
    groups:
    - datasets:
      - doc: Any notes or comments about the channel
        dtype: text
        name: description
      - doc: Emission lambda for channel
        dtype: text
        name: emission_lambda
      doc: 'One of possibly many groups storing channel-specific data COMMENT: Name is
        arbitrary but should be meaningful'
      neurodata_type_def: OpticalChannel
    neurodata_type_def: ImagingPlane
    quantity: '*'


