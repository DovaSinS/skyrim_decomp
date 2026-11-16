// BGSMusicTrack partial declarations.
// Build sse-steam-1-7-104.
// Labels: v2
// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// InitItem: Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicTrack.cpp:33
// TestCanPlay: Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicTrack.cpp:21
// RVA 0x326dc0, 14 bytes: BGSMusicTrack::InitItem
// RVA 0x326d00, 35 bytes: BGSMusicTrack::TestCanPlay
// BGSMusicTrack, BGSMusicTrack::InitItem, BGSMusicTrack::TestCanPlay: SIBLING(fo4-private@1b765c70, author-permission)
// TESForm, ChangeMap, MusicCondition, Player, musicPlayer, unknown00, unknown10, formID, changes, conditions: STANDIN GUESS(low)
// Names, signatures, and layout are unverified.
#pragma once
#include <cstdint>
class TESForm;
class Player;
class MusicCondition { public: void InitItem(TESForm*); bool IsTrue(Player*, Player*); };
class BGSMusicTrack { public: void InitItem(TESForm*); bool TestCanPlay() const; private: std::uint64_t unknown00[2]; MusicCondition* conditions; };
