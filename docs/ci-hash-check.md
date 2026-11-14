# Advisory MSVC hash checks for contributor pull requests

Task p124, 2026-11-14. Engineer: gpt-6.1-sol; human owner: awarebayes. Exposure: public
reconstruction source and sanitized accepted records only; no private game input was used to
implement this prototype. Build identity is the pinned `sse-steam-1-7-104` manifest in
`builds/target.json`. This document is a tooling design, not a behavior or clean-room claim.

## Phase 1: prove the compiler with existing public records

Dispatch `.github/workflows/ci-hash-check.yml` on main. The `windows-2022` job asks the runner's
Visual Studio installer to add `Microsoft.VisualStudio.Component.VC.v141.x86.x64` and the pinned
SDK headers. `tools/ci_msvc_install.ps1` records installation wall time. `tools/ci_hash_check.py
probe` prints the compiler version, size and SHA-256, plus the hashes and sizes of `c1xx.dll`,
`c2.dll` and `link.exe`. `MATCH` requires x64 version 19.16.27054 and every hash in
`tools/verifier/pinned.sha256`; a v141 label alone proves nothing.

If the installed component differs or the self-test fails, the job tries Microsoft's evergreen
VS2017 Build Tools bootstrapper at `https://aka.ms/vs/15/release/vs_buildtools.exe`. It checks
the bootstrapper's Microsoft Authenticode signature and supplies the existing fixed 15.9.85
catalog URL and SHA-256 from `tools/verifier/setup_boat_machine.sh` through
`--installCatalogUri`. It probes the resulting binaries against exactly the same pins. This
tests an official exact-version source without assuming that the evergreen installer or a
toolset directory name will yield the pin. Failure or mismatch remains visible; no pin changes.

The public self-test compiles three separate units twice, with the flags read from the accepted
record's recipe, the verifier's cleared environment and include-closure checks, and a 180-second
compile timeout. It compares these functions with their existing public records:

- `NiTimeController::ProcessClone`, RVA `0xef8900`, 53 bytes, the contributor setup self-test.
- `NiAVObject::GetCollisionObject` (const), RVA `0x405a50`, 33 bytes.
- `TESForm::GetGoldValue`, RVA `0x1f3560`, 157 bytes.

The expected values come from the accepted records, checked for source-digest, recipe and
cross-run agreement, rather than newly published target data. Extraction calls the unchanged
comparator's `find_function` and `check_relocation_layout`; hashing calls its
`code_section_sha256` directly. These three references have one code section and no funclet
sections. Phase 1 tests clean-compilation determinism on these units, not all C++ features.

**Existing hash semantics:** `code-section-sha256-v1` hashes section names, lengths, bytes and
relocation offset/type/target identity. It excludes object timestamps, symbol indices and debug
paths. It does not simply zero relocation fields. Phase 1 reproduces this existing public hash;
it does not pretend it is the future masked-target hash below. Neither comparison runs the
game comparator against a target image on CI.

Compiler packages, objects and raw compiler diagnostics stay in runner scratch and are never
uploaded as artifacts. No `actions/cache` toolset cache is enabled: `LEGAL.md` prohibits
distributing compiler packages through this project, and GitHub caches can be restored by fork
pull requests. An installation also has installer state outside the toolset directory, so
restoring that directory alone would not prove a valid installed component. Report the uncached
installation time from logs; cached time is **not measured**, not an invented speedup. Revisit
caching only with a distribution basis and a reproducible installation strategy.

## Phase 2: published target hashes (p128)

p128 implements the maintainer-authorized publication after p124's successful compiler pilot.
There is **no size threshold**. Tiny functions' SHA-256 hashes are brute-forceable: the maintainer
accepted this, saying "you are being too strict" and allowing all sizes; the full verbatim
statement is in `docs/authorizations.md`. This is a publication decision, not a legality claim.

`tools/target_hashes.py` runs only locally against the owner's SHA-256-checked pinned image.
It processes every `(build id, RVA, size)` in the current `data/progress.json` inventory, including
unmatched functions; this inventory is smaller than the full executable census. Install the
local extraction dependency `iced-x86==1.21.0` in an ignored environment. For example:

```sh
python3.13 tools/target_hashes.py --image <private-image> \
    --out data/target-hashes/sse-steam-1-7-104.json
```

The index manifest binds thirteen bounded JSON shards with SHA-256 and row counts, keeping every
file below the existing publication cap. It records the build, image hash, inventory snapshot hash, comparator and normalizer
source hashes, compiler-pin file hash and recipe hashes. Each row records RVA, size, extraction
method, `normalized_sha256` and `layout_sha256`; the build and normalization version are inherited
from the manifest. **No bytes, mask contents, reference destinations, listings or decompiler output
are published.** `layout_sha256` commits to the ordered field offsets, widths and relocation types;
only its digest is public. It prevents a candidate from erasing arbitrary instructions by adding
relocations. It does not reveal a mask or reconstruct any instruction bytes.

Normalization version `relocation-masked-sha256-v1` is ordinary, key-free **SHA-256 of the full
function buffer with each four-byte relocation field replaced by zeros**. Size remains an explicit
identity field. The candidate uses the unchanged comparator's `find_function` and
`check_relocation_layout`, including its supported types, widths, overlap and bounds checks.
Every unmasked byte, including internal branches and padding, stays exact. This hash is distinct
from the stronger `code-section-sha256-v1` in Phase 1: reference names, addends, unwind/EH data and
funclets are outside this advisory digest and remain the local comparator's job.

