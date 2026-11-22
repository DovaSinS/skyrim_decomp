// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1aee60 ArrayLeaf1aee60::~ArrayLeaf1aee60
// Adapted bodies: none
// CI hash: 0x1aee60 ??1ArrayLeaf1aee60@@QEAA@XZ
#include "ArrayLeaf1aee60.h"

ArrayLeaf1aee60::~ArrayLeaf1aee60()
{
    if (data) {
        FreeArrayLeaf1aee60(this);
        size = 0;
    }
}
