// Source exposure: mixed (authorized target analysis and anonymous permitted sibling source).
// Code origin: written for this reconstruction from the listing; QClassAgentType adapted from the permitted sibling source.
// MovementHandlerAgentSprintActionTrigger, QClassAgentType: SIBLING(fo4-private@1b765c70, author-permission)
// BSFixedString, data, flag, Function7a6100, Function7a6490: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
struct BSFixedString { const char* data; BSFixedString(const char*); ~BSFixedString(); };
class MovementHandlerAgentSprintActionTrigger {
public:
    static const BSFixedString &QClassAgentType();
    void Function7a6100(bool a_value);
    bool Function7a6490();

    unsigned char unk00[0x1C];
    bool flag;
};
