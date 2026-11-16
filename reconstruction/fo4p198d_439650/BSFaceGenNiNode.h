// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: independently decoded target and anonymous sibling; declarations adapted from community headers.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// Declarations: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); adapted from include/RE/B/BSFaceGenNiNode.h, include/RE/N/NiNode.h, include/RE/N/NiAVObject.h, include/RE/N/NiObjectNET.h, include/RE/N/NiRefObject.h, include/RE/N/NiTArray.h, include/RE/N/NiTransform.h and include/RE/N/NiBound.h.
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
// names: GUESS(low); signatures and helper identities require review.
#pragma once
struct NiPoint3 { float x,y,z; }; struct NiMatrix3 { float entry[3][3]; }; struct NiTransform { NiMatrix3 rotate; NiPoint3 translate; float scale; }; struct NiBound { NiPoint3 center; float radius; };
class NiTimeController; class NiExtraData; class NiCollisionObject; class TESObjectREFR; class NiUpdateData; class NiNode;
class NiRefObject { public: virtual ~NiRefObject(); unsigned refCount; };
class NiObject : public NiRefObject {};
class NiObjectNET : public NiObject { public: const char* name; NiTimeController* controllers; NiExtraData** extra; unsigned short extraDataSize, maxSize; unsigned pad; };
class NiAVObject : public NiObjectNET { public: NiNode* parent; unsigned parentIndex, unknown; NiCollisionObject* collision; NiTransform local, world, previousWorld; NiBound worldBound; unsigned flags; TESObjectREFR* userData; float fadeAmount; unsigned lastUpdatedFrameCounter; unsigned char unknown108, flags02; unsigned short unknown10A; unsigned pad10C; };
template<class T> class NiTObjectArray { public: virtual ~NiTObjectArray(); T* data; unsigned short capacity, freeIndex, size, growthSize; };
class NiNode : public NiAVObject { public: void UpdateDownwardPass(NiUpdateData&, unsigned); NiTObjectArray<NiAVObject*> children; };
class BSFaceGenNiNode : public NiNode { public: void UpdateMorphing(NiUpdateData&); void UpdateDownwardPass(NiUpdateData&, unsigned); };
