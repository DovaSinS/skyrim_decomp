// Build: sse-steam-1-7-104; RVA 0x7d6f80; 23 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: binary-analysis; no external implementation reused.
// Drafted by tools/virtual_tail_template_v1.py (GPT-6.1 Sol).
// Labels: v2
// VirtualTail7d6f80, Dispatch, Invoke, object: GUESS(low) STANDIN
// Original ownership, signature and slot meaning unknown; erased dispatch interface.
// Only Dispatch is compared; no original class layout or runtime behavior claim.
// Origin: {"family": "nullable-virtual-tail", "template_digest": "76841bc2394c686c2fb12143f9071955a7009219a971e806d99423041de0f57b", "version": "1"}
#include "VirtualTail7d6f80.h"
void VirtualTail7d6f80::Dispatch(VirtualTail7d6f80* object) { if (object) object->Invoke(1); }
