# Guide for a contributor's coding agent

One PR may carry any number of functions.

You are a coding agent helping an **external contributor** match one function of Skyrim Special
Edition. This file is all you need. Do not follow the internal orchestration or verifier-session
instructions in [the internal workflow](internal-agent-workflow.md) (including
`tools/verifier/attempt|confirm`): they are for the
project's own machines. Do not use the project's internal verifier hosts or its runner tools.
Everything below runs on the contributor's computer.

Drive one tool, `tools/contrib.py` (macOS/Linux: `./sr`, which finds a working Python 3.11+
on PATH or in common Homebrew, pyenv and uv locations and otherwise prints the install command;
Windows: `.\sr.cmd`, which finds Python 3.11+ or unpacks a pinned private copy), always with `--json`. Each call prints one JSON object with `ok`, `exit_code`, `error` and `next` (the one next action). Do what
`next` says. Exit codes: 0 ok, 1 a check failed, 2 usage, 3 compile failed, 4 unit or include
problem, 5 input missing, 6 claimed by someone else, 7 a person must decide, 8 offline.

## When to ask the person

For game setup, ask the person when the helper reports these decisions. Account, fork and
authentication steps can also require their action; do not claim they are already complete.

1. **The path to their `SkyrimSE.exe`**, when `setup` could not find it in a Steam library
   (exit 5, `game executable`).
2. **Microsoft's licence** for the Visual Studio 2017 Build Tools (exit 7 with a `licence` field).
   Show them the link. Pass `--accept-microsoft-license` only after they say they accept it. Never
   accept it yourself.

Before you read any pack, ask once: reading a listing or decompiler view made from their
own copy of the game sends parts of it to your AI provider. That is their decision and their
responsibility, under their provider's terms; the project grants no rights in the game. Continue only if they agree. Nothing
from a pack ever goes into the repository, a pull request, an issue or CI.

Their system may add questions of its own, which only they answer: on Apple silicon, Rosetta 2 has
its own Apple licence (if `setup` reports `rosetta`, they run `softwareupdate --install-rosetta`);
a package manager may want their password (`sudo`; the tool prints the command for them to run);
winget on Windows asks them to accept its package source terms (pass
`--accept-winget-source-agreements` only after they have). Package installs themselves need no
decision: pass `--yes`.

## The loop

```sh
./sr --json --yes go [--exe "<path>"] [--accept-microsoft-license] \
    [--profile cheap|full] --drafted-by "<person>, assisted by <your model id>"
```

**Profiles.** Read [the self-contained contributor card](contributor-card.md). `cheap` uses
3 no-improvement attempts and a hard cap of 6 comparisons; `full` uses 4 and 10. The helper
prints the current limit. The full profile may help a harder function, but neither changes
what counts as a pass. [The matching cookbook](matching-cookbook.md) is optional reference.

`go` = `setup` (idempotent; installs Wine and msitools off Windows, LLVM, the community headers,
the FNV decompilation and its index, the pinned MSVC 19.16.27054 toolset and SDK from Microsoft's
servers, then compiles and compares a function the project already matched as a self-test) +
`next` + `claim` + `start`. Run it again after any fix; finished steps are skipped. When you show
the person output to post publicly, add `--redact` (it replaces their checkout and home paths).
`setup` may also upgrade unrelated Homebrew packages as dependencies are installed.
Then:

1. Read the private pack named in the `packs` field: `bytes.txt` (offsets, bytes with relocated
   fields as `..`, and each call or data target with its public name) and `listing.txt`
   (disassembly, when LLVM is installed). These files never leave the machine: do not paste them
   into issues, pull requests, commit messages or any public place.
2. Read `docs/contributor-card.md` for source, labels, diagnostics and stopping rules.
   The matching cookbook is optional; internal Drafter cards are not contributor instructions.
