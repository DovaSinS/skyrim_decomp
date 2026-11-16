// Actor functions for build sse-steam-1-7-104.
// Labels: v2
// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: signatures from anonymous sibling hints.
// CalcArmorRating, GetArmorBaseFactorSum, GetWalkSpeed, GetRunSpeed, IsPathing, SetDelete: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor.cpp:6642
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor.cpp:6650
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor.cpp:1015
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor.cpp:1026
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor.cpp:3201
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor.cpp:4273
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x6bd520, 4 bytes: Actor::CalcArmorRating
// RVA 0x6bdd70, 4 bytes: Actor::GetArmorBaseFactorSum
// RVA 0x6926f0, 10 bytes: Actor::GetWalkSpeed
// RVA 0x692650, 13 bytes: Actor::GetRunSpeed
// RVA 0x6a6980, 21 bytes: Actor::IsPathing
// RVA 0x690e50, 51 bytes: Actor::SetDelete
#include "Actor.h"
float Actor::CalcArmorRating(const BGSInventoryItem&, unsigned int) const { return 0.0f; }
float Actor::GetArmorBaseFactorSum() { return 0.0f; }
float Actor::GetWalkSpeed() const { return GetMovementSpeed(0, 0); }
float Actor::GetRunSpeed() const { return GetMovementSpeed(1, 1); }
bool Actor::IsPathing() const { return GetCurrentActorMover()->IsPathing(); }
void Actor::SetDelete(bool deleted) { TESObjectREFR::SetDelete(deleted); if (deleted) processLists->AddActorToTempChangeList(this); }
