// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed.
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// GridArray::SetCenter: SIBLING(fo4-private@1b765c70, author-permission); adapted to observed target behavior.
// Sibling source: fo4-private@1b765c70 src/Shared/Misc/GridArray.cpp:46
// GridArray: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); adapted from include/RE/G/GridArray.h.
// names: GUESS(low); local and member names are inferred.
// RVA 0x226ce0, 66 bytes: GridArray::SetCenter
#include "GridArray.h"
bool GridArray::SetCenter(std::int32_t x, std::int32_t y) { int dx = x - centerX; int dy = y - centerY; Shift(dx, dy); return dx || dy; }
