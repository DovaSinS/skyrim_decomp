// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Character, Character::Function6a5310, RefCounted, RefCounted::DecRef: GUESS(low)
#pragma once

#include <intrin.h>

class RefCounted
{
public:
    virtual ~RefCounted() {}

    void DecRef()
    {
        // atomic release of one reference; the last one destroys the object
        if (_InterlockedDecrement(&refCount) == 0) {
            delete this;
        }
    }

    long refCount;  // 0x8
};

class Character
{
public:
    void Function6a5310();  // compared: 0x6a5310

    char pad000[0x150];
    RefCounted* held;  // 0x150
};
