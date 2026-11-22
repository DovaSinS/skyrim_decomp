// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x29c7f0 ArrayLeaf29c7f0::~ArrayLeaf29c7f0
// Adapted bodies: none
// CI hash: 0x29c7f0 ??1ArrayLeaf29c7f0@@QEAA@XZ
#include "ArrayLeaf29c7f0.h"

ArrayLeaf29c7f0::~ArrayLeaf29c7f0()
{
    if (data) {
        FreeArrayLeaf29c7f0(this);
        size = 0;
    }
}
