.. _sec-NWBFile:

NWBFile
^^^^^^^

**Source Specification:** see :numref:`sec-NWBFile-src`

**Overview:** Top level of NWB file.




.. figure:: ./_format_auto_docs/NWBFile.*
    :alt: NWBFile




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-NWBFile-data:

.. table:: Datasets, Links, and Attributes contained in <NWBFile>
    :class: longtable

    +------------------------+-----------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | Id                     | Type      | Description                                                                                                                                                                                                                                                        |
    +========================+===========+====================================================================================================================================================================================================================================================================+
    | root                   | group     | Top level group for root                                                                                                                                                                                                                                           |
    +------------------------+-----------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .nwb_version           | dataset   | File version string.                                                                                                                                                                                                                                               |
    |                        |           |                                                                                                                                                                                                                                                                    |
    |                        |           | **Comment:**  Eg, NWB-1.0.0. This will be the name of the format with trailing major, minor and patch numbers.                                                                                                                                                     |
    |                        |           |                                                                                                                                                                                                                                                                    |
    |                        |           | - **Data Type:** text                                                                                                                                                                                                                                              |
    |                        |           |                                                                                                                                                                                                                                                                    |
    +------------------------+-----------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .identifier            | dataset   | A unique text identifier for the file.                                                                                                                                                                                                                             |
    |                        |           |                                                                                                                                                                                                                                                                    |
    |                        |           | **Comment:**  Eg, concatenated lab name, file creation date/time and experimentalist, or a hash of these and/or other values. The goal is that the string should be unique to all other files.                                                                     |
    |                        |           |                                                                                                                                                                                                                                                                    |
    |                        |           | - **Data Type:** text                                                                                                                                                                                                                                              |
    |                        |           |                                                                                                                                                                                                                                                                    |
    +------------------------+-----------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .file_create_date      | dataset   | Time file was created, UTC, and subsequent modifications to file.                                                                                                                                                                                                  |
    |                        |           |                                                                                                                                                                                                                                                                    |
    |                        |           | **Comment:**  Date + time, Use ISO format (eg, ISO 8601) or a format that is easy to read and unambiguous. File can be created after the experiment was run, so this may differ from experiment start time. Each modifictation to file adds new entry to array.    |
    |                        |           |                                                                                                                                                                                                                                                                    |
    |                        |           | - **Data Type:** text                                                                                                                                                                                                                                              |
    |                        |           | - **Dimensions:** ['*unlimited*']                                                                                                                                                                                                                                  |
    |                        |           | - **Shape:** [None]                                                                                                                                                                                                                                                |
    |                        |           |                                                                                                                                                                                                                                                                    |
    +------------------------+-----------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .session_description   | dataset   | One or two sentences describing the experiment and data in the file.                                                                                                                                                                                               |
    |                        |           |                                                                                                                                                                                                                                                                    |
    |                        |           | - **Data Type:** text                                                                                                                                                                                                                                              |
    |                        |           |                                                                                                                                                                                                                                                                    |
    +------------------------+-----------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .session_start_time    | dataset   | Time of experiment/session start, UTC.                                                                                                                                                                                                                             |
    |                        |           |                                                                                                                                                                                                                                                                    |
    |                        |           | **Comment:**  Date + time, Use ISO format (eg, ISO 8601) or an easy-to-read and unambiguous format. All times stored in the file use this time as reference (ie, time zero)                                                                                        |
    |                        |           |                                                                                                                                                                                                                                                                    |
    |                        |           | - **Data Type:** text                                                                                                                                                                                                                                              |
    |                        |           |                                                                                                                                                                                                                                                                    |
    +------------------------+-----------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-NWBFile-groups:

