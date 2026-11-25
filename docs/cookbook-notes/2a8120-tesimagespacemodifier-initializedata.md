# 0x2a8120 TESImageSpaceModifier::InitializeData

<!-- tags: method/diagnostic -->

- Function: 0x2a8120 TESImageSpaceModifier::InitializeData
- Label: GUESS(low)
- Outcome: fixed
- Cause: instruction-order
- Best score: 68/68
- Attempts: 3

## What differed

After a call that zeroes a block the target still stores zero to a word in that block. The candidate dropped the store as dead after the memset, so it was 9 bytes shorter. A volatile word store kept it but used a zeroed register instead of the immediate word store.

## Spellings tried that did not help

A volatile 16-bit member (register store, size matched but bytes differ). An explicit zero store after `std::memset` (store removed).

## Spelling that fixed it

Declare the zeroing call as an ordinary external function (`void* ZeroBlock(void*, int, std::size_t);`, bound to the CRT address) so the compiler does not know it is memset, and write the two adjacent byte members `unkE0 = 0; unkE1 = 0;` (rule 32). The stores stay and merge into one immediate word store.
