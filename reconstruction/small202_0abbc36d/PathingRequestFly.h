// PathingRequestFly, build sse-steam-1-7-104.
// Labels: v2
// Origin: original reconstruction; no sibling source used.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// PathingRequestFly: EXE_RTTI
// Compared functions:
// RVA 0x4f5400, 47 bytes: PathingRequestFly::Function4f5400.
#pragma once
#include <cstdint>
// PathingRequestFly: EXE_RTTI
// Function4f5400: GUESS(low)
// RegisterType, PathingRequestFlyTypeId, PathingRequestFlyTypeName: GUESS(low)
extern std::uint32_t PathingRequestFlyTypeId;
extern const char PathingRequestFlyTypeName[];
void RegisterType(std::uint32_t* id, const char* name, void* context);
class PathingRequestFly { public: std::uint32_t Function4f5400() const; };
