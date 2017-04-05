Format Specification
====================

AbstractFeatureSeries
---------------------

.. code-block:: python

    {
        "attributes": [
            {
                "doc": "",
                "name": "help",
                "type": "text",
                "value": "Features of an applied stimulus. This is useful when storing the raw stimulus is impractical"
            }
        ],
        "datasets": [
            {
                "attributes": [
                    {
                        "doc": "",
                        "name": "unit",
                        "type": "None",
                        "value": "see 'feature_units'"
                    }
                ],
                "doc": "Values of each feature at each time.",
                "name": "data",
                "type": "float32"
            },
            {
                "doc": "Units of each feature.",
                "name": "feature_units",
                "type": "text"
            },
            {
                "doc": "Description of the features represented in TimeSeries::data.",
                "name": "features",
                "type": "text"
            }
        ],
        "doc": "Abstract features, such as quantitative descriptions of sensory stimuli. The TimeSeries::data field is a 2D array, storing those features (e.g., for visual grating stimulus this might be orientation, spatial frequency and contrast). Null stimuli (eg, uniform gray) can be marked as being an independent feature (eg, 1.0 for gray, 0.0 for actual stimulus) or by storing NaNs for feature values, or through use of the TimeSeries::control fields. A set of features is considered to persist until the next set of features is defined. The final set of features stored should be the null set.",
        "neurodata_type": "TimeSeries",
        "neurodata_type_def": "AbstractFeatureSeries"
    }

AnnotationSeries
----------------

.. code-block:: python

    {
        "attributes": [
            {
                "doc": "",
                "name": "help",
                "type": "text",
                "value": "Time-stamped annotations about an experiment"
            }
        ],
        "datasets": [
            {
                "attributes": [
                    {
                        "doc": "Value is \"n/a\" to indicate that this does not apply",
                        "name": "unit",
                        "type": "None",
                        "value": "n/a"
                    },
                    {
                        "doc": "Value is float('nan') (const) since this does not apply",
                        "name": "resolution",
                        "type": "None",
                        "value": "float('NaN')"
                    },
                    {
                        "doc": "Value is float('NaN') (const) since this does not apply.",
                        "name": "conversion",
                        "type": "None",
                        "value": "float('NaN')"
                    }
                ],
                "doc": "Annotations made during an experiment.",
                "name": "data",
                "type": "text"
            }
        ],
        "doc": "Stores, eg, user annotations made during an experiment. The TimeSeries::data[] field stores a text array, and timestamps are stored for each annotation (ie, interval=1). This is largely an alias to a standard TimeSeries storing a text array but that is identifiable as storing annotations in a machine-readable way.",
        "neurodata_type": "TimeSeries",
        "neurodata_type_def": "AnnotationSeries"
    }

BehavioralEpochs
----------------

.. code-block:: python

    {
        "attributes": [
            {
                "doc": "",
                "name": "help",
                "type": "text",
                "value": "General container for storing behavorial epochs"
            }
        ],
        "doc": "TimeSeries for storing behavoioral epochs.  The objective of this and the other two Behavioral interfaces (e.g. BehavioralEvents and BehavioralTimeSeries) is to provide generic hooks for software tools/scripts. This allows a tool/script to take the output one specific interface (e.g., UnitTimes) and plot that data relative to another data modality (e.g., behavioral events) without having to define all possible modalities in advance. Declaring one of these interfaces means that one or more TimeSeries of the specified type is published. These TimeSeries should reside in a group having the same name as the interface. For example, if a BehavioralTimeSeries interface is declared, the module will have one or more TimeSeries defined in the module sub-group \"BehavioralTimeSeries\". BehavioralEpochs should use IntervalSeries. BehavioralEvents is used for irregular events. BehavioralTimeSeries is for continuous data.",
        "groups": [
            {
                "doc": "",
                "neurodata_type": "IntervalSeries"
            }
        ],
        "name": "BehavioralEpochs",
        "neurodata_type": "Interface",
        "neurodata_type_def": "BehavioralEpochs"
    }

BehavioralEvents
----------------

.. code-block:: python

    {
        "attributes": [
            {
                "doc": "",
                "name": "help",
                "type": "text",
                "value": "Position data, whether along the x, xy or xyz axis"
            }
        ],
        "doc": "TimeSeries for storing behavioral events. See description of <a href=\"#BehavioralEpochs\">BehavioralEpochs</a> for more details.",
        "groups": [
            {
                "doc": "",
                "neurodata_type": "TimeSeries"
            }
        ],
        "name": "BehavioralEvents",
        "neurodata_type": "Interface",
        "neurodata_type_def": "BehavioralEvents"
    }

ClusterWaveforms
----------------

.. code-block:: python

    {
        "attributes": [
            {
                "doc": "",
                "name": "help",
                "type": "text",
                "value": "Mean waveform shape of clusters. Waveforms should be high-pass filtered (ie, not the same bandpass filter used waveform analysis and clustering)"
            }
        ],
        "datasets": [
            {
                "doc": "The mean waveform for each cluster, using the same indices for each wave as cluster numbers in the associated Clustering module (i.e, cluster 3 is in array slot [3]). Waveforms corresponding to gaps in cluster sequence should be empty (e.g., zero- filled)",
                "name": "waveform_mean",
                "type": "float32"
            },
            {
                "doc": "Stdev of waveforms for each cluster, using the same indices as in mean",
                "name": "waveform_sd",
                "type": "float32"
            },
            {
                "doc": "Path to linked clustering interface",
                "name": "clustering_interface_path",
                "type": "text"
            },
            {
                "doc": "Filtering applied to data before generating mean/sd",
                "name": "waveform_filtering",
                "type": "text"
            }
        ],
        "doc": "The mean waveform shape, including standard deviation, of the different clusters. Ideally, the waveform analysis should be performed on data that is only high-pass filtered. This is a separate module because it is expected to require updating. For example, IMEC probes may require different storage requirements to store/display mean waveforms, requiring a new interface or an extension of this one.",
        "links": [
            {
                "doc": "",
                "name": "clustering_interface",
                "target_type": "Clustering"
            }
        ],
        "name": "ClusterWaveforms",
        "neurodata_type": "Interface",
        "neurodata_type_def": "ClusterWaveforms"
    }

Clustering
----------

.. code-block:: python

    {
        "attributes": [
            {
                "doc": "",
                "name": "help",
                "type": "text",
                "value": "Clustered spike data, whether from automatic clustering tools (eg, klustakwik) or as a result of manual sorting"
            }
        ],
        "datasets": [
            {
                "doc": "Description of clusters or clustering, (e.g. cluster 0 is noise, clusters curated using Klusters, etc)",
                "name": "description",
                "type": "text"
            },
            {
                "doc": "Cluster number of each event",
                "name": "num",
                "type": "int32"
            },
            {
                "doc": "Maximum ratio of waveform peak to RMS on any channel in the cluster (provides a basic clustering metric).",
                "name": "peak_over_rms",
                "type": "float32"
            },
            {
                "doc": "Times of clustered events, in seconds. This may be a link to times field in associated FeatureExtraction module.",
                "name": "times",
                "type": "float64!"
            },
            {
                "doc": "List of cluster number that are a part of this set (cluster numbers can be non- continuous)",
                "name": "cluster_nums",
                "type": "int32"
            }
        ],
        "doc": "Clustered spike data, whether from automatic clustering tools (e.g., klustakwik) or as a result of manual sorting.",
        "name": "Clustering",
        "neurodata_type": "Interface",
        "neurodata_type_def": "Clustering"
    }

CompassDirection
----------------

.. code-block:: python

    {
        "attributes": [
            {
                "doc": "",
                "name": "help",
                "type": "text",
                "value": "Direction as measured radially. Spatial series reference frame should indicate which direction corresponds to zero and what is the direction of positive rotation"
            }
        ],
        "doc": "With a CompassDirection interface, a module publishes a SpatialSeries object representing a floating point value for theta. The SpatialSeries::reference_frame field should indicate what direction corresponds to 0 and which is the direction of rotation (this should be clockwise). The si_unit for the SpatialSeries should be radians or degrees.",
        "groups": [
            {
                "doc": "",
                "neurodata_type": "SpatialSeries"
            }
        ],
        "name": "CompassDirection",
        "neurodata_type": "Interface",
        "neurodata_type_def": "CompassDirection"
    }

CurrentClampSeries
------------------

.. code-block:: python

    {
        "attributes": [
            {
                "doc": "",
                "name": "help",
                "type": "text",
                "value": "Voltage recorded from cell during current-clamp recording"
            }
        ],
        "datasets": [
            {
                "doc": "Unit: Ohm",
                "name": "bridge_balance",
                "type": "float32"
            },
            {
                "doc": "Unit: Farad",
                "name": "capacitance_compensation",
                "type": "float32"
            },
            {
                "doc": "Unit: Amp",
                "name": "bias_current",
                "type": "float32"
            }
        ],
        "doc": "Stores voltage data recorded from intracellular current-clamp recordings. A corresponding CurrentClampStimulusSeries (stored separately as a stimulus) is used to store the current injected.",
        "neurodata_type": "PatchClampSeries",
        "neurodata_type_def": "CurrentClampSeries"
    }

CurrentClampStimulusSeries
--------------------------

.. code-block:: python

    {
        "attributes": [
            {
                "doc": "",
                "name": "help",
                "type": "text",
                "value": "Stimulus current applied during current clamp recording"
            }
        ],
        "doc": "Aliases to standard PatchClampSeries. Its functionality is to better tag PatchClampSeries for machine (and human) readability of the file.",
        "neurodata_type": "PatchClampSeries",
        "neurodata_type_def": "CurrentClampStimulusSeries"
    }

DfOverF
-------

.. code-block:: python

    {
        "attributes": [
            {
                "doc": "",
                "name": "help",
                "type": "text",
                "value": "Df/f over time of one or more ROIs. TimeSeries names should correspond to imaging plane names"
            }
        ],
        "doc": "dF/F information about a region of interest (ROI). Storage hierarchy of dF/F should be the same as for segmentation (ie, same names for ROIs and for image planes).",
        "groups": [
            {
                "doc": "",
                "neurodata_type": "RoiResponseSeries"
            }
        ],
        "name": "DfOverF",
        "neurodata_type": "Interface",
        "neurodata_type_def": "DfOverF"
    }

ElectricalSeries
----------------

