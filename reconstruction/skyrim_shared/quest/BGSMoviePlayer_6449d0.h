// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// InputEvent, ButtonEvent, UserEvents, QUserEvent, activate, device, eventType, next, value, heldDownSecs: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); trimmed class views
// BGSMoviePlayer, BGSMoviePlayer::HandleInputEvent, StringRef, skipRequested, gUserEvents: GUESS(low)
// BGSMoviePlayer::HandleInputEvent: CRASHLOGGER_PDB(59818@2026.10.24); sink Handle name only, class kept
#pragma once

#include <cstdint>
#include <cstddef>

struct StringRef
{
    const char* data;
};

class InputEvent
{
public:
    virtual ~InputEvent();
    virtual bool HasIDCode() const;
    virtual const StringRef& QUserEvent() const;

    std::uint32_t device;
    std::uint32_t eventType;
    InputEvent* next;
};

class ButtonEvent : public InputEvent
{
public:
    std::uint8_t unk18[0x10];
    float value;
    float heldDownSecs;
};

class UserEvents
{
public:
    std::uint8_t unk00[0x38];
    StringRef activate;
};

extern UserEvents* gUserEvents;

class BGSMoviePlayer
{
public:
    int HandleInputEvent(InputEvent* const* events);  // compared: 0x6449d0

    std::uint8_t unk00[0x60];
    bool skipRequested;
};
