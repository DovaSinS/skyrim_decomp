// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1aec20 ArrayLeaf1aec20::~ArrayLeaf1aec20
// Adapted bodies: none
// CI hash: 0x1aec20 ??1ArrayLeaf1aec20@@QEAA@XZ
#include "ArrayLeaf1aec20.h"

ArrayLeaf1aec20::~ArrayLeaf1aec20()
{
    if (data) {
        FreeArrayLeaf1aec20(this);
        size = 0;
    }
}
