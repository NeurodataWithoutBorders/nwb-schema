=============
Release Notes
=============


Version 1.2a (April, 2017)
--------------------------

Summary
^^^^^^^
* Simplify reuse of neurodata_types:
    * Added new key: ```neurodata_type_def and  ```neurodata_type_inc``` (which in combination replace the keys ```neurodata_type```, ```include``` and ```merge```). See below for details.
    * Removed key: ```include```
    * Removed key: ```merge```
    * Removed key: ```merge+```
    * Removed key: ```neurodata_type``` (replaced by ``neurodata_type_inc`` and ``neurodata_type_def``)
    * Removed ```\_properties``` key. The primary use of the key is to define ``abstract`` specifications. However, as format specifications don't implement functions but define a layout of objects, any spec (even if marked abstract) could still be instantiated and used in practice withou limitations. Also, in the curretn instantiation of NWB-N this concept is only used for the ```Interface``` type and it is unclear why a user shoudl not be able to use it.  As such this concept was removed.
    * To imporve compliance of NWB-N inheritance mechanism with establish object-oriented design concepts, the option of restricting the use of subclasses in place of parent classes was removed. A subclass is always also a valid instance of a parent class. This also improves consistentcy with the NWB-N principle of a minimal specification that allows users to add custom data. This change effects the ```allow_subclasses``` key of links and the subclasses option of the removed ```include`` key.
