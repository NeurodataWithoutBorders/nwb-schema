.. _sec-PlaneSegmentation:

PlaneSegmentation
^^^^^^^^^^^^^^^^^

**Extends:** :ref:`NWBContainer <sec-NWBContainer>`

**Source Specification:** see :numref:`sec-PlaneSegmentation-src`

**Overview:** Group name is human-readable description of imaging plane


``PlaneSegmentation`` extends ``NWBContainer`` (see :numref:`sec-NWBContainer`) and includes all elements of :ref:`NWBContainer <sec-NWBContainer>` with the following additions or changes.



- **Quantity** 0 or more


.. figure:: ./_format_auto_docs/PlaneSegmentation.*
    :alt: PlaneSegmentation




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-PlaneSegmentation-data:

.. table:: Datasets, Links, and Attributes contained in <PlaneSegmentation>
    :class: longtable

    +-----------------------+-------------+----------------------------------------------------------------------------+
    | Id                    | Type        | Description                                                                |
    +=======================+=============+============================================================================+
    | <PlaneSegmentation>   | group       | Top level group for <PlaneSegmentation>                                    |
    |                       |             |                                                                            |
    |                       |             | - **Quantity** 0 or more                                                   |
    |                       |             | - **Extends:** :ref:`NWBContainer <sec-NWBContainer>`                      |
    |                       |             | - **Neurodata Type:** :ref:`PlaneSegmentation <sec-PlaneSegmentation>`     |
    |                       |             |                                                                            |
    +-----------------------+-------------+----------------------------------------------------------------------------+
    | .help                 | attribute   | Value is 'Results from segmentation of an imaging plane'                   |
    |                       |             |                                                                            |
    |                       |             | - **Data Type:** text                                                      |
    |                       |             | - **Value:** Results from segmentation of an imaging plane                 |
    |                       |             | - **Name:** help                                                           |
    |                       |             |                                                                            |
    +-----------------------+-------------+----------------------------------------------------------------------------+
    | .description          | dataset     | Description of image plane, recording wavelength, depth, etc               |
    |                       |             |                                                                            |
    |                       |             | - **Quantity** 0 or 1                                                      |
    |                       |             | - **Data Type:** text                                                      |
    |                       |             | - **Name:** description                                                    |
    |                       |             |                                                                            |
    +-----------------------+-------------+----------------------------------------------------------------------------+
    | .imaging_plane        | link        | link to ImagingPlane group from which this TimeSeries data was generated   |
    |                       |             |                                                                            |
    |                       |             | - **Target Type** :ref:`ImagingPlane <sec-ImagingPlane>`                   |
    |                       |             | - **Name:** imaging_plane                                                  |
    |                       |             |                                                                            |
    +-----------------------+-------------+----------------------------------------------------------------------------+




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-PlaneSegmentation-groups:

.. table:: Groups contained in <PlaneSegmentation>
    :class: longtable

    +-----------------------+---------+----------------------------------------------------------------------------+
    | Id                    | Type    | Description                                                                |
    +=======================+=========+============================================================================+
    | <PlaneSegmentation>   | group   | Top level group for <PlaneSegmentation>                                    |
    |                       |         |                                                                            |
    |                       |         | - **Quantity** 0 or more                                                   |
    |                       |         | - **Extends:** :ref:`NWBContainer <sec-NWBContainer>`                      |
    |                       |         | - **Neurodata Type:** :ref:`PlaneSegmentation <sec-PlaneSegmentation>`     |
    |                       |         |                                                                            |
    +-----------------------+---------+----------------------------------------------------------------------------+
    | .imaging_plane        | link    | link to ImagingPlane group from which this TimeSeries data was generated   |
    |                       |         |                                                                            |
    |                       |         | - **Target Type** :ref:`ImagingPlane <sec-ImagingPlane>`                   |
    |                       |         | - **Name:** imaging_plane                                                  |
    |                       |         |                                                                            |
    +-----------------------+---------+----------------------------------------------------------------------------+
    | .<ROI>                | group   | Name of ROI                                                                |
    |                       |         |                                                                            |
    |                       |         | - **Quantity** 0 or more                                                   |
    |                       |         | - **Extends:** :ref:`NWBContainer <sec-NWBContainer>`                      |
    |                       |         | - **Neurodata Type:** :ref:`ROI <sec-ROI>`                                 |
    |                       |         |                                                                            |
    +-----------------------+---------+----------------------------------------------------------------------------+
    | .reference_images     | group   | Stores image stacks segmentation mask apply to.                            |
    |                       |         |                                                                            |
    |                       |         | - **Name:** reference_images                                               |
    |                       |         |                                                                            |
    +-----------------------+---------+----------------------------------------------------------------------------+


