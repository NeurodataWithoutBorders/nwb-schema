## Summary of changes

- ...

## Checklist

For all schema changes:
- [ ] Add release notes for the PR to `docs/format/source/format_release_notes.rst`.

If this is the first schema change after a schema release (i.e., the version string in `core/nwb.namespace.yaml` does not
end in "-alpha"), then:
- [ ] Update the version string in `core/nwb.namespace.yaml` and `core/nwb.file.yaml` to the next major/minor/patch
  version with the suffix "-alpha". For example, if the current version is 2.4.0 and this is a minor change, then the
  new version string should be "2.5.0-alpha".
- [ ] Update the value of the `version` variable in `docs/format/source/conf.py` to the next version **without** the
  suffix "-alpha", e.g., "2.5.0".
- [ ] Update the value of the `release` variable in `docs/format/source/conf.py` to the next version **with** the suffix
  "-alpha", e.g., "2.5.0-alpha".
- [ ] Add a new section in the release notes `docs/format/source/format_release_notes.rst` for the new version
  with the date "Upcoming" in parentheses.

<!-- See https://nwb-schema.readthedocs.io/en/latest/software_process.html for more details. -->
