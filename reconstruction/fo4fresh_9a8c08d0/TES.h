// TES, build sse-steam-1-7-104.
// Labels: v2
// RVA 0x1a59d0, 31 bytes: TES::GetLandMaterialType
// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/FileIO/TES.cpp:158 (TES::GetLandMaterialType)
// RVA 0x1a46a0, 12 bytes: TES::ResumeMasterFileLoads
// RVA 0x1a4670, 32 bytes: TES::CancelMasterFileLoads
// Sibling source: fo4-private@1b765c70 src/Shared/FileIO/TES.cpp:702 (TES::ResumeMasterFileLoads)
// Sibling source: fo4-private@1b765c70 src/Shared/FileIO/TES.cpp:695 (TES::CancelMasterFileLoads)
// BGSDynamicPersistenceManager, instance, Pause, Resume, ExteriorCellLoader, loader, CancelAllCellLoads: GUESS(low)
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
// TES, GetLandMaterialType, NiPoint3, TESLandTexture, GetLandTexture, GetHavokMaterialType, coord: GUESS(low)
#pragma once
class NiPoint3;
class TESLandTexture { public: unsigned int GetHavokMaterialType(); };
class BGSDynamicPersistenceManager { public: static BGSDynamicPersistenceManager* instance; void Pause(); void Resume(); };
class ExteriorCellLoader { public: void CancelAllCellLoads(); };
extern ExteriorCellLoader* loader;
class TES { public: void ResumeMasterFileLoads(); void CancelMasterFileLoads(); public: TESLandTexture* GetLandTexture(const NiPoint3& coord); unsigned int GetLandMaterialType(const NiPoint3& coord); };
