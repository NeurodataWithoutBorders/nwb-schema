.. _sec-Image:

Image
^^^^^

**Source Specification:** see :numref:`sec-Image-src`

**Overview:** Photograph of experiment or experimental setup (video also OK). 

**Comment:**  Name is arbitrary.  Data is stored as a single binary object (HDF5 opaque type).




- **Quantity** 0 or more
- **Data Type:** binary


.. figure:: ./_format_auto_docs/Image.*
    :alt: Image




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-Image-data:

.. table:: Datasets, Links, and Attributes contained in <Image>
    :class: longtable

    +----------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------+
    | Id             | Type        | Description                                                                                                                               |
    +================+=============+===========================================================================================================================================+
    | <Image>        | dataset     | Top level dataset for <Image>                                                                                                             |
    +----------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------+
    | .description   | attribute   | Human description of image.                                                                                                               |
    |                |             |                                                                                                                                           |
    |                |             | **Comment:**  If image is of slice data, include slice thickness and orientation, and reference to appropriate entry in /general/slices   |
    |                |             |                                                                                                                                           |
    |                |             | - **Data Type:** text                                                                                                                     |
    |                |             |                                                                                                                                           |
    +----------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------+
    | .format        | attribute   | Format of the image.                                                                                                                      |
    |                |             |                                                                                                                                           |
    |                |             | **Comment:**  eg, jpg, png, mpeg                                                                                                          |
    |                |             |                                                                                                                                           |
    |                |             | - **Data Type:** text                                                                                                                     |
    |                |             |                                                                                                                                           |
    +----------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------+