.. code-block:: python

    {
        "attributes": [
            {
                "doc": "",
                "name": "help",
                "type": "text",
                "value": "Stores acquired voltage data from extracellular recordings"
            }
        ],
        "datasets": [
            {
                "attributes": [
                    {
                        "doc": "",
                        "name": "unit",
                        "type": "text",
                        "value": "volt"
                    }
                ],
                "doc": "Recorded voltage data.",
                "name": "data",
                "type": "number"
            }
        ],
        "doc": "Stores acquired voltage data from extracellular recordings. The data field of an ElectricalSeries is an int or float array storing data in Volts. TimeSeries::data array structure: :blue:`[num times] [num channels] (or [num_times] for single electrode).`",
        "links": [
            {
                "doc": "link to ElectrodeGroup group that generated this TimeSeries data",
                "name": "electrode_group",
                "target_type": "ElectrodeGroup"
            }
        ],
        "neurodata_type": "TimeSeries",
        "neurodata_type_def": "ElectricalSeries"
    }

ElectrodeGroup
--------------

.. code-block:: python

    {
        "datasets": [
            {
                "doc": "Description of probe or shank",
                "name": "description",
                "type": "text"
            },
            {
                "doc": "Description of probe locationCOMMENT: E.g., stereotaxic coordinates and other data, e.g., drive placement, angle and orientation and tetrode location in drive and tetrode depth",
                "name": "location",
                "type": "text"
            },
            {
                "doc": "Name of device(s) in /general/devices",
                "name": "device",
                "type": "text"
            }
        ],
        "doc": "One of possibly many groups, one for each electrode group. If the groups have a hierarchy, such as multiple probes each having multiple shanks, that hierarchy can be mirrored here, using groups for electrode_probe_X and subgroups for electrode_group_X.COMMENT: Name is arbitrary but should be meaningful.",
        "neurodata_type_def": "ElectrodeGroup"
    }

Epoch
-----

.. code-block:: python

    {
        "attributes": [
            {
                "doc": "A sorted list mapping TimeSeries entries in the epoch to the path of the TimeSeries within the file. Each entry in the list has the following format: \"'<i>&lt;TimeSeries_X&gt;</i>' <b>is</b> '<i>path_to_TimeSeries</i>'\", where <i>&lt;TimeSeries_X&gt;</i> is the name assigned to group  &lt;TimeSeries_X&gt; (below). Note that the name and path are both enclosed in single quotes and the word \"is\" (with a single space before and after) separate them. <b>Example list element:</b> \"'auditory_cue' is '/stimulus/presentation/auditory_cue'\".",
                "name": "links",
                "type": "text"
            }
        ],
        "datasets": [
            {
                "doc": "Start time of epoch, in seconds",
                "name": "start_time",
                "type": "float64!"
            },
            {
                "doc": "Stop time of epoch, in seconds",
                "name": "stop_time",
                "type": "float64!"
            },
            {
                "doc": "User-defined tags used throughout the epochs. Tags are to help identify or categorize epochs. COMMENT: E.g., can describe stimulus (if template) or behavioral characteristic (e.g., \"lick left\")",
                "name": "tags",
                "type": "text"
            },
            {
                "doc": "Description of this epoch (&lt;epoch_X&gt;).",
                "name": "description",
                "type": "text"
            }
        ],
        "doc": "",
        "groups": [
            {
                "datasets": [
                    {
                        "doc": "Number of data samples available in this time series, during this epoch.",
                        "name": "count",
                        "type": "int32"
                    },
                    {
                        "doc": "Epoch's start index in TimeSeries data[] field. COMMENT: This can be used to calculate location in TimeSeries timestamp[] field",
                        "name": "idx_start",
                        "type": "int32"
                    }
                ],
                "doc": "One of possibly many input or output streams recorded during epoch. COMMENT: Name is arbitrary and does not have to match the TimeSeries that it refers to.",
                "links": [
                    {
                        "doc": "",
                        "name": "timeseries",
                        "target_type": "TimeSeries"
                    }
                ],
                "neurodata_type_def": "EpochTimeSeries"
            }
        ],
        "neurodata_type_def": "Epoch"
    }

EpochTimeSeries
---------------

.. code-block:: python

    {
        "datasets": [
            {
                "doc": "Number of data samples available in this time series, during this epoch.",
                "name": "count",
                "type": "int32"
            },
            {
                "doc": "Epoch's start index in TimeSeries data[] field. COMMENT: This can be used to calculate location in TimeSeries timestamp[] field",
                "name": "idx_start",
                "type": "int32"
            }
        ],
        "doc": "One of possibly many input or output streams recorded during epoch. COMMENT: Name is arbitrary and does not have to match the TimeSeries that it refers to.",
        "links": [
            {
                "doc": "",
                "name": "timeseries",
                "target_type": "TimeSeries"
            }
        ],
        "neurodata_type_def": "EpochTimeSeries"
    }

EventWaveform
-------------

.. code-block:: python

    {
        "attributes": [
            {
                "doc": "",
                "name": "help",
                "type": "text",
                "value": "Waveform of detected extracellularly recorded spike events"
            }
        ],
        "doc": "Represents either the waveforms of detected events, as extracted from a raw data trace in /acquisition, or the event waveforms that were stored during experiment acquisition.",
        "groups": [
            {
                "doc": "",
                "neurodata_type": "SpikeEventSeries"
            }
        ],
        "name": "EventWaveform",
        "neurodata_type": "Interface",
        "neurodata_type_def": "EventWaveform"
    }

EyeTracking
-----------

.. code-block:: python

    {
        "attributes": [
            {
                "doc": "",
                "name": "help",
                "type": "text",
                "value": "Eye-tracking data, representing direction of gaze"
            }
        ],
        "doc": "Eye-tracking data, representing direction of gaze.",
        "groups": [
            {
                "doc": "",
                "neurodata_type": "SpatialSeries"
            }
        ],
        "name": "EyeTracking",
        "neurodata_type": "Interface",
        "neurodata_type_def": "EyeTracking"
    }

FeatureExtraction
-----------------

.. code-block:: python

    {
        "attributes": [
            {
                "doc": "",
                "name": "help",
                "type": "text",
                "value": "Container for salient features of detected events"
            }
        ],
        "datasets": [
            {
                "doc": "Description of features (eg, \"PC1\") for each of the extracted features.",
                "name": "description",
                "type": "text"
            },
            {
                "doc": "Times of events that features correspond to (can be a link).",
                "name": "times",
                "type": "float64!"
            },
            {
                "doc": "Multi-dimensional array of features extracted from each event.",
                "name": "features",
                "type": "float32"
            }
        ],
        "doc": "Features, such as PC1 and PC2, that are extracted from signals stored in a SpikeEvent TimeSeries or other source.",
        "links": [
            {
                "doc": "link to ElectrodeGroup group that generated this TimeSeries data",
                "name": "electrode_group",
                "target_type": "ElectrodeGroup"
            }
        ],
        "name": "FeatureExtraction",
        "neurodata_type": "Interface",
        "neurodata_type_def": "FeatureExtraction"
    }

FilteredEphys
-------------

.. code-block:: python

    {
        "attributes": [
            {
                "doc": "",
                "name": "help",
                "type": "text",
                "value": "Ephys data from one or more channels that is subjected to filtering, such as for gamma or theta oscillations (LFP has its own interface). Filter properties should be noted in the ElectricalSeries"
            }
        ],
        "doc": "Ephys data from one or more channels that has been subjected to filtering. Examples of filtered data include Theta and Gamma (LFP has its own interface). FilteredEphys modules publish an ElectricalSeries for each filtered channel or set of channels. The name of each ElectricalSeries is arbitrary but should be informative. The source of the filtered data, whether this is from analysis of another time series or as acquired by hardware, should be noted in each's TimeSeries::description field. There is no assumed 1::1 correspondence between filtered ephys signals and electrodes, as a single signal can apply to many nearby electrodes, and one electrode may have different filtered (e.g., theta and/or gamma) signals represented.",
        "groups": [
            {
                "doc": "",
                "neurodata_type": "ElectricalSeries"
            }
        ],
        "name": "FilteredEphys",
        "neurodata_type": "Interface",
        "neurodata_type_def": "FilteredEphys"
    }

Fluorescence
------------

.. code-block:: python

    {
        "attributes": [
            {
                "doc": "",
                "name": "help",
                "type": "text",
                "value": "Fluorescence over time of one or more ROIs. TimeSeries names should correspond to imaging plane names"
            }
        ],
        "doc": "Fluorescence information about a region of interest (ROI). Storage hierarchy of fluorescence should be the same as for segmentation (ie, same names for ROIs and for image planes).",
        "groups": [
            {
                "doc": "",
                "neurodata_type": "RoiResponseSeries"
            }
        ],
        "name": "Fluorescence",
        "neurodata_type": "Interface",
        "neurodata_type_def": "Fluorescence"
    }

IZeroClampSeries
----------------

.. code-block:: python

    {
        "attributes": [
            {
                "doc": "",
                "name": "help",
                "type": "text",
                "value": "Voltage from intracellular recordings when all current and amplifier settings are off"
            }
        ],
        "doc": "Stores recorded voltage data from intracellular recordings when all current and amplifier settings are off (i.e., CurrentClampSeries fields will be zero). There is no CurrentClampStimulusSeries associated with an IZero series because the amplifier is disconnected and no stimulus can reach the cell.",
        "neurodata_type": "CurrentClampSeries",
        "neurodata_type_def": "IZeroClampSeries"
    }

ImageMaskSeries
---------------

.. code-block:: python

    {
        "attributes": [
            {
                "doc": "",
                "name": "help",
                "type": "text",
                "value": "An alpha mask that is applied to a presented visual stimulus"
            }
        ],
        "datasets": [
            {
                "doc": "Path to linked ImageSeries",
                "name": "masked_imageseries_path",
                "type": "text"
            }
        ],
        "doc": "An alpha mask that is applied to a presented visual stimulus. The data[] array contains an array of mask values that are applied to the displayed image. Mask values are stored as RGBA. Mask can vary with time. The timestamps array indicates the starting time of a mask, and that mask pattern continues until it's explicitly changed.",
        "links": [
            {
                "doc": "",
                "name": "masked_imageseries",
                "target_type": "ImageSeries"
            }
        ],
        "neurodata_type": "ImageSeries",
        "neurodata_type_def": "ImageMaskSeries"
    }

ImageSegmentation
-----------------

