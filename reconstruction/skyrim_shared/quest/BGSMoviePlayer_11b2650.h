// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BGSMoviePlayer, BGSMoviePlayer::StopThread, threadHandle, stopping: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* handle, unsigned long milliseconds);

class BGSMoviePlayer
{
public:
    void StopThread();  // compared: 0x11b2650

    std::uint8_t unk00[0x10];
    void* threadHandle;
    std::uint8_t unk18[0x28];
    bool stopping;
};
