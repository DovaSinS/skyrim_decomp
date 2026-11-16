// NiAlphaAccumulator, build sse-steam-1-7-104.
// Labels: v2
// Origin: adapted declarations from powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944, GPL-3.0, NiAccumulator.h, NiBackToFrontAccumulator.h, NiAlphaAccumulator.h, NiTListBase.h; body original reconstruction.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// Compared functions:
// RVA 0xf0f210, 46 bytes: NiAlphaAccumulator::Functionf0f210.
// Adapted declarations are licensed under GPL-3.0.
#include "NiAlphaAccumulator.h"
void NiAlphaAccumulator::Functionf0f210(NiAlphaAccumulator* a_dest)
{
 NiBackToFrontAccumulator::CopyMembers(a_dest);
 a_dest->observeNoSortHint = observeNoSortHint;
 a_dest->sortByClosestPoint = sortByClosestPoint;
}
