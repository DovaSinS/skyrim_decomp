// Source exposure: binary-analysis (pinned image listing only).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// Actor: GUESS(low); the class is the placeholder owner
// GetBodyObject: CRASHLOGGER_PDB(59818@2026.10.24)
// header-gap Actor: stand-in view, only the base-object member the body reads
// TESForm, TESNPC, formType: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NpcBodyData, baseForm, npcData, bodySlot: GUESS(low); stand-in members and classes
#pragma once

#include <cstdint>
#include <cstddef>

struct NpcBodyData
{
    std::uint8_t pad000[0x150];
    std::uint32_t bodySlot;
};

struct TESForm
{
    std::uint8_t pad00[0x1A];
    std::uint8_t formType;
};

struct TESNPC : TESForm
{
    std::uint8_t pad1B[0x158 - 0x1B];
    NpcBodyData* npcData;
};

class Actor
{
public:
    std::uint32_t GetBodyObject();  // compared: 0x2e5bd0

    std::uint8_t pad00[0x40];
    TESForm* baseForm;
};
