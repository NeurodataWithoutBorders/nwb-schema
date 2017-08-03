.. _sec-PlaneSegmentation:

PlaneSegmentation
^^^^^^^^^^^^^^^^^

**Source Specification:** see :numref:`sec-PlaneSegmentation-src`

**Overview:** Group name is human-readable description of imaging plane




- **Quantity** 0 or more


.. figure:: ./_format_auto_docs/PlaneSegmentation.*
    :alt: PlaneSegmentation




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-PlaneSegmentation-data:

.. table:: Datasets, Links, and Attributes contained in <PlaneSegmentation>
    :class: longtable

    +-----------------------+-----------+----------------------------------------------------------------------------+
    | Id                    | Type      | Description                                                                |
    +=======================+===========+============================================================================+
    | <PlaneSegmentation>   | group     | Top level group for <PlaneSegmentation>                                    |
    +-----------------------+-----------+----------------------------------------------------------------------------+
    | .description          | dataset   | Description of image plane, recording wavelength, depth, etc               |
    |                       |           |                                                                            |
    |                       |           | - **Quantity** 0 or 1                                                      |
    |                       |           | - **Data Type:** text                                                      |
    |                       |           |                                                                            |
    +-----------------------+-----------+----------------------------------------------------------------------------+
    | .roi_list             | dataset   | List of ROIs in this imaging plane                                         |
    |                       |           |                                                                            |
    |                       |           | - **Data Type:** text                                                      |
    |                       |           | - **Dimensions:** ['num_rois']                                             |
    |                       |           | - **Shape:** [None]                                                        |
    |                       |           |                                                                            |
    +-----------------------+-----------+----------------------------------------------------------------------------+
    | .imaging_plane        | link      | link to ImagingPlane group from which this TimeSeries data was generated   |
    |                       |           |                                                                            |
    |                       |           | - **Target Type** :ref:`ImagingPlane <sec-ImagingPlane>`                   |
    |                       |           |                                                                            |
    +-----------------------+-----------+----------------------------------------------------------------------------+




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-PlaneSegmentation-groups:

.. table:: Groups contained in <PlaneSegmentation>
    :class: longtable

    +-----------------------+---------+----------------------------------------------------------------------------+
    | Id                    | Type    | Description                                                                |
    +=======================+=========+============================================================================+
    | <PlaneSegmentation>   | group   | Top level group for <PlaneSegmentation>                                    |
    +-----------------------+---------+----------------------------------------------------------------------------+
    | .imaging_plane        | link    | link to ImagingPlane group from which this TimeSeries data was generated   |
    |                       |         |                                                                            |
    |                       |         | - **Target Type** :ref:`ImagingPlane <sec-ImagingPlane>`                   |
    |                       |         |                                                                            |
    +-----------------------+---------+----------------------------------------------------------------------------+
    | .<ROI>                | group   | Name of ROI                                                                |
    |                       |         |                                                                            |
    |                       |         | - **Quantity** 0 or more                                                   |
    |                       |         | - **Neurodata Type:** :ref:`ROI <sec-ROI>`                                 |
    |                       |         |                                                                            |
    +-----------------------+---------+----------------------------------------------------------------------------+
    | .reference_images     | group   | Stores image stacks segmentation mask apply to.                            |
    +-----------------------+---------+----------------------------------------------------------------------------+


Groups: <ROI>
"""""""""""""

Name of ROI



- **Quantity** 0 or more
- **Neurodata Type:** :ref:`ROI <sec-ROI>`


.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. table:: Datasets, Links, and Attributes contained in ``<ROI>``
    :class: longtable

    +--------------------+-----------+--------------------------------------------------------+
    | Id                 | Type      | Description                                            |
    +====================+===========+========================================================+
    | <ROI>              | group     | Top level group for <ROI>                              |
    +--------------------+-----------+--------------------------------------------------------+
    | .img_mask          | dataset   | ROI mask, represented in 2D ([y][x]) intensity image   |
    |                    |           |                                                        |
    |                    |           | - **Data Type:** float32                               |
    |                    |           | - **Dimensions:** ['num_x', 'num_y']                   |
    |                    |           | - **Shape:** [None, None]                              |
    |                    |           |                                                        |
    +--------------------+-----------+--------------------------------------------------------+
    | .pix_mask          | dataset   | List of pixels (x,y) that compose the mask             |
    |                    |           |                                                        |
    |                    |           | - **Data Type:** uint16                                |
    |                    |           | - **Dimensions:** ['num_pixels', '2']                  |
    |                    |           | - **Shape:** [None, None]                              |
    |                    |           |                                                        |
    +--------------------+-----------+--------------------------------------------------------+
    | .pix_mask_weight   | dataset   | Weight of each pixel listed in pix_mask                |
    |                    |           |                                                        |
    |                    |           | - **Data Type:** float32                               |
    |                    |           | - **Dimensions:** ['num_pixels']                       |
    |                    |           | - **Shape:** [None]                                    |
    |                    |           |                                                        |
    +--------------------+-----------+--------------------------------------------------------+
    | .roi_description   | dataset   | Description of this ROI.                               |
    |                    |           |                                                        |
    |                    |           | - **Data Type:** text                                  |
    |                    |           |                                                        |
    +--------------------+-----------+--------------------------------------------------------+


Groups: reference_images
""""""""""""""""""""""""

Stores image stacks segmentation mask apply to.



.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. table:: Groups contained in <reference_images>
    :class: longtable

    +-------------------------------------------+---------+-------------------------------------------------------------------------------+
    | Id                                        | Type    | Description                                                                   |
    +===========================================+=========+===============================================================================+
    | reference_images                          | group   | Top level group for reference_images                                          |
    +-------------------------------------------+---------+-------------------------------------------------------------------------------+
    | .<:ref:`ImageSeries <sec-ImageSeries>`>   | group   | One or more image stacks that the masks apply to (can be one-element stack)   |
    |                                           |         |                                                                               |
    |                                           |         | - **Extends:** :ref:`ImageSeries <sec-ImageSeries>`                           |
    |                                           |         |                                                                               |
    +-------------------------------------------+---------+-------------------------------------------------------------------------------+


Groups: reference_images/<ImageSeries>
""""""""""""""""""""""""""""""""""""""

One or more image stacks that the masks apply to (can be one-element stack)



- **Extends:** :ref:`ImageSeries <sec-ImageSeries>`

