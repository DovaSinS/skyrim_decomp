// Build: sse-steam-1-7-104
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (pinned community interface declarations and target RTTI/secondary-slot analysis).
// Drafted by GPT-6.1 Sol; shared SkyrimVM polymorphic interface prefix recovery.
// Labels: v2
// Code origin: adapted community interface declarations; original owner prefix and defaulted construction. No external implementation body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/I/IFreezeQuery.h, include/RE/I/IStackCallbackSaveInterface.h and include/RE/B/BSTEvent.h; MIT.
// IFreezeQuery, IStackCallbackSaveInterface, BSTEventSink, BSEventNotifyControl, GetIsFrozen, Unk_01, Unk_02, ProcessEvent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SkyrimVM: EXE_RTTI
// SkyrimVMInterfacePrefixLayout, SkyrimVMFreezeQueryLayout, SkyrimVMStackSaveLayout, SkyrimVMEventSinkLayout, SkyrimVMEventSourceLayout, SkyrimVMEventTag, SkyrimVMVptrPrefixStorageLayout: GUESS(medium) STANDIN
// This representation covers exactly the 54 polymorphic interface subobjects at target RTTI offsets 0..424.
// It deliberately omits the nonpolymorphic singleton/event-source bases and every data member beyond the interface prefix.
// The 432-byte assertion describes this prefix view only, not SkyrimVM's whole-object size. Original complete definitions and instantiability remain unassessed.
// The target includes two Amiibo interfaces absent from the pinned community SkyrimVM header; target RTTI, not that header's owner offsets, determines base ordering.
// Only listed compiler-generated secondary deleting-destructor adjustors are compared; construction, original owner destruction, event handling and lifetime behavior are outside this claim.
// No deletion-size argument, explicit padding, byte array, helper body or emission-forcing attribute is used to manufacture the prefix.
// Layout agreement is not a function pass. Exact byte matching of an adjustor proves no omitted owner layout or original-source identity.
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
// RVA 0x9ef6d0; 9 bytes
// RVA 0x9ef6dc; 9 bytes
// RVA 0x9ef7a8; 9 bytes
// RVA 0x9ef7fc; 9 bytes
// RVA 0x9ef808; 9 bytes
// RVA 0x9ef814; 9 bytes
// RVA 0x9ef820; 9 bytes
// RVA 0x9ef82c; 9 bytes
// RVA 0x9ef838; 9 bytes
// RVA 0x9ef844; 9 bytes
// RVA 0x9ef850; 9 bytes
// RVA 0x9ef85c; 9 bytes
// RVA 0x9ef868; 9 bytes
// RVA 0x9ef874; 9 bytes
// RVA 0x9ef880; 9 bytes
#include "SkyrimVMInterfacePrefixLayout.h"
namespace ResearchLayouts {
SkyrimVMInterfacePrefixLayout::SkyrimVMInterfacePrefixLayout() = default;
}
