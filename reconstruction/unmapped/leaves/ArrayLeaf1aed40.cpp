// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1aed40 ArrayLeaf1aed40::~ArrayLeaf1aed40
// Adapted bodies: none
// CI hash: 0x1aed40 ??1ArrayLeaf1aed40@@QEAA@XZ
#include "ArrayLeaf1aed40.h"

ArrayLeaf1aed40::~ArrayLeaf1aed40()
{
    if (data) {
        FreeArrayLeaf1aed40(this);
        size = 0;
    }
}
