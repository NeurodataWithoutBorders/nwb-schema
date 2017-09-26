.. _sec-ImagingRetinotopy:

ImagingRetinotopy
^^^^^^^^^^^^^^^^^

**Extends:** :ref:`NWBContainer <sec-NWBContainer>`

**Source Specification:** see :numref:`sec-ImagingRetinotopy-src`

**Overview:** Intrinsic signal optical imaging or widefield imaging for measuring retinotopy. Stores orthogonal maps (e.g., altitude/azimuth; radius/theta) of responses to specific stimuli and a combined polarity map from which to identify visual areas.<br />Note: for data consistency, all images and arrays are stored in the format [row][column] and [row, col], which equates to [y][x]. Field of view and dimension arrays may appear backward (i.e., y before x).


``ImagingRetinotopy`` extends ``NWBContainer`` (see :numref:`sec-NWBContainer`) and includes all elements of :ref:`NWBContainer <sec-NWBContainer>` with the following additions or changes.



- **Default Name:** ImagingRetinotopy


.. figure:: ./_format_auto_docs/ImagingRetinotopy.*
    :alt: ImagingRetinotopy




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-ImagingRetinotopy-data:

.. table:: Datasets, Links, and Attributes contained in <ImagingRetinotopy>
    :class: longtable

    +-----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | Id                    | Type        | Description                                                                                                                                                       |
    +=======================+=============+===================================================================================================================================================================+
    | <ImagingRetinotopy>   | group       | Top level group for <ImagingRetinotopy>                                                                                                                           |
    |                       |             |                                                                                                                                                                   |
    |                       |             | - **Extends:** :ref:`NWBContainer <sec-NWBContainer>`                                                                                                             |
    |                       |             | - **Neurodata Type:** :ref:`ImagingRetinotopy <sec-ImagingRetinotopy>`                                                                                            |
    |                       |             | - **Default Name:** ImagingRetinotopy                                                                                                                             |
    |                       |             |                                                                                                                                                                   |
    +-----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .help                 | attribute   | Value is 'Intrinsic signal optical imaging or Widefield imaging for measuring retinotopy'                                                                         |
    |                       |             |                                                                                                                                                                   |
    |                       |             | - **Data Type:** text                                                                                                                                             |
    |                       |             | - **Value:** Intrinsic signal optical imaging or Widefield imaging for measuring retinotopy                                                                       |
    |                       |             | - **Name:** help                                                                                                                                                  |
    |                       |             |                                                                                                                                                                   |
    +-----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .axis_1_phase_map     | dataset     | Phase response to stimulus on the first measured axis                                                                                                             |
    |                       |             |                                                                                                                                                                   |
    |                       |             | - **Data Type:** float32                                                                                                                                          |
    |                       |             | - **Dimensions:** ['num_rows', 'num_cols']                                                                                                                        |
    |                       |             | - **Shape:** [None, None]                                                                                                                                         |
    |                       |             | - **Name:** axis_1_phase_map                                                                                                                                      |
    |                       |             |                                                                                                                                                                   |
    +-----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..dimension           | attribute   | Number of rows and columns in the image.                                                                                                                          |
    |                       |             |                                                                                                                                                                   |
    |                       |             |  **Additional Information:**  row, column representation is equivalent to height,width.                                                                           |
    |                       |             |                                                                                                                                                                   |
    |                       |             | - **Data Type:** int32                                                                                                                                            |
    |                       |             | - **Dimensions:** ['row_col']                                                                                                                                     |
    |                       |             | - **Shape:** (None,)                                                                                                                                              |
    |                       |             | - **Name:** dimension                                                                                                                                             |
    |                       |             |                                                                                                                                                                   |
    +-----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..field_of_view       | attribute   | Size of viewing area, in meters                                                                                                                                   |
    |                       |             |                                                                                                                                                                   |
    |                       |             | - **Data Type:** float                                                                                                                                            |
    |                       |             | - **Dimensions:** ['row|column']                                                                                                                                  |
    |                       |             | - **Shape:** (None,)                                                                                                                                              |
    |                       |             | - **Name:** field_of_view                                                                                                                                         |
    |                       |             |                                                                                                                                                                   |
    +-----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..unit                | attribute   | Unit that axis data is stored in (e.g., degrees)                                                                                                                  |
    |                       |             |                                                                                                                                                                   |
    |                       |             | - **Data Type:** text                                                                                                                                             |
    |                       |             | - **Name:** unit                                                                                                                                                  |
    |                       |             |                                                                                                                                                                   |
    +-----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .axis_1_power_map     | dataset     | Power response on the first measured axis. Response is scaled so 0.0 is no power in the response and 1.0 is maximum relative power.                               |
    |                       |             |                                                                                                                                                                   |
    |                       |             | - **Quantity** 0 or 1                                                                                                                                             |
    |                       |             | - **Data Type:** float32                                                                                                                                          |
    |                       |             | - **Dimensions:** ['num_rows', 'num_cols']                                                                                                                        |
    |                       |             | - **Shape:** [None, None]                                                                                                                                         |
    |                       |             | - **Name:** axis_1_power_map                                                                                                                                      |
    |                       |             |                                                                                                                                                                   |
    +-----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..dimension           | attribute   | Number of rows and columns in the image.                                                                                                                          |
    |                       |             |                                                                                                                                                                   |
    |                       |             |  **Additional Information:**  row, column representation is equivalent to height,width.                                                                           |
    |                       |             |                                                                                                                                                                   |
    |                       |             | - **Data Type:** int32                                                                                                                                            |
    |                       |             | - **Dimensions:** ['row_col']                                                                                                                                     |
    |                       |             | - **Shape:** (None,)                                                                                                                                              |
    |                       |             | - **Name:** dimension                                                                                                                                             |
    |                       |             |                                                                                                                                                                   |
    +-----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..field_of_view       | attribute   | Size of viewing area, in meters                                                                                                                                   |
    |                       |             |                                                                                                                                                                   |
    |                       |             | - **Data Type:** float                                                                                                                                            |
    |                       |             | - **Dimensions:** ['row_col']                                                                                                                                     |
    |                       |             | - **Shape:** (None,)                                                                                                                                              |
    |                       |             | - **Name:** field_of_view                                                                                                                                         |
    |                       |             |                                                                                                                                                                   |
    +-----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..unit                | attribute   | Unit that axis data is stored in (e.g., degrees)                                                                                                                  |
    |                       |             |                                                                                                                                                                   |
    |                       |             | - **Data Type:** text                                                                                                                                             |
    |                       |             | - **Name:** unit                                                                                                                                                  |
    |                       |             |                                                                                                                                                                   |
    +-----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .axis_2_phase_map     | dataset     | Phase response to stimulus on the second measured axis                                                                                                            |
    |                       |             |                                                                                                                                                                   |
    |                       |             | - **Data Type:** float32                                                                                                                                          |
    |                       |             | - **Dimensions:** ['num_rows', 'num_cols']                                                                                                                        |
    |                       |             | - **Shape:** [None, None]                                                                                                                                         |
    |                       |             | - **Name:** axis_2_phase_map                                                                                                                                      |
    |                       |             |                                                                                                                                                                   |
    +-----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..dimension           | attribute   | Number of rows and columns in the image.                                                                                                                          |
    |                       |             |                                                                                                                                                                   |
    |                       |             |  **Additional Information:**  row, column representation is equivalent to height,width.                                                                           |
    |                       |             |                                                                                                                                                                   |
    |                       |             | - **Data Type:** int32                                                                                                                                            |
    |                       |             | - **Dimensions:** ['row_col']                                                                                                                                     |
    |                       |             | - **Shape:** (None,)                                                                                                                                              |
    |                       |             | - **Name:** dimension                                                                                                                                             |
    |                       |             |                                                                                                                                                                   |
    +-----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..field_of_view       | attribute   | Size of viewing area, in meters                                                                                                                                   |
    |                       |             |                                                                                                                                                                   |
    |                       |             | - **Data Type:** float                                                                                                                                            |
    |                       |             | - **Dimensions:** ['row_col']                                                                                                                                     |
    |                       |             | - **Shape:** (None,)                                                                                                                                              |
    |                       |             | - **Name:** field_of_view                                                                                                                                         |
    |                       |             |                                                                                                                                                                   |
    +-----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..unit                | attribute   | Unit that axis data is stored in (e.g., degrees)                                                                                                                  |
    |                       |             |                                                                                                                                                                   |
    |                       |             | - **Data Type:** text                                                                                                                                             |
    |                       |             | - **Name:** unit                                                                                                                                                  |
    |                       |             |                                                                                                                                                                   |
    +-----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .axis_2_power_map     | dataset     | Power response on the second measured axis. Response is scaled so 0.0 is no power in the response and 1.0 is maximum relative power.                              |
    |                       |             |                                                                                                                                                                   |
    |                       |             | - **Quantity** 0 or 1                                                                                                                                             |
    |                       |             | - **Data Type:** float32                                                                                                                                          |
    |                       |             | - **Dimensions:** ['num_rows', 'num_cols']                                                                                                                        |
    |                       |             | - **Shape:** [None, None]                                                                                                                                         |
    |                       |             | - **Name:** axis_2_power_map                                                                                                                                      |
    |                       |             |                                                                                                                                                                   |
    +-----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..dimension           | attribute   | Number of rows and columns in the image.                                                                                                                          |
    |                       |             |                                                                                                                                                                   |
    |                       |             |  **Additional Information:**  row, column representation is equivalent to height,width.                                                                           |
    |                       |             |                                                                                                                                                                   |
    |                       |             | - **Data Type:** int32                                                                                                                                            |
    |                       |             | - **Dimensions:** ['row_col']                                                                                                                                     |
    |                       |             | - **Shape:** (None,)                                                                                                                                              |
    |                       |             | - **Name:** dimension                                                                                                                                             |
    |                       |             |                                                                                                                                                                   |
    +-----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..field_of_view       | attribute   | Size of viewing area, in meters                                                                                                                                   |
    |                       |             |                                                                                                                                                                   |
    |                       |             | - **Data Type:** float                                                                                                                                            |
    |                       |             | - **Dimensions:** ['row_col']                                                                                                                                     |
    |                       |             | - **Shape:** (None,)                                                                                                                                              |
    |                       |             | - **Name:** field_of_view                                                                                                                                         |
    |                       |             |                                                                                                                                                                   |
    +-----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..unit                | attribute   | Unit that axis data is stored in (e.g., degrees)                                                                                                                  |
    |                       |             |                                                                                                                                                                   |
    |                       |             | - **Data Type:** text                                                                                                                                             |
    |                       |             | - **Name:** unit                                                                                                                                                  |
    |                       |             |                                                                                                                                                                   |
    +-----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .axis_descriptions    | dataset     | Two-element array describing the contents of the two response axis fields. Description should be something like ['altitude', 'azimuth'] or '['radius', 'theta']   |
    |                       |             |                                                                                                                                                                   |
    |                       |             | - **Data Type:** text                                                                                                                                             |
    |                       |             | - **Dimensions:** ['2']                                                                                                                                           |
    |                       |             | - **Shape:** [None]                                                                                                                                               |
    |                       |             | - **Name:** axis_descriptions                                                                                                                                     |
    |                       |             |                                                                                                                                                                   |
    +-----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .focal_depth_image    | dataset     | Gray-scale image taken with same settings/parameters (e.g., focal depth, wavelength) as data collection. Array format: [rows][columns]                            |
    |                       |             |                                                                                                                                                                   |
    |                       |             | - **Data Type:** uint16                                                                                                                                           |
    |                       |             | - **Dimensions:** ['num_rows', 'num_cols']                                                                                                                        |
    |                       |             | - **Shape:** [None, None]                                                                                                                                         |
    |                       |             | - **Name:** focal_depth_image                                                                                                                                     |
    |                       |             |                                                                                                                                                                   |
    +-----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..bits_per_pixel      | attribute   | Number of bits used to represent each value. This is necessary to determine maximum (white) pixel value                                                           |
    |                       |             |                                                                                                                                                                   |
    |                       |             | - **Data Type:** int32                                                                                                                                            |
    |                       |             | - **Name:** bits_per_pixel                                                                                                                                        |
    |                       |             |                                                                                                                                                                   |
    +-----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..dimension           | attribute   | Number of rows and columns in the image.                                                                                                                          |
    |                       |             |                                                                                                                                                                   |
    |                       |             |  **Additional Information:**  row, column representation is equivalent to height,width.                                                                           |
    |                       |             |                                                                                                                                                                   |
    |                       |             | - **Data Type:** int32                                                                                                                                            |
    |                       |             | - **Dimensions:** ['row_col']                                                                                                                                     |
    |                       |             | - **Shape:** (None,)                                                                                                                                              |
    |                       |             | - **Name:** dimension                                                                                                                                             |
    |                       |             |                                                                                                                                                                   |
    +-----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..field_of_view       | attribute   | Size of viewing area, in meters                                                                                                                                   |
    |                       |             |                                                                                                                                                                   |
    |                       |             | - **Data Type:** float                                                                                                                                            |
    |                       |             | - **Dimensions:** ['row_col']                                                                                                                                     |
    |                       |             | - **Shape:** (None,)                                                                                                                                              |
    |                       |             | - **Name:** field_of_view                                                                                                                                         |
    |                       |             |                                                                                                                                                                   |
    +-----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..focal_depth         | attribute   | Focal depth offset, in meters                                                                                                                                     |
    |                       |             |                                                                                                                                                                   |
    |                       |             | - **Data Type:** float                                                                                                                                            |
    |                       |             | - **Name:** focal_depth                                                                                                                                           |
    |                       |             |                                                                                                                                                                   |
    +-----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..format              | attribute   | Format of image. Right now only 'raw' supported                                                                                                                   |
    |                       |             |                                                                                                                                                                   |
    |                       |             | - **Data Type:** text                                                                                                                                             |
    |                       |             | - **Name:** format                                                                                                                                                |
    |                       |             |                                                                                                                                                                   |
    +-----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .sign_map             | dataset     | Sine of the angle between the direction of the gradient in axis_1 and axis_2                                                                                      |
    |                       |             |                                                                                                                                                                   |
    |                       |             | - **Data Type:** float32                                                                                                                                          |
    |                       |             | - **Dimensions:** ['num_rows', 'num_cols']                                                                                                                        |
    |                       |             | - **Shape:** [None, None]                                                                                                                                         |
    |                       |             | - **Name:** sign_map                                                                                                                                              |
    |                       |             |                                                                                                                                                                   |
    +-----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..dimension           | attribute   | Number of rows and columns in the image.                                                                                                                          |
    |                       |             |                                                                                                                                                                   |
    |                       |             |  **Additional Information:**  row, column representation is equivalent to height,width.                                                                           |
    |                       |             |                                                                                                                                                                   |
    |                       |             | - **Data Type:** int32                                                                                                                                            |
    |                       |             | - **Dimensions:** ['row_col']                                                                                                                                     |
    |                       |             | - **Shape:** (None,)                                                                                                                                              |
    |                       |             | - **Name:** dimension                                                                                                                                             |
    |                       |             |                                                                                                                                                                   |
    +-----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..field_of_view       | attribute   | Size of viewing area, in meters.                                                                                                                                  |
    |                       |             |                                                                                                                                                                   |
    |                       |             | - **Data Type:** float                                                                                                                                            |
    |                       |             | - **Dimensions:** ['row_col']                                                                                                                                     |
    |                       |             | - **Shape:** (None,)                                                                                                                                              |
    |                       |             | - **Name:** field_of_view                                                                                                                                         |
    |                       |             |                                                                                                                                                                   |
    +-----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .vasculature_image    | dataset     | Gray-scale anatomical image of cortical surface. Array structure: [rows][columns]                                                                                 |
    |                       |             |                                                                                                                                                                   |
    |                       |             | - **Data Type:** uint16                                                                                                                                           |
    |                       |             | - **Dimensions:** ['num_rows', 'num_cols']                                                                                                                        |
    |                       |             | - **Shape:** [None, None]                                                                                                                                         |
    |                       |             | - **Name:** vasculature_image                                                                                                                                     |
    |                       |             |                                                                                                                                                                   |
    +-----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..bits_per_pixel      | attribute   | Number of bits used to represent each value. This is necessary to determine maximum (white) pixel value                                                           |
    |                       |             |                                                                                                                                                                   |
    |                       |             | - **Data Type:** int32                                                                                                                                            |
    |                       |             | - **Name:** bits_per_pixel                                                                                                                                        |
    |                       |             |                                                                                                                                                                   |
    +-----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..dimension           | attribute   | Number of rows and columns in the image.                                                                                                                          |
    |                       |             |                                                                                                                                                                   |
    |                       |             |  **Additional Information:**  row, column representation is equivalent to height,width.                                                                           |
    |                       |             |                                                                                                                                                                   |
    |                       |             | - **Data Type:** int32                                                                                                                                            |
    |                       |             | - **Dimensions:** ['row_col']                                                                                                                                     |
    |                       |             | - **Shape:** (None,)                                                                                                                                              |
    |                       |             | - **Name:** dimension                                                                                                                                             |
    |                       |             |                                                                                                                                                                   |
    +-----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..field_of_view       | attribute   | Size of viewing area, in meters                                                                                                                                   |
    |                       |             |                                                                                                                                                                   |
    |                       |             | - **Data Type:** float                                                                                                                                            |
    |                       |             | - **Dimensions:** ['row_col']                                                                                                                                     |
    |                       |             | - **Shape:** (None,)                                                                                                                                              |
    |                       |             | - **Name:** field_of_view                                                                                                                                         |
    |                       |             |                                                                                                                                                                   |
    +-----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..format              | attribute   | Format of image. Right now only 'raw' supported                                                                                                                   |
    |                       |             |                                                                                                                                                                   |
    |                       |             | - **Data Type:** text                                                                                                                                             |
    |                       |             | - **Name:** format                                                                                                                                                |
    |                       |             |                                                                                                                                                                   |
    +-----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+



