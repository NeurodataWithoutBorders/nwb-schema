Format Specification
====================


.. raw:: latex

    \clearpage \newpage

.. _sec-AbstractFeatureSeries:

AbstractFeatureSeries
---------------------

**Extends:** :ref:`TimeSeries <sec-TimeSeries>`

**Overview**

Abstract features, such as quantitative descriptions of sensory stimuli. The TimeSeries::data field is a 2D array, storing those features (e.g., for visual grating stimulus this might be orientation, spatial frequency and contrast). Null stimuli (eg, uniform gray) can be marked as being an independent feature (eg, 1.0 for gray, 0.0 for actual stimulus) or by storing NaNs for feature values, or through use of the TimeSeries::control fields. A set of features is considered to persist until the next set of features is defined. The final set of features stored should be the null set.

``AbstractFeatureSeries`` extends ``TimeSeries`` and includes all elements of :ref:`TimeSeries <sec-TimeSeries>` with the following additions or changes.


.. figure:: ./format_auto_docs/AbstractFeatureSeries.*
    :alt: AbstractFeatureSeries


:ref:`AbstractFeatureSeries specification sources <sec-AbstractFeatureSeries-src>`

.. _sec-AnnotationSeries:

AnnotationSeries
----------------

**Extends:** :ref:`TimeSeries <sec-TimeSeries>`

**Overview**

Stores, eg, user annotations made during an experiment. The TimeSeries::data[] field stores a text array, and timestamps are stored for each annotation (ie, interval=1). This is largely an alias to a standard TimeSeries storing a text array but that is identifiable as storing annotations in a machine-readable way.

``AnnotationSeries`` extends ``TimeSeries`` and includes all elements of :ref:`TimeSeries <sec-TimeSeries>` with the following additions or changes.


.. figure:: ./format_auto_docs/AnnotationSeries.*
    :alt: AnnotationSeries


:ref:`AnnotationSeries specification sources <sec-AnnotationSeries-src>`

.. _sec-BehavioralEpochs:

BehavioralEpochs
----------------

**Extends:** :ref:`Interface <sec-Interface>`

**Overview**

TimeSeries for storing behavoioral epochs.  The objective of this and the other two Behavioral interfaces (e.g. BehavioralEvents and BehavioralTimeSeries) is to provide generic hooks for software tools/scripts. This allows a tool/script to take the output one specific interface (e.g., UnitTimes) and plot that data relative to another data modality (e.g., behavioral events) without having to define all possible modalities in advance. Declaring one of these interfaces means that one or more TimeSeries of the specified type is published. These TimeSeries should reside in a group having the same name as the interface. For example, if a BehavioralTimeSeries interface is declared, the module will have one or more TimeSeries defined in the module sub-group "BehavioralTimeSeries". BehavioralEpochs should use IntervalSeries. BehavioralEvents is used for irregular events. BehavioralTimeSeries is for continuous data.

``BehavioralEpochs`` extends ``Interface`` and includes all elements of :ref:`Interface <sec-Interface>` with the following additions or changes.


.. figure:: ./format_auto_docs/BehavioralEpochs.*
    :alt: BehavioralEpochs


:ref:`BehavioralEpochs specification sources <sec-BehavioralEpochs-src>`

.. _sec-BehavioralEvents:

BehavioralEvents
----------------

**Extends:** :ref:`Interface <sec-Interface>`

**Overview**

TimeSeries for storing behavioral events. See description of <a href="#BehavioralEpochs">BehavioralEpochs</a> for more details.

``BehavioralEvents`` extends ``Interface`` and includes all elements of :ref:`Interface <sec-Interface>` with the following additions or changes.


.. figure:: ./format_auto_docs/BehavioralEvents.*
    :alt: BehavioralEvents


:ref:`BehavioralEvents specification sources <sec-BehavioralEvents-src>`

.. _sec-BehavioralTimeSeries:

BehavioralTimeSeries
--------------------

**Extends:** :ref:`Interface <sec-Interface>`

**Overview**

TimeSeries for storing Behavoioral time series data.See description of <a href="#BehavioralEpochs">BehavioralEpochs</a> for more details.

``BehavioralTimeSeries`` extends ``Interface`` and includes all elements of :ref:`Interface <sec-Interface>` with the following additions or changes.

