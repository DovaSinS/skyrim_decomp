// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1afa00 ArrayLeaf1afa00::~ArrayLeaf1afa00
// Adapted bodies: none
// CI hash: 0x1afa00 ??1ArrayLeaf1afa00@@QEAA@XZ
#include "ArrayLeaf1afa00.h"

ArrayLeaf1afa00::~ArrayLeaf1afa00()
{
    if (data) {
        FreeArrayLeaf1afa00(this);
        size = 0;
    }
}
