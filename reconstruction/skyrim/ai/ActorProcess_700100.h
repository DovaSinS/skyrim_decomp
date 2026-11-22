// Source exposure: community-headers (names, layout), binary-analysis (offsets from the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// ActorProcess: GUESS(low); the class is the placeholder owner
// GetVoiceRecoveryTime: CRASHLOGGER_PDB(59818@2026.10.24)
// AIProcess::high, HighProcessData, voiceRecoveryTime: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); HighProcessData is a stand-in with only the member the body reads
#pragma once

#include <cstdint>
#include <cstddef>

struct HighProcessData
{
    std::uint8_t pad00[0x18];
    float voiceRecoveryTime;
};

class ActorProcess
{
public:
    float GetVoiceRecoveryTime() const;  // compared: 0x700100

    std::uint8_t pad00[0x10];
    HighProcessData* high;
};
