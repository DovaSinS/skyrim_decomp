// BSVMLoadTask, build sse-steam-1-7-104.
// Labels: v2
// RVA 0x1e7cb0, 30 bytes: BSVMLoadTask::GetDescription
// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESForm.cpp:827 (BSVMLoadTask::GetDescription)
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
// BSVMLoadTask, GetDescription: GUESS(low)
#include "BSVMLoadTask.h"
extern "C" __declspec(dllimport) int strcpy_s(char*, unsigned long long, const char*);
bool BSVMLoadTask::GetDescription(char* description, unsigned int size) const { strcpy_s(description, size, "VMLoadTask"); return true; }
