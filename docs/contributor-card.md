# Contributor drafting card

Use `./sr` (Windows: `.\sr.cmd`) in your own clone. Start with
`go --drafted-by "<person>, assisted by <model>"`, edit the two source files it creates, run
`compare`, then `submit --dry-run` and `submit`. Project runners and private handoffs are not used.

Read only the private pack named by the helper, after the owner has agreed to model exposure.
Never post listings, pseudo-C, Ghidra projects, bytes, objects, raw diagnostics or paths. Keep the skeleton's provenance and
licence fields; name your actual model. Fill the required `Code origin:` placeholder truthfully in
each file, including any adaptations and sources. `start` prepares build/evidence/recipe/model and
per-function metadata; it never invents an original-code declaration. Community headers supply
hypotheses, not binary proof.
For FNV reuse use `SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)` and cite each reused
body in a `Sibling source: momusdigital/fnv_decomp@91e1b6e8 <path>:<line>` header line. Another
game proves no Skyrim offset, layout or behavior. Follow LEGAL.md and PROVENANCE.md.

Read `functions[].reason`, sizes, `first_mismatch` and `hint` from `compare`; its private
`side-by-side.txt` is for local diagnosis only. An unbound symbol needs the helper's bind hint,
using an RVA from your own pack. A compile or include failure is not comparison evidence.

Under `cheap`, stop after 3 attempts without an improvement in matching bytes, with a hard cap
of 6 comparisons. Under `full`, use 4 without improvement and a hard cap of 10. Keep going while
matching bytes improve; missing diagnostics are unknown. Stop when the helper says to stop,
preserve the source and sanitized reason, and release the claim if you leave it. Never change
inputs, compiler flags, comparator or checks to force a pass. The matching cookbook is optional.

For typed bases, virtual signatures, cleanup choices and header gaps, see the
[declaration kit](declaration-kit.md). `start` leaves bodies and code origin
unfilled; resolve every skeleton marker before submitting.

## Recommended pseudo-C hint, installed by default

`./sr --json --yes setup` or `go` installs hash-pinned Ghidra and
Temurin privately and starts a one-time background analysis. The macOS arm64 archives total
706 MB; the measured install occupied 1.16 GiB and its project 0.64 GiB. Reused-install setup
took 0.36 seconds; fresh import/analysis took 8.8 minutes, with 4.62 GiB sampled peak RSS under
a 16 GiB heap cap. The complete measured directory used about 1.8 GiB. RSS is not a minimum
RAM requirement. `--no-decompiler` skips this step; setup also skips it with a clear retry hint
below 18 GiB available RAM (including a 2 GiB margin), about 3 GiB free disk, or unknown resources.
It runs in the background; start the first function while it works. Rerun setup for progress.
See [setup and platform status](contributing-agent.md#recommended-local-decompiler).
Once ready, `start` adds `decomp.c` beside the listing; `./sr --json decomp 0x<rva>` fills an
existing pack. It includes direct callees' guessed signatures.

Ask once before reading listings **or pseudo-C**: this sends parts of the owner's own game copy
to their AI provider, under their own account and provider's terms; it is their decision and
responsibility. Continue only if they agree. Pseudo-C is a private, untrusted hint for control
flow and possible types. Write your own reconstruction; the listing and unchanged `compare`
decide byte matching. Never paste the hint or project into a public place.

## Rules for small functions

1. **Members.** A byte-sized read from `this + 0x18` indicates a 1-byte member at offset 0x18. Split the
   padding, keep the size check: `std::uint8_t unknown18[0x8];` -> `bool data; std::uint8_t unknown19[0x7];`.
2. **Accessors and forwarders** are one line: `return data;`, `return 3;`, `return a_other->Get();`.
3. **Store order follows the target.** Write assignments in the order the listing stores them.
4. **Deleting destructor** (when your private pack identifies this form): keep the skeleton's constructor (it
   makes the compiler emit the compared body). Pick the destructor form from the listing:
   - the target **inlines** the complete destructor (it stores the vftable, then calls the base or frees
     members itself): give it an **empty inline body**, `X::~X() {}`;
   - the target **calls out** to the complete destructor (one call, then a test of `EDX` bit 0): **declare
     only**, `virtual ~X();`, and delete any definition, so compare binds the call.
   A header saying `Base form: inline stand-ins` already has the right destructor: leave it as written.
5. **Declare, don't define, a function the target calls:** `void Reset();`, no body; compare binds it.
6. **Flag test** (`shr eax,3; test al,1`): `inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
   { return ((a_flags >> a_bit) & 1) != 0; }`, call `TestBit(flags, 3)`, label `// TestBit: GUESS(low)`.
7. **Null test the target repeats:** read the member again instead of keeping a local copy.
8. **`static_assert` needs a message:** `static_assert(sizeof(X) == 0x20, "X size");`.
9. **Includes:** own header `#include "X.h"`; shared headers use reconstruction-root paths such as
   `"area/Y.h"` with the matching recipe include root. Parent steps and host/private paths fail the
   contributor screen. Follow the skeleton's recipe; do not change compiler flags to force a match.
   Some accepted headers still need re-confirmation before their old spelling can change; see the
   [include audit](contributor-include-audit.md).
10. **Labels.** A label line is `// <names>: <LABEL>`; LABEL is `COMMUNITY(<owner>/<repo>@<rev>, <licence>)`,
    `GUESS(low)`, `EXE_RTTI`, `OBSERVED`, or `STANDIN` plus one of those. Copy the skeleton's labels;
    add one for every name you add. Never write the label words anywhere else. One label per line:
    the lint rejects a second label clause after `;`, so write a second label line instead.
11. **Tail jump** (the listing ends in `JMP <function>`, not `CALL` then `RET`): make that call the last
    statement, `return Callee(...);` when it returns a value; keep no local alive after it.

Never write `asm`, `##`, `#pragma` (except `once`), byte arrays, `\x` strings. Never edit verifier inputs, tools, or another unit to force a pass.


A local PASS is a contribution candidate. Run `preflight` while drafting, then `submit --dry-run`;
fix its blockers before submitting. Submit source plus the generated sanitized summary only.
The project independently confirms on two hosts and reviews it before recording `matched`.
You do not need prior project acceptance or a project Reviewer approval to open the intake PR.
Git author/co-author credit is added at accepted integration; model charts are separate.

`next` explains its advisory readiness ranking: usable declarations and simple accessor/flag/
forwarder names first, ABI-heavy or locally known EH/unsupported/parked cases later. Existing units
can be extended. Size and names alone prove no readiness or match. Stale accepted companions show
**project re-confirmation needed (no action for you)**; the project renews their evidence under the
unchanged acceptance gate, and they do not block your submission preflight.

Ordinary work uses one clone and one task. [Parallel agents and shared private storage](contributor-parallel.md)
are advanced, opt-in use. They are not prerequisites and offline claims do not reserve work publicly.
