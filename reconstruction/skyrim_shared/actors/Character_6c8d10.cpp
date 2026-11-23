// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6c8d10 Character::Function6c8d10
// Adapted bodies: TestBit (header), momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422, CC0-1.0
#include "Character_6c8d10.h"

bool Character::Function6c8d10()
{
    if (process) {
        Inner* inner = process->unk50;
        if (inner && !TestBitClear(inner->flags2C, 27)) {
            return TestBit(inner->flags28, 3);
        }
    }
    return unk211();
}
