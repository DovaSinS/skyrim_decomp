// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: TESRegionDataLandscape::LoadRegionDataLandscape.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/region system/tesregiondatalandscape.cpp:20
// 0x250920 TESRegionDataLandscape::LoadRegionDataLandscape
#include "TESRegionDataLandscape_250920.h"

bool TESRegionDataLandscape::LoadRegionDataLandscape(TESFile* apFile)
{
    if (!apFile)
        return false;
    unsigned int chunk = apFile->GetChunkID();
    switch (chunk)
    {
    case 0x4e4f4349:
        TESTexture::ReadTextureData(m_pLandscapeTexture, apFile);
        break;
    }
    return true;
}
