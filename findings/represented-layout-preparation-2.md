# Further represented layouts for field and storage leaves

Build: `sse-steam-1-7-104`, image SHA-256
`846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f`.
Owner awarebayes; Engineer GPT-6.1 Sol, 2026-11-15, p144 second box.
Exposure: mixed, authorized local binary analysis and pinned community declarations.
Transfer status: UNREVIEWED. This is exposure-bearing research, not a specification
for an independent implementation or a transfer to Mudcrab.

The input is the 324 field leaves and 184 p104b cases left after the first preparation.
`tools/represented_layout_catalog_v2.json` is an additive catalogue, pinned to its v1
predecessor; it does not edit v1 or any active family. It supplies 96 owner bindings,
99 field leaves and five storage leaves. Remaining input counts are 225 and 179.
These are bounded preparation counts, not target completion denominators.

## Prepared groups and evidence

- `_Func_impl_no_alloc`: 89 of the remaining 146 field candidates. Thirty are
  function-pointer wrappers, 30 are single-word captures, 19 are bound pairs and ten
  have a function word, three separately copied bytes and another word. Four physical
  layout headers represent those variants. Each member has independently checked primary
  RTTI and getter slot 5; a complete scalar copy/move method demonstrates every stored
  slot, and a separate slot-4 conditional sized delete gives 16, 24 or 32 bytes.
  Natural scalar alignment must reproduce all offsets and the size. No storage is
  invented solely from an allocation size. The callable aggregates, field meanings and
  bound signatures are guesses, not claims about the original STL implementation.
  No Microsoft STL implementation source was read or reused. The other 57 wrappers
  retain their unresolved status: an empty or bulk-copy operation, or a nontrivial
  destructor, does not establish the admitted scalar representation.
- `BGSAIWorldLocationPointRadius`: two field leaves and one storage leaf. Its primary
  base is eight bytes. Independent accesses establish a three-float value at offset 8,
  pointer-sized slots at 24 and 32, floats at 40 and 44 and bytes at 48 and 49. Compiler
  alignment yields 56 bytes, agreeing with the target's sized delete. Float arithmetic,
  separate component transfers and byte accessors support the types and widths.
- `BGSAIWorldLocationInteriorCell`: two field leaves and one storage leaf. An eight-byte
  slot at offset 8 and three separately transferred floats at offset 16 give 32 bytes
  with the same primary interface. A serialization call independently transfers twelve
  bytes beginning at offset 16. The target's own sized delete also gives 32.
- `BGSAIWorldLocationRefRadius`: one storage leaf. Four-byte handle storage at offset 8,
  floats at 12, 16 and 20 and a byte at 24 are independently accessed by its clone,
  accessors and serializer; alignment and sized delete agree on 32 bytes. Handle meaning
  and other inferred field names remain guesses. All three AI-location layouts omit
  zero-storage intermediate template identities while retaining the observed primary
  interface; they do not claim recovered original template arguments.
- `NiIntersector`: two field leaves and one storage leaf. Its constructor separately
  initializes every scalar and all six components of the two values at offsets 36 and
  48. Solver accesses distinguish floats at 8, 12, 16, 20 and 32 and integer slots at
  24 and 28. The resulting 64-byte representation agrees with sized delete. The two
  nonvirtual getter associations originate from proximity plus agreement with these
  constructor fields; their ownership is explicitly `GUESS(low)`, not a vtable proof.
- `BSScript::Internal::AutoPropGetFunction` and `AutoPropSetFunction`: four field leaves.
  The unchanged represented IFunction base is 16 bytes. Destructor calls on the values
  at offsets 16 and 24 agree with the existing string representation, the typed value
  at offset 32 is independently read, and a dword at offset 40 is used by dispatch.
  The target's own sized deletes give 48 bytes. Inferred field names are guesses.
- `BSScript::Internal::CodeTasklet`: one storage leaf. Pinned public declarations provide
  its fields through offset 72 and its 80-byte size. The target RTTI places IFuncCallQuery
  at the primary base, and its deleting leaf independently observes 80. The existing
  reference-count/interface header is included unchanged. Its body is not reused.

`CombatPathT` remains blocked by missing specialization fields despite a represented
base and known differing total sizes. The ten ConcreteEventCallbackFactory leaves
remain blocked: an 80-byte bulk transfer does not describe the intervening fields.
RawProfileCallQuery and owner-unknown entries are not enrolled. None was sent to
another model tier, and no allocation-sized opaque array was introduced.

## Sources, proof and limits

The callable and spatial declarations are original physical aliases derived from the
pinned target's access, copy, initialization, RTTI and size evidence. Their inferred
names, pointer meanings and signatures are labelled guesses. No game bytes, listings,
raw extractor tables, proprietary symbols or private command paths are published.

CodeTasklet's declaration-only source is
[CommonLibSSE-NG at b93280e832f263dbef44e44cbe2936622a02f91a](https://github.com/CharmedBaryon/CommonLibSSE-NG/tree/b93280e832f263dbef44e44cbe2936622a02f91a),
MIT, `include/RE/C/CodeTasklet.h` and `include/RE/I/IFuncCallQuery.h`. The new adapted
header retains the complete notice. The previously represented NativeFunction and
CommunityLeafStorage headers are reused unchanged with their existing provenance.
No external implementation body or sibling decompilation was read or reused here.

All 99 indexed field leaves and all five storage leaves passed stock mac-wine comparison
from 13 private translation units. The post-run audit checks current header/TU hashes,
compiler, recipe, symbol map, image, object, comparator, identity and full function
coverage. The index records sanitized proof hashes, status `mac-only-preparation` and
acceptance `not-evaluated`. A getter pass checks its own field access, not every other
field. A deleting-leaf pass checks deletion code, size and references, not field meaning.
Confidence is medium for the physical aliases; uncertain meanings and ownership remain
explicit guesses. Proof sources, actual objects, reports and raw evidence stay private.

The p144 handoff supplies private reproduction scripts and task paths. Field probes
use ordinary member or member-address expressions with static offset assertions;
storage probes use the existing empty-destructor stand-ins and exact RTTI/table bindings.
Both use `reconstruction/recipes/msvc-19.16.27054-o2.json` and unchanged stock AgentHost,
unit_build and runtime comparison. Exact saved TU hashes require the saved probe sources.

Consumers add `field_members` or `storage_members` to new catalogue versions with the
included header pins and evidence limitations; do not rewrite an active family's source
or claim. All new field probes return ordinary `void*`. Windows confirmation and fresh
independent review remain necessary before function acceptance. No inventory status,
function match, family activation or claim changes here. CI proves publication hygiene
and site generation only.
