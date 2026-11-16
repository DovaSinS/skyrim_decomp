// CombatInventoryItem partial declarations.
// Build sse-steam-1-7-104.
// Labels: v2
// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Names, signatures and layout are unverified.
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x82ce00, 4 bytes: CombatInventoryItem::GetMinRange
// RVA 0x82ce10, 4 bytes: CombatInventoryItem::GetMaxRange
// RVA 0x82ce20, 4 bytes: CombatInventoryItem::GetOptimalRange
// RVA 0x82ce30, 9 bytes: CombatInventoryItem::GetEquipRange
// GetMinRange: Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:88
// GetMaxRange: Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:90
// GetOptimalRange: Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:92
// GetEquipRange: Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:94
// CombatInventoryItem, CombatInventoryItem::GetMinRange, CombatInventoryItem::GetMaxRange, CombatInventoryItem::GetOptimalRange, CombatInventoryItem::GetEquipRange: SIBLING(fo4-private@1b765c70, author-permission)
// unknown00, health, lookFor, inheritRotation, minRange, maxRange, score, artObject: STANDIN GUESS(low)
#pragma once
#include <cstdint>
class CombatController;
class EffectItem;
class NiAVObject;
class CombatInventoryItem
{
public:
    float GetMinRange() const;
    float GetMaxRange() const;
    float GetOptimalRange() const;
    float GetEquipRange() const;
};