* Improve readability and avoid collision of keys by replacing values encoded in keys with dedicated key/value pairs:
    * Explicit encoding of names and types:
        * Added ```name``` key
        * Removed `<...>` name identifier (replaced by empty ```name``` key)
        * Added ```groups``` key  (previously groups were indicated by "/" as part of object's key)
        * Added ```datasets``` key (previously datasets were indicated by missing "/" as part of the object's key)
        * Added ```links``` key (previously this was a key on the group and dataset specification). The concept of links is with this now  a first-class type (rather than being part of the group and dataset specs).
        * Removed ``link`` key on datasets as this functionality is now fully implemented by the ``links`` key on groups.
        * Removed `/` flag in keys to identify groups (replaced by ```groups``` and ```datasets``` keys)
    * Explicit encoding of quantitites:
        * Added new key ```quantity``` (which replaces the ```quantity_flag```). See below for details.
        * Removed ```quantity_flag``` as part of keys
        * Removed `Exclude\_in`` key. The key is currently not used in the NWB core spec. This feature is superseded by the ability to overwrite the ```quantity``` key as part of the reuse of ```neurodata_types```
    * Removed ```\_description``` key. The key is no longer need because name conflicts with datasets and groups are no longer possible since the name is now explicitly encoded in a dedicated key/value pair.
* Improve human readability:
    * Added support for YAML in addition to JSON
    * Values, such as, names, types, quantities etc. are now explicitly encoded in dedicated key/value pairs rather than being encoded as regular expressions in keys.
* Improve direct interpretation of data:
    * Remove ```references``` key. This key was used in previous versions of NWB to generate implicit data structures where datasets store references to part of other metadata structures. These implicit data structures violate core NWB principles as they hinder the direct interpretation of data and cannot be interpreted (neither by human nor program) based on NWB files alone without having additional informaton about the specification as well. Through simple reorganization of metadata in the file, all instances of these implicit data structures were replaced by simple links that can be interpreted directly.
* Simplified specification of dimensions for datasets:
    * Rendamed ```dimensions``` key to ```dims```
    * Added key ```shape``` to allow the specification of the shape of datasets
    * Removed custom keys for defining structures as types for dimensions:
        * ```unit``` keys from previous structured dimensions are now ```unit``` attributes on the datasets (i.e., all values in a dataset have the same units)
        * The length of the structs are used to define the lenght of the corresponding dimension as part of the ```shape``` key
        * ```alias``` for components of dimensiosn are currently encoded in the dimensions name.
* Improved governance and reuse of specifications:
    * The core specification documents are no longer stored as .py files as part of the orignal Python API but are released as separate YAML (or optionally JSON) documents in a seperate repository
    * All documentation has been ported to use reStructuredText (RST) markup that can be easily translated to PDF, HTML, text, and many other forms.
    * Documentation for source codes and the specification are auto-generated from source to ensure consistency between sources and the documentation
* Others:
    * Removed key ```autogen``` (without replacement). The autogen key was used to describe how to compute certain derived datasets from the file. This feature was problematic with respect to the guiding principles of NWB for a couple of reasons. E.g., the resulting datasets where often not interprepatable without the provenance of the autogeneration procedure and autogeneration itself and often described the generation of derived data structures to ease follow-on computations. Describing computations as part of a format specification is problematic as it creates strong dependencies and often unnecessary restrictions for use and analysis of data stored in the format. Also, the reorganization of metadata has eliminted the need for autogen in many cases. A autogen features is arguably the role of a data API or intermediary derived-quantity API (or specification), rather than a format specification.
    * Removed key ```\_\_custom``` (without replacement). This feature was used only in one location to provide user hints where custom data could be placed, however, since the NWB specification approach explicitly allows users to add custom data in any location, this information was not binding.


Currently unsupported features that will be added in 1.2.1a
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* ```_required``` : The current API does not yet support specification and verification of
* Relationships are currently available only through implicit concepts, i.e., by sharing dimension names and through implicite references as part of datasets. The goal is to provide explicit mechanisms for describing these as well as more advanced relationships.
* ```dimensions_specification```: This will be implmented in later version likely through the use of relationships.


YAML support
^^^^^^^^^^^^

To improve human readability of the specification language, Version 1.2a now allows specifications to be defined in YAML as well as JSON (Version 1.1c allowed only JSON).

```quantity```
^^^^^^^^^^^^^^


Version 1.1c of the specification language used a ```quantity_flag``` as part of the name key of groups and datasets to the quantity

* `!` – Required (this is the default)
* `?`– Optional
* `^` – Recommended
* `+` - One or more instances of variable-named identifier required
* `*` - Zero or more instances of variable-named identifier allowed

Version 1.2a replaces the ```quantity_flag``` with a new key ```quantity``` with the following values:

+---------------------------------+------------+-------------------------------------------------------+
| value                           |  required  |  number of instances                                  |
+=================================+============+=======================================================+
|  ```zero_or_more``` or ```*```  |  optional  |   unlimited                                           |
+---------------------------------+------------+-------------------------------------------------------+
|  ```one_or_more``` or ```+```   |  required  |   unlimited but at least 1                            |
+---------------------------------+------------+-------------------------------------------------------+
|  ```zero_or_one``` or ```?```   |  optional  |   0 or 1                                              |
+---------------------------------+------------+-------------------------------------------------------+
|  ```1```, ```2```, ```3```, ... |  required  |   Fixed number of instances as indicated by the value |
+---------------------------------+------------+-------------------------------------------------------+


```merge``` and ```include```
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

To simplify the concept ```include``` and ```merge```, version 1.2a introduced a new
key ```neurodata_type_def``` which  describes the creation of a new neurodata_type.
The combination ```neurodata_type_def``` and ```neurodata_type_inc``
simplifies the concepts of merge (i.e., inheritance/extension) and inclusion and
allows us to express the same concepts in an easier-to-use fashion.
Accordingly, the keys ```include```, ```merge``` and ```merge+``` have been removed in version 1.2a.
Here a summary of the basic cases:

+--------------------+--------------------+------------------------------------------------------------------------+
| neurodata_type_inc | neurodata_type_def |  Description                                                           |
+====================+====================+========================================================================+
|not set             | not set            |  define standard dataset or group without a type                       |
+--------------------+--------------------+------------------------------------------------------------------------+
|not set             | set                |  create a new neurodata_type from scratch                              |
+--------------------+--------------------+------------------------------------------------------------------------+
|set                 | not set            |  include (reuse) neurodata_type without creating a new one (include)   |
+--------------------+--------------------+------------------------------------------------------------------------+
|set                 | set                |  merge/extend neurodata_type and create a new type (merge)             |
+--------------------+--------------------+------------------------------------------------------------------------+

```structured_dimensions```
^^^^^^^^^^^^^^^^^^^^^^^^^^^

The definition of structured dimensions has been removed in version 1.2a. The concept of structs as dimensions is
problematic for several reasons: 1) it implies support for defining general tables with mixed units and data types
which are currently not supported, 2) they easily allow for colliding specification where mixed units are assigned
to the same value, 3) they are hard to use and unsupported by HDF5. Currently structured dimensions, however, have
been used only to encode information about "columns" of a dataset (e.g., to indicate that a dimension stores x,y,z
values). This information was translated to the ``dims``` and ```shape``` keys and ```unit``` attributes.
The more general concept of structured dimensions will be implemented in futrue versions of the specification language
and format likely via support for modeling of relationships or support for table data structures (stay tuned)

```autogen```
^^^^^^^^^^^^^

The ```autogen``` key has been removed in 1.2a without replacement.


Version 1.1c (Oct. 7, 2016)
---------------------------

* Original version of the specification language generated as part of the NWB pilot project