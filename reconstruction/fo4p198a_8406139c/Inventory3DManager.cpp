// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and community declarations.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x93ddd0, 37 bytes: Inventory3DManager::LoadInventoryItem
// names: GUESS(low); target call identity and function name remain unverified.
#include "Inventory3DManager.h"
void Inventory3DManager::LoadInventoryItem(InventoryEntryData* entry) { if (entry) LoadInventoryItem(entry->object, entry->extraLists ? entry->extraLists->item : nullptr); }
