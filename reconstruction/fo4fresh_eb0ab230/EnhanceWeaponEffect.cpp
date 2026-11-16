// EnhanceWeaponEffect, build sse-steam-1-7-104.
// Labels: v2
// RVA 0x64d0b0, 43 bytes: EnhanceWeaponEffect::Start
// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/EnhanceWeaponEffect.cpp:67 (EnhanceWeaponEffect::Start)
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
// EnhanceWeaponEffect, Start: GUESS(low)
#include "EnhanceWeaponEffect.h"
void EnhanceWeaponEffect::Start() { if (!SetWeaponEnchantment()) Dispel(true); else ValueModifierEffect::Start(); }
