// Projectile functions for build sse-steam-1-7-104.
// Labels: v2
// Task: p177fb-98611a0b
// Source exposure: mixed (pinned target listing and sibling hints).
// Evidence: findings/ghidra-import.md
// RVA 0x7fe5d0, 27 bytes: Projectile::GetLinearVelocity
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
// Origin: adapted sibling source and target listing.
// Projectile::GetLinearVelocity: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/Projectile.cpp:643
// Projectile, Projectile::GetLinearVelocity: GUESS(low)
// Projectile fields: STANDIN GUESS(low)
#include "Projectile.h"
void Projectile::GetLinearVelocity(Point3& out) const { out.x = velocity.x; out.y = velocity.y; out.z = velocity.z; }
