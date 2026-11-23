// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x11b2500 BGSMoviePlayer::IsThreadRunning
// Adapted bodies: none
#include "BGSMoviePlayer_11b2500.h"

bool BGSMoviePlayer::IsThreadRunning()
{
    if (!threadHandle) {
        return false;
    }
    unsigned long code;
    GetExitCodeThread(threadHandle, &code);
    return code == 0x103;
}
