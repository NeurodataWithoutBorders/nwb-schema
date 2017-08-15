.. _sec-OptogeneticStimulusSite:

OptogeneticStimulusSite
^^^^^^^^^^^^^^^^^^^^^^^

**Extends:** :ref:`NWBContainer <sec-NWBContainer>`

**Source Specification:** see :numref:`sec-OptogeneticStimulusSite-src`

**Overview:** One of possibly many groups describing an optogenetic stimuluation site. 

**Comment:**  Name is arbitrary but should be meaningful. Name is referenced by OptogeneticSeries


``OptogeneticStimulusSite`` extends ``NWBContainer`` (see :numref:`sec-NWBContainer`) and includes all elements of :ref:`NWBContainer <sec-NWBContainer>` with the following additions or changes.



- **Quantity** 0 or more


.. figure:: ./_format_auto_docs/OptogeneticStimulusSite.*
    :alt: OptogeneticStimulusSite




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-OptogeneticStimulusSite-data:

.. table:: Datasets, Links, and Attributes contained in <OptogeneticStimulusSite>
    :class: longtable

    +-----------------------------+-------------+------------------------------------------------------------+
    | Id                          | Type        | Description                                                |
    +=============================+=============+============================================================+
    | <OptogeneticStimulusSite>   | group       | Top level group for <OptogeneticStimulusSite>              |
    +-----------------------------+-------------+------------------------------------------------------------+
    | .help                       | attribute   | Value is 'Metadata about an optogenetic stimulus site'     |
    |                             |             |                                                            |
    |                             |             | - **Data Type:** text                                      |
    |                             |             | - **Value:** Metadata about an optogenetic stimulus site   |
    |                             |             |                                                            |
    +-----------------------------+-------------+------------------------------------------------------------+
    | .description                | dataset     | Description of site                                        |
    |                             |             |                                                            |
    |                             |             | - **Data Type:** text                                      |
    |                             |             |                                                            |
    +-----------------------------+-------------+------------------------------------------------------------+
    | .device                     | dataset     | Name of device in /general/devices                         |
    |                             |             |                                                            |
    |                             |             | - **Data Type:** text                                      |
    |                             |             |                                                            |
    +-----------------------------+-------------+------------------------------------------------------------+
    | .excitation_lambda          | dataset     | Excitation wavelength                                      |
    |                             |             |                                                            |
    |                             |             | - **Data Type:** text                                      |
    |                             |             |                                                            |
    +-----------------------------+-------------+------------------------------------------------------------+
    | .location                   | dataset     | Location of stimulation site                               |
    |                             |             |                                                            |
    |                             |             | - **Data Type:** text                                      |
    |                             |             |                                                            |
    +-----------------------------+-------------+------------------------------------------------------------+



