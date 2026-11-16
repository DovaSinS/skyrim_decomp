// PathingRequestHide, build sse-steam-1-7-104.
// Labels: v2
// Origin: original reconstruction; no sibling source used.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// PathingRequestHide: EXE_RTTI
// Compared functions:
// RVA 0x4f7d30, 47 bytes: PathingRequestHide::Function4f7d30.
#pragma once
#include <cstdint>
// PathingRequestHide: EXE_RTTI
// Function4f7d30: GUESS(low)
// RegisterType, PathingRequestHideTypeId, PathingRequestHideTypeName: GUESS(low)
extern std::uint32_t PathingRequestHideTypeId;
extern const char PathingRequestHideTypeName[];
void RegisterType(std::uint32_t* id, const char* name, void* context);
class PathingRequestHide { public: std::uint32_t Function4f7d30() const; };
