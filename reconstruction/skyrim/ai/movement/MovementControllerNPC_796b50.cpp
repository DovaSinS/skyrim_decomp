// Source exposure: mixed (CrashLogger and FO4 layout names; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x796b50 MovementControllerNPC::Unk_11
// Adapted bodies: none
#include "MovementControllerNPC_796b50.h"

// gTlsValue, TlsScopedValue: GUESS(low); a per-thread value the engine sets to 0x50 while this runs, then restores
extern __declspec(thread) std::uint32_t gTlsValue;

struct TlsScopedValue
{
    explicit TlsScopedValue(std::uint32_t a_value) :
        saved(gTlsValue)
    {
        gTlsValue = a_value;
    }
    ~TlsScopedValue() { gTlsValue = saved; }

    std::uint32_t saved;
};

void MovementControllerNPC::Unk_11(std::uint8_t a_flag)
{
    TlsScopedValue scope(0x50);
    if (a_flag != flag1C4) {
        flag1C4 = a_flag;
        if (subObject.Slot06()) {
            subObject.Slot04();
        }
    }
}
