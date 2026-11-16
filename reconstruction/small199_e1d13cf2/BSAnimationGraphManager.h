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

#pragma once
// BSAnimationGraphManager: EXE_RTTI
// Functionbc19d0, singleton: GUESS(low)
class BSAnimationGraphManager { public: virtual ~BSAnimationGraphManager(); static void Functionbc19d0(); static BSAnimationGraphManager* singleton; };
