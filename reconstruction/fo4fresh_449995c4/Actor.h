// Actor declarations for build sse-steam-1-7-104.
// Labels: v2
// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: target listing and anonymous sibling hints.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// Actor, BGSInventoryItem, CalcArmorRating, GetArmorBaseFactorSum, GetWalkSpeed, GetRunSpeed, GetMovementSpeed, ActorMover, GetCurrentActorMover, IsPathing, TESObjectREFR, SetDelete, ProcessLists, processLists, AddActorToTempChangeList: GUESS(low)
#pragma once
class BGSInventoryItem;
class Actor;
class TESObjectREFR { public: void SetDelete(bool); };
class ProcessLists { public: void AddActorToTempChangeList(Actor*); };
extern ProcessLists* processLists;
class ActorMover { public: bool IsPathing() const; };
class Actor : public TESObjectREFR {
public:
    float CalcArmorRating(const BGSInventoryItem&, unsigned int) const;
    float GetArmorBaseFactorSum();
    float GetMovementSpeed(unsigned int, unsigned int) const;
    float GetWalkSpeed() const;
    float GetRunSpeed() const;
    ActorMover* GetCurrentActorMover() const;
    bool IsPathing() const;
    void SetDelete(bool);
};
