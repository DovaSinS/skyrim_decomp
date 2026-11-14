// Build: sse-steam-1-7-104; RVA 0x7d16f0; 43 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: binary-analysis
// Drafted by tools/deleting_eight_template_v3.py (GPT-6.1 Sol).
// Labels: v2
// DeletingLeaf7d16f0, object: GUESS(low) STANDIN
// Original owner and interface identity are unknown.
// Object state is only the compiler's virtual table pointer; no data members are added.
// Only the compiler-emitted scalar deleting destructor is compared.
// Static object forces emission; its initializer and teardown are not compared.
// No external implementation is copied; a pass proves code, not original names.
// Origin: {"family": "scalar-deleting-eight-byte-leaf", "template_digest": "84ae3a8e11f1b776be6127355d8090154d38d36fb973b55ca3f51e8c7402fc37", "version": "3"}
#include "DeletingLeaf7d16f0.h"
static DeletingLeaf7d16f0 object;
