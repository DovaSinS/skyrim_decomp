// BSPCOrbisGamepadDevice, build sse-steam-1-7-104.
// Labels: v2
// BSPCOrbisGamepadDevice, sub, Register, Manager, SetEnabled, configuration, manager: GUESS(low)
// Inferred names: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis (local binary analysis only).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// Compared functions:
// RVA 0xe7bf50, 37 bytes: BSPCOrbisGamepadDevice::sub.

#include "BSPCOrbisGamepadDevice.h"
void BSPCOrbisGamepadDevice::sub() { Register(configuration); manager->SetEnabled(true); }
