// BSShaderMaterial, build sse-steam-1-7-104.
// Labels: v2
// BSShaderMaterial, Function15758c0, Manager, Release, manager, material: GUESS(low)
// Inferred names: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis (local binary analysis only).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// Compared functions:
// RVA 0x15758c0, 39 bytes: BSShaderMaterial::Function15758c0.

#include "BSShaderMaterial.h"
void BSShaderMaterial::Function15758c0() { manager->Release(material); material = nullptr; }
