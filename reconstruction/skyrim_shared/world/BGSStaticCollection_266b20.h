// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSStaticCollection, BGSStaticCollection::ClearData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSStaticCollection::ClearData: SYMBOLS(tesv-2013-map) SYMBOLS(fo4-pdb); virtual void, no parameters
// TESForm, TESForm::ClearData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the base class is modelled only by its virtual slots up to ClearData
// TESForm::unk00, ::unk01, ::unk02, ::unk03, ::unk04: GUESS(low); placeholders that put ClearData at slot 05
// g_allocationContext, AllocationContextScope: GUESS(low); a per-thread int the function saves, sets to 0x65 around the base call and restores (a scope object with a destructor)
#pragma once

#include <cstdint>

class TESForm
{
public:
    virtual ~TESForm();                // 00
    virtual void unk01();              // 01
    virtual void unk02();              // 02
    virtual void unk03();              // 03
    virtual void unk04();              // 04
    virtual void ClearData();          // 05
};

class BGSStaticCollection : public TESForm
{
public:
    virtual void ClearData() override;  // 05
};

extern __declspec(thread) std::uint32_t g_allocationContext;

struct AllocationContextScope
{
    std::uint32_t saved;
    AllocationContextScope() : saved(g_allocationContext) { g_allocationContext = 0x65; }
    ~AllocationContextScope() { g_allocationContext = saved; }
};
