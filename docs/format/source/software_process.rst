The "dev" Branch and Releases
=============================

The default branch is "dev". The "dev" branch will hold the bleeding edge version of the NWB format specification,
language specification, and storage specification. PRs should be made to "dev". Every PR should include an update to
the corresponding format/language/storage release notes. If the PR involves a change to the NWB format, the PR should
also update the version of the format in three places: `/docs/format/conf.py`, `/core/nwb.namespace.yaml` and
`/core/nwb.file.yaml`. The new version string should be the next bugfix/minor/major version of the format with the
suffix "-alpha". For example, if the format is currently in version "2.2.0" and the format is then updated with a bug
fix, then the PR for that bug fix should update the format version to "2.2.1-alpha". Appending the "-alpha" tag
ensures that any person or API accessing the default dev branch of the repo containing an unreleased version of the
schema receives the schema with a version string that is distinct from the released versions of the schema.

Before merging a PR on nwb-schema, developers should take care to test their changes locally with the latest version
of PyNWB and MatNWB to ensure compatibility. If the APIs require changes to work with the PR, those changes should be
implemented and tested locally before merging the PR to ensure that the API changes can be implemented and no further
changes to the schema are required.

When a new release is ready, the branches of the APIs, PyNWB and MatNWB, that track nwb-schema should be checked to
ensure that when the new release is made, the branches in the APIs can be merged without issue.

Immediately prior to a new release, the version of the format should be updated to remove the "-alpha" suffix and the
documentation and release notes should be checked and updated (see release process documents).

It is important that all releases of nwb-schema contain a released version of hdmf-common-schema. If a release
contains an unreleased version of hdmf-common-schema, e.g., from an untagged commit on the "dev" branch, then tracking
the identity of the included hdmf-common-schema becomes difficult and the same version string could point to two
different versions of the schema.
