// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x3a9250 BGSScene::InitLoadGame
// Adapted bodies: none
#include "BGSScene_3a9250.h"

// 0x3a9250 BGSScene::InitLoadGame
void BGSScene::InitLoadGame(BGSLoadFormBuffer* a_buf)
{
    for (std::uint32_t i = 0; i < actions.size; ++i) {
        actions.data[i]->InitLoadGame(this, a_buf);
    }
}