.. table:: Groups contained in <NWBFile>
    :class: longtable

    +----------------+---------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | Id             | Type    | Description                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
    +================+=========+=====================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================+
    | root           | group   | Top level group for root                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
    +----------------+---------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .acquisition   | group   | Data streams recorded from the system, including ephys, ophys, tracking, etc.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
    |                |         |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     |
    |                |         | **Comment:**  This group is read-only after the experiment is completed and timestamps are corrected to a common timebase. The data stored here may be links to raw data stored in external HDF5 files. This will allow keeping bulky raw data out of the file while preserving the option of keeping some/all in the file.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
    |                |         |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     |
    |                |         | **Additional Information:**  Acquired data includes tracking and experimental data streams (ie, everything measured from the system).If bulky data is stored in the /acquisition group, the data can exist in a separate HDF5 file that is linked to by the file being used for processing and analysis.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
    +----------------+---------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .analysis      | group   | Lab-specific and custom scientific analysis of data. There is no defined format for the content of this group - the format is up to the individual user/lab.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
    |                |         |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     |
    |                |         | **Comment:**  To facilitate sharing analysis data between labs, the contents here should be stored in standard types (eg, INCF types) and appropriately documented.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 |
    |                |         |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     |
    |                |         | **Additional Information:**  The file can store lab-specific and custom data analysis without restriction on its form or schema, reducing data formatting restrictions on end users. Such data should be placed in the analysis group. The analysis data should be documented so that it is sharable with other labs                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                |
    +----------------+---------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .epochs        | group   | Experimental intervals, whether that be logically distinct sub-experiments having a particular scientific goal, trials during an experiment, or epochs deriving from analysis of data.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
    |                |         |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     |
    |                |         | **Comment:**  Epochs provide pointers to time series that are relevant to the epoch, and windows into the data in those time series (i.e., the start and end indices of TimeSeries::data[] that overlap with the epoch). This allows easy access to a range of data in specific experimental intervals.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
    |                |         |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     |
    |                |         | **Additional Information:**  An experiment can be separated into one or many logical intervals, with the order and duration of these intervals often definable before the experiment starts. In this document, and in the context of NWB, these intervals are called 'epochs'. Epochs have acquisition and stimulus data associated with them, and different epochs can overlap. Examples of epochs are the time when a rat runs around an enclosure or maze as well as intervening sleep sessions; the presentation of a set of visual stimuli to a mouse running on a wheel; or the uninterrupted presentation of current to a patch-clamped cell. Epochs can be limited to the interval of a particular stimulus, or they can span multiple stimuli. Different windows into the same time series can be achieved by including multiple instances of that time series, each with different start/stop times.                                      |
    +----------------+---------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .processing    | group   | The home for processing Modules. These modules perform intermediate analysis of data that is necessary to perform before scientific analysis. Examples include spike clustering, extracting position from tracking data, stitching together image slices.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
    |                |         |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     |
    |                |         | **Comment:**  Modules are defined below. They can be large and express many data sets from relatively complex analysis (e.g., spike detection and clustering) or small, representing extraction of position information from tracking video, or even binary lick/no-lick decisions. Common software tools (e.g., klustakwik, MClust) are expected to read/write data here.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
    |                |         |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     |
    |                |         | **Additional Information:**  'Processing' refers to intermediate analysis of the acquired data to make it more amenable to scientific analysis. These are performed using Modules, as defined above. All modules reside in the processing group.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    |
    +----------------+---------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .stimulus      | group   | Data pushed into the system (eg, video stimulus, sound, voltage, etc) and secondary representations of that data (eg, measurements of something used as a stimulus)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 |
    |                |         |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     |
    |                |         | **Comment:**  This group is read-only after experiment complete and timestamps are corrected to common timebase. Stores both presented stimuli and stimulus templates, the latter in case the same stimulus is presented multiple times, or is pulled from an external stimulus library.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
    |                |         |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     |
    |                |         | **Additional Information:**  Stimuli are here defined as any signal that is pushed into the system as part of the experiment (eg, sound, video, voltage, etc). Many different experiments can use the same stimuli, and stimuli can be re-used during an experiment. The stimulus group is organized so that one version of template stimuli can be stored and these be used multiple times. These templates can exist in the present file or can be HDF5-linked to a remote library file.                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
    +----------------+---------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .general       | group   | Experimental metadata, including protocol, notes and description of hardware device(s).                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
    |                |         |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     |
    |                |         | **Comment:**  The metadata stored in this section should be used to describe the experiment. Metadata necessary for interpreting the data is stored with the data.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
    |                |         |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     |
    |                |         | **Additional Information:**  General experimental metadata, including animal strain, experimental protocols, experimenter, devices, etc, are stored under 'general'. Core metadata (e.g., that required to interpret data fields) is stored with the data itself, and implicitly defined by the file specification (eg, time is in seconds). The strategy used here for storing non-core metadata is to use free-form text fields, such as would appear in sentences or paragraphs from a Methods section. Metadata fields are text to enable them to be more general, for example to represent ranges instead of numerical values. Machine-readable metadata is stored as attributes to these free-form datasets. <br /><br />All entries in the below table are to be included when data is present. Unused groups (e.g., intracellular_ephys in an optophysiology experiment) should not be created unless there is data to store within them.   |
    +----------------+---------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+


Groups: /acquisition
""""""""""""""""""""

Data streams recorded from the system, including ephys, ophys, tracking, etc. 

**Comment:**  This group is read-only after the experiment is completed and timestamps are corrected to a common timebase. The data stored here may be links to raw data stored in external HDF5 files. This will allow keeping bulky raw data out of the file while preserving the option of keeping some/all in the file. 

**Additional Information:**  Acquired data includes tracking and experimental data streams (ie, everything measured from the system).If bulky data is stored in the /acquisition group, the data can exist in a separate HDF5 file that is linked to by the file being used for processing and analysis.



.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. table:: Groups contained in <acquisition>
    :class: longtable

    +---------------+---------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | Id            | Type    | Description                                                                                                                                                                                                     |
    +===============+=========+=================================================================================================================================================================================================================+
    | acquisition   | group   | Top level group for acquisition                                                                                                                                                                                 |
    +---------------+---------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .images       | group   | Acquired images                                                                                                                                                                                                 |
    +---------------+---------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .timeseries   | group   | Acquired TimeSeries.                                                                                                                                                                                            |
    |               |         |                                                                                                                                                                                                                 |
    |               |         | **Comment:**  When importing acquisition data to an NWB file, all acquisition/tracking/stimulus data must already be aligned to a common time frame. It is assumed that this task has already been performed.   |
    +---------------+---------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+


