// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1afc40 ArrayLeaf1afc40::~ArrayLeaf1afc40
// Adapted bodies: none
// CI hash: 0x1afc40 ??1ArrayLeaf1afc40@@QEAA@XZ
#include "ArrayLeaf1afc40.h"

ArrayLeaf1afc40::~ArrayLeaf1afc40()
{
    if (data) {
        FreeArrayLeaf1afc40(this);
        size = 0;
    }
}
