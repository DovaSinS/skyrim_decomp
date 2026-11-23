// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BGSLoadFormBuffer, BGSLoadFormBuffer::Function5bc750, LoadFormVisitor, ListNode, Visit: GUESS(low)
// BGSLoadFormBuffer::Function5bc750: CRASHLOGGER_PDB(59818@2026.10.24); placeholder name only, class kept
#pragma once

#include <cstdint>
#include <cstddef>

class BGSLoadFormBuffer;

class LoadFormVisitor
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
    virtual void Visit(BGSLoadFormBuffer* buffer);
};

struct ListNode
{
    LoadFormVisitor* item;
    ListNode* next;
};

class BGSLoadFormBuffer
{
public:
    void Function5bc750(ListNode* head);  // compared: 0x5bc750
};
