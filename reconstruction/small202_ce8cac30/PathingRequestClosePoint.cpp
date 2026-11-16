// PathingRequestClosePoint, build sse-steam-1-7-104.
// Labels: v2
// Origin: original reconstruction; no sibling source used.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// PathingRequestClosePoint: EXE_RTTI
// Compared functions:
// RVA 0x4f2420, 47 bytes: PathingRequestClosePoint::Function4f2420.
#include "PathingRequestClosePoint.h"
std::uint32_t PathingRequestClosePoint::Function4f2420() const {
  if (!PathingRequestClosePointTypeId) RegisterType(&PathingRequestClosePointTypeId, PathingRequestClosePointTypeName, nullptr);
  return PathingRequestClosePointTypeId;
}
