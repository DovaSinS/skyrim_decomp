// BSLight, build sse-steam-1-7-104.
// Labels: v2
// Origin: original reconstruction; NiObject declarations from reconstruction/netimmerse/NiObject.h.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// Compared functions:
// RVA 0x1576830, 44 bytes: BSLight::Function1576830.
#include "BSLight.h"
void BSLight::Function1576830(NiObject* a_object)
{
 if (a_object) {
  if (auto node = a_object->AsNode()) {
   ApplyNode(node);
  }
 }
}
