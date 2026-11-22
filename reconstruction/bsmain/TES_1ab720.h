// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// TES: GUESS(low); the class is the placeholder owner; layout is a minimal stand-in
// IsExteriorCellInBuffer: CRASHLOGGER_PDB(59818@2026.10.24)
// exteriorBuffer: CRASHLOGGER_PDB(59818@2026.10.24)
// iTempExteriorBufferSize: SYMBOLS(fo4-pdb); the global at 0x2077768 is assumed to be this one
#pragma once

#include <cstdint>
#include <cstddef>

class TESObjectCELL;

extern std::uint32_t iTempExteriorBufferSize;

class TES
{
public:
    bool IsExteriorCellInBuffer(TESObjectCELL* a_cell);

    std::uint8_t    pad00[0xD0];
    TESObjectCELL** exteriorBuffer;  // 0D0
};
