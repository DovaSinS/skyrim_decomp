// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BGSExplosion: STANDIN GUESS(low); the class is the placeholder owner
// BGSExplosion::sub_1403BF730: CRASHLOGGER_PDB(59818@2026.10.24); placeholder name of the compared function
// BGSExplosion::ScaleByDistance, gDistanceScale, gDistanceBias, unk00, strength: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class BGSExplosion
{
public:
    static float ScaleByDistance(const BGSExplosion* a_explosion, float a_distance);

    unsigned char unk00[0xCC];
    float strength;
};
static_assert(offsetof(BGSExplosion, strength) == 0xCC, "strength offset");

extern float gDistanceScale;
extern float gDistanceBias;
