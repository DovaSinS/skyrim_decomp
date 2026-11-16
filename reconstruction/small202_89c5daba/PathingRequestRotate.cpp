// PathingRequestRotate, build sse-steam-1-7-104.
// Labels: v2
// Origin: original reconstruction; no sibling source used.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// PathingRequestRotate: EXE_RTTI
// Compared functions:
// RVA 0x4f90c0, 47 bytes: PathingRequestRotate::Function4f90c0.
#include "PathingRequestRotate.h"
std::uint32_t PathingRequestRotate::Function4f90c0() const {
  if (!PathingRequestRotateTypeId) RegisterType(&PathingRequestRotateTypeId, PathingRequestRotateTypeName, nullptr);
  return PathingRequestRotateTypeId;
}
