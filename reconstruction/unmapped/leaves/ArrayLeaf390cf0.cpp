// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x390cf0 ArrayLeaf390cf0::~ArrayLeaf390cf0
// Adapted bodies: none
// CI hash: 0x390cf0 ??1ArrayLeaf390cf0@@QEAA@XZ
#include "ArrayLeaf390cf0.h"

ArrayLeaf390cf0::~ArrayLeaf390cf0()
{
    if (data) {
        FreeArrayLeaf390cf0(this);
        size = 0;
    }
}
