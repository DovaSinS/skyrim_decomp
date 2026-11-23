// Source exposure: mixed (community and sibling layout names; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x82d250 CombatInventoryItemMelee::Function82d250
// Adapted bodies: none
#include "CombatInventoryItemMelee_82d250.h"

std::uint32_t CombatInventoryItemMelee::Function82d250(BGSEquipSlot* a_slot)
{
    if (a_slot != equipSlot && a_slot == BGSDefaultObjectManager::GetLeftHandEquip()) {
        return item == gUnk31df2c0 ? 0 : 3;
    }
    return 1;
}
