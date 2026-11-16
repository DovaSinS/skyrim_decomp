// ReferenceEffectController, build sse-steam-1-7-104.
// Labels: v2
// RVA 0x5dbea0, 4 bytes: ReferenceEffectController::GetElapsedTime
// RVA 0x5dbf60, 4 bytes: ReferenceEffectController::GetParticleAttachExtent
// RVA 0x5dbeb0, 9 bytes: ReferenceEffectController::GetScale
// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ReferenceEffectControllers.cpp:29 (ReferenceEffectController::GetElapsedTime)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ReferenceEffectControllers.cpp:56 (ReferenceEffectController::GetParticleAttachExtent)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ReferenceEffectControllers.cpp:32 (ReferenceEffectController::GetScale)
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
// ReferenceEffectController, GetElapsedTime, GetParticleAttachExtent, GetScale: GUESS(low)
#include "ReferenceEffectController.h"

float ReferenceEffectController::GetElapsedTime() const
{
    return 0.0f;
}

float ReferenceEffectController::GetParticleAttachExtent()
{
    return 0.0f;
}

float ReferenceEffectController::GetScale() const
{
    return 1.0f;
}

