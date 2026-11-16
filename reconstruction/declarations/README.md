# Contributor declaration kit

These additive headers are reconstructed declaration stand-ins under the existing publication
policy, generated from the pinned, permitted community sources by `tools/declaration_kit.py`.
They provide typed primary inheritance, full community virtual signatures in slot order, opaque
reference declarations, and community size assertions for NiRefObject, NiObject, NiObjectNET,
NiAVObject, NiNode, BaseFormComponent, TESForm and BSTEventSink-style interfaces. No game export
or raw class table is distributed. All current kit headers use CharmedBaryon/CommonLibSSE-NG
`b93280e832f263dbef44e44cbe2936622a02f91a` (MIT), with the complete MIT notice in each header.

Use a root-relative include such as `"declarations/NiNode.h"`; the compiler's existing
`reconstruction` include root resolves it. The shared renderer selects an additive
`*-root-includes.json` recipe with the admitted `/Ireconstruction` flag and records that
recipe in the new task/source. Existing recipes and accepted units are unchanged. These headers define the ordinary class names and are
alternatives to existing partial stand-ins: mixing both definitions in one include closure fails.
In particular, this NiObject chain declares slot 4 as `NiSwitchNode* AsSwitchNode()`; the older
stand-ins embedded in `netimmerse/NiNode.h` have incomplete signatures. The older accepted headers
are unchanged. No existing accepted unit includes this kit, so adding it changes no accepted digest.

`start` uses the same renderer as internal `tools/skeleton.py`, preparing all requested functions.
It reads declarations at immutable public-source revisions, prefers this kit for covered bases,
retains other community virtuals, and leaves bodies and code origin unfilled. If no declaration is
available, the signature remains explicitly unknown. Source disagreements, such as the different
OnVisible signatures in the pinned NG and po3 declarations, get an unfilled signature marker;
resolve these using local evidence before comparing. Unsupported nested/value types, extra bases
and unparsed declarations need preparation; the generator is not a C++ frontend.

Community slots, sizes and inherited types are hypotheses. Run the existing C1-C5 checks from
[resource guidelines](../../docs/resource-guidelines.md) on your own copy. Size agreement alone
proves neither fields nor ownership. Opaque padding is not a field map, and no ownership or
cleanup action follows from a size assertion. A declaration inventory is not match evidence;
acceptance remains per function with the unchanged comparator, two hosts and independent review.

For a scalar deleting destructor identified in your own local evidence, `start` accepts
`--deleting-cleanup inline` or `--deleting-cleanup out-of-line`. The former generates the ordinary
empty complete-destructor definition plus a constructor to emit the deleting wrapper; add any
observed member cleanup. The latter generates only the destructor declaration plus the emission
constructor, so comparison can bind the call to the separate complete destructor. Without this
choice the body stays unfilled. Neither option guesses cleanup from object size.

For example, with an out-of-line base destructor:

```cpp
class Example : public NiObject {
public:
    Example();
    ~Example() override;
};
Example::Example() {}  // emission helper, not compared
// Inline complete-cleanup alternative, only when the local evidence supports it:
Example::~Example() {}  // this also calls the base destructor
// Out-of-line complete-cleanup alternative: omit that definition entirely.
```

If the target also inlines the base cleanup, the base must have an inline destructor implementing
that cleanup. An empty base destructor is correct only when its cleanup is empty; NiRefObject's
atomic lifetime-counter update cannot be dropped. The shared renderer already supports the
inline NiRefObject/NiObject form when the contributor's local pack explicitly identifies it.
The event-sink interface can likewise use an empty inline destructor only after local confirmation;
its default kit form is declaration-only. Declare callees without bodies so the binder resolves
them; an arbitrary empty implementation is not a reference declaration.

Inspect published headers with:

```sh
python3 tools/header_index.py --class NiNode
python3 tools/header_index.py --class NiObject --slot 4
python3 tools/header_index.py --class TESForm --member SaveGame
python3 tools/header_index.py > .local/header-index.json
```

The index maps each published header to its declared classes, supported members, explicit slots,
undeclared slots and known signature/placeholder gaps. Missing slots may be inherited. Inline
bodies are ignored; macros and multiline declarations can remain unknown. `start` prints relevant
header advice and returns it as `declarations` in JSON. Published declarations may support only
the members exercised by accepted functions; check the per-function reports before calling a
member reviewed. The index copies no origin hints or implementation bodies.

Regenerate the kit after contributor setup with `python3 tools/declaration_kit.py --write`.
The generator reads immutable Git blobs, so edits to local community checkouts are not imported.
New classes and changed signatures need source/provenance review. NG is preferred; permitted
powerof3/CommonLibSSE `654e55f7979c1733033d5dbef176e43827bac944` is the fallback for contributor
preparation. Files containing its declarations retain the MIT attribution and the full
GPL-3.0-or-later notice. [COPYING-GPL-3.0.txt](COPYING-GPL-3.0.txt) is the complete upstream licence;
no GPL bodies are adapted by this kit. Do not relabel reconstruction as infrastructure MIT.

Keep extensions additive. Editing any accepted unit's include closure requires the existing
[stale-acceptance procedure](../../docs/verification.md#stale-acceptances-and-delta-reviews).
