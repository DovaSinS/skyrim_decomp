// BGSScene, build sse-steam-1-7-104.
// Labels: v2
// Origin: adapted declarations from CommonLibSSE-NG, MIT, b93280e832f263dbef44e44cbe2936622a02f91a.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// BGSScene: EXE_RTTI
// Compared functions:
// RVA 0x3a8980, 38 bytes: BGSScene::Function3a8980.
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
#include <cstdint>
// BGSScene, TESForm, BaseFormComponent, TESFileContainer, TESFileArray, BSTArray, BGSScenePhase, BGSSceneAction, phases, actors, actorFlags, actorProgressionFlags, actions: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Function3a8980, SceneVisitor, Apply, scene, arg, value: GUESS(low)
class TESFileArray; class BGSScenePhase; class BGSSceneAction;
enum class SCENE_ACTOR_FLAG : std::uint32_t;
enum class FormType : std::uint8_t;
namespace stl { template<class E, class T> struct enumeration { T value; }; }
struct TESFileContainer { TESFileArray* array; };
class BaseFormComponent { public: virtual ~BaseFormComponent(); };
class TESForm : public BaseFormComponent {
public:
 enum class InGameFormFlag : std::uint16_t;
 TESFileContainer sourceFiles;
 std::uint32_t formFlags, formID;
 stl::enumeration<InGameFormFlag, std::uint16_t> inGameFormFlags;
 stl::enumeration<FormType, std::uint8_t> formType;
 std::uint8_t pad1B;
 std::uint32_t pad1C;
};
struct SceneVisitor;
struct BSTArrayHeapAllocator { void* data; std::uint32_t capacity; };
struct BSTArrayBase { std::uint32_t size; };
template<class T> class BSTArray : public BSTArrayHeapAllocator, public BSTArrayBase { public: void Apply(SceneVisitor* visitor); };
class BGSScene : public TESForm {
public:
 enum class BehaviourFlag : std::uint32_t;
 void Function3a8980(void* arg, std::uint32_t value);
 BSTArray<BGSScenePhase*> phases;
 BSTArray<std::uint32_t> actors;
 BSTArray<stl::enumeration<SCENE_ACTOR_FLAG, std::uint32_t>> actorFlags;
 BSTArray<stl::enumeration<BehaviourFlag, std::uint32_t>> actorProgressionFlags;
 BSTArray<BGSSceneAction*> actions;
};
struct SceneVisitor { BGSScene* scene; void* arg; std::uint32_t value; };
