Making a Pull Request
=====================

Actions to take on each PR that modifies the schema and does not prepare the schema for a public release
(this is also in the `GitHub PR template`_):

If the current schema version on "dev" is a public release, then:

1. Update the version string in ``docs/format/source/conf.py`` and ``common/namespace.yaml`` to the next version with the
   suffix "-alpha"
2. Add a new section in the release notes for the new version with the date "Upcoming"

Always:

1. Add release notes for the PR to ``docs/format/source/format_release_notes.rst``

Documentation or internal changes to the repo (i.e., changes that do not affect the schema files)
do not need to be accompanied with a version bump or addition to the release notes.

.. _`GitHub PR template`: https://github.com/NeurodataWithoutBorders/nwb-schema/blob/dev/.github/PULL_REQUEST_TEMPLATE.md


Merging PRs and Making Releases
===============================

**Public release**: a tagged release of the schema. The version string MUST NOT have a suffix indicating a pre-release,
such as "-alpha". The current "dev" branch of PyNWB and all PyNWB releases MUST point to a public release of
nwb-schema. All schema that use nwb-schema as a submodule MUST also point only to public releases.

**Internal release**: a state of the schema "dev" branch where the version string ends with "-alpha".

The default branch of nwb-schema is "dev". **The "dev" branch holds the bleeding edge version of
the nwb-schema specification.**

PRs should be made to "dev". Every PR should include an update to ``docs/format/source/format_release_notes.rst``.
If the current version is a public release, then the PR should also update the version of the schema in two places:
``docs/format/source/conf.py`` and ``core/nwb.namespace.yaml``. The new version should be the next bugfix/minor/major version
of the schema with the suffix "-alpha". For example, if the current schema on "dev" has version "2.2.0",
then a PR implementing a bug fix should update the schema version from "2.2.0" to "2.2.1-alpha". Appending the "-alpha"
suffix ensures that any person or API accessing the default "dev" branch of the repo containing an internal release
of the schema receives the schema with a version string that is distinct from public releases of the schema. If the
current schema on "dev" is already an internal release, then the version string does not need to be updated unless
the PR requires an upgrade in the version (e.g., from bugfix to minor).

PyNWB should contain a branch and PR that tracks the "dev" branch of nwb-schema. Before
a public release of nwb-schema is made, this PyNWB branch should be checked to ensure that when the new release
is made, the branch can be merged without issue.

Immediately prior to making a new public release, the version of the schema should be updated to remove the "-alpha"
suffix and the documentation and release notes should be updated as needed (see next section).

The current "dev" branch of PyNWB and all PyNWB releases MUST always point to a public release of nwb-schema. If
a public release contains an internally released version of nwb-schema, e.g., from an untagged commit on the
"dev" branch, then it will be difficult to find the version (commit) of nwb-schema that was used to create
an NWB file when the schema is not cached.

Making a Release Checklist
==========================

Before merging:

1. Update requirements versions as needed
2. Update legal file dates and information in ``Legal.txt``, ``license.txt``, ``README.md``, ``docs/format/source/conf.py``,
   and any other locations as needed
3. Update ``README.rst`` as needed
4. Update the version string in ``docs/format/source/conf.py``, ``core/nwb.namespace.yaml``, and ``/core/nwb.file.yaml``
   (remove "-alpha" suffix)
5. Update ``docs/format/source/conf.py`` as needed
6. Update release notes (set release date) in ``docs/format/source/format_release_notes.rst`` and any other docs as needed
7. Test docs locally (``cd docs/format; make fulldoc``) where the nwb-schema submodule in the local version of PyNWB
   is fully up-to-date with the head of the dev branch.
8. Push changes to a new PR and make sure all PRs to be included in this release have been merged. Add
   ``?template=release.md`` to the PR URL to auto-populate the PR with this checklist.
9. Check that the readthedocs build for this PR succeeds (build latest to pull the new branch, then activate and
   build docs for new branch): https://readthedocs.org/projects/nwb-schema/builds/

After merging:

1. Create a new git tag. Pull the latest dev branch locally, run ``git tag [version] --sign``, copy and paste the
   release notes into the tag message, and run ``git push --tags``.
2. On the `GitHub tags`_ page, click "..." -> "Create release" for the new tag on the right side of the page.
   Copy and paste the release notes into the release message, update the formatting if needed (reST to Markdown),
   and set the title to the version string.
3. Check that the readthedocs "latest" and "stable" builds run and succeed. Delete the readthedocs build for the
   merged PR. https://readthedocs.org/projects/nwb-schema/builds/
4. Update the nwb-schema submodule in the PyNWB branch corresponding to this schema version to point to the tagged commit.

This checklist can also be found in the `GitHub release PR template`_.

The time between merging this PR and creating a new public release should be minimized.

.. _`GitHub tags`: https://github.com/NeurodataWithoutBorders/nwb-schema/tags
.. _`GitHub release PR template`: https://github.com/NeurodataWithoutBorders/nwb-schema/blob/dev/.github/PULL_REQUEST_TEMPLATE/release.md



The "dev" Branch and Releases
=============================

The default branch is "dev". The "dev" branch will hold the bleeding edge version of the NWB format specification,
language specification, and storage specification. PRs should be made to "dev". Every PR should include an update to
the corresponding format/language/storage release notes. If the PR involves a change to the NWB format, the PR should
also update the version of the format in three places: `/docs/format/conf.py`, `/core/nwb.namespace.yaml` and
`/core/nwb.file.yaml`. The new version string should be the next bugfix/minor/major version of the format with the
suffix "a" (for "alpha"). For example, if the format is currently in version "2.2.0" and the format is then updated /
released internally with a bug fix, then the PR for that bug fix should update the format version from "2.2.0" to
"2.2.1a". Appending the "a" suffix ensures that any person or API accessing the default dev branch of the repo
containing an internally released version of the schema receives the schema with a version string that is distinct from
the full public released versions of the schema.

Before merging a PR on nwb-schema, developers should take care to test their changes locally with the latest version
of PyNWB and MatNWB to ensure compatibility. If the APIs require changes to work with the PR, those changes should be
implemented and tested locally before merging the PR to ensure that the API changes can be implemented and no further
changes to the schema are required.

When a new public release is ready, the branches of the APIs, PyNWB and MatNWB, that track nwb-schema should be checked
to ensure that when the new release is made, the branches in the APIs can be merged without issue.

Immediately prior to a new public release, the version of the format should be updated to remove the any alphabetic,
suffixes, e.g., "a", "b", and "rc", and the documentation and release notes should be checked and updated (see release
process documents).

It is important that all public releases of nwb-schema contain a publicly released version of hdmf-common-schema. If a
public release contains an internally released version of hdmf-common-schema, e.g., from an untagged commit on the "dev"
branch, then tracking the identity of the included hdmf-common-schema becomes difficult and the same version string
could point to two different versions of the schema.

For the same reason, it is important that all public releases of the APIs, PyNWB and MatNWB, contain a publicly
released version of nwb-schema. Starting with nwb-schema version 2.2.0, the dev branch and all public releases of PyNWB
and MatNWB include only publicly released versions of nwb-schema. For more details, see the
[PyNWB software process documentation](https://pynwb.readthedocs.io/en/stable/software_process.html).

The [NWB Extensions Versioning Guidelines](https://nwb-extensions.github.io/versioning_guidelines) are used to guide
versioning of the NWB core schema, as well as extensions to NWB.
