Extending the format
====================

The data organization presented in this document constitutes the *core*
NWB format. Extensibility is handled by allowing users to store
additional data as necessary using new datasets, attributes or groups.
There are two ways to document these additions. The first is to add an
attribute "neurodata\_type" with value the string "Custom" to the
additional groups or datasets, and provide documentation to describe the
extra data if it is not clear from the context what the data represent.
This method is simple but does not include a consistant way to describe
the additions. The second method is to write an *extension* to the
format. With this method, the additions are describe by the extension
and attribute "schema\_id" is set to the schema\_id associated with the
extension. Extensions to the format are written using the same
specification language that is used to define the core format. Creating
an extension allows adding the new data to the file through the API,
validating files containing extra data, and also generating
documentation for the additions. Popular extensions can be proposed and
added to the official format specification. Writing and using extensions
are described in the API documentation. Both methods allow extensibility
without breaking backward compatibility.