.. code-block:: python

    {
        "attributes": [
            {
                "doc": "",
                "name": "help",
                "type": "text",
                "value": "Stores groups of pixels that define regions of interest from one or more imaging planes"
            }
        ],
        "doc": "Stores pixels in an image that represent different regions of interest (ROIs) or masks. All segmentation for a given imaging plane is stored together, with storage for multiple imaging planes (masks) supported. Each ROI is stored in its own subgroup, with the ROI group containing both a 2D mask and a list of pixels that make up this mask. Segments can also be used for masking neuropil. If segmentation is allowed to change with time, a new imaging plane (or module) is required and ROI names should remain consistent between them.",
        "groups": [
            {
                "datasets": [
                    {
                        "doc": "Name of imaging plane under general/optophysiology",
                        "name": "imaging_plane_name",
                        "type": "text"
                    },
                    {
                        "doc": "List of ROIs in this imaging plane",
                        "name": "roi_list",
                        "type": "text"
                    },
                    {
                        "doc": "Description of image plane, recording wavelength, depth, etc",
                        "name": "description",
                        "type": "text"
                    }
                ],
                "doc": "",
                "groups": [
                    {
                        "doc": "Stores image stacks segmentation mask apply to.",
                        "groups": [
                            {
                                "doc": "",
                                "neurodata_type": "ImageSeries"
                            }
                        ],
                        "name": "reference_images"
                    },
                    {
                        "datasets": [
                            {
                                "doc": "Weight of each pixel listed in pix_mask",
                                "name": "pix_mask_weight",
                                "type": "float32"
                            },
                            {
                                "doc": "Description of this ROI.",
                                "name": "roi_description",
                                "type": "text"
                            },
                            {
                                "doc": "List of pixels (x,y) that compose the mask",
                                "name": "pix_mask",
                                "type": "uint16"
                            },
                            {
                                "doc": "ROI mask, represented in 2D ([y][x]) intensity image",
                                "name": "img_mask",
                                "type": "float32"
                            }
                        ],
                        "doc": "Name of ROI",
                        "neurodata_type_def": "ROI"
                    }
                ],
                "neurodata_type_def": "PlaneSegmentation"
            }
        ],
        "name": "ImageSegmentation",
        "neurodata_type": "Interface",
        "neurodata_type_def": "ImageSegmentation"
    }

ImageSeries
-----------

.. code-block:: python

    {
        "attributes": [
            {
                "doc": "",
                "name": "help",
                "type": "text",
                "value": "Storage object for time-series 2-D image data"
            }
        ],
        "datasets": [
            {
                "doc": "Either binary data containing image or empty.",
                "name": "data",
                "type": "number"
            },
            {
                "doc": "Number of pixels on x, y, (and z) axes.",
                "name": "dimension",
                "type": "int32"
            },
            {
                "attributes": [
                    {
                        "doc": "Each entry is the frame number (within the full ImageSeries) of the first frame in the corresponding external_file entry. This serves as an index to what frames each file contains, allowing random access.Zero-based indexing is used.  (The first element will always be zero).",
                        "name": "starting_frame",
                        "type": "int"
                    }
                ],
                "doc": "Path or URL to one or more external file(s). Field only present if format=external. NOTE: this is only relevant if the image is stored in the file system as one or more image file(s). This field should NOT be used if the image is stored in another HDF5 file and that file is HDF5 linked to this file.",
                "name": "external_file",
                "type": "text"
            },
            {
                "doc": "Number of bit per image pixel.",
                "name": "bits_per_pixel",
                "type": "int32"
            },
            {
                "doc": "Format of image. If this is 'external' then the field external_file contains the path or URL information to that file. For tiff, png, jpg, etc, the binary representation of the image is stored in data. If the format is raw then the fields bit_per_pixel and dimension are used. For raw images, only a single channel is stored (eg, red).",
                "name": "format",
                "type": "text"
            }
        ],
        "doc": "General image data that is common between acquisition and stimulus time series. Sometimes the image data is stored in the HDF5 file in a raw format while other times it will be stored as an external image file in the host file system. The data field will either be binary data or empty. TimeSeries::data array structure: [frame] [y][x] or [frame][z][y][x].",
        "neurodata_type": "TimeSeries",
        "neurodata_type_def": "ImageSeries"
    }

ImagingPlane
------------

.. code-block:: python

    {
        "datasets": [
            {
                "attributes": [
                    {
                        "doc": "Base unit that coordinates are stored in (e.g., Meters)",
                        "name": "unit",
                        "type": "text",
                        "value": "Meter"
                    },
                    {
                        "doc": "Multiplier to get from stored values to specified unit (e.g., 1e-3 for millimeters)",
                        "name": "conversion",
                        "type": "float",
                        "value": 1.0
                    }
                ],
                "doc": "Physical position of each pixel. COMMENT: \"xyz\" represents the position of the pixel relative to the defined coordinate space",
                "name": "manifold",
                "type": "float32"
            },
            {
                "doc": "Rate images are acquired, in Hz.",
                "name": "imaging_rate",
                "type": "text"
            },
            {
                "doc": "Describes position and reference frame of manifold based on position of first element in manifold. For example, text description of anotomical location or vectors needed to rotate to common anotomical axis (eg, AP/DV/ML). COMMENT: This field is necessary to interpret manifold. If manifold is not present then this field is not required",
                "name": "reference_frame",
                "type": "text"
            },
            {
                "doc": "Location of image plane",
                "name": "location",
                "type": "text"
            },
            {
                "doc": "Excitation wavelength",
                "name": "excitation_lambda",
                "type": "text"
            },
            {
                "doc": "Name of device in /general/devices",
                "name": "device",
                "type": "text"
            },
            {
                "doc": "Description of &lt;image_plane_X&gt;",
                "name": "description",
                "type": "text"
            },
            {
                "doc": "Calcium indicator",
                "name": "indicator",
                "type": "text"
            }
        ],
        "doc": "",
        "groups": [
            {
                "datasets": [
                    {
                        "doc": "Any notes or comments about the channel",
                        "name": "description",
                        "type": "text"
                    },
                    {
                        "doc": "Emission lambda for channel",
                        "name": "emission_lambda",
                        "type": "text"
                    }
                ],
                "doc": "One of possibly many groups storing channel-specific data COMMENT: Name is arbitrary but should be meaningful",
                "neurodata_type_def": "OpticalChannel"
            }
        ],
        "neurodata_type_def": "ImagingPlane"
    }

ImagingRetinotopy
-----------------

.. code-block:: python

    {
        "attributes": [
            {
                "doc": "",
                "name": "help",
                "type": "text",
                "value": "Intrinsic signal optical imaging or Widefield imaging for measuring retinotopy"
            }
        ],
        "datasets": [
            {
                "attributes": [
                    {
                        "doc": "Number of rows and columns in the image. NOTE: row, column representation is equivalent to height,width.",
                        "name": "dimension",
                        "type": "int32"
                    },
                    {
                        "doc": "Size of viewing area, in meters.",
                        "name": "field_of_view",
                        "type": "float"
                    }
                ],
                "doc": "Sine of the angle between the direction of the gradient in axis_1 and axis_2",
                "name": "sign_map",
                "type": "float32"
            },
            {
                "attributes": [
                    {
                        "doc": "Number of rows and columns in the image. NOTE: row, column representation is equivalent to height,width.",
                        "name": "dimension",
                        "type": "int32"
                    },
                    {
                        "doc": "Number of bits used to represent each value. This is necessary to determine maximum (white) pixel value",
                        "name": "bits_per_pixel",
                        "type": "int32"
                    },
                    {
                        "doc": "Format of image. Right now only 'raw' supported",
                        "name": "format",
                        "type": "text"
                    },
                    {
                        "doc": "Size of viewing area, in meters",
                        "name": "field_of_view",
                        "type": "float"
                    }
                ],
                "doc": "Gray-scale anatomical image of cortical surface. Array structure: [rows][columns]",
                "name": "vasculature_image",
                "type": "uint16"
            },
            {
                "attributes": [
                    {
                        "doc": "Size of viewing area, in meters",
                        "name": "field_of_view",
                        "type": "float"
                    },
                    {
                        "doc": "Number of rows and columns in the image. NOTE: row, column representation is equivalent to height,width.",
                        "name": "dimension",
                        "type": "int32"
                    },
                    {
                        "doc": "Unit that axis data is stored in (e.g., degrees)",
                        "name": "unit",
                        "type": "text"
                    }
                ],
                "doc": "Phase response to stimulus on the first measured axis",
                "name": "axis_1_phase_map",
                "type": "float32"
            },
            {
                "attributes": [
                    {
                        "doc": "Size of viewing area, in meters",
                        "name": "field_of_view",
                        "type": "float"
                    },
                    {
                        "doc": "Number of rows and columns in the image. NOTE: row, column representation is equivalent to height,width.",
                        "name": "dimension",
                        "type": "int32"
                    },
                    {
                        "doc": "Unit that axis data is stored in (e.g., degrees)",
                        "name": "unit",
                        "type": "text"
                    }
                ],
                "doc": "Power response on the first measured axis. Response is scaled so 0.0 is no power in the response and 1.0 is maximum relative power.",
                "name": "axis_1_power_map",
                "type": "float32"
            },
            {
                "doc": "Two-element array describing the contents of the two response axis fields. Description should be something like ['altitude', 'azimuth'] or '['radius', 'theta']",
                "name": "axis_descriptions",
                "type": "text"
            },
            {
                "attributes": [
                    {
                        "doc": "Size of viewing area, in meters",
                        "name": "field_of_view",
                        "type": "float"
                    },
                    {
                        "doc": "Number of rows and columns in the image. NOTE: row, column representation is equivalent to height,width.",
                        "name": "dimension",
                        "type": "int32"
                    },
                    {
                        "doc": "Unit that axis data is stored in (e.g., degrees)",
                        "name": "unit",
                        "type": "text"
                    }
                ],
                "doc": "Phase response to stimulus on the second measured axis",
                "name": "axis_2_phase_map",
                "type": "float32"
            },
            {
                "attributes": [
                    {
                        "doc": "Number of rows and columns in the image. NOTE: row, column representation is equivalent to height,width.",
                        "name": "dimension",
                        "type": "int32"
                    },
                    {
                        "doc": "Focal depth offset, in meters",
                        "name": "focal_depth",
                        "type": "float"
                    },
                    {
                        "doc": "Number of bits used to represent each value. This is necessary to determine maximum (white) pixel value",
                        "name": "bits_per_pixel",
                        "type": "int32"
                    },
                    {
                        "doc": "Format of image. Right now only 'raw' supported",
                        "name": "format",
                        "type": "text"
                    },
                    {
                        "doc": "Size of viewing area, in meters",
                        "name": "field_of_view",
                        "type": "float"
                    }
                ],
                "doc": "Gray-scale image taken with same settings/parameters (e.g., focal depth, wavelength) as data collection. Array format: [rows][columns]",
                "name": "focal_depth_image",
                "type": "uint16"
            },
            {
                "attributes": [
                    {
                        "doc": "Size of viewing area, in meters",
                        "name": "field_of_view",
                        "type": "float"
                    },
                    {
                        "doc": "Number of rows and columns in the image. NOTE: row, column representation is equivalent to height,width.",
                        "name": "dimension",
                        "type": "int32"
                    },
                    {
                        "doc": "Unit that axis data is stored in (e.g., degrees)",
                        "name": "unit",
                        "type": "text"
                    }
                ],
                "doc": "Power response on the second measured axis. Response is scaled so 0.0 is no power in the response and 1.0 is maximum relative power.",
                "name": "axis_2_power_map",
                "type": "float32"
            }
        ],
        "doc": "Intrinsic signal optical imaging or widefield imaging for measuring retinotopy. Stores orthogonal maps (e.g., altitude/azimuth; radius/theta) of responses to specific stimuli and a combined polarity map from which to identify visual areas.<br />Note: for data consistency, all images and arrays are stored in the format [row][column] and [row, col], which equates to [y][x]. Field of view and dimension arrays may appear backward (i.e., y before x).",
        "name": "ImagingRetinotopy",
        "neurodata_type": "Interface",
        "neurodata_type_def": "ImagingRetinotopy"
    }

IndexSeries
-----------

.. code-block:: python

    {
        "attributes": [
            {
                "doc": "",
                "name": "help",
                "type": "text",
                "value": "A sequence that is generated from an existing image stack. Frames can be presented in an arbitrary order. The data[] field stores frame number in reference stack"
            }
        ],
        "datasets": [
            {
                "doc": "Index of the frame in the referenced ImageSeries.",
                "name": "data",
                "type": "int"
            },
            {
                "doc": "Path to linked TimeSeries",
                "name": "indexed_timeseries_path",
                "type": "text"
            }
        ],
        "doc": "Stores indices to image frames stored in an ImageSeries. The purpose of the ImageIndexSeries is to allow a static image stack to be stored somewhere, and the images in the stack to be referenced out-of-order. This can be for the display of individual images, or of movie segments (as a movie is simply a series of images). The data field stores the index of the frame in the referenced ImageSeries, and the timestamps array indicates when that image was displayed.",
        "links": [
            {
                "doc": "",
                "name": "indexed_timeseries",
                "target_type": "ImageSeries"
            }
        ],
        "neurodata_type": "TimeSeries",
        "neurodata_type_def": "IndexSeries"
    }

Interface
---------

.. code-block:: python

    {
        "attributes": [
            {
                "doc": "Short description of what this type of Interface contains.",
                "name": "help",
                "required": false,
                "type": "text"
            },
            {
                "doc": "Path to the origin of the data represented in this interface.",
                "name": "source",
                "type": "text"
            }
        ],
        "doc": "The attributes specified here are included in all interfaces.",
        "neurodata_type_def": "Interface"
    }

IntervalSeries
--------------

.. code-block:: python

    {
        "attributes": [
            {
                "doc": "",
                "name": "help",
                "type": "text",
                "value": "Stores the start and stop times for events"
            }
        ],
        "datasets": [
            {
                "attributes": [
                    {
                        "doc": "",
                        "name": "unit",
                        "type": "None",
                        "value": "n/a"
                    },
                    {
                        "doc": "",
                        "name": "resolution",
                        "type": "None",
                        "value": "float('NaN')"
                    },
                    {
                        "doc": "",
                        "name": "conversion",
                        "type": "None",
                        "value": "float('NaN')"
                    }
                ],
                "doc": ">0 if interval started, <0 if interval ended.",
                "name": "data",
                "type": "int8"
            }
        ],
        "doc": "Stores intervals of data. The timestamps field stores the beginning and end of intervals. The data field stores whether the interval just started (>0 value) or ended (<0 value). Different interval types can be represented in the same series by using multiple key values (eg, 1 for feature A, 2 for feature B, 3 for feature C, etc). The field data stores an 8-bit integer. This is largely an alias of a standard TimeSeries but that is identifiable as representing time intervals in a machine-readable way.",
        "neurodata_type": "TimeSeries",
        "neurodata_type_def": "IntervalSeries"
    }

IntracellularElectrode
----------------------

.. code-block:: python

    {
        "datasets": [
            {
                "doc": "Initial access resistance",
                "name": "initial_access_resistance",
                "type": "text"
            },
            {
                "doc": "Name(s) of devices in general/devices",
                "name": "device",
                "type": "text"
            },
            {
                "doc": "Information about seal used for recording",
                "name": "seal",
                "type": "text"
            },
            {
                "doc": "Recording description, description of electrode (e.g.,  whole-cell, sharp, etc)COMMENT: Free-form text (can be from Methods)",
                "name": "description",
                "type": "text"
            },
            {
                "doc": "Information about slice used for recording",
                "name": "slice",
                "type": "text"
            },
            {
                "doc": "Electrode resistance COMMENT: unit: Ohm",
                "name": "resistance",
                "type": "text"
            },
            {
                "doc": "Area, layer, comments on estimation, stereotaxis coordinates (if in vivo, etc)",
                "name": "location",
                "type": "text"
            },
            {
                "doc": "Electrode specific filtering.",
                "name": "filtering",
                "type": "text"
            }
        ],
        "doc": "One of possibly many. COMMENT: Name should be informative.",
        "neurodata_type_def": "IntracellularElectrode"
    }

LFP
---

.. code-block:: python

    {
        "attributes": [
            {
                "doc": "",
                "name": "help",
                "type": "text",
                "value": "LFP data from one or more channels. Filter properties should be noted in the ElectricalSeries"
            }
        ],
        "doc": "LFP data from one or more channels. The electrode map in each published ElectricalSeries will identify which channels are providing LFP data. Filter properties should be noted in the ElectricalSeries description or comments field.",
        "groups": [
            {
                "doc": "",
                "neurodata_type": "ElectricalSeries"
            }
        ],
        "name": "LFP",
        "neurodata_type": "Interface",
        "neurodata_type_def": "LFP"
    }

Module
------

.. code-block:: python

    {
        "attributes": [
            {
                "doc": "Description of Module",
                "name": "description",
                "required": false,
                "type": "text"
            },
            {
                "doc": "Names of the data interfaces offered by this module. COMMENT: E.g., [0]=\"EventDetection\", [1]=\"Clustering\", [2]=\"FeatureExtraction\"",
                "name": "interfaces",
                "type": "text"
            }
        ],
        "doc": "Module.  Name should be descriptive. Stores a collection of related data organized by contained interfaces.  Each interface is a contract specifying content related to a particular type of data.",
        "groups": [
            {
                "doc": "",
                "neurodata_type": "Interface"
            }
        ],
        "neurodata_type_def": "Module"
    }

MotionCorrection
----------------

.. code-block:: python

    {
        "attributes": [
            {
                "doc": "",
                "name": "help",
                "type": "text",
                "value": "Image stacks whose frames have been shifted (registered) to account for motion"
            }
        ],
        "doc": "An image stack where all frames are shifted (registered) to a common coordinate system, to account for movement and drift between frames. Note: each frame at each point in time is assumed to be 2-D (has only x & y dimensions).",
        "groups": [
            {
                "datasets": [
                    {
                        "doc": "Path to linked original timeseries",
                        "name": "original_path",
                        "type": "text"
                    }
                ],
                "doc": "One of possibly many.  Name should be informative.",
                "groups": [
                    {
                        "doc": "",
                        "name": "xy_translation",
                        "neurodata_type": "TimeSeries"
                    },
                    {
                        "doc": "",
                        "name": "corrected",
                        "neurodata_type": "ImageSeries"
                    }
                ],
                "links": [
                    {
                        "doc": "",
                        "name": "original",
                        "target_type": "ImageSeries"
                    }
                ],
                "name": "<image stack name>/+"
            }
        ],
        "name": "MotionCorrection",
        "neurodata_type": "Interface",
        "neurodata_type_def": "MotionCorrection"
    }

NWBFile
-------

