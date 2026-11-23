// Source exposure: mixed (community declarations and the contributor-owned pack).
// Code origin: original body from the pinned image listing; names and declarations follow CommonLibSSE-NG, except TestBit, which is close to the sibling helper named in the .cpp
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Base form: shared header declarations/TESForm.h for TESForm.
// BGSRagdoll, BGSRagdoll::~BGSRagdoll, BGSRagdoll::InitializeData, BGSRagdoll::ClearData, BGSRagdoll::Load, BGSRagdoll::InitItemImpl: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown20, unk1A8, unk1B0: GUESS(low); the last two follow the community member names, typed as the stand-in classes the cast targets name
#pragma once

#include <cstdint>
#include <cstddef>
#include "declarations/TESForm.h"

class RagdollRefForm;
class RagdollRefForm2;

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
    std::uint8_t unknown40[0x168];  // 40
    // A form id until InitItemImpl resolves it, then the pointer to the form it names.
    union { std::uint32_t unk1A8Id; RagdollRefForm* unk1A8; };  // 1A8
    union { std::uint32_t unk1B0Id; RagdollRefForm2* unk1B0; };  // 1B0
};
static_assert(sizeof(BGSRagdoll) == 0x1B8, "BGSRagdoll size");
