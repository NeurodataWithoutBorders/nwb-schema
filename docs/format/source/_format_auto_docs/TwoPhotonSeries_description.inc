.. _sec-TwoPhotonSeries:

TwoPhotonSeries
^^^^^^^^^^^^^^^

**Extends:** :ref:`ImageSeries <sec-ImageSeries>`

**Source Specification:** see :numref:`sec-TwoPhotonSeries-src`

**Overview:** A special case of optical imaging.


``TwoPhotonSeries`` extends ``ImageSeries`` (see :numref:`sec-ImageSeries`) and includes all elements of :ref:`ImageSeries <sec-ImageSeries>` with the following additions or changes.



.. figure:: ./_format_auto_docs/TwoPhotonSeries.*
    :alt: TwoPhotonSeries




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-TwoPhotonSeries-data:

.. table:: Datasets, Links, and Attributes contained in <TwoPhotonSeries>
    :class: longtable

    +---------------------+-------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | Id                  | Type        | Description                                                                                                                                                                       |
    +=====================+=============+===================================================================================================================================================================================+
    | <TwoPhotonSeries>   | group       | Top level group for <TwoPhotonSeries>                                                                                                                                             |
    |                     |             |                                                                                                                                                                                   |
    |                     |             | - **Extends:** :ref:`ImageSeries <sec-ImageSeries>`                                                                                                                               |
    |                     |             | - **Neurodata Type:** :ref:`TwoPhotonSeries <sec-TwoPhotonSeries>`                                                                                                                |
    |                     |             |                                                                                                                                                                                   |
    +---------------------+-------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .help               | attribute   | Value is 'Image stack recorded from 2-photon microscope'                                                                                                                          |
    |                     |             |                                                                                                                                                                                   |
    |                     |             | - **Data Type:** text                                                                                                                                                             |
    |                     |             | - **Value:** Image stack recorded from 2-photon microscope                                                                                                                        |
    |                     |             | - **Name:** help                                                                                                                                                                  |
    |                     |             |                                                                                                                                                                                   |
    +---------------------+-------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .field_of_view      | dataset     | Width, height and depth of image, or imaged area (meters).                                                                                                                        |
    |                     |             |                                                                                                                                                                                   |
    |                     |             | - **Quantity** 0 or 1                                                                                                                                                             |
    |                     |             | - **Data Type:** float32                                                                                                                                                          |
    |                     |             | - **Dimensions:** ['width|height|depth']                                                                                                                                          |
    |                     |             | - **Shape:** [3]                                                                                                                                                                  |
    |                     |             | - **Name:** field_of_view                                                                                                                                                         |
    |                     |             |                                                                                                                                                                                   |
    +---------------------+-------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .pmt_gain           | dataset     | Photomultiplier gain                                                                                                                                                              |
    |                     |             |                                                                                                                                                                                   |
    |                     |             | - **Quantity** 0 or 1                                                                                                                                                             |
    |                     |             | - **Data Type:** float32                                                                                                                                                          |
    |                     |             | - **Name:** pmt_gain                                                                                                                                                              |
    |                     |             |                                                                                                                                                                                   |
    +---------------------+-------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .scan_line_rate     | dataset     | Lines imaged per second. This is also stored in /general/optophysiology but is kept here as it is useful information for analysis, and so good to be stored w/ the actual data.   |
    |                     |             |                                                                                                                                                                                   |
    |                     |             | - **Quantity** 0 or 1                                                                                                                                                             |
    |                     |             | - **Data Type:** float32                                                                                                                                                          |
    |                     |             | - **Name:** scan_line_rate                                                                                                                                                        |
    |                     |             |                                                                                                                                                                                   |
    +---------------------+-------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .imaging_plane      | link        | link to ImagingPlane group from which this TimeSeries data was generated                                                                                                          |
    |                     |             |                                                                                                                                                                                   |
    |                     |             | - **Target Type** :ref:`ImagingPlane <sec-ImagingPlane>`                                                                                                                          |
    |                     |             | - **Name:** imaging_plane                                                                                                                                                         |
    |                     |             |                                                                                                                                                                                   |
    +---------------------+-------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-TwoPhotonSeries-groups:

.. table:: Groups contained in <TwoPhotonSeries>
    :class: longtable

    +---------------------+---------+----------------------------------------------------------------------------+
    | Id                  | Type    | Description                                                                |
    +=====================+=========+============================================================================+
    | <TwoPhotonSeries>   | group   | Top level group for <TwoPhotonSeries>                                      |
    |                     |         |                                                                            |
    |                     |         | - **Extends:** :ref:`ImageSeries <sec-ImageSeries>`                        |
    |                     |         | - **Neurodata Type:** :ref:`TwoPhotonSeries <sec-TwoPhotonSeries>`         |
    |                     |         |                                                                            |
    +---------------------+---------+----------------------------------------------------------------------------+
    | .imaging_plane      | link    | link to ImagingPlane group from which this TimeSeries data was generated   |
    |                     |         |                                                                            |
    |                     |         | - **Target Type** :ref:`ImagingPlane <sec-ImagingPlane>`                   |
    |                     |         | - **Name:** imaging_plane                                                  |
    |                     |         |                                                                            |
    +---------------------+---------+----------------------------------------------------------------------------+


