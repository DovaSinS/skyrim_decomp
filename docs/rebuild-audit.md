# Accepted-unit rebuild audit

`tools/rebuild_audit.py` rebuilds every `matched` entry in `data/progress.json` from a clean,
pinned `origin/main` checkout, using its recorded recipe, symbol map and compiler pins. It
copies the comparator and `unit_build.py` unchanged from that checkout. The compiler sees the
current include closure, with the existing cleared environment and `/showIncludes` checks.
Every function is compared against the pinned target on each host. No acceptance record,
family status or progress entry is changed.

This catches accepted units broken by later shared-header or include changes. It does not
link all units into one executable, detect every cross-unit ODR conflict, or establish game
playability. A clean audit is a current per-unit reproduction claim only.

## Run and resume

From the repository root, create a clean checkout under `.local/` using git, fetch
`origin/main`, and detach at its full SHA. Keep that checkout unchanged. Prepare an export:

```sh
python3.13 tools/rebuild_audit.py prepare --repo .local/audit/checkout \
  --revision <full-origin-main-sha> --out .local/audit/export
```

Historical symbol maps are rebuilt byte-for-byte from the tracked current map and its history,
using the existing gate helper and requiring the exact recorded SHA-256. They are exported under
private task-map names; no symbol-map entry is invented or changed.

The export contains needed tracked inputs and those proven map versions, their hashes, all matched functions, recorded
internal symbol selectors, and an independent copy of the audit driver. It omits old objects,
old passes, compiler packages and game files. Transfer it once to each trusted runner under a
private `.local/` directory. Use the existing private runner configuration for host locations,
compiler, image, Wine environment and Python executable. Do not transfer the game through the
export. Each host uses its own already installed image and toolchain.

On each runner itself, from its scratch root (all paths below are placeholders):

```sh
<python> .local/audit/export/rebuild_audit.py run --export .local/audit/export \
  --out .local/audit/results/<host-id> --host <host-id> --loader <wine-or-native> \
  --msvc <installed-toolchain> --image <local-target> --jobs <parallelism>
```

Use each host's privately configured compiler environment and parallelism.
The native worker requires Python 3.11+ and the standard library only; Python 3.12 is supported.
Start the worker detached on its own host so closing an SSH session does not interrupt it.
`--limit N` runs a pilot of N additional units; the summary explicitly retains the pending count.

Resume with exactly the same export, host, toolchain, image and output directory. An OS lock
prevents two writers. A journal without its bound identity is refused. Each completed unit is flushed and fsynced to `results.jsonl`; an incomplete
final journal append is discarded and that unit rerun. A failed unit is completed evidence,
not silently retried on resume; use a new output directory for a deliberate fresh audit.
Every restart verifies the exported inputs, target and compiler hashes and binds the journal
to the snapshot SHA, plan hash, driver hash, host and private installation locations.

`summary.json` is replaced atomically about every 15 seconds. Transient Windows reader sharing
violations are retried with a bounded delay. A persistent checkpoint failure cancels pending
work instead of draining the rest of the queue without saving results. It includes the snapshot SHA,
total, pass/fail/pending counts, elapsed active time, throughput, digest drift, code hash drift
and the failing RVAs with closed reason codes. Exit 0 means every selected accepted function
passed with none pending; 1 means failures; 2 means incomplete or an audit infrastructure error.
Raw compiler output and diagnostics remain in private scratch for failed units; successful
scratch is removed. Do not publish scratch or the private identity file.

## Interpret failures

The four cause buckets are `header-drift`, `recipe-or-compiler-mismatch`, `missing-file`, and
`other`. `header-drift` is a **candidate cause**: the accepted TU digest changed and the
recompile/comparison failed. Check the private diagnostics and git history before calling it
a confirmed header regression or attributing an introducing commit. A changed digest that
still passes the comparator is reported as drift, not a failure. A changed code-section hash
is also an observation separate from the comparator result. Record the exact reason when the
unchanged comparator refuses an internal identity or symbol map before comparing code.
A host-wide target/compiler/export mismatch aborts the audit; it is not thousands of proven
function failures. Report such a blocked host separately from completed per-function results.

Join both hosts by build id and RVA. For every common failure, record its family, cause,
reproducing command and any confirmed introducing commit in the handoff. Propose either a
shared-header/recipe repair followed by a full rerun, or family-wide reassessment and revocation
under `docs/verification.md`. The maintainer decides; this tool never revokes anything.

## Regular execution proposal

An operator may schedule audits of the latest green `origin/main`, using a unique snapshot
directory and the runner environment and parallelism from private configuration. Resume an unfinished snapshot before starting another. Fetch summaries and journals;
retain private failure scratch, and report new failures and pending work. Audit results are
not new acceptances and must not rewrite historical comparator records.

For quicker detection, also run affected accepted units whenever a shared header, recipe,
compiler pin, include scanner or verifier changes. Derive reverse dependencies from every
accepted unit's **current** closure, including transitive headers; a deleted/moved header must
also consult recorded closures. Rebuild on both hosts before releasing that lane candidate.
Keep a periodic full sweep because dependency selection can itself be wrong. These are
proposals; p158 installs no scheduler and changes no acceptance or lane gate.
