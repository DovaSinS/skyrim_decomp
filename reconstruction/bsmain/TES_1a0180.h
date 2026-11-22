// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// TES: GUESS(low); the class is the placeholder owner; layout is a minimal stand-in
// currentGridX, currentGridY, interiorCell: CRASHLOGGER_PDB(59818@2026.10.24)
// GetCurrentCell: SYMBOLS(fo4-pdb)
// GetCellAtGrid: GUESS(low); the callee at 0x1a3a00 takes the grid coordinates
#pragma once

#include <cstdint>
#include <cstddef>

class TESObjectCELL;

class TES
{
public:
    TESObjectCELL* GetCurrentCell();
    TESObjectCELL* GetCellAtGrid(std::int32_t a_x, std::int32_t a_y);

    std::uint8_t   pad00[0xB0];
    std::int32_t   currentGridX;  // 0B0
    std::int32_t   currentGridY;  // 0B4
    std::uint8_t   pad0B8[8];
    TESObjectCELL* interiorCell;  // 0C0
};
