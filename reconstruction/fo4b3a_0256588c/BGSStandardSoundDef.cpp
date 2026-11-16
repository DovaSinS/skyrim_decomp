// Build: sse-steam-1-7-104
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
// RVA 0x32c210, 5 bytes: BGSStandardSoundDef::SoundPlaybackCharacteristics::GetFrequencyShift
// RVA 0x32c220, 5 bytes: BGSStandardSoundDef::SoundPlaybackCharacteristics::GetFrequencyVariance
// RVA 0x32c230, 5 bytes: BGSStandardSoundDef::SoundPlaybackCharacteristics::GetPriority
// RVA 0x32c250, 5 bytes: BGSStandardSoundDef::SoundPlaybackCharacteristics::GetStaticAttenuation
// RVA 0x32c210, 5 bytes: BGSStandardSoundDef::SoundPlaybackCharacteristics::GetFrequencyShift
// BGSStandardSoundDef::SoundPlaybackCharacteristics::GetFrequencyShift: SIBLING(fo4-private@1b765c70, author-permission); adaptation of src/Shared/TESForms/Gameplay/BGSStandardSoundDef.cpp:265.
// RVA 0x32c220, 5 bytes: BGSStandardSoundDef::SoundPlaybackCharacteristics::GetFrequencyVariance
// BGSStandardSoundDef::SoundPlaybackCharacteristics::GetFrequencyVariance: SIBLING(fo4-private@1b765c70, author-permission); adaptation of src/Shared/TESForms/Gameplay/BGSStandardSoundDef.cpp:271.
// RVA 0x32c230, 5 bytes: BGSStandardSoundDef::SoundPlaybackCharacteristics::GetPriority
// BGSStandardSoundDef::SoundPlaybackCharacteristics::GetPriority: SIBLING(fo4-private@1b765c70, author-permission); adaptation of src/Shared/TESForms/Gameplay/BGSStandardSoundDef.cpp:277.
// RVA 0x32c250, 5 bytes: BGSStandardSoundDef::SoundPlaybackCharacteristics::GetStaticAttenuation
// BGSStandardSoundDef::SoundPlaybackCharacteristics::GetStaticAttenuation: SIBLING(fo4-private@1b765c70, author-permission); adaptation of src/Shared/TESForms/Gameplay/BGSStandardSoundDef.cpp:289.
// Semantic names and types: GUESS(low)
// Labels: v2
// Source exposure: mixed.
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra. Evidence: findings/ghidra-import.md
#include "BGSStandardSoundDef.h"
std::uint8_t BGSStandardSoundDef::SoundPlaybackCharacteristics::GetFrequencyShift() { return frequencyShift; }
std::uint8_t BGSStandardSoundDef::SoundPlaybackCharacteristics::GetFrequencyVariance() { return frequencyVariance; }
std::uint8_t BGSStandardSoundDef::SoundPlaybackCharacteristics::GetPriority() { return priority; }
std::uint16_t BGSStandardSoundDef::SoundPlaybackCharacteristics::GetStaticAttenuation() { return staticAttenuation; }
