// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BGSMoviePlayer, BGSMoviePlayer::IsThreadRunning, threadHandle: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

extern "C" __declspec(dllimport) int __stdcall GetExitCodeThread(void* thread, unsigned long* exitCode);

class BGSMoviePlayer
{
public:
    bool IsThreadRunning();  // compared: 0x11b2500

    std::uint8_t unk00[0x10];
    void* threadHandle;
};
