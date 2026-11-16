// Build: sse-steam-1-7-104; RVA 0x639830; 37 bytes
// Labels: v2
// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// BGSSaveFormBuffer::GetReference: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/SaveGame/Buffers/BGSSaveFormBuffer.cpp:65
// TESForm, BGSSaveFormBuffer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/T/TESForm.h, include/RE/B/BaseFormComponent.h, include/RE/B/BGSSaveGameBuffer.h and include/RE/B/BGSSaveFormBuffer.h.
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
#include <cstdint>
class TESFile; class BGSSaveFormBuffer; class BGSLoadFormBuffer; class TESObjectREFR;
enum class FormType : unsigned char;
class BaseFormComponent { public: virtual ~BaseFormComponent(); virtual void InitializeDataComponent(); virtual void ClearDataComponent(); virtual void CopyComponent(BaseFormComponent*); };
class TESForm : public BaseFormComponent { public:
virtual void                               InitializeData();
virtual void                               ClearData();
virtual bool                               Load(TESFile* a_mod);
virtual bool                               LoadPartial(TESFile* a_mod);
virtual bool                               LoadEdit(TESFile* a_mod);
virtual TESForm*                           CreateDuplicateForm(bool a_createEditorID, void* a_arg2);
virtual bool                               AddChange(std::uint32_t a_changeFlags);
virtual void                               RemoveChange(std::uint32_t a_changeFlags);
virtual bool                               FindInFileFast(TESFile* a_mod);
virtual bool                               CheckSaveGame(BGSSaveFormBuffer* a_buf);
virtual void                               SaveGame(BGSSaveFormBuffer* a_buf);
virtual void                               LoadGame(BGSLoadFormBuffer* a_buf);
virtual void                               InitLoadGame(BGSLoadFormBuffer* a_buf);
virtual void                               FinishLoadGame(BGSLoadFormBuffer* a_buf);
virtual void                               Revert(BGSLoadFormBuffer* a_buf);
virtual void                               InitItemImpl();
virtual TESFile*             GetDescriptionOwnerFile() const;
virtual FormType             GetSavedFormType() const;
virtual void                               GetFormDetailedString(char* a_buf, std::uint32_t a_bufLen);
virtual bool                 GetKnown() const;
virtual bool                 GetRandomAnim() const;
virtual bool                 GetPlayable() const;
virtual bool                 IsHeadingMarker() const;
virtual bool                 GetDangerous() const;
virtual bool                 QHasCurrents() const;
virtual bool                 GetObstacle() const;
virtual bool                 QIsLODLandObject() const;
virtual bool                 GetOnLocalMap() const;
virtual bool                 GetMustUpdate() const;
virtual void                               SetOnLocalMap(bool a_set);
virtual bool                 GetIgnoredBySandbox() const;
virtual void                               SetDelete(bool a_set);
virtual void                               SetAltered(bool a_set);
virtual void                               SaveObjectBound();
virtual void                               LoadObjectBound(TESFile* a_mod);
virtual bool                 IsBoundObject() const;
virtual bool                 IsObject() const;
virtual bool                 IsMagicItem() const;
virtual bool                 IsWater() const;
virtual TESObjectREFR*                     AsReference1();
virtual const TESObjectREFR* AsReference2() const;
};
class BGSSaveGameBuffer { public: virtual ~BGSSaveGameBuffer(); virtual TESForm* GetForm(); };
class BGSSaveFormBuffer : public BGSSaveGameBuffer { public: const TESObjectREFR* GetReference(); };
