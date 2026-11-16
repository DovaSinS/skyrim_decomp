// PeakValueModifierEffect functions for build sse-steam-1-7-104.
// Labels: v2
// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: anonymous sibling and target listing.
// OnAdd, FinishLoadGame: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/PeakValueModifierEffect.cpp:172
// Sibling source: fo4-private@1b765c70 src/Game/Magic/PeakValueModifierEffect.cpp:288
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x5da050, 42 bytes: PeakValueModifierEffect::OnAdd
// RVA 0x5da1b0, 42 bytes: PeakValueModifierEffect::FinishLoadGame
#include "PeakValueModifierEffect.h"
void PeakValueModifierEffect::OnAdd(MagicTarget* target) { FindListPosition(); ValueModifierEffect::OnAdd(target); }
void PeakValueModifierEffect::FinishLoadGame(BGSLoadFormBuffer* buffer) { FindListPosition(); ActiveEffect::FinishLoadGame(buffer); }