Groups: /acquisition/images
"""""""""""""""""""""""""""

Acquired images



.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. table:: Datasets, Links, and Attributes contained in ``/acquisition/images``
    :class: longtable

    +-----------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------+
    | Id              | Type        | Description                                                                                                                               |
    +=================+=============+===========================================================================================================================================+
    | images          | group       | Top level group for images                                                                                                                |
    +-----------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------+
    | .<Image>        | dataset     | Photograph of experiment or experimental setup (video also OK).                                                                           |
    |                 |             |                                                                                                                                           |
    |                 |             | **Comment:**  Name is arbitrary.  Data is stored as a single binary object (HDF5 opaque type).                                            |
    |                 |             |                                                                                                                                           |
    |                 |             | - **Quantity** 0 or more                                                                                                                  |
    |                 |             | - **Data Type:** binary                                                                                                                   |
    |                 |             | - **Neurodata Type:** Image                                                                                                               |
    |                 |             |                                                                                                                                           |
    +-----------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------+
    | ..format        | attribute   | Format of the image.                                                                                                                      |
    |                 |             |                                                                                                                                           |
    |                 |             | **Comment:**  eg, jpg, png, mpeg                                                                                                          |
    |                 |             |                                                                                                                                           |
    |                 |             | - **Data Type:** text                                                                                                                     |
    |                 |             |                                                                                                                                           |
    +-----------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------+
    | ..description   | attribute   | Human description of image.                                                                                                               |
    |                 |             |                                                                                                                                           |
    |                 |             | **Comment:**  If image is of slice data, include slice thickness and orientation, and reference to appropriate entry in /general/slices   |
    |                 |             |                                                                                                                                           |
    |                 |             | - **Data Type:** text                                                                                                                     |
    |                 |             |                                                                                                                                           |
    +-----------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------+


Groups: /acquisition/timeseries
"""""""""""""""""""""""""""""""

Acquired TimeSeries.

**Comment:**  When importing acquisition data to an NWB file, all acquisition/tracking/stimulus data must already be aligned to a common time frame. It is assumed that this task has already been performed.



.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. table:: Groups contained in <timeseries>
    :class: longtable

    +-----------------------------------------+---------+-----------------------------------------------------------------------+
    | Id                                      | Type    | Description                                                           |
    +=========================================+=========+=======================================================================+
    | timeseries                              | group   | Top level group for timeseries                                        |
    +-----------------------------------------+---------+-----------------------------------------------------------------------+
    | .<:ref:`TimeSeries <sec-TimeSeries>`>   | group   | TimeSeries object containing data generated during data acquisition   |
    |                                         |         |                                                                       |
    |                                         |         | - **Extends:** :ref:`TimeSeries <sec-TimeSeries>`                     |
    |                                         |         |                                                                       |
    +-----------------------------------------+---------+-----------------------------------------------------------------------+


Groups: /acquisition/timeseries/<TimeSeries>
""""""""""""""""""""""""""""""""""""""""""""

TimeSeries object containing data generated during data acquisition



- **Extends:** :ref:`TimeSeries <sec-TimeSeries>`

Groups: /analysis
"""""""""""""""""

Lab-specific and custom scientific analysis of data. There is no defined format for the content of this group - the format is up to the individual user/lab. 

**Comment:**  To facilitate sharing analysis data between labs, the contents here should be stored in standard types (eg, INCF types) and appropriately documented. 

**Additional Information:**  The file can store lab-specific and custom data analysis without restriction on its form or schema, reducing data formatting restrictions on end users. Such data should be placed in the analysis group. The analysis data should be documented so that it is sharable with other labs


Groups: /epochs
"""""""""""""""

Experimental intervals, whether that be logically distinct sub-experiments having a particular scientific goal, trials during an experiment, or epochs deriving from analysis of data.  

**Comment:**  Epochs provide pointers to time series that are relevant to the epoch, and windows into the data in those time series (i.e., the start and end indices of TimeSeries::data[] that overlap with the epoch). This allows easy access to a range of data in specific experimental intervals. 

**Additional Information:**  An experiment can be separated into one or many logical intervals, with the order and duration of these intervals often definable before the experiment starts. In this document, and in the context of NWB, these intervals are called 'epochs'. Epochs have acquisition and stimulus data associated with them, and different epochs can overlap. Examples of epochs are the time when a rat runs around an enclosure or maze as well as intervening sleep sessions; the presentation of a set of visual stimuli to a mouse running on a wheel; or the uninterrupted presentation of current to a patch-clamped cell. Epochs can be limited to the interval of a particular stimulus, or they can span multiple stimuli. Different windows into the same time series can be achieved by including multiple instances of that time series, each with different start/stop times.



.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. table:: Datasets, Links, and Attributes contained in ``/epochs``
    :class: longtable

    +----------+-------------+---------------------------------------------------------------------------------------------------+
    | Id       | Type        | Description                                                                                       |
    +==========+=============+===================================================================================================+
    | epochs   | group       | Top level group for epochs                                                                        |
    +----------+-------------+---------------------------------------------------------------------------------------------------+
    | .tags    | attribute   | A sorted list of the different tags used by epochs.                                               |
    |          |             |                                                                                                   |
    |          |             | **Comment:** This is a sorted list of all tags that are in any of the <epoch_X>/tags datasets`.   |
    |          |             |                                                                                                   |
    |          |             | - **Data Type:** text                                                                             |
    |          |             | - **Dimensions:** ['num_tags']                                                                    |
    |          |             | - **Shape:** (None,)                                                                              |
    |          |             |                                                                                                   |
    +----------+-------------+---------------------------------------------------------------------------------------------------+



.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. table:: Groups contained in <epochs>
    :class: longtable

    +-------------------------------+---------+-----------------------------------------------------------------------------+
    | Id                            | Type    | Description                                                                 |
    +===============================+=========+=============================================================================+
    | epochs                        | group   | Top level group for epochs                                                  |
    +-------------------------------+---------+-----------------------------------------------------------------------------+
    | .<:ref:`Epoch <sec-Epoch>`>   | group   | One of possibly many different experimental epoch                           |
    |                               |         |                                                                             |
    |                               |         | **Comment:**  Name is arbitrary but must be unique within the experiment.   |
    |                               |         |                                                                             |
    |                               |         | - **Quantity** 0 or more                                                    |
    |                               |         | - **Extends:** :ref:`Epoch <sec-Epoch>`                                     |
    |                               |         |                                                                             |
    +-------------------------------+---------+-----------------------------------------------------------------------------+


Groups: /epochs/<Epoch>
"""""""""""""""""""""""

One of possibly many different experimental epoch

**Comment:**  Name is arbitrary but must be unique within the experiment.



- **Quantity** 0 or more
- **Extends:** :ref:`Epoch <sec-Epoch>`

Groups: /processing
"""""""""""""""""""

The home for processing Modules. These modules perform intermediate analysis of data that is necessary to perform before scientific analysis. Examples include spike clustering, extracting position from tracking data, stitching together image slices. 

