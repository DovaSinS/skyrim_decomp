// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Character, Character::Function303b00, Form, Form::formType, ExtraList, ExtraList::Get: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct Form
{
    uint8_t pad00[0x1a];
    uint8_t formType;
};

struct ExtraList
{
    Form** Get();
};

class Character
{
public:
    Form* Function303b00();
    uint8_t pad00[0x70];
    ExtraList list70;
};
