.. _sec-ImagingRetinotopy:

ImagingRetinotopy
^^^^^^^^^^^^^^^^^

**Extends:** :ref:`Interface <sec-Interface>`

**Source Specification:** see :numref:`sec-ImagingRetinotopy-src`

**Overview:** Intrinsic signal optical imaging or widefield imaging for measuring retinotopy. Stores orthogonal maps (e.g., altitude/azimuth; radius/theta) of responses to specific stimuli and a combined polarity map from which to identify visual areas.<br />Note: for data consistency, all images and arrays are stored in the format [row][column] and [row, col], which equates to [y][x]. Field of view and dimension arrays may appear backward (i.e., y before x).


``ImagingRetinotopy`` extends ``Interface`` (see :numref:`sec-Interface`) and includes all elements of :ref:`Interface <sec-Interface>` with the following additions or changes.



.. figure:: ./_format_auto_docs/ImagingRetinotopy.*
    :alt: ImagingRetinotopy




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-ImagingRetinotopy-data:

.. table:: Datasets, Links, and Attributes contained in <ImagingRetinotopy>
    :class: longtable

    +----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | Id                   | Type        | Description                                                                                                                                                       |
    +======================+=============+===================================================================================================================================================================+
    | ImagingRetinotopy    | group       | Top level group for ImagingRetinotopy                                                                                                                             |
    +----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .help                | attribute   | Value is Intrinsic signal optical imaging or Widefield imaging for measuring retinotopy                                                                           |
    |                      |             |                                                                                                                                                                   |
    |                      |             | - **Data Type:** text                                                                                                                                             |
    |                      |             | - **Value:** Intrinsic signal optical imaging or Widefield imaging for measuring retinotopy                                                                       |
    |                      |             |                                                                                                                                                                   |
    +----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .axis_2_power_map    | dataset     | Power response on the second measured axis. Response is scaled so 0.0 is no power in the response and 1.0 is maximum relative power.                              |
    |                      |             |                                                                                                                                                                   |
    |                      |             | - **Quantity** 0 or 1                                                                                                                                             |
    |                      |             | - **Data Type:** float32                                                                                                                                          |
    |                      |             | - **Dimensions:** ['num_rows', 'num_cols']                                                                                                                        |
    |                      |             | - **Shape:** [None, None]                                                                                                                                         |
    |                      |             |                                                                                                                                                                   |
    +----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..dimension          | attribute   | Number of rows and columns in the image.                                                                                                                          |
    |                      |             |                                                                                                                                                                   |
    |                      |             |  **Additional Information:**  row, column representation is equivalent to height,width.                                                                           |
    |                      |             |                                                                                                                                                                   |
    |                      |             | - **Data Type:** int32                                                                                                                                            |
    |                      |             | - **Dimensions:** ['row_col']                                                                                                                                     |
    |                      |             | - **Shape:** (None,)                                                                                                                                              |
    |                      |             |                                                                                                                                                                   |
    +----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..field_of_view      | attribute   | Size of viewing area, in meters                                                                                                                                   |
    |                      |             |                                                                                                                                                                   |
    |                      |             | - **Data Type:** float                                                                                                                                            |
    |                      |             | - **Dimensions:** ['row_col']                                                                                                                                     |
    |                      |             | - **Shape:** (None,)                                                                                                                                              |
    |                      |             |                                                                                                                                                                   |
    +----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..unit               | attribute   | Unit that axis data is stored in (e.g., degrees)                                                                                                                  |
    |                      |             |                                                                                                                                                                   |
    |                      |             | - **Data Type:** text                                                                                                                                             |
    |                      |             |                                                                                                                                                                   |
    +----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .axis_1_phase_map    | dataset     | Phase response to stimulus on the first measured axis                                                                                                             |
    |                      |             |                                                                                                                                                                   |
    |                      |             | - **Data Type:** float32                                                                                                                                          |
    |                      |             | - **Dimensions:** ['num_rows', 'num_cols']                                                                                                                        |
    |                      |             | - **Shape:** [None, None]                                                                                                                                         |
    |                      |             |                                                                                                                                                                   |
    +----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..field_of_view      | attribute   | Size of viewing area, in meters                                                                                                                                   |
    |                      |             |                                                                                                                                                                   |
    |                      |             | - **Data Type:** float                                                                                                                                            |
    |                      |             | - **Dimensions:** ['row|column']                                                                                                                                  |
    |                      |             | - **Shape:** (None,)                                                                                                                                              |
    |                      |             |                                                                                                                                                                   |
    +----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..unit               | attribute   | Unit that axis data is stored in (e.g., degrees)                                                                                                                  |
    |                      |             |                                                                                                                                                                   |
    |                      |             | - **Data Type:** text                                                                                                                                             |
    |                      |             |                                                                                                                                                                   |
    +----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..dimension          | attribute   | Number of rows and columns in the image.                                                                                                                          |
    |                      |             |                                                                                                                                                                   |
    |                      |             |  **Additional Information:**  row, column representation is equivalent to height,width.                                                                           |
    |                      |             |                                                                                                                                                                   |
    |                      |             | - **Data Type:** int32                                                                                                                                            |
    |                      |             | - **Dimensions:** ['row_col']                                                                                                                                     |
    |                      |             | - **Shape:** (None,)                                                                                                                                              |
    |                      |             |                                                                                                                                                                   |
    +----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .vasculature_image   | dataset     | Gray-scale anatomical image of cortical surface. Array structure: [rows][columns]                                                                                 |
    |                      |             |                                                                                                                                                                   |
    |                      |             | - **Data Type:** uint16                                                                                                                                           |
    |                      |             | - **Dimensions:** ['num_rows', 'num_cols']                                                                                                                        |
    |                      |             | - **Shape:** [None, None]                                                                                                                                         |
    |                      |             |                                                                                                                                                                   |
    +----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..dimension          | attribute   | Number of rows and columns in the image.                                                                                                                          |
    |                      |             |                                                                                                                                                                   |
    |                      |             |  **Additional Information:**  row, column representation is equivalent to height,width.                                                                           |
    |                      |             |                                                                                                                                                                   |
    |                      |             | - **Data Type:** int32                                                                                                                                            |
    |                      |             | - **Dimensions:** ['row_col']                                                                                                                                     |
    |                      |             | - **Shape:** (None,)                                                                                                                                              |
    |                      |             |                                                                                                                                                                   |
    +----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..field_of_view      | attribute   | Size of viewing area, in meters                                                                                                                                   |
    |                      |             |                                                                                                                                                                   |
    |                      |             | - **Data Type:** float                                                                                                                                            |
    |                      |             | - **Dimensions:** ['row_col']                                                                                                                                     |
    |                      |             | - **Shape:** (None,)                                                                                                                                              |
    |                      |             |                                                                                                                                                                   |
    +----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..format             | attribute   | Format of image. Right now only 'raw' supported                                                                                                                   |
    |                      |             |                                                                                                                                                                   |
    |                      |             | - **Data Type:** text                                                                                                                                             |
    |                      |             |                                                                                                                                                                   |
    +----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..bits_per_pixel     | attribute   | Number of bits used to represent each value. This is necessary to determine maximum (white) pixel value                                                           |
    |                      |             |                                                                                                                                                                   |
    |                      |             | - **Data Type:** int32                                                                                                                                            |
    |                      |             |                                                                                                                                                                   |
    +----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .focal_depth_image   | dataset     | Gray-scale image taken with same settings/parameters (e.g., focal depth, wavelength) as data collection. Array format: [rows][columns]                            |
    |                      |             |                                                                                                                                                                   |
    |                      |             | - **Data Type:** uint16                                                                                                                                           |
    |                      |             | - **Dimensions:** ['num_rows', 'num_cols']                                                                                                                        |
    |                      |             | - **Shape:** [None, None]                                                                                                                                         |
    |                      |             |                                                                                                                                                                   |
    +----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..field_of_view      | attribute   | Size of viewing area, in meters                                                                                                                                   |
    |                      |             |                                                                                                                                                                   |
    |                      |             | - **Data Type:** float                                                                                                                                            |
    |                      |             | - **Dimensions:** ['row_col']                                                                                                                                     |
    |                      |             | - **Shape:** (None,)                                                                                                                                              |
    |                      |             |                                                                                                                                                                   |
    +----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..dimension          | attribute   | Number of rows and columns in the image.                                                                                                                          |
    |                      |             |                                                                                                                                                                   |
    |                      |             |  **Additional Information:**  row, column representation is equivalent to height,width.                                                                           |
    |                      |             |                                                                                                                                                                   |
    |                      |             | - **Data Type:** int32                                                                                                                                            |
    |                      |             | - **Dimensions:** ['row_col']                                                                                                                                     |
    |                      |             | - **Shape:** (None,)                                                                                                                                              |
    |                      |             |                                                                                                                                                                   |
    +----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..focal_depth        | attribute   | Focal depth offset, in meters                                                                                                                                     |
    |                      |             |                                                                                                                                                                   |
    |                      |             | - **Data Type:** float                                                                                                                                            |
    |                      |             |                                                                                                                                                                   |
    +----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..format             | attribute   | Format of image. Right now only 'raw' supported                                                                                                                   |
    |                      |             |                                                                                                                                                                   |
    |                      |             | - **Data Type:** text                                                                                                                                             |
    |                      |             |                                                                                                                                                                   |
    +----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..bits_per_pixel     | attribute   | Number of bits used to represent each value. This is necessary to determine maximum (white) pixel value                                                           |
    |                      |             |                                                                                                                                                                   |
    |                      |             | - **Data Type:** int32                                                                                                                                            |
    |                      |             |                                                                                                                                                                   |
    +----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .axis_1_power_map    | dataset     | Power response on the first measured axis. Response is scaled so 0.0 is no power in the response and 1.0 is maximum relative power.                               |
    |                      |             |                                                                                                                                                                   |
    |                      |             | - **Quantity** 0 or 1                                                                                                                                             |
    |                      |             | - **Data Type:** float32                                                                                                                                          |
    |                      |             | - **Dimensions:** ['num_rows', 'num_cols']                                                                                                                        |
    |                      |             | - **Shape:** [None, None]                                                                                                                                         |
    |                      |             |                                                                                                                                                                   |
    +----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..dimension          | attribute   | Number of rows and columns in the image.                                                                                                                          |
    |                      |             |                                                                                                                                                                   |
    |                      |             |  **Additional Information:**  row, column representation is equivalent to height,width.                                                                           |
    |                      |             |                                                                                                                                                                   |
    |                      |             | - **Data Type:** int32                                                                                                                                            |
    |                      |             | - **Dimensions:** ['row_col']                                                                                                                                     |
    |                      |             | - **Shape:** (None,)                                                                                                                                              |
    |                      |             |                                                                                                                                                                   |
    +----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..field_of_view      | attribute   | Size of viewing area, in meters                                                                                                                                   |
    |                      |             |                                                                                                                                                                   |
    |                      |             | - **Data Type:** float                                                                                                                                            |
    |                      |             | - **Dimensions:** ['row_col']                                                                                                                                     |
    |                      |             | - **Shape:** (None,)                                                                                                                                              |
    |                      |             |                                                                                                                                                                   |
    +----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..unit               | attribute   | Unit that axis data is stored in (e.g., degrees)                                                                                                                  |
    |                      |             |                                                                                                                                                                   |
    |                      |             | - **Data Type:** text                                                                                                                                             |
    |                      |             |                                                                                                                                                                   |
    +----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .sign_map            | dataset     | Sine of the angle between the direction of the gradient in axis_1 and axis_2                                                                                      |
    |                      |             |                                                                                                                                                                   |
    |                      |             | - **Data Type:** float32                                                                                                                                          |
    |                      |             | - **Dimensions:** ['num_rows', 'num_cols']                                                                                                                        |
    |                      |             | - **Shape:** [None, None]                                                                                                                                         |
    |                      |             |                                                                                                                                                                   |
    +----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..dimension          | attribute   | Number of rows and columns in the image.                                                                                                                          |
    |                      |             |                                                                                                                                                                   |
    |                      |             |  **Additional Information:**  row, column representation is equivalent to height,width.                                                                           |
    |                      |             |                                                                                                                                                                   |
    |                      |             | - **Data Type:** int32                                                                                                                                            |
    |                      |             | - **Dimensions:** ['row_col']                                                                                                                                     |
    |                      |             | - **Shape:** (None,)                                                                                                                                              |
    |                      |             |                                                                                                                                                                   |
    +----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..field_of_view      | attribute   | Size of viewing area, in meters.                                                                                                                                  |
    |                      |             |                                                                                                                                                                   |
    |                      |             | - **Data Type:** float                                                                                                                                            |
    |                      |             | - **Dimensions:** ['row_col']                                                                                                                                     |
    |                      |             | - **Shape:** (None,)                                                                                                                                              |
    |                      |             |                                                                                                                                                                   |
    +----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .axis_2_phase_map    | dataset     | Phase response to stimulus on the second measured axis                                                                                                            |
    |                      |             |                                                                                                                                                                   |
    |                      |             | - **Data Type:** float32                                                                                                                                          |
    |                      |             | - **Dimensions:** ['num_rows', 'num_cols']                                                                                                                        |
    |                      |             | - **Shape:** [None, None]                                                                                                                                         |
    |                      |             |                                                                                                                                                                   |
    +----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..field_of_view      | attribute   | Size of viewing area, in meters                                                                                                                                   |
    |                      |             |                                                                                                                                                                   |
    |                      |             | - **Data Type:** float                                                                                                                                            |
    |                      |             | - **Dimensions:** ['row_col']                                                                                                                                     |
    |                      |             | - **Shape:** (None,)                                                                                                                                              |
    |                      |             |                                                                                                                                                                   |
    +----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..unit               | attribute   | Unit that axis data is stored in (e.g., degrees)                                                                                                                  |
    |                      |             |                                                                                                                                                                   |
    |                      |             | - **Data Type:** text                                                                                                                                             |
    |                      |             |                                                                                                                                                                   |
    +----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | ..dimension          | attribute   | Number of rows and columns in the image.                                                                                                                          |
    |                      |             |                                                                                                                                                                   |
    |                      |             |  **Additional Information:**  row, column representation is equivalent to height,width.                                                                           |
    |                      |             |                                                                                                                                                                   |
    |                      |             | - **Data Type:** int32                                                                                                                                            |
    |                      |             | - **Dimensions:** ['row_col']                                                                                                                                     |
    |                      |             | - **Shape:** (None,)                                                                                                                                              |
    |                      |             |                                                                                                                                                                   |
    +----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .axis_descriptions   | dataset     | Two-element array describing the contents of the two response axis fields. Description should be something like ['altitude', 'azimuth'] or '['radius', 'theta']   |
    |                      |             |                                                                                                                                                                   |
    |                      |             | - **Data Type:** text                                                                                                                                             |
    |                      |             | - **Dimensions:** ['2']                                                                                                                                           |
    |                      |             | - **Shape:** [None]                                                                                                                                               |
    |                      |             |                                                                                                                                                                   |
    +----------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+



