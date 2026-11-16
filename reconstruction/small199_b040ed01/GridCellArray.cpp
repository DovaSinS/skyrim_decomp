// GridCellArray, build sse-steam-1-7-104.
// Labels: v2
// GridCellArray, sub, Process, Finish: GUESS(low)
// Inferred names: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis (local binary analysis only).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// Compared functions:
// RVA 0x227250, 34 bytes: GridCellArray::sub.

#include "GridCellArray.h"
void GridCellArray::sub(bool finish) { Process(); if (finish) Finish(); }
