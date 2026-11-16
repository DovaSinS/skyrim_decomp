// TES, build sse-steam-1-7-104.
// Labels: v2
// TES, Function1a5a00, Function1a5a30, FindCell, Cell, GetValueA, GetValueB, fallback: GUESS(low)
// Inferred names: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis (local binary analysis only).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// Compared functions:
// RVA 0x1a5a00, 39 bytes: TES::sub.
// RVA 0x1a5a30, 39 bytes: TES::sub.

#include "TES.h"
float TES::Function1a5a00() { auto cell = FindCell(); return cell ? cell->GetValueA() : fallback; }
float TES::Function1a5a30() { auto cell = FindCell(); return cell ? cell->GetValueB() : fallback; }
