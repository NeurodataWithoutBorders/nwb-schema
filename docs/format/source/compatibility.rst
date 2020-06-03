API and Schema Compatibility
============================

There are separate, but related, notions of compatibility for the NWB schema (standard) and the official APIs.

Backward compatibility in the official APIs
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Both the PyNWB and MatNWB APIs implement backward compatibility for **reading and validating** NWB 2.x files. Both
APIs can read and validate any NWB file compliant with NWB schema 2.0 and later.

- Note: MatNWB reads NWB files based on the cached schema within the file. If an older schema was used to
  create the file and the schema was not cached, then additional steps [#f1]_ need to be taken to read the file.
- If PyNWB reads an NWB file with an older, cached version of the NWB schema and then modifies the file, the file
  will be written with the newer version of the schema. As a precaution, after writing the file, the file should
  be validated against the newer version of the schema to ensure compliance.
- If MatNWB reads an NWB file with an older, cached version of the NWB schema and then modifies the file, the file
  will still be compliant with the older, cached version. Updating the file to a newer version of the schema is
  not yet supported in MatNWB.

Most NWB users are concerns about backward compatibility in the APIs. A file written now with NWB schema 2.x
will be readable by all future versions of PyNWB and MatNWB.

Schema compatibility
^^^^^^^^^^^^^^^^^^^^

An NWB file compliant with NWB schema ``x.y`` is generally compliant with later minor versions of the NWB
schema ``x.(y+1)``. Later minor ``x.(y+1)`` versions of the NWB schema may add new data types, add new
optional fields, and make required fields optional.

- For example, a new optional data type may be introduced in NWB 2.1 that is not present in NWB 2.0.
  Because the new data type is optional, the NWB 2.0 file is still compliant with the NWB 2.1 schema.

Later minor ``x.(y+1)`` and bugfix ``x.y.(z+1)`` versions of the NWB schema will avoid adding new required
fields. Changes that break this rule will generally not be implemented until the next major ``(x+1).0``
version of NWB. Rare exceptions to this rule are noted in the NWB schema version release notes.

- For example, the shape of a dataset changed from a scalar in NWB 2.0 to a 1-D array in NWB 2.1. Thus the NWB
  2.0 file where the dataset is a scalar is not automatically compliant with the NWB 2.1 schema or later
  versions. Validators are encouraged to encode this exception.

Later versions of the NWB schema may fix bugs present in older versions of the schema. These are
generally released in a bugfix ``x.y.(z+1)`` version, but may be released in a minor ``x.(y+1)`` or major
``(x+1).0.0`` version.

- For example, a new dataset data type may be added in NWB 2.2.0 and found to have specified its shape
  incorrectly. This may be fixed in NWB 2.2.1. In this case, an NWB 2.2.0 file that includes the dataset
  with the wrong shape will not be compliant with NWB 2.2.1 or later versions.

An NWB file compliant with NWB schema ``x.y`` is not necessarily compliant with an earlier version of the
NWB schema ``x.(y-1)``.

- For example, a field that is required in NWB 2.0 may become optional in NWB 2.1. So, an NWB 2.1 file
  may be missing that field, which would make it not compliant with the NWB 2.0 schema.

See the `NWB versioning guidelines`_ for details on the semantic versioning scheme that NWB uses.

.. _`NWB versioning guidelines`: https://nwb-extensions.github.io/versioning_guidelines

.. rubric:: Footnotes

.. [#f1] Some older NWB files do not have the schema cached within the file. To read these files in MatNWB, you must
   do the following:

   1. Identify the older version of the schema used to write the file
   2. Download the older version of the schema from the `nwb-schema GitHub releases page`_
   3. Copy the .yaml files from the downloaded schema into ``matnwb/nwb-schema/core/``
   4. Run ``generateCore()`` to generate API classes based on the older version of the schema.

.. _`nwb-schema GitHub releases page`: https://github.com/NeurodataWithoutBorders/nwb-schema/releases
