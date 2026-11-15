// Build: sse-steam-1-7-104
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: binary-analysis (RTTI, invocation and complete construction/copy evidence).
// Drafted by GPT-6.1 Sol; p175 typed F012 pilot.
// Labels: v2
// Code origin: original typed function-pointer declaration and ordinary constructors/defaulted destructors; no external implementation body or declaration reused.
// bnet::LogParams, CallableBase, CopyableCallable, ICallableBase, ICopyableCallable: EXE_RTTI
// LogCallback, LogCallableInterfaceLayout, LogCopyableInterfaceLayout, LogFunctionCallableLayout, CopyableLogFunctionCallableLayout, callback, Invoke: GUESS(medium) STANDIN
// RTTI encodes a void function pointer taking a const reference to bnet::LogParams.
// An independently examined constructor allocates16 bytes, installs the owner table and stores that function pointer at8; dispatch tail-calls through that member.
// The field is a typed function pointer, not an opaque capture or a deletion-size filler.
// Virtual interface method sets are narrowed to the invocation contract; unassessed copy/move slots and implementation bodies are omitted.
// Only the scalar deleting destructor is compared; constructors, invocation implementation and complete original source identity remain unclaimed.
// Compiler alignment and typed members determine size; size assertions alone are not a function pass.
#pragma once
#include "LogCallableInterfaceLayout.h"
namespace ResearchLayouts {
class LogCopyableInterfaceLayout : public LogCallableInterfaceLayout {
public:
    LogCopyableInterfaceLayout();
    ~LogCopyableInterfaceLayout() override = default;
};
static_assert(sizeof(LogCopyableInterfaceLayout) == 8, "copy interface adds no storage");
}
