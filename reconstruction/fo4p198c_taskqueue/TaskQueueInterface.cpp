// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed (local target analysis and permitted sibling).
// Origin: independently reconstructed from target and sibling hints.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// names: GUESS(low); signatures and type names are hypotheses.
// RVA 0x669110, 43 bytes; RVA 0x668fd0, 44 bytes; RVA 0x6695d0, 46 bytes.
// TaskQueueInterface::QueueForceWeather: SIBLING(fo4-private@1b765c70, author-permission); adapted task construction.
// TaskQueueInterface::QueueRemoveSpell: SIBLING(fo4-private@1b765c70, author-permission); adapted task construction.
// TaskQueueInterface::QueueActorDisarm: SIBLING(fo4-private@1b765c70, author-permission); adapted task construction.
// Sibling source: fo4-private@1b765c70 src/Game/Misc/TaskQueueInterface.cpp:1134
// Sibling source: fo4-private@1b765c70 src/Game/Misc/TaskQueueInterface.cpp:1022
// Sibling source: fo4-private@1b765c70 src/Game/Misc/TaskQueueInterface.cpp:1476
#include "TaskQueueInterface.h"
void TaskQueueInterface::QueueForceWeather(TESWeather* weather, bool overrideWeather) {
    BSPackedTask task;
    task.data[0].integer = 0x40;
    task.data[1].pointer = weather;
    task.data[2].boolean = overrideWeather;
    QueueIfActive(task);
}
void TaskQueueInterface::QueueRemoveSpell(ActorHandle& target, SpellItem* spell) {
    BSPackedTask task;
    task.data[0].integer = 0x5d;
    task.data[1].integer = target.bits;
    task.data[2].pointer = spell;
    QueueIfActive(task);
}
void TaskQueueInterface::QueueActorDisarm(ActorHandle& target, ActorHandle& attacker) {
    BSPackedTask task;
    task.data[1].integer = target.bits;
    task.data[2].integer = attacker.bits;
    task.data[0].integer = 0x5b;
    QueueIfActive(task);
}
