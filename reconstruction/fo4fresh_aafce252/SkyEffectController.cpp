// SkyEffectController, build sse-steam-1-7-104.
// Labels: v2
// RVA 0x5dd1d0, 8 bytes: SkyEffectController::RemoveHitEffect
// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ReferenceEffectControllers.cpp:512 (SkyEffectController::RemoveHitEffect)
// RVA 0x5dd1e0, 8 bytes: SkyEffectController::GetAttachRoot
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ReferenceEffectControllers.cpp:524 (SkyEffectController::GetAttachRoot)
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
// SkyEffectController, RemoveHitEffect: GUESS(low)
#include "SkyEffectController.h"

void SkyEffectController::RemoveHitEffect(ReferenceEffect* effect) { Sky::RemoveReferenceEffect(effect); }

NiAVObject* SkyEffectController::GetAttachRoot() const { return weatherRoot; }