Groups: <ROI>
"""""""""""""

Name of ROI



- **Quantity** 0 or more
- **Extends:** :ref:`NWBContainer <sec-NWBContainer>`
- **Neurodata Type:** :ref:`ROI <sec-ROI>`


.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. table:: Datasets, Links, and Attributes contained in ``<ROI>``
    :class: longtable

    +--------------------+-------------+------------------------------------------------------------------------+
    | Id                 | Type        | Description                                                            |
    +====================+=============+========================================================================+
    | <ROI>              | group       | Top level group for <ROI>                                              |
    |                    |             |                                                                        |
    |                    |             | - **Quantity** 0 or more                                               |
    |                    |             | - **Extends:** :ref:`NWBContainer <sec-NWBContainer>`                  |
    |                    |             | - **Neurodata Type:** :ref:`ROI <sec-ROI>`                             |
    |                    |             |                                                                        |
    +--------------------+-------------+------------------------------------------------------------------------+
    | .help              | attribute   | Value is 'Region of interest, as determined by image segmentation'     |
    |                    |             |                                                                        |
    |                    |             | - **Data Type:** text                                                  |
    |                    |             | - **Value:** Region of interest, as determined by image segmentation   |
    |                    |             | - **Name:** help                                                       |
    |                    |             |                                                                        |
    +--------------------+-------------+------------------------------------------------------------------------+
    | .img_mask          | dataset     | ROI mask, represented in 2D ([y][x]) intensity image                   |
    |                    |             |                                                                        |
    |                    |             | - **Data Type:** float32                                               |
    |                    |             | - **Dimensions:** ['num_x', 'num_y']                                   |
    |                    |             | - **Shape:** [None, None]                                              |
    |                    |             | - **Name:** img_mask                                                   |
    |                    |             |                                                                        |
    +--------------------+-------------+------------------------------------------------------------------------+
    | .pix_mask          | dataset     | List of pixels (x,y) that compose the mask                             |
    |                    |             |                                                                        |
    |                    |             | - **Data Type:** uint16                                                |
    |                    |             | - **Dimensions:** ['num_pixels', '2']                                  |
    |                    |             | - **Shape:** [None, None]                                              |
    |                    |             | - **Name:** pix_mask                                                   |
    |                    |             |                                                                        |
    +--------------------+-------------+------------------------------------------------------------------------+
    | .pix_mask_weight   | dataset     | Weight of each pixel listed in pix_mask                                |
    |                    |             |                                                                        |
    |                    |             | - **Data Type:** float32                                               |
    |                    |             | - **Dimensions:** ['num_pixels']                                       |
    |                    |             | - **Shape:** [None]                                                    |
    |                    |             | - **Name:** pix_mask_weight                                            |
    |                    |             |                                                                        |
    +--------------------+-------------+------------------------------------------------------------------------+
    | .roi_description   | dataset     | Description of this ROI.                                               |
    |                    |             |                                                                        |
    |                    |             | - **Data Type:** text                                                  |
    |                    |             | - **Name:** roi_description                                            |
    |                    |             |                                                                        |
    +--------------------+-------------+------------------------------------------------------------------------+


Groups: reference_images
""""""""""""""""""""""""

Stores image stacks segmentation mask apply to.



- **Name:** reference_images


.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. table:: Groups contained in <reference_images>
    :class: longtable

    +-------------------------------------------+---------+-------------------------------------------------------------------------------+
    | Id                                        | Type    | Description                                                                   |
    +===========================================+=========+===============================================================================+
    | reference_images                          | group   | Top level group for reference_images                                          |
    |                                           |         |                                                                               |
    |                                           |         | - **Name:** reference_images                                                  |
    |                                           |         |                                                                               |
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

