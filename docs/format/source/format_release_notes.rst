Release Notes
=============

2.0.0 Beta (2017/18)
--------------------

**First release:** November 2017

**Subsequent releases:** The schema was improved and updated throughout the beta phase with full release planed for fall 2018.

Improved organization of electrode metadata in ``/general/extracellular_ephys``
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

**Change:** Consolidate metadata from related electrodes (e.g., from a single device) in a single location.

**Example:** Previous versions of the format specified in ``/general/extracellular_ephys`` for each electrode a
group ``<electrode_group_X>`` that stores 3 text datastes with a description, device name, and location, respectively.
The main ``/general/extracellular_ephys group`` then contained in addition the following datasets:

    - ``electrode_group`` text array describing for each electrode_group (implicitly referenced by index)
      which device (shank, probe, tetrode, etc.) was used,
    - ``electrode_map`` array with the x,y,z locations of each electrode
    - ``filtering``, i.e., a single string describing the filtering for all electrodes (even though each
      electrode might be from different devices), and iv),
    - ``impedance``, i.e, a single text array for impedance (i.e., the user has to know which format the
      string has, e.g, a float or a tuple of floats for impedance ranges).


**Reason:**

    - Avoid explosion of the number of groups and datasets. For example, in the case of an ECoG grid with 128 channels
      one had to create 128 groups and corresponding datasets to store the required metadata about the electrodes
      using the original layout.
    - Simplify access to related metadata. E.g., access to metadata from all electrodes of a single device requires
      resolution of a potentially large number of implicit links and access to a large number of groups (one per electrode)
      and datasets.
    - Improve performance of metadata access operations. E.g., to access the ``location`` of all electrodes corresponding to a
      single recording in an ``<ElectricalSeries>`` in the original layout required iterating over a potentially large number of
      groups and datasets (one per electrode), hence, leading to a large number of small, independent read/write/seek operations,
      causing slow performance on common data accesses. Using the new layout, these kind of common data accesses can often be
      resolved via a single read/write
    - Ease maintenance, use, and development through consolidation of related metadata

**Format Changes**

    - Added specification of a new neurodata type ``<ElectrodeGroup>`` group.
      Each ``<ElectrodeGroup>`` contains the following datasets to describe the metadata of a set of related
      electrodes (e.g,. all electrodes from a single device):

        - ``description`` : text dataset (for the group)
        - ``device``: Soft link to the device in ``/general/devices/``
        - ``location``: Text description of the location of the device

    - Added table-like dataset ``electrodes`` that consolidates all electrode-specific metadata. This is a
      :ref:`DynamicTable <sec-DynamicTable>` describing for each electrode:

        - ``id`` : a user-specified unique identifier
        - ``x``, ``y``, ``z`` : The floating point coordinate for the electrode
        - ``imp`` : the impedance of the channel
        - ``location`` : The location of channel within the subject e.g. brain region
        - ``filtering`` : Description of hardware filtering
        - ``group`` : Object reference to the ``ElectrodeGroup`` object
        - ``group_name`` : The name of the ``ElectrodeGroup``

    - Updated ``/general/extracellular_ephys`` as follows:

        - Replaced ``/general/extracellular_ephys/<electrode_group_X>`` group (and all its contents) with the new ``<ElectrodeGroup>``
        - Removed ``/general/extracellular_ephys/electrode_map`` dataset. This information is now stored in the ``ElectrodeTable``.
        - Removed ``/general/extracellular_ephys/electrode_group`` dataset. This information is now stored in ``<ElectrodeGroup>/device``.
        - Removed ``/general/extracellular_ephys/impedance`` This information is now stored in the ``ElectrodeTable``.
        - Removed ``/general/extracellular_ephys/filtering`` This information is now stored in the ``ElectrodeTable``.


.. note::

    In NWB 2.0Beta the refactor originally used a row-based table for the ``ElectrodeTable`` based on a compound
    data type as described in `#I6 (new-schema) <https://github.com/NeurodataWithoutBorders/nwb-schema/issues/6>`_, i.e.,
    ``electrodes`` was a 1D compound dataset. This was later changed to a column-based :ref:`DynamicTable <sec-DynamicTable>`
    (see :ref:`sec-rn-tables`). The main reason for this later change was mainly to avoid the need
    for large numbers of user-extensions to add electrode metadata
    (see `#I623 (PyNWB) <https://github.com/NeurodataWithoutBorders/pynwb/issues/623>`_ and
    `PR634 (PyNWB) <https://github.com/NeurodataWithoutBorders/pynwb/pull/634>`_ for details.) This change
    also removed the optional ``description`` column as it can be added easily by the user to the
    :ref:`DynamicTable <sec-DynamicTable>` if required.


Replaced Implicit Links/Data-Structures with Explicit Links
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

