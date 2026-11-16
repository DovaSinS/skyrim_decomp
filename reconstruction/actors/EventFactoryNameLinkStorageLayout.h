// Build: sse-steam-1-7-104
// Source exposure: mixed (original target-binary storage evidence and authorized game-code sibling role hints).
// Drafted by GPT-6.1 Sol; callback factory bounded-text and link storage recovery.
// Labels: v2
// Code origin: original data declarations recovered from target constructors/import contracts and vtable-bound field accesses; no external implementation body reused.
// ConcreteEventCallbackFactory, IEventCallbackFactory: EXE_RTTI
// ConcreteEventCallbackFactory: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling role hint: fo4-private@1b765c70 src/Shared/TESForms/Character/BGSSceneActionTimer.cpp line11 instantiates a named callback factory. No sibling layout, offset or body is transferred.
// EventFactoryNameLinkStorageLayout, name, next: GUESS(medium) STANDIN
// Five target static initializers assign each original RTTI-bound vptr at0, zero the object link at88, and call the imported strncpy_s with destination this+8, capacity80, maximum copy79. Buffer length80 comes from this actual bounded-character-copy contract. Actual primary slot2 returns the buffer address8, slot3 loads link88; slot4 chain insertion stores an argument object pointer at88 and registration traverses slot3.
// This initial96-byte storage view covers the vptr,80-character bounded text buffer and object link. Original complete owner size, virtual method sets, signatures, ownership, destruction and registration behavior remain unclaimed. Layout assertions establish this view only, never a function match. No deletion/allocation size supplies storage.
#pragma once
#include <cstddef>
namespace ResearchLayouts {
class EventFactoryNameLinkStorageLayout {
public:
    virtual ~EventFactoryNameLinkStorageLayout();
    char name[80];
    EventFactoryNameLinkStorageLayout* next;
};
static_assert(sizeof(EventFactoryNameLinkStorageLayout)==96,"represented text/link prefix");
static_assert(offsetof(EventFactoryNameLinkStorageLayout,name)==8,"target bounded-copy destination");
static_assert(sizeof(EventFactoryNameLinkStorageLayout::name)==80,"target strncpy_s capacity");
static_assert(offsetof(EventFactoryNameLinkStorageLayout,next)==88,"target initialized and linked object pointer");
}
