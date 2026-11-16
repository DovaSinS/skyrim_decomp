# Contributor CI, strikes and credit

`Advisory target hashes` / `target-hashes` compiles every changed reconstruction unit and
units affected by changed headers using base-branch tools, the pinned MSVC/SDK and a fully
verified cache. Each selected function's result appears in the Actions check summary:
PASS (hash only), FAIL, or UNVERIFIED if its published target or symbol binding is unavailable.
For a new function add `// CI hash: 0x<RVA> <decorated-symbol>` in its source header. The
request selects a public target; it cannot change its size, normalization, hash or recipe.
Unbound units are still compiled. Compile errors fail the check. No-target is never a pass.

Fork PRs run on GitHub-hosted disposable machines, with read-only permissions, no secrets,
no game files and no private verifier access. PR source blobs are data: PR tools and resulting
objects are never executed. Compiler diagnostics and objects stay in scratch; only metadata
and hashes are printed. Compiler packages come from Microsoft and all restored files are
verified against the trusted manifest. PR jobs never save caches.

This is advisory evidence. Normalized hash equality omits reference identity and does not
replace the two-host acceptance rule or review.
A PR may alter its workflow, so neither a green check nor a PR-supplied report is authoritative.

## Strike rules

`data/contributor-strikes.json` is the tracked, public ledger keyed by normalized GitHub
handle. There are no emails, free-text accusations or private paths.
`data/contributors.json` is the derived public record of verified matches, bytes, false claims
and strikes per handle; the ledger above remains the authoritative strike history.
`contributor_standing.py` also reports the handle's current accepted `verified_matches`
(derived from accepted report credit),
confirmed false claims, active strikes and automatic-intake eligibility.

- A false claim is an explicit assertion in a PR that a named RVA matches, contradicted by a
  completed exact-head hash comparison against a trusted published target. Asking CI to try a
  symbol is not itself a match claim. The existing contributor template's local PASS table is
  an explicit claim; maintainers check its exact RVA and head before recording a contradiction.
- Each PR can earn at most one strike, even if it has multiple failed functions or reruns.
  Failed compilation, setup/network failures, missing targets, unsupported layouts, review
  rejection and a mere unverified claim earn no strike.
- A maintainer verifies the run provenance, author, head and explicit claim, then records the
  event with its PR number, head, contradicted RVAs and check-run ID. Untrusted PR artifacts
  never write the ledger. Initial ledger empty means no historical accusations are invented.
- Three active strikes fail `Contributor standing / contributor-standing`, apply the public
  `needs maintainer` label and stop automatic intake before compilation. Automatic intake
  independently reads trusted local ledger state; a forged or stale green PR check cannot
  bypass it. Already-enqueued acceptance transactions settle normally.
- Maintainers clear active strikes by setting `cleared_strikes` to the current false-claim
  count; history stays visible. Commit the ledger change and rerun the standing check. Remove
  its `needs maintainer` label after clearance if there is no other hold.

Example maintainer commands (run only after verifying GitHub's exact-head check provenance):

```sh
python3 tools/contributor_standing.py --author PUBLIC_HANDLE --record TRUSTED_REPORT.json \
  --head FULL_PR_HEAD --pr PR_NUMBER --check-run CHECK_RUN_ID --claimed 0x1234
python3 tools/contributor_standing.py --author PUBLIC_HANDLE --clear
python3 tools/contributor_standing.py --author PUBLIC_HANDLE
```

Stage and commit the named ledger file using the project publication procedure. Invalid or duplicate
records fail validation. The read-only `pull_request` standing check uses trusted base tools
without secrets. The privileged `pull_request_target` label job checks out only the trusted
default branch; it never fetches PR source, compiles anything or consumes artifacts.
It uses GitHub's short-lived token solely to apply the label. The compilation workflow remains
unprivileged and works without secrets on forks. Make `contributor-standing` a required check
if enabling GitHub's own auto-merge; the local automatic intake already enforces the threshold.

## Contribution credit

Accepted source retains Git authorship/co-authorship in the integration commit. The accepted
results are listed in [the reconstruction index](../reconstruction/INDEX.md). Model-family
charts describe recorded drafting attribution, not human authorship. A local comparison or
public hash-CI result alone grants neither project acceptance nor commit credit.
