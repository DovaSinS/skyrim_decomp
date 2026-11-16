// CombatInventoryItemRanged partial declarations.
// Build sse-steam-1-7-104.
// Labels: v2
// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Names, signatures and layout are unverified.
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x82d6f0, 6 bytes: CombatInventoryItemRanged::GetMinRange
// RVA 0x82d700, 6 bytes: CombatInventoryItemRanged::GetMaxRange
// RVA 0x82d730, 6 bytes: CombatInventoryItemRanged::GetEquipRange
// GetMinRange: Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:242
// GetMaxRange: Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:244
// GetEquipRange: Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:248
// CombatInventoryItemRanged, CombatInventoryItemRanged::GetMinRange, CombatInventoryItemRanged::GetMaxRange, CombatInventoryItemRanged::GetEquipRange: SIBLING(fo4-private@1b765c70, author-permission)
// unknown00, health, lookFor, inheritRotation, minRange, maxRange, score, artObject: STANDIN GUESS(low)
#pragma once
#include <cstdint>
class CombatController;
class EffectItem;
class NiAVObject;
class CombatInventoryItemRanged
{
public:
    float GetMinRange() const;
    float GetMaxRange() const;
    float GetEquipRange() const;
private:
    std::uint64_t unknown00[7];
    float minRange;
    float maxRange;
};
