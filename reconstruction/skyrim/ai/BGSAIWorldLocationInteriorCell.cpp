// Source exposure: mixed (pinned image listing and community names).
// Code origin: existing leaf plus original reconstruction of Function449350 and Function449370.
// Adapted bodies: none
// 0x4493d0 BGSAIWorldLocationInteriorCell::Slot13
// 0x449350 BGSAIWorldLocationInteriorCell::Function449350
// 0x449370 BGSAIWorldLocationInteriorCell::Function449370
#include <cfloat>
#include "BGSAIWorldLocationInteriorCell.h"

std::uint8_t BGSAIWorldLocationInteriorCell::Slot13() const
{
    return 0x1;
}

float BGSAIWorldLocationInteriorCell::Function449350(const LocationCellHolder* a_target) const
{
    if (a_target->cell == cell) {
        return 0.0f;
    }
    return FLT_MAX;
}

bool BGSAIWorldLocationInteriorCell::Function449370(const LocationCellHolder* a_target) const
{
    return a_target->cell == cell;
}