**Change** Replace implicit links with explicit soft-links to the corresponding HDF5 objects where possible, i.e.,
use explicit HDF5 mechanisms for expressing basic links between data rather than implicit ones that require
users/developers to know how to use the specific data.

**Reason:** In several places datasets containing arrays of either i) strings with object names, ii) strings with paths,
or iii) integer indexes are used that implicitly point to other locations in the file. These forms of implicit
links are not self-describing (e.g., the kind of linking, target location, implicit size and numbering assumptions
are not easily identified). This hinders human interpretation of the data as well as programmatic resolution of these
kind of links.

**Format Changes:**

    - Text dataset ``image_plane`` of ``<TwoPhotonSeries>`` is now a link to the corresponding ``<ImagingPlane>``
      (which is stored in ``/general/optophysiology``)
    - Text dataset ``image_plane_name`` of ``<ImageSegmentation>`` is now a link to the corresponding ``<ImagingPlane>``
      (which is stored in ``/general/optophysiology``). The dataset is also renamed to ``image_plane`` for consistency with ``<TwoPhotonSeries>``
    - Text dataset ``electrode_name`` of ``<PatchClampSeries>`` is now a link to the corresponding ``<IntracellularElectrode>``
      (which is stored in ``/general/intracellular_ephys``). The dataset is also renamed to ``electrode`` for consistency.
    - Text dataset ``site`` in ``<OptogeneticSeries>`` is now a link to the corresponding ``<StimulusSite>``
      (which is stored in ``/general/optogenetics``).
    - Integer dataset ``electrode_idx`` of ``FeatureExtraction`` is now a dataset ``electrodes`` of type
      :ref:`DynamicTableRegion <sec-DynamicTableRegion>` pointing to a region of the ``ElectrodeTable`` stored in ``/general/extracellular_ephys/electrodes``.
    - Integer array dataset ``electrode_idx`` of ``<ElectricalSeries>`` is now a dataset ``electrodes`` of type
      :ref:`DynamicTableRegion <sec-DynamicTableRegion>` pointing to a region of the ``ElectrodeTable`` stored in ``/general/extracellular_ephys/electrodes``.
    - Text dataset ``/general/extracellular_ephys/<electrode_group_X>/device`` is now a link ``<ElectrodeGroup>/device``


.. _sec-rn-tables:

Support row-based and column-based tables
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

**Change:** Add support for storing tabular data via row-based and column-based table structures.

**Reason:** Simplify storage of complex metadata. Simplify storage of dynamic and variable-length metadata.

