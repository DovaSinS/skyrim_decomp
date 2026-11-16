// Labels: v2
// Build: sse-steam-1-7-104
// RVA 0xfe8e40, 24 bytes: GetFrustum.
// Evidence: findings/ghidra-import.md
// Origin: original reconstruction; declarations adapted from powerof3/CommonLibSSE, GPL-3.0, include/RE/B/BSOcclusionPlane.h, BSOcclusionShape.h, BSCompoundFrustum.h, BSTArray.h and include/RE/N/NiFrustumPlanes.h, NiPlane.h, NiMatrix3.h, NiPoint2.h, NiPoint3.h, NiRefObject.h, NiObject.h.
// Source exposure: mixed (binary-analysis and community headers).
// Drafted by: gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// GetFrustum is compared; Refresh and declarations are not compared. Names and signatures are unverified.
// BSOcclusionPlane, BSOcclusionShape, NiObject, NiRefObject, NiPoint2, NiPoint3, NiMatrix3, NiPlane, NiFrustumPlanes, BSCompoundFrustum, BSTArray, translation, rotation, updateFacesOrVertices, size, frustum, planes, functionOperators, viewFrustum, viewPosition, camera, freePlane, freeOp, firstOp, skipViewFrustum, prethreaded: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// Refresh, GetFrustum: GUESS(low)
#include "BSOcclusionPlane.h"
BSCompoundFrustum* BSOcclusionPlane::GetFrustum() { Refresh(); return &frustum; }
