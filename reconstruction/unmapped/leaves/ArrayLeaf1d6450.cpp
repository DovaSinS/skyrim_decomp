// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1d6450 ArrayLeaf1d6450::~ArrayLeaf1d6450
// Adapted bodies: none
// CI hash: 0x1d6450 ??1ArrayLeaf1d6450@@QEAA@XZ
#include "ArrayLeaf1d6450.h"

ArrayLeaf1d6450::~ArrayLeaf1d6450()
{
    if (data) {
        FreeArrayLeaf1d6450(this);
        size = 0;
    }
}
