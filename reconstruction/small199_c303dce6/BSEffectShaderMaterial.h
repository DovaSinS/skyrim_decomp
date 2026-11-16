// BSEffectShaderMaterial, build sse-steam-1-7-104.
// Labels: v2
// Inferred names: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// Compared functions:
// RVA 0x1556600, 39 bytes: BSEffectShaderMaterial::Function1556600.
// BSEffectShaderMaterial: STANDIN EXE_RTTI
// MaterialResource, MaterialResourceManager, materialManager, sharedMaterial, ReleaseResource, Function1556600: GUESS(low)
#pragma once
class MaterialResource;
class MaterialResourceManager { public: void ReleaseResource(MaterialResource*); };
extern MaterialResourceManager* materialManager;
extern MaterialResource* sharedMaterial;
class BSEffectShaderMaterial { public: static void Function1556600(); };
