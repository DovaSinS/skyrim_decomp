// Main, build sse-steam-1-7-104.
// Labels: v2
// Inferred names: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// Compared functions:
// RVA 0x65bfd0, 38 bytes: Main::Function65bfd0.
// Main: STANDIN EXE_RTTI
// Function65bfd0, TimerService, GetTimerService, StartTimer: GUESS(low)
#pragma once
#include <cstdint>
class TimerService { public: void StartTimer(std::uint32_t, std::uint32_t); };
TimerService* GetTimerService();
class Main { public: static void Function65bfd0(bool enabled); };
