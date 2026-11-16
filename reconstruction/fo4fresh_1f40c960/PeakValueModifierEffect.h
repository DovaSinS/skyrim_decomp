// PeakValueModifierEffect declarations for build sse-steam-1-7-104.
// Labels: v2
// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: target listing and anonymous sibling hints.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// PeakValueModifierEffect, ActiveEffect, ValueModifierEffect, MagicTarget, BGSLoadFormBuffer, OnAdd, FinishLoadGame, FindListPosition: GUESS(low)
#pragma once
class MagicTarget;
class BGSLoadFormBuffer;
class ActiveEffect { public: void FinishLoadGame(BGSLoadFormBuffer*); };
class ValueModifierEffect : public ActiveEffect { public: void OnAdd(MagicTarget*); };
class PeakValueModifierEffect : public ValueModifierEffect {
public:
    void OnAdd(MagicTarget*);
    void FinishLoadGame(BGSLoadFormBuffer*);
    void FindListPosition();
};
