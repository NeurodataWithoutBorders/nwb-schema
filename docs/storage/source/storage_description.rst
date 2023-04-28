.. _storage:

=============
NWB Storage
=============


What is the role of data storage?
=================================

The `NWB format specification <http://nwb-schema.readthedocs.io/en/latest/index.html>`_
defined using the `NWB specification language <http://schema-language.readthedocs.io/en/latest/index.html>`_
describes how to organize large collections of neuroscience data using
basic primitives, e.g., Files, Groups, Datasets, Attributes, and Links to describe and hierarchically group data.
The role of the data storage then is to store large collections of neuroscience data. In other words,
the role of the storage is to map NWB primitives (and types, i.e., neurodata_types) to persistent storage.
For an overview of the various components of the NWB project
see `here <https://neurodatawithoutborders.github.io/overview>`_ .

How are NWB files stored?
===========================

The NWB format currently uses HDF5 as primary storage mechanism. The mapping of
the NWB format to HDF5 files is described in more detail in :numref:`sec-hdf5`.

Are backends other than HDF5 supported?
=======================================

NWB currently only officially supports HDF5 as main storage backend. However, the PyNWB API has been
designed to enable the design of custom read/write backends for the API, enabling other storage backends
to be mapped to NWB.
