.. _sec-Epoch:

Epoch
^^^^^

**Extends:** :ref:`NWBContainer <sec-NWBContainer>`

**Source Specification:** see :numref:`sec-Epoch-src`

**Overview:** One of possibly many different experimental epoch

**Comment:**  Name is arbitrary but must be unique within the experiment.


``Epoch`` extends ``NWBContainer`` (see :numref:`sec-NWBContainer`) and includes all elements of :ref:`NWBContainer <sec-NWBContainer>` with the following additions or changes.



- **Quantity** 0 or more


.. figure:: ./_format_auto_docs/Epoch.*
    :alt: Epoch




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-Epoch-data:

.. table:: Datasets, Links, and Attributes contained in <Epoch>
    :class: longtable

    +----------------+-------------+------------------------------------------------------------------------------------------------------------+
    | Id             | Type        | Description                                                                                                |
    +================+=============+============================================================================================================+
    | <Epoch>        | group       | Top level group for <Epoch>                                                                                |
    |                |             |                                                                                                            |
    |                |             | - **Quantity** 0 or more                                                                                   |
    |                |             | - **Extends:** :ref:`NWBContainer <sec-NWBContainer>`                                                      |
    |                |             | - **Neurodata Type:** :ref:`Epoch <sec-Epoch>`                                                             |
    |                |             |                                                                                                            |
    +----------------+-------------+------------------------------------------------------------------------------------------------------------+
    | .help          | attribute   | Value is 'A general epoch object'                                                                          |
    |                |             |                                                                                                            |
    |                |             | - **Data Type:** text                                                                                      |
    |                |             | - **Value:** A general epoch object                                                                        |
    |                |             | - **Name:** help                                                                                           |
    |                |             |                                                                                                            |
    +----------------+-------------+------------------------------------------------------------------------------------------------------------+
    | .description   | dataset     | Description of this epoch (<epoch_X>).                                                                     |
    |                |             |                                                                                                            |
    |                |             | - **Quantity** 0 or 1                                                                                      |
    |                |             | - **Data Type:** text                                                                                      |
    |                |             | - **Name:** description                                                                                    |
    |                |             |                                                                                                            |
    +----------------+-------------+------------------------------------------------------------------------------------------------------------+
    | .start_time    | dataset     | Start time of epoch, in seconds                                                                            |
    |                |             |                                                                                                            |
    |                |             | - **Data Type:** float64!                                                                                  |
    |                |             | - **Name:** start_time                                                                                     |
    |                |             |                                                                                                            |
    +----------------+-------------+------------------------------------------------------------------------------------------------------------+
    | .stop_time     | dataset     | Stop time of epoch, in seconds                                                                             |
    |                |             |                                                                                                            |
    |                |             | - **Data Type:** float64!                                                                                  |
    |                |             | - **Name:** stop_time                                                                                      |
    |                |             |                                                                                                            |
    +----------------+-------------+------------------------------------------------------------------------------------------------------------+
    | .tags          | dataset     | User-defined tags used throughout the epochs. Tags are to help identify or categorize epochs.              |
    |                |             |                                                                                                            |
    |                |             | **Comment:**  E.g., can describe stimulus (if template) or behavioral characteristic (e.g., "lick left")   |
    |                |             |                                                                                                            |
    |                |             | - **Quantity** 0 or 1                                                                                      |
    |                |             | - **Data Type:** text                                                                                      |
    |                |             | - **Dimensions:** ['num_tags']                                                                             |
    |                |             | - **Shape:** [None]                                                                                        |
    |                |             | - **Name:** tags                                                                                           |
    |                |             |                                                                                                            |
    +----------------+-------------+------------------------------------------------------------------------------------------------------------+




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-Epoch-groups:

.. table:: Groups contained in <Epoch>
    :class: longtable

    +----------------------+---------+------------------------------------------------------------------------------------------------+
    | Id                   | Type    | Description                                                                                    |
    +======================+=========+================================================================================================+
    | <Epoch>              | group   | Top level group for <Epoch>                                                                    |
    |                      |         |                                                                                                |
    |                      |         | - **Quantity** 0 or more                                                                       |
    |                      |         | - **Extends:** :ref:`NWBContainer <sec-NWBContainer>`                                          |
    |                      |         | - **Neurodata Type:** :ref:`Epoch <sec-Epoch>`                                                 |
    |                      |         |                                                                                                |
    +----------------------+---------+------------------------------------------------------------------------------------------------+
    | .<EpochTimeSeries>   | group   | One of possibly many input or output streams recorded during epoch.                            |
    |                      |         |                                                                                                |
    |                      |         | **Comment:**  Name is arbitrary and does not have to match the TimeSeries that it refers to.   |
    |                      |         |                                                                                                |
    |                      |         | - **Quantity** 0 or more                                                                       |
    |                      |         | - **Extends:** :ref:`NWBContainer <sec-NWBContainer>`                                          |
    |                      |         | - **Neurodata Type:** :ref:`EpochTimeSeries <sec-EpochTimeSeries>`                             |
    |                      |         |                                                                                                |
    +----------------------+---------+------------------------------------------------------------------------------------------------+
    | ..timeseries         | link    | Link to TimeSeries.  An HDF5 soft-link should be used.                                         |
    |                      |         |                                                                                                |
    |                      |         | - **Target Type** :ref:`TimeSeries <sec-TimeSeries>`                                           |
    |                      |         | - **Name:** timeseries                                                                         |
    |                      |         |                                                                                                |
    +----------------------+---------+------------------------------------------------------------------------------------------------+


