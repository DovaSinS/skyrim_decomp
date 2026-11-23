// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// AIFormulas::GetSoundLevelValue: CRASHLOGGER_PDB(59818@2026.10.24)
// SOUND_LEVEL, kLevel0, kLevel1, kLevel2, kLevel3, gValue0, gValue1, gValue2, gValue3: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Character
{
};  // unit class only; the function below is a free function in the AIFormulas namespace

enum SOUND_LEVEL
{
    kLevel0 = 0,
    kLevel1 = 1,
    kLevel2 = 2,
    kLevel3 = 3
};

extern int gValue0;
extern int gValue1;
extern int gValue2;
extern int gValue3;

namespace AIFormulas
{
    int GetSoundLevelValue(SOUND_LEVEL a_level);
}
