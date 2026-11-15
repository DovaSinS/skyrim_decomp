// BGSSaveGameBuffer declarations for build sse-steam-1-7-104.
//
// Labels: v2
// Task: p92-s-bgssavegamebuffer
// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// Started from a tools/skeleton.py skeleton: stand-ins carry only what the compared code needs, and
// community names are unverified.
// BGSSaveGameBuffer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BGSSaveGameBuffer::GetActor, BGSSaveGameBuffer::GetForm, BGSSaveGameBuffer::GetReference: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Actor, TESForm, TESObjectREFR: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown08: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Actor;
class TESForm;
class TESObjectREFR;

class BGSSaveGameBuffer
{
public:
    virtual Actor* GetActor();  // compared: 0x63a2e0
    virtual TESForm* GetForm();  // compared: 0x63a2f0
    virtual TESObjectREFR* GetReference();  // compared: 0x63a300

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint8_t unknown08[0x10];  // 08
};
static_assert(sizeof(BGSSaveGameBuffer) == 0x18, "BGSSaveGameBuffer size");
