// BSWaterShaderMaterial, build sse-steam-1-7-104.
// Labels: v2
// Inferred names: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis (local binary analysis).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// Compared functions:
// RVA 0x155ae90, 39 bytes: BSWaterShaderMaterial::Function155ae90.
// BSWaterShaderMaterial: EXE_RTTI

#pragma once
// BSWaterShaderMaterial: EXE_RTTI
// WaterManager, Release, manager, material: GUESS(low) STANDIN
class BSWaterShaderMaterial;
class WaterManager { public: void Release(BSWaterShaderMaterial* material); };
extern WaterManager* manager;
extern BSWaterShaderMaterial* material;
// Function155ae90: GUESS(low)
class BSWaterShaderMaterial { public: static void Function155ae90(); };
