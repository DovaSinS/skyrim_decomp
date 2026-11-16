// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed (local target analysis and permitted sibling).
// Origin: independently reconstructed from target and sibling hints.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// names: GUESS(low); signatures and type names are hypotheses.
// TaskQueueInterface::QueueForceWeather: SIBLING(fo4-private@1b765c70, author-permission); adapted task construction.
// TaskQueueInterface::QueueRemoveSpell: SIBLING(fo4-private@1b765c70, author-permission); adapted task construction.
// TaskQueueInterface::QueueActorDisarm: SIBLING(fo4-private@1b765c70, author-permission); adapted task construction.
// Sibling source: fo4-private@1b765c70 src/Game/Misc/TaskQueueInterface.cpp:1134
// Sibling source: fo4-private@1b765c70 src/Game/Misc/TaskQueueInterface.cpp:1022
// Sibling source: fo4-private@1b765c70 src/Game/Misc/TaskQueueInterface.cpp:1476
#pragma once
#include <cstdint>
class TESWeather;
class SpellItem;
struct ActorHandle { std::uint32_t bits; };
union PackedTaskData { std::uint32_t integer; void* pointer; bool boolean; };
struct BSPackedTask { PackedTaskData data[16]; };
class TaskQueueInterface {
public:
    void QueueIfActive(BSPackedTask& task);
    void QueueForceWeather(TESWeather* weather, bool overrideWeather);
    void QueueRemoveSpell(ActorHandle& target, SpellItem* spell);
    void QueueActorDisarm(ActorHandle& target, ActorHandle& attacker);
};
