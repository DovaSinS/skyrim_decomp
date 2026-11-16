# What happens after your pull request

Submit with `./sr submit` after `./sr submit --dry-run` is clean. Your PR contains source and a sanitized local summary.
The maintainer-operated intake service checks the source and provenance, then recompiles and compares it on two independent project hosts.
A fresh Reviewer checks the source under the [acceptance rule](verification.md); a local PASS or green CI alone is not acceptance.
Approved work is integrated with Git author/co-author credit. Blocking reasons and service waits appear in PR labels and comments.
The intake service is operated by the maintainer, has no promised turnaround and may take days.
As of 2026-11-15 it has never processed an outside PR through acceptance; follow your PR labels
and comments for status.

See [contributor CI, strikes and credit](contributor-ci.md) for public hash checks and claim rules.
Service configuration and implementation details are in [internal intake operations](internal-contributor-intake.md).
