// Build: sse-steam-1-7-104
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
// RVA 0x5e5bf0, 9 bytes: CalmEffect::GetTargetValue
// CalmEffect::GetTargetValue, build sse-steam-1-7-104, RVA 0x5e5bf0, 9 bytes.
// Labels: v2
// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: original reconstruction using target listing and anonymous sibling hints.
// GetTargetValue: SIBLING(fo4-private@1b765c70, author-permission); src/Game/Magic/TargetValueModifierEffect.cpp:145; adapted behavior.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Semantic names and types: GUESS(low); except where separately attributed.
#include "CalmEffect.h"
float CalmEffect::GetTargetValue() const { return -1.0f; }
