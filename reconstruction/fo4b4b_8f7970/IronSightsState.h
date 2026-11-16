// Build: sse-steam-1-7-104; RVA 0x8f7970; 35 bytes
// Labels: v2
// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// IronSightsState::GetRotation: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/IronSightsState.cpp:37
// TESCameraState, NiAVObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/T/TESCameraState.h, include/RE/N/NiAVObject.h, include/RE/N/NiObjectNET.h, include/RE/N/NiRefObject.h and include/RE/N/NiTransform.h.
// names: GUESS(low); names and original signatures are tentative.
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
struct NiMatrix3 { float entries[3][3]; }; struct NiPoint3 { float x,y,z; }; struct NiTransform { NiMatrix3 rotation; NiPoint3 translation; float scale; };
class NiRefObject { public: virtual ~NiRefObject(); unsigned refCount, pad; };
class NiObject : public NiRefObject {};
class NiObjectNET : public NiObject { public: const char* name; void* controllers; void** extra; unsigned short extraDataSize, maxSize; unsigned pad; };
class NiAVObject : public NiObjectNET { public: void* parent; unsigned parentIndex, unknown; void* collision; NiTransform local, world; };
class NiQuaternion { public: float w,x,y,z; void FromRotation(const NiMatrix3&); };
extern const NiQuaternion identityQuaternion;
class TESCameraState { public: virtual ~TESCameraState(); unsigned refCount, pad; void* camera; unsigned id, pad2; };
class IronSightsState : public TESCameraState { public: NiAVObject* cameraObject; void GetRotation(NiQuaternion&) const; };
