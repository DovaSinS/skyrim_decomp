// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x3eb180 ArrayLeaf3eb180::~ArrayLeaf3eb180
// Adapted bodies: none
// CI hash: 0x3eb180 ??1ArrayLeaf3eb180@@QEAA@XZ
#include "ArrayLeaf3eb180.h"

ArrayLeaf3eb180::~ArrayLeaf3eb180()
{
    if (data) {
        FreeArrayLeaf3eb180(this);
        size = 0;
    }
}
