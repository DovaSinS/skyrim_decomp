// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// BGSCollisionLayer::ClearData: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSCollisionLayer.cpp:143
// BGSCollisionLayer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/B/BGSCollisionLayer.h, include/RE/T/TESForm.h, include/RE/T/TESDescription.h and include/RE/B/BSTArray.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x31aa10 BGSCollisionLayer::ClearData
// Code origin: Original reconstruction from the pinned image listing and labelled community declarations; existing bodies retained.
// 0x31aa50 BGSCollisionLayer::GetCollidesWithMask
// Adapted bodies: ClearData retains the labelled author-permitted sibling adaptation.
#include "BGSCollisionLayer.h"

void BGSCollisionLayer::ClearData() { collidesWith.Clear(); }

// Accumulate one collision bit for each linked layer.
std::uint64_t BGSCollisionLayer::GetCollidesWithMask() const
{
    std::uint64_t mask = 0;
    if (collidesWith.size != 0) {
        BGSCollisionLayer* const* current = collidesWith.data;
        std::size_t remaining = collidesWith.size;
        do {
            mask |= std::int64_t{1} << (*current++)->collisionIdx;
        } while (--remaining != 0);
    }
    return mask;
}
