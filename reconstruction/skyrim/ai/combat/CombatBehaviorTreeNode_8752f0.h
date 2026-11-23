// Source exposure: mixed (CrashLogger layout names; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// CombatBehaviorTreeNode, name, parent, children: CRASHLOGGER_PDB(59818@2026.10.24)
// CombatBehaviorTreeNode::~CombatBehaviorTreeNode, ChildArray, data, size, pad2C: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class CombatBehaviorTreeNode;

struct ChildArray
{
    CombatBehaviorTreeNode** data;
    std::uint32_t size;
};

class CombatBehaviorTreeNode
{
public:
    CombatBehaviorTreeNode();  // compared: 0x8752f0
    virtual ~CombatBehaviorTreeNode();

    const char* name;
    CombatBehaviorTreeNode* parent;
    ChildArray children;
};
static_assert(sizeof(CombatBehaviorTreeNode) == 0x28, "CombatBehaviorTreeNode size");