A linked PE does not retain the original COFF relocations. The local extractor infers RIP-relative
four-byte reference fields (including REL32 trailing-immediate variants), four-byte direct calls
(including self calls) and branches outside the function. Other internal branches stay unmasked. It never guesses address-like immediates.
This is labelled `linked-reference-inference`, **not a claim of recovered original relocations**.
ADDR32NB, SECREL, linker transformations and unusual instruction streams can require additional
local evidence. An optional private layout file can supply comparator-checked fields; it never
leaves `.local/`. Undecodable ranges receive an explicitly unmasked digest and
`unmasked-unsupported`; the CI checker always returns `no-target` for these. A different candidate
relocation layout also returns `no-target`, rather than passing under candidate-selected masking.
Hashes cover the recorded ranges; they do not independently validate inventory extents.

`data/target-hashes/determinism-sample.json` pins 50 accepted external, single-code-section
references, stratified across distinct accepted sizes. Local validation compiles each twice,
checks normalized object/target hash equality and layout agreement, and reproduces the unchanged
full comparator pass on each compile. Run `tools/target_hash_determinism.py --image <private-image> --msvc <private-msvc>
--work .local/<audit>` to reproduce locally with the recipe and the accepted record's comparator
engine (including runtime records). Raw inputs and masks stay in `.local/p128/`; measured
results and size range are in the p128 handoff. The push/dispatch Windows job separately compiles
these 50 public references twice against the same published target hashes. This exercises the
format across the accepted size range; it does not prove inferred masks for all unmatched code.
The manifest is regenerated deliberately on a maintainer machine when inventory extents,
normalization, comparator, pins or recipes change; CI never needs a game image.

## PR job and p123 integration

`.github/workflows/ci-target-hash.yml` runs on reconstruction pull requests. It uses a disposable
GitHub-hosted Windows runner, `contents: read`, no secrets, persisted checkout credentials, OIDC,
private inputs or object execution. The trusted checkout is the event's immutable **base SHA**.
Only its tools, recipes, inventory and target commitments run. The head SHA is fetched as git
objects; `prepare` reads bounded regular UTF-8 reconstruction blobs from the PR diff and overlays
them on a separate trusted source tree. It enforces the contributor path/deletion/file-size rules
and the same source lint; PR symlinks, tools, recipes, response files and build commands are refused.
It never checks out PR tools or imports PR Python. Header edits trigger affected units too.

Known RVA/symbol/recipe bindings come from base records. A new unit can request a public target
in its source header with `// CI hash: 0x<RVA> <COFF-symbol>`. This is only a request to compare:
it cannot change a target's size, committed layout, digest or fixed default v141 recipe. Unknown
or unsupported bindings remain `no-target`. The compiler runs through `contrib.compile_unit`
with fixed recipe flags, cleared environment, include-closure checks, exact /showIncludes
agreement and its timeout. All four compiler pins and the pinned SDK headers must match.

Results contain only public identities/digests and `hash-match`, `mismatch` or `no-target` per
function, with `acceptance: not-evaluated`. Compile failures are sanitized as `mismatch` with
`compile-failed`; no compiler output, bytes or diffs enter logs or artifacts. Mismatches fail the
advisory job, while absent coverage remains visibly `no-target`. No-target is never hash equality.
The compiler's parser still receives untrusted C++, bounded by compile and job timeouts on a
runner without private data. Compiler packages, objects and diagnostics stay in scratch.

The p123 adapter `tools/contrib_hash_signal.py:advisory_hash_signal` consumes GitHub check-run API
metadata, selects only the latest GitHub Actions `target-hashes` job for the exact PR head SHA,
and returns an explicitly advisory signal (absent/pending/success/failure/etc.). The sanitized
JSON summary also records trusted base, head and tool/manifest/pin digests for investigation.
A PR can edit its own workflow; an apparently successful check cannot authenticate itself.
The adapter never changes the acceptance decision, authorizes compilation locally, or suppresses
intake or verification. `tools/contrib_autopilot.py` records this signal in the exact-head revision
state on every intake attempt. API errors produce `unavailable`. A successful job can still
contain `no-target` rows and is not a claim of hash coverage. Contributor intake, full comparison
on **two independent local hosts**, independent
Reviewer approval and integrated-source checks remain mandatory for `matched`. GitHub CI is
neither an acceptance host nor a substitute for any acceptance rule.

## Compiler cache decision

p124 assessed the official-install path and left Actions toolset caching disabled: `LEGAL.md`
prohibits compiler-package distribution, and GitHub caches are accessible to fork PRs. That
assessment supplies no licence basis for sharing a cached install. p128 therefore leaves the
cache **off**. A toolset-directory restore also omits installer state. The measured p124 installer
invocation took **325.85 seconds without an Actions cache**; cached time is **not measured**.
No speedup is claimed. See the p128 handoff for its own uncached installation measurement.

## Sources and limits

Microsoft documents the [v141 component](https://learn.microsoft.com/en-us/visualstudio/install/workload-component-id-vs-build-tools?view=vs-2022)
and the [installer parameters](https://learn.microsoft.com/en-us/visualstudio/install/use-command-line-parameters-to-install-visual-studio),
including catalog selection. The existing pinned catalog is the exact-source candidate tested
here; the [VS2017 release history](https://learn.microsoft.com/en-us/visualstudio/releases/2017/vs2017-relnotes-history)
does not by itself prove binary identity. GitHub documents [cache visibility and scope](https://docs.github.com/en/actions/reference/workflows-and-actions/dependency-caching).
These are public documentation sources consulted on 2026-11-14; successful installation and
binary identity must be measured in the actual workflow run. The private handoff records the
pushed revision, run URL, observed results and remaining limits.
