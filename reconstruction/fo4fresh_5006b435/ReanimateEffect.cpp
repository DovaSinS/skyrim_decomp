// ReanimateEffect reconstructed functions.
// Build sse-steam-1-7-104.
// Labels: v2
// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// ShouldDispelOnDeath: Sibling source: fo4-private@1b765c70 src/Game/Magic/ReanimateEffect.cpp:63
// RVA 0x5da700, 36 bytes: ReanimateEffect::ShouldDispelOnDeath
// ReanimateEffect, ReanimateEffect::ShouldDispelOnDeath: SIBLING(fo4-private@1b765c70, author-permission)
// unknown00, gettingUp, BaseShouldDispelOnDeath: STANDIN GUESS(low)
// Names, signatures, and layout are unverified.
#include "ReanimateEffect.h"
bool ReanimateEffect::ShouldDispelOnDeath() const { return !gettingUp && BaseShouldDispelOnDeath(); }
