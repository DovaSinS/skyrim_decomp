// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSProcedureTreeBranch, BGSProcedureTreeBranch::conditions: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NG calls the array conditions
// BGSProcedureTreeBranch::Func5: CRASHLOGGER_PDB(59818@2026.10.24); slot 05 override of the item base
// BGSProcedureTreeConditionalItem, BGSProcedureTreeConditionalItem::Unk_05: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slot only, parameters observed
// ChildArray: GUESS(low); partial stand-in for BSTArray of child items, data pointer and size only
#pragma once

#include <cstdint>
#include <cstddef>

class BGSProcedureTreeConditionalItem
{
public:
    virtual void unk00();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void unk04();
    virtual void Unk_05(void* a_arg, bool a_flag);
};

struct ChildArray
{
    BGSProcedureTreeConditionalItem** data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
    std::uint32_t size;
    std::uint32_t pad14;
};

class BGSProcedureTreeBranch : public BGSProcedureTreeConditionalItem
{
public:
    void Unk_05(void* a_arg, bool a_flag) override;

    std::uint8_t pad08[0x8];
    ChildArray conditions;
};
