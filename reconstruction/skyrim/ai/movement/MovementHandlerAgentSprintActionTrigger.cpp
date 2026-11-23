// Source exposure: mixed (authorized target analysis and anonymous permitted sibling source).
// Code origin: written for this reconstruction from the listing; QClassAgentType adapted from the permitted sibling source.
// Adapted bodies: QClassAgentType from fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentSprintActionTrigger.cpp:25 (author permission)
// MovementHandlerAgentSprintActionTrigger, QClassAgentType: SIBLING(fo4-private@1b765c70, author-permission)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x7a6100 MovementHandlerAgentSprintActionTrigger::Function7a6100
// 0x7a6490 MovementHandlerAgentSprintActionTrigger::Function7a6490
// 0x7a5b20 MovementHandlerAgentSprintActionTrigger::QClassAgentType
// Drafted by v-macrev, assisted by claude-sonnet-5-5.
#include "MovementHandlerAgentSprintActionTrigger.h"

const BSFixedString &MovementHandlerAgentSprintActionTrigger::QClassAgentType()
{
    static BSFixedString typeString("Sprint Action Trigger");
    return typeString;

}

void MovementHandlerAgentSprintActionTrigger::Function7a6100(bool a_value)
{
    flag = a_value;
}

bool MovementHandlerAgentSprintActionTrigger::Function7a6490()
{
    return flag;
}
