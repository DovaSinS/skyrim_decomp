// DynamicAttenuationCharacteristics reconstructed functions.
// Build sse-steam-1-7-104.
// Labels: v2
// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Body reconstructed from the target listing.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// GetMaxDistance: Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSSoundOutput.cpp:77
// RVA 0x32b5b0, 6 bytes: BGSSoundOutput::DynamicAttenuationCharacteristics::GetMaxDistance
// DynamicAttenuationCharacteristics, BGSSoundOutput::DynamicAttenuationCharacteristics::GetMaxDistance: SIBLING(fo4-private@1b765c70, author-permission)
// unknown00, actorValue, maxDistance: STANDIN GUESS(low)
// Names, signatures, and layout are unverified.
#include "DynamicAttenuationCharacteristics.h"

float BGSSoundOutput::DynamicAttenuationCharacteristics::GetMaxDistance() const { return maxDistance; }
