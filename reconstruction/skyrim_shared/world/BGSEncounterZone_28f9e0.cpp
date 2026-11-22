// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x28f9e0 BGSEncounterZone::GetCalcedZoneLevel
// Adapted bodies: none
#include "BGSEncounterZone_28f9e0.h"

// IsBitSet: GUESS(low); a flag-word bit test by bit index, taking the word by value.
inline bool IsBitSet(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

// 0x28f9e0 BGSEncounterZone::GetCalcedZoneLevel
std::uint16_t BGSEncounterZone::GetCalcedZoneLevel()
{
    std::uint16_t level = PlayerCharacter::singleton->GetLevel();
    if (level < data.minLevel) {
        if (!IsBitSet(data.flags, 1)) {
            level = data.minLevel;
        }
    } else {
        level = static_cast<std::uint16_t>(static_cast<float>(level - data.minLevel) * fLevelScale + static_cast<float>(data.minLevel));
    }
    if (data.maxLevel) {
        const std::uint16_t maxLevel = data.maxLevel;
        return maxLevel >= level ? level : maxLevel;
    }
    return level;
}
