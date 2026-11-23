// Source exposure: mixed (community headers; the pinned image listing)
// Code origin: written for this reconstruction from the listing; names from the header
// Adapted bodies: none
// MovementHandlerAgentPlayerControls::Function7a49a0: GUESS(low)
#pragma once
struct BSFixedString { const char* data; BSFixedString(const char*); ~BSFixedString(); };
class MovementHandlerAgentPlayerControls {
public:
    static const BSFixedString &QClassAgentType();
    void Function7a49a0(float a_newValue);
private:
    char _unk00[0x28];
    float _unk28;
};
