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

<a id="optional-decompiler-status"></a>

## Recommended decompiler status

**Native macOS arm64 end-to-end run passed on 2026-11-16:** macOS 26.2, Apple M4 Pro,
24 GiB physical RAM, Python 3.13.12, the pinned Steam target, Ghidra 12.2 and Temurin 25.0.1+8.
The verified install and its previously built native decompiler were reused. This was not a
bare-machine installation or a new download measurement.

Real `./sr --json --yes setup --decompiler --no-sources --no-sibling --no-self-test` took
**0.36 seconds** to reuse the tools and launch the worker. A fresh project import and complete
analysis took **526.5 seconds (8.8 minutes)** from that setup invocation, with **4.62 GiB** sampled
peak process-tree resident memory. The heap cap was **16 GiB**, with four analysis CPUs.
The earlier 8 GiB-cap attempt reported a JVM out-of-memory error; the helper now exits on OOM and refuses to
mark a pass ready if its current log contains an OOM diagnostic, even with a success exit/checkpoint.

Real `./sr --json decomp 0xef8900` on the already-matched public
`NiTimeController::ProcessClone` took **13.5 seconds**, with **0.44 GiB** sampled peak RSS.
`start 0xef8900 --practice --no-branch` then passed in **10.2 seconds**: private hint markers,
a direct-callee signature, byte/listing/decompiler pack files and unchanged tracked reconstruction
were checked locally. Only sanitized metrics and outcomes were returned; no raw export is published.
This validates the local hint workflow, not pseudo-C correctness or another comparator match.

Allocated disk measured with `du -sk`: **1,241,018,368 bytes (1.16 GiB)** for installed tools,
**684,421,120 bytes (0.64 GiB)** for the project including exports, and **1,958,977,536 bytes
(1.82 GiB)** for the complete decompiler directory, including runtime cache/settings. Archive cache
and the owner's executable are excluded; the pinned macOS arm64 archives total **706,001,130 bytes**.
The project was removed after measuring it; the verified tools were retained. Removing a project
means the next setup must analyze again. Temporary extraction, swap and other contributor tools
need additional space; this directory footprint is not a minimum free-disk guarantee.

Wall times include polling (one second for analysis, half a second for export/pack checks).
RSS was sampled across the worker's process tree every second, with the helper's own analysis
sampler at two seconds; export RSS used half-second samples. Sampling can miss spikes, and RSS
does not count nonresident memory or define how much free RAM another machine needs.
Native Windows and Linux decompiler runs remain **unverified**. Offline tests cover
archive hashes, installation reuse, platform/native-build selection, checkpoints, OOM rejection,
private pack layout and publication rejection; those tests do not establish another OS run.