:ref:`BehavioralTimeSeries specification sources <sec-BehavioralTimeSeries-src>`

.. _sec-ClusterWaveforms:

ClusterWaveforms
----------------

**Extends:** :ref:`Interface <sec-Interface>`

**Overview**

The mean waveform shape, including standard deviation, of the different clusters. Ideally, the waveform analysis should be performed on data that is only high-pass filtered. This is a separate module because it is expected to require updating. For example, IMEC probes may require different storage requirements to store/display mean waveforms, requiring a new interface or an extension of this one.

``ClusterWaveforms`` extends ``Interface`` and includes all elements of :ref:`Interface <sec-Interface>` with the following additions or changes.


.. figure:: ./format_auto_docs/ClusterWaveforms.*
    :alt: ClusterWaveforms


:ref:`ClusterWaveforms specification sources <sec-ClusterWaveforms-src>`

.. _sec-Clustering:

Clustering
----------

**Extends:** :ref:`Interface <sec-Interface>`

**Overview**

Clustered spike data, whether from automatic clustering tools (e.g., klustakwik) or as a result of manual sorting.

``Clustering`` extends ``Interface`` and includes all elements of :ref:`Interface <sec-Interface>` with the following additions or changes.


.. figure:: ./format_auto_docs/Clustering.*
    :alt: Clustering


:ref:`Clustering specification sources <sec-Clustering-src>`

.. _sec-CompassDirection:

CompassDirection
----------------

**Extends:** :ref:`Interface <sec-Interface>`

**Overview**

With a CompassDirection interface, a module publishes a SpatialSeries object representing a floating point value for theta. The SpatialSeries::reference_frame field should indicate what direction corresponds to 0 and which is the direction of rotation (this should be clockwise). The si_unit for the SpatialSeries should be radians or degrees.

``CompassDirection`` extends ``Interface`` and includes all elements of :ref:`Interface <sec-Interface>` with the following additions or changes.


.. figure:: ./format_auto_docs/CompassDirection.*
    :alt: CompassDirection


:ref:`CompassDirection specification sources <sec-CompassDirection-src>`

.. _sec-CorrectedImageStack:

CorrectedImageStack
-------------------

**Overview**

One of possibly many.  Name should be informative.


.. figure:: ./format_auto_docs/CorrectedImageStack.*
    :alt: CorrectedImageStack


:ref:`CorrectedImageStack specification sources <sec-CorrectedImageStack-src>`

.. _sec-CurrentClampSeries:

CurrentClampSeries
------------------

**Extends:** :ref:`PatchClampSeries <sec-PatchClampSeries>`

**Overview**

Stores voltage data recorded from intracellular current-clamp recordings. A corresponding CurrentClampStimulusSeries (stored separately as a stimulus) is used to store the current injected.

``CurrentClampSeries`` extends ``PatchClampSeries`` and includes all elements of :ref:`PatchClampSeries <sec-PatchClampSeries>` with the following additions or changes.


.. figure:: ./format_auto_docs/CurrentClampSeries.*
    :alt: CurrentClampSeries


:ref:`CurrentClampSeries specification sources <sec-CurrentClampSeries-src>`

.. _sec-CurrentClampStimulusSeries:

CurrentClampStimulusSeries
--------------------------

**Extends:** :ref:`PatchClampSeries <sec-PatchClampSeries>`

**Overview**

Aliases to standard PatchClampSeries. Its functionality is to better tag PatchClampSeries for machine (and human) readability of the file.

``CurrentClampStimulusSeries`` extends ``PatchClampSeries`` and includes all elements of :ref:`PatchClampSeries <sec-PatchClampSeries>` with the following additions or changes.

:ref:`CurrentClampStimulusSeries specification sources <sec-CurrentClampStimulusSeries-src>`

.. _sec-Device:

Device
------

**Overview**

One of possibly many. Information about device and device description. COMMENT: Name should be informative. Contents can be from Methods.

:ref:`Device specification sources <sec-Device-src>`

.. _sec-DfOverF:

DfOverF
-------

**Extends:** :ref:`Interface <sec-Interface>`

**Overview**

dF/F information about a region of interest (ROI). Storage hierarchy of dF/F should be the same as for segmentation (ie, same names for ROIs and for image planes).

