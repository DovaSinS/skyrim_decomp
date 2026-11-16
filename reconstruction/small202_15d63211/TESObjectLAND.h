// TESObjectLAND, build sse-steam-1-7-104.
// Labels: v2
// Origin: adapted declarations from CommonLibSSE-NG, MIT, b93280e832f263dbef44e44cbe2936622a02f91a.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// TESObjectLAND: EXE_RTTI
// Compared functions:
// RVA 0x2ab510, 46 bytes: TESObjectLAND::Function2ab510.
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
// TESObjectLAND, TESForm, TESChildCell, BaseFormComponent, TESFileContainer, LoadedLandData, OBJ_LAND, data, parentCell, queuedTextures, loadedData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Function2ab510, UpdateData, FinishUpdate, ptr: GUESS(low)
class TESFileArray; class TESObjectCELL; class QueuedFile;
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
class TESChildCell { public: virtual ~TESChildCell(); virtual TESObjectCELL* GetSaveParentCell() = 0; };
template<class T> struct NiPointer { T* ptr; };
struct OBJ_LAND { enum class Flag : std::uint32_t; stl::enumeration<Flag, std::uint32_t> flags; };
class TESObjectLAND : public TESForm, public TESChildCell {
public:
 struct LoadedLandData;
 void Function2ab510(std::uint8_t first, std::uint16_t second);
 void FinishUpdate();
 OBJ_LAND data;
 std::uint32_t pad2C;
 TESObjectCELL* parentCell;
 NiPointer<QueuedFile> queuedTextures;
 LoadedLandData* loadedData;
};
void UpdateData(std::uint8_t first, std::uint16_t second, TESObjectLAND::LoadedLandData* data);
