// Source exposure: mixed (community headers; compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// BGSEncounterZone, BGSEncounterZone::GetLevel: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// GetCalcedZoneLevel: CRASHLOGGER_PDB(59818@2026.10.24)
// ENCOUNTER_ZONE_DATA, zoneOwner, location, ownerRank, minLevel, flags, maxLevel: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG declares flags as an unsigned byte, the body reads it sign-extended
// PlayerCharacter, Actor::GetLevel: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the accessor the body calls
// singleton: GUESS(low); a pack-listed community name, not found as a member in the pinned checkouts; the global at RVA 0x3230778 holds the player pointer
// fLevelScale: GUESS(low); float global at RVA 0x207b5f8 that scales the span above the minimum level
#pragma once

#include <cstdint>
#include <cstddef>

class PlayerCharacter
{
public:
    std::uint16_t GetLevel() const;

    static PlayerCharacter* singleton;
};

extern float fLevelScale;

struct ENCOUNTER_ZONE_DATA
{
    void*        zoneOwner;  // 00
    void*        location;   // 08
    std::int8_t  ownerRank;  // 10
    std::uint8_t minLevel;   // 11
    std::int8_t  flags;      // 12
    std::uint8_t maxLevel;   // 13
};

class BGSEncounterZone
{
public:
    std::uint16_t GetCalcedZoneLevel();

    std::uint8_t        pad00[0x20];
    ENCOUNTER_ZONE_DATA data;  // 20
};
