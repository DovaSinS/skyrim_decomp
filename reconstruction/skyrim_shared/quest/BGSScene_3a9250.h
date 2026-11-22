// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSScene, BGSScene::InitLoadGame: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// actions: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG declares a BSTArray, a plain struct holds the same words here
// BGSSceneAction: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only slot 12
// SceneActionArray: GUESS(low); stand-in for the BSTArray of actions
// Unk_0C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); action slot 12, renamed to InitLoadGame in this unit
#pragma once

#include <cstdint>
#include <cstddef>

class BGSLoadFormBuffer;
class BGSScene;

class BGSSceneAction
{
public:
    virtual void unk00();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void unk04();
    virtual void unk05();
    virtual void unk06();
    virtual void unk07();
    virtual void unk08();
    virtual void unk09();
    virtual void unk0A();
    virtual void unk0B();
    virtual void InitLoadGame(BGSScene* a_scene, BGSLoadFormBuffer* a_buf);
};

struct SceneActionArray
{
    BGSSceneAction** data;      // 00
    std::uint32_t    capacity;  // 08
    std::uint32_t    pad0C;     // 0C
    std::uint32_t    size;      // 10
    std::uint32_t    pad14;     // 14
};

class BGSScene
{
public:
    void InitLoadGame(BGSLoadFormBuffer* a_buf);

    std::uint8_t     pad00[0x80];
    SceneActionArray actions;  // 80
};
