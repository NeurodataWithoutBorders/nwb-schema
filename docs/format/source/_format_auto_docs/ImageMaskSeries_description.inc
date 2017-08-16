.. _sec-ImageMaskSeries:

ImageMaskSeries
^^^^^^^^^^^^^^^

**Extends:** :ref:`ImageSeries <sec-ImageSeries>`

**Source Specification:** see :numref:`sec-ImageMaskSeries-src`

**Overview:** An alpha mask that is applied to a presented visual stimulus. The data[] array contains an array of mask values that are applied to the displayed image. Mask values are stored as RGBA. Mask can vary with time. The timestamps array indicates the starting time of a mask, and that mask pattern continues until it's explicitly changed.


``ImageMaskSeries`` extends ``ImageSeries`` (see :numref:`sec-ImageSeries`) and includes all elements of :ref:`ImageSeries <sec-ImageSeries>` with the following additions or changes.



.. figure:: ./_format_auto_docs/ImageMaskSeries.*
    :alt: ImageMaskSeries




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-ImageMaskSeries-data:

.. table:: Datasets, Links, and Attributes contained in <ImageMaskSeries>
    :class: longtable

    +-----------------------+-------------+-----------------------------------------------------------------------------+
    | Id                    | Type        | Description                                                                 |
    +=======================+=============+=============================================================================+
    | <ImageMaskSeries>     | group       | Top level group for <ImageMaskSeries>                                       |
    |                       |             |                                                                             |
    |                       |             | - **Extends:** :ref:`ImageSeries <sec-ImageSeries>`                         |
    |                       |             | - **Neurodata Type:** :ref:`ImageMaskSeries <sec-ImageMaskSeries>`          |
    |                       |             |                                                                             |
    +-----------------------+-------------+-----------------------------------------------------------------------------+
    | .help                 | attribute   | Value is 'An alpha mask that is applied to a presented visual stimulus'     |
    |                       |             |                                                                             |
    |                       |             | - **Data Type:** text                                                       |
    |                       |             | - **Value:** An alpha mask that is applied to a presented visual stimulus   |
    |                       |             | - **Name:** help                                                            |
    |                       |             |                                                                             |
    +-----------------------+-------------+-----------------------------------------------------------------------------+
    | .masked_imageseries   | link        | Link to ImageSeries that mask is applied to.                                |
    |                       |             |                                                                             |
    |                       |             | - **Target Type** :ref:`ImageSeries <sec-ImageSeries>`                      |
    |                       |             | - **Name:** masked_imageseries                                              |
    |                       |             |                                                                             |
    +-----------------------+-------------+-----------------------------------------------------------------------------+




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-ImageMaskSeries-groups:

.. table:: Groups contained in <ImageMaskSeries>
    :class: longtable

    +-----------------------+---------+----------------------------------------------------------------------+
    | Id                    | Type    | Description                                                          |
    +=======================+=========+======================================================================+
    | <ImageMaskSeries>     | group   | Top level group for <ImageMaskSeries>                                |
    |                       |         |                                                                      |
    |                       |         | - **Extends:** :ref:`ImageSeries <sec-ImageSeries>`                  |
    |                       |         | - **Neurodata Type:** :ref:`ImageMaskSeries <sec-ImageMaskSeries>`   |
    |                       |         |                                                                      |
    +-----------------------+---------+----------------------------------------------------------------------+
    | .masked_imageseries   | link    | Link to ImageSeries that mask is applied to.                         |
    |                       |         |                                                                      |
    |                       |         | - **Target Type** :ref:`ImageSeries <sec-ImageSeries>`               |
    |                       |         | - **Name:** masked_imageseries                                       |
    |                       |         |                                                                      |
    +-----------------------+---------+----------------------------------------------------------------------+


