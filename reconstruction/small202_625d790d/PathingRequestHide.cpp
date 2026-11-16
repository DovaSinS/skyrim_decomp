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
#include "PathingRequestHide.h"
std::uint32_t PathingRequestHide::Function4f7d30() const {
  if (!PathingRequestHideTypeId) RegisterType(&PathingRequestHideTypeId, PathingRequestHideTypeName, nullptr);
  return PathingRequestHideTypeId;
}