``DfOverF`` extends ``Interface`` and includes all elements of :ref:`Interface <sec-Interface>` with the following additions or changes.


.. figure:: ./format_auto_docs/DfOverF.*
    :alt: DfOverF


:ref:`DfOverF specification sources <sec-DfOverF-src>`

.. _sec-ElectricalSeries:

ElectricalSeries
----------------

**Extends:** :ref:`TimeSeries <sec-TimeSeries>`

**Overview**

Stores acquired voltage data from extracellular recordings. The data field of an ElectricalSeries is an int or float array storing data in Volts. TimeSeries::data array structure: :blue:`[num times] [num channels] (or [num_times] for single electrode).`

``ElectricalSeries`` extends ``TimeSeries`` and includes all elements of :ref:`TimeSeries <sec-TimeSeries>` with the following additions or changes.


.. figure:: ./format_auto_docs/ElectricalSeries.*
    :alt: ElectricalSeries


:ref:`ElectricalSeries specification sources <sec-ElectricalSeries-src>`

.. _sec-ElectrodeGroup:

ElectrodeGroup
--------------

**Overview**

One of possibly many groups, one for each electrode group. If the groups have a hierarchy, such as multiple probes each having multiple shanks, that hierarchy can be mirrored here, using groups for electrode_probe_X and subgroups for electrode_group_X.COMMENT: Name is arbitrary but should be meaningful.


.. figure:: ./format_auto_docs/ElectrodeGroup.*
    :alt: ElectrodeGroup


:ref:`ElectrodeGroup specification sources <sec-ElectrodeGroup-src>`

.. _sec-Epoch:

Epoch
-----

**Overview**

One of possibly many different experimental epochCOMMENT: Name is arbitrary but must be unique within the experiment.


.. figure:: ./format_auto_docs/Epoch.*
    :alt: Epoch


:ref:`Epoch specification sources <sec-Epoch-src>`

.. _sec-EpochTimeSeries:

EpochTimeSeries
---------------

**Overview**

One of possibly many input or output streams recorded during epoch. COMMENT: Name is arbitrary and does not have to match the TimeSeries that it refers to.


.. figure:: ./format_auto_docs/EpochTimeSeries.*
    :alt: EpochTimeSeries


:ref:`EpochTimeSeries specification sources <sec-EpochTimeSeries-src>`

.. _sec-EventDetection:

EventDetection
--------------

**Extends:** :ref:`Interface <sec-Interface>`

**Overview**

Detected spike events from voltage trace(s).

``EventDetection`` extends ``Interface`` and includes all elements of :ref:`Interface <sec-Interface>` with the following additions or changes.


.. figure:: ./format_auto_docs/EventDetection.*
    :alt: EventDetection


:ref:`EventDetection specification sources <sec-EventDetection-src>`

.. _sec-EventWaveform:

EventWaveform
-------------

**Extends:** :ref:`Interface <sec-Interface>`

**Overview**

Represents either the waveforms of detected events, as extracted from a raw data trace in /acquisition, or the event waveforms that were stored during experiment acquisition.

``EventWaveform`` extends ``Interface`` and includes all elements of :ref:`Interface <sec-Interface>` with the following additions or changes.


.. figure:: ./format_auto_docs/EventWaveform.*
    :alt: EventWaveform


:ref:`EventWaveform specification sources <sec-EventWaveform-src>`

.. _sec-EyeTracking:

EyeTracking
-----------

**Extends:** :ref:`Interface <sec-Interface>`

**Overview**

Eye-tracking data, representing direction of gaze.

``EyeTracking`` extends ``Interface`` and includes all elements of :ref:`Interface <sec-Interface>` with the following additions or changes.


.. figure:: ./format_auto_docs/EyeTracking.*
    :alt: EyeTracking


:ref:`EyeTracking specification sources <sec-EyeTracking-src>`

.. _sec-FeatureExtraction:

FeatureExtraction
-----------------

**Extends:** :ref:`Interface <sec-Interface>`

**Overview**

Features, such as PC1 and PC2, that are extracted from signals stored in a SpikeEvent TimeSeries or other source.

``FeatureExtraction`` extends ``Interface`` and includes all elements of :ref:`Interface <sec-Interface>` with the following additions or changes.


