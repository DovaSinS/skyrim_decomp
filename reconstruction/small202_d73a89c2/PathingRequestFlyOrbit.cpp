// p202_d73a89c2: GUESS(low)
// PathingRequestFlyOrbit, build sse-steam-1-7-104.
// Labels: v2
// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis.
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// Compared functions:
// RVA 0x4f7530, 47 bytes: PathingRequestFlyOrbit::Function4f7530.
#include "PathingRequestFlyOrbit.h"
using namespace p202_d73a89c2;
std::uint32_t PathingRequestFlyOrbit::Function4f7530()
{
 if (!registeredType) {
  RegisterType(&registeredType, typeName, nullptr);
 }
 return registeredType;
}
