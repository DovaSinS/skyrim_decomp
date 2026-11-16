// FreeCameraState partial declarations.
// Build sse-steam-1-7-104.
// Labels: v2
// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// GetTranslation: Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/FreeCameraState.cpp:25
// RVA 0x8f60a0, 18 bytes: FreeCameraState::GetTranslation
// FreeCameraState, FreeCameraState::GetTranslation: SIBLING(fo4-private@1b765c70, author-permission)
// Names, signatures, and layout are unverified.
// Fields and helper types: STANDIN GUESS(low)
#pragma once
#include <cstdint>
struct NiPoint3 { float x, y, z; };
class FreeCameraState
{
public:
    void GetTranslation(NiPoint3& value) const;
private:
    std::uint64_t unknown00[6];
    NiPoint3 translation;
};
