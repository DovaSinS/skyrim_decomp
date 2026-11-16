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
// p202_629d90bc: GUESS(low)
// PathingRequestSafeStraightLine, Function4f93e0, registeredType, typeName, RegisterType: GUESS(low)
// PathingRequestSafeStraightLine: STANDIN GUESS(low)
#pragma once
#include <cstdint>
namespace p202_629d90bc {
extern std::uint32_t registeredType;
extern const char typeName[];
void RegisterType(std::uint32_t*, const char*, void*);
}
class PathingRequestSafeStraightLine {
public:
 std::uint32_t Function4f93e0();
};
