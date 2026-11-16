# Tested contributor platforms and disk budget

This is the single platform-status record for the newcomer workflow. A local comparator pass
is not project acceptance. No live outsider claim-to-credited-merge completion is claimed.

| Actual platform | Cold setup | Warm setup / self-test | Local comparison | Live claim / submit |
| --- | --- | --- | --- | --- |
| macOS, Apple silicon | Fresh Wine/compiler/SDK/reference downloads and fresh HOME exercised on an existing OS; Rosetta and system dependencies already present | Pinned compiler self-test passed | A small unmatched function passed locally | Prefilled claim link and local submit dry-run exercised; no issue, fork PR or credited merge posted |
| Windows 11 x64 | Compiler download and package installation not exercised | Existing native compiler: doctor, setup/self-test passed | Practice comparison passed | Not exercised live |
| Linux x64 | Not exercised | Not exercised | Not exercised | Not exercised |
| Windows Arm, Linux Arm and other environments | Not established | Not established | Not established | Not established |

Evidence: the 2026-11-15 isolated-HOME contributor simulation used public revision
`132f71b7594ed931e7cb5e552a478852da13335e`, Python 3.13 and the pinned Steam target.
It used the contributor's own legal image locally, with owner-approved model exposure; only
sanitized outcomes are published. The existing OS supplied dependencies, so this is not a
bare-machine installation test. Earlier native Windows observations are described in
[the Windows verifier findings](windows-verifier-host.md). Neither synthetic platform tests
nor public hash CI establish an untested OS workflow.

The completed macOS clone, toolchain, Wine, reference sources and check/site artifacts occupied
about **5.1 GiB** in that simulation, excluding the game installation. Leave additional room for
downloads, temporary extraction and comparisons. **8 GiB initially free is a planning buffer,
not a measured minimum or guarantee.** A whole-game Steam installation needs separate space;
other platforms and tasks can require more. Private reproduction logs remain with the operator.
