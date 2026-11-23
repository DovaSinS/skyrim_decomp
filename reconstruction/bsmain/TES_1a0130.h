// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// TES, ResetGridPositions: GUESS(low); stand-in view, layout only as far as the compared code writes it.
// currentGridX, currentGridY, currentQueuedX, currentQueuedY, saveGridX, saveGridY: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

#include <cstdint>
#include <cstddef>

class TES
{
public:
    std::uint8_t unk00[0xB0];
    int currentGridX;       // B0
    int currentGridY;       // B4
    int currentQueuedX;     // B8
    int currentQueuedY;     // BC
    std::uint8_t unkC0[0x20];
    int saveGridX;          // E0
    int saveGridY;          // E4
    void ResetGridPositions();
};
