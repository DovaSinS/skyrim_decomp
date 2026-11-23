// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// UIBlurManager, UIBlurManager::~UIBlurManager, EventSinkBase, SingletonBase, ReleaseBlurState, gUIBlurManager: GUESS(low)
// UIBlurManager::~UIBlurManager: CRASHLOGGER_PDB(59818@2026.10.24); placeholder name only, class kept
#pragma once

#include <cstdint>
#include <cstddef>

class UIBlurManager;

void* ReleaseBlurState(UIBlurManager* manager);

class EventSinkBase
{
public:
    virtual ~EventSinkBase() {}
};

class UIBlurManager;
extern UIBlurManager* gUIBlurManager;

class SingletonBase
{
public:
    ~SingletonBase() { gUIBlurManager = nullptr; }
};

class UIBlurManager : public SingletonBase, public EventSinkBase
{
public:
    ~UIBlurManager() override;  // compared: 0x98c970
};
