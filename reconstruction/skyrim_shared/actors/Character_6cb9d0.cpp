// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6cb9d0 Character::IsMeleeAttackState
// Adapted bodies: none
#include "Character_6cb9d0.h"

// meleeAttackState: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); top 4 bits of actorState1, kDraw to kBash span 1 to 5
bool Character::IsMeleeAttackState()
{
    std::uint32_t state = actorState1 >> 28;
    return state >= 1 && state <= 5;
}
