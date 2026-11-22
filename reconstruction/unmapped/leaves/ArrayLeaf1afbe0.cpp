// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1afbe0 ArrayLeaf1afbe0::~ArrayLeaf1afbe0
// Adapted bodies: none
// CI hash: 0x1afbe0 ??1ArrayLeaf1afbe0@@QEAA@XZ
#include "ArrayLeaf1afbe0.h"

ArrayLeaf1afbe0::~ArrayLeaf1afbe0()
{
    if (data) {
        FreeArrayLeaf1afbe0(this);
        size = 0;
    }
}
