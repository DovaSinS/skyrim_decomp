// Actor functions for build sse-steam-1-7-104.
// Labels: v2
// Task: p177fb-449995c4
// Source exposure: mixed (pinned target listing and sibling hints).
// Evidence: findings/ghidra-import.md
// RVA 0x6767b0, 8 bytes: Actor::ForceEditorLocation
// RVA 0x6bdd90, 8 bytes: Actor::GetEditorLocation
// RVA 0x687a20, 14 bytes: Actor::IsKnockedDown
// RVA 0x686640, 12 bytes: Actor::GetClass
// RVA 0x6c9090, 16 bytes: Actor::SetCombatGroup
// RVA 0x6c9070, 17 bytes: Actor::GetCombatGroup
// RVA 0x6c9850, 24 bytes: Actor::IsInCombat
// RVA 0x6d5350, 36 bytes: Actor::IsInCastPowerList
// RVA 0x692da0, 18 bytes: Actor::GetStartingAngle
// RVA 0x692dc0, 30 bytes: Actor::GetStartingLocation
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
// Origin: adapted sibling source and target listing.
// Actor::ForceEditorLocation: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor.cpp:6004
// Actor::GetClass: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor.cpp:778
// Actor::SetCombatGroup: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor_Combat.cpp:494
// Actor::GetCombatGroup: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor_Combat.cpp:487
// Actor::IsInCombat: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor_Combat.cpp:684
// Actor::IsInCastPowerList: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor_Magic.cpp:463
// Actor::GetStartingAngle: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor.cpp:2666
// Actor::GetStartingLocation: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor.cpp:2676
// Actor, Actor::ForceEditorLocation, Actor::GetEditorLocation, Actor::IsKnockedDown: GUESS(low)
// Actor fields: STANDIN GUESS(low)
#include "Actor.h"
void Actor::ForceEditorLocation(void* location) { editorLocation = location; }
void* Actor::GetEditorLocation() const { return editorLocation; }
bool Actor::IsKnockedDown() const { return (flags & 0x0e000000) != 0; }

void Actor::SetCombatGroup(void* value) { if (combat) combat->group = value; }
void* Actor::GetCombatGroup() const { return combat ? combat->group : nullptr; }
bool Actor::IsInCombat() const { return combat && !combat->inactive; }
void* Actor::GetClass() { return base->actorClass; }
bool Actor::IsInCastPowerList(void* power) const { PowerNode* item = powers; bool found = false; while (item && !found) { found = item->power == power; item = item->next; } return found; }

Point3 Actor::GetStartingLocation() { return startingLocation; }
Point3 Actor::GetStartingAngle() { return Point3{0.0f, 0.0f, startingAngle}; }
