// ValueModifierEffect partial declarations.
// Build sse-steam-1-7-104.
// Labels: v2
// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Body reconstructed from the target listing.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// SetActorValue: Sibling source: fo4-private@1b765c70 src/Game/Magic/StimpakEffect.cpp:6
// RVA 0x5ba090, 7 bytes: ValueModifierEffect::SetActorValue
// ValueModifierEffect, ValueModifierEffect::SetActorValue: SIBLING(fo4-private@1b765c70, author-permission)
// unknown00, actorValue, maxDistance: STANDIN GUESS(low)
// Names, signatures, and layout are unverified.
#pragma once
#include <cstdint>
class ValueModifierEffect {
public:
    void SetActorValue(std::uint32_t value);
private:
    std::uint64_t unknown00[18];
    std::uint32_t actorValue;
};
