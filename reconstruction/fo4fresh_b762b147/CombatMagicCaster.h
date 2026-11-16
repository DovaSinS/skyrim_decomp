// CombatMagicCaster partial declarations.
// Build sse-steam-1-7-104.
// Labels: v2
// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Names, signatures and layout are unverified.
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x8334f0, 9 bytes: CombatMagicCaster::CalcCastMagicChance
// RVA 0x833500, 9 bytes: CombatMagicCaster::CalcMagicHoldTime
// CalcCastMagicChance: Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatMagicCaster.cpp:46
// CalcMagicHoldTime: Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatMagicCaster.cpp:52
// CombatMagicCaster, CombatMagicCaster::CalcCastMagicChance, CombatMagicCaster::CalcMagicHoldTime: SIBLING(fo4-private@1b765c70, author-permission)
// unknown00, health, lookFor, inheritRotation, minRange, maxRange, score, artObject: STANDIN GUESS(low)
#pragma once
#include <cstdint>
class CombatController;
class EffectItem;
class NiAVObject;
class CombatMagicCaster
{
public:
    float CalcCastMagicChance(const CombatController*) const;
    float CalcMagicHoldTime(const CombatController*) const;
};
