// Source exposure: mixed (community declarations and the contributor-owned pack).
// Code origin: original body from the pinned image listing; names and declarations follow CommonLibSSE-NG, except TestBit, which is close to the sibling helper named in the .cpp
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Base form: shared header declarations/TESForm.h for TESForm.
// BGSRagdoll, BGSRagdoll::~BGSRagdoll, BGSRagdoll::InitializeData, BGSRagdoll::ClearData, BGSRagdoll::Load, BGSRagdoll::InitItemImpl: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown20: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include "declarations/TESForm.h"

// TODO bases: the available class context also lists TESModel after the first base; add them in that order if a compared function needs them (cookbook rule 25).

// Stand-in for the second polymorphic base (TESModel): its vptr lives at +0x20.
class TESModelStandIn
{
public:
    virtual ~TESModelStandIn();
    std::uint8_t unknown08[0x18];
};
static_assert(sizeof(TESModelStandIn) == 0x20, "second base size");

class BGSRagdoll : public TESForm, public TESModelStandIn
{
public:
    virtual ~BGSRagdoll();  // slot 00
    void InitializeData() override;  // 04
    void ClearData() override;  // 05
    bool Load(TESFile* a_mod) override;  // 06
    void InitItemImpl() override;  // 13
    BGSRagdoll();

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint8_t unknown40[0x178];  // 40
};
static_assert(sizeof(BGSRagdoll) == 0x1B8, "BGSRagdoll size");
