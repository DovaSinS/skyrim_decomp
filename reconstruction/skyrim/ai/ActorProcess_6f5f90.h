// Source exposure: community-headers (names, layout), binary-analysis (offsets from the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// ActorProcess: GUESS(low); the class is the placeholder owner
// GetWaitingforLipFile: SYMBOLS(fo4-pdb); FO4 names it on AIProcess, the unit keeps the placeholder class ActorProcess
// AIProcess::high, HighProcessData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); HighProcessData is a stand-in with only the member the body reads
// LipState, lipState, flags: GUESS(low); stand-in for the object at offset 0x3B8 of HighProcessData, which NG leaves as unk3B8
#pragma once

#include <cstdint>
#include <cstddef>

struct LipState
{
    std::uint8_t pad00[0xC];
    std::uint32_t flags;
};

struct HighProcessData
{
    std::uint8_t pad00[0x3B8];
    LipState* lipState;
};

class ActorProcess
{
public:
    bool GetWaitingforLipFile() const;  // compared: 0x6f5f90

    std::uint8_t pad00[0x10];
    HighProcessData* high;
};