.. code-block:: python

    {
        "datasets": [
            {
                "doc": "File version string. COMMENT: Eg, NWB-1.0.0. This will be the name of the format with trailing major, minor and patch numbers.",
                "name": "nwb_version",
                "type": "text"
            },
            {
                "doc": "Time file was created, UTC, and subsequent modifications to file. COMMENT: Date + time, Use ISO format (eg, ISO 8601) or a format that is easy to read and unambiguous. File can be created after the experiment was run, so this may differ from experiment start time. Each modifictation to file adds new entry to array. ",
                "name": "file_create_date",
                "type": "text"
            },
            {
                "doc": "Time of experiment/session start, UTC.  COMMENT: Date + time, Use ISO format (eg, ISO 8601) or an easy-to-read and unambiguous format. All times stored in the file use this time as reference (ie, time zero)",
                "name": "session_start_time",
                "type": "text"
            },
            {
                "doc": "A unique text identifier for the file. COMMENT: Eg, concatenated lab name, file creation date/time and experimentalist, or a hash of these and/or other values. The goal is that the string should be unique to all other files.",
                "name": "identifier",
                "type": "text"
            },
            {
                "doc": "One or two sentences describing the experiment and data in the file.",
                "name": "session_description",
                "type": "text"
            }
        ],
        "doc": "Top level of NWB file.",
        "groups": [
            {
                "doc": "Data streams recorded from the system, including ephys, ophys, tracking, etc. COMMENT: This group is read-only after the experiment is completed and timestamps are corrected to a common timebase. The data stored here may be links to raw data stored in external HDF5 files. This will allow keeping bulky raw data out of the file while preserving the option of keeping some/all in the file. MORE_INFO: Acquired data includes tracking and experimental data streams (ie, everything measured from the system).If bulky data is stored in the /acquisition group, the data can exist in a separate HDF5 file that is linked to by the file being used for processing and analysis.",
                "groups": [
                    {
                        "datasets": [
                            {
                                "attributes": [
                                    {
                                        "doc": "Format of the image.  COMMENT: eg, jpg, png, mpeg",
                                        "name": "format",
                                        "type": "text"
                                    },
                                    {
                                        "doc": "Human description of image. COMMENT: If image is of slice data, include slice thickness and orientation, and reference to appropriate entry in /general/slices",
                                        "name": "description",
                                        "type": "text"
                                    }
                                ],
                                "doc": "Photograph of experiment or experimental setup (video also OK). COMMENT: Name is arbitrary.  Data is stored as a single binary object (HDF5 opaque type).",
                                "name": "<image_X>*",
                                "type": "binary"
                            }
                        ],
                        "doc": "Acquired images",
                        "name": "images"
                    },
                    {
                        "doc": "Acquired TimeSeries.COMMENT: When importing acquisition data to an NWB file, all acquisition/tracking/stimulus data must already be aligned to a common time frame. It is assumed that this task has already been performed.",
                        "groups": [
                            {
                                "doc": "",
                                "neurodata_type": "TimeSeries"
                            }
                        ],
                        "name": "timeseries"
                    }
                ],
                "name": "acquisition"
            },
            {
                "doc": "Lab-specific and custom scientific analysis of data. There is no defined format for the content of this group - the format is up to the individual user/lab. COMMENT: To facilitate sharing analysis data between labs, the contents here should be stored in standard types (eg, INCF types) and appropriately documented. MORE_INFO: The file can store lab-specific and custom data analysis without restriction on its form or schema, reducing data formatting restrictions on end users. Such data should be placed in the analysis group. The analysis data should be documented so that it is sharable with other labs",
                "name": "analysis"
            },
            {
                "attributes": [
                    {
                        "doc": "A sorted list of the different tags used by epochs. COMMENT:This is a sorted list of all tags that are in any of the &lt;epoch_X&gt;/tags datasets`.",
                        "name": "tags",
                        "type": "text"
                    }
                ],
                "doc": "Experimental intervals, whether that be logically distinct sub-experiments having a particular scientific goal, trials during an experiment, or epochs deriving from analysis of data.  COMMENT: Epochs provide pointers to time series that are relevant to the epoch, and windows into the data in those time series (i.e., the start and end indices of TimeSeries::data[] that overlap with the epoch). This allows easy access to a range of data in specific experimental intervals. MORE_INFO: An experiment can be separated into one or many logical intervals, with the order and duration of these intervals often definable before the experiment starts. In this document, and in the context of NWB, these intervals are called 'epochs'. Epochs have acquisition and stimulus data associated with them, and different epochs can overlap. Examples of epochs are the time when a rat runs around an enclosure or maze as well as intervening sleep sessions; the presentation of a set of visual stimuli to a mouse running on a wheel; or the uninterrupted presentation of current to a patch-clamped cell. Epochs can be limited to the interval of a particular stimulus, or they can span multiple stimuli. Different windows into the same time series can be achieved by including multiple instances of that time series, each with different start/stop times.",
                "groups": [
                    {
                        "attributes": [
                            {
                                "doc": "A sorted list mapping TimeSeries entries in the epoch to the path of the TimeSeries within the file. Each entry in the list has the following format: \"'<i>&lt;TimeSeries_X&gt;</i>' <b>is</b> '<i>path_to_TimeSeries</i>'\", where <i>&lt;TimeSeries_X&gt;</i> is the name assigned to group  &lt;TimeSeries_X&gt; (below). Note that the name and path are both enclosed in single quotes and the word \"is\" (with a single space before and after) separate them. <b>Example list element:</b> \"'auditory_cue' is '/stimulus/presentation/auditory_cue'\".",
                                "name": "links",
                                "type": "text"
                            }
                        ],
                        "datasets": [
                            {
                                "doc": "Start time of epoch, in seconds",
                                "name": "start_time",
                                "type": "float64!"
                            },
                            {
                                "doc": "Stop time of epoch, in seconds",
                                "name": "stop_time",
                                "type": "float64!"
                            },
                            {
                                "doc": "User-defined tags used throughout the epochs. Tags are to help identify or categorize epochs. COMMENT: E.g., can describe stimulus (if template) or behavioral characteristic (e.g., \"lick left\")",
                                "name": "tags",
                                "type": "text"
                            },
                            {
                                "doc": "Description of this epoch (&lt;epoch_X&gt;).",
                                "name": "description",
                                "type": "text"
                            }
                        ],
                        "doc": "",
                        "groups": [
                            {
                                "datasets": [
                                    {
                                        "doc": "Number of data samples available in this time series, during this epoch.",
                                        "name": "count",
                                        "type": "int32"
                                    },
                                    {
                                        "doc": "Epoch's start index in TimeSeries data[] field. COMMENT: This can be used to calculate location in TimeSeries timestamp[] field",
                                        "name": "idx_start",
                                        "type": "int32"
                                    }
                                ],
                                "doc": "One of possibly many input or output streams recorded during epoch. COMMENT: Name is arbitrary and does not have to match the TimeSeries that it refers to.",
                                "links": [
                                    {
                                        "doc": "",
                                        "name": "timeseries",
                                        "target_type": "TimeSeries"
                                    }
                                ],
                                "neurodata_type_def": "EpochTimeSeries"
                            }
                        ],
                        "neurodata_type_def": "Epoch"
                    }
                ],
                "name": "epochs"
            },
            {
                "doc": "The home for processing Modules. These modules perform intermediate analysis of data that is necessary to perform before scientific analysis. Examples include spike clustering, extracting position from tracking data, stitching together image slices. COMMENT: Modules are defined below. They can be large and express many data sets from relatively complex analysis (e.g., spike detection and clustering) or small, representing extraction of position information from tracking video, or even binary lick/no-lick decisions. Common software tools (e.g., klustakwik, MClust) are expected to read/write data here. MORE_INFO: 'Processing' refers to intermediate analysis of the acquired data to make it more amenable to scientific analysis. These are performed using Modules, as defined above. All modules reside in the processing group.",
                "name": "processing"
            },
            {
                "doc": "Data pushed into the system (eg, video stimulus, sound, voltage, etc) and secondary representations of that data (eg, measurements of something used as a stimulus) COMMENT: This group is read-only after experiment complete and timestamps are corrected to common timebase. Stores both presented stimuli and stimulus templates, the latter in case the same stimulus is presented multiple times, or is pulled from an external stimulus library.MORE_INFO: Stimuli are here defined as any signal that is pushed into the system as part of the experiment (eg, sound, video, voltage, etc). Many different experiments can use the same stimuli, and stimuli can be re-used during an experiment. The stimulus group is organized so that one version of template stimuli can be stored and these be used multiple times. These templates can exist in the present file or can be HDF5-linked to a remote library file.",
                "groups": [
                    {
                        "doc": "Template stimuli. COMMENT: Time stamps in templates are based on stimulus design and are relative to the beginning of the stimulus. When templates are used, the stimulus instances must convert presentation times to the experiment's time reference frame.",
                        "groups": [
                            {
                                "doc": "",
                                "neurodata_type": "TimeSeries"
                            }
                        ],
                        "name": "templates"
                    },
                    {
                        "doc": "Stimuli presented during the experiment.",
                        "groups": [
                            {
                                "doc": "",
                                "neurodata_type": "TimeSeries"
                            }
                        ],
                        "name": "presentation"
                    }
                ],
                "name": "stimulus"
            },
            {
                "datasets": [
                    {
                        "doc": "Name of person who performed the experiment.COMMENT: More than one person OK. Can specify roles of different people involved.",
                        "name": "experimenter",
                        "type": "text"
                    },
                    {
                        "doc": "Information about virus(es) used in experiments, including virus ID, source, date made, injection location, volume, etc",
                        "name": "virus",
                        "type": "text"
                    },
                    {
                        "doc": "Institution(s) where experiment was performed",
                        "name": "institution",
                        "type": "text"
                    },
                    {
                        "doc": "Lab where experiment was performed",
                        "name": "lab",
                        "type": "text"
                    },
                    {
                        "doc": "Lab-specific ID for the session.COMMENT: Only 1 session_id per file, with all time aligned to experiment start time.",
                        "name": "session_id",
                        "type": "text"
                    },
                    {
                        "doc": "Notes about stimuli, such as how and where presented.COMMENT: Can be from Methods",
                        "name": "stimulus",
                        "type": "text"
                    },
                    {
                        "doc": "Notes about the experiment.  COMMENT: Things particular to this experiment",
                        "name": "notes",
                        "type": "text"
                    },
                    {
                        "doc": "Description of slices, including information about preparation thickness, orientation, temperature and bath solution",
                        "name": "slices",
                        "type": "text"
                    },
                    {
                        "doc": "Narrative description about surgery/surgeries, including date(s) and who performed surgery. COMMENT: Much can be copied from Methods",
                        "name": "surgery",
                        "type": "text"
                    },
                    {
                        "attributes": [
                            {
                                "doc": "Name of script file",
                                "name": "file_name",
                                "required": false,
                                "type": "text"
                            }
                        ],
                        "doc": "Script file used to create this NWB file.",
                        "name": "source_script",
                        "type": "text"
                    },
                    {
                        "doc": "Notes about data collection and analysis.COMMENT: Can be from Methods",
                        "name": "data_collection",
                        "type": "text"
                    },
                    {
                        "doc": "Description of drugs used, including how and when they were administered. COMMENT: Anesthesia(s), painkiller(s), etc., plus dosage, concentration, etc.",
                        "name": "pharmacology",
                        "type": "text"
                    },
                    {
                        "doc": "Experimetnal protocol, if applicable.COMMENT: E.g., include IACUC protocol",
                        "name": "protocol",
                        "type": "text"
                    },
                    {
                        "doc": "Publication information.COMMENT: PMID, DOI, URL, etc. If multiple, concatenate together and describe which is which. such as PMID, DOI, URL, etc",
                        "name": "related_publications",
                        "type": "text"
                    },
                    {
                        "doc": "General description of the experiment.COMMENT: Can be from Methods",
                        "name": "experiment_description",
                        "type": "text"
                    }
                ],
                "doc": "Experimental metadata, including protocol, notes and description of hardware device(s).  COMMENT: The metadata stored in this section should be used to describe the experiment. Metadata necessary for interpreting the data is stored with the data. MORE_INFO: General experimental metadata, including animal strain, experimental protocols, experimenter, devices, etc, are stored under 'general'. Core metadata (e.g., that required to interpret data fields) is stored with the data itself, and implicitly defined by the file specification (eg, time is in seconds). The strategy used here for storing non-core metadata is to use free-form text fields, such as would appear in sentences or paragraphs from a Methods section. Metadata fields are text to enable them to be more general, for example to represent ranges instead of numerical values. Machine-readable metadata is stored as attributes to these free-form datasets. <br /><br />All entries in the below table are to be included when data is present. Unused groups (e.g., intracellular_ephys in an optophysiology experiment) should not be created unless there is data to store within them.",
                "groups": [
                    {
                        "datasets": [
                            {
                                "doc": "One of possibly many. Information about device and device description. COMMENT: Name should be informative. Contents can be from Methods.",
                                "name": "<device_X>*",
                                "type": "text"
                            }
                        ],
                        "doc": "Description of hardware devices used during experiment. COMMENT: Eg, monitors, ADC boards, microscopes, etc",
                        "name": "devices"
                    },
                    {
                        "datasets": [
                            {
                                "attributes": [
                                    {
                                        "doc": "",
                                        "name": "help",
                                        "type": "text",
                                        "value": "Contents of format specification file."
                                    },
                                    {
                                        "doc": "Namespaces defined in the file",
                                        "name": "namespaces",
                                        "type": "text"
                                    }
                                ],
                                "doc": "Dataset for storing contents of a specification file for either the core format or an extension.  Name should match name of file.`",
                                "name": "<specification_file>*",
                                "type": "text"
                            }
                        ],
                        "doc": "Group for storing format specification files.",
                        "name": "specifications"
                    },
                    {
                        "datasets": [
                            {
                                "doc": "Genetic strain COMMENT: If absent, assume Wild Type (WT)",
                                "name": "genotype",
                                "type": "text"
                            },
                            {
                                "doc": "Description of subject and where subject came from (e.g., breeder, if animal)",
                                "name": "description",
                                "type": "text"
                            },
                            {
                                "doc": "Age of subject",
                                "name": "age",
                                "type": "text"
                            },
                            {
                                "doc": "Weight at time of experiment, at time of surgery and at other important times",
                                "name": "weight",
                                "type": "text"
                            },
                            {
                                "doc": "ID of animal/person used/participating in experiment (lab convention)",
                                "name": "subject_id",
                                "type": "text"
                            },
                            {
                                "doc": "Species of subject",
                                "name": "species",
                                "type": "text"
                            },
                            {
                                "doc": "Gender of subject",
                                "name": "sex",
                                "type": "text"
                            }
                        ],
                        "doc": "",
                        "name": "subject"
                    },
                    {
                        "datasets": [
                            {
                                "doc": "Physical location of electrode, (x,y,z in meters) COMMENT: Location of electrodes relative to one another. This records the points in space. If an electrode is moved, it needs a new entry in the electrode map for its new location. Otherwise format doesn't support using the same electrode in a new location, or processing spikes pre/post drift.",
                                "name": "electrode_map",
                                "type": "number"
                            },
                            {
                                "doc": "Impedence of electrodes listed in electrode_map. COMMENT: Text, in the event that impedance is stored as range and not a fixed value",
                                "name": "impedance",
                                "type": "text"
                            },
                            {
                                "doc": "Identification string for probe, shank or tetrode each electrode resides on. Name should correspond to one of electrode_group_X groups below. COMMENT: There's one entry here for each element in electrode_map. All elements in an electrode group should have a functional association, for example all being on the same planar electrode array, or on the same shank.",
                                "name": "electrode_group",
                                "type": "text"
                            },
                            {
                                "doc": "Description of filtering used. COMMENT: Includes filtering type and parameters, frequency fall- off, etc. If this changes between TimeSeries, filter description should be stored as a text attribute for each TimeSeries.  If this changes between TimeSeries, filter description should be stored as a text attribute for each TimeSeries.",
                                "name": "filtering",
                                "type": "text"
                            }
                        ],
                        "doc": "Metadata related to extracellular electrophysiology.",
                        "groups": [
                            {
                                "datasets": [
                                    {
                                        "doc": "Description of probe or shank",
                                        "name": "description",
                                        "type": "text"
                                    },
                                    {
                                        "doc": "Description of probe locationCOMMENT: E.g., stereotaxic coordinates and other data, e.g., drive placement, angle and orientation and tetrode location in drive and tetrode depth",
                                        "name": "location",
                                        "type": "text"
                                    },
                                    {
                                        "doc": "Name of device(s) in /general/devices",
                                        "name": "device",
                                        "type": "text"
                                    }
                                ],
                                "doc": "One of possibly many groups, one for each electrode group. If the groups have a hierarchy, such as multiple probes each having multiple shanks, that hierarchy can be mirrored here, using groups for electrode_probe_X and subgroups for electrode_group_X.COMMENT: Name is arbitrary but should be meaningful.",
                                "neurodata_type_def": "ElectrodeGroup"
                            }
                        ],
                        "name": "extracellular_ephys"
                    },
                    {
                        "datasets": [
                            {
                                "doc": "Description of filtering used. COMMENT: Includes filtering type and parameters, frequency fall- off, etc. If this changes between TimeSeries, filter description should be stored as a text attribute for each TimeSeries.",
                                "name": "filtering",
                                "type": "text"
                            }
                        ],
                        "doc": "Metadata related to intracellular electrophysiology",
                        "groups": [
                            {
                                "datasets": [
                                    {
                                        "doc": "Initial access resistance",
                                        "name": "initial_access_resistance",
                                        "type": "text"
                                    },
                                    {
                                        "doc": "Name(s) of devices in general/devices",
                                        "name": "device",
                                        "type": "text"
                                    },
                                    {
                                        "doc": "Information about seal used for recording",
                                        "name": "seal",
                                        "type": "text"
                                    },
                                    {
                                        "doc": "Recording description, description of electrode (e.g.,  whole-cell, sharp, etc)COMMENT: Free-form text (can be from Methods)",
                                        "name": "description",
                                        "type": "text"
                                    },
                                    {
                                        "doc": "Information about slice used for recording",
                                        "name": "slice",
                                        "type": "text"
                                    },
                                    {
                                        "doc": "Electrode resistance COMMENT: unit: Ohm",
                                        "name": "resistance",
                                        "type": "text"
                                    },
                                    {
                                        "doc": "Area, layer, comments on estimation, stereotaxis coordinates (if in vivo, etc)",
                                        "name": "location",
                                        "type": "text"
                                    },
                                    {
                                        "doc": "Electrode specific filtering.",
                                        "name": "filtering",
                                        "type": "text"
                                    }
                                ],
                                "doc": "One of possibly many. COMMENT: Name should be informative.",
                                "neurodata_type_def": "IntracellularElectrode"
                            }
                        ],
                        "name": "intracellular_ephys"
                    },
                    {
                        "doc": "Metadata describing optogenetic stimuluation",
                        "groups": [
                            {
                                "datasets": [
                                    {
                                        "doc": "Description of site",
                                        "name": "description",
                                        "type": "text"
                                    },
                                    {
                                        "doc": "Location of stimulation site",
                                        "name": "location",
                                        "type": "text"
                                    },
                                    {
                                        "doc": "Excitation wavelength",
                                        "name": "excitation_lambda",
                                        "type": "text"
                                    },
                                    {
                                        "doc": "Name of device in /general/devices",
                                        "name": "device",
                                        "type": "text"
                                    }
                                ],
                                "doc": "One of possibly many groups describing an optogenetic stimuluation site. COMMENT: Name is arbitrary but should be meaningful. Name is referenced by OptogeneticSeries",
                                "neurodata_type_def": "OptogeneticStimulusSite"
                            }
                        ],
                        "name": "optogenetics"
                    },
                    {
                        "doc": "Metadata related to optophysiology.",
                        "groups": [
                            {
                                "datasets": [
                                    {
                                        "attributes": [
                                            {
                                                "doc": "Base unit that coordinates are stored in (e.g., Meters)",
                                                "name": "unit",
                                                "type": "text",
                                                "value": "Meter"
                                            },
                                            {
                                                "doc": "Multiplier to get from stored values to specified unit (e.g., 1e-3 for millimeters)",
                                                "name": "conversion",
                                                "type": "float",
                                                "value": 1.0
                                            }
                                        ],
                                        "doc": "Physical position of each pixel. COMMENT: \"xyz\" represents the position of the pixel relative to the defined coordinate space",
                                        "name": "manifold",
                                        "type": "float32"
                                    },
                                    {
                                        "doc": "Rate images are acquired, in Hz.",
                                        "name": "imaging_rate",
                                        "type": "text"
                                    },
                                    {
                                        "doc": "Describes position and reference frame of manifold based on position of first element in manifold. For example, text description of anotomical location or vectors needed to rotate to common anotomical axis (eg, AP/DV/ML). COMMENT: This field is necessary to interpret manifold. If manifold is not present then this field is not required",
                                        "name": "reference_frame",
                                        "type": "text"
                                    },
                                    {
                                        "doc": "Location of image plane",
                                        "name": "location",
                                        "type": "text"
                                    },
                                    {
                                        "doc": "Excitation wavelength",
                                        "name": "excitation_lambda",
                                        "type": "text"
                                    },
                                    {
                                        "doc": "Name of device in /general/devices",
                                        "name": "device",
                                        "type": "text"
                                    },
                                    {
                                        "doc": "Description of &lt;image_plane_X&gt;",
                                        "name": "description",
                                        "type": "text"
                                    },
                                    {
                                        "doc": "Calcium indicator",
                                        "name": "indicator",
                                        "type": "text"
                                    }
                                ],
                                "doc": "",
                                "groups": [
                                    {
                                        "datasets": [
                                            {
                                                "doc": "Any notes or comments about the channel",
                                                "name": "description",
                                                "type": "text"
                                            },
                                            {
                                                "doc": "Emission lambda for channel",
                                                "name": "emission_lambda",
                                                "type": "text"
                                            }
                                        ],
                                        "doc": "One of possibly many groups storing channel-specific data COMMENT: Name is arbitrary but should be meaningful",
                                        "neurodata_type_def": "OpticalChannel"
                                    }
                                ],
                                "neurodata_type_def": "ImagingPlane"
                            }
                        ],
                        "name": "optophysiology"
                    }
                ],
                "name": "general"
            }
        ],
        "name": "root",
        "neurodata_type_def": "NWBFile"
    }

