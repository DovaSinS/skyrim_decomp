// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x39bf10 ArrayLeaf39bf10::~ArrayLeaf39bf10
// Adapted bodies: none
// CI hash: 0x39bf10 ??1ArrayLeaf39bf10@@QEAA@XZ
#include "ArrayLeaf39bf10.h"

ArrayLeaf39bf10::~ArrayLeaf39bf10()
{
    if (data) {
        FreeArrayLeaf39bf10(this);
        size = 0;
    }
}
