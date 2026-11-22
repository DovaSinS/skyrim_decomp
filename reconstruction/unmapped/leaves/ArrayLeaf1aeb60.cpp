// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1aeb60 ArrayLeaf1aeb60::~ArrayLeaf1aeb60
// Adapted bodies: none
// CI hash: 0x1aeb60 ??1ArrayLeaf1aeb60@@QEAA@XZ
#include "ArrayLeaf1aeb60.h"

ArrayLeaf1aeb60::~ArrayLeaf1aeb60()
{
    if (data) {
        FreeArrayLeaf1aeb60(this);
        size = 0;
    }
}
