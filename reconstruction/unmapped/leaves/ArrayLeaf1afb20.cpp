// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1afb20 ArrayLeaf1afb20::~ArrayLeaf1afb20
// Adapted bodies: none
// CI hash: 0x1afb20 ??1ArrayLeaf1afb20@@QEAA@XZ
#include "ArrayLeaf1afb20.h"

ArrayLeaf1afb20::~ArrayLeaf1afb20()
{
    if (data) {
        FreeArrayLeaf1afb20(this);
        size = 0;
    }
}
