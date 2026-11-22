// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x309bd0 ArrayLeaf309bd0::~ArrayLeaf309bd0
// Adapted bodies: none
// CI hash: 0x309bd0 ??1ArrayLeaf309bd0@@QEAA@XZ
#include "ArrayLeaf309bd0.h"

ArrayLeaf309bd0::~ArrayLeaf309bd0()
{
    if (data) {
        FreeArrayLeaf309bd0(this);
        size = 0;
    }
}
