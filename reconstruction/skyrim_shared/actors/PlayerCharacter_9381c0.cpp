// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x9381c0 PlayerCharacter::Function9381c0
// Adapted bodies: none
#include "PlayerCharacter_9381c0.h"

void PlayerCharacter::Function9381c0(float a_a, float a_b, bool a_sticky, bool a_flag)
{
    g_valueA9381c0 = a_a;
    g_valueB9381c0 = a_b;
    if (!g_stickyFlag9381c0) {
        g_stickyFlag9381c0 = a_sticky;
    }
    g_flag9381c0 = a_flag;
}
