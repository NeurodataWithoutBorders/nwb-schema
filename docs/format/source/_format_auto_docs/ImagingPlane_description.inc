.. _sec-ImagingPlane:

ImagingPlane
^^^^^^^^^^^^

**Extends:** :ref:`NWBContainer <sec-NWBContainer>`

**Source Specification:** see :numref:`sec-ImagingPlane-src`

**Overview:** One of possibly many groups describing an imaging plane. 

**Comment:**  Name is arbitrary but should be meaningful. It is referenced by TwoPhotonSeries and also ImageSegmentation and DfOverF interfaces


``ImagingPlane`` extends ``NWBContainer`` (see :numref:`sec-NWBContainer`) and includes all elements of :ref:`NWBContainer <sec-NWBContainer>` with the following additions or changes.



- **Quantity** 0 or more


.. figure:: ./_format_auto_docs/ImagingPlane.*
    :alt: ImagingPlane




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-ImagingPlane-data:

.. table:: Datasets, Links, and Attributes contained in <ImagingPlane>
    :class: longtable

    +----------------------+-------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | Id                   | Type        | Description                                                                                                                                                                                                                      |
    +======================+=============+==================================================================================================================================================================================================================================+
    | <ImagingPlane>       | group       | Top level group for <ImagingPlane>                                                                                                                                                                                               |
    |                      |             |                                                                                                                                                                                                                                  |
    |                      |             | - **Quantity** 0 or more                                                                                                                                                                                                         |
    |                      |             | - **Extends:** :ref:`NWBContainer <sec-NWBContainer>`                                                                                                                                                                            |
    |                      |             | - **Neurodata Type:** :ref:`ImagingPlane <sec-ImagingPlane>`                                                                                                                                                                     |
    |                      |             |                                                                                                                                                                                                                                  |
    +----------------------+-------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .help                | attribute   | Value is 'Metadata about an imaging plane'                                                                                                                                                                                       |
    |                      |             |                                                                                                                                                                                                                                  |
    |                      |             | - **Data Type:** text                                                                                                                                                                                                            |
    |                      |             | - **Value:** Metadata about an imaging plane                                                                                                                                                                                     |
    |                      |             | - **Name:** help                                                                                                                                                                                                                 |
    |                      |             |                                                                                                                                                                                                                                  |
    +----------------------+-------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .description         | dataset     | Description of <image_plane_X>                                                                                                                                                                                                   |
    |                      |             |                                                                                                                                                                                                                                  |
    |                      |             | - **Quantity** 0 or 1                                                                                                                                                                                                            |
    |                      |             | - **Data Type:** text                                                                                                                                                                                                            |
    |                      |             | - **Name:** description                                                                                                                                                                                                          |
    |                      |             |                                                                                                                                                                                                                                  |
    +----------------------+-------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .device              | dataset     | Name of device in /general/devices                                                                                                                                                                                               |
    |                      |             |                                                                                                                                                                                                                                  |
    |                      |             | - **Data Type:** text                                                                                                                                                                                                            |
    |                      |             | - **Name:** device                                                                                                                                                                                                               |
    |                      |             |                                                                                                                                                                                                                                  |
    +----------------------+-------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .excitation_lambda   | dataset     | Excitation wavelength                                                                                                                                                                                                            |
    |                      |             |                                                                                                                                                                                                                                  |
    |                      |             | - **Data Type:** text                                                                                                                                                                                                            |
    |                      |             | - **Name:** excitation_lambda                                                                                                                                                                                                    |
    |                      |             |                                                                                                                                                                                                                                  |
    +----------------------+-------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .imaging_rate        | dataset     | Rate images are acquired, in Hz.                                                                                                                                                                                                 |
    |                      |             |                                                                                                                                                                                                                                  |
    |                      |             | - **Data Type:** text                                                                                                                                                                                                            |
    |                      |             | - **Name:** imaging_rate                                                                                                                                                                                                         |
    |                      |             |                                                                                                                                                                                                                                  |
    +----------------------+-------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .indicator           | dataset     | Calcium indicator                                                                                                                                                                                                                |
    |                      |             |                                                                                                                                                                                                                                  |
    |                      |             | - **Data Type:** text                                                                                                                                                                                                            |
    |                      |             | - **Name:** indicator                                                                                                                                                                                                            |
    |                      |             |                                                                                                                                                                                                                                  |
    +----------------------+-------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .location            | dataset     | Location of image plane                                                                                                                                                                                                          |
    |                      |             |                                                                                                                                                                                                                                  |
    |                      |             | - **Data Type:** text                                                                                                                                                                                                            |
    |                      |             | - **Name:** location                                                                                                                                                                                                             |
    |                      |             |                                                                                                                                                                                                                                  |
    +----------------------+-------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .manifold            | dataset     | Physical position of each pixel.                                                                                                                                                                                                 |
    |                      |             |                                                                                                                                                                                                                                  |
    |                      |             | **Comment:**  "xyz" represents the position of the pixel relative to the defined coordinate space                                                                                                                                |
    |                      |             |                                                                                                                                                                                                                                  |
    |                      |             | - **Data Type:** float32                                                                                                                                                                                                         |
    |                      |             | - **Dimensions:** ['height', 'weight', 'x|y|z']                                                                                                                                                                                  |
    |                      |             | - **Shape:** [None, None, 3]                                                                                                                                                                                                     |
    |                      |             | - **Name:** manifold                                                                                                                                                                                                             |
    |                      |             |                                                                                                                                                                                                                                  |
    +----------------------+-------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..conversion         | attribute   | Multiplier to get from stored values to specified unit (e.g., 1e-3 for millimeters)                                                                                                                                              |
    |                      |             |                                                                                                                                                                                                                                  |
    |                      |             | - **Data Type:** float                                                                                                                                                                                                           |
    |                      |             | - **Reuqired:** False                                                                                                                                                                                                            |
    |                      |             | - **Default Value:** 1.0                                                                                                                                                                                                         |
    |                      |             | - **Name:** conversion                                                                                                                                                                                                           |
    |                      |             |                                                                                                                                                                                                                                  |
    +----------------------+-------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..unit               | attribute   | Base unit that coordinates are stored in (e.g., Meters)                                                                                                                                                                          |
    |                      |             |                                                                                                                                                                                                                                  |
    |                      |             | - **Data Type:** text                                                                                                                                                                                                            |
    |                      |             | - **Reuqired:** False                                                                                                                                                                                                            |
    |                      |             | - **Default Value:** Meter                                                                                                                                                                                                       |
    |                      |             | - **Name:** unit                                                                                                                                                                                                                 |
    |                      |             |                                                                                                                                                                                                                                  |
    +----------------------+-------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .reference_frame     | dataset     | Describes position and reference frame of manifold based on position of first element in manifold. For example, text description of anotomical location or vectors needed to rotate to common anotomical axis (eg, AP/DV/ML).    |
    |                      |             |                                                                                                                                                                                                                                  |
    |                      |             | **Comment:**  This field is necessary to interpret manifold. If manifold is not present then this field is not required                                                                                                          |
    |                      |             |                                                                                                                                                                                                                                  |
    |                      |             | - **Data Type:** text                                                                                                                                                                                                            |
    |                      |             | - **Name:** reference_frame                                                                                                                                                                                                      |
    |                      |             |                                                                                                                                                                                                                                  |
    +----------------------+-------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-ImagingPlane-groups:

.. table:: Groups contained in <ImagingPlane>
    :class: longtable

    +---------------------+---------+--------------------------------------------------------------------+
    | Id                  | Type    | Description                                                        |
    +=====================+=========+====================================================================+
    | <ImagingPlane>      | group   | Top level group for <ImagingPlane>                                 |
    |                     |         |                                                                    |
    |                     |         | - **Quantity** 0 or more                                           |
    |                     |         | - **Extends:** :ref:`NWBContainer <sec-NWBContainer>`              |
    |                     |         | - **Neurodata Type:** :ref:`ImagingPlane <sec-ImagingPlane>`       |
    |                     |         |                                                                    |
    +---------------------+---------+--------------------------------------------------------------------+
    | .<OpticalChannel>   | group   | One of possibly many groups storing channel-specific data          |
    |                     |         |                                                                    |
    |                     |         | **Comment:**  Name is arbitrary but should be meaningful           |
    |                     |         |                                                                    |
    |                     |         | - **Extends:** :ref:`NWBContainer <sec-NWBContainer>`              |
    |                     |         | - **Neurodata Type:** :ref:`OpticalChannel <sec-OpticalChannel>`   |
    |                     |         |                                                                    |
    +---------------------+---------+--------------------------------------------------------------------+


Groups: <OpticalChannel>
""""""""""""""""""""""""

One of possibly many groups storing channel-specific data 

**Comment:**  Name is arbitrary but should be meaningful



- **Extends:** :ref:`NWBContainer <sec-NWBContainer>`
- **Neurodata Type:** :ref:`OpticalChannel <sec-OpticalChannel>`


.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. table:: Datasets, Links, and Attributes contained in ``<OpticalChannel>``
    :class: longtable

    +--------------------+-------------+---------------------------------------------------------------------------------------+
    | Id                 | Type        | Description                                                                           |
    +====================+=============+=======================================================================================+
    | <OpticalChannel>   | group       | Top level group for <OpticalChannel>                                                  |
    |                    |             |                                                                                       |
    |                    |             | - **Extends:** :ref:`NWBContainer <sec-NWBContainer>`                                 |
    |                    |             | - **Neurodata Type:** :ref:`OpticalChannel <sec-OpticalChannel>`                      |
    |                    |             |                                                                                       |
    +--------------------+-------------+---------------------------------------------------------------------------------------+
    | .help              | attribute   | Value is 'Metadata about an optical channel used to record from an imaging plane'     |
    |                    |             |                                                                                       |
    |                    |             | - **Data Type:** text                                                                 |
    |                    |             | - **Value:** Metadata about an optical channel used to record from an imaging plane   |
    |                    |             | - **Name:** help                                                                      |
    |                    |             |                                                                                       |
    +--------------------+-------------+---------------------------------------------------------------------------------------+
    | .description       | dataset     | Any notes or comments about the channel                                               |
    |                    |             |                                                                                       |
    |                    |             | - **Data Type:** text                                                                 |
    |                    |             | - **Name:** description                                                               |
    |                    |             |                                                                                       |
    +--------------------+-------------+---------------------------------------------------------------------------------------+
    | .emission_lambda   | dataset     | Emission lambda for channel                                                           |
    |                    |             |                                                                                       |
    |                    |             | - **Data Type:** text                                                                 |
    |                    |             | - **Name:** emission_lambda                                                           |
    |                    |             |                                                                                       |
    +--------------------+-------------+---------------------------------------------------------------------------------------+


