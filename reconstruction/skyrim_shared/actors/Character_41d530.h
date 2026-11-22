// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Character: GUESS(low); the class is the placeholder owner
// GetFollowRadiusMatchSpeed: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(fo4-pdb); the PDB class is AiFormulas, this unit keeps the placeholder class
// kFollowRadiusBase: GUESS(low); a float constant in the image data read by this function
#pragma once

extern const float kFollowRadiusBase;

class Character
{
public:
    static float GetFollowRadiusMatchSpeed(float a_speed);  // compared: 0x41d530
};
