// Source exposure: binary-analysis (names from CrashLogger output; shapes from the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// PlayerCharacter::Function755620: CRASHLOGGER_PDB(59818@2026.10.24) GUESS(low); placeholder name for PlayerCharacter::sub_1406AE010
#pragma once

#include <cstdint>
#include <cstddef>

class PlayerCharacter
{
public:
    void Function755620(std::uint8_t a_flags);

    std::uint8_t unk00[0xBEB];
    std::uint8_t unkBEB;
};
