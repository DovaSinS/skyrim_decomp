// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1527560 BSLightingShaderMaterialLandscape::Create
// 0x15279b0 BSLightingShaderMaterialLandscape::GetTextures
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x1527a80 BSLightingShaderMaterialLandscape::GetFeature
// 0x1529030 BSLightingShaderMaterialLandscape::~BSLightingShaderMaterialLandscape
// Code origin: existing unit text, declarations after CommonLibSSE-NG names; this change only adds the origin line.
// Code origin: original; written from the local pinned-image listing and the community declarations.
// 0x15277e0 BSLightingShaderMaterialLandscape::ClearTextures
#include "BSLightingShaderMaterialLandscape.h"

inline void ReleaseTexture(NiSourceTexture*& a_ptr)
{
    if (a_ptr) {
        NiSourceTexture* old = a_ptr;
        a_ptr = nullptr;
        old->DecRefCount();
    }
}

// Not compared on its own: the compiler emits the vftable here, and with it the deleting
// destructor that is compared. The destructor itself stays undefined here so that the compiler
// calls the separate complete destructor, as the listing does.
BSLightingShaderMaterialLandscape::BSLightingShaderMaterialLandscape()
{
}

BSLightingShaderMaterialLandscape::Feature BSLightingShaderMaterialLandscape::GetFeature() const
{
    return static_cast<Feature>(0x13);
}

std::uint32_t BSLightingShaderMaterialLandscape::GetTextures(NiSourceTexture** a_textures)
{
    std::uint32_t count = 0;
    if (diffuseTexture) {
        a_textures[count++] = diffuseTexture._ptr;
    }
    if (normalTexture) {
        a_textures[count++] = normalTexture._ptr;
    }
    if (rimSoftLightingTexture) {
        a_textures[count++] = rimSoftLightingTexture._ptr;
    }
    if (specularBackLightingTexture) {
        a_textures[count++] = specularBackLightingTexture._ptr;
    }
    for (std::uint32_t i = 0; i < layerCount; ++i) {
        if (diffuse[i]) {
            a_textures[count++] = diffuse[i];
        }
        if (normal[i]) {
            a_textures[count++] = normal[i];
        }
    }
    if (extraF8) {
        a_textures[count++] = extraF8;
    }
    if (extra100) {
        a_textures[count++] = extra100;
    }
    return count;
}

void* BSLightingShaderMaterialLandscape::operator new(std::size_t a_size) throw()
{
    if (g_memoryManagerGuard != 2) {
        InitMemoryManager(&g_memoryManager, &g_memoryManagerGuard);
    }
    return g_memoryManager.Allocate(static_cast<std::uint32_t>(a_size), 0, false);
}

BSShaderMaterial* BSLightingShaderMaterialLandscape::Create()
{
    return new BSLightingShaderMaterialLandscape;
}

// BSLightingShaderMaterialLandscape::ClearTextures: CRASHLOGGER_PDB(59818@2026.10.24)
void BSLightingShaderMaterialLandscape::ClearTextures()
{
    BSLightingShaderMaterialBase::ClearTextures();
    for (std::uint32_t i = 0; i < 5; ++i) {
        ReleaseTexture(diffuse[i]);
        ReleaseTexture(normal[i]);
    }
    ReleaseTexture(extraF8);
    ReleaseTexture(extra100);
}