OpticalChannel
--------------

.. code-block:: python

    {
        "datasets": [
            {
                "doc": "Any notes or comments about the channel",
                "name": "description",
                "type": "text"
            },
            {
                "doc": "Emission lambda for channel",
                "name": "emission_lambda",
                "type": "text"
            }
        ],
        "doc": "One of possibly many groups storing channel-specific data COMMENT: Name is arbitrary but should be meaningful",
        "neurodata_type_def": "OpticalChannel"
    }

OpticalSeries
-------------

.. code-block:: python

    {
        "attributes": [
            {
                "doc": "",
                "name": "help",
                "type": "text",
                "value": "Time-series image stack for optical recording or stimulus"
            }
        ],
        "datasets": [
            {
                "doc": "Width, height and depto of image, or imaged area (meters).",
                "name": "field_of_view",
                "type": "float32"
            },
            {
                "doc": "Description of image relative to some reference frame (e.g., which way is up). Must also specify frame of reference.",
                "name": "orientation",
                "type": "text"
            },
            {
                "doc": "Distance from camera/monitor to target/eye.",
                "name": "distance",
                "type": "float32"
            }
        ],
        "doc": "Image data that is presented or recorded. A stimulus template movie will be stored only as an image. When the image is presented as stimulus, additional data is required, such as field of view (eg, how much of the visual field the image covers, or how what is the area of the target being imaged). If the OpticalSeries represents acquired imaging data, orientation is also important.",
        "neurodata_type": "ImageSeries",
        "neurodata_type_def": "OpticalSeries"
    }

