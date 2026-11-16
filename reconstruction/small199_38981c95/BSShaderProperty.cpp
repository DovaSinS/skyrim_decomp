// BSShaderProperty, build sse-steam-1-7-104.
// Labels: v2
// BSShaderProperty, Function14e78b0, Update: GUESS(low)
// Inferred names: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis (local binary analysis only).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// Compared functions:
// RVA 0x14e78b0, 41 bytes: BSShaderProperty::Function14e78b0.

#include "BSShaderProperty.h"
void BSShaderProperty::Function14e78b0(BSShaderProperty** slot, BSShaderProperty* value) { value->Update(*slot); *slot = value; }
