# Represented layouts for blocked field and storage leaves

Build: `sse-steam-1-7-104`, image SHA-256
`846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f`.
Owner: awarebayes. Engineer: GPT-6.1 Sol, 2026-11-15, task p144.
Exposure: mixed, pinned community declarations and authorized local binary analysis.
Transfer status: UNREVIEWED. This research is exposure-bearing; it is not an independent
implementation specification or a proposed transfer to Mudcrab.

## Ranking and selection

The two input snapshots contain 555 field leaves and 206 storage-layout cases. Grouping by
exact owner gives 694 groups, including one owner-unknown bucket. Grouping template
instantiations by their outer class spelling gives 289 groups. These are task-input counts,
not the target's function scope or a completion denominator. Candidates and detailed
unresolved evidence stay private.

The largest groups, ranked by dependent candidates, are:

1. `_Func_impl_no_alloc`: 146 field leaves; not prepared. A callable's address at offset 8
   does not establish its type, alignment or complete representation. No invented callable
   storage is introduced.
2. `ConcreteFormFactory`: 115 field leaves; prepared.
3. `ConcreteObjectFormFactory`: 102 field leaves; prepared. These two related factory
   templates share the same independently declared name storage.
4. Owner unknown: 30 field leaves; not a class and not prepared.
5. `CombatPathT`: 26 field leaves; not prepared. The community CombatPath base is 56 bytes,
   while target specializations have different larger sizes. An access at offset 56 does
   not describe the remaining specialization fields.
6. `ConcreteEventCallbackFactory`: 10 field leaves; not prepared. Separate accesses do not
   establish the intervening fields.
