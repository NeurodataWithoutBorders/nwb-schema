.. _sec-ROI:

ROI
^^^

**Source Specification:** see :numref:`sec-ROI-src`

**Overview:** Name of ROI




- **Quantity** 0 or more


.. figure:: ./_format_auto_docs/ROI.*
    :alt: ROI




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-ROI-data:

.. table:: Datasets, Links, and Attributes contained in <ROI>
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