**Comment:**  Modules are defined below. They can be large and express many data sets from relatively complex analysis (e.g., spike detection and clustering) or small, representing extraction of position information from tracking video, or even binary lick/no-lick decisions. Common software tools (e.g., klustakwik, MClust) are expected to read/write data here. 

**Additional Information:**  'Processing' refers to intermediate analysis of the acquired data to make it more amenable to scientific analysis. These are performed using Modules, as defined above. All modules reside in the processing group.


Groups: /stimulus
"""""""""""""""""

Data pushed into the system (eg, video stimulus, sound, voltage, etc) and secondary representations of that data (eg, measurements of something used as a stimulus) 

**Comment:**  This group is read-only after experiment complete and timestamps are corrected to common timebase. Stores both presented stimuli and stimulus templates, the latter in case the same stimulus is presented multiple times, or is pulled from an external stimulus library.

**Additional Information:**  Stimuli are here defined as any signal that is pushed into the system as part of the experiment (eg, sound, video, voltage, etc). Many different experiments can use the same stimuli, and stimuli can be re-used during an experiment. The stimulus group is organized so that one version of template stimuli can be stored and these be used multiple times. These templates can exist in the present file or can be HDF5-linked to a remote library file.



.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. table:: Groups contained in <stimulus>
    :class: longtable

    +-----------------+---------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | Id              | Type    | Description                                                                                                                                                                                                                                        |
    +=================+=========+====================================================================================================================================================================================================================================================+
    | stimulus        | group   | Top level group for stimulus                                                                                                                                                                                                                       |
    +-----------------+---------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .templates      | group   | Template stimuli.                                                                                                                                                                                                                                  |
    |                 |         |                                                                                                                                                                                                                                                    |
    |                 |         | **Comment:**  Time stamps in templates are based on stimulus design and are relative to the beginning of the stimulus. When templates are used, the stimulus instances must convert presentation times to the experiment's time reference frame.   |
    +-----------------+---------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .presentation   | group   | Stimuli presented during the experiment.                                                                                                                                                                                                           |
    +-----------------+---------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+


Groups: /stimulus/templates
"""""""""""""""""""""""""""

Template stimuli. 

**Comment:**  Time stamps in templates are based on stimulus design and are relative to the beginning of the stimulus. When templates are used, the stimulus instances must convert presentation times to the experiment's time reference frame.



.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. table:: Groups contained in <templates>
    :class: longtable

    +-----------------------------------------+---------+--------------------------------------------------------------------+
    | Id                                      | Type    | Description                                                        |
    +=========================================+=========+====================================================================+
    | templates                               | group   | Top level group for templates                                      |
    +-----------------------------------------+---------+--------------------------------------------------------------------+
    | .<:ref:`TimeSeries <sec-TimeSeries>`>   | group   | TimeSeries objects containing template data of presented stimuli   |
    |                                         |         |                                                                    |
    |                                         |         | - **Extends:** :ref:`TimeSeries <sec-TimeSeries>`                  |
    |                                         |         |                                                                    |
    +-----------------------------------------+---------+--------------------------------------------------------------------+


Groups: /stimulus/templates/<TimeSeries>
""""""""""""""""""""""""""""""""""""""""

TimeSeries objects containing template data of presented stimuli



- **Extends:** :ref:`TimeSeries <sec-TimeSeries>`

Groups: /stimulus/presentation
""""""""""""""""""""""""""""""

Stimuli presented during the experiment.



.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. table:: Groups contained in <presentation>
    :class: longtable

    +-----------------------------------------+---------+-----------------------------------------------------------+
    | Id                                      | Type    | Description                                               |
    +=========================================+=========+===========================================================+
    | presentation                            | group   | Top level group for presentation                          |
    +-----------------------------------------+---------+-----------------------------------------------------------+
    | .<:ref:`TimeSeries <sec-TimeSeries>`>   | group   | TimeSeries objects containing data of presented stimuli   |
    |                                         |         |                                                           |
    |                                         |         | - **Extends:** :ref:`TimeSeries <sec-TimeSeries>`         |
    |                                         |         |                                                           |
    +-----------------------------------------+---------+-----------------------------------------------------------+


Groups: /stimulus/presentation/<TimeSeries>
"""""""""""""""""""""""""""""""""""""""""""

TimeSeries objects containing data of presented stimuli



- **Extends:** :ref:`TimeSeries <sec-TimeSeries>`

Groups: /general
""""""""""""""""

Experimental metadata, including protocol, notes and description of hardware device(s).  

**Comment:**  The metadata stored in this section should be used to describe the experiment. Metadata necessary for interpreting the data is stored with the data. 

**Additional Information:**  General experimental metadata, including animal strain, experimental protocols, experimenter, devices, etc, are stored under 'general'. Core metadata (e.g., that required to interpret data fields) is stored with the data itself, and implicitly defined by the file specification (eg, time is in seconds). The strategy used here for storing non-core metadata is to use free-form text fields, such as would appear in sentences or paragraphs from a Methods section. Metadata fields are text to enable them to be more general, for example to represent ranges instead of numerical values. Machine-readable metadata is stored as attributes to these free-form datasets. <br /><br />All entries in the below table are to be included when data is present. Unused groups (e.g., intracellular_ephys in an optophysiology experiment) should not be created unless there is data to store within them.



