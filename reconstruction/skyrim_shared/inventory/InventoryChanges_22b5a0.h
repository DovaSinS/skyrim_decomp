// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// InventoryChanges, InventoryChanges::GetWornMask, InventoryChanges::VisitWornItems, InventoryChanges::IItemChangeVisitor: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// IItemChangeVisitor::~IItemChangeVisitor, ::Visit, ::ShouldVisit, ::Unk_03: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// InventoryChanges::GetWornMask: CRASHLOGGER_PDB(59818@2026.10.24)
// InventoryUtils::GetWornMaskVisitor: CRASHLOGGER_PDB(59818@2026.10.24) EXE_RTTI; the name of the visitor whose vtable the function stores
// GetWornMaskVisitor::mask: GUESS(low); the accumulated slot mask the function returns
// InventoryEntryData, TESBoundObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the type names only
#pragma once

#include <cstdint>

class InventoryEntryData;
class TESBoundObject;

class InventoryChanges
{
public:
    class IItemChangeVisitor
    {
    public:
        virtual ~IItemChangeVisitor() {}                                            // 00
        virtual std::uint32_t Visit(InventoryEntryData* a_entryData) = 0;           // 01
        virtual bool ShouldVisit(InventoryEntryData* a_entryData, TESBoundObject* a_object);  // 02
        virtual std::uint32_t Unk_03(InventoryEntryData* a_entryData, void* a_arg2, bool* a_arg3);  // 03
    };

    std::uint32_t GetWornMask();
    void VisitWornItems(IItemChangeVisitor& a_visitor);

    void* entryList;       // 00
    void* owner;           // 08
    float totalWeight;     // 10
    float armorWeight;     // 14
    bool changed;          // 18
    std::uint8_t unk19;    // 19
    std::uint8_t unk1A;    // 1A
    std::uint8_t unk1B;    // 1B
    std::uint32_t unk1C;   // 1C
};
static_assert(sizeof(InventoryChanges) == 0x20, "InventoryChanges size");

namespace InventoryUtils
{
    class GetWornMaskVisitor : public InventoryChanges::IItemChangeVisitor
    {
    public:
        ~GetWornMaskVisitor() override {}
        std::uint32_t Visit(InventoryEntryData* a_entryData) override;

        std::uint32_t mask = 0;  // 08
    };
}
