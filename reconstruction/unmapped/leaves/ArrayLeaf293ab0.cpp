// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x293ab0 ArrayLeaf293ab0::~ArrayLeaf293ab0
// Adapted bodies: none
// CI hash: 0x293ab0 ??1ArrayLeaf293ab0@@QEAA@XZ
#include "ArrayLeaf293ab0.h"

ArrayLeaf293ab0::~ArrayLeaf293ab0()
{
    if (data) {
        FreeArrayLeaf293ab0(this);
        size = 0;
    }
}