.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. table:: Datasets, Links, and Attributes contained in ``/general``
    :class: longtable

    +---------------------------+-------------+---------------------------------------------------------------------------------------------------------------------------------+
    | Id                        | Type        | Description                                                                                                                     |
    +===========================+=============+=================================================================================================================================+
    | general                   | group       | Top level group for general                                                                                                     |
    +---------------------------+-------------+---------------------------------------------------------------------------------------------------------------------------------+
    | .protocol                 | dataset     | Experimetnal protocol, if applicable.                                                                                           |
    |                           |             |                                                                                                                                 |
    |                           |             | **Comment:**  E.g., include IACUC protocol                                                                                      |
    |                           |             |                                                                                                                                 |
    |                           |             | - **Quantity** 0 or 1                                                                                                           |
    |                           |             | - **Data Type:** text                                                                                                           |
    |                           |             |                                                                                                                                 |
    +---------------------------+-------------+---------------------------------------------------------------------------------------------------------------------------------+
    | .experiment_description   | dataset     | General description of the experiment.                                                                                          |
    |                           |             |                                                                                                                                 |
    |                           |             | **Comment:**  Can be from Methods                                                                                               |
    |                           |             |                                                                                                                                 |
    |                           |             | - **Quantity** 0 or 1                                                                                                           |
    |                           |             | - **Data Type:** text                                                                                                           |
    |                           |             |                                                                                                                                 |
    +---------------------------+-------------+---------------------------------------------------------------------------------------------------------------------------------+
    | .related_publications     | dataset     | Publication information.                                                                                                        |
    |                           |             |                                                                                                                                 |
    |                           |             | **Comment:**  PMID, DOI, URL, etc. If multiple, concatenate together and describe which is which. such as PMID, DOI, URL, etc   |
    |                           |             |                                                                                                                                 |
    |                           |             | - **Quantity** 0 or 1                                                                                                           |
    |                           |             | - **Data Type:** text                                                                                                           |
    |                           |             |                                                                                                                                 |
    +---------------------------+-------------+---------------------------------------------------------------------------------------------------------------------------------+
    | .session_id               | dataset     | Lab-specific ID for the session.                                                                                                |
    |                           |             |                                                                                                                                 |
    |                           |             | **Comment:**  Only 1 session_id per file, with all time aligned to experiment start time.                                       |
    |                           |             |                                                                                                                                 |
    |                           |             | - **Quantity** 0 or 1                                                                                                           |
    |                           |             | - **Data Type:** text                                                                                                           |
    |                           |             |                                                                                                                                 |
    +---------------------------+-------------+---------------------------------------------------------------------------------------------------------------------------------+
    | .lab                      | dataset     | Lab where experiment was performed                                                                                              |
    |                           |             |                                                                                                                                 |
    |                           |             | - **Quantity** 0 or 1                                                                                                           |
    |                           |             | - **Data Type:** text                                                                                                           |
    |                           |             |                                                                                                                                 |
    +---------------------------+-------------+---------------------------------------------------------------------------------------------------------------------------------+
    | .source_script            | dataset     | Script file used to create this NWB file.                                                                                       |
    |                           |             |                                                                                                                                 |
    |                           |             | - **Quantity** 0 or 1                                                                                                           |
    |                           |             | - **Data Type:** text                                                                                                           |
    |                           |             |                                                                                                                                 |
    +---------------------------+-------------+---------------------------------------------------------------------------------------------------------------------------------+
    | ..file_name               | attribute   | Name of script file                                                                                                             |
    |                           |             |                                                                                                                                 |
    |                           |             | - **Data Type:** text                                                                                                           |
    |                           |             |                                                                                                                                 |
    +---------------------------+-------------+---------------------------------------------------------------------------------------------------------------------------------+
    | .data_collection          | dataset     | Notes about data collection and analysis.                                                                                       |
    |                           |             |                                                                                                                                 |
    |                           |             | **Comment:**  Can be from Methods                                                                                               |
    |                           |             |                                                                                                                                 |
    |                           |             | - **Quantity** 0 or 1                                                                                                           |
    |                           |             | - **Data Type:** text                                                                                                           |
    |                           |             |                                                                                                                                 |
    +---------------------------+-------------+---------------------------------------------------------------------------------------------------------------------------------+
    | .surgery                  | dataset     | Narrative description about surgery/surgeries, including date(s) and who performed surgery.                                     |
    |                           |             |                                                                                                                                 |
    |                           |             | **Comment:**  Much can be copied from Methods                                                                                   |
    |                           |             |                                                                                                                                 |
    |                           |             | - **Quantity** 0 or 1                                                                                                           |
    |                           |             | - **Data Type:** text                                                                                                           |
    |                           |             |                                                                                                                                 |
    +---------------------------+-------------+---------------------------------------------------------------------------------------------------------------------------------+
    | .institution              | dataset     | Institution(s) where experiment was performed                                                                                   |
    |                           |             |                                                                                                                                 |
    |                           |             | - **Quantity** 0 or 1                                                                                                           |
    |                           |             | - **Data Type:** text                                                                                                           |
    |                           |             |                                                                                                                                 |
    +---------------------------+-------------+---------------------------------------------------------------------------------------------------------------------------------+
    | .experimenter             | dataset     | Name of person who performed the experiment.                                                                                    |
    |                           |             |                                                                                                                                 |
    |                           |             | **Comment:**  More than one person OK. Can specify roles of different people involved.                                          |
    |                           |             |                                                                                                                                 |
    |                           |             | - **Quantity** 0 or 1                                                                                                           |
    |                           |             | - **Data Type:** text                                                                                                           |
    |                           |             |                                                                                                                                 |
    +---------------------------+-------------+---------------------------------------------------------------------------------------------------------------------------------+
    | .pharmacology             | dataset     | Description of drugs used, including how and when they were administered.                                                       |
    |                           |             |                                                                                                                                 |
    |                           |             | **Comment:**  Anesthesia(s), painkiller(s), etc., plus dosage, concentration, etc.                                              |
    |                           |             |                                                                                                                                 |
    |                           |             | - **Quantity** 0 or 1                                                                                                           |
    |                           |             | - **Data Type:** text                                                                                                           |
    |                           |             |                                                                                                                                 |
    +---------------------------+-------------+---------------------------------------------------------------------------------------------------------------------------------+
    | .notes                    | dataset     | Notes about the experiment.                                                                                                     |
    |                           |             |                                                                                                                                 |
    |                           |             | **Comment:**  Things particular to this experiment                                                                              |
    |                           |             |                                                                                                                                 |
    |                           |             | - **Quantity** 0 or 1                                                                                                           |
    |                           |             | - **Data Type:** text                                                                                                           |
    |                           |             |                                                                                                                                 |
    +---------------------------+-------------+---------------------------------------------------------------------------------------------------------------------------------+
    | .stimulus                 | dataset     | Notes about stimuli, such as how and where presented.                                                                           |
    |                           |             |                                                                                                                                 |
    |                           |             | **Comment:**  Can be from Methods                                                                                               |
    |                           |             |                                                                                                                                 |
    |                           |             | - **Quantity** 0 or 1                                                                                                           |
    |                           |             | - **Data Type:** text                                                                                                           |
    |                           |             |                                                                                                                                 |
    +---------------------------+-------------+---------------------------------------------------------------------------------------------------------------------------------+
    | .slices                   | dataset     | Description of slices, including information about preparation thickness, orientation, temperature and bath solution            |
    |                           |             |                                                                                                                                 |
    |                           |             | - **Quantity** 0 or 1                                                                                                           |
    |                           |             | - **Data Type:** text                                                                                                           |
    |                           |             |                                                                                                                                 |
    +---------------------------+-------------+---------------------------------------------------------------------------------------------------------------------------------+
    | .virus                    | dataset     | Information about virus(es) used in experiments, including virus ID, source, date made, injection location, volume, etc         |
    |                           |             |                                                                                                                                 |
    |                           |             | - **Quantity** 0 or 1                                                                                                           |
    |                           |             | - **Data Type:** text                                                                                                           |
    |                           |             |                                                                                                                                 |
    +---------------------------+-------------+---------------------------------------------------------------------------------------------------------------------------------+



