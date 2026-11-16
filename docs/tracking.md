# Maintaining the project report

The public report is generated from `data/progress.json` at each push to `main` and manual
workflow dispatch. It needs no accounts, trackers, backend, third-party fonts or external APIs.
It links to GitHub issues for discussion. Edit the JSON and submit a reviewed commit to change
the displayed state; GitHub issue edits alone do not change it.

```sh
python3 tools/check.py
python3 tools/build_site.py
```

Open `dist/index.html`. `dist/progress.json` is the same validated public metadata. `dist/` is
ignored; GitHub Actions generates and deploys it. Only that generated directory is uploaded.
The commit shown on the site identifies the version used to generate the report. CI uses Python
3.13; local tools support Python 3.11+. No Python package installation is required.

Scope, trend charts and costs come from committed evidence and data. Human contribution credit
is Git authorship/co-authorship in accepted commits; model attribution is separate.
Unknown scope has no percentage. Issues provide the public work queue; local account scopes
and optional board setup belong in private operator configuration.
