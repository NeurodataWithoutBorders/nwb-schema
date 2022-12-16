Prepare for release of nwb-schema [version]
Target release date: [date]

### Before merging:
- [ ] Update requirements versions as needed
- [ ] Update legal file dates and information in `Legal.txt`, `license.txt`, `README.md`, `docs/format/source/conf.py`,
  and any other locations as needed
- [ ] Update `README.rst` as needed
- [ ] Update the version string in `docs/format/source/conf.py`, `core/nwb.namespace.yaml`, and `core/nwb.file.yaml`
  (remove "-alpha" suffix)
- [ ] Update `docs/format/source/conf.py` as needed
- [ ] Update release notes (set release date) in `docs/format/source/format_release_notes.rst` and any other docs as
  needed
- [ ] Test docs locally (`cd docs/format; make fulldoc`) where the nwb-schema submodule in the local version of PyNWB
  is fully up-to-date with the head of the dev branch.
- [ ] Push changes to this PR and make sure all PRs to be included in this release have been merged
- [ ] Check that the readthedocs build for this PR succeeds (see auto-triggered PR build):
  https://readthedocs.org/projects/nwb-schema/builds/

### After merging:
1. Create a new git tag. Pull the latest master branch locally, run `git tag [version] --sign`, copy and paste the
   release notes into the tag message, and run `git push --tags`.
2. On the [GitHub tags page](https://github.com/NeurodataWithoutBorders/nwb-schema/tags) page,
   click "..." -> "Create release" for the new tag on the right side of the page.
   Copy and paste the release notes into the release message, update the formatting if needed (reST to Markdown),
   and set the title to the version string.
3. Check that the readthedocs "latest" and "stable" builds run and succeed. Delete the readthedocs build for the
   merged PR. https://readthedocs.org/projects/nwb-schema/builds/
4. Update the nwb-schema submodule in the PyNWB branch corresponding to this schema version to point to the tagged
   commit.

See https://nwb-schema.readthedocs.io/en/latest/software_process.html for more details.
