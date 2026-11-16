// BSAnimationGraphManager, build sse-steam-1-7-104.
// Labels: v2
// Inferred names: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis (local binary analysis).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// Compared functions:
// RVA 0xbc19d0, 39 bytes: BSAnimationGraphManager::Functionbc19d0.
// BSAnimationGraphManager: EXE_RTTI

#include "BSAnimationGraphManager.h"
void BSAnimationGraphManager::Functionbc19d0() { if (singleton) { singleton->~BSAnimationGraphManager(); singleton = nullptr; } }
