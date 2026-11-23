// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x3ad190 BGSSceneActionTimer::LoadBuffer
// Adapted bodies: none
#include "BGSSceneActionTimer_3ad190.h"

void BGSSceneActionTimer::LoadBuffer(void* a_arg1, BGSLoadGameBuffer* a_buf)
{
    a_buf->LoadDataEndian(&unk24, 4, 4);
    a_buf->LoadDataEndian(&unk29, 1, 1);
    a_buf->LoadDataEndian(&unk28, 1, 1);
    BGSSceneAction::LoadBuffer(a_arg1, a_buf);
}
