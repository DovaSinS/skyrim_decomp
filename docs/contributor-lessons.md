# Contributor lessons

- Never pad a base class with opaque bytes to force its size; declare represented fields with named unknowns at their offsets. (docs/reviewer-runbook.md#checklist-per-function)
- Write plausible original source rather than copying decompiler output. (docs/reviewer-runbook.md#checklist-per-function)
- Avoid code whose only plausible purpose is steering emitted bytes. (docs/reviewer-runbook.md#checklist-per-function)
- Ensure each submitted function compiles and binds to its intended symbol. (docs/verification.md)
- Reproduce the comparator pass on both verifier hosts before claiming a match. (docs/verification.md#acceptance-rule)
- Mark inferred names as guesses and preserve unknowns. (docs/reviewer-runbook.md#checklist-per-function)