OptogeneticSeries
-----------------

.. code-block:: python

    {
        "attributes": [
            {
                "doc": "",
                "name": "help",
                "type": "text",
                "value": "Optogenetic stimulus"
            }
        ],
        "datasets": [
            {
                "attributes": [
                    {
                        "doc": "",
                        "name": "unit",
                        "type": "text",
                        "value": "watt"
                    }
                ],
                "doc": "Applied power for optogenetic stimulus.",
                "name": "data",
                "type": "float32"
            }
        ],
        "doc": "Optogenetic stimulus.  The data[] field is in unit of watts.",
        "links": [
            {
                "doc": "link to OptogeneticStimulusSite group that describes the site to which this stimulus was applied",
                "name": "site",
                "target_type": "OptogeneticStimulusSite"
            }
        ],
        "neurodata_type": "TimeSeries",
        "neurodata_type_def": "OptogeneticSeries"
    }

OptogeneticStimulusSite
-----------------------

.. code-block:: python

    {
        "datasets": [
            {
                "doc": "Description of site",
                "name": "description",
                "type": "text"
            },
            {
                "doc": "Location of stimulation site",
                "name": "location",
                "type": "text"
            },
            {
                "doc": "Excitation wavelength",
                "name": "excitation_lambda",
                "type": "text"
            },
            {
                "doc": "Name of device in /general/devices",
                "name": "device",
                "type": "text"
            }
        ],
        "doc": "One of possibly many groups describing an optogenetic stimuluation site. COMMENT: Name is arbitrary but should be meaningful. Name is referenced by OptogeneticSeries",
        "neurodata_type_def": "OptogeneticStimulusSite"
    }

PatchClampSeries
----------------

.. code-block:: python

    {
        "attributes": [
            {
                "doc": "",
                "name": "help",
                "type": "text",
                "value": "Superclass definition for patch-clamp data"
            }
        ],
        "datasets": [
            {
                "doc": "Recorded voltage or current.",
                "name": "data",
                "type": "number"
            },
            {
                "doc": "Units: Volt/Amp (v-clamp) or Volt/Volt (c-clamp)",
                "name": "gain",
                "type": "float"
            }
        ],
        "doc": "Stores stimulus or response current or voltage. Superclass definition for patch-clamp data (this class should not be instantiated directly).",
        "links": [
            {
                "doc": "link to IntracellularElectrode group that describes th electrode that was used to apply or record this data",
                "name": "electrode",
                "target_type": "IntracellularElectrode"
            }
        ],
        "neurodata_type": "TimeSeries",
        "neurodata_type_def": "PatchClampSeries"
    }

PlaneSegmentation
-----------------

.. code-block:: python

    {
        "datasets": [
            {
                "doc": "Name of imaging plane under general/optophysiology",
                "name": "imaging_plane_name",
                "type": "text"
            },
            {
                "doc": "List of ROIs in this imaging plane",
                "name": "roi_list",
                "type": "text"
            },
            {
                "doc": "Description of image plane, recording wavelength, depth, etc",
                "name": "description",
                "type": "text"
            }
        ],
        "doc": "",
        "groups": [
            {
                "doc": "Stores image stacks segmentation mask apply to.",
                "groups": [
                    {
                        "doc": "",
                        "neurodata_type": "ImageSeries"
                    }
                ],
                "name": "reference_images"
            },
            {
                "datasets": [
                    {
                        "doc": "Weight of each pixel listed in pix_mask",
                        "name": "pix_mask_weight",
                        "type": "float32"
                    },
                    {
                        "doc": "Description of this ROI.",
                        "name": "roi_description",
                        "type": "text"
                    },
                    {
                        "doc": "List of pixels (x,y) that compose the mask",
                        "name": "pix_mask",
                        "type": "uint16"
                    },
                    {
                        "doc": "ROI mask, represented in 2D ([y][x]) intensity image",
                        "name": "img_mask",
                        "type": "float32"
                    }
                ],
                "doc": "Name of ROI",
                "neurodata_type_def": "ROI"
            }
        ],
        "neurodata_type_def": "PlaneSegmentation"
    }

Position
--------

.. code-block:: python

    {
        "attributes": [
            {
                "doc": "",
                "name": "help",
                "type": "text",
                "value": "Position data, whether along the x, xy or xyz axis"
            }
        ],
        "doc": "Position data, whether along the x, x/y or x/y/z axis.",
        "groups": [
            {
                "doc": "",
                "neurodata_type": "SpatialSeries"
            }
        ],
        "name": "Position",
        "neurodata_type": "Interface",
        "neurodata_type_def": "Position"
    }

PupilTracking
-------------

.. code-block:: python

    {
        "attributes": [
            {
                "doc": "",
                "name": "help",
                "type": "text",
                "value": "Eye-tracking data, representing pupil size"
            }
        ],
        "doc": "Eye-tracking data, representing pupil size.",
        "groups": [
            {
                "doc": "",
                "neurodata_type": "TimeSeries"
            }
        ],
        "name": "PupilTracking",
        "neurodata_type": "Interface",
        "neurodata_type_def": "PupilTracking"
    }

ROI
---

.. code-block:: python

    {
        "datasets": [
            {
                "doc": "Weight of each pixel listed in pix_mask",
                "name": "pix_mask_weight",
                "type": "float32"
            },
            {
                "doc": "Description of this ROI.",
                "name": "roi_description",
                "type": "text"
            },
            {
                "doc": "List of pixels (x,y) that compose the mask",
                "name": "pix_mask",
                "type": "uint16"
            },
            {
                "doc": "ROI mask, represented in 2D ([y][x]) intensity image",
                "name": "img_mask",
                "type": "float32"
            }
        ],
        "doc": "Name of ROI",
        "neurodata_type_def": "ROI"
    }

RoiResponseSeries
-----------------

.. code-block:: python

    {
        "attributes": [
            {
                "doc": "",
                "name": "help",
                "type": "text",
                "value": "ROI responses over an imaging plane. Each row in data[] should correspond to the signal from one ROI"
            }
        ],
        "datasets": [
            {
                "doc": "Signals from ROIs",
                "name": "data",
                "type": "float32"
            },
            {
                "doc": "List of ROIs represented, one name for each row of data[].",
                "name": "roi_names",
                "type": "text"
            },
            {
                "doc": "Path to segmentation module.",
                "name": "segmentation_interface_path",
                "type": "text"
            }
        ],
        "doc": "ROI responses over an imaging plane. Each row in data[] should correspond to the signal from one ROI.",
        "links": [
            {
                "doc": "",
                "name": "segmentation_interface",
                "target_type": "ImageSegmentation"
            }
        ],
        "neurodata_type": "TimeSeries",
        "neurodata_type_def": "RoiResponseSeries"
    }

SpatialSeries
-------------

.. code-block:: python

    {
        "attributes": [
            {
                "doc": "",
                "name": "help",
                "type": "text",
                "value": "Stores points in space over time. The data[] array structure is [num samples][num spatial dimensions]"
            }
        ],
        "datasets": [
            {
                "attributes": [
                    {
                        "doc": "",
                        "name": "unit",
                        "type": "text",
                        "value": "meter"
                    }
                ],
                "doc": "2-D array storing position or direction relative to some reference frame.",
                "name": "data",
                "type": "number"
            },
            {
                "doc": "Description defining what exactly 'straight-ahead' means.",
                "name": "reference_frame",
                "type": "text"
            }
        ],
        "doc": "Direction, e.g., of gaze or travel, or position. The TimeSeries::data field is a 2D array storing position or direction relative to some reference frame. Array structure: [num measurements] [num dimensions]. Each SpatialSeries has a text dataset reference_frame that indicates the zero-position, or the zero-axes for direction. For example, if representing gaze direction, \"straight-ahead\" might be a specific pixel on the monitor, or some other point in space. For position data, the 0,0 point might be the top-left corner of an enclosure, as viewed from the tracking camera. The unit of data will indicate how to interpret SpatialSeries values.",
        "neurodata_type": "TimeSeries",
        "neurodata_type_def": "SpatialSeries"
    }

SpikeEventSeries
----------------

.. code-block:: python

    {
        "attributes": [
            {
                "doc": "",
                "name": "help",
                "type": "text",
                "value": "Snapshots of spike events from data."
            }
        ],
        "datasets": [
            {
                "attributes": [
                    {
                        "doc": "",
                        "name": "unit",
                        "type": "text",
                        "value": "volt"
                    }
                ],
                "doc": "Spike waveforms.",
                "name": "data",
                "type": "float32"
            }
        ],
        "doc": "Stores \"snapshots\" of spike events (i.e., threshold crossings) in data. This may also be raw data, as reported by ephys hardware. If so, the TimeSeries::description field should describing how events were detected. All SpikeEventSeries should reside in a module (under EventWaveform interface) even if the spikes were reported and stored by hardware. All events span the same recording channels and store snapshots of equal duration. TimeSeries::data array structure: :blue:`[num events] [num channels] [num samples] (or [num events] [num samples] for single electrode)`.",
        "neurodata_type": "ElectricalSeries",
        "neurodata_type_def": "SpikeEventSeries"
    }

SpikeUnit
---------

.. code-block:: python

    {
        "datasets": [
            {
                "doc": "Description of the unit (eg, cell type).",
                "name": "unit_description",
                "type": "text"
            },
            {
                "doc": "Spike time for the units (exact or estimated)",
                "name": "times",
                "type": "float64!"
            },
            {
                "doc": "Name, path or description of where unit times originated. This is necessary only if the info here differs from or is more fine-grained than the interface's source field",
                "name": "source",
                "type": "text"
            }
        ],
        "doc": "Group storing times for &lt;unit_N&gt;.",
        "neurodata_type_def": "SpikeUnit"
    }

TimeSeries
----------

