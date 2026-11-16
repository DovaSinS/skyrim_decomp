// Build: sse-steam-1-7-104
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (pinned community reference-count/movement-interface storage, independent target construction/RTTI/slot analysis).
// Drafted by GPT-6.1 Sol; shared MovementAgent primary-storage prefix reuse.
// Labels: v2
// Code origin: original explicitly narrowed owner/interface views and defaulted construction, reusing the represented community-backed MovementAgent storage. No external implementation body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/B/BSIntrusiveRefCounted.h and include/RE/I/{IMovementInterface,IMovementState}.h; MIT.
// BSIntrusiveRefCounted, IMovementInterface, IMovementState, _refCount: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// MovementAgent, IPipelineStageInterface: EXE_RTTI
// MovementVptrContractLayout, Identity, all owner names ending InterfacePrefixLayout and their StorageLayout mirrors: GUESS(medium) STANDIN
// The primary24-byte MovementAgent storage is independently supported by constructor writes at8 and16 and the NullMovementState object RTTI; see its included declaration.
// Each following represented contract is the actual target's eight-byte vptr prefix at a nonvirtual subobject start. The Identity tag only distinguishes those RTTI-bound subobjects; it introduces no storage or runtime value.
// Fieldless interface ancestry is flattened; unassessed methods, any data beyond represented contract prefixes and all owner suffixes are omitted. Whole owner sizes, complete original definitions, instantiability and behavior remain unclaimed.
// Independent target COLs place every represented secondary table consecutively at24+8*n; each selected slot0 points to an adjustor with the same owner/primary target.
// The declaration introduces no byte arrays, padding or emission attributes. All sizes follow the known primary fields and represented vptr contracts; deletion-size arguments are not used.
// Only listed ordinary compiler-emitted secondary destructor adjustors are compared. Constructor, primary destruction and movement behavior are outside the byte-match claim.
// Layout size/offset assertions are not function passes or original-source identity claims.
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
// RVA 0x121f918; 9 bytes
// RVA 0x121f924; 9 bytes
// RVA 0x121f930; 9 bytes
// RVA 0x11caf20; 9 bytes
// RVA 0x11caf2c; 9 bytes
// RVA 0x11caf38; 9 bytes
// RVA 0x1229670; 9 bytes
// RVA 0x122967c; 9 bytes
// RVA 0x1229688; 9 bytes
// RVA 0x1229694; 9 bytes
// RVA 0x122abfc; 9 bytes
// RVA 0x122ac08; 9 bytes
// RVA 0x122ac14; 9 bytes
// RVA 0x122ac20; 9 bytes
// RVA 0x122406c; 9 bytes
// RVA 0x122b3dc; 9 bytes
// RVA 0x122bccc; 9 bytes
// RVA 0x122c34c; 9 bytes
// RVA 0x7a373c; 9 bytes
// RVA 0x122c8bc; 9 bytes
// RVA 0x122d1ac; 9 bytes
// RVA 0x7a4d2c; 9 bytes
// RVA 0x7a4d38; 9 bytes
// RVA 0x7a588c; 9 bytes
// RVA 0x122bfdc; 9 bytes
// RVA 0x7a63d0; 9 bytes
// RVA 0x7a63dc; 9 bytes
// RVA 0x7a68cc; 9 bytes
// RVA 0x122cccc; 9 bytes
// RVA 0x1221bbc; 9 bytes
// RVA 0x1221bc8; 9 bytes
// RVA 0x11d5978; 9 bytes
// RVA 0x12303e8; 9 bytes
// RVA 0x1227a5c; 9 bytes
// RVA 0x121d2cc; 9 bytes
// RVA 0x121d2d8; 9 bytes
// RVA 0x121d2e4; 9 bytes
// RVA 0x1226aa0; 9 bytes
// RVA 0x7a7d0c; 9 bytes
// RVA 0x7a820c; 9 bytes
// RVA 0x7a8d88; 9 bytes
// RVA 0x7a8d94; 9 bytes
// RVA 0x122ec7c; 9 bytes
// RVA 0x122ec88; 9 bytes
// RVA 0x7aa814; 9 bytes
// RVA 0x7aa820; 9 bytes
// RVA 0x1234a6c; 9 bytes
// RVA 0x1233dac; 9 bytes
// RVA 0x1232ce0; 9 bytes
// RVA 0x7ab20c; 9 bytes
// RVA 0x122329c; 9 bytes
// RVA 0x12232a8; 9 bytes
// RVA 0x7ab9b0; 9 bytes
// RVA 0x7ab9bc; 9 bytes
#include "MovementVptrContractLayout.h"
namespace ResearchLayouts {
MovementAgentActorAvoiderInterfacePrefixLayout::MovementAgentActorAvoiderInterfacePrefixLayout() = default;
MovementAgentActorStateInterfacePrefixLayout::MovementAgentActorStateInterfacePrefixLayout() = default;
MovementAgentPathFollowerFlightInterfacePrefixLayout::MovementAgentPathFollowerFlightInterfacePrefixLayout() = default;
MovementAgentPathFollowerVirtualInterfacePrefixLayout::MovementAgentPathFollowerVirtualInterfacePrefixLayout() = default;
MovementHandlerAgentInterfacePrefixLayout::MovementHandlerAgentInterfacePrefixLayout() = default;
MovementHandlerAgentAngleControllerInterfacePrefixLayout::MovementHandlerAgentAngleControllerInterfacePrefixLayout() = default;
MovementHandlerAgentAngleGainInterfacePrefixLayout::MovementHandlerAgentAngleGainInterfacePrefixLayout() = default;
MovementHandlerAgentAnglePassThroughInterfacePrefixLayout::MovementHandlerAgentAnglePassThroughInterfacePrefixLayout() = default;
MovementHandlerAgentDirectControlInterfacePrefixLayout::MovementHandlerAgentDirectControlInterfacePrefixLayout() = default;
MovementHandlerAgentDirectionPassThroughInterfacePrefixLayout::MovementHandlerAgentDirectionPassThroughInterfacePrefixLayout() = default;
MovementHandlerAgentLargeDeltaIdleInterfacePrefixLayout::MovementHandlerAgentLargeDeltaIdleInterfacePrefixLayout() = default;
MovementHandlerAgentPlayerControlsInterfacePrefixLayout::MovementHandlerAgentPlayerControlsInterfacePrefixLayout() = default;
MovementHandlerAgentPlayerControlsActionTriggerInterfacePrefixLayout::MovementHandlerAgentPlayerControlsActionTriggerInterfacePrefixLayout() = default;
MovementHandlerAgentSpeedPassThroughInterfacePrefixLayout::MovementHandlerAgentSpeedPassThroughInterfacePrefixLayout() = default;
MovementHandlerAgentSprintActionTriggerInterfacePrefixLayout::MovementHandlerAgentSprintActionTriggerInterfacePrefixLayout() = default;
MovementHandlerAgentStairsHelperInterfacePrefixLayout::MovementHandlerAgentStairsHelperInterfacePrefixLayout() = default;
MovementHandlerAgentStrafingInterfacePrefixLayout::MovementHandlerAgentStrafingInterfacePrefixLayout() = default;
MovementHandlerAgentTranslationControllerInterfacePrefixLayout::MovementHandlerAgentTranslationControllerInterfacePrefixLayout() = default;
MovementPathManagerAgentInterfacePrefixLayout::MovementPathManagerAgentInterfacePrefixLayout() = default;
MovementPathManagerAgentAvoidBoxInterfacePrefixLayout::MovementPathManagerAgentAvoidBoxInterfacePrefixLayout() = default;
MovementPathManagerAgentLoadedAreaMonitorInterfacePrefixLayout::MovementPathManagerAgentLoadedAreaMonitorInterfacePrefixLayout() = default;
MovementPathManagerAgentStaticAvoiderInterfacePrefixLayout::MovementPathManagerAgentStaticAvoiderInterfacePrefixLayout() = default;
MovementPlannerAgentInterfacePrefixLayout::MovementPlannerAgentInterfacePrefixLayout() = default;
MovementPlannerAgentDirectControlInterfacePrefixLayout::MovementPlannerAgentDirectControlInterfacePrefixLayout() = default;
MovementPlannerAgentHorseControlsInterfacePrefixLayout::MovementPlannerAgentHorseControlsInterfacePrefixLayout() = default;
MovementPlannerAgentKeepOffsetInterfacePrefixLayout::MovementPlannerAgentKeepOffsetInterfacePrefixLayout() = default;
MovementPlannerAgentNavmeshBoundsInterfacePrefixLayout::MovementPlannerAgentNavmeshBoundsInterfacePrefixLayout() = default;
MovementPlannerAgentWarpInterfacePrefixLayout::MovementPlannerAgentWarpInterfacePrefixLayout() = default;
MovementStateFollowPathInterfacePrefixLayout::MovementStateFollowPathInterfacePrefixLayout() = default;
MovementStateTweenerInterfacePrefixLayout::MovementStateTweenerInterfacePrefixLayout() = default;
MovementTweenerAgentInterfacePrefixLayout::MovementTweenerAgentInterfacePrefixLayout() = default;
MovementTweenerAgentAnimationDrivenInterfacePrefixLayout::MovementTweenerAgentAnimationDrivenInterfacePrefixLayout() = default;
MovementTweenerAgentFixedDeltaInterfacePrefixLayout::MovementTweenerAgentFixedDeltaInterfacePrefixLayout() = default;
MovementTweenerAgentNodeFollowerInterfacePrefixLayout::MovementTweenerAgentNodeFollowerInterfacePrefixLayout() = default;
}
