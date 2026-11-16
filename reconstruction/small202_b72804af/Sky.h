// Sky, build sse-steam-1-7-104.
// Labels: v2
// Origin: adapted declarations from CommonLibSSE-NG, MIT, b93280e832f263dbef44e44cbe2936622a02f91a.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// Sky: EXE_RTTI
// Compared functions:
// RVA 0x417af0, 46 bytes: Sky::Function417af0.
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
// Sky, NiPointer, BSSimpleList, NiColor, SkySound, ObjectRefHandle, Node, item, next, _listHead, red, green, blue, Mode, skySoundList, root, moonsRoot, auroraRoot, auroraDBHandle, extLightingOverride, currentRoom, previousRoom, lightingTransition, lightingTransitionTimer, currentClimate, currentWeather, lastWeather, defaultWeather, overrideWeather, region, atmosphere, stars, sun, clouds, masser, secunda, precip, skyColor, unk174, unk178, unk180, windSpeed, windAngle, fogNear, fogFar, unk19C, unk1A0, unk1A4, fogPower, fogClamp, currentGameHour, lastWeatherUpdate, currentWeatherPct, mode: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Function417af0, UpdateSound, ptr, value: GUESS(low)
class BSMultiBoundNode; class NiNode; class BGSLightingTemplate; class TESClimate; class TESWeather; class TESRegion; class Atmosphere; class Stars; class Sun; class Clouds; class Moon; class Precipitation; class SkySound;
template <class T> class NiPointer { public: T* ptr; };
template <class T> class BSSimpleList { public: struct Node { T item; Node* next; }; Node _listHead; };
struct ObjectRefHandle { std::uint32_t value; };
struct NiColor { float red, green, blue; };
void UpdateSound(SkySound*);
class Sky {
public:
 enum class Mode : std::uint32_t { kNone, kInterior, kSkyDomeOnly, kFull, kTotal };
 virtual ~Sky();
 void Function417af0();
 NiPointer<BSMultiBoundNode> root;
 NiPointer<NiNode> moonsRoot, auroraRoot;
 void* auroraDBHandle;
 BGSLightingTemplate* extLightingOverride;
 ObjectRefHandle currentRoom, previousRoom;
 float lightingTransition, lightingTransitionTimer;
 TESClimate* currentClimate;
 TESWeather *currentWeather, *lastWeather, *defaultWeather, *overrideWeather;
 TESRegion* region;
 Atmosphere* atmosphere;
 Stars* stars;
 Sun* sun;
 Clouds* clouds;
 Moon *masser, *secunda;
 Precipitation* precip;
 NiColor skyColor[17];
 std::uint32_t unk174;
 std::uint64_t unk178;
 NiColor unk180;
 float windSpeed, windAngle, fogNear, fogFar;
 std::uint32_t unk19C, unk1A0, unk1A4;
 float fogPower, fogClamp, currentGameHour, lastWeatherUpdate, currentWeatherPct;
 Mode mode;
 BSSimpleList<SkySound*>* skySoundList;
};
