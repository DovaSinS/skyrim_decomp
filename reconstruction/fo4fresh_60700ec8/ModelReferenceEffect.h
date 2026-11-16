// ModelReferenceEffect partial declarations.
// Build sse-steam-1-7-104.
// Labels: v2
// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Names, signatures and layout are unverified.
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x5d77c0, 10 bytes: ModelReferenceEffect::GetAttached
// GetAttached: Sibling source: fo4-private@1b765c70 src/Game/Magic/ModelReferenceEffect.cpp:291
// ModelReferenceEffect::GetAttached: SIBLING(fo4-private@1b765c70, author-permission)
// flags: STANDIN GUESS(low)
// RVA 0x5d6a40, 8 bytes: ModelReferenceEffect::Get3D
// Get3D: Sibling source: fo4-private@1b765c70 src/Game/Magic/ModelReferenceEffect.cpp:57
// ModelReferenceEffect, ModelReferenceEffect::Get3D: SIBLING(fo4-private@1b765c70, author-permission)
// unknown00, health, lookFor, inheritRotation, minRange, maxRange, score, artObject: STANDIN GUESS(low)
#pragma once
#include <cstdint>
class CombatController;
class EffectItem;
class NiAVObject;
class ModelReferenceEffect
{
public:
    NiAVObject* Get3D() const;
    bool GetAttached() const;
private:
    std::uint64_t unknown00[25];
    NiAVObject* artObject;
    std::uint32_t flags;
};
