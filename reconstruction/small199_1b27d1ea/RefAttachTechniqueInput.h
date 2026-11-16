// RefAttachTechniqueInput, build sse-steam-1-7-104.
// Labels: v2
// Inferred names: GUESS(low)
// Origin: declarations adapted from CommonLibSSE-NG b93280e, MIT; body original reconstruction.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// Compared functions:
// RVA 0x5d8790, 31 bytes: RefAttachTechniqueInput::sub.
// MIT License
// Copyright (c) 2018 Ryan-rsm-McKenzie
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// RefAttachTechniqueInput, BSFixedString, AttachTechniqueInput: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// actor, actorRace, physicsWorld, collisionFilter, pad3C, nodeName, current3DRoot, attachedArt, attachPoint: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Cleanup, ReleaseString, CleanupBase: GUESS(low); function and callee semantics inferred
#pragma once
#include <cstdint>
class NiNode; class TESObjectREFR; class TESRace; class bhkWorld;
class BSFixedString { public: void ReleaseString(); const char* data; };
namespace BSAttachTechniques { class AttachTechniqueInput { public: virtual ~AttachTechniqueInput(); virtual void Clear(); void CleanupBase(); NiNode* current3DRoot; NiNode* attachedArt; std::uint32_t attachPoint; std::uint32_t pad18; }; }
class RefAttachTechniqueInput : public BSAttachTechniques::AttachTechniqueInput { public: void Cleanup(); TESObjectREFR* actor; TESRace* actorRace; bhkWorld* physicsWorld; std::uint32_t collisionFilter; std::uint32_t pad3C; BSFixedString nodeName; };
