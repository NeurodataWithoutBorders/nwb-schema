.. _sec-SpecFile:

SpecFile
^^^^^^^^

**Source Specification:** see :numref:`sec-SpecFile-src`

**Overview:** Dataset for storing contents of a specification file for either the core format or an extension.  Name should match name of file.`




- **Quantity** 0 or more
- **Data Type:** text


.. figure:: ./_format_auto_docs/SpecFile.*
    :alt: SpecFile




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-SpecFile-data:

.. table:: Datasets, Links, and Attributes contained in <SpecFile>
    :class: longtable

    +---------------+-------------+-------------------------------------------------------+
    | Id            | Type        | Description                                           |
    +===============+=============+=======================================================+
    | <SpecFile>    | dataset     | Top level dataset for <SpecFile>                      |
    +---------------+-------------+-------------------------------------------------------+
    | .help         | attribute   | Value is Contents of format specification file.       |
    |               |             |                                                       |
    |               |             | - **Data Type:** text                                 |
    |               |             | - **Value:** Contents of format specification file.   |
    |               |             |                                                       |
    +---------------+-------------+-------------------------------------------------------+
    | .namespaces   | attribute   | Namespaces defined in the file                        |
    |               |             |                                                       |
    |               |             | - **Data Type:** text                                 |
    |               |             | - **Dimensions:** ['num_namespaces']                  |
    |               |             | - **Shape:** (None,)                                  |
    |               |             |                                                       |
    +---------------+-------------+-------------------------------------------------------+



