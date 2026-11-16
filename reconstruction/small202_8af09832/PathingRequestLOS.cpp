// p202_8af09832: GUESS(low)
// PathingRequestLOS, build sse-steam-1-7-104.
// Labels: v2
// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis.
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// Compared functions:
// RVA 0x4f82f0, 47 bytes: PathingRequestLOS::Function4f82f0.
#include "PathingRequestLOS.h"
using namespace p202_8af09832;
std::uint32_t PathingRequestLOS::Function4f82f0()
{
 if (!registeredType) {
  RegisterType(&registeredType, typeName, nullptr);
 }
 return registeredType;
}
