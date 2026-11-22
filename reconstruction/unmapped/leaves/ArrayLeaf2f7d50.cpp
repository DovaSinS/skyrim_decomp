// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x2f7d50 ArrayLeaf2f7d50::~ArrayLeaf2f7d50
// Adapted bodies: none
// CI hash: 0x2f7d50 ??1ArrayLeaf2f7d50@@QEAA@XZ
#include "ArrayLeaf2f7d50.h"

ArrayLeaf2f7d50::~ArrayLeaf2f7d50()
{
    if (data) {
        FreeArrayLeaf2f7d50(this);
        size = 0;
    }
}