**Format Changes:**

    * **Row-based tables:** are implemented via a change in the specification language through support for
      compound data types The advantage of row-based tables is that they i) allow referencing of sets of
      rows via region-references to a single dataset (e.g., a set of electrodes), ii)  make it
      easy to add rows by appending to a single dataset, iii) make it easy to read individual rows
      of a table (but require reading the full table to extract the data of a single column).
      Row-based tables are used to simplify, e.g,. the organization of electrode-metadata in NWB:N 2 (see above).
      (See the `specification language release notes <http://schema-language.readthedocs.io/en/latest/specification_language_release_notes.html#release-notes>`_
      for details about the addition of compound data types in the schema).

      * *Referencing rows in a row-based tables:* Subsets of rows can referenced directly via a region-reference to the
        row-based table. Subsets
      * *Referencing columns in a row-based table:* This is currently not directly supported, but could be implemented
        via a combination of an object-reference to the table and a list of the lables of columns.

    * **Column-based tables:** are implemented via the new neurodata_type :ref:`DynamicTable <sec-DynamicTable>`.
      A DynamicTable is simplified-speaking just a collection of an arbitrary number of :ref:`TableColumn <sec-TableColumn>`
      datasets (all with equal length) and a dataset storing row ids and a dataset storing column names. The
      advantage of the column-based store is that it i) makes it easy to add new columns to the table without
      the need for extensions and ii) the column-based storage makes it easy to read individual columns
      efficiently (while reading full rows requires reading from multiple datasets). DynamicTable is used, e.g.,
      to enhance storage of trial data. (See https://github.com/NeurodataWithoutBorders/pynwb/pull/536/files )

      * *Referencing rows in column-based tables:*  As :ref:`DynamicTable <sec-DynamicTable>` consist of multiple
        datasets (compared to row-based tables which consists of a single 1D dataset with a compound datatuype)
        is not possible to reference a set of rows with a single region reference. To address this issue, NWB:N defines
        :ref:`DynamicTableRegion <sec-DynamicTableRegion>` (added later in `PR634 (PyNWB) <https://github.com/NeurodataWithoutBorders/pynwb/pull/634>`_)
        dataset type, which stores a list of integer indices (row index) and also has an attribute ``table`` with
        the object reference to the corresponding :ref:`DynamicTable <sec-DynamicTable>`.
      * *Referencing columns in a columns-based table:* As each column is a seperate dataset, columns of a column-based
        :ref:`DynamicTable <sec-DynamicTable>` can be directly references via links, object-references and
        region-references.

Improved support for trial-based data
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

**Change:** Add dedicated concept for storing trial data.

**Reason:** Users indicated that it was not easy to store trial data in NWB:N 1.x.

**Format Changes:** Added optional top-level group ``trials/`` which is a :ref:`DynamicTable <sec-DynamicTable>`
with ``id``,``start``, and ``end`` columns and optional additional user-defined table columns.
See `PR536 on PyNWB <https://github.com/NeurodataWithoutBorders/pynwb/pull/536/files>`_ for detailed code changes. See
the `PyNWB docs <https://pynwb.readthedocs.io/en/latest/tutorials/general/file.html?highlight=Trial#trials>`__ for a
short tutorial on how to use trials. See :ref:`NWBFile <sec-NWBFile>` *Groups: /trials* for an overview of the trial
schema.

Improved support for unit-based metadata
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

**Change:** Add dedicated concept for storing unit data.

**Reason:** Users indicated that it was not easy to store user-defined  metadata about units.

**Format Changes:** Added optional top-level group ``units/`` which is a :ref:`DynamicTable <sec-DynamicTable>`
with a ``id`` and``description`` columns and optional additional user-defined table columns.
See `PR597 on PyNWB <https://github.com/NeurodataWithoutBorders/pynwb/pull/597>`_ for detailed code changes. See
the `PyNWB docs <https://pynwb.readthedocs.io/en/latest/tutorials/general/file.html#units>`__ for a
short tutorial on how to use unit metadata. See :ref:`NWBFile <sec-NWBFile>` *Groups: /units* for an overview of the
unit schema.

Improved storage of epoch data
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

**Change:** Store epoch data as a series of tables to improve efficiency, usability and extensibility.

**Reason:** In NWB 1.x Epochs are stored as a single group per Epoch. Within each Epoch, the index into each
TimeSeries that the Epoch applies to was stored as a single group. This structure is inefficient for storing
large numbers of Epochs.

**Format Changes:**

* Create new neurodata_type :ref:`Epochs <sec-Epochs>` which is included in :ref:`NWBFile <sec-NWBFile>` as the group
  ``epochs``. This simplifies extension of the epochs structure. /epochs now contains an
  :ref:`EpochTable <sec-EpochTable>` that describes that start/stop times, tags, and a region reference into the
  :ref:`TimeSeriesIndex <sec-TimeSeriesIndex>` to identify the timeseries parts the epoch applys to.
  (see `PR396 (PyNWB) <https://github.com/NeurodataWithoutBorders/pynwb/pull/396>`_ and
  `I119 (nwb-schema) <https://github.com/NeurodataWithoutBorders/nwb-schema/issues/119>`_ )
* In addition, a :ref:`DynamicTable <sec-DynamicTable>` for storing dynamic metadata about epochs has been added to
  the :ref:`Epochs <sec-Epochs>` neurodata_type to support storage of dynamic metadata about epochs without requiring
  users to create custom extensions
  (see `PR536 (PyNWB) <https://github.com/NeurodataWithoutBorders/pynwb/pull/536/files>`_).

Improved storage of ROIs
^^^^^^^^^^^^^^^^^^^^^^^^

**Reason:**

* **Improve efficiency:** Similar to epochs, in NWB 1.x ROIs were stored as a single group per ROI. This structure is
  inefficient for storing large numbers of ROIs.
* **Make links explicit:** The relationship of ``RoiResponseSeries`` to ``ROI`` objects was implicit (i.e. ROI was
  specified by a string), so one had to know a priori which ``ImageSegmentation`` and ``ImagingPlane`` was used
  to produce the ROIs.

**Changes:** See also `PR391 (PyNWB) <https://github.com/NeurodataWithoutBorders/pynwb/pull/391>`_ and
`I118 (nwb-schema) <https://github.com/NeurodataWithoutBorders/nwb-schema/issues/118>`_ for details:

1. Added neurodata_type :ref:`ImageMasks <sec-ImageMasks>` replacing ROI.img_mask (from NWB:N 1.x) with a 3D dataset with
   shape [num_rois, num_x_pixels, num_y_pixels] (i.e. an array of image masks)
2. Added neurodata_type :ref:`PixelMasks <sec-PixelMasks>` which replaces ROI.pix_mask/ROI.pix_mask_weight (from NWB:N 1.x)
   with a table that has columns “x”, “y”, and “weight” (i.e. combining ROI.pix_mask and ROI.pix_mask_weight
   into a single table)
3. Added neurodata_type :ref:`ROITable <sec-ROITable>` which defines a table  for storing references to the image mask
   and pixel mask for each ROI (see item 1,2)
4. Added neurodata_type :ref:`ROITableRegion <sec-ROITableRegion>` for referencing a subset of elements in an ROITable
5. Replaced ``RoiResponseSeries.roi_names`` with ``RoiResponseSeries.rois``, which is
   an :ref:`ROITableRegion <sec-ROITableRegion>`  (see items 3,4)
6. Removed ``RoiResponseSeries.segmentation_interface``. This information is available through
   ``RoiResponseSeries.rois`` (described above in 5.)
7. Assigned neurodata_type :ref:`PlaneSegmentation <sec-PlaneSegmentation>` to the image_plan group in
   :ref:`ImageSegmentation <sec-ImageSegmentation>` and updated it to use the new :ref:`ROITable <sec-ROITable>`,
   :ref:`ImageMasks <sec-ImageMasks>`, and :ref:`PixelMasks <sec-PixelMasks>` (see items 1-4 above).



.. _sec-rn-vectordata-nwb2:

Enable efficient storage of large numbers of vector data elements
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

**Change** Introduce neurodata_types :ref:`VectorData <sec-VectorData>` , :ref:`VectorIndex <sec-VectorIndex>`,
:ref:`ElementIdentifiers <sec-ElementIdentifiers>`

**Reason** To efficiently store spike data as part of UnitTimes a new, more efficient data structure was required.
This builds the general, reusable types to define efficient data storage for large numbers of data vectors in
efficient, consolidated arrays, which enable more efficient read, write, and search (see :ref:`sec-rn-unittimes-nwb2`).

**Format Changes**

* :ref:`VectorData <sec-VectorData>` : Data values from a series of data elements are concatinated into a single
  array. This allows all elements to be stored efficiently in a single data array.
* :ref:`VectorIndex <sec-VectorIndex>` : 1D dataset of region-references selecting subranges in
  :ref:`VectorData <sec-VectorData>`. With this we can efficiently access single sub-vectors associated with single
  elements from the :ref:`VectorData <sec-VectorData>` collection.
* :ref:`ElementIdentifiers <sec-ElementIdentifiers>` : 1D array for stroing unique identifiers for the elements in
  a VectorIndex.

See :ref:`sec-rn-vectordata-nwb2` for am illustration and specific example use in practice.
See also `I116 (nwb-schema) <https://github.com/NeurodataWithoutBorders/nwb-schema/issues/117>`__ and
`PR382 (PyNWB) <https://github.com/NeurodataWithoutBorders/pynwb/pull/382>`__ for further details.


.. _sec-rn-unittimes-nwb2:

Improve storage of spike data (i.e., UnitTimes)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

**Change** Restructure :ref:`UnitTimes <sec-UnitTimes>` to use the new :ref:`VectorData <sec-VectorData>` ,
:ref:`VectorIndex <sec-VectorIndex>`, :ref:`ElementIdentifiers <sec-ElementIdentifiers>` data structures
(see :ref:`sec-rn-vectordata-nwb2`)

**Reason:** In NWB:N 1.x each unit was stored as a separate group ``unit_n`` containing the ``times`` and
``unit_description`` for unit with index ``n``. In cases where users have a very large number of units, this
was problematic with regard to performance.

**Format Changes:**


* Replaced ``unit_n`` (from NWB:N 1.x, also referred to by neurodata_type ``SpikeUnit`` in NWB:N 2beta) groups in
  :ref:`UnitTimes <sec-UnitTimes>` with the following datadates:

    * ``unit_ids`` : :ref:`ElementIdentifiers <sec-ElementIdentifiers>` dataset for stroing unique ides for each element
    * ``spike_times_index``: :ref:`VectorIndex <sec-VectorIndex>` dataset with region references into the spike times dataset
    * ``spike_times``: :ref:`VectorData <sec-VectorData>` dataset storing the actual spike times data of all units in
      a single data array (for efficiency).

.. _fig-software-architecture:

.. figure:: figures/unit_times_refactor_nwb2_release_notes.*
   :width: 75%
   :alt: UnitTimes data structure overview

   Overview of the basic data structure for storing :ref:`UnitTimes <sec-UnitTimes>` using the
   :ref:`VectorData <sec-VectorData>` (``spike_times``), :ref:`VectorIndex <sec-VectorIndex>` (``spike_times_index``),
   and :ref:`ElementIdentifiers <sec-ElementIdentifiers>` (``unit_ids``) data structures.


See also `I116 (nwb-schema) <https://github.com/NeurodataWithoutBorders/nwb-schema/issues/117>`__ and
`PR382 (PyNWB) <https://github.com/NeurodataWithoutBorders/pynwb/pull/382>`__ for further details.

Reduce requirement for potentially empty groups
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

**Change:** Make several previously required fields optional

**Reason:** Reduce need for empty groups.

**Format Changes:** The following groups/datasets have been made optional:

    * ``/epochs`` : not all experiments may require epochs.
    * ``/general/optogenetics`` : not all epeeriments may use optogenetic data
    * ``device`` in :ref:`IntracellularElectrode <sec-IntracellularElectrode>`
    *

Added missing metadata
^^^^^^^^^^^^^^^^^^^^^^

**Change:** Add a few missing metadata attributes/datasets.

**Reason:** Ease data interpretation, improve format consistency, and enable storage of additional metadata

**Format Changes:**

    - ``/general/devices`` text dataset becomes group with neurodata type ``Device`` to enable storage of more complex
      and structured metadata about devices (rather than just a single string)
    - Added attribute ``unit=Seconds`` to ``<EventDetection>/times`` dataset to explicitly describe time units
      and improve human and programmatic data interpretation
    - Added ``filtering`` dataset to type ``<IntracellularElectrode>`` (i.e., ``/general/intracellular_ephys/<electrode_X>``)
      to enable specification of per-electrode filtering data
    - Added default values for ``<TimeSeries>/description`` and ``<TimeSeries>/comments``

Improved identifiably of objects
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

**Change:** All groups and datasets are now required to either have a unique ``name`` or a unique ``neurodata_type`` defined.

**Reason:**  This greatly simplifies the unique identification of objects with variable names.

**Format Changes:** Defined missing neurodata_types for a number of objects, e.g.,:

    - Group ``/general/optophysiology/<imaging_plane_X>`` now has the neurodata type ``ImagingPlane``
    - Group ``/general/intracellular_ephys/<electrode_X>`` now has the neurodata type ``IntracellularElectrode``
    - Group ``/general/optogenetics/<site_X>`` now has the neurodata type ``StimulusSite``
    - ...

To enable identification of the type of objects, the ``neurodata_type`` is stored in HDF5 files as an
attribute on the corresponding object (i.e., group or dataset). Also information about the ``namespace``
(e.g., the name and version) are stored as attributed to allow unique identification of the specification
for storage objects.


Improved Consistency
^^^^^^^^^^^^^^^^^^^^

**Change:** Rename objects (and add missing objects)

**Reason:** Improve consistency in the naming of data objects that store similar types of information in different
places and ensure that the same kind of information is available.

**Format Changes:**

    - Added missing ``help`` attribute for ``<BehavioralTimeSeries>`` to improve consistency with other types
      as well as human data interpretation
    - Renamed dataset ``image_plan_name`` in ``<ImageSegmentation>`` to ``image_plane``to ensure consistency
      in naming with ``<TwoPhotonSeries>``
    - Renamed dataset ``electrode_name`` in ``<PatchClampSeries>`` to ``electrode`` for consistency (and
      since the dataset is now a link, rather than a text name).
    - Renamed dataset ``electrode_idx`` in ``<FeatureExtraction>`` to ``electrode_group`` for consistency
      (and since the dataset is now a link to the ``<ElectrodeGroup>``)
    - Renamed dataset ``electrode_idx`` in ``<ElectricalSeries>`` to ``electrode_group`` for consistency
      (and since the dataset is now a link to the ``<ElectrodeGroup>``)

Improved governance and accessibility
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

**Change:** Updated release and documentation mechanisms for the NWB:N format specification

**Reason:** Improve governance, ease-of-use, extensibility, and accessibility of the NWB:N format specification

**Specific Changes**

    - The NWB:N format specification is now released in seperate Git repository
    - Format specifications are released as YAML files (rather than via Python .py file included in the API)
    - Organized core types into a set of smaller YAML files to ease overview and maintenance
    - Converted all documentation documents to Sphinx reStructuredText to improve portability, maintainability,
      deployment, and public access
    - Sphinx documentation for the format are auto-generated from the YAML sources to ensure consistency between
      the specification and documentation
    - The PyNWB API now provides dedicated data structured to interact with NWB:N specifications, enabling users
      programmatically access and generate format specifications


Added new base data dypes: ``NWBContainer``, ``NWBData``, ``NWBDataInterface``
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

**Change:** Added common base types for Groups, Datasets, and for Groups storing primary experiment data

**Reason** Collect common functionality and ease future evolution of the standard

**Specific Changes**

    * :ref:`NWBContainer <sec-NWBContainer>` defines a common base type for all Groups with a ``neurodata_type`` and
      is now the base type of all main data group types in the NWB:N format,
      including :ref:`TimeSeries <sec-TimeSeries>`. This also means that all group types now inherit the required
      ``help`` and ``source`` attribute from ``NWBContainer``. A number of neurodata_types have been updated
      to add the missing ``help`` (see
      https://github.com/NeurodataWithoutBorders/nwb-schema/pull/37/files for details)
    * :ref:`NWBDataInterface <sec-NWBDataInterface>` extends :ref:`NWBContainer <sec-NWBContainer>` and replaces
      ``Interface`` from NWB:N 1.x. It has been renamed to ease intuition. :ref:`NWBDataInterface <sec-NWBDataInterface>`
      serves as base type for primary data (e.g., experimental or analysis data) and is used to
      distinguish in the schema between non-metadata data containers and metadata containers.
      (see https://github.com/NeurodataWithoutBorders/nwb-schema/pull/116/files for details)
    * :ref:`NWBData <sec-NWBData>` defines a common base type for all Datasets with a ``neurodata_type``
      and serves a similar function to :ref:`NWBContainer <sec-NWBContainer>` only for Datasets instead of Groups.


Improved organization of processed data
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

**Change:** Relaxed requirements and renamed and refined core types used for storage of processed data.

**Reason:** Ease user intuition and provide greater flexibility for users.

**Specific Changes:** The following changes have been made to the organization of processed data:

    * *Module* has been renamed to :ref:`ProcessingModule <sec-ProcessingModule>` to avoid possible confusion
       and to clarify its purpose. Also :ref:`ProcessingModule <sec-ProcessingModule>` may now
       contain any  :ref:`NWBDataInterface <sec-NWBDataInterface>`.
    * With :ref:`NWBDataInterface <sec-NWBDataInterface>` now being a general base class of
      :ref:`TimeSeries <sec-TimeSeries>`, this means that it is is now
      possible to define data processing types that directly inherit from :ref:`TimeSeries <sec-TimeSeries>`,
      which was not possible in NWB:N 1.x.
    * *Interface* has been renamed to *NWBDataInterface* to avoid confusion and ease intuition (see above)
    * All *Interface* types in the original format had fixed names. The fixed names have been replaced by
      specification of corresponding default names. This change enables storage of
      multiple instances of the same analysis type in the same :ref:`ProcessingModule <sec-ProcessingModule>` by allowing users to
      customize the name of the data processing types, whereas in version 1.0.x only a single instance of
      each analysis could be stored in a *ProcessingModule* due to the requirement for fixed names.

Simplified organization of acquistion data
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

**Specific Changes:**

    * ``/acquistion`` may now store any primary data defined via an :ref:`NWBDataInterface <sec-NWBDataInterface>` type
      (not just TimeSeries).
    * ``/acquistion/timeseries`` and ``/acquistion/images`` have been removed
    * Created a new neurodata_type :ref:`Images <sec-Images>` for storing a collection of images to replace
      ``acquisition/images`` and provide a more general container for use elsewhere in NWB:N (i.e., this is not
      meant to replace :ref:`ImageSeries <sec-ImageSeries>`)

Simplified extension of subject metadata
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

**Specific Change:** Assigned ``neurodata_type`` to ``/general/subject`` to enable extension of the subject container
directly without having to extend ``NWBFile`` itself. (see https://github.com/NeurodataWithoutBorders/nwb-schema/issues/120
and https://github.com/NeurodataWithoutBorders/nwb-schema/pull/121 for details)


Keywords
^^^^^^^^

**Change:** Added keywords fields to ``/general``

**Reason:** Data archive and search tools often rely on user-defined keywords to facilitate discovery. This
enables users to specify keywords for a file. (see `PR620 (PyNWB) <https://github.com/NeurodataWithoutBorders/pynwb/pull/620>`_)

Source
^^^^^^

**Change:** Remove required attribute ``source`` from all neurodata_types

**Reason:** In NWB:N 1.0.x the attribute ``source`` was defined as a free text entry
intended for storage of provenance information. In practice, however, this
attribute was often either ignored, contained no useful information, and/or
was misused to encode custom metadata (that should have been defined via extensions).

**Specific Change:** Removed attribute ``source`` from the core base neurodata_types
which effects a large number of the types throughout the NWB:N schema. For further
details see `PR695 (PyNWB) <https://github.com/NeurodataWithoutBorders/pynwb/pull/695>`_)


Ancestry
^^^^^^^^

**Change:** Removed the explicit specification of ancestry as an attribute as part of the format specification

**Reason:** 1) avoid redundant information as the ancestry is encoded in the inheritance of types, 2) ease maintenance,
and 3) avoid possible inconsistencies between the ancestry attribute and the true ancestry (i.e., inheritance hierarchy)
as defined by the spec.

