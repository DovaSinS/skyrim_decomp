// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSMusicType, BGSMusicType::DoFinish: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the body works on the BSIMusicType subobject (offsets are relative to it), so this class is a stand-in for that view
// BGSMusicType::fadeTime, ::currentTrackIndex, ::tracks, ::typeStatus: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); members of BSIMusicType
// BSIMusicTrack, BSIMusicTrack::DoFinish, BSIMusicTrack::GetMusicStatus: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the slots up to GetMusicStatus
// BSIMusicTrack::unk01, ::unk02, ::unk03, ::unk05, ::unk06, ::unk07: GUESS(low); slot placeholders (NG names DoUpdate, DoPlay, DoPause, GetDurationImpl, GetType, TestCanPlay)
// BGSMusicType::unk00, ::unk18, ::unk38: GUESS(low); unused regions of the subobject
#pragma once

#include <cstdint>
#include <cstddef>

class BSIMusicTrack
{
public:
    virtual ~BSIMusicTrack();                       // 00
    virtual void unk01();                           // 01
    virtual void unk02();                           // 02
    virtual void unk03();                           // 03
    virtual void DoFinish(bool immediate, float fadeTime);  // 04
    virtual float unk05();                          // 05
    virtual std::uint32_t unk06();                  // 06
    virtual bool unk07();                           // 07
    virtual std::uint32_t GetMusicStatus();         // 08
};

class BGSMusicType
{
public:
    void DoFinish(bool arg1);  // compared: 0x327e70

    unsigned char unk00[0x10];
    float fadeTime;                      // 10
    std::uint32_t currentTrackIndex;     // 14
    unsigned char unk18[0x18];
    BSIMusicTrack** tracks;              // 30
    unsigned char unk38[0x10];
    std::uint32_t typeStatus;            // 48
};
