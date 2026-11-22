// Source exposure: community-headers (names, layout), binary-analysis (offsets from the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x700100 ActorProcess::GetVoiceRecoveryTime
// Adapted bodies: none
#include "ActorProcess_700100.h"

float ActorProcess::GetVoiceRecoveryTime() const
{
    return high ? high->voiceRecoveryTime : 0.0f;
}
