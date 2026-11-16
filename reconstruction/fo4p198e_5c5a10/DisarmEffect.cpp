// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed.
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// DisarmEffect::Start: SIBLING(fo4-private@1b765c70, author-permission); adapted to observed target behavior.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/DisarmEffect.cpp:44
// DisarmEffect, StaggerEffect, MagicTarget: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/D/DisarmEffect.h, include/RE/S/StaggerEffect.h and include/RE/A/ActiveEffect.h.
// names: GUESS(low); method signatures and local names are inferred.
// RVA 0x5c5a10, 68 bytes: DisarmEffect::Start
#include "DisarmEffect.h"
void DisarmEffect::Start() { flags |= 0x40; Actor* actor = target->GetTargetAsActor(); if (actor && actor->CanBeDisarmed()) { magnitude = 1.0f; StaggerEffect::Start(); duration = 10.0f; } }
