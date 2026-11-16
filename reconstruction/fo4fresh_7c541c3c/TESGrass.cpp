// TESGrass reconstructed functions.
// Build sse-steam-1-7-104.
// Labels: v2
// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x2704e0, 51 bytes: TESGrass::InitializeData
// InitializeData: Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Objects/TESGrass.cpp:102
// TESGrass::InitializeData: SIBLING(fo4-private@1b765c70, author-permission)
// waterDistance, waterMode, grassFlags: STANDIN GUESS(low)
// SetDensity: Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Objects/TESGrass.cpp:35
// SetMinSlopeDegrees: Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Objects/TESGrass.cpp:46
// SetMaxSlopeDegrees: Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Objects/TESGrass.cpp:55
// SetWavePeriod: Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Objects/TESGrass.cpp:91
// RVA 0x2703d0, 14 bytes: TESGrass::SetDensity
// RVA 0x2703f0, 19 bytes: TESGrass::SetMinSlopeDegrees
// RVA 0x270410, 19 bytes: TESGrass::SetMaxSlopeDegrees
// RVA 0x2704c0, 19 bytes: TESGrass::SetWavePeriod
// TESGrass, TESGrass::SetDensity, TESGrass::SetMinSlopeDegrees, TESGrass::SetMaxSlopeDegrees, TESGrass::SetWavePeriod: SIBLING(fo4-private@1b765c70, author-permission)
// Names, signatures, and layout are unverified.
#include "TESGrass.h"

bool TESGrass::SetDensity(std::uint8_t value) { if (value <= 100) { density = value; return true; } return false; }
bool TESGrass::SetMinSlopeDegrees(std::uint8_t value) { if (value > 90 || value > maxSlope) return false; minSlope = value; return true; }
bool TESGrass::SetMaxSlopeDegrees(std::uint8_t value) { if (value > 90 || value < minSlope) return false; maxSlope = value; return true; }
bool TESGrass::SetWavePeriod(float value) { if (value > 0.0f) { wavePeriod = value; return true; } return false; }

void TESGrass::InitializeData() { density = 30; minSlope = 0; waterDistance = 0; waterMode = 0; grassFlags = 0; maxSlope = 90; positionRange = 32.0f; heightRange = 0.2f; colorRange = 0.5f; wavePeriod = 10.0f; }
