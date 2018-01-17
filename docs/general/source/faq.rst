**************************
Frequently Asked Questions
**************************

I would like to use NWB:N. How do I get started?
------------------------------------------------


What is the difference between pynwb, nwb-schema and api-python?
----------------------------------------------------------------

``PyNWB`` is the current Python reference read/write API for the NWB:N 2.x format.
The ``nwb-schema`` repo is used to manage development on the format schema. End-users
who want to use NWB:N typically do not need to worry about the ``nwb-schema`` repo
as the current schema is always installed with the correspondign API (whether it
is PyNWB for Python or MatNWB for Matlab). ``api-python`` is a deprecated write-only
API designed for NWB:N 1.0.x files.

How do I install PyNWB?
-----------------------

See the PyNWB documentation for details here `http://pynwb.readthedocs.io/en/latest/getting_started.html#installation <http://pynwb.readthedocs.io/en/latest/getting_started.html#installation>`_

How do I contribute to PyNWB?
-----------------------------

For details on how to contribute to PyNWB see our `contribution guidelines <https://github.com/NeurodataWithoutBorders/pynwb/blob/dev/docs/CONTRIBUTING.rst>`_ .

Does pynwb support both python 2.7 and python >3.5?
---------------------------------------------------

Yes

Does it make sense to start using NWB:N 2.0 now, or is it more sensible to wait?
--------------------------------------------------------------------------------

Yes. A first public beta release of PyNWB (for Python 2.7.x and >3.5) and NWB 2.0 has been released in
November 2017 in conjunction with the Annual Society for Neuroscience Meeting (SfN). The intent of this beta
release is to enable early adopters to start exploring the new format and software. While development on NWB 2.0 has
been progressing rapidly, further changes to the APIs as well as the format are still planed between this beta
and the first full release of NWB 2.0. However, overall we expect that most of these changes will be small so that
the current API and format provide a good starting point for exploring and beginning adoption of the format.
The current development plan is available here: http://nwb-overview.readthedocs.io/en/latest/development_plan.html