.. figure:: ./format_auto_docs/FeatureExtraction.*
    :alt: FeatureExtraction


:ref:`FeatureExtraction specification sources <sec-FeatureExtraction-src>`

.. _sec-FilteredEphys:

FilteredEphys
-------------

**Extends:** :ref:`Interface <sec-Interface>`

**Overview**

Ephys data from one or more channels that has been subjected to filtering. Examples of filtered data include Theta and Gamma (LFP has its own interface). FilteredEphys modules publish an ElectricalSeries for each filtered channel or set of channels. The name of each ElectricalSeries is arbitrary but should be informative. The source of the filtered data, whether this is from analysis of another time series or as acquired by hardware, should be noted in each's TimeSeries::description field. There is no assumed 1::1 correspondence between filtered ephys signals and electrodes, as a single signal can apply to many nearby electrodes, and one electrode may have different filtered (e.g., theta and/or gamma) signals represented.

``FilteredEphys`` extends ``Interface`` and includes all elements of :ref:`Interface <sec-Interface>` with the following additions or changes.


.. figure:: ./format_auto_docs/FilteredEphys.*
    :alt: FilteredEphys


:ref:`FilteredEphys specification sources <sec-FilteredEphys-src>`

.. _sec-Fluorescence:

Fluorescence
------------

**Extends:** :ref:`Interface <sec-Interface>`

**Overview**

Fluorescence information about a region of interest (ROI). Storage hierarchy of fluorescence should be the same as for segmentation (ie, same names for ROIs and for image planes).

``Fluorescence`` extends ``Interface`` and includes all elements of :ref:`Interface <sec-Interface>` with the following additions or changes.


.. figure:: ./format_auto_docs/Fluorescence.*
    :alt: Fluorescence


:ref:`Fluorescence specification sources <sec-Fluorescence-src>`

.. _sec-IZeroClampSeries:

IZeroClampSeries
----------------

**Extends:** :ref:`CurrentClampSeries <sec-CurrentClampSeries>`

**Overview**

Stores recorded voltage data from intracellular recordings when all current and amplifier settings are off (i.e., CurrentClampSeries fields will be zero). There is no CurrentClampStimulusSeries associated with an IZero series because the amplifier is disconnected and no stimulus can reach the cell.

``IZeroClampSeries`` extends ``CurrentClampSeries`` and includes all elements of :ref:`CurrentClampSeries <sec-CurrentClampSeries>` with the following additions or changes.

:ref:`IZeroClampSeries specification sources <sec-IZeroClampSeries-src>`

.. _sec-Image:

Image
-----

**Overview**

Photograph of experiment or experimental setup (video also OK). COMMENT: Name is arbitrary.  Data is stored as a single binary object (HDF5 opaque type).


.. figure:: ./format_auto_docs/Image.*
    :alt: Image


:ref:`Image specification sources <sec-Image-src>`

.. _sec-ImageMaskSeries:

ImageMaskSeries
---------------

**Extends:** :ref:`ImageSeries <sec-ImageSeries>`

**Overview**

An alpha mask that is applied to a presented visual stimulus. The data[] array contains an array of mask values that are applied to the displayed image. Mask values are stored as RGBA. Mask can vary with time. The timestamps array indicates the starting time of a mask, and that mask pattern continues until it's explicitly changed.

``ImageMaskSeries`` extends ``ImageSeries`` and includes all elements of :ref:`ImageSeries <sec-ImageSeries>` with the following additions or changes.


.. figure:: ./format_auto_docs/ImageMaskSeries.*
    :alt: ImageMaskSeries


:ref:`ImageMaskSeries specification sources <sec-ImageMaskSeries-src>`

.. _sec-ImageSegmentation:

ImageSegmentation
-----------------

**Extends:** :ref:`Interface <sec-Interface>`

**Overview**

Stores pixels in an image that represent different regions of interest (ROIs) or masks. All segmentation for a given imaging plane is stored together, with storage for multiple imaging planes (masks) supported. Each ROI is stored in its own subgroup, with the ROI group containing both a 2D mask and a list of pixels that make up this mask. Segments can also be used for masking neuropil. If segmentation is allowed to change with time, a new imaging plane (or module) is required and ROI names should remain consistent between them.

