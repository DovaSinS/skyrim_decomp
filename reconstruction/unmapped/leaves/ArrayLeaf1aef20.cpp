// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1aef20 ArrayLeaf1aef20::~ArrayLeaf1aef20
// Adapted bodies: none
// CI hash: 0x1aef20 ??1ArrayLeaf1aef20@@QEAA@XZ
#include "ArrayLeaf1aef20.h"

ArrayLeaf1aef20::~ArrayLeaf1aef20()
{
    if (data) {
        FreeArrayLeaf1aef20(this);
        size = 0;
    }
}
