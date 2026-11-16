// ConsoleNativeUIMenu functions for build sse-steam-1-7-104.
// Labels: v2
// Task: p177fb-a31e35e3
// Source exposure: mixed (pinned target listing and sibling hints).
// Evidence: findings/ghidra-import.md
// RVA 0x90f610, 44 bytes: ConsoleNativeUIMenu::ProcessMessage
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
// Origin: adapted sibling source and target listing.
// ConsoleNativeUIMenu::ProcessMessage: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/Interface/Menus/ConsoleNativeUIMenu.cpp:18
// ConsoleNativeUIMenu, ConsoleNativeUIMenu::ProcessMessage: GUESS(low)
// ConsoleNativeUIMenu fields: STANDIN GUESS(low)
#include "ConsoleNativeUIMenu.h"
int ConsoleNativeUIMenu::ProcessMessage(Message& message) { if (message.type != 6 || detected) return 0; Event* event = message.data->event; if (event->type != 6 || event->code != 16) return 0; detected = true; return 2; }