``ImageSegmentation`` extends ``Interface`` and includes all elements of :ref:`Interface <sec-Interface>` with the following additions or changes.


.. figure:: ./format_auto_docs/ImageSegmentation.*
    :alt: ImageSegmentation


:ref:`ImageSegmentation specification sources <sec-ImageSegmentation-src>`

.. _sec-ImageSeries:

ImageSeries
-----------

**Extends:** :ref:`TimeSeries <sec-TimeSeries>`

**Overview**

General image data that is common between acquisition and stimulus time series. Sometimes the image data is stored in the HDF5 file in a raw format while other times it will be stored as an external image file in the host file system. The data field will either be binary data or empty. TimeSeries::data array structure: [frame] [y][x] or [frame][z][y][x].

``ImageSeries`` extends ``TimeSeries`` and includes all elements of :ref:`TimeSeries <sec-TimeSeries>` with the following additions or changes.


.. figure:: ./format_auto_docs/ImageSeries.*
    :alt: ImageSeries


:ref:`ImageSeries specification sources <sec-ImageSeries-src>`

.. _sec-ImagingPlane:

ImagingPlane
------------

**Overview**

One of possibly many groups describing an imaging plane. COMMENT: Name is arbitrary but should be meaningful. It is referenced by TwoPhotonSeries and also ImageSegmentation and DfOverF interfaces


.. figure:: ./format_auto_docs/ImagingPlane.*
    :alt: ImagingPlane


:ref:`ImagingPlane specification sources <sec-ImagingPlane-src>`

.. _sec-ImagingRetinotopy:

ImagingRetinotopy
-----------------

**Extends:** :ref:`Interface <sec-Interface>`

**Overview**

Intrinsic signal optical imaging or widefield imaging for measuring retinotopy. Stores orthogonal maps (e.g., altitude/azimuth; radius/theta) of responses to specific stimuli and a combined polarity map from which to identify visual areas.<br />Note: for data consistency, all images and arrays are stored in the format [row][column] and [row, col], which equates to [y][x]. Field of view and dimension arrays may appear backward (i.e., y before x).

``ImagingRetinotopy`` extends ``Interface`` and includes all elements of :ref:`Interface <sec-Interface>` with the following additions or changes.


.. figure:: ./format_auto_docs/ImagingRetinotopy.*
    :alt: ImagingRetinotopy


:ref:`ImagingRetinotopy specification sources <sec-ImagingRetinotopy-src>`

.. _sec-IndexSeries:

IndexSeries
-----------

**Extends:** :ref:`TimeSeries <sec-TimeSeries>`

**Overview**

Stores indices to image frames stored in an ImageSeries. The purpose of the ImageIndexSeries is to allow a static image stack to be stored somewhere, and the images in the stack to be referenced out-of-order. This can be for the display of individual images, or of movie segments (as a movie is simply a series of images). The data field stores the index of the frame in the referenced ImageSeries, and the timestamps array indicates when that image was displayed.

``IndexSeries`` extends ``TimeSeries`` and includes all elements of :ref:`TimeSeries <sec-TimeSeries>` with the following additions or changes.


.. figure:: ./format_auto_docs/IndexSeries.*
    :alt: IndexSeries


:ref:`IndexSeries specification sources <sec-IndexSeries-src>`

.. _sec-Interface:

Interface
---------

**Overview**

The attributes specified here are included in all interfaces.


.. figure:: ./format_auto_docs/Interface.*
    :alt: Interface


:ref:`Interface specification sources <sec-Interface-src>`

.. _sec-IntervalSeries:

IntervalSeries
--------------

**Extends:** :ref:`TimeSeries <sec-TimeSeries>`

**Overview**

Stores intervals of data. The timestamps field stores the beginning and end of intervals. The data field stores whether the interval just started (>0 value) or ended (<0 value). Different interval types can be represented in the same series by using multiple key values (eg, 1 for feature A, 2 for feature B, 3 for feature C, etc). The field data stores an 8-bit integer. This is largely an alias of a standard TimeSeries but that is identifiable as representing time intervals in a machine-readable way.

``IntervalSeries`` extends ``TimeSeries`` and includes all elements of :ref:`TimeSeries <sec-TimeSeries>` with the following additions or changes.


