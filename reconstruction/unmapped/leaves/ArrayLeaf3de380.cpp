// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x3de380 ArrayLeaf3de380::~ArrayLeaf3de380
// Adapted bodies: none
// CI hash: 0x3de380 ??1ArrayLeaf3de380@@QEAA@XZ
#include "ArrayLeaf3de380.h"

ArrayLeaf3de380::~ArrayLeaf3de380()
{
    if (data) {
        FreeArrayLeaf3de380(this);
        size = 0;
    }
}
