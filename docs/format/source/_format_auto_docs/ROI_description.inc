.. _sec-ROI:

ROI
^^^

**Extends:** :ref:`NWBContainer <sec-NWBContainer>`

**Source Specification:** see :numref:`sec-ROI-src`

**Overview:** Name of ROI


``ROI`` extends ``NWBContainer`` (see :numref:`sec-NWBContainer`) and includes all elements of :ref:`NWBContainer <sec-NWBContainer>` with the following additions or changes.



- **Quantity** 0 or more


.. figure:: ./_format_auto_docs/ROI.*
    :alt: ROI




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-ROI-data:

.. table:: Datasets, Links, and Attributes contained in <ROI>
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



