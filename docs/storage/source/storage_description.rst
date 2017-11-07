.. _storage:

=============
NWB:N Storage
=============


What is the role of data storage?
=================================

The `NWB:N format specification <http://nwb-schema.readthedocs.io/en/latest/index.html>`_
defined using the `NWB:N specification language <http://schema-language.readthedocs.io/en/latest/index.html>`_
describes how to organize large collections of neuroscience data using
basic primitives, e.g., Files, Groups, Datasets, Attributes, and Links to describe and hierarchically group data.
The role of the data storage then is to store large collections of neuroscience data. In other words,
the role of the storage is to map NWB:N primitives (and types, i.e., neurodata_types) to persistent storage.
For an overview of the various components of the NWB:N project
see `here <http://nwb-overview.readthedocs.io/en/latest/nwbintro.html>`_ .

How are NWB:N files stored?
===========================

The NWB:N format currently uses HDF5 as primary storage mechanism. The mapping of
the NWB:N format to HDF5 files is described in more detail in :numref:`sec-hdf5`.

Are backends other than HDF5 supported?
=======================================

NWB:N currently only officially supports HDF5 as main storage backend. However, the PyNWB API has been
designed to enable the design of custom read/write backends for the API, enabling other storage backends
to be mapped to NWB:N.
