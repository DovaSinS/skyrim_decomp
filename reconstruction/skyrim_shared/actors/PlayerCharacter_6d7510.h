// Source exposure: binary-analysis (names from CrashLogger output; shapes from the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// PlayerCharacter::Function6d7510: CRASHLOGGER_PDB(59818@2026.10.24) GUESS(low); placeholder name for PlayerCharacter::sub_140632B10
// ActorMagicCaster::Function5c17e0: CRASHLOGGER_PDB(59818@2026.10.24) GUESS(low); callee placeholder (CrashLogger sub_140543AE0), declared as a stand-in
// MagicCasterLike, unk1A8: GUESS(low); stand-in for a caster and the array of four caster pointers
#pragma once

#include <cstdint>
#include <cstddef>

class MagicCasterLike
{
public:
    void Function5c17e0(void* a_arg);
};

class PlayerCharacter
{
public:
    void Function6d7510(void* a_arg);

    std::uint8_t unk00[0x1A8];
    MagicCasterLike* unk1A8[4];
};
