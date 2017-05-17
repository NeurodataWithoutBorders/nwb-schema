.. _sec-Fluorescence-src:

Fluorescence
^^^^^^^^^^^^

**Extends:** :ref:`Interface <sec-Interface>`

**Description:** see :numref:`sec-Fluorescence`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Value is Fluorescence over time of one or more ROIs. TimeSeries names should
        correspond to imaging plane names
      dtype: text
      name: help
      value: Fluorescence over time of one or more ROIs. TimeSeries names should correspond
        to imaging plane names
    doc: Fluorescence information about a region of interest (ROI). Storage hierarchy
      of fluorescence should be the same as for segmentation (ie, same names for ROIs
      and for image planes).
    groups:
    - doc: RoiResponseSeries object containing fluorescence data for a ROI
      neurodata_type_inc: RoiResponseSeries
    name: Fluorescence
    neurodata_type_def: Fluorescence
    neurodata_type_inc: Interface


