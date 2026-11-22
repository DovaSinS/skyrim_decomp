// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1aec80 ArrayLeaf1aec80::~ArrayLeaf1aec80
// Adapted bodies: none
// CI hash: 0x1aec80 ??1ArrayLeaf1aec80@@QEAA@XZ
#include "ArrayLeaf1aec80.h"

ArrayLeaf1aec80::~ArrayLeaf1aec80()
{
    if (data) {
        FreeArrayLeaf1aec80(this);
        size = 0;
    }
}
