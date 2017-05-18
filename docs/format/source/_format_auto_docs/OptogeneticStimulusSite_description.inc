.. _sec-OptogeneticStimulusSite:

OptogeneticStimulusSite
^^^^^^^^^^^^^^^^^^^^^^^

**Source Specification:** see :numref:`sec-OptogeneticStimulusSite-src`

**Overview:** One of possibly many groups describing an optogenetic stimuluation site. 

**Comment:**  Name is arbitrary but should be meaningful. Name is referenced by OptogeneticSeries




- **Quantity** 0 or more


.. figure:: ./_format_auto_docs/OptogeneticStimulusSite.*
    :alt: OptogeneticStimulusSite




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-OptogeneticStimulusSite-data:

.. table:: Datasets, Links, and Attributes contained in <OptogeneticStimulusSite>
    :class: longtable

    +-----------------------------+-----------+-------------------------------------------------+
    | Id                          | Type      | Description                                     |
    +=============================+===========+=================================================+
    | <OptogeneticStimulusSite>   | group     | Top level group for <OptogeneticStimulusSite>   |
    +-----------------------------+-----------+-------------------------------------------------+
    | .device                     | dataset   | Name of device in /general/devices              |
    |                             |           |                                                 |
    |                             |           | - **Data Type:** text                           |
    |                             |           |                                                 |
    +-----------------------------+-----------+-------------------------------------------------+
    | .excitation_lambda          | dataset   | Excitation wavelength                           |
    |                             |           |                                                 |
    |                             |           | - **Data Type:** text                           |
    |                             |           |                                                 |
    +-----------------------------+-----------+-------------------------------------------------+
    | .description                | dataset   | Description of site                             |
    |                             |           |                                                 |
    |                             |           | - **Data Type:** text                           |
    |                             |           |                                                 |
    +-----------------------------+-----------+-------------------------------------------------+
    | .location                   | dataset   | Location of stimulation site                    |
    |                             |           |                                                 |
    |                             |           | - **Data Type:** text                           |
    |                             |           |                                                 |
    +-----------------------------+-----------+-------------------------------------------------+



