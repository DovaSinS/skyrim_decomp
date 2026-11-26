// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/o2-fpfast-noeh-root-includes.json
// 0xb5a190 hkpWorld::getClosestPoints
// Adapted bodies: none
#include "hkpWorld_b5a190.h"

namespace
{
    // one pair: skip the body itself and filtered pairs, then call the closest-point function of the two shape types
    // forced inline: the image has this step inlined in all three loops
    __forceinline void collide(const hkpWorld* a_world, const hkpCollidable* a_collidable, const hkpCollidable* a_other, const CollisionInput* a_input,
        void* a_collector, int a_typeA)
    {
        if (a_collidable != a_other && a_world->collisionFilter->filter.isCollisionEnabled(*a_collidable, *a_other) && a_other->shape) {
            const std::uint8_t agent = a_input->dispatcher->agent2Types[a_typeA][a_other->shape->type];
            a_input->dispatcher->agentFunctions[agent].getClosestPoints(a_collidable, a_other, a_input, a_collector);
        }
    }
}

// find everything near the collidable (broad phase or the trees) and report the closest points to the collector
void hkpWorld::getClosestPoints(const hkpCollidable* a_collidable, const CollisionInput* a_input, void* a_collector) noexcept
{
    hkAabb aabb;
    a_collidable->shape->getAabb(a_collidable->motion, a_input->tolerance - collisionInput->tolerance * 0.5f, &aabb);

    if (!kdTreeManager || !kdTreeManager->hasTrees()) {
        hkTimerBeginList("LthkpWorld::getClosestPoints(Broadphase)", "St3AxisBp");
        hkInplaceArray<BroadPhaseHandlePair, 128> hits;
        broadPhase->querySingleAabb(aabb, &hits);
        const BroadPhaseHandlePair* pair = hits.data;
        const int typeA = a_collidable->shape->type;
        hkTimerSplitList("St3AxisNp");
        for (int i = hits.size - 1; i >= 0; --i) {
            // a broad phase handle stores its own offset inside the collidable that owns it
            const auto* other = reinterpret_cast<const hkpCollidable*>(reinterpret_cast<const char*>(pair->b) + pair->b->ownerOffset);
            collide(this, a_collidable, other, a_input, a_collector, typeA);
            ++pair;
        }
        hkTimerEndList();
    } else {
        hkTimerBeginList("LthkpWorld::getClosestPoints(Trees)", "StAabbTreeBp");
        void* aabbTree = kdTreeManager->aabbTree;
        void* kdTree = kdTreeManager->kdTree;
        if (aabbTree) {
            hkInplaceArray<const hkpCollidable*, 128> hits;
            g_aabbTreeQueryAabb(aabbTree, &aabb, &hits);
            hkTimerSplitList("StAabbTreeNp");
            const int typeA = a_collidable->shape->type;
            for (int i = 0; i < hits.size; ++i) {
                collide(this, a_collidable, hits.data[i], a_input, a_collector, typeA);
            }
        }
        if (kdTree) {
            hkTimerSplitList("StKdTreeBp");
            hkTempArray<const hkpCollidable*> hits;
            g_kdTreeQueryAabb(kdTree, &aabb, &hits);
            hkTimerSplitList("StKdTreeNp");
            const int typeA = a_collidable->shape->type;
            for (int i = 0; i < hits.size; ++i) {
                collide(this, a_collidable, hits.data[i], a_input, a_collector, typeA);
            }
        }
        hkTimerEndList();
    }
}
