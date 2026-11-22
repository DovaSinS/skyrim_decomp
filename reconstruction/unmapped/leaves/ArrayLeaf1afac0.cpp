// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1afac0 ArrayLeaf1afac0::~ArrayLeaf1afac0
// Adapted bodies: none
// CI hash: 0x1afac0 ??1ArrayLeaf1afac0@@QEAA@XZ
#include "ArrayLeaf1afac0.h"

ArrayLeaf1afac0::~ArrayLeaf1afac0()
{
    if (data) {
        FreeArrayLeaf1afac0(this);
        size = 0;
    }
}
