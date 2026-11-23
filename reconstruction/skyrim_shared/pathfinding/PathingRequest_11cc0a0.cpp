// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x11cc0a0 PathingRequest::Function11cc0a0
// Adapted bodies: none
#include "PathingRequest_11cc0a0.h"

bool PathingRequest::Function11cc0a0()
{
    field10.Read();
    // unsigned compare: the flag test is an unsigned-greater-than-zero check in the original
    if (!((flags82 & 2u) > 0u) && *field58.Read() == 0) {
        return false;
    }
    return (flagsD0 & 0x70) != 0;
}
