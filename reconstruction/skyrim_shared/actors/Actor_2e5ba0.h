// Source exposure: binary-analysis (pinned image listing only).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// Actor: GUESS(low); the class is the placeholder owner
// GetShieldObjectSlot: CRASHLOGGER_PDB(59818@2026.10.24)
// header-gap Actor: stand-in view, only the base-object member the body reads
// TESForm, TESNPC, formType: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NpcBodyData, baseForm, npcData, shieldSlot: GUESS(low); stand-in members and classes
#pragma once

#include <cstdint>
#include <cstddef>

struct NpcBodyData
{
    std::uint8_t pad000[0x138];
    std::uint32_t shieldSlot;
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
    std::uint32_t GetShieldObjectSlot();  // compared: 0x2e5ba0

    std::uint8_t pad00[0x40];
    TESForm* baseForm;
};
