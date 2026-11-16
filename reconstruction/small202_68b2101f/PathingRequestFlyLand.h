// PathingRequestFlyLand, build sse-steam-1-7-104.
// Labels: v2
// Origin: original reconstruction; no sibling source used.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// PathingRequestFlyLand: EXE_RTTI
// Compared functions:
// RVA 0x4f6ed0, 47 bytes: PathingRequestFlyLand::Function4f6ed0.
#pragma once
#include <cstdint>
// PathingRequestFlyLand: EXE_RTTI
// Function4f6ed0: GUESS(low)
// RegisterType, PathingRequestFlyLandTypeId, PathingRequestFlyLandTypeName: GUESS(low)
extern std::uint32_t PathingRequestFlyLandTypeId;
extern const char PathingRequestFlyLandTypeName[];
void RegisterType(std::uint32_t* id, const char* name, void* context);
class PathingRequestFlyLand { public: std::uint32_t Function4f6ed0() const; };
