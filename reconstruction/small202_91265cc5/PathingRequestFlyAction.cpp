// p202_91265cc5: GUESS(low)
// PathingRequestFlyAction, build sse-steam-1-7-104.
// Labels: v2
// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis.
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// Compared functions:
// RVA 0x4f5b00, 47 bytes: PathingRequestFlyAction::Function4f5b00.
#include "PathingRequestFlyAction.h"
using namespace p202_91265cc5;
std::uint32_t PathingRequestFlyAction::Function4f5b00()
{
 if (!registeredType) {
  RegisterType(&registeredType, typeName, nullptr);
 }
 return registeredType;
}
