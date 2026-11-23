// Source exposure: binary-analysis (names from CrashLogger output; shapes from the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// PlayerCharacter::Function7513a0: CRASHLOGGER_PDB(59818@2026.10.24) GUESS(low); placeholder name for PlayerCharacter::sub_1406A9E90
// g_flag7513a0: GUESS(low); a global byte flag read by the function
#pragma once

#include <cstdint>
#include <cstddef>

extern std::uint8_t g_flag7513a0;

class PlayerCharacter
{
public:
    void Function7513a0();

    std::uint8_t unk00[0xBEC];
    std::uint8_t unkBEC_low : 7;
    std::uint8_t unkBEC_bit7 : 1;
};
