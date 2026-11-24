// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: mixed (pinned image and community declarations).
// Code origin: original factory method and partial product declarations. Adapted bodies: none.
// Factory and product identities: EXE_RTTI
// Allocation sizes and constructor calls: OBSERVED
// CreateImpl: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Heap helpers, product storage and its constructor symbol: GUESS(low) STANDIN
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once
#include "ConcreteFormFactory.h"
#include "TESForm.h"

namespace FormFactoryAllocation
{
class MemoryManager
{
public:
    static MemoryManager instance;
    static unsigned initState;
    void EnsureInitialized(unsigned* state);
    void* Allocate(size_t bytes, int alignment, bool alignmentRequired);
};

// Represents only the TESForm base and the storage needed by the external constructor.
template<class T> struct ProductSize;

template<class T>
class FormFactoryProductStorage : public TESForm
{
public:
    FormFactoryProductStorage();

    static void* operator new(size_t bytes)
    {
        if (MemoryManager::initState != 2) {
            MemoryManager::instance.EnsureInitialized(&MemoryManager::initState);
        }
        return MemoryManager::instance.Allocate(bytes, 0, false);
    }

private:
    unsigned char unknown[ProductSize<T>::value - sizeof(TESForm)];
};
}

class EffectSetting;
namespace FormFactoryAllocation
{
template<> struct ProductSize<EffectSetting>
{
    static constexpr size_t value = 0x198;
};
static_assert(sizeof(FormFactoryProductStorage<EffectSetting>) == 0x198,
              "form allocation size");
}

class TESCombatStyle;
namespace FormFactoryAllocation
{
template<> struct ProductSize<TESCombatStyle>
{
    static constexpr size_t value = 0xa0;
};
static_assert(sizeof(FormFactoryProductStorage<TESCombatStyle>) == 0xa0,
              "form allocation size");
}

class TESObjectARMO;
namespace FormFactoryAllocation
{
template<> struct ProductSize<TESObjectARMO>
{
    static constexpr size_t value = 0x228;
};
static_assert(sizeof(FormFactoryProductStorage<TESObjectARMO>) == 0x228,
              "form allocation size");
}

class TESObjectWEAP;
namespace FormFactoryAllocation
{
template<> struct ProductSize<TESObjectWEAP>
{
    static constexpr size_t value = 0x220;
};
static_assert(sizeof(FormFactoryProductStorage<TESObjectWEAP>) == 0x220,
              "form allocation size");
}

class TESWaterForm;
namespace FormFactoryAllocation
{
template<> struct ProductSize<TESWaterForm>
{
    static constexpr size_t value = 0x260;
};
static_assert(sizeof(FormFactoryProductStorage<TESWaterForm>) == 0x260,
              "form allocation size");
}

class TESWeather;
namespace FormFactoryAllocation
{
template<> struct ProductSize<TESWeather>
{
    static constexpr size_t value = 0x8d8;
};
static_assert(sizeof(FormFactoryProductStorage<TESWeather>) == 0x8d8,
              "form allocation size");
}

class TESWorldSpace;
namespace FormFactoryAllocation
{
template<> struct ProductSize<TESWorldSpace>
{
    static constexpr size_t value = 0x358;
};
static_assert(sizeof(FormFactoryProductStorage<TESWorldSpace>) == 0x358,
              "form allocation size");
}

class BGSFootstepSet;
namespace FormFactoryAllocation
{
template<> struct ProductSize<BGSFootstepSet>
{
    static constexpr size_t value = 0x98;
};
static_assert(sizeof(FormFactoryProductStorage<BGSFootstepSet>) == 0x98,
              "form allocation size");
}

class BGSImpactDataSet;
namespace FormFactoryAllocation
{
template<> struct ProductSize<BGSImpactDataSet>
{
    static constexpr size_t value = 0x58;
};
static_assert(sizeof(FormFactoryProductStorage<BGSImpactDataSet>) == 0x58,
              "form allocation size");
}

class BGSTextureSet;
namespace FormFactoryAllocation
{
template<> struct ProductSize<BGSTextureSet>
{
    static constexpr size_t value = 0x130;
};
static_assert(sizeof(FormFactoryProductStorage<BGSTextureSet>) == 0x130,
              "form allocation size");
}

class Script;
namespace FormFactoryAllocation
{
template<> struct ProductSize<Script>
{
    static constexpr size_t value = 0x80;
};
static_assert(sizeof(FormFactoryProductStorage<Script>) == 0x80,
              "form allocation size");
}

class BGSBodyPartData;
namespace FormFactoryAllocation
{
template<> struct ProductSize<BGSBodyPartData>
{
    static constexpr size_t value = 0x88;
};
static_assert(sizeof(FormFactoryProductStorage<BGSBodyPartData>) == 0x88,
              "form allocation size");
}

class BGSRagdoll;
namespace FormFactoryAllocation
{
template<> struct ProductSize<BGSRagdoll>
{
    static constexpr size_t value = 0x1b8;
};
static_assert(sizeof(FormFactoryProductStorage<BGSRagdoll>) == 0x1b8,
              "form allocation size");
}

class TESNPC;
namespace FormFactoryAllocation
{
template<> struct ProductSize<TESNPC>
{
    static constexpr size_t value = 0x268;
};
static_assert(sizeof(FormFactoryProductStorage<TESNPC>) == 0x268,
              "form allocation size");
}

class TESQuest;
namespace FormFactoryAllocation
{
template<> struct ProductSize<TESQuest>
{
    static constexpr size_t value = 0x268;
};
static_assert(sizeof(FormFactoryProductStorage<TESQuest>) == 0x268,
              "form allocation size");
}

class TESRace;
namespace FormFactoryAllocation
{
template<> struct ProductSize<TESRace>
{
    static constexpr size_t value = 0x4b8;
};
static_assert(sizeof(FormFactoryProductStorage<TESRace>) == 0x4b8,
              "form allocation size");
}
