.. _sec-DfOverF-src:

DfOverF
^^^^^^^

**Extends:** :ref:`Interface <sec-Interface>`

**Description:** see :numref:`sec-DfOverF`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Value is Df/f over time of one or more ROIs. TimeSeries names should correspond
        to imaging plane names
      dtype: text
      name: help
      value: Df/f over time of one or more ROIs. TimeSeries names should correspond to
        imaging plane names
    doc: dF/F information about a region of interest (ROI). Storage hierarchy of dF/F
      should be the same as for segmentation (ie, same names for ROIs and for image planes).
    groups:
    - doc: RoiResponseSeries object containing dF/F for a ROI
      neurodata_type_inc: RoiResponseSeries
    name: DfOverF
    neurodata_type_def: DfOverF
    neurodata_type_inc: Interface


