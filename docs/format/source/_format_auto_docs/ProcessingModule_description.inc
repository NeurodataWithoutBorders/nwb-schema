.. _sec-ProcessingModule:

ProcessingModule
^^^^^^^^^^^^^^^^

**Extends:** :ref:`NWBContainer <sec-NWBContainer>`

**Source Specification:** see :numref:`sec-ProcessingModule-src`

**Overview:** Module.  Name should be descriptive. Stores a collection of related data organized by contained interfaces.  Each interface is a contract specifying content related to a particular type of data.


``ProcessingModule`` extends ``NWBContainer`` (see :numref:`sec-NWBContainer`) and includes all elements of :ref:`NWBContainer <sec-NWBContainer>` with the following additions or changes.



.. figure:: ./_format_auto_docs/ProcessingModule.*
    :alt: ProcessingModule




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-ProcessingModule-data:

.. table:: Datasets, Links, and Attributes contained in <ProcessingModule>
    :class: longtable

    +----------------------+-------------+-------------------------------------------------------------------------+
    | Id                   | Type        | Description                                                             |
    +======================+=============+=========================================================================+
    | <ProcessingModule>   | group       | Top level group for <ProcessingModule>                                  |
    |                      |             |                                                                         |
    |                      |             | - **Extends:** :ref:`NWBContainer <sec-NWBContainer>`                   |
    |                      |             | - **Neurodata Type:** :ref:`ProcessingModule <sec-ProcessingModule>`    |
    |                      |             |                                                                         |
    +----------------------+-------------+-------------------------------------------------------------------------+
    | .description         | attribute   | Description of Module                                                   |
    |                      |             |                                                                         |
    |                      |             | - **Data Type:** text                                                   |
    |                      |             | - **Name:** description                                                 |
    |                      |             |                                                                         |
    +----------------------+-------------+-------------------------------------------------------------------------+
    | .help                | attribute   | Value is 'A collection of analysis outputs from processing of data'     |
    |                      |             |                                                                         |
    |                      |             | - **Data Type:** text                                                   |
    |                      |             | - **Value:** A collection of analysis outputs from processing of data   |
    |                      |             | - **Name:** help                                                        |
    |                      |             |                                                                         |
    +----------------------+-------------+-------------------------------------------------------------------------+




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-ProcessingModule-groups:

.. table:: Groups contained in <ProcessingModule>
    :class: longtable

    +---------------------------------------------+---------+------------------------------------------------------------------------+
    | Id                                          | Type    | Description                                                            |
    +=============================================+=========+========================================================================+
    | <ProcessingModule>                          | group   | Top level group for <ProcessingModule>                                 |
    |                                             |         |                                                                        |
    |                                             |         | - **Extends:** :ref:`NWBContainer <sec-NWBContainer>`                  |
    |                                             |         | - **Neurodata Type:** :ref:`ProcessingModule <sec-ProcessingModule>`   |
    |                                             |         |                                                                        |
    +---------------------------------------------+---------+------------------------------------------------------------------------+
    | .<:ref:`NWBContainer <sec-NWBContainer>`>   | group   | Interface objects containing data output from processing steps         |
    |                                             |         |                                                                        |
    |                                             |         | - **Quantity** 0 or more                                               |
    |                                             |         | - **Extends:** :ref:`NWBContainer <sec-NWBContainer>`                  |
    |                                             |         |                                                                        |
    +---------------------------------------------+---------+------------------------------------------------------------------------+


Groups: <NWBContainer>
""""""""""""""""""""""

Interface objects containing data output from processing steps



- **Quantity** 0 or more
- **Extends:** :ref:`NWBContainer <sec-NWBContainer>`

