Release Notes: NWB Specification Language
=========================================


Version 1.2a (April, 2017)
--------------------------

Summary
^^^^^^^
* Simplify reuse of neurodata_types:
    * Added new key: ```neurodata_type_def``` (which in compination with ```neurodata_type``` replaces the keys ```include``` and ```merge```)
    * Removed key: ```include```
    * Removed key: ``merge```
    * Removed key: ``merge+```
* Replace encoding of values in keys:
    * Added new key ```quantity``` (which replaces the ```quantity_flag```)
    * Removed ```quantity_flag``` as part of keys
    * Removed key ```structured_dimensions``` (see below for details)
    * Removed key ```autogen``` (without replacement)
    * Added ```name``` key
    * Removed `<...>` name identifier (replaced by empty ```name``` key)
    * Added ```groups``` key
    * Added ```datasets``` key
    * Removed `/` flag in keys to identify groups (replace by ```groups``` and ```datasets``` keys)
* Improve human readability:
    * Add support for YAML in addition to JSON

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
key ```neurodata_type_def``` which  describes the creation of a new ```neurodata_type```.
The combination ```neurodata_type_def``` and ```neurodata_type``
simplifies the concepts of merge (i.e., inheritance/extension) and inclusion and
allows us to express the same concepts in an easier-to-use fashion.
Accordingly, the keys ```include```, ```merge``` and ```merge+``` have been removed in version 1.2a.
Here a summary of the basic cases:

+----------------+--------------------+------------------------------------------------------------------------+
| neurodata_type | neurodata_type_def |  Description                                                           |
+================+====================+========================================================================+
|not set         | not set            |  define standard dataset or group without a type                       |
+----------------+--------------------+------------------------------------------------------------------------+
|not set         | set                |  create a new neurodata_type from scratch                              |
+----------------+--------------------+------------------------------------------------------------------------+
|set             | not set            |  include (reuse) neurodata_type without creating a new one (include)   |
+----------------+--------------------+------------------------------------------------------------------------+
|set             | set                |  merge/extend neurodata_type and create a new type (merge)             |
+----------------+--------------------+------------------------------------------------------------------------+

```structured_dimensions```
^^^^^^^^^^^^^^^^^^^^^^^^^^^

The definition of structured dimensions has been removed in version 1.2a. The ```unit``` defined as part of ```structured_dimensions``` in version 1.1c is now an attribute on the corresponding dataset in version 1.2a. The concept of structured_dimensions will likley be implemented in future version of the specification language via support for modeling of relationships or a special table neurodata_type.

```autogen```
^^^^^^^^^^^^^

The ```autogen``` key has been removed in 1.2a without replacement.


Version 1.1c (Oct. 7, 2016)
---------------------------

* Original version of the specification language generated as part of the NWB pilot project