**Overview**

The NWB-N specification documentation uses Sphinx [http://www.sphinx-doc.org/en/stable/index.html](http://www.sphinx-doc.org/en/stable/index.html)

**Building the documentation**

To build the documentation simply:

```make <doctype>```

where ```<doctype>``` is, e.g., ```latexpdf```, ```html```, ```singlehtml``` or ```man```. For a complete list of supported doc-types see:

```make help```

**How is the format documentation generated**

The format documentation is auto-generated each time the documentation is built by invoking the script

```python source/format_autodocs/generate_format_docs.py```

The script automatically generates a series of .rst files that are stored in the folder ```source/format_autodocs```. The generated .rst files are included in ```source/format.rst```.


