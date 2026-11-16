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
// p202_d73a89c2: GUESS(low)
// PathingRequestFlyOrbit, Function4f7530, registeredType, typeName, RegisterType: GUESS(low)
// PathingRequestFlyOrbit: STANDIN GUESS(low)
#pragma once
#include <cstdint>
namespace p202_d73a89c2 {
extern std::uint32_t registeredType;
extern const char typeName[];
void RegisterType(std::uint32_t*, const char*, void*);
}
class PathingRequestFlyOrbit {
public:
 std::uint32_t Function4f7530();
};
