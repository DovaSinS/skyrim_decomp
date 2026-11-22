// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x29c730 ArrayLeaf29c730::~ArrayLeaf29c730
// Adapted bodies: none
// CI hash: 0x29c730 ??1ArrayLeaf29c730@@QEAA@XZ
#include "ArrayLeaf29c730.h"

ArrayLeaf29c730::~ArrayLeaf29c730()
{
    if (data) {
        FreeArrayLeaf29c730(this);
        size = 0;
    }
}
