// Actor, build sse-steam-1-7-104.
// Labels: v2
// Inferred names: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// Compared functions:
// RVA 0xa012c0, 36 bytes: papyrus::Actor::KillSilent.
// RVA 0xa012f0, 36 bytes: papyrus::Actor::Kill.
// RVA 0xa01930, 36 bytes: papyrus::Actor::PlayIdle.
// RVA 0xa01960, 38 bytes: papyrus::Actor::PlayIdleWithTarget.
#include "Actor.h"
namespace papyrus {
void Actor::KillSilent(VM* vm, std::uint32_t stack, ::Actor* self, ::Actor* killer) { KillImpl(self, killer, false, vm, stack); }
void Actor::Kill(VM* vm, std::uint32_t stack, ::Actor* self, ::Actor* killer) { KillImpl(self, killer, true, vm, stack); }
bool Actor::PlayIdle(VM* vm, std::uint32_t stack, ::Actor* self, TESIdleForm* idle) { return PlayIdleImpl(self, idle, nullptr, vm, stack); }
bool Actor::PlayIdleWithTarget(VM* vm, std::uint32_t stack, ::Actor* self, TESIdleForm* idle, TESObjectREFR* target) { return PlayIdleImpl(self, idle, target, vm, stack); }
}
