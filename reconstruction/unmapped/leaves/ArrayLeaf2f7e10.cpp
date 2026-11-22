// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x2f7e10 ArrayLeaf2f7e10::~ArrayLeaf2f7e10
// Adapted bodies: none
// CI hash: 0x2f7e10 ??1ArrayLeaf2f7e10@@QEAA@XZ
#include "ArrayLeaf2f7e10.h"

ArrayLeaf2f7e10::~ArrayLeaf2f7e10()
{
    if (data) {
        FreeArrayLeaf2f7e10(this);
        size = 0;
    }
}
