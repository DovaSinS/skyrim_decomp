// Build: sse-steam-1-7-104
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: binary-analysis (independent RTTI and concrete stored-value boundary evidence).
// Drafted by GPT-6.1 Sol; typed layout recovery continuation.
// Labels: v2
// Code origin: original narrowed physical interface declarations and defaulted special members; no external implementation body or declaration reused.
// ICallableBase, ICopyableCallable: EXE_RTTI
// Unassessed invocation/copy/move method signatures are omitted, rather than invented.
// These ABI views claim storage and the selected deleting destructor only; original complete definitions and instantiability are unassessed.
// Exact primary RTTI slots bind each owner; concrete descendants independently pass their stored-value address at8 to invocation/copy operations.
// The fieldless primary interface prefix follows that member boundary and nonvirtual RTTI inheritance, not this destructor's deletion argument.
// Compiler-emitted vptr storage supplies the natural size. No explicit padding or capture-sized opaque array is introduced.
// Only the listed destructor is compared; constructor and unassessed operations remain outside the byte-match claim.
// Size and offset assertions are layout checks, not function passes or behavior claims.
// ErasedSignature1338d30CallableLayout: GUESS(medium) STANDIN
// Owner RTTI descriptor: .?AVICallableBase@?$FunctionImpl@UCopyable@attrib@detail@bnet_std@@$$A6AX$$QEAU?$CallbackParams@V?$UniquePtr@VListCollectionResponse@Mods@bnet@@@bnet@@VHttpResponseInfo@2@@bnet@@@Z@detail@bnet_std@@
#pragma once
#include "ErasedCallableVptrStorageLayout.h"
namespace ResearchLayouts {
class ErasedSignature1338d30CallableLayout {
public:
    ErasedSignature1338d30CallableLayout();
    virtual ~ErasedSignature1338d30CallableLayout() = default;
};
static_assert(sizeof(ErasedSignature1338d30CallableLayout) == sizeof(ErasedCallableVptrStorageLayout), "independently evidenced primary interface prefix");
}
