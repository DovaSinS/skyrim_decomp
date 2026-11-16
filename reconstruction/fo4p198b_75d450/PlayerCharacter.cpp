// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: authorized sibling and community declarations
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x75d450, 35 bytes: PlayerCharacter::WornArmorChanged
// PlayerCharacter::WornArmorChanged: SIBLING(fo4-private@1b765c70, author-permission); adapted using target evidence
// Sibling source: fo4-private@1b765c70 src/Game/AI/PlayerCharacter.cpp:2050
// TESObjectREFR::GetInventoryChanges: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission); unverified mapped name
// names: GUESS(low); remaining declarations and signatures are provisional
#include "PlayerCharacter.h"
void PlayerCharacter::WornArmorChanged() {
    GetInventoryChanges()->SetCachedWeightDirty();
    TESObjectREFR::WornArmorChanged();
}
