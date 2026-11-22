// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1c6450 ArrayLeaf1c6450::~ArrayLeaf1c6450
// Adapted bodies: none
// CI hash: 0x1c6450 ??1ArrayLeaf1c6450@@QEAA@XZ
#include "ArrayLeaf1c6450.h"

ArrayLeaf1c6450::~ArrayLeaf1c6450()
{
    if (data) {
        FreeArrayLeaf1c6450(this);
        size = 0;
    }
}
