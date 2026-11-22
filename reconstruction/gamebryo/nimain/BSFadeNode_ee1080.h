// Source exposure: mixed (community headers; compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// BSFadeNode, HasActiveControllerFlag: CRASHLOGGER_PDB(59818@2026.10.24)
// NiTimeController, controllers, next: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; names only, offsets read from the listing
// flagsHigh: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class NiTimeController
{
public:
    unsigned char unk00[0x11];
    std::uint8_t flagsHigh;
    unsigned char unk12[0x2E];
    NiTimeController* next;
};
static_assert(offsetof(NiTimeController, next) == 0x40, "next controller offset");

class BSFadeNode
{
public:
    bool HasActiveControllerFlag() const;

    unsigned char unk00[0x18];
    NiTimeController* controllers;
};