.. figure:: ./format_auto_docs/IntervalSeries.*
    :alt: IntervalSeries


:ref:`IntervalSeries specification sources <sec-IntervalSeries-src>`

.. _sec-IntracellularElectrode:

IntracellularElectrode
----------------------

**Overview**

One of possibly many. COMMENT: Name should be informative.


.. figure:: ./format_auto_docs/IntracellularElectrode.*
    :alt: IntracellularElectrode


:ref:`IntracellularElectrode specification sources <sec-IntracellularElectrode-src>`

.. _sec-LFP:

LFP
---

**Extends:** :ref:`Interface <sec-Interface>`

**Overview**

LFP data from one or more channels. The electrode map in each published ElectricalSeries will identify which channels are providing LFP data. Filter properties should be noted in the ElectricalSeries description or comments field.

``LFP`` extends ``Interface`` and includes all elements of :ref:`Interface <sec-Interface>` with the following additions or changes.


.. figure:: ./format_auto_docs/LFP.*
    :alt: LFP


:ref:`LFP specification sources <sec-LFP-src>`

.. _sec-Module:

Module
------

**Overview**

Module.  Name should be descriptive. Stores a collection of related data organized by contained interfaces.  Each interface is a contract specifying content related to a particular type of data.


.. figure:: ./format_auto_docs/Module.*
    :alt: Module


:ref:`Module specification sources <sec-Module-src>`

.. _sec-MotionCorrection:

MotionCorrection
----------------

**Extends:** :ref:`Interface <sec-Interface>`

**Overview**

An image stack where all frames are shifted (registered) to a common coordinate system, to account for movement and drift between frames. Note: each frame at each point in time is assumed to be 2-D (has only x & y dimensions).

``MotionCorrection`` extends ``Interface`` and includes all elements of :ref:`Interface <sec-Interface>` with the following additions or changes.


.. figure:: ./format_auto_docs/MotionCorrection.*
    :alt: MotionCorrection


:ref:`MotionCorrection specification sources <sec-MotionCorrection-src>`

.. _sec-NWBFile:

NWBFile
-------

**Overview**

Top level of NWB file.


.. figure:: ./format_auto_docs/NWBFile.*
    :alt: NWBFile


:ref:`NWBFile specification sources <sec-NWBFile-src>`

.. _sec-OpticalChannel:

OpticalChannel
--------------

**Overview**

One of possibly many groups storing channel-specific data COMMENT: Name is arbitrary but should be meaningful


.. figure:: ./format_auto_docs/OpticalChannel.*
    :alt: OpticalChannel


:ref:`OpticalChannel specification sources <sec-OpticalChannel-src>`

.. _sec-OpticalSeries:

OpticalSeries
-------------

**Extends:** :ref:`ImageSeries <sec-ImageSeries>`

**Overview**

Image data that is presented or recorded. A stimulus template movie will be stored only as an image. When the image is presented as stimulus, additional data is required, such as field of view (eg, how much of the visual field the image covers, or how what is the area of the target being imaged). If the OpticalSeries represents acquired imaging data, orientation is also important.

``OpticalSeries`` extends ``ImageSeries`` and includes all elements of :ref:`ImageSeries <sec-ImageSeries>` with the following additions or changes.


.. figure:: ./format_auto_docs/OpticalSeries.*
    :alt: OpticalSeries


:ref:`OpticalSeries specification sources <sec-OpticalSeries-src>`

.. _sec-OptogeneticSeries:

OptogeneticSeries
-----------------

**Extends:** :ref:`TimeSeries <sec-TimeSeries>`

**Overview**

Optogenetic stimulus.  The data[] field is in unit of watts.

``OptogeneticSeries`` extends ``TimeSeries`` and includes all elements of :ref:`TimeSeries <sec-TimeSeries>` with the following additions or changes.


.. figure:: ./format_auto_docs/OptogeneticSeries.*
    :alt: OptogeneticSeries


:ref:`OptogeneticSeries specification sources <sec-OptogeneticSeries-src>`

.. _sec-OptogeneticStimulusSite:

OptogeneticStimulusSite
-----------------------

**Overview**

One of possibly many groups describing an optogenetic stimuluation site. COMMENT: Name is arbitrary but should be meaningful. Name is referenced by OptogeneticSeries


