// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// BSNiAllocator: EXE_RTTI
// VerifyAddress: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// member, padding: GUESS(low); storage names invented for the measured member offset
// 0xeae860 compared function
// 0xeae7f0 compared function
// 0xeae760 compared function
// 0xeae6d0 compared function
// 0xeae660 compared function
// 0xeae5d0 compared function
// Unk_14369ac98, Unk_14369a810, Unk_cde810, Unk_cde6a0: GUESS(low); globals and callees of the compared body
#pragma once
#include <cstdint>
// VerifyAddress: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
extern std::uint32_t Unk_14369ac98;
extern char Unk_14369a810;
void Unk_cde810(void* a_object, std::uint32_t* a_state);
void Unk_cde6a0(void* a_object, void* a_ptr, bool a_flag);
void* Unk_cde250(void* a_object, std::uint64_t a_value, std::uint32_t a_count, bool a_flag);
void Unk_15a97f8(void* a_ptr, std::uint64_t a_zero, std::uint64_t a_value);
struct PtrHolder { void* field0; };
struct Count { std::uint32_t value; };
void Unk_cde4A0(void* a_object, void* a_ptr, void* a_holder, std::uint32_t a_count, bool a_flag);

class BSNiAllocator
{
public:
    virtual std::uint8_t VerifyAddress() const;
    // Initialize, Shutdown: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); empty bodies in the compared image
    virtual void Initialize();
    virtual void Shutdown();
    void Deallocate(void* a_ptr, std::uint32_t a_alignment);
    void TrackDeallocate(void* a_ptr, std::uint32_t a_alignment);
    void* Allocate(std::uint64_t* a_ptr, void* a_count, std::uint32_t a_alignment);
    void Reallocate(void* a_ptr, PtrHolder* a_holder, Count* a_count, std::uint32_t a_alignment);
    void* TrackAllocate(std::uint64_t* a_ptr, void* a_count, std::uint32_t a_alignment);
    void Unk_06(void* a_ptr, PtrHolder* a_holder, Count* a_count, std::uint32_t a_alignment);
};
