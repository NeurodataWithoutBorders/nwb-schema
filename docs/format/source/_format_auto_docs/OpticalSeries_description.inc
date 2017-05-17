.. _sec-OpticalSeries:

OpticalSeries
^^^^^^^^^^^^^

**Extends:** :ref:`ImageSeries <sec-ImageSeries>`

**Source Specification:** see :numref:`sec-OpticalSeries-src`

**Overview:** Image data that is presented or recorded. A stimulus template movie will be stored only as an image. When the image is presented as stimulus, additional data is required, such as field of view (eg, how much of the visual field the image covers, or how what is the area of the target being imaged). If the OpticalSeries represents acquired imaging data, orientation is also important.


``OpticalSeries`` extends ``ImageSeries`` (see :numref:`sec-ImageSeries`) and includes all elements of :ref:`ImageSeries <sec-ImageSeries>` with the following additions or changes.



.. figure:: ./_format_auto_docs/OpticalSeries.*
    :alt: OpticalSeries




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-OpticalSeries-data:

.. table:: Datasets, Links, and Attributes contained in <OpticalSeries>
    :class: longtable

    +-------------------+-------------+------------------------------------------------------------------------------------------------------------------------+
    | Id                | Type        | Description                                                                                                            |
    +===================+=============+========================================================================================================================+
    | <OpticalSeries>   | group       | Top level group for <OpticalSeries>                                                                                    |
    +-------------------+-------------+------------------------------------------------------------------------------------------------------------------------+
    | .help             | attribute   | Value is Time-series image stack for optical recording or stimulus                                                     |
    |                   |             |                                                                                                                        |
    |                   |             | - **Data Type:** text                                                                                                  |
    |                   |             | - **Value:** Time-series image stack for optical recording or stimulus                                                 |
    |                   |             |                                                                                                                        |
    +-------------------+-------------+------------------------------------------------------------------------------------------------------------------------+
    | .field_of_view    | dataset     | Width, height and depto of image, or imaged area (meters).                                                             |
    |                   |             |                                                                                                                        |
    |                   |             | - **Quantity** 0 or 1                                                                                                  |
    |                   |             | - **Data Type:** float32                                                                                               |
    |                   |             | - **Dimensions:** [['width|height', 'width|height|depth']]                                                             |
    |                   |             | - **Shape:** [2]                                                                                                       |
    |                   |             |                                                                                                                        |
    +-------------------+-------------+------------------------------------------------------------------------------------------------------------------------+
    | .orientation      | dataset     | Description of image relative to some reference frame (e.g., which way is up). Must also specify frame of reference.   |
    |                   |             |                                                                                                                        |
    |                   |             | - **Quantity** 0 or 1                                                                                                  |
    |                   |             | - **Data Type:** text                                                                                                  |
    |                   |             |                                                                                                                        |
    +-------------------+-------------+------------------------------------------------------------------------------------------------------------------------+
    | .distance         | dataset     | Distance from camera/monitor to target/eye.                                                                            |
    |                   |             |                                                                                                                        |
    |                   |             | - **Quantity** 0 or 1                                                                                                  |
    |                   |             | - **Data Type:** float32                                                                                               |
    |                   |             |                                                                                                                        |
    +-------------------+-------------+------------------------------------------------------------------------------------------------------------------------+



