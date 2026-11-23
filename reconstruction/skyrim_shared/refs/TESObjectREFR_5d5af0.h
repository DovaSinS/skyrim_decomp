// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectREFR, InventoryChanges, IItemChangeVisitor, InventoryEntryData, GetInventoryChanges, VisitWornItems, Visit: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); minimal views.
// WornVisitorA, WornVisitorB, VisitWorn5d5af0: GUESS(low); the visitor class chain and its dtor order are read from the unwind data.
#pragma once

#include <cstdint>
#include <cstddef>

class InventoryEntryData;

class IItemChangeVisitor
{
public:
    virtual ~IItemChangeVisitor() {}
    virtual std::uint32_t Visit(InventoryEntryData* a_entryData) = 0;
};

class WornVisitorA : public IItemChangeVisitor
{
public:
    ~WornVisitorA() override {}
    std::uint32_t Visit(InventoryEntryData* a_entryData) override { return 1; }
};

class WornVisitorB : public WornVisitorA
{
public:
    ~WornVisitorB() override {}
    std::uint32_t Visit(InventoryEntryData* a_entryData) override { return 1; }
};

class InventoryChanges
{
public:
    void VisitWornItems(IItemChangeVisitor& a_visitor);
};

class TESObjectREFR
{
public:
    InventoryChanges* GetInventoryChanges();
    void VisitWorn5d5af0();
};
