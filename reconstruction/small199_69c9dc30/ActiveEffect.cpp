// ActiveEffect, build sse-steam-1-7-104.
// Labels: v2
// ActiveEffect, ShouldApply, GetEffect: GUESS(low)
// Inferred names: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis (local binary analysis only).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// Compared functions:
// RVA 0x5bad70, 36 bytes: ActiveEffect::ShouldApply.

#include "ActiveEffect.h"
bool ActiveEffect::ShouldApply(ActiveEffect** slot) { return *slot && (*slot)->GetEffect() != nullptr; }