3. Edit the unit the skeleton created (`reconstruction/<area>/<Class>.h` and `.cpp`). Declare only
   the members the function needs, at the offsets the listing uses. Names come from the community
   headers in the explicit search roots below (label `COMMUNITY(...)`), `GUESS` only for names you
   invent. If `start` reported a `sibling` file, it points at the same-named method in the FNV
   decompilation (`.local/sources/fnv_decomp`): read it for shape and names, never for offsets,
   layouts or slots (another game, older engine, 32-bit). Label what you take
   `SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)`, and add a
   `Sibling source: momusdigital/fnv_decomp@91e1b6e8 <path>:<line>` header line for a reused body.
4. `./sr --json compare`. Read `functions[].reason`, `first_mismatch`, sizes and
   `hint`; the private `side-by-side.txt` under `private_dir` shows target and candidate together.
   If `bind` lists `UNBOUND`, add the hint it names to the task's `bind-hints.json` with an RVA from
   the pack. Revise and repeat. Stop when `next` says to (the no-improvement threshold or hard
   outer cap), using the printed current/target matching bytes and change versus the previous
   attempt, and tell the person; `release 0x<rva> --reason "<one line>"` gives the function back.
5. Run `./sr --json preflight` while drafting (no comparator pass or fork required).
   It shares intake's deterministic contributor screen, complete include-closure checks, source
   lint and review-readiness checks. Findings name the file, line and a one-line repair; label
   checks remain advisory. `start` prefills build, evidence, recipe and drafting attribution,
   including headers for functions added to an existing unit. State the actual code and declaration
   origin in each file's leading header: the interactive prompt or `start --code-origin "<truthful
   declaration>"` supplies it, otherwise a required placeholder remains. Disclose adaptations and
   sources; never claim original reconstruction just to satisfy the check. Update the declaration
   if the drafting sources change. Header edits change the source digest, so compare again afterwards.
6. On PASS: `./sr --json submit --dry-run`, fix any `blockers`, then
   `submit`. It needs a fork remote; if it reports none, ask the person to fork the repository on
   GitHub and add it (`git remote add fork https://github.com/<them>/skyrim_decomp.git`).

Extending an accepted unit is allowed. A stale accepted companion is reported as **project
re-confirmation needed (no action for you)**, separately from submission blockers. This does not
renew its acceptance: the unchanged project acceptance gate still requires valid evidence,
independent confirmation, review and integration. `preflight --staged` checks the exact index
source that submit will commit.

A pass on this machine is not acceptance. Tell the person that the project re-runs the comparison
on its own two hosts and a Reviewer checks the source before the function counts as matched.

## Recommended local decompiler

