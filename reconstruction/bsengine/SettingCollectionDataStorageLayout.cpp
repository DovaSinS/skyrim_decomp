// Build: sse-steam-1-7-104
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/represented-magic-wrapper-o2.json
// Source exposure: mixed (pinned complete public data and independent target primary RTTI/call operands).
// Drafted by GPT-6.1 Sol; remaining settings-list and shader storage recovery.
// Labels: v2
// Code origin: public data-only adaptations; ordinary compiler deleting wrappers, complete destructor bodies external. No external implementation body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/{S/SettingCollection.h,S/SettingCollectionList.h,I/INISettingCollection.h,I/INIPrefSettingCollection.h,R/RegSettingCollection.h,B/BSShaderProperty.h,S/ShaderReferenceEffect.h,B/BSTArray.h,B/BSSoundHandle.h}; MIT.
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/B/BSDistantTreeShaderProperty.h; GPL-3.0.
// SettingCollection, SettingCollectionList, INISettingCollection, INIPrefSettingCollection, RegSettingCollection, BSShaderProperty, ShaderReferenceEffect, RenderPassArray: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSDistantTreeShaderProperty: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// New storage names, member aliases and pointee names: GUESS(medium) STANDIN
// Named subKey is the public character string array of260 elements, not arbitrary padding. RenderPassArray is the public one-head-pointer struct. Heap arrays represent allocator/count storage; element definitions, methods and lifetimes are unclaimed. All complete data fields/bases follow the pinned public declarations, explicit padding is omitted, every size/offset asserted. Original methodsets/signatures, instantiability, source identity, ownership/lifetimes/behavior remain unclaimed. Target deletion sizes only cross-check known layouts and supply no fields. Only six listed52-byte deleting wrappers are compared.
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
// RVA 0x1558e70; 52 bytes
// RVA 0x14e8580; 52 bytes
// RVA 0x19ed70; 52 bytes
// RVA 0x1925a0; 52 bytes
// RVA 0x661ea0; 52 bytes
// RVA 0x5e2100; 52 bytes
void operator delete(void*, unsigned __int64) noexcept;
#include "SettingCollectionDataStorageLayout.h"
static ResearchLayouts::DistantTreeShaderDataStorageLayout object0;
static ResearchLayouts::ShaderPropertyDataStorageLayout object1;
static ResearchLayouts::IniPrefSettingsDataStorageLayout object2;
static ResearchLayouts::IniSettingsDataStorageLayout object3;
static ResearchLayouts::RegistrySettingsDataStorageLayout object4;
static ResearchLayouts::ShaderReferenceDataStorageLayout object5;
