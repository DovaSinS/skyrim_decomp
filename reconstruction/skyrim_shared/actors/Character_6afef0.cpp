// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6afef0 Character::Function6afef0
// Adapted bodies: TestBit (header), momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp, CC0-1.0
#include "Character_6afef0.h"

void Character::Function6afef0()
{
    if (gFlag3244aa4 == 0 && !TestBit(gBGSSaveLoadGame->unk340, 1)) {
        unkE8 |= 1;
        return;
    }
    ProcessOwner* owner = unk380();
    if (owner) {
        ParamBlock block;
        block.unk00 = gConstant219e5f0;
        block.unk04 = 0x2001;
        owner->vslot44(&block, 0);
    }
}