.. figure:: ./format_auto_docs/OptogeneticStimulusSite.*
    :alt: OptogeneticStimulusSite


:ref:`OptogeneticStimulusSite specification sources <sec-OptogeneticStimulusSite-src>`

.. _sec-PatchClampSeries:

PatchClampSeries
----------------

**Extends:** :ref:`TimeSeries <sec-TimeSeries>`

**Overview**

Stores stimulus or response current or voltage. Superclass definition for patch-clamp data (this class should not be instantiated directly).

``PatchClampSeries`` extends ``TimeSeries`` and includes all elements of :ref:`TimeSeries <sec-TimeSeries>` with the following additions or changes.


.. figure:: ./format_auto_docs/PatchClampSeries.*
    :alt: PatchClampSeries


:ref:`PatchClampSeries specification sources <sec-PatchClampSeries-src>`

.. _sec-PlaneSegmentation:

PlaneSegmentation
-----------------

**Overview**

Group name is human-readable description of imaging plane


.. figure:: ./format_auto_docs/PlaneSegmentation.*
    :alt: PlaneSegmentation


:ref:`PlaneSegmentation specification sources <sec-PlaneSegmentation-src>`

.. _sec-Position:

Position
--------

**Extends:** :ref:`Interface <sec-Interface>`

**Overview**

Position data, whether along the x, x/y or x/y/z axis.

``Position`` extends ``Interface`` and includes all elements of :ref:`Interface <sec-Interface>` with the following additions or changes.


.. figure:: ./format_auto_docs/Position.*
    :alt: Position


:ref:`Position specification sources <sec-Position-src>`

.. _sec-PupilTracking:

PupilTracking
-------------

**Extends:** :ref:`Interface <sec-Interface>`

**Overview**

Eye-tracking data, representing pupil size.

``PupilTracking`` extends ``Interface`` and includes all elements of :ref:`Interface <sec-Interface>` with the following additions or changes.


.. figure:: ./format_auto_docs/PupilTracking.*
    :alt: PupilTracking


:ref:`PupilTracking specification sources <sec-PupilTracking-src>`

.. _sec-ROI:

ROI
---

**Overview**

Name of ROI


.. figure:: ./format_auto_docs/ROI.*
    :alt: ROI


:ref:`ROI specification sources <sec-ROI-src>`

.. _sec-RoiResponseSeries:

RoiResponseSeries
-----------------

**Extends:** :ref:`TimeSeries <sec-TimeSeries>`

**Overview**

ROI responses over an imaging plane. Each row in data[] should correspond to the signal from one ROI.

``RoiResponseSeries`` extends ``TimeSeries`` and includes all elements of :ref:`TimeSeries <sec-TimeSeries>` with the following additions or changes.


.. figure:: ./format_auto_docs/RoiResponseSeries.*
    :alt: RoiResponseSeries


:ref:`RoiResponseSeries specification sources <sec-RoiResponseSeries-src>`

.. _sec-SpatialSeries:

SpatialSeries
-------------

**Extends:** :ref:`TimeSeries <sec-TimeSeries>`

**Overview**

Direction, e.g., of gaze or travel, or position. The TimeSeries::data field is a 2D array storing position or direction relative to some reference frame. Array structure: [num measurements] [num dimensions]. Each SpatialSeries has a text dataset reference_frame that indicates the zero-position, or the zero-axes for direction. For example, if representing gaze direction, "straight-ahead" might be a specific pixel on the monitor, or some other point in space. For position data, the 0,0 point might be the top-left corner of an enclosure, as viewed from the tracking camera. The unit of data will indicate how to interpret SpatialSeries values.

``SpatialSeries`` extends ``TimeSeries`` and includes all elements of :ref:`TimeSeries <sec-TimeSeries>` with the following additions or changes.


.. figure:: ./format_auto_docs/SpatialSeries.*
    :alt: SpatialSeries


:ref:`SpatialSeries specification sources <sec-SpatialSeries-src>`

.. _sec-SpecFile:

SpecFile
--------

**Overview**

