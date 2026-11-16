// Build: sse-steam-1-7-104
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (pinned public interface/reference/menu storage and independent target RTTI/slot analysis).
// Drafted by GPT-6.1 Sol; shared fieldless interface and UI prefix recovery.
// Labels: v2
// Code origin: adapted community storage declarations and original narrowed prefix construction; no external implementation body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/{B/BSTEvent.h,B/BSIntrusiveRefCounted.h,G/GRefCountImpl.h,G/GFxFunctionHandler.h,F/FxDelegateHandler.h,J/JournalTab.h,J/Journal_SystemTab.h,I/IMenu.h,I/IVirtualMachine.h}; MIT.
// BSTEventSink, BSTSingletonSDM, FxDelegateHandler, JournalTab, IMenu, GFxFunctionHandler, IVirtualMachine, BSIntrusiveRefCounted: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// All ResearchLayouts names ending Layout, PrefixLayout or StorageLayout, Contract and Identity tags, and physical mirror member names: GUESS(medium) STANDIN
// Primary storage is supported by the pinned declarations: reference-counted delegate16 plus movie pointer8 for JournalTab24; IMenu48 with movie/depth/flag/context/delegate fields; IVirtualMachine16 with its inherited count32 at8.
// Each generic contract tags a real RTTI-bound eight-byte vptr subobject. Tags introduce no storage or runtime value. Only destructor slot0 is needed; unassessed interface methods and fieldless ancestry are omitted.
// Owner-specific data, trailing nonpolymorphic singleton bases, later event-source storage, complete original owner definitions, method sets, lifetimes and instantiability/behavior are unclaimed.
// Public explicit padding fields are omitted; natural alignment gaps are unassessed rather than attributed to original source padding. No array, invented padding, helper body or emission attribute is introduced.
// Independent target primary/secondary RTTI and slot0 targets establish every selected offset. No deletion-size argument supplies storage.
// Only listed compiler-generated secondary destructor adjustors are compared. Constructors, complete destruction and other methods remain outside this byte-match claim. Size/offset assertions are not function passes.
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
// RVA 0x14c876c; 9 bytes
// RVA 0x14c8778; 9 bytes
// RVA 0x14c8784; 9 bytes
// RVA 0x9a7f2c; 9 bytes
// RVA 0x9a7f38; 9 bytes
// RVA 0x9a7f44; 9 bytes
// RVA 0x9a7f50; 9 bytes
// RVA 0x5b920c; 9 bytes
// RVA 0x5b9218; 9 bytes
// RVA 0x5b9224; 9 bytes
// RVA 0x95e344; 9 bytes
// RVA 0x95e350; 9 bytes
// RVA 0x95e35c; 9 bytes
// RVA 0x65125c; 9 bytes
// RVA 0x651268; 9 bytes
// RVA 0x651274; 9 bytes
// RVA 0x651280; 9 bytes
// RVA 0x7b1938; 9 bytes
// RVA 0x7b1944; 9 bytes
// RVA 0x7b1950; 9 bytes
// RVA 0x65128c; 9 bytes
// RVA 0x651298; 9 bytes
// RVA 0x6512a4; 9 bytes
// RVA 0x6512b0; 9 bytes
// RVA 0xa67d8c; 9 bytes
// RVA 0xa67d98; 9 bytes
// RVA 0xa67da4; 9 bytes
// RVA 0xa67db0; 9 bytes
#include "EventInterfaceVptrPrefixLayout.h"
namespace ResearchLayouts {
BSScript__Internal__VirtualMachineInterfaceStoragePrefixLayout::BSScript__Internal__VirtualMachineInterfaceStoragePrefixLayout() = default;
Journal_SystemTabInterfaceStoragePrefixLayout::Journal_SystemTabInterfaceStoragePrefixLayout() = default;
LoadWaitSpinnerInterfaceStoragePrefixLayout::LoadWaitSpinnerInterfaceStoragePrefixLayout() = default;
MainMenuInterfaceStoragePrefixLayout::MainMenuInterfaceStoragePrefixLayout() = default;
PathManagerPositionPlayerAdapterInterfaceStoragePrefixLayout::PathManagerPositionPlayerAdapterInterfaceStoragePrefixLayout() = default;
PlayerControlsInterfaceStoragePrefixLayout::PlayerControlsInterfaceStoragePrefixLayout() = default;
PlayerSleepWaitMovementControllerAdapterInterfaceStoragePrefixLayout::PlayerSleepWaitMovementControllerAdapterInterfaceStoragePrefixLayout() = default;
SkyrimSpeechRecognitionInterfaceStoragePrefixLayout::SkyrimSpeechRecognitionInterfaceStoragePrefixLayout() = default;
}
