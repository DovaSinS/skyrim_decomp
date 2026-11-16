// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed (local target analysis, public declarations and permitted sibling).
// Origin: reconstructed from target and sibling hints.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// names: GUESS(low); signatures and type names are hypotheses.
// TESObjectREFR::GetCurrentBiped: SIBLING(fo4-private@1b765c70, author-permission); adapted virtual forwarding.
// TESObjectREFR::Get3D: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); body adapted from src/RE/T/TESObjectREFR.cpp:102; declaration from include/RE/T/TESObjectREFR.h.
// TESObjectREFR::MoveHavok: SIBLING(fo4-private@1b765c70, author-permission); adapted simulation reset.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/TESObjectREFR.cpp:2436
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/TESObjectREFR.cpp:3193
// TESObjectREFR and virtual declarations: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted declarations.
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
#include "TESForm.h"
#include <cstdint>
class BGSLocation; struct NiPoint3; class TESObjectCELL; class TESTopicInfo; class BGSAnimationSequencer;
class BGSKeyword; class TESPackage; class BGSScene; class DialogueResponse; class BGSDialogueBranch;
class ActorCause; class ObjectRefHandle; enum class ITEM_REMOVE_REASON : std::int32_t;
struct TrapData; class TrapEntry; class TargetEntry; class MagicCaster; class MagicTarget;
class TESActorBase; class BSFaceGenNiNode; class BSFaceGenAnimationData; class NiAVObject;
class NiNode; class BSAnimationUpdateData; class BipedAnim;
namespace MagicSystem { enum class CastingSource : std::uint32_t; }
template <class T> class BSTSmartPointer;
class TESObjectREFR : public TESForm {
public:
    virtual void Predestroy();
    virtual BGSLocation* GetEditorLocation1() const;
    virtual bool GetEditorLocation2(NiPoint3&, NiPoint3&, TESForm*&, TESObjectCELL*);
    virtual void ForceEditorLocation(BGSLocation*);
    virtual void Update3DPosition(bool);
    virtual void UpdateSoundCallBack(bool);
    virtual bool SetDialogueWithPlayer(bool, bool, TESTopicInfo*);
    virtual void DamageObject(float, bool);
    virtual bool GetFullLODRef() const;
    virtual void SetFullLODRef(bool);
    virtual BGSAnimationSequencer* GetSequencer() const;
    virtual bool QCanUpdateSync() const;
    virtual bool GetAllowPromoteToPersistent() const;
    virtual bool HasKeywordHelper(const BGSKeyword*) const;
    virtual TESPackage* CheckForCurrentAliasPackage();
    virtual BGSScene* GetCurrentScene() const;
    virtual void SetCurrentScene(BGSScene*);
    virtual bool UpdateInDialogue(DialogueResponse*, bool);
    virtual BGSDialogueBranch* GetExclusiveBranch() const;
    virtual void SetExclusiveBranch(BGSDialogueBranch*);
    virtual void PauseCurrentDialogue();
    virtual void SetActorCause(ActorCause*);
    virtual ActorCause* GetActorCause() const;
    virtual NiPoint3 GetStartingAngle() const;
    virtual NiPoint3 GetStartingLocation() const;
    virtual void SetStartingPosition(const NiPoint3&);
    virtual void UpdateRefLight();
    virtual ObjectRefHandle RemoveItem(TESBoundObject*, std::int32_t, ITEM_REMOVE_REASON, ExtraDataList*, TESObjectREFR*, const NiPoint3*, const NiPoint3*);
    virtual bool AddWornItem(TESBoundObject*, std::int32_t, bool, std::uint32_t, std::uint32_t);
    virtual void DoTrap1(TrapData&);
    virtual void DoTrap2(TrapEntry*, TargetEntry*);
    virtual void AddObjectToContainer(TESBoundObject*, ExtraDataList*, std::int32_t, TESObjectREFR*);
    virtual NiPoint3 GetLookingAtLocation() const;
    virtual MagicCaster* GetMagicCaster(MagicSystem::CastingSource);
    virtual MagicTarget* GetMagicTarget();
    virtual bool IsChild() const;
    virtual TESActorBase* GetTemplateActorBase();
    virtual void SetTemplateActorBase(TESActorBase*);
    virtual BSFaceGenNiNode* GetFaceNodeSkinned();
    virtual BSFaceGenNiNode* GetFaceNode();
    virtual BSFaceGenAnimationData* GetFaceGenAnimationData();
    virtual bool ClampToGround();
    virtual bool DetachHavok(NiAVObject*);
    virtual void InitHavok();
    virtual void Unk_67(); virtual void Unk_68(); virtual void Unk_69();
    virtual NiAVObject* Load3D(bool);
    virtual void Release3DRelatedData();
    virtual void Set3D(NiAVObject*, bool);
    virtual bool ShouldBackgroundClone() const;
    virtual void Unk_6E();
    virtual NiAVObject* Get3D1(bool) const;
    virtual NiAVObject* Get3D2() const;
    virtual bool Is3rdPersonVisible() const;
    virtual bool PopulateGraphProjectsToLoad() const;
    virtual NiPoint3 GetBoundMin() const;
    virtual NiPoint3 GetBoundMax() const;
    virtual void Unk_75();
    virtual bool InitNonNPCAnimation(NiNode&);
    virtual bool CheckAndFixSkinAndBoneOrder(NiNode&);
    virtual void Unk_78();
    virtual void ModifyAnimationUpdateData(BSAnimationUpdateData&);
    virtual bool ShouldSaveAnimationOnUnloading() const;
    virtual bool ShouldSaveAnimationOnSaving() const;
    virtual bool ShouldPerformRevert() const;
    virtual void UpdateAnimation(float);
    virtual const BSTSmartPointer<BipedAnim>& GetBiped1(bool) const;
    virtual const BSTSmartPointer<BipedAnim>& GetBiped2() const;
    virtual const BSTSmartPointer<BipedAnim>& GetCurrentBiped() const;
    NiAVObject* Get3D() const;
    void MoveHavok(bool force);
};
class bhkNPCollisionObject { public: static void ResetSim(NiAVObject*, bool); };
