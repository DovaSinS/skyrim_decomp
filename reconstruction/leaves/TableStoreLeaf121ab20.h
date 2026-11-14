// Build: sse-steam-1-7-104; RVA 0x121ab20; 11 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: binary-analysis
// Drafted by tools/table_store_template_v1.py (GPT-6.1 Sol).
// Labels: v2
// TableStoreLeaf121ab20, TableStoreLeaf121ab20::~TableStoreLeaf121ab20: GUESS(low) STANDIN
// The stored table is bound through its primary RTTI complete object locator.
// Represented layout: the compiler-managed primary virtual pointer only.
// Other members, bases, total object size and original destructor role are unknown.
// No opaque storage or size-forcing declaration; no full-layout claim is made.
// This empty virtual destructor is an ABI stand-in for the compared table store.
// No external implementation is copied; a pass proves code, not names or behaviour.
// Origin: {"family": "primary-table-store-leaf", "template_digest": "73beeb645c4644918c4a046efd6fcc3aa3d66c23bacf9b075324d91aacbc6c1c", "version": "1"}
#pragma once
class TableStoreLeaf121ab20 {
public:
    virtual ~TableStoreLeaf121ab20();
};
