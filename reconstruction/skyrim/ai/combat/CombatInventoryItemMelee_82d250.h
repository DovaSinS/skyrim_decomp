// Source exposure: mixed (community and sibling layout names; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// CombatInventoryItemMelee: CRASHLOGGER_PDB(59818@2026.10.24)
// BGSDefaultObjectManager::GetLeftHandEquip: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission); static here, the listing takes no this
// BGSDefaultObjectManager, BGSEquipSlot, TESForm: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Function82d250, item, equipSlot, pad00, pad18, gUnk31df2c0: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class TESForm;
class BGSEquipSlot;

class BGSDefaultObjectManager
{
public:
    static BGSEquipSlot* GetLeftHandEquip();  // defined in its own unit
};

extern TESForm* gUnk31df2c0;  // data at 0x31df2c0

class CombatInventoryItemMelee
{
public:
    std::uint32_t Function82d250(BGSEquipSlot* a_slot);

    std::uint8_t pad00[0x10];
    TESForm* item;
    std::uint8_t pad18[0x8];
    BGSEquipSlot* equipSlot;
};
static_assert(offsetof(CombatInventoryItemMelee, equipSlot) == 0x20, "equipSlot offset");
