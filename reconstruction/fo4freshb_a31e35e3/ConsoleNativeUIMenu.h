// ConsoleNativeUIMenu declarations for build sse-steam-1-7-104.
// Labels: v2
// Origin: original partial declarations from target listing and sibling type/name hints.
// Task: p177fb-a31e35e3
// Source exposure: mixed (pinned target listing and sibling hints).
// ConsoleNativeUIMenu, ConsoleNativeUIMenu::ProcessMessage: GUESS(low)
// ConsoleNativeUIMenu fields: STANDIN GUESS(low)
// Supporting types: STANDIN GUESS(low)
#pragma once
#include <cstdint>
struct Event { unsigned type; unsigned code; };
struct Data { std::uint8_t pad[0x10]; Event* event; };
struct Message { std::uint8_t pad[8]; unsigned type; std::uint8_t gap[4]; Data* data; };
class ConsoleNativeUIMenu {
public: int ProcessMessage(Message& message);
private: std::uint8_t pad[0x30]; bool detected;
};