.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. table:: Groups contained in <general>
    :class: longtable

    +------------------------+---------+----------------------------------------------------------------------------+
    | Id                     | Type    | Description                                                                |
    +========================+=========+============================================================================+
    | general                | group   | Top level group for general                                                |
    +------------------------+---------+----------------------------------------------------------------------------+
    | .subject               | group   | Information about the animal or person from which the data was measured.   |
    |                        |         |                                                                            |
    |                        |         | - **Quantity** 0 or 1                                                      |
    |                        |         |                                                                            |
    +------------------------+---------+----------------------------------------------------------------------------+
    | .specifications        | group   | Group for storing format specification files.                              |
    |                        |         |                                                                            |
    |                        |         | - **Quantity** 0 or 1                                                      |
    |                        |         |                                                                            |
    +------------------------+---------+----------------------------------------------------------------------------+
    | .devices               | group   | Description of hardware devices used during experiment.                    |
    |                        |         |                                                                            |
    |                        |         | **Comment:**  Eg, monitors, ADC boards, microscopes, etc                   |
    |                        |         |                                                                            |
    |                        |         | - **Quantity** 0 or 1                                                      |
    |                        |         |                                                                            |
    +------------------------+---------+----------------------------------------------------------------------------+
    | .extracellular_ephys   | group   | Metadata related to extracellular electrophysiology.                       |
    |                        |         |                                                                            |
    |                        |         | - **Quantity** 0 or 1                                                      |
    |                        |         |                                                                            |
    +------------------------+---------+----------------------------------------------------------------------------+
    | .intracellular_ephys   | group   | Metadata related to intracellular electrophysiology                        |
    |                        |         |                                                                            |
    |                        |         | - **Quantity** 0 or 1                                                      |
    |                        |         |                                                                            |
    +------------------------+---------+----------------------------------------------------------------------------+
    | .optogenetics          | group   | Metadata describing optogenetic stimuluation                               |
    |                        |         |                                                                            |
    |                        |         | - **Quantity** 0 or 1                                                      |
    |                        |         |                                                                            |
    +------------------------+---------+----------------------------------------------------------------------------+
    | .optophysiology        | group   | Metadata related to optophysiology.                                        |
    |                        |         |                                                                            |
    |                        |         | - **Quantity** 0 or 1                                                      |
    |                        |         |                                                                            |
    +------------------------+---------+----------------------------------------------------------------------------+


Groups: /general/subject
""""""""""""""""""""""""

Information about the animal or person from which the data was measured.



- **Quantity** 0 or 1


.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. table:: Datasets, Links, and Attributes contained in ``/general/subject``
    :class: longtable

    +----------------+-----------+---------------------------------------------------------------------------------+
    | Id             | Type      | Description                                                                     |
    +================+===========+=================================================================================+
    | subject        | group     | Top level group for subject                                                     |
    +----------------+-----------+---------------------------------------------------------------------------------+
    | .weight        | dataset   | Weight at time of experiment, at time of surgery and at other important times   |
    |                |           |                                                                                 |
    |                |           | - **Quantity** 0 or 1                                                           |
    |                |           | - **Data Type:** text                                                           |
    |                |           |                                                                                 |
    +----------------+-----------+---------------------------------------------------------------------------------+
    | .genotype      | dataset   | Genetic strain                                                                  |
    |                |           |                                                                                 |
    |                |           | **Comment:**  If absent, assume Wild Type (WT)                                  |
    |                |           |                                                                                 |
    |                |           | - **Quantity** 0 or 1                                                           |
    |                |           | - **Data Type:** text                                                           |
    |                |           |                                                                                 |
    +----------------+-----------+---------------------------------------------------------------------------------+
    | .description   | dataset   | Description of subject and where subject came from (e.g., breeder, if animal)   |
    |                |           |                                                                                 |
    |                |           | - **Quantity** 0 or 1                                                           |
    |                |           | - **Data Type:** text                                                           |
    |                |           |                                                                                 |
    +----------------+-----------+---------------------------------------------------------------------------------+
    | .species       | dataset   | Species of subject                                                              |
    |                |           |                                                                                 |
    |                |           | - **Quantity** 0 or 1                                                           |
    |                |           | - **Data Type:** text                                                           |
    |                |           |                                                                                 |
    +----------------+-----------+---------------------------------------------------------------------------------+
    | .subject_id    | dataset   | ID of animal/person used/participating in experiment (lab convention)           |
    |                |           |                                                                                 |
    |                |           | - **Quantity** 0 or 1                                                           |
    |                |           | - **Data Type:** text                                                           |
    |                |           |                                                                                 |
    +----------------+-----------+---------------------------------------------------------------------------------+
    | .age           | dataset   | Age of subject                                                                  |
    |                |           |                                                                                 |
    |                |           | - **Quantity** 0 or 1                                                           |
    |                |           | - **Data Type:** text                                                           |
    |                |           |                                                                                 |
    +----------------+-----------+---------------------------------------------------------------------------------+
    | .sex           | dataset   | Gender of subject                                                               |
    |                |           |                                                                                 |
    |                |           | - **Quantity** 0 or 1                                                           |
    |                |           | - **Data Type:** text                                                           |
    |                |           |                                                                                 |
    +----------------+-----------+---------------------------------------------------------------------------------+


