// Build: sse-steam-1-7-104; RVA 0x55ee10; 52 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/represented-wrapper-o2.json
// Source exposure: mixed (represented community declarations and local binary analysis).
// Drafted by tools/represented_wrapper_v3.py (GPT-6.1 Sol).
// Labels: v2
// object: GUESS(low)
// Code origin: original wrapper emission harness; represented declarations are included.
// No members or bases are added to the published represented header.
// Its type is a represented layout stand-in, not the recovered original specialization.
// The external complete destructor is bound independently for each target wrapper.
// A static object requests ordinary compiler emission of the scalar deleting destructor.
// Initialization, complete destruction and other methods are not compared or implemented.
// Only the wrapper's bytes are claimed; a pass proves no name or full layout identity.
// Origin: {"family": "represented-deleting-wrapper", "template_digest": "75155c404ef77594a8e33981f7312a231633427915442dbad33b658f951fde24", "version": "3"}
void operator delete(void*, unsigned __int64) noexcept;
#include "CombatBehaviorTreeNodeLayout.h"
static_assert(sizeof(ResearchLayouts::CombatBehaviorTreeNodeLayout) == 40, "represented allocation size");
static ResearchLayouts::CombatBehaviorTreeNodeLayout object;
