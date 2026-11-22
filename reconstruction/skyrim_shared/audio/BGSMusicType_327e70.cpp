// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x327e70 BGSMusicType::DoFinish
// Adapted bodies: none
#include "BGSMusicType_327e70.h"

// fade the current track out over at least four seconds, then cache its status
void BGSMusicType::DoFinish(bool arg1)
{
    float fade = fadeTime > 4.0f ? fadeTime : 4.0f;
    tracks[currentTrackIndex]->DoFinish(false, fade);
    typeStatus = tracks[currentTrackIndex]->GetMusicStatus();
}
