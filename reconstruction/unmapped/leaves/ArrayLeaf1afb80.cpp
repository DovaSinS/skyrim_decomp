// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1afb80 ArrayLeaf1afb80::~ArrayLeaf1afb80
// Adapted bodies: none
// CI hash: 0x1afb80 ??1ArrayLeaf1afb80@@QEAA@XZ
#include "ArrayLeaf1afb80.h"

ArrayLeaf1afb80::~ArrayLeaf1afb80()
{
    if (data) {
        FreeArrayLeaf1afb80(this);
        size = 0;
    }
}
