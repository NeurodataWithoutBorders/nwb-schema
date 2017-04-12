Definitions
===========

**#TODO Add description of all definition needed to understand the format specification**


Link types
----------

In some instances, the specification refers to HDF5 links. When links
are made within the file, HDF5 soft-links (and not hard-links) should be
used. This is because soft-links distinguish between the link and the
target of the link, whereas hard-links cause multiple names (paths) to
be created for the target, and there is no way to determine which of
these names are preferable in a given situation. If the target of a soft
link is removed (or moved to another location in the HDF5 file)—both of
which can be done using the HDF5 API—then the soft link will "dangle,"
that is point to a target that no longer exists. For this reason, moving
or removing targets of soft links should be avoided unless the links are
updated to point to the new location.

