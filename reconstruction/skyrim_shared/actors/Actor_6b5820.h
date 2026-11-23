// Source exposure: binary-analysis (names from CrashLogger output; shapes from the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Actor::Function6b5820: CRASHLOGGER_PDB(59818@2026.10.24) GUESS(low); placeholder name for ActorState::Func7_14060EB20; the unit keeps the placeholder class Actor
// ActorProcess::Function7233b0: CRASHLOGGER_PDB(59818@2026.10.24) GUESS(low); callee placeholder, declared as a stand-in
// Vec3Like, g_defaultVec6b5820: GUESS(low); a three-float value and the global default returned when no process exists
#pragma once

#include <cstdint>
#include <cstddef>

struct Vec3Like
{
    float x;
    float y;
    float z;
};

extern Vec3Like g_defaultVec6b5820;

class ActorProcess
{
public:
    const Vec3Like& Function7233b0();
};

class Actor
{
public:
    void Function6b5820(Vec3Like& a_out);

    std::uint8_t unk00[0x38];
    ActorProcess* unk38;
};