7. `BSScript::Internal::ScriptFunction`: 5 field leaves; prepared.
8. `BSScript::Internal::NativeFunctionStub`: 4 field leaves; bound to an existing layout.
9. `CombatBlackboardKey`: 4 field leaves; not prepared.
10. Several groups have three candidates. Prepared here: `WeaponEnchantmentController`
    (three field leaves), `TESRegionGrassObject` (two field leaves and one storage leaf),
    and `BSTFreeList` (three storage leaves, carried from p104b's final declaration).

The additive index is `tools/represented_layout_catalog_v1.json`. Its `classes` map contains
242 exact owner/instantiation bindings; `field_members` lists 231 of the 555 field candidates
and `storage_members` lists 22 of the 206 storage cases. The remaining 324 and 184 input rows
have no new claim from this work. Existing function sources and their claims are unaffected.

## Layout evidence

- The two factory templates adapt the pinned MIT CommonLibSSE-NG declarations. The interface
  is 8 bytes; the factory adds one `const char* _name` at offset 8, giving 16 bytes; the object
  factory adds no data. Every indexed target getter reads that eight-byte field. Each exact
  specialization's own primary RTTI table and slot were checked, rather than transferring
  a binding between template instances.
- `ScriptBytecodeFunctionLayout` represents the bytecode ScriptFunction, separately from the
  existing `ScriptFunctionLayout` alias for the IFunction base. Public declarations provide
  the fields through offset 120 and the 128-byte size; target getters address the five string
  fields at offsets 16, 24, 32, 96 and 104. The target's sized-delete observation also gives
  128 bytes. The represented descriptor and instruction-stream values retain their public
  scalar fields; no allocation-sized filler is used.
- NativeFunctionStub's RTTI, 80-byte sized-delete observation and four string addresses agree
  with the existing `NativeFunctionBaseLayout` representation. This is an explicit layout
  binding, not a claim that the community type is the original target class. The existing
  header is unchanged.
- `WeaponEnchantmentControllerLayout` adapts the pinned GPL-3.0 CommonLibSSE declarations.
  It retains the empty polymorphic controller base, six pointer representations and the final
  boolean, with compiler alignment giving 64 bytes. Target getters independently read the
  target, shader and art fields at offsets 16, 24 and 32. The smart pointer's one-pointer
  representation claims neither ownership behavior nor its omitted methods.
- `TESRegionGrassObjectLayout` is an original minimal declaration. Primary RTTI establishes
  the base at offset zero; the base's own sized delete gives 8 bytes, and the derived sized
  delete gives 24. Separate accessors establish two eight-byte slots at offsets 8 and 16,
  and a setter independently accesses the latter. Both slots have guessed names and guessed
  pointer interpretation; integer-valued alternatives and pointee meanings remain unresolved.
  This is individually observed storage, not padding invented to reach a delete size.
- `CommunityLeafStorageLayout.h` is copied unchanged from p104b's final prepared declaration.
  It covers 21 cases: 13 reference-count/interface cases, three free lists, setting collection,
  hit-effect visitor, actor filter, message callback and memory-page policy. Public fields and
  primary-base RTTI provide the representations. All 21 final header bindings were freshly
  compiled and compared here. The seven extra-data prototypes outside the 206-case input are
  excluded. The carried HandleExtraDeleteLayout and QueueDeleteLayout headers are unchanged.

The headers assert represented class sizes and field offsets. A passing accessor tests its own
field access; it does not independently validate every other field of that class. Similarly,
a deleting-leaf pass checks emitted deletion code and its size/reference bindings, not all
field meanings. Confidence is medium for the declared physical representations; meanings,
original signatures and inferred aliases retain their explicit guesses.

## Sources and exposure

No external implementation body or sibling decompilation was used. Declaration-only sources:

- [CommonLibSSE-NG at b93280e832f263dbef44e44cbe2936622a02f91a](https://github.com/CharmedBaryon/CommonLibSSE-NG/tree/b93280e832f263dbef44e44cbe2936622a02f91a),
  MIT: the named headers cited in each represented header, including the form factories,
  IFunction, ScriptFunction, PackedInstructionStream, VDescTable and reference-count/value
  declarations. Every new adapted MIT header retains the complete notice.
- [CommonLibSSE at 654e55f7979c1733033d5dbef176e43827bac944](https://github.com/powerof3/CommonLibSSE/tree/654e55f7979c1733033d5dbef176e43827bac944),
  GPL-3.0: WeaponEnchantmentController and its interface declarations, explicitly labelled in
  the represented header. CombatPath was inspected to establish the limitation above.
- The pinned target's own access widths, primary RTTI identities, base displacements and
  sized-delete arguments, analyzed locally. Private analysis and proof sources remain local.

## Verification and use

Eight private translation units passed the unchanged stock mac-wine runner and runtime
comparator: all 231 field leaves and all 22 storage leaves, 253 unique functions. Independent
post-run auditing checked complete function coverage, function identity, current header/TU
hashes, recipe, compiler, target, symbol map, object and comparator hashes. The index records
sanitized per-unit and per-function proof hashes. Its status is `mac-only-preparation`,
with acceptance `not-evaluated`; these are not public match records.

Reproduction uses the pinned recipe `reconstruction/recipes/msvc-19.16.27054-o2.json` and the
stock local runner. The private p144 handoff names the preparation, runner and audit scripts
and exact output paths. Each field probe derives a container with no added storage from its
indexed declaration, asserts the indexed offset and returns the member or its address.
Storage probes use the indexed destructor stand-ins and exact table bindings. The stock
AgentHost and unit_build compile and compare complete extents against the locally pinned image;
no target bytes or analysis listings are published. Saved proof sources are required to
reproduce their exact TU hashes.

For p143 extension, use `field_members` as the bounded field catalogue's `members`, retaining
these header pins and each explicit owner/slot binding. All operations are ordinary pointer
reads or member-address reads. For p104b extension, the `storage_members` retain its existing
catalogue entry conventions, definitions and table bindings. Add these to a new catalogue
version; do not replace an active family's pinned catalogue or edit its reviewed source.
Resolve include closures with the unchanged stock compiler/include checks.

The index is opt-in evidence for later generation. It neither extends a claim, activates a
family nor changes inventory status. Windows confirmation and the normal independent review
and acceptance path are still required for every eventual accepted function. CI validates
publication hygiene, metadata and site generation only.
