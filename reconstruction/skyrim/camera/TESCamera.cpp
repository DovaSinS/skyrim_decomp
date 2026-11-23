// Code origin: written for this reconstruction from the listing; names and declarations from the header
// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x9969f0 TESCamera::Function9969f0
// 0x558e10 TESCamera::GetNode
// 0x558f90 TESCamera::SetState
// 0x558dd0 TESCamera::SetCameraRoot
// Drafted by v-macrev, assisted by claude-haiku-5-5.
#include "TESCamera.h"

#include <intrin.h>

void TESCamera::Function9969f0(float a_value)
{
    unk4C = a_value;
    return Function558E70(this, a_value);
}

void TESCamera::SetState(TESCameraState* a_state)
{
    if (currentState.ptr) {
        currentState.ptr->End();
    }

    currentState = a_state;

    if (currentState.ptr) {
        currentState.ptr->Begin();
    }
}

bool TESCamera::GetNode(NiPointer<NiNode>& a_out)
{
    a_out = cameraRoot;
    return a_out.pointer != nullptr;
}

void TESCamera::SetCameraRoot(NiPointer<NiNode> a_root)
{
    cameraRoot = a_root;
}
