// QueuedPromoteReferencesTask, build sse-steam-1-7-104.
// Labels: v2
// RVA 0x204320, 15 bytes: QueuedPromoteReferencesTask::Finish
// RVA 0x204340, 21 bytes: QueuedPromoteReferencesTask::Cancel
// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/Misc/BGSDynamicPersistenceManager.cpp:47 (QueuedPromoteReferencesTask::Finish)
// Sibling source: fo4-private@1b765c70 src/Shared/Misc/BGSDynamicPersistenceManager.cpp:59 (QueuedPromoteReferencesTask::Cancel)
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
// QueuedPromoteReferencesTask, Finish, Cancel, BGSDynamicPersistenceManager, instance, RemoveTask, state: GUESS(low)
#include "QueuedPromoteReferencesTask.h"
void QueuedPromoteReferencesTask::Finish() { BGSDynamicPersistenceManager::instance->RemoveTask(this); }
void QueuedPromoteReferencesTask::Cancel(int state, void*) { if (state != 5) BGSDynamicPersistenceManager::instance->RemoveTask(this); }