.. code-block:: python

    {
        "attributes": [
            {
                "doc": "List of fields that are HDF5 external links.COMMENT: Only present if one or more datasets is set to an HDF5 external link.",
                "name": "extern_fields",
                "type": "text"
            },
            {
                "doc": "A sorted list of the paths of all TimeSeries that share a link to the same timestamps field.  Example element of list: \"/acquisition/timeseries/lick_trace\" COMMENT: Attribute is only present if links are present. List should include the path to this TimeSeries also.",
                "name": "timestamp_link",
                "type": "text"
            },
            {
                "doc": "The class-hierarchy of this TimeSeries, with one entry in the array for each ancestor. An alternative and equivalent description is that this TimeSeries object contains the datasets defined for all of the TimeSeries classes listed. The class hierarchy is described more fully below. COMMENT: For example: [0]=TimeSeries, [1]=ElectricalSeries [2]=PatchClampSeries. The hierarchical order should be preserved in the array -- i.e., the parent object of subclassed element N in the array should be element N-1",
                "name": "ancestry",
                "type": "text",
                "value": "TimeSeries"
            },
            {
                "doc": "A sorted list of the paths of all TimeSeries that share a link to the same data field. Example element of list: \"/stimulus/presentation/Sweep_0\"` COMMENT: Attribute is only present if links are present. List should include the path to this TimeSeries also.",
                "name": "data_link",
                "type": "text"
            },
            {
                "doc": "List of fields that are not optional (i.e. either required or recommended parts of the TimeSeries) that are missing. COMMENT: Only present if one or more required or recommended fields are missing. Note that a missing required field (such as data or timestamps) should generate an error by the API",
                "name": "missing_fields",
                "type": "text"
            },
            {
                "doc": "Name of TimeSeries or Modules that serve as the source for the data contained here. It can also be the name of a device, for stimulus or acquisition data",
                "name": "source",
                "type": "text"
            },
            {
                "doc": "Human-readable comments about the TimeSeries. This second descriptive field can be used to store additional information, or descriptive information if the primary description field is populated with a computer-readable string.",
                "name": "comments",
                "type": "text"
            },
            {
                "doc": "Short description indicating what this type of TimeSeries stores.",
                "name": "help",
                "type": "text",
                "value": "General time series object"
            },
            {
                "doc": "Description of TimeSeries",
                "name": "description",
                "type": "text"
            }
        ],
        "datasets": [
            {
                "doc": "Description of each control value. COMMENT: Array length should be as long as the highest number in control minus one, generating an zero-based indexed array for control values.",
                "name": "control_description",
                "type": "text"
            },
            {
                "doc": "Number of samples in data, or number of image frames. COMMENT: This is important if the length of timestamp and data are different, such as for externally stored stimulus image stacks",
                "name": "num_samples",
                "type": "int32"
            },
            {
                "attributes": [
                    {
                        "doc": "The number of samples between each timestamp. COMMENT: Presently this value is restricted to 1 (ie, a timestamp for each sample)",
                        "name": "interval",
                        "type": "int32",
                        "value": 1
                    },
                    {
                        "doc": "The string \"Seconds\" COMMENT: All timestamps in the file are stored in seconds. Specifically, this is the number of seconds since the start of the experiment (i.e., since session_start_time)",
                        "name": "unit",
                        "type": "text",
                        "value": "Seconds"
                    }
                ],
                "doc": "Timestamps for samples stored in data.COMMENT: Timestamps here have all been corrected to the common experiment master-clock. Time is stored as seconds and all timestamps are relative to experiment start time.",
                "name": "timestamps",
                "type": "float64!"
            },
            {
                "attributes": [
                    {
                        "doc": "Sampling rate, in Hz COMMENT: Rate information is stored in Hz",
                        "name": "rate",
                        "type": "float32!"
                    },
                    {
                        "doc": "The string \"Seconds\"COMMENT: All timestamps in the file are stored in seconds. Specifically, this is the number of seconds since the start of the experiment (i.e., since session_start_time)",
                        "name": "unit",
                        "type": "text",
                        "value": "Seconds"
                    }
                ],
                "doc": "The timestamp of the first sample. COMMENT: When timestamps are uniformly spaced, the timestamp of the first sample can be specified and all subsequent ones calculated from the sampling rate.",
                "name": "starting_time",
                "type": "float64!"
            },
            {
                "attributes": [
                    {
                        "doc": "The base unit of measure used to store data. This should be in the SI unit. COMMENT: This is the SI unit (when appropriate) of the stored data, such as Volts. If the actual data is stored in millivolts, the field 'conversion' below describes how to convert the data to the specified SI unit.",
                        "name": "unit",
                        "type": "text"
                    },
                    {
                        "doc": "Smallest meaningful difference between values in data, stored in the specified by unit. COMMENT: E.g., the change in value of the least significant bit, or a larger number if signal noise is known to be present. If unknown, use NaN",
                        "name": "resolution",
                        "type": "float32!",
                        "value": 0.0
                    },
                    {
                        "doc": "Scalar to multiply each element in data to convert it to the specified unit",
                        "name": "conversion",
                        "type": "float32!",
                        "value": 1.0
                    }
                ],
                "doc": "Data values. Can also store binary data (eg, image frames) COMMENT: This field may be a link to data stored in an external file, especially in the case of raw data.",
                "name": "data",
                "type": "any"
            },
            {
                "doc": "Numerical labels that apply to each element in data[]. COMMENT: Optional field. If present, the control array should have the same number of elements as data[].",
                "name": "control",
                "type": "uint8"
            }
        ],
        "doc": "General purpose time series.",
        "groups": [
            {
                "doc": "Lab specific time and sync information as provided directly from hardware devices and that is necessary for aligning all acquired time information to a common timebase. The timestamp array stores time in the common timebase. COMMENT: This group will usually only be populated in TimeSeries that are stored external to the NWB file, in files storing raw data. Once timestamp data is calculated, the contents of 'sync' are mostly for archival purposes.",
                "name": "sync"
            }
        ],
        "neurodata_type_def": "TimeSeries"
    }

TwoPhotonSeries
---------------

.. code-block:: python

    {
        "attributes": [
            {
                "doc": "",
                "name": "help",
                "type": "text",
                "value": "Image stack recorded from 2-photon microscope"
            }
        ],
        "datasets": [
            {
                "doc": "Lines imaged per second. This is also stored in /general/optophysiology but is kept here as it is useful information for analysis, and so good to be stored w/ the actual data.",
                "name": "scan_line_rate",
                "type": "float32"
            },
            {
                "doc": "Photomultiplier gain",
                "name": "pmt_gain",
                "type": "float32"
            },
            {
                "doc": "Width, height and depth of image, or imaged area (meters).",
                "name": "field_of_view",
                "type": "float32"
            }
        ],
        "doc": "A special case of optical imaging.",
        "links": [
            {
                "doc": "link to ImagingPlane group from which this TimeSeries data was generated",
                "name": "imaging_plane",
                "target_type": "ImagingPlane"
            }
        ],
        "neurodata_type": "ImageSeries",
        "neurodata_type_def": "TwoPhotonSeries"
    }

UnitTimes
---------

.. code-block:: python

    {
        "attributes": [
            {
                "doc": "",
                "name": "help",
                "type": "text",
                "value": "Estimated spike times from a single unit"
            }
        ],
        "datasets": [
            {
                "doc": "List of units present.",
                "name": "unit_list",
                "type": "text"
            }
        ],
        "doc": "Event times of observed units (e.g. cell, synapse, etc.). The UnitTimes group contains a group for each unit. The name of the group should match the value in the source module, if that is possible/relevant (e.g., name of ROIs from Segmentation module).",
        "groups": [
            {
                "datasets": [
                    {
                        "doc": "Description of the unit (eg, cell type).",
                        "name": "unit_description",
                        "type": "text"
                    },
                    {
                        "doc": "Spike time for the units (exact or estimated)",
                        "name": "times",
                        "type": "float64!"
                    },
                    {
                        "doc": "Name, path or description of where unit times originated. This is necessary only if the info here differs from or is more fine-grained than the interface's source field",
                        "name": "source",
                        "type": "text"
                    }
                ],
                "doc": "Group storing times for &lt;unit_N&gt;.",
                "neurodata_type_def": "SpikeUnit"
            }
        ],
        "name": "UnitTimes",
        "neurodata_type": "Interface",
        "neurodata_type_def": "UnitTimes"
    }

VoltageClampSeries
------------------

.. code-block:: python

    {
        "attributes": [
            {
                "doc": "",
                "name": "help",
                "type": "text",
                "value": "Current recorded from cell during voltage-clamp recording"
            }
        ],
        "datasets": [
            {
                "attributes": [
                    {
                        "doc": "",
                        "name": "unit",
                        "type": "text",
                        "value": "pecent"
                    }
                ],
                "doc": "Unit: %",
                "name": "resistance_comp_correction",
                "type": "float32"
            },
            {
                "attributes": [
                    {
                        "doc": "",
                        "name": "unit",
                        "type": "text",
                        "value": "Farad"
                    }
                ],
                "doc": "Unit: Farad",
                "name": "capacitance_fast",
                "type": "float32"
            },
            {
                "attributes": [
                    {
                        "doc": "",
                        "name": "unit",
                        "type": "text",
                        "value": "Farad"
                    }
                ],
                "doc": "Unit: Farad",
                "name": "capacitance_slow",
                "type": "float32"
            },
            {
                "attributes": [
                    {
                        "doc": "",
                        "name": "unit",
                        "type": "text",
                        "value": "pecent"
                    }
                ],
                "doc": "Unit: %",
                "name": "resistance_comp_prediction",
                "type": "float32"
            },
            {
                "attributes": [
                    {
                        "doc": "",
                        "name": "unit",
                        "type": "text",
                        "value": "Hz"
                    }
                ],
                "doc": "Unit: Hz",
                "name": "resistance_comp_bandwidth",
                "type": "float32"
            },
            {
                "attributes": [
                    {
                        "doc": "",
                        "name": "unit",
                        "type": "text",
                        "value": "Ohm"
                    }
                ],
                "doc": "Unit: Ohm",
                "name": "whole_cell_series_resistance_comp",
                "type": "float32"
            },
            {
                "attributes": [
                    {
                        "doc": "",
                        "name": "unit",
                        "type": "text",
                        "value": "Farad"
                    }
                ],
                "doc": "Unit: Farad",
                "name": "whole_cell_capacitance_comp",
                "type": "float32"
            }
        ],
        "doc": "Stores current data recorded from intracellular voltage-clamp recordings. A corresponding VoltageClampStimulusSeries (stored separately as a stimulus) is used to store the voltage injected.",
        "neurodata_type": "PatchClampSeries",
        "neurodata_type_def": "VoltageClampSeries"
    }

VoltageClampStimulusSeries
--------------------------

.. code-block:: python

    {
        "attributes": [
            {
                "doc": "",
                "name": "help",
                "type": "text",
                "value": "Stimulus voltage applied during voltage clamp recording"
            }
        ],
        "doc": "Aliases to standard PatchClampSeries. Its functionality is to better tag PatchClampSeries for machine (and human) readability of the file.",
        "neurodata_type": "PatchClampSeries",
        "neurodata_type_def": "VoltageClampStimulusSeries"
    }

