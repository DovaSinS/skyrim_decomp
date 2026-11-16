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
// p202_91265cc5: GUESS(low)
// PathingRequestFlyAction, Function4f5b00, registeredType, typeName, RegisterType: GUESS(low)
// PathingRequestFlyAction: STANDIN GUESS(low)
#pragma once
#include <cstdint>
namespace p202_91265cc5 {
extern std::uint32_t registeredType;
extern const char typeName[];
void RegisterType(std::uint32_t*, const char*, void*);
}
class PathingRequestFlyAction {
public:
 std::uint32_t Function4f5b00();
};
