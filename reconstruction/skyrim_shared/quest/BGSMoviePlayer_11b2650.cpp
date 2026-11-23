// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x11b2650 BGSMoviePlayer::StopThread
// Adapted bodies: none
#include "BGSMoviePlayer_11b2650.h"

void BGSMoviePlayer::StopThread()
{
    if (threadHandle) {
        stopping = true;
        WaitForSingleObject(threadHandle, 0xFFFFFFFF);
        threadHandle = nullptr;
        stopping = false;
    }
}
