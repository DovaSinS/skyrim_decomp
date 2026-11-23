// Recipe: reconstruction/recipes/o2-fpfast.json
// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6449d0 BGSMoviePlayer::HandleInputEvent
// Adapted bodies: none
#include "BGSMoviePlayer_6449d0.h"

int BGSMoviePlayer::HandleInputEvent(InputEvent* const* events)
{
    skipRequested = false;
    for (InputEvent* event = *events; event; event = event->next) {
        if (event->eventType != 0) {
            continue;
        }
        UserEvents* userEvents = gUserEvents;
        if (event->QUserEvent().data != userEvents->activate.data) {
            continue;
        }
        const ButtonEvent* button = static_cast<const ButtonEvent*>(event);
        if (button->value != 0.0f && button->heldDownSecs == 0.0f) {
            skipRequested = true;
        }
    }
    return 0;
}
