// BGSPackageDataLocation functions for build sse-steam-1-7-104.
// Labels: v2
// Task: p177fb-c75cd24d
// Source exposure: mixed (pinned target listing and sibling hints).
// Evidence: findings/ghidra-import.md
// RVA 0x44df50, 19 bytes: BGSPackageDataLocation::GetAsPackageLocation
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
// Origin: adapted sibling source and target listing.
// BGSPackageDataLocation::GetAsPackageLocation: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/AI/BGSPackageData.cpp:82
// BGSPackageDataLocation, BGSPackageDataLocation::GetAsPackageLocation: GUESS(low)
// BGSPackageDataLocation fields: STANDIN GUESS(low)
#include "BGSPackageDataLocation.h"
const PackageLocation* BGSPackageDataLocation::GetAsPackageLocation() const { return pointer ? pointer->GetAsPackageLocation() : nullptr; }
