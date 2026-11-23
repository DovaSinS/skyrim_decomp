// Source exposure: mixed (community headers; the pinned image listing)
// Code origin: written for this reconstruction from the listing; names from the header
// Adapted bodies: none
// 0x7a49a0 MovementHandlerAgentPlayerControls::Function7a49a0
// 0x7a3f10 MovementHandlerAgentPlayerControls::QClassAgentType
// Drafted by v-macrev, assisted by claude-haiku-5-5.
#include "MovementHandlerAgentPlayerControls.h"
const BSFixedString &MovementHandlerAgentPlayerControls::QClassAgentType()
{
    static BSFixedString typeString("Player Controls");
    return typeString;

}

void MovementHandlerAgentPlayerControls::Function7a49a0(float a_newValue)
{
    this->_unk28 = a_newValue;
}
