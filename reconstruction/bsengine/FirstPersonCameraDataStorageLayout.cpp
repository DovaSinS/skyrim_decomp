// Build: sse-steam-1-7-104
// Evidence: findings/ghidra-import.md
// Source exposure: mixed (public complete data declarations and independent primary RTTI/call operand bindings).
// Drafted by GPT-6.1 Sol; complete remaining public camera/value storage recovery.
// Labels: v2
// Code origin: public data-only adaptations and ordinary compiler deleting-wrapper emission. No external implementation body reused; complete destructors remain external.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/{F/FirstPersonState.h,F/FreeCameraState.h,T/ThirdPersonState.h,N/NiPoint2.h,N/NiPoint3.h,N/NiQuaternion.h,C/Color.h,S/Setting.h,G/GFxValue.h,G/GPtr.h,H/HUDObject.h,H/HUDChargeMeter.h,B/BSTempEffectDebris.h,B/BGSPackageDataLocation.h,B/BGSNamedPackageData.h,B/BGSPackageDataPointerTemplate.h,B/BGSTextureModel.h}; MIT.
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/{A/AutoVanityState.h,F/FurnitureCameraState.h,C/CombatPath.h}; GPL-3.0.
// FirstPersonState, FreeCameraState, ThirdPersonState, Setting, GFxValue, HUDObject, HUDChargeMeter, BSTempEffectDebris, BGSPackageDataLocation, BGSNamedPackageData, BGSPackageDataPointerTemplate, BGSTextureModel: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// AutoVanityState, FurnitureCameraState, CombatPath: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// New storage class names, fields and pointee names: GUESS(medium) STANDIN
// All represented data/base storage follows pinned public declarations and is asserted by size/offset. Public explicit padding is omitted; compiler alignment leaves those gaps unclaimed. Complete data coverage does not claim original methodsets/signatures, source identity, instantiability, ownership/lifetime or behavior. Target deletion sizes are consistency checks only, never a source of fields. Only listed deleting wrappers and one field getter are compared; complete destructor bodies remain outside scope.
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
// Recipe: reconstruction/recipes/represented-magic-wrapper-o2.json
// RVA 0x44f5f0; 52 bytes
// RVA 0x4aae00; 52 bytes
// RVA 0x8fc570; 52 bytes
// RVA 0x8fc5b0; 52 bytes
// RVA 0x55d4e0; 52 bytes
// RVA 0x8fc4b0; 52 bytes
// RVA 0x3eb800; 52 bytes
// RVA 0x85e100; 52 bytes
// RVA 0x8fc5f0; 52 bytes
// RVA 0x93be30; 52 bytes
// RVA 0x93c120; 52 bytes
// RVA 0x1b45b0; 52 bytes
// RVA 0x148010; 52 bytes
void operator delete(void*, unsigned __int64) noexcept;
#include "FirstPersonCameraDataStorageLayout.h"
static ResearchLayouts::PackageLocationDataStorageLayout object0;
static ResearchLayouts::DebrisEffectDataStorageLayout object1;
static ResearchLayouts::FirstPersonCameraDataStorageLayout object2;
static ResearchLayouts::FreeCameraDataStorageLayout object3;
static ResearchLayouts::ThirdPersonCameraDataStorageLayout object4;
static ResearchLayouts::AutoVanityCameraDataStorageLayout object5;
static ResearchLayouts::TextureModelCompleteDataStorageLayout object6;
static ResearchLayouts::CombatPathCompleteDataStorageLayout object7;
static ResearchLayouts::FurnitureCameraDataStorageLayout object8;
static ResearchLayouts::HudChargeMeterDataStorageLayout object9;
static ResearchLayouts::HudObjectDataStorageLayout object10;
static ResearchLayouts::CellEventCompleteDataStorageLayout object11;
static ResearchLayouts::SettingDataStorageLayout object12;
