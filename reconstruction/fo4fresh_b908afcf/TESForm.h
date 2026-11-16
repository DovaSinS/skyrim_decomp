// TESForm, build sse-steam-1-7-104.
// Labels: v2
// RVA 0x1e56b0, 27 bytes: TESForm::RemoveChange
// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESForm.cpp:766 (TESForm::RemoveChange)
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
// TESForm, RemoveChange: GUESS(low)
#pragma once
// SaveLoadGame, saveLoad, RemoveChange, flags: GUESS(low)
class TESForm;
class SaveLoadGame { public: void RemoveChange(TESForm*, int); };
extern SaveLoadGame* saveLoad;
class TESForm { public: void RemoveChange(int flags); };
