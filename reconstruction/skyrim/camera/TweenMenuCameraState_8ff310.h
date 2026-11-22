// Source exposure: mixed (community headers; compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// TweenMenuCameraState: CRASHLOGGER_PDB(59818@2026.10.24); layout view only
// TESCameraState::Begin, TESCameraState::camera: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; virtual slot 01 and the member at 0x10, redeclared here in the derived view
// initialFOV, currentAddedRot, targetAddedRot, currentAddedFOV, targetAddedFOV, endingState: CRASHLOGGER_PDB(59818@2026.10.24); layout names from the CrashLogger type
// GetCurrentNormalFOV: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission); the community name is PlayerCamera::GetCurrentNormalFOV, declared here as a free function taking the camera
// PlayerCamera: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); opaque here
// gTweenTargetFOV, gTweenRotX, gTweenRotY, unk00, unk08, unk18: GUESS(low); globals the body copies and padding
#pragma once

#include <cstdint>

class PlayerCamera;

float GetCurrentNormalFOV(PlayerCamera* a_camera);
extern float gTweenTargetFOV;
extern float gTweenRotX;
extern float gTweenRotY;

class TweenMenuCameraState
{
public:
    virtual void unk00();  // 00
    virtual void Begin();  // 01

    std::uint8_t unk08[8];         // 08
    PlayerCamera* camera;          // 10
    std::uint8_t unk18[0x18];      // 18
    float initialFOV;              // 30
    float currentAddedRotX;        // 34
    float currentAddedRotY;        // 38
    float targetAddedRotX;         // 3C
    float targetAddedRotY;         // 40
    float currentAddedFOV;         // 44
    float targetAddedFOV;          // 48
    bool endingState;              // 4C
};
