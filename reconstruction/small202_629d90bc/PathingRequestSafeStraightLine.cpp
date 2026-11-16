// p202_629d90bc: GUESS(low)
// PathingRequestSafeStraightLine, build sse-steam-1-7-104.
// Labels: v2
// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis.
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// Compared functions:
// RVA 0x4f93e0, 47 bytes: PathingRequestSafeStraightLine::Function4f93e0.
#include "PathingRequestSafeStraightLine.h"
using namespace p202_629d90bc;
std::uint32_t PathingRequestSafeStraightLine::Function4f93e0()
{
 if (!registeredType) {
  RegisterType(&registeredType, typeName, nullptr);
 }
 return registeredType;
}
