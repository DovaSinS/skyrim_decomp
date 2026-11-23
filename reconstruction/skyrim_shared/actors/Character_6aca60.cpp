// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6aca60 Character::Function6aca60
// Adapted bodies: TestBit (header), momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422, CC0-1.0
#include "Character_6aca60.h"

bool Character::Function6aca60()
{
    bool result;
    Inner* inner = process ? process->unk50 : nullptr;
    if (inner && !TestBitClear(inner->flags2C, 26)) {
        result = TestBit(inner->flags28, 2);
    } else {
        result = unk277();
    }
    if (result || (flagsC8 & 0x1E00000) == 0x800000) {
        return true;
    }
    return false;
}
