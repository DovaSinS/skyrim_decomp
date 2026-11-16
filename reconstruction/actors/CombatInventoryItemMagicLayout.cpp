// Build: sse-steam-1-7-104; RVA 0x83c760; 52 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/represented-magic-wrapper-o2.json
// Source exposure: mixed (represented community declarations and independent target bindings).
// Drafted by tools/rootless_wrapper_generate_v2.py (GPT-6.1 Sol).
// Labels: v2
// object: GUESS(low)
// Original represented fields, bases and external complete destructor are unchanged.
// Header includes are relative; this recipe needs no repository include root.
// Only the compiler-emitted deleting wrapper is compared, not original specialization or behavior.
// Origin: {"family": "represented-rootless-deleting-wrapper", "template_digest": "3e13200d864140c9f5432646a97957e329844e85f8bef3ee7943e9c83ef36400", "version": "2"}
void operator delete(void*, unsigned __int64) noexcept;
#include "CombatInventoryItemMagicLayout.h"
static ResearchLayouts::CombatInventoryItemMagicLayout object;