`./sr --json --yes setup` (Windows: `.\sr.cmd --json --yes setup`) and `./sr go`
install the recommended private Ghidra view by default. Use `--no-decompiler` to skip it.
The ordinary byte and LLVM listings remain available without it. The helper first checks the owner's executable
against the pinned hash, then downloads **Ghidra 12.2** from the official NSA GitHub release and
**Eclipse Temurin 25.0.1+8**, checking every archive against the exact SHA-256 in
[`tools/contrib-decompiler-pins.json`](../tools/contrib-decompiler-pins.json). Ghidra is Apache-2.0;
Temurin is GPL-2.0 with the Classpath exception ([licence](https://adoptium.net/about/license/)).
Neither needs an acceptance prompt; the existing `--yes` install choice covers these downloads.
The runtime archives need no package manager or administrator access. The official archive
contains Linux x64 and Windows x64 decompiler binaries; on macOS and Linux arm64 the helper
builds the native decompiler from that same hash-checked source, with four compile jobs.
macOS needs Apple's Command Line Tools (`make` and `clang++`, normally present with Homebrew);
Linux arm64 needs `make` and `g++`. The helper prints an install command when build tools are
missing. Build objects and binaries remain in the private tool tree.

The pinned archives total **690–711 MB**, depending on platform (706.0 MB on macOS arm64).
On the tested 24 GiB Apple-silicon Mac, reusing the verified install and launching setup took
**0.36 seconds**; a fresh import and analysis took **526.5 seconds (8.8 minutes)**, with a sampled
peak process-tree RSS of **4.62 GiB**. The configured Java heap cap is **16 GiB**, with at most
four analysis CPUs and additional native memory. RSS is not a minimum RAM requirement: sampling,
nonresident pages and other work on the machine affect it. The earlier 8 GiB-cap attempt reported
a JVM out-of-memory error.
Before a new analysis, setup measures available RAM and free disk. It automatically skips the
decompiler below **18 GiB available RAM** (16 GiB heap plus a 2 GiB margin), below about **3 GiB
free disk**, or when resources cannot be measured. One line explains the skip and says to rerun
`./sr --yes setup` later. Installation or launch failure also leaves ordinary setup usable.
A per-function `decomp` took **13.5 seconds**, with **0.44 GiB** sampled peak RSS. Installed tools
occupied **1.16 GiB**, the completed project **0.64 GiB**, and the complete decompiler directory
**1.82 GiB**, excluding archive cache and the executable. These are measured local observations,
not cold-install timing or universal capacity guarantees; see [method and platform limits](contributor-platforms.md#optional-decompiler-status).
It runs in the background, so the first function can start before analysis finishes: rerun `setup` to see
its phase, elapsed seconds and sampled process-tree RSS in the `decompiler` result. The private
`state.json` and `analysis.log` paths are printed at launch. An interrupted run reuses the saved
import and restarts the incomplete analysis pass; a completed analysis is reused. PDB acquisition
is disabled. Public names already resolved by the helper are applied where functions still have
default names; Ghidra recovers RTTI names locally. These remain naming/type hypotheses.
The JVM exits on memory exhaustion, and a pass with an OOM diagnostic cannot become ready.

All tools, caches, logs, projects and exports live under the ignored `.local/contrib/` tree
(or the existing private `SR_LOCAL_DIR/contrib` override). Ghidra rejects dot-prefixed project
paths, so a temporary system-directory symlink (Windows: junction) points into this private tree
while Ghidra runs; the alias contains no project data and is removed afterwards. Supported runtime
packages cover macOS arm64/x64, Linux arm64/x64 and Windows x64. Native validation is recorded in
[the platform record](contributor-platforms.md); synthetic tests do not establish an OS run.

Once analysis is ready, `start` adds **`decomp.c`** to each function's private pack. If a task
started while analysis was still running, use `./sr --json decomp 0x<rva>` afterwards; this also
works for a function already matched by the project. It writes Ghidra's pseudo-C and direct
callees' signatures, labelled **private, untrusted hints, not evidence**. Use it to understand
control flow and suggest types, then reconstruct your own C++ and check it against the listing
and `compare`. Never treat guessed types, prototypes or pseudo-C as proof of byte matching.

The same once-per-owner model-exposure decision above covers this file: reading it sends parts
of their own copy to their AI provider, under their account and provider's terms; it is their
decision and responsibility. Never paste it, a Ghidra project, or other pack material into the
repository, PRs, issues, commit messages or CI. Submission stages only the existing source
allowlist; the publication guard and contributor screen reject private output/project paths.

## Optional advanced use

Use one clone/task for ordinary contributions. [Parallel agents and shared private storage](contributor-parallel.md)
are opt-in and do not replace public claiming.

## The game executable

The pinned file is in `builds/target.json` (Steam, 1.7.104.0, Steam build 24914197). If `setup`
reports another build, tell the person; do not try to obtain or modify game files yourself. Their
own purchased copy fetched with their own account through Valve's clients is fine: the Steam app,
or SteamCMD (`setup --steamcmd` installs it with Homebrew; on Debian or Ubuntu it prints
`sudo apt install steamcmd` for the person, because that package shows Steam's licence for them to
accept). `setup` prints the SteamCMD steps (the whole game, or only the executable's depot, about
38 MB) and, in a terminal, offers to start SteamCMD there; the person types their login, password
and guard code into SteamCMD themselves. Never handle, store or type Steam credentials, and never
read Steam's account files. A Steam install made in October 2026 delivered exactly the pinned build;
`setup` checks the hash of whatever it finds.

## Claims

`next` ranks **draft readiness**, then size and RVA. It prefers small accessor/flag-test/forwarder
names with usable declarations in represented units; an existing class is welcome. Each result
explains its ordering. Names and lexical signatures are heuristics, not proof of behavior, ABI,
compiler support or likely acceptance. Constructors, destructors and adjustors need explicit ABI
preparation and rank lower. Without local analysis, EH/support/parked-pattern facts remain unknown.
Optionally pass `next --function-table .local/<your-table-directory>` for your own exporter's
`table-meta.json` and `functions.jsonl`, or a JSON object containing `build_id` and `functions`.
Known EH, unsupported and parked entries rank lower and carry cautions. The build and any recorded
image hash must match the pin. Generate this data from your own legal copy; keep it private.
Live claims are still excluded before ranking.

`claim` requires `--model <actual-model-id>`, `--agent <name>`, or `--drafted-by` attribution
(including the model when AI-assisted) before claiming, and remembers it in private config and
claim records. `go --drafted-by` supplies this up front. Later claim/compare commands inherit it;
an external contributor's model is never guessed from a project profile.

`claim` publishes a GitHub issue, or prints a link for you to file. The issue author identifies
the claimant; labels and assignment are optional project-side decoration. A claim may cover one function,
hundreds of functions, several classes or half-open address ranges. For example:

```sh
./sr claim 0x1000 0x2000 --model <your-model-id>
./sr claim --class Actor --class TESForm
./sr claim --list functions.txt --range 0x1000-0x2000
```

List files hold one RVA per line, with optional names after it and `#` comment lines. A range
includes every function starting at or above its start and below its end. Titles look like
`claim: <build id> <classes or range> (<N> functions)`. Bodies have a `skyrim-claim-v1 <build id>`
fenced block, one `0x<rva> [public name]` or `0x<start>-0x<end>` per line. Bodies stay below
60,000 characters; large claims split into numbered parts. Names come only from the committed
inventory, never from a local listing. Old single-function issue titles remain recognized.

`next` excludes other people's live claims, including ranges and the project's own published
queue claims. Any partial overlap with another person's live issue or PR is refused (exit 6)
and names the issue. Overlap with your own claim is allowed. If claims race, the older issue
wins and the newer claim is withdrawn. Claims lapse after 24 hours without activity (an issue
update, comment or linked pull request); `claim --take-over` records a takeover comment. With no network,
`claim --offline-ok` records an unpublished local claim: run it again online to make it visible.
The claim form accepts `title`, `body` (the full versioned claim block) and optional `plan`
prefill IDs. If a browser does not prefill the form, paste the helper's complete sanitized claim
body into its claim field; do not post a listing. Without signed-in `gh`, the helper prints prefilled issue links; file them and
run `claim` again (`--github-user <login>` identifies you). Releasing one member of a batch does
not close the entire batch: edit its scope or close the issue on GitHub.

`python3 tools/claims.py list` shows live claims and accepted counts; `check 0x<rva> ...` checks
specific addresses. Reads use an ignored `.local/claims-cache.json` with a ten-minute TTL;
`--refresh` forces a refresh. Offline project queue commands warn and use the stale cache.
Project `publish` and `sync` renew live claims after 12 hours of inactivity while their work
remains active in the pipeline or is a planned family member.

## Platform status and storage

Use [the tested-platform matrix and disk budget](contributor-platforms.md). Do not infer native
Windows or Linux validation from a macOS run or from synthetic tests. Report failures using a
sanitized summary; do not work around a check.
