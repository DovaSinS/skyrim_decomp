// OwnedCameraEffectController partial declarations.
// Build sse-steam-1-7-104.
// Labels: v2
// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Names, signatures and layout are unverified.
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x5dc480, 5 bytes: OwnedCameraEffectController::EffectRotatesWithCamera
// EffectRotatesWithCamera: Sibling source: fo4-private@1b765c70 src/Game/Magic/ReferenceEffectControllers.cpp:155
// OwnedCameraEffectController, OwnedCameraEffectController::EffectRotatesWithCamera: SIBLING(fo4-private@1b765c70, author-permission)
// unknown00, health, lookFor, inheritRotation, minRange, maxRange, score, artObject: STANDIN GUESS(low)
#pragma once
#include <cstdint>
class CombatController;
class EffectItem;
class NiAVObject;
class OwnedCameraEffectController
{
public:
    bool EffectRotatesWithCamera() const;
private:
    std::uint64_t unknown00[6];
    bool inheritRotation;
};
