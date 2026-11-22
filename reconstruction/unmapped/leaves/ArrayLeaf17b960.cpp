// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x17b960 ArrayLeaf17b960::~ArrayLeaf17b960
// Adapted bodies: none
// CI hash: 0x17b960 ??1ArrayLeaf17b960@@QEAA@XZ
#include "ArrayLeaf17b960.h"

ArrayLeaf17b960::~ArrayLeaf17b960()
{
    if (data) {
        FreeArrayLeaf17b960(this);
        size = 0;
    }
}
