// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x687a40 Character::Function687a40
// Adapted bodies: TestBit (header), momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp, CC0-1.0
#include "Character_687a40.h"

bool Character::Function687a40()
{
    if (unk4c8(true)) {
        return false;
    }
    TargetRace* race = unk1f8;
    std::uint8_t hidden = 0;
    if (race) {
        hidden = GetBit(race->unk108, 9);
    }
    if (hidden) {
        return false;
    }
    if ((unkC8 & 0x1e00000) == 0xc00000) {
        return false;
    }
    if (TestBit(race->unk108, 22)) {
        return false;
    }
    if (currentProcess && currentProcess->Function6f6470() == 9) {
        return false;
    }
    return true;
}