Groups: <EpochTimeSeries>
"""""""""""""""""""""""""

One of possibly many input or output streams recorded during epoch. 

**Comment:**  Name is arbitrary and does not have to match the TimeSeries that it refers to.



- **Quantity** 0 or more
- **Extends:** :ref:`NWBContainer <sec-NWBContainer>`
- **Neurodata Type:** :ref:`EpochTimeSeries <sec-EpochTimeSeries>`


.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. table:: Datasets, Links, and Attributes contained in ``<EpochTimeSeries>``
    :class: longtable

    +---------------------+-------------+----------------------------------------------------------------------------------------+
    | Id                  | Type        | Description                                                                            |
    +=====================+=============+========================================================================================+
    | <EpochTimeSeries>   | group       | Top level group for <EpochTimeSeries>                                                  |
    |                     |             |                                                                                        |
    |                     |             | - **Quantity** 0 or more                                                               |
    |                     |             | - **Extends:** :ref:`NWBContainer <sec-NWBContainer>`                                  |
    |                     |             | - **Neurodata Type:** :ref:`EpochTimeSeries <sec-EpochTimeSeries>`                     |
    |                     |             |                                                                                        |
    +---------------------+-------------+----------------------------------------------------------------------------------------+
    | .help               | attribute   | Value is 'Data on how an epoch applies to a time series'                               |
    |                     |             |                                                                                        |
    |                     |             | - **Data Type:** text                                                                  |
    |                     |             | - **Value:** Data on how an epoch applies to a time series                             |
    |                     |             | - **Name:** help                                                                       |
    |                     |             |                                                                                        |
    +---------------------+-------------+----------------------------------------------------------------------------------------+
    | .count              | dataset     | Number of data samples available in this time series, during this epoch.               |
    |                     |             |                                                                                        |
    |                     |             | - **Data Type:** int32                                                                 |
    |                     |             | - **Name:** count                                                                      |
    |                     |             |                                                                                        |
    +---------------------+-------------+----------------------------------------------------------------------------------------+
    | .idx_start          | dataset     | Epoch's start index in TimeSeries data[] field.                                        |
    |                     |             |                                                                                        |
    |                     |             | **Comment:**  This can be used to calculate location in TimeSeries timestamp[] field   |
    |                     |             |                                                                                        |
    |                     |             | - **Data Type:** int32                                                                 |
    |                     |             | - **Name:** idx_start                                                                  |
    |                     |             |                                                                                        |
    +---------------------+-------------+----------------------------------------------------------------------------------------+
    | .timeseries         | link        | Link to TimeSeries.  An HDF5 soft-link should be used.                                 |
    |                     |             |                                                                                        |
    |                     |             | - **Target Type** :ref:`TimeSeries <sec-TimeSeries>`                                   |
    |                     |             | - **Name:** timeseries                                                                 |
    |                     |             |                                                                                        |
    +---------------------+-------------+----------------------------------------------------------------------------------------+



.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. table:: Groups contained in <<EpochTimeSeries>>
    :class: longtable

    +---------------------+---------+----------------------------------------------------------------------+
    | Id                  | Type    | Description                                                          |
    +=====================+=========+======================================================================+
    | <EpochTimeSeries>   | group   | Top level group for <EpochTimeSeries>                                |
    |                     |         |                                                                      |
    |                     |         | - **Quantity** 0 or more                                             |
    |                     |         | - **Extends:** :ref:`NWBContainer <sec-NWBContainer>`                |
    |                     |         | - **Neurodata Type:** :ref:`EpochTimeSeries <sec-EpochTimeSeries>`   |
    |                     |         |                                                                      |
    +---------------------+---------+----------------------------------------------------------------------+
    | .timeseries         | link    | Link to TimeSeries.  An HDF5 soft-link should be used.               |
    |                     |         |                                                                      |
    |                     |         | - **Target Type** :ref:`TimeSeries <sec-TimeSeries>`                 |
    |                     |         | - **Name:** timeseries                                               |
    |                     |         |                                                                      |
    +---------------------+---------+----------------------------------------------------------------------+


