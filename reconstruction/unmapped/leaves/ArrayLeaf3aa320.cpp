// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x3aa320 ArrayLeaf3aa320::~ArrayLeaf3aa320
// Adapted bodies: none
// CI hash: 0x3aa320 ??1ArrayLeaf3aa320@@QEAA@XZ
#include "ArrayLeaf3aa320.h"

ArrayLeaf3aa320::~ArrayLeaf3aa320()
{
    if (data) {
        FreeArrayLeaf3aa320(this);
        size = 0;
    }
}
