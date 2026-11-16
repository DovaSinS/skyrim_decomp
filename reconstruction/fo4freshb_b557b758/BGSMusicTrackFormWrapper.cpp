// BGSMusicTrackFormWrapper functions for build sse-steam-1-7-104.
// Labels: v2
// Source exposure: mixed (pinned target listing, community declarations, sibling hints).
// Evidence: findings/ghidra-import.md
// RVA 0x327660, 11 bytes: BGSMusicTrackFormWrapper::DoFinish
// RVA 0x327670, 11 bytes: BGSMusicTrackFormWrapper::DoPause
// RVA 0x327680, 11 bytes: BGSMusicTrackFormWrapper::DoPlay
// RVA 0x3276a0, 11 bytes: BGSMusicTrackFormWrapper::DoUpdate
// RVA 0x3276b0, 11 bytes: BGSMusicTrackFormWrapper::GetDurationImpl
// RVA 0x3276c0, 11 bytes: BGSMusicTrackFormWrapper::GetMusicStatus
// RVA 0x3276d0, 11 bytes: BGSMusicTrackFormWrapper::GetType
// RVA 0x327790, 11 bytes: BGSMusicTrackFormWrapper::TestCanPlay
// RVA 0x327650, 11 bytes: BGSMusicTrackFormWrapper::DoClearDucking
// RVA 0x327690, 11 bytes: BGSMusicTrackFormWrapper::DoSetDuckingAttenuation
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
// Origin: adapted sibling source and target listing.
// BGSMusicTrackFormWrapper::DoFinish: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicTrackFormWrapper.cpp:158
// BGSMusicTrackFormWrapper::DoPause: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicTrackFormWrapper.cpp:148
// BGSMusicTrackFormWrapper::DoPlay: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicTrackFormWrapper.cpp:138
// BGSMusicTrackFormWrapper::DoUpdate: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicTrackFormWrapper.cpp:128
// BGSMusicTrackFormWrapper::GetDurationImpl: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicTrackFormWrapper.cpp:168
// BGSMusicTrackFormWrapper::GetMusicStatus: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicTrackFormWrapper.cpp:198
// BGSMusicTrackFormWrapper::GetType: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicTrackFormWrapper.cpp:178
// BGSMusicTrackFormWrapper::TestCanPlay: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicTrackFormWrapper.cpp:188
// BGSMusicTrackFormWrapper::DoClearDucking: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicTrackFormWrapper.cpp:218
// BGSMusicTrackFormWrapper::DoSetDuckingAttenuation: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicTrackFormWrapper.cpp:208
#include "BGSMusicTrackFormWrapper.h"
void BGSMusicTrackFormWrapper::DoUpdate() { track->DoUpdate(); }
void BGSMusicTrackFormWrapper::DoPlay() { track->DoPlay(); }
void BGSMusicTrackFormWrapper::DoPause() { track->DoPause(); }
void BGSMusicTrackFormWrapper::DoFinish(bool immediate, float fadeTime) { track->DoFinish(immediate, fadeTime); }
float BGSMusicTrackFormWrapper::GetDurationImpl() const { return track->GetDurationImpl(); }
std::uint32_t BGSMusicTrackFormWrapper::GetType() const { return track->GetType(); }
bool BGSMusicTrackFormWrapper::TestCanPlay() const { return track->TestCanPlay(); }
BSIMusicTrack::MusicStatus BGSMusicTrackFormWrapper::GetMusicStatus() const { return track->GetMusicStatus(); }

void BGSMusicTrackFormWrapper::DoSetDuckingAttenuation(std::uint16_t ducking) { track->DoSetDuckingAttenuation(ducking); }
void BGSMusicTrackFormWrapper::DoClearDucking() { track->DoClearDucking(); }
