// BGSMusicTrackFormWrapper declarations for build sse-steam-1-7-104.
// Labels: v2
// Origin: declarations adapted from labelled pinned community headers and target-specific partial declarations.
// Source exposure: mixed (pinned target listing and community declarations).
// BSIMusicTrack, BSIMusicTrack::DoUpdate, BSIMusicTrack::DoPlay, BSIMusicTrack::DoPause, BSIMusicTrack::DoFinish, BSIMusicTrack::GetDurationImpl, BSIMusicTrack::GetType, BSIMusicTrack::TestCanPlay, BSIMusicTrack::GetMusicStatus, BSIMusicTrack::DoSetDuckingAttenuation, BSIMusicTrack::DoClearDucking: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declared in NG slot order.
// BGSMusicTrackFormWrapper, track: GUESS(low)
// MIT License
//
// Copyright (c) 2018 Ryan-rsm-McKenzie
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
class BSIMusicTrack {
public:
    enum class MusicStatus : std::uint32_t {};
    virtual ~BSIMusicTrack() = default;
    virtual void DoUpdate();
    virtual void DoPlay();
    virtual void DoPause();
    virtual void DoFinish(bool immediate, float fadeTime);
    virtual float GetDurationImpl() const;
    virtual std::uint32_t GetType() const;
    virtual bool TestCanPlay() const;
    virtual MusicStatus GetMusicStatus() const;
    virtual void DoSetDuckingAttenuation(std::uint16_t ducking);
    virtual void DoClearDucking();
};
class BGSMusicTrackFormWrapper {
public:
    void DoUpdate(); void DoPlay(); void DoPause(); void DoFinish(bool immediate, float fadeTime);
    float GetDurationImpl() const; std::uint32_t GetType() const; bool TestCanPlay() const;
    BSIMusicTrack::MusicStatus GetMusicStatus() const;
    void DoSetDuckingAttenuation(std::uint16_t ducking); void DoClearDucking();
private:
    std::uint8_t pad[0x10]; BSIMusicTrack* track;
};
