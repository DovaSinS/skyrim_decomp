// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Character, Character::Function679c80: GUESS(low)
// Character::unk40, Character_Obj40, Character_Obj40::ai, TESAIForm: GUESS(low)
// TESAIForm::Function1deb20: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

#include <cstdint>
#include <cstddef>

struct TESAIForm
{
    bool Function1deb20();
};

struct Character_Obj40
{
    std::uint8_t pad00[0xB0];
    TESAIForm ai;
};

class Character
{
public:
    std::int32_t Function679c80();  // compared: 0x679c80

    std::uint8_t pad00[0x40];
    Character_Obj40* unk40;
};
