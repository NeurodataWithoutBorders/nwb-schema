.. _sec-AnnotationSeries:

AnnotationSeries
^^^^^^^^^^^^^^^^

**Extends:** :ref:`TimeSeries <sec-TimeSeries>`

**Source Specification:** see :numref:`sec-AnnotationSeries-src`

**Overview:** Stores, eg, user annotations made during an experiment. The TimeSeries::data[] field stores a text array, and timestamps are stored for each annotation (ie, interval=1). This is largely an alias to a standard TimeSeries storing a text array but that is identifiable as storing annotations in a machine-readable way.


``AnnotationSeries`` extends ``TimeSeries`` (see :numref:`sec-TimeSeries`) and includes all elements of :ref:`TimeSeries <sec-TimeSeries>` with the following additions or changes.



.. figure:: ./_format_auto_docs/AnnotationSeries.*
    :alt: AnnotationSeries




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-AnnotationSeries-data:

.. table:: Datasets, Links, and Attributes contained in <AnnotationSeries>
    :class: longtable

    +----------------------+-------------+-------------------------------------------------------------+
    | Id                   | Type        | Description                                                 |
    +======================+=============+=============================================================+
    | <AnnotationSeries>   | group       | Top level group for <AnnotationSeries>                      |
    +----------------------+-------------+-------------------------------------------------------------+
    | .help                | attribute   | Value is 'Time-stamped annotations about an experiment'     |
    |                      |             |                                                             |
    |                      |             | - **Data Type:** text                                       |
    |                      |             | - **Value:** Time-stamped annotations about an experiment   |
    |                      |             |                                                             |
    +----------------------+-------------+-------------------------------------------------------------+
    | .data                | dataset     | Annotations made during an experiment.                      |
    |                      |             |                                                             |
    |                      |             | - **Data Type:** text                                       |
    |                      |             | - **Dimensions:** ['num_times']                             |
    |                      |             | - **Shape:** [None]                                         |
    |                      |             |                                                             |
    +----------------------+-------------+-------------------------------------------------------------+
    | ..conversion         | attribute   | Value is 'float('NaN')'                                     |
    |                      |             |                                                             |
    |                      |             | - **Data Type:** None                                       |
    |                      |             | - **Value:** NaN                                            |
    |                      |             |                                                             |
    +----------------------+-------------+-------------------------------------------------------------+
    | ..unit               | attribute   | Value is 'n/a'                                              |
    |                      |             |                                                             |
    |                      |             | - **Data Type:** None                                       |
    |                      |             | - **Value:** n/a                                            |
    |                      |             |                                                             |
    +----------------------+-------------+-------------------------------------------------------------+
    | ..resolution         | attribute   | Value is 'float('NaN')'                                     |
    |                      |             |                                                             |
    |                      |             | - **Data Type:** None                                       |
    |                      |             | - **Value:** NaN                                            |
    |                      |             |                                                             |
    +----------------------+-------------+-------------------------------------------------------------+



