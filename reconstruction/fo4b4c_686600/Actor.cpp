// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x686600, 43 bytes: Actor::SetObjectReference
// Actor::SetObjectReference: SIBLING(fo4-private@1b765c70, author-permission); adapted to target base and race fields.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor.cpp:65
// names: GUESS(low); object and race identities remain inferred.
#include "Actor.h"
void Actor::SetObjectReference(TESBoundObject* object) { TESObjectREFR::SetObjectReference(object); if (data.objectReference) race = static_cast<TESNPC*>(data.objectReference)->TESRaceForm::race; }
