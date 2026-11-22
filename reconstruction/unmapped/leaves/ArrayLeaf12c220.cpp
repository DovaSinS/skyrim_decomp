// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x12c220 ArrayLeaf12c220::~ArrayLeaf12c220
// Adapted bodies: none
// CI hash: 0x12c220 ??1ArrayLeaf12c220@@QEAA@XZ
#include "ArrayLeaf12c220.h"

ArrayLeaf12c220::~ArrayLeaf12c220()
{
    if (data) {
        FreeArrayLeaf12c220(this);
        size = 0;
    }
}
