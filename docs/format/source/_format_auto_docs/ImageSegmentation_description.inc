.. _sec-ImageSegmentation:

ImageSegmentation
^^^^^^^^^^^^^^^^^

**Extends:** :ref:`Interface <sec-Interface>`

**Source Specification:** see :numref:`sec-ImageSegmentation-src`

**Overview:** Stores pixels in an image that represent different regions of interest (ROIs) or masks. All segmentation for a given imaging plane is stored together, with storage for multiple imaging planes (masks) supported. Each ROI is stored in its own subgroup, with the ROI group containing both a 2D mask and a list of pixels that make up this mask. Segments can also be used for masking neuropil. If segmentation is allowed to change with time, a new imaging plane (or module) is required and ROI names should remain consistent between them.


``ImageSegmentation`` extends ``Interface`` (see :numref:`sec-Interface`) and includes all elements of :ref:`Interface <sec-Interface>` with the following additions or changes.



.. figure:: ./_format_auto_docs/ImageSegmentation.*
    :alt: ImageSegmentation




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-ImageSegmentation-data:

.. table:: Datasets, Links, and Attributes contained in <ImageSegmentation>
    :class: longtable

    +---------------------+-------------+--------------------------------------------------------------------------------------------------------+
    | Id                  | Type        | Description                                                                                            |
    +=====================+=============+========================================================================================================+
    | ImageSegmentation   | group       | Top level group for ImageSegmentation                                                                  |
    +---------------------+-------------+--------------------------------------------------------------------------------------------------------+
    | .help               | attribute   | Value is Stores groups of pixels that define regions of interest from one or more imaging planes       |
    |                     |             |                                                                                                        |
    |                     |             | - **Data Type:** text                                                                                  |
    |                     |             | - **Value:** Stores groups of pixels that define regions of interest from one or more imaging planes   |
    |                     |             |                                                                                                        |
    +---------------------+-------------+--------------------------------------------------------------------------------------------------------+




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-ImageSegmentation-groups:

.. table:: Groups contained in <ImageSegmentation>
    :class: longtable

    +------------------------+---------+----------------------------------------------------------------------------+
    | Id                     | Type    | Description                                                                |
    +========================+=========+============================================================================+
    | ImageSegmentation      | group   | Top level group for ImageSegmentation                                      |
    +------------------------+---------+----------------------------------------------------------------------------+
    | .<PlaneSegmentation>   | group   | Group name is human-readable description of imaging plane                  |
    |                        |         |                                                                            |
    |                        |         | - **Quantity** 0 or more                                                   |
    |                        |         | - **Neurodata Type:** :ref:`PlaneSegmentation <sec-PlaneSegmentation>`     |
    |                        |         |                                                                            |
    +------------------------+---------+----------------------------------------------------------------------------+
    | ..imaging_plane        | link    | link to ImagingPlane group from which this TimeSeries data was generated   |
    |                        |         |                                                                            |
    |                        |         | - **Target Type** :ref:`ImagingPlane <sec-ImagingPlane>`                   |
    |                        |         |                                                                            |
    +------------------------+---------+----------------------------------------------------------------------------+


Groups: <PlaneSegmentation>
"""""""""""""""""""""""""""

Group name is human-readable description of imaging plane



- **Quantity** 0 or more
- **Neurodata Type:** :ref:`PlaneSegmentation <sec-PlaneSegmentation>`


.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. table:: Datasets, Links, and Attributes contained in ``<PlaneSegmentation>``
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
.. table:: Groups contained in <<PlaneSegmentation>>
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
    | .reference_images     | group   | Stores image stacks segmentation mask apply to.                            |
    +-----------------------+---------+----------------------------------------------------------------------------+
    | .<ROI>                | group   | Name of ROI                                                                |
    |                       |         |                                                                            |
    |                       |         | - **Quantity** 0 or more                                                   |
    |                       |         | - **Neurodata Type:** :ref:`ROI <sec-ROI>`                                 |
    |                       |         |                                                                            |
    +-----------------------+---------+----------------------------------------------------------------------------+


Groups: <PlaneSegmentation>/reference_images
""""""""""""""""""""""""""""""""""""""""""""

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


Groups: <PlaneSegmentation>/reference_images/<ImageSeries>
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

One or more image stacks that the masks apply to (can be one-element stack)



- **Extends:** :ref:`ImageSeries <sec-ImageSeries>`

Groups: <PlaneSegmentation>/<ROI>
"""""""""""""""""""""""""""""""""

Name of ROI



- **Quantity** 0 or more
- **Neurodata Type:** :ref:`ROI <sec-ROI>`


.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. table:: Datasets, Links, and Attributes contained in ``<PlaneSegmentation>/<ROI>``
    :class: longtable

    +--------------------+-----------+--------------------------------------------------------+
    | Id                 | Type      | Description                                            |
    +====================+===========+========================================================+
    | <ROI>              | group     | Top level group for <ROI>                              |
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
    | .img_mask          | dataset   | ROI mask, represented in 2D ([y][x]) intensity image   |
    |                    |           |                                                        |
    |                    |           | - **Data Type:** float32                               |
    |                    |           | - **Dimensions:** ['num_x', 'num_y']                   |
    |                    |           | - **Shape:** [None, None]                              |
    |                    |           |                                                        |
    +--------------------+-----------+--------------------------------------------------------+