**Note** The new specification API as part of PyNWB/FORM makes the ancestry still easily accessible to users. As
the ancestry can be easily extracted from the spec, we currently do not write a separate ancestry attribute
but this could be easily added if needed.


Specification language changes
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

**Change:** Numerous changes have been made to the specification language itself in NWB:N 2.0. Most changes to
the specification language effect mainly how the format is specified, rather than the actual structure of the format.
The changes that have implications on the format itself are described next. For an overview and discussion of the
changes to the specification language see `specification language release notes <http://schema-language.readthedocs.io/en/latest/specification_language_release_notes.html#release-notes>`_.

Specification of dataset dimensions
"""""""""""""""""""""""""""""""""""

**Change:** Updated the specification of the dimensions of dataset

**Reason:** To simplify the specification of dimension of datasets and attribute

**Format Changes:**

    * The shape of various dataset is now specified explicitly for several datasets via the new ``shape`` key
    * The ``unit`` for values in a dataset are specified via an attribute on the dataset itself rather than via
      ``unit`` definitions in structs that are available only in the specification itself but not the format.
    * In some cases the length of a dimension was implicitly described by the length of structs describing the
      components of a dimension. This information is now explitily described in the ``shape`` of a dataset.

Added ``Link`` type
"""""""""""""""""""

**Change** Added new type for links

**Reason:**

    - Links are usually a different type than datasets on the storage backend (e.g., HDF5)
    - Make links more readily identifiable
    - Avoid special type specification in datasets

**Format Changes:** The format itself is not affected by this change aside from the fact that
datasets that were links are now explicitly declared as links.


Removed datasets defined via autogen
""""""""""""""""""""""""""""""""""""

**Change** Support for ``autogen`` has been removed from the specification language. After review
of all datasets that were produced via autogen it was decided that all autogen datasets should be
removed from the format.

**Reason** The main reasons for removal of autogen dataset is to ease use and maintance of NWB:N files by
i) avoiding redundant storage of information (i.e., improve normalization of data) and ii) avoiding
dependencies between data (i.e., datasets havging to be updated due to changes in other locations in a file).

**Format Changes**

* Datasets/Attributes that have been removed due to redundant storage of the path of links stored in the same group:

    * IndexSeries/indexed_timeseries_path
    * RoiResponseSeries/segmentation_interface_path
    * ImageMaskSeries/masked_imageseries_path
    * ClusterWaveforms/clustering_interface_path
    * EventDetection/source_electricalseries_path
    * MotionCorrection/image_stack_name/original_path
    * NWBFile/epochs/epoch_X.links

* Datasets//Attributes that have been removed because they stored only a list of groups/datasets (of a given type or property)
  in the current group.

    * Module.interfaces  (now ProcessingModule)
    * ImageSegmentation/image_plane/roi_list
    * UnitTimes/unit_list
    * TimeSeries.extern_fields
    * TimeSeries.data_link
    * TimeSeries.timestamp_link
    * TimeSeries.missing_fields


* Other datasets/attributes that have been removed to ease use and maintance because the data stored is redundant and can be
  easily extracted from the file:

    * NWBFile/epochs.tags
    * TimeSeries/num_samples
    * Clustering/cluster_nums


Removed ``'neurodata\_type=Custom'``
""""""""""""""""""""""""""""""""""""

**Change** The ``'neurodata\_type=Custom'`` has been removed.

**Reason** All additions of data should be governed by extensions. Custom datasets can be identified based on
the specification, i.e., any objects that are not part of the specification are custom.




1.0.6, April 8, 2017
--------------------
Minor fixes:

    * Modify <IntervalSeries>/ documentation to use html entities for < and >.
    * Fix indentation of unit attribute data_type, and conversion attribute description in
      ``/general/optophysiology/<imaging_plane_X>/manifold``.
    * Fix typos in ``<AnnotationSeries>/`` conversion, resolution and unit attributes.
    * Update documentation for ``IndexSeries`` to reflect more general usage.
    * Change to all numerical version number to remove warning message when installing using setuptools.

1.0.5i_beta, Dec 6, 2016
------------------------
Removed some comments. Modify author string in info section.

1.0.5h_beta, Nov 30, 2016
-------------------------
Add dimensions to ``/acquisition/images/<image_X>``


1.0.5g\_beta, Oct 7, 2016
-------------------------

-  Replace group options: ``autogen: {"type": "create"}`` and ``"closed": True``
   with ``"\_properties": {"create": True}`` and ``"\_properties": {"closed": True}``.
   This was done to make the specification language more consistent by
   having these group properties specified in one place (``"\_properties"``
   dictionary).


1.0.5f\_beta, Oct 3, 2016
-------------------------

-  Minor fixes to allow validation of schema using json-schema specification
   in file ``meta-schema.py`` using utility ``check\_schema.py``.


1.0.5e\_beta, Sept 22, 2016
---------------------------

-  Moved definition of ``<Module>/`` out of ``/processing`` group to allow creating subclasses of Module.
   This is useful for making custom Module types that specified required interfaces. Example of this
   is in ``python-api/examples/create\_scripts/module-e.py`` and the extension it uses (``extensions/e-module.py``).
-  Fixed malformed html in ``nwb\_core.py`` documentation.
-  Changed html generated by ``doc\_tools.py`` to html5 and fixed so passes validation at https://validator.w3.org.

1.0.5d\_beta, Sept 6, 2016
--------------------------

- Changed ImageSeries img\_mask dimensions to: ``"dimensions": ["num\_y","num\_x"]`` to match description.

1.0.5c\_beta, Aug 17, 2016
--------------------------

- Change IndexSeries to allow linking to any form of TimeSeries, not just an ``ImageSeries``


1.0.5b\_beta, Aug 16, 2016
--------------------------

-  Make ``'manifold'`` and ``'reference\_frame'`` (under
   ``/general/optophysiology``) recommended rather than required.
-  In all cases, allow subclasses of a TimeSeries to fulfill validation
   requirements when an instance of TimeSeries is required.
-  Change unit attributes in ``VoltageClampSeries`` series datasets from
   required to recommended.
-  Remove ``'const'=True`` from ``TimeSeries`` attributes in ``AnnotationSeries``
   and ``IntervalSeries``.
-  Allow the base ``TimeSeries`` class to store multi-dimensional arrays in
   ``'data'``. A user is expected to describe the contents of 'data' in the
   comments and/or description fields.


1.0.5a\_beta, Aug 10, 2016
--------------------------

Expand class of Ids allowed in ``TimeSeries`` ``missing\_fields`` attribute to
allow custom uses.


1.0.5\_beta Aug 2016
--------------------

-  Allow subclasses to be used for merges instead of base class
   (specified by ``'merge+'`` in format specification file).
-  Use ``'neurodata\_type=Custom'`` to flag additions that are not describe
   by a schema.
-  Exclude TimeSeries timestamps and starting time from under
   ``/stimulus/templates``


1.0.4\_beta June 2016
---------------------

- Generate documentation directly from format specification file."
- Change ImageSeries ``external\_file`` to an array.
- Made TimeSeries description and comments recommended.

1.0.3 April, 2016
-----------------

- Renamed ``"ISI\_Retinotopy"`` to ``"ISIRetinotopy"``
- Change ``ImageSeries`` ``external\_file`` to an array. Added attribute ``starting\_frame``.
- Added ``IZeroClampSeries``.


1.0.2 February, 2016
--------------------

-  Fixed documentation error, updating ``'neurodata\_version'`` to ``'nwb\_version'``
-  Created ``ISI\_Retinotopy`` interface
-  In ``ImageSegmentation`` module, moved ``pix\_mask::weight`` attribute to be its
   own dataset, named ``pix\_mask\_weight``. Attribute proved inadequate for
   storing sufficiently large array data for some segments
-  Moved ``'gain'`` field from ``Current/VoltageClampSeries`` to parent
   ``PatchClampSeries``, due need of stimuli to sometimes store gain
-  Added Ken Harris to the Acknowledgements section


1.0.1 October 7th, 2015
-----------------------

-  Added ``'required'`` field to tables in the documentation, to indicate if
   ``group/dataset/attribute`` is required, standard or optional
-  Obsoleted ``'file\_create\_date'`` attribute ``'modification\_time'`` and made ``file\_create\_date`` a text array
-  Removed ``'resistance\_compensation'`` from ``CurrentClampSeries`` due being duplicate of another field
-  Upgraded ``TwoPhotonSeries::imaging\_plane`` to be a required value
-  Removed ``'tags'`` attribute to group 'epochs' as it was fully redundant with the ``'epoch/tags'`` dataset
-  Added text to the documentation stating that specified sizes for integer
   values are recommended sizes, while sizes for floats are minimum sizes
-  Added text to the documentation stating that, if the
   ``TimeSeries::data::resolution`` attribute value is unknown then store a ``NaN``
-  Declaring the following groups as required (this was implicit before)

.. code-block:: python

    acquisition/

    \_ images/

    \_ timeseries/

    analysis/

    epochs/

    general/

    processing/

    stimulus/

    \_ presentation/

    \_ templates/


This is to ensure consistency between ``.nwb`` files, to provide a minimum
expected structure, and to avoid confusion by having someone expect time
series to be in places they're not. I.e., if ``'acquisition/timeseries'`` is
not present, someone might reasonably expect that acquisition time
series might reside in ``'acquisition/'``. It is also a subtle reminder
about what the file is designed to store, a sort of built-in
documentation. Subfolders in ``'general/'`` are only to be included as
needed. Scanning ``'general/'`` should provide the user a quick idea what
the experiment is about, so only domain-relevant subfolders should be
present (e.g., ``'optogenetics'`` and ``'optophysiology'``). There should always
be a ``'general/devices'``, but it doesn't seem worth making it mandatory
without making all subfolders mandatory here.


1.0.0 September 28\ :sup:`th`, 2015
-----------------------------------

- Convert document to .html
- ``TwoPhotonSeries::imaging\_plane`` was upgraded to mandatory to help
  enforce inclusion of important metadata in the file.

