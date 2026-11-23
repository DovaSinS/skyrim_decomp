// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x3abc50 BGSSceneActionDialogue::LoadBuffer
// Adapted bodies: none
#include "BGSSceneActionDialogue_3abc50.h"

void BGSSceneActionDialogue::LoadBuffer(void* a_arg1, BGSLoadGameBuffer* a_buf)
{
    a_buf->LoadDataEndian(&unk34, 4, 4);
    BGSSceneAction::LoadBuffer(a_arg1, a_buf);
}
