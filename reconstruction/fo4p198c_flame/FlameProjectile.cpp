// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed (local target analysis, public declarations and permitted sibling).
// Origin: independently reconstructed from target and sibling hints.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// names: GUESS(low); signatures and type names are hypotheses.
// FlameProjectile::Handle3DLoaded: SIBLING(fo4-private@1b765c70, author-permission); adapted flag update.
// FlameProjectile::Revert: SIBLING(fo4-private@1b765c70, author-permission); adapted state reset.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/FlameProjectile.cpp:107
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/FlameProjectile.cpp:99
// RVA 0x7eb430, 19 bytes; RVA 0x7eb240, 29 bytes.
#include "FlameProjectile.h"
void FlameProjectile::Handle3DLoaded() { flags = (flags & 0xffffffccu) | 8u; }
void FlameProjectile::Revert(BGSLoadFormBuffer* buffer) {
    Projectile::Revert(buffer);
    timers.expirationTimer = 0;
    timers.coneAngle = 0;
}
