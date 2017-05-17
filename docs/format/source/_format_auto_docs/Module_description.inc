.. _sec-Module:

Module
^^^^^^

**Source Specification:** see :numref:`sec-Module-src`

**Overview:** Module.  Name should be descriptive. Stores a collection of related data organized by contained interfaces.  Each interface is a contract specifying content related to a particular type of data.




.. figure:: ./_format_auto_docs/Module.*
    :alt: Module




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-Module-data:

.. table:: Datasets, Links, and Attributes contained in <Module>
    :class: longtable

    +----------------+-------------+---------------------------------------------------------------------------------------+
    | Id             | Type        | Description                                                                           |
    +================+=============+=======================================================================================+
    | <Module>       | group       | Top level group for <Module>                                                          |
    +----------------+-------------+---------------------------------------------------------------------------------------+
    | .description   | attribute   | Description of Module                                                                 |
    |                |             |                                                                                       |
    |                |             | - **Data Type:** text                                                                 |
    |                |             |                                                                                       |
    +----------------+-------------+---------------------------------------------------------------------------------------+
    | .interfaces    | attribute   | Names of the data interfaces offered by this module.                                  |
    |                |             |                                                                                       |
    |                |             | **Comment:**  E.g., [0]="EventDetection", [1]="Clustering", [2]="FeatureExtraction"   |
    |                |             |                                                                                       |
    |                |             | - **Data Type:** text                                                                 |
    |                |             | - **Dimensions:** ['num_interfaces']                                                  |
    |                |             | - **Shape:** (None,)                                                                  |
    |                |             |                                                                                       |
    +----------------+-------------+---------------------------------------------------------------------------------------+




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-Module-groups:

.. table:: Groups contained in <Module>
    :class: longtable

    +---------------------------------------+---------+------------------------------------------------------------------+
    | Id                                    | Type    | Description                                                      |
    +=======================================+=========+==================================================================+
    | <Module>                              | group   | Top level group for <Module>                                     |
    +---------------------------------------+---------+------------------------------------------------------------------+
    | .<:ref:`Interface <sec-Interface>`>   | group   | Interface objects containing data output from processing steps   |
    |                                       |         |                                                                  |
    |                                       |         | - **Extends:** :ref:`Interface <sec-Interface>`                  |
    |                                       |         |                                                                  |
    +---------------------------------------+---------+------------------------------------------------------------------+


Groups: <Interface>
"""""""""""""""""""

Interface objects containing data output from processing steps



- **Extends:** :ref:`Interface <sec-Interface>`

