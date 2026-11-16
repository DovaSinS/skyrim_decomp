// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x7ee740, 35 bytes: Hazard::SetActorCause
// Hazard::SetActorCause: SIBLING(fo4-private@1b765c70, author-permission); adapted to target call sequence.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/Hazard.cpp:200
// names: GUESS(low); call identities and method names remain unverified.
#include "Hazard.h"
void Hazard::SetActorCause(ActorCause* cause) { if (cause) ownerActor = cause->actor; else ownerActor = nullHandle; TESObjectREFR::SetActorCause(cause); }
