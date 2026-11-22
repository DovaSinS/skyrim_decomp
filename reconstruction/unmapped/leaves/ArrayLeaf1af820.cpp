// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1af820 ArrayLeaf1af820::~ArrayLeaf1af820
// Adapted bodies: none
// CI hash: 0x1af820 ??1ArrayLeaf1af820@@QEAA@XZ
#include "ArrayLeaf1af820.h"

ArrayLeaf1af820::~ArrayLeaf1af820()
{
    if (data) {
        FreeArrayLeaf1af820(this);
        size = 0;
    }
}
