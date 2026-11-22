// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x3de260 ArrayLeaf3de260::~ArrayLeaf3de260
// Adapted bodies: none
// CI hash: 0x3de260 ??1ArrayLeaf3de260@@QEAA@XZ
#include "ArrayLeaf3de260.h"

ArrayLeaf3de260::~ArrayLeaf3de260()
{
    if (data) {
        FreeArrayLeaf3de260(this);
        size = 0;
    }
}
