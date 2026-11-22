// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x3aa380 ArrayLeaf3aa380::~ArrayLeaf3aa380
// Adapted bodies: none
// CI hash: 0x3aa380 ??1ArrayLeaf3aa380@@QEAA@XZ
#include "ArrayLeaf3aa380.h"

ArrayLeaf3aa380::~ArrayLeaf3aa380()
{
    if (data) {
        FreeArrayLeaf3aa380(this);
        size = 0;
    }
}
