// Build: sse-steam-1-7-104
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (pinned community intrusive-reference and movement-interface declarations; independent target RTTI/construction/slot analysis).
// Drafted by GPT-6.1 Sol; shared movement-agent primary storage and interface-prefix recovery.
// Labels: v2
// Code origin: adapted field/interface declarations and original narrowed prefix construction; no external implementation body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/B/BSIntrusiveRefCounted.h and include/RE/I/{IMovementInterface,IMovementState}.h; MIT.
// BSIntrusiveRefCounted, _refCount, IMovementInterface, IMovementState: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// MovementAgent, MovementAgentPathFollowerStandard, IPipelineStageInterface, IMovementPlannerAgent, IMovementPathManagerAgent, IMovementQueryPathFollowing, IMovementSetPathFollowing, IMovementPlayIdleResult, IMovementHandlerAgent, NullMovementState: EXE_RTTI
// MovementAgentStoragePrefixLayout, MovementInterfacePrefixLayout, MovementStatePrefixLayout, PipelineStagePrefixLayout, MovementPlannerPrefixLayout, MovementPathManagerPrefixLayout, MovementQueryPathFollowingPrefixLayout, MovementSetPathFollowingPrefixLayout, MovementIdleResultPrefixLayout, MovementHandlerPrefixLayout, MovementAgentPathFollowerStandardPrefixLayout, MovementAgentPathFollowerStandardPrefixStorageLayout, state: GUESS(medium) STANDIN
// Target base construction writes the intrusive refcount at8 and a pointer at16 to a static object whose RTTI is NullMovementState and derives IMovementState at0.
// These independently observed fields and normal pointer alignment produce the24-byte primary storage prefix; the target's next direct interface starts at24. No deletion-size argument supplies a field or size.
// The natural gap at12..15 is unassessed and is not claimed to be original padding. Only known fields are represented.
// Target RTTI independently places the six following nonvirtual interfaces at24/32/40/48/56/64; each representation contains only its vptr prefix and known interface inheritance.
// All unassessed interface methods/data and owner-specific fields beyond this72-byte prefix are omitted. Original complete definitions, instantiability, lifetime behavior and whole-owner size are unclaimed.
// Only listed ordinary compiler-emitted secondary deleting-destructor adjustors are compared. Constructor, primary destruction and movement/state behavior are outside the byte-match claim.
// No explicit padding, byte array, helper body or emission attribute is introduced. Size/offset agreement is a layout check, not a function pass.
// MIT License
// 
// Copyright (c) 2018 Ryan-rsm-McKenzie
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
#pragma once
#include <cstddef>
#include <cstdint>
#include "BSIntrusiveRefCountedStorageLayout.h"
namespace ResearchLayouts {
class MovementInterfacePrefixLayout { public: virtual ~MovementInterfacePrefixLayout(); };
class MovementStatePrefixLayout : public MovementInterfacePrefixLayout { public: ~MovementStatePrefixLayout() override; };
class MovementAgentStoragePrefixLayout : public BSIntrusiveRefCountedStorageLayout {
public:
    virtual ~MovementAgentStoragePrefixLayout();
    MovementStatePrefixLayout* state;
};
class PipelineStagePrefixLayout { public: virtual ~PipelineStagePrefixLayout(); };
class MovementPlannerPrefixLayout : public PipelineStagePrefixLayout { public: ~MovementPlannerPrefixLayout() override; };
class MovementPathManagerPrefixLayout : public PipelineStagePrefixLayout { public: ~MovementPathManagerPrefixLayout() override; };
class MovementQueryPathFollowingPrefixLayout : public MovementInterfacePrefixLayout { public: ~MovementQueryPathFollowingPrefixLayout() override; };
class MovementSetPathFollowingPrefixLayout : public MovementInterfacePrefixLayout { public: ~MovementSetPathFollowingPrefixLayout() override; };
class MovementIdleResultPrefixLayout { public: virtual ~MovementIdleResultPrefixLayout(); };
class MovementHandlerPrefixLayout : public PipelineStagePrefixLayout { public: ~MovementHandlerPrefixLayout() override; };
class MovementAgentPathFollowerStandardPrefixLayout : public MovementAgentStoragePrefixLayout, public MovementPlannerPrefixLayout, public MovementPathManagerPrefixLayout, public MovementQueryPathFollowingPrefixLayout, public MovementSetPathFollowingPrefixLayout, public MovementIdleResultPrefixLayout, public MovementHandlerPrefixLayout {
public:
    MovementAgentPathFollowerStandardPrefixLayout();
    ~MovementAgentPathFollowerStandardPrefixLayout() override;
};
struct MovementAgentPathFollowerStandardPrefixStorageLayout {
    const void* const* primary;
    volatile std::uint32_t refCount;
    MovementStatePrefixLayout* state;
    const void* const* planner;
    const void* const* pathManager;
    const void* const* queryPath;
    const void* const* setPath;
    const void* const* idleResult;
    const void* const* handler;
};
static_assert(sizeof(MovementInterfacePrefixLayout) == 8, "represented observed storage/interface prefix");
static_assert(sizeof(MovementStatePrefixLayout) == 8, "represented observed storage/interface prefix");
static_assert(sizeof(MovementAgentStoragePrefixLayout) == 24, "represented observed storage/interface prefix");
static_assert(sizeof(PipelineStagePrefixLayout) == 8, "represented observed storage/interface prefix");
static_assert(sizeof(MovementPlannerPrefixLayout) == 8, "represented observed storage/interface prefix");
static_assert(sizeof(MovementPathManagerPrefixLayout) == 8, "represented observed storage/interface prefix");
static_assert(sizeof(MovementQueryPathFollowingPrefixLayout) == 8, "represented observed storage/interface prefix");
static_assert(sizeof(MovementSetPathFollowingPrefixLayout) == 8, "represented observed storage/interface prefix");
static_assert(sizeof(MovementIdleResultPrefixLayout) == 8, "represented observed storage/interface prefix");
static_assert(sizeof(MovementHandlerPrefixLayout) == 8, "represented observed storage/interface prefix");
static_assert(sizeof(MovementAgentPathFollowerStandardPrefixLayout) == 72, "represented observed storage/interface prefix");
static_assert(sizeof(MovementAgentPathFollowerStandardPrefixStorageLayout) == 72, "represented observed storage/interface prefix");
static_assert(offsetof(MovementAgentStoragePrefixLayout, _refCount) == 8, "independent target field/subobject offset");
static_assert(offsetof(MovementAgentStoragePrefixLayout, state) == 16, "independent target field/subobject offset");
static_assert(offsetof(MovementAgentPathFollowerStandardPrefixStorageLayout, primary) == 0, "independent target field/subobject offset");
static_assert(offsetof(MovementAgentPathFollowerStandardPrefixStorageLayout, refCount) == 8, "independent target field/subobject offset");
static_assert(offsetof(MovementAgentPathFollowerStandardPrefixStorageLayout, state) == 16, "independent target field/subobject offset");
static_assert(offsetof(MovementAgentPathFollowerStandardPrefixStorageLayout, planner) == 24, "independent target field/subobject offset");
static_assert(offsetof(MovementAgentPathFollowerStandardPrefixStorageLayout, pathManager) == 32, "independent target field/subobject offset");
static_assert(offsetof(MovementAgentPathFollowerStandardPrefixStorageLayout, queryPath) == 40, "independent target field/subobject offset");
static_assert(offsetof(MovementAgentPathFollowerStandardPrefixStorageLayout, setPath) == 48, "independent target field/subobject offset");
static_assert(offsetof(MovementAgentPathFollowerStandardPrefixStorageLayout, idleResult) == 56, "independent target field/subobject offset");
static_assert(offsetof(MovementAgentPathFollowerStandardPrefixStorageLayout, handler) == 64, "independent target field/subobject offset");
}
