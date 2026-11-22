// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1afca0 ArrayLeaf1afca0::~ArrayLeaf1afca0
// Adapted bodies: none
// CI hash: 0x1afca0 ??1ArrayLeaf1afca0@@QEAA@XZ
#include "ArrayLeaf1afca0.h"

ArrayLeaf1afca0::~ArrayLeaf1afca0()
{
    if (data) {
        FreeArrayLeaf1afca0(this);
        size = 0;
    }
}