Dataset for storing contents of a specification file for either the core format or an extension.  Name should match name of file.`


.. figure:: ./format_auto_docs/SpecFile.*
    :alt: SpecFile


:ref:`SpecFile specification sources <sec-SpecFile-src>`

.. _sec-SpikeEventSeries:

SpikeEventSeries
----------------

**Extends:** :ref:`ElectricalSeries <sec-ElectricalSeries>`

**Overview**

Stores "snapshots" of spike events (i.e., threshold crossings) in data. This may also be raw data, as reported by ephys hardware. If so, the TimeSeries::description field should describing how events were detected. All SpikeEventSeries should reside in a module (under EventWaveform interface) even if the spikes were reported and stored by hardware. All events span the same recording channels and store snapshots of equal duration. TimeSeries::data array structure: :blue:`[num events] [num channels] [num samples] (or [num events] [num samples] for single electrode)`.

``SpikeEventSeries`` extends ``ElectricalSeries`` and includes all elements of :ref:`ElectricalSeries <sec-ElectricalSeries>` with the following additions or changes.


.. figure:: ./format_auto_docs/SpikeEventSeries.*
    :alt: SpikeEventSeries


:ref:`SpikeEventSeries specification sources <sec-SpikeEventSeries-src>`

.. _sec-SpikeUnit:

SpikeUnit
---------

**Overview**

Group storing times for &lt;unit_N&gt;.


.. figure:: ./format_auto_docs/SpikeUnit.*
    :alt: SpikeUnit


:ref:`SpikeUnit specification sources <sec-SpikeUnit-src>`

.. _sec-TimeSeries:

TimeSeries
----------

**Overview**

General purpose time series.


.. figure:: ./format_auto_docs/TimeSeries.*
    :alt: TimeSeries


:ref:`TimeSeries specification sources <sec-TimeSeries-src>`

.. _sec-TwoPhotonSeries:

TwoPhotonSeries
---------------

**Extends:** :ref:`ImageSeries <sec-ImageSeries>`

**Overview**

A special case of optical imaging.

``TwoPhotonSeries`` extends ``ImageSeries`` and includes all elements of :ref:`ImageSeries <sec-ImageSeries>` with the following additions or changes.


.. figure:: ./format_auto_docs/TwoPhotonSeries.*
    :alt: TwoPhotonSeries


:ref:`TwoPhotonSeries specification sources <sec-TwoPhotonSeries-src>`

.. _sec-UnitTimes:

UnitTimes
---------

**Extends:** :ref:`Interface <sec-Interface>`

**Overview**

Event times of observed units (e.g. cell, synapse, etc.). The UnitTimes group contains a group for each unit. The name of the group should match the value in the source module, if that is possible/relevant (e.g., name of ROIs from Segmentation module).

``UnitTimes`` extends ``Interface`` and includes all elements of :ref:`Interface <sec-Interface>` with the following additions or changes.


.. figure:: ./format_auto_docs/UnitTimes.*
    :alt: UnitTimes


:ref:`UnitTimes specification sources <sec-UnitTimes-src>`

.. _sec-VoltageClampSeries:

VoltageClampSeries
------------------

**Extends:** :ref:`PatchClampSeries <sec-PatchClampSeries>`

**Overview**

Stores current data recorded from intracellular voltage-clamp recordings. A corresponding VoltageClampStimulusSeries (stored separately as a stimulus) is used to store the voltage injected.

``VoltageClampSeries`` extends ``PatchClampSeries`` and includes all elements of :ref:`PatchClampSeries <sec-PatchClampSeries>` with the following additions or changes.


.. figure:: ./format_auto_docs/VoltageClampSeries.*
    :alt: VoltageClampSeries


:ref:`VoltageClampSeries specification sources <sec-VoltageClampSeries-src>`

.. _sec-VoltageClampStimulusSeries:

VoltageClampStimulusSeries
--------------------------

**Extends:** :ref:`PatchClampSeries <sec-PatchClampSeries>`

**Overview**

Aliases to standard PatchClampSeries. Its functionality is to better tag PatchClampSeries for machine (and human) readability of the file.

``VoltageClampStimulusSeries`` extends ``PatchClampSeries`` and includes all elements of :ref:`PatchClampSeries <sec-PatchClampSeries>` with the following additions or changes.

:ref:`VoltageClampStimulusSeries specification sources <sec-VoltageClampStimulusSeries-src>`

