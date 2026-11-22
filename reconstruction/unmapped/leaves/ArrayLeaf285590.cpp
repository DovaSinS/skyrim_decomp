// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x285590 ArrayLeaf285590::~ArrayLeaf285590
// Adapted bodies: none
// CI hash: 0x285590 ??1ArrayLeaf285590@@QEAA@XZ
#include "ArrayLeaf285590.h"

ArrayLeaf285590::~ArrayLeaf285590()
{
    if (data) {
        FreeArrayLeaf285590(this);
        size = 0;
    }
}