Groups: /general/specifications
"""""""""""""""""""""""""""""""

Group for storing format specification files.



- **Quantity** 0 or 1


.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. table:: Datasets, Links, and Attributes contained in ``/general/specifications``
    :class: longtable

    +------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------+
    | Id               | Type        | Description                                                                                                                          |
    +==================+=============+======================================================================================================================================+
    | specifications   | group       | Top level group for specifications                                                                                                   |
    +------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------+
    | .<SpecFile>      | dataset     | Dataset for storing contents of a specification file for either the core format or an extension.  Name should match name of file.`   |
    |                  |             |                                                                                                                                      |
    |                  |             | - **Quantity** 0 or more                                                                                                             |
    |                  |             | - **Data Type:** text                                                                                                                |
    |                  |             | - **Neurodata Type:** SpecFile                                                                                                       |
    |                  |             |                                                                                                                                      |
    +------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------+
    | ..help           | attribute   | Value is Contents of format specification file.                                                                                      |
    |                  |             |                                                                                                                                      |
    |                  |             | - **Data Type:** text                                                                                                                |
    |                  |             | - **Value:** Contents of format specification file.                                                                                  |
    |                  |             |                                                                                                                                      |
    +------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------+
    | ..namespaces     | attribute   | Namespaces defined in the file                                                                                                       |
    |                  |             |                                                                                                                                      |
    |                  |             | - **Data Type:** text                                                                                                                |
    |                  |             | - **Dimensions:** ['num_namespaces']                                                                                                 |
    |                  |             | - **Shape:** (None,)                                                                                                                 |
    |                  |             |                                                                                                                                      |
    +------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------+


Groups: /general/devices
""""""""""""""""""""""""

Description of hardware devices used during experiment. 

**Comment:**  Eg, monitors, ADC boards, microscopes, etc



- **Quantity** 0 or 1


.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. table:: Groups contained in <devices>
    :class: longtable

    +-------------+---------+---------------------------------------------------------------------------+
    | Id          | Type    | Description                                                               |
    +=============+=========+===========================================================================+
    | devices     | group   | Top level group for devices                                               |
    +-------------+---------+---------------------------------------------------------------------------+
    | .<Device>   | group   | One of possibly many. Information about device and device description.    |
    |             |         |                                                                           |
    |             |         | **Comment:**  Name should be informative. Contents can be from Methods.   |
    |             |         |                                                                           |
    |             |         | - **Quantity** 0 or more                                                  |
    |             |         | - **Neurodata Type:** :ref:`Device <sec-Device>`                          |
    |             |         |                                                                           |
    +-------------+---------+---------------------------------------------------------------------------+


Groups: /general/devices/<Device>
"""""""""""""""""""""""""""""""""

One of possibly many. Information about device and device description. 

**Comment:**  Name should be informative. Contents can be from Methods.



- **Quantity** 0 or more
- **Neurodata Type:** :ref:`Device <sec-Device>`

Groups: /general/extracellular_ephys
""""""""""""""""""""""""""""""""""""

Metadata related to extracellular electrophysiology.



- **Quantity** 0 or 1


.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. table:: Groups contained in <extracellular_ephys>
    :class: longtable

    +-------------------------------------------------+---------+--------------------------------------------------------------+
    | Id                                              | Type    | Description                                                  |
    +=================================================+=========+==============================================================+
    | extracellular_ephys                             | group   | Top level group for extracellular_ephys                      |
    +-------------------------------------------------+---------+--------------------------------------------------------------+
    | .<:ref:`ElectrodeGroup <sec-ElectrodeGroup>`>   | group   | One of possibly many groups, one for each electrode group.   |
    |                                                 |         |                                                              |
    |                                                 |         | - **Quantity** 0 or more                                     |
    |                                                 |         | - **Extends:** :ref:`ElectrodeGroup <sec-ElectrodeGroup>`    |
    |                                                 |         |                                                              |
    +-------------------------------------------------+---------+--------------------------------------------------------------+


Groups: /general/extracellular_ephys/<ElectrodeGroup>
"""""""""""""""""""""""""""""""""""""""""""""""""""""

One of possibly many groups, one for each electrode group.



- **Quantity** 0 or more
- **Extends:** :ref:`ElectrodeGroup <sec-ElectrodeGroup>`

Groups: /general/intracellular_ephys
""""""""""""""""""""""""""""""""""""

Metadata related to intracellular electrophysiology



- **Quantity** 0 or 1


.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. table:: Datasets, Links, and Attributes contained in ``/general/intracellular_ephys``
    :class: longtable

    +-----------------------+-----------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | Id                    | Type      | Description                                                                                                                                                                                        |
    +=======================+===========+====================================================================================================================================================================================================+
    | intracellular_ephys   | group     | Top level group for intracellular_ephys                                                                                                                                                            |
    +-----------------------+-----------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | .filtering            | dataset   | Description of filtering used.                                                                                                                                                                     |
    |                       |           |                                                                                                                                                                                                    |
    |                       |           | **Comment:**  Includes filtering type and parameters, frequency fall- off, etc. If this changes between TimeSeries, filter description should be stored as a text attribute for each TimeSeries.   |
    |                       |           |                                                                                                                                                                                                    |
    |                       |           | - **Quantity** 0 or 1                                                                                                                                                                              |
    |                       |           | - **Data Type:** text                                                                                                                                                                              |
    |                       |           |                                                                                                                                                                                                    |
    +-----------------------+-----------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+



.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. table:: Groups contained in <intracellular_ephys>
    :class: longtable

    +-----------------------------------------------------------------+---------+-----------------------------------------------------------------------------+
    | Id                                                              | Type    | Description                                                                 |
    +=================================================================+=========+=============================================================================+
    | intracellular_ephys                                             | group   | Top level group for intracellular_ephys                                     |
    +-----------------------------------------------------------------+---------+-----------------------------------------------------------------------------+
    | .<:ref:`IntracellularElectrode <sec-IntracellularElectrode>`>   | group   | One of possibly many.                                                       |
    |                                                                 |         |                                                                             |
    |                                                                 |         | **Comment:**  Name should be informative.                                   |
    |                                                                 |         |                                                                             |
    |                                                                 |         | - **Quantity** 0 or more                                                    |
    |                                                                 |         | - **Extends:** :ref:`IntracellularElectrode <sec-IntracellularElectrode>`   |
    |                                                                 |         |                                                                             |
    +-----------------------------------------------------------------+---------+-----------------------------------------------------------------------------+


Groups: /general/intracellular_ephys/<IntracellularElectrode>
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

One of possibly many. 

**Comment:**  Name should be informative.



- **Quantity** 0 or more
- **Extends:** :ref:`IntracellularElectrode <sec-IntracellularElectrode>`

Groups: /general/optogenetics
"""""""""""""""""""""""""""""

Metadata describing optogenetic stimuluation



- **Quantity** 0 or 1


.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. table:: Groups contained in <optogenetics>
    :class: longtable

    +-------------------------------------------------------------------+---------+-----------------------------------------------------------------------------------------------------+
    | Id                                                                | Type    | Description                                                                                         |
    +===================================================================+=========+=====================================================================================================+
    | optogenetics                                                      | group   | Top level group for optogenetics                                                                    |
    +-------------------------------------------------------------------+---------+-----------------------------------------------------------------------------------------------------+
    | .<:ref:`OptogeneticStimulusSite <sec-OptogeneticStimulusSite>`>   | group   | One of possibly many groups describing an optogenetic stimuluation site.                            |
    |                                                                   |         |                                                                                                     |
    |                                                                   |         | **Comment:**  Name is arbitrary but should be meaningful. Name is referenced by OptogeneticSeries   |
    |                                                                   |         |                                                                                                     |
    |                                                                   |         | - **Quantity** 0 or more                                                                            |
    |                                                                   |         | - **Extends:** :ref:`OptogeneticStimulusSite <sec-OptogeneticStimulusSite>`                         |
    |                                                                   |         |                                                                                                     |
    +-------------------------------------------------------------------+---------+-----------------------------------------------------------------------------------------------------+


Groups: /general/optogenetics/<OptogeneticStimulusSite>
"""""""""""""""""""""""""""""""""""""""""""""""""""""""

One of possibly many groups describing an optogenetic stimuluation site. 

**Comment:**  Name is arbitrary but should be meaningful. Name is referenced by OptogeneticSeries



- **Quantity** 0 or more
- **Extends:** :ref:`OptogeneticStimulusSite <sec-OptogeneticStimulusSite>`

Groups: /general/optophysiology
"""""""""""""""""""""""""""""""

Metadata related to optophysiology.



- **Quantity** 0 or 1


.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. table:: Groups contained in <optophysiology>
    :class: longtable

    +---------------------------------------------+---------+---------------------------------------------------------------------------------------------------------------------------------------------------+
    | Id                                          | Type    | Description                                                                                                                                       |
    +=============================================+=========+===================================================================================================================================================+
    | optophysiology                              | group   | Top level group for optophysiology                                                                                                                |
    +---------------------------------------------+---------+---------------------------------------------------------------------------------------------------------------------------------------------------+
    | .<:ref:`ImagingPlane <sec-ImagingPlane>`>   | group   | One of possibly many groups describing an imaging plane.                                                                                          |
    |                                             |         |                                                                                                                                                   |
    |                                             |         | **Comment:**  Name is arbitrary but should be meaningful. It is referenced by TwoPhotonSeries and also ImageSegmentation and DfOverF interfaces   |
    |                                             |         |                                                                                                                                                   |
    |                                             |         | - **Quantity** 0 or more                                                                                                                          |
    |                                             |         | - **Extends:** :ref:`ImagingPlane <sec-ImagingPlane>`                                                                                             |
    |                                             |         |                                                                                                                                                   |
    +---------------------------------------------+---------+---------------------------------------------------------------------------------------------------------------------------------------------------+


Groups: /general/optophysiology/<ImagingPlane>
""""""""""""""""""""""""""""""""""""""""""""""

One of possibly many groups describing an imaging plane. 

**Comment:**  Name is arbitrary but should be meaningful. It is referenced by TwoPhotonSeries and also ImageSegmentation and DfOverF interfaces



- **Quantity** 0 or more
- **Extends:** :ref:`ImagingPlane <sec-ImagingPlane>`

