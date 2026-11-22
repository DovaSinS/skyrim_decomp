// Source exposure: mixed (community headers; compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// Character: GUESS(low); the class is the placeholder owner
// GetFlightRadius: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(fo4-pdb); the PDB class is Actor, this unit keeps the placeholder class
// TESRace, RACE_DATA, race, data, flightRadius: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); stand-in race view, data at 0xE8 and flightRadius at 0x70 within it
// GetScale: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declared without a body, matched elsewhere
#pragma once

#include <cstdint>
#include <cstddef>

struct RACE_DATA
{
    std::uint8_t unk00[0x70];
    float flightRadius;
};

class TESRace
{
public:
    std::uint8_t unk00[0xE8];
    RACE_DATA data;
};

class Character
{
public:
    float GetFlightRadius() const;  // compared: 0x685930
    float GetScale() const;

    std::uint8_t unk00[0x1F8];
    TESRace* race;
};
