// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ActiveEffect, ActiveEffect::hitEffects, ActiveEffect::ForEachHitEffectVisitor, ForEachHitEffectVisitor::operator(): COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ActiveEffect::ForEachHitEffect: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(fo4-pdb); the visitor reference parameter follows the FO4 prototype
// BSContainer::ForEachResult, kStop, kContinue, ReferenceEffect: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SimpleListNode, SimpleListNode::item, SimpleListNode::next: GUESS(low) STANDIN; the BSSimpleList node layout read from the listing, an item then a next pointer
// ActiveEffect::padding00: GUESS(low); padding for the members this function does not touch
#pragma once

#include <cstdint>

class ReferenceEffect;

namespace BSContainer
{
    enum class ForEachResult
    {
        kStop = 0,
        kContinue = 1
    };
}

struct SimpleListNode
{
    ReferenceEffect* item;  // 00
    SimpleListNode* next;   // 08
};

class ActiveEffect
{
public:
    class ForEachHitEffectVisitor
    {
    public:
        virtual ~ForEachHitEffectVisitor();                                          // 00
        virtual BSContainer::ForEachResult operator()(ReferenceEffect* a_hitEffect) = 0;  // 01
    };

    void ForEachHitEffect(ForEachHitEffectVisitor& a_visitor);

    std::uint8_t padding00[0x60];   // 00
    SimpleListNode* hitEffects;     // 60
};
static_assert(sizeof(ActiveEffect) == 0x68, "ActiveEffect view size");
