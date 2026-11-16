// p202_c5cd5b12: GUESS(low)
// PathingRequestClosestGoal, build sse-steam-1-7-104.
// Labels: v2
// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis.
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// Compared functions:
// RVA 0x4f29d0, 47 bytes: PathingRequestClosestGoal::Function4f29d0.
#include "PathingRequestClosestGoal.h"
using namespace p202_c5cd5b12;
std::uint32_t PathingRequestClosestGoal::Function4f29d0()
{
 if (!registeredType) {
  RegisterType(&registeredType, typeName, nullptr);
 }
 return registeredType;
}
