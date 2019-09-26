=============
Release Notes
=============

NWB:N - v2.1.0
--------------
Added documentation for new NWB key 'object_id' (see also format release notes for NWB 2.1.0: https://nwb-schema.readthedocs.io/en/latest/format_release_notes.html#september-2019).

NWB:N - v2.0.1
--------------
Added missing documentation on how format specification are cached in HDF5.

NWB:N - v2.0.0
---------------

Created separate reStructuredText documentation (i.e., this document) discuss and govern
storage-related concerns. In particular this documents describes how primitives and keys
described via the specification language are mapped to storage, in particular HDF5.

NWB:N - v1.0.x and earlier
--------------------------

For version 1.0.x and earlier, there was no official separate document governing NWB:N storage concerns as
HDF5 was the only supported storage backend with implicit mapping between HDF5 types and NWB:N
language primitives.
