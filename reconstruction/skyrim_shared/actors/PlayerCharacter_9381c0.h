// Source exposure: binary-analysis (names from CrashLogger output; shapes from the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// PlayerCharacter::Function9381c0: CRASHLOGGER_PDB(59818@2026.10.24) GUESS(low); placeholder name for PlayerCharacter::sub_140881C80; static, no use of this
// g_valueA9381c0, g_valueB9381c0, g_stickyFlag9381c0, g_flag9381c0: GUESS(low); globals written by the function
#pragma once

#include <cstdint>
#include <cstddef>

extern float g_valueA9381c0;
extern float g_valueB9381c0;
extern bool g_stickyFlag9381c0;
extern bool g_flag9381c0;

class PlayerCharacter
{
public:
    static void Function9381c0(float a_a, float a_b, bool a_sticky, bool a_flag);
};
