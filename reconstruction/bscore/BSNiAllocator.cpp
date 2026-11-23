// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// BSNiAllocator: EXE_RTTI
// VerifyAddress: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// member, padding: GUESS(low); storage names invented for the measured member offset
// 0xeae910 BSNiAllocator::VerifyAddress
// Code origin: the VerifyAddress leaf as above; the six allocator functions below are original, from the listing and community declarations only
// 0xeae5d0 BSNiAllocator::Allocate
// 0xeae660 BSNiAllocator::Deallocate
// 0xeae6d0 BSNiAllocator::Reallocate
// 0xeae760 BSNiAllocator::TrackAllocate
// 0xeae7f0 BSNiAllocator::TrackDeallocate
// 0xeae860 BSNiAllocator::Unk_06
#include "BSNiAllocator.h"
// VerifyAddress: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
std::uint8_t BSNiAllocator::VerifyAddress() const
{
    return 0x1;
}

// BSNiAllocator::Initialize: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
void BSNiAllocator::Initialize()
{
}

// BSNiAllocator::Shutdown: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
void BSNiAllocator::Shutdown()
{
}

void BSNiAllocator::Deallocate(void* a_ptr, std::uint32_t a_alignment)
{
    bool flag;
    if (a_alignment == 10) {
        if (Unk_14369ac98 != 2) {
            Unk_cde810(&Unk_14369a810, &Unk_14369ac98);
        }
        flag = true;
    } else {
        if (Unk_14369ac98 != 2) {
            Unk_cde810(&Unk_14369a810, &Unk_14369ac98);
        }
        flag = false;
    }
    Unk_cde6a0(&Unk_14369a810, a_ptr, flag);
}

void* BSNiAllocator::Allocate(std::uint64_t* a_ptr, void* a_count, std::uint32_t a_alignment)
{
    std::uint32_t count;
    bool flag;
    if (a_alignment == 7) {
        if (Unk_14369ac98 != 2) {
            Unk_cde810(&Unk_14369a810, &Unk_14369ac98);
        }
        count = *static_cast<std::uint32_t*>(a_count);
        flag = true;
    } else {
        if (Unk_14369ac98 != 2) {
            Unk_cde810(&Unk_14369a810, &Unk_14369ac98);
        }
        count = 0;
        flag = false;
    }
    void* p = Unk_cde250(&Unk_14369a810, *a_ptr, count, flag);
    Unk_15a97f8(p, 0, *a_ptr);
    return p;
}

void BSNiAllocator::Reallocate(void* a_ptr, PtrHolder* a_holder, Count* a_count, std::uint32_t a_alignment)
{
    std::uint32_t count;
    bool flag;
    if (a_alignment == 8) {
        if (Unk_14369ac98 != 2) {
            Unk_cde810(&Unk_14369a810, &Unk_14369ac98);
        }
        count = a_count->value;
        flag = true;
    } else {
        if (Unk_14369ac98 != 2) {
            Unk_cde810(&Unk_14369a810, &Unk_14369ac98);
        }
        count = 0;
        flag = false;
    }
    Unk_cde4A0(&Unk_14369a810, a_ptr, a_holder->field0, count, flag);
}

void* BSNiAllocator::TrackAllocate(std::uint64_t* a_ptr, void* a_count, std::uint32_t a_alignment)
{
    std::uint32_t count;
    bool flag;
    if (a_alignment == 13) {
        if (Unk_14369ac98 != 2) {
            Unk_cde810(&Unk_14369a810, &Unk_14369ac98);
        }
        count = *static_cast<std::uint32_t*>(a_count);
        flag = true;
    } else {
        if (Unk_14369ac98 != 2) {
            Unk_cde810(&Unk_14369a810, &Unk_14369ac98);
        }
        count = 0;
        flag = false;
    }
    void* p = Unk_cde250(&Unk_14369a810, *a_ptr, count, flag);
    Unk_15a97f8(p, 0, *a_ptr);
    return p;
}

void BSNiAllocator::Unk_06(void* a_ptr, PtrHolder* a_holder, Count* a_count, std::uint32_t a_alignment)
{
    std::uint32_t count;
    bool flag;
    if (a_alignment == 14) {
        if (Unk_14369ac98 != 2) {
            Unk_cde810(&Unk_14369a810, &Unk_14369ac98);
        }
        count = a_count->value;
        flag = true;
    } else {
        if (Unk_14369ac98 != 2) {
            Unk_cde810(&Unk_14369a810, &Unk_14369ac98);
        }
        count = 0;
        flag = false;
    }
    Unk_cde4A0(&Unk_14369a810, a_ptr, a_holder->field0, count, flag);
}

void BSNiAllocator::TrackDeallocate(void* a_ptr, std::uint32_t a_alignment)
{
    bool flag;
    if (a_alignment == 16) {
        if (Unk_14369ac98 != 2) {
            Unk_cde810(&Unk_14369a810, &Unk_14369ac98);
        }
        flag = true;
    } else {
        if (Unk_14369ac98 != 2) {
            Unk_cde810(&Unk_14369a810, &Unk_14369ac98);
        }
        flag = false;
    }
    Unk_cde6a0(&Unk_14369a810, a_ptr, flag);
}
