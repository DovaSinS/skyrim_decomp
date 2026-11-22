// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x2020e0 ArrayLeaf2020e0::~ArrayLeaf2020e0
// Adapted bodies: none
// CI hash: 0x2020e0 ??1ArrayLeaf2020e0@@QEAA@XZ
#include "ArrayLeaf2020e0.h"

ArrayLeaf2020e0::~ArrayLeaf2020e0()
{
    if (data) {
        FreeArrayLeaf2020e0(this);
        size = 0;
    }
}
