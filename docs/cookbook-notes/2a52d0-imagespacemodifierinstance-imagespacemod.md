# 0x2a52d0 ImageSpaceModifierInstance::~ImageSpaceModifierInstance

<!-- tags: method/diagnostic -->

- Function: 0x2a52d0 ImageSpaceModifierInstance::~ImageSpaceModifierInstance
- Label: GUESS(low)
- Outcome: unsolved
- Cause: prologue-epilogue
- Best score: 118/128
- Attempts: 2

## What differed

All instructions match (reference release inlined twice, base destructor store and the global object count decrement). The unwind info differs: the target saves the callee-saved register in the second home slot, the candidate in the first. The same shift appears in the Atmosphere constructor 0x40b4f0 (194/214) and the water displacement effect deleting destructor 0x155c090 (210/230): each has an inlined smart-pointer release and the target keeps one more 8-byte slot in the shadow space (see 0x2a4ca0, where an 8-byte local explained the same kind of frame difference).

## Spellings tried that did not help

A null assignment of the smart-pointer member as a plain release; the same with a temporary guard object that releases on destruction; the release helper declared noexcept (no exception state at all).

## Spelling that fixed it

none; a spilled eight-byte object, kept alive for the unwind funclet, probably sits in the first home slot in the target. Candidate for the shadow-slot local of 0x2a4ca0.
