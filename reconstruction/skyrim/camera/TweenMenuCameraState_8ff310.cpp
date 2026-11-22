// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x8ff310 TweenMenuCameraState::Begin
// Adapted bodies: none
#include "TweenMenuCameraState_8ff310.h"

void TweenMenuCameraState::Begin()
{
    endingState = false;
    initialFOV = GetCurrentNormalFOV(camera);
    currentAddedFOV = 0.0f;
    targetAddedFOV = gTweenTargetFOV;
    currentAddedRotX = gTweenRotX;
    currentAddedRotY = gTweenRotY;
    targetAddedRotX = gTweenRotX;
    targetAddedRotY = gTweenRotY;
}
