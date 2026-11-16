// BGSMessage partial declarations.
// Build sse-steam-1-7-104.
// Labels: v2
// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// InitializeData: Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMessage.cpp:132
// RVA 0x323dc0, 25 bytes: BGSMessage::InitializeData
// BGSMessage, BGSMessage::InitializeData: SIBLING(fo4-private@1b765c70, author-permission)
// unknown00, icon, owner, unknown50, flags, displayTime: STANDIN GUESS(low)
// Names, signatures, and layout are unverified.
#pragma once
#include <cstdint>
class BGSMessage { public: void InitializeData(); private: std::uint64_t unknown00[8]; void* icon; void* owner; std::uint64_t unknown50[2]; std::uint32_t flags; std::uint32_t displayTime; };
