// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x137220 ArrayLeaf137220::~ArrayLeaf137220
// Adapted bodies: none
// CI hash: 0x137220 ??1ArrayLeaf137220@@QEAA@XZ
#include "ArrayLeaf137220.h"

ArrayLeaf137220::~ArrayLeaf137220()
{
    if (data) {
        FreeArrayLeaf137220(this);
        size = 0;
    }
}
