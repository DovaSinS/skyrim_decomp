# Threat model (contributors)

Defences aim at fairness, not punishment; no one is banned for being active.

| Threat | Simple defence | Status |
|---|---|---|
| Many PRs from one person flood the intake queue | Intake takes PRs round-robin by author, oldest first | added |
| PR text tries to instruct the AI reviewer | Reviewers treat PR text as untrusted; a review can only block, never override the byte-match gate | exists |
| Leaked or unlicensed code that still matches | Code-origin line required; publication screen; reviewers check provenance | exists |
| PR changes tools/, .github/ or sr scripts | Not auto-merged; labelled for the maintainer | exists |
| Malicious CI changes | Fork CI is read-only; the privileged workflow runs default-branch code only | exists |
| Claims never finished | Inactive claims auto-release with a friendly note; re-claiming is free | later |

## Later

- Sandboxed build user for outside PRs.
- Similarity check against public sources.
