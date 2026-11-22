// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x3aafa0 BGSSceneAction::LoadBuffer
// Adapted bodies: none
#include "BGSSceneAction_3aafa0.h"

// 0x3aafa0 BGSSceneAction::LoadBuffer
void BGSSceneAction::LoadBuffer(void* a_arg1, BGSLoadGameBuffer* a_buf)
{
    std::uint8_t value;
    a_buf->LoadDataEndian(&value, 1, 1);
    loadsFirst = value;
    a_buf->LoadDataEndian(&value, 1, 1);
    loadsSecond = value;
}
