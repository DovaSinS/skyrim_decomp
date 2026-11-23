// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// InventoryChanges, VisitWornItems, IItemChangeVisitor, ~IItemChangeVisitor, Visit, ShouldVisit, Unk_03: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// PlayerCharacter::sub_14088B840: CRASHLOGGER_PDB(59818@2026.10.24); the only name recorded for this address
// Function941130, PlayerWornItemVisitor, player: GUESS(low); the visitor class has no recorded name
#pragma once

#include <cstdint>
#include <cstddef>

class InventoryEntryData;
class TESBoundObject;
class PlayerCharacter;

class InventoryChanges
{
public:
    class IItemChangeVisitor
    {
    public:
        virtual ~IItemChangeVisitor() {}                                                            // 00
        virtual std::uint32_t Visit(InventoryEntryData* a_entryData) = 0;                           // 01
        virtual bool ShouldVisit(InventoryEntryData* a_entryData, TESBoundObject* a_object);        // 02
        virtual std::uint32_t Unk_03(InventoryEntryData* a_entryData, void* a_arg2, bool* a_arg3);  // 03
    };

    void VisitWornItems(IItemChangeVisitor& a_visitor);  // defined in its own unit
};

class PlayerWornItemVisitor : public InventoryChanges::IItemChangeVisitor
{
public:
    explicit PlayerWornItemVisitor(PlayerCharacter* a_player) :
        player(a_player)
    {
    }

    std::uint32_t Visit(InventoryEntryData* a_entryData) override;  // defined in its own translation unit

    PlayerCharacter* player;
};

class PlayerCharacter
{
public:
    void Function941130(InventoryChanges* a_changes);
};
