// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x98c970 UIBlurManager::~UIBlurManager
// Adapted bodies: none
#include "UIBlurManager_98c970.h"

UIBlurManager::~UIBlurManager()
{
    ReleaseBlurState(this);
}
