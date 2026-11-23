// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: written for this reconstruction from the pinned image listings; names and layout from CommonLibSSE-NG b93280e.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BaseFormComponent: STANDIN EXE_RTTI COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only class names, base chain,
// slot order and sizes are claimed.
#pragma once

#include <cstddef>
#include <cstdint>

class BaseFormComponent
{
public:
	virtual ~BaseFormComponent() {}  // 00
	virtual void InitializeDataComponent();  // 01
	virtual void ClearDataComponent();  // 02
	virtual void CopyComponent();  // 03
};
static_assert(sizeof(BaseFormComponent) == 0x8, "layout");

class TESBoundObject;

struct ContainerObject
{
	std::int32_t count;  // 00
	std::uint32_t pad04;  // 04
	TESBoundObject* obj;  // 08
	void* itemExtra;  // 10
};
static_assert(sizeof(ContainerObject) == 0x18, "layout");

class TESContainer : public ::BaseFormComponent
{
public:
	~TESContainer() override;  // 00
	void InitializeDataComponent() override;  // 01
	void ClearDataComponent() override;  // 02
	void CopyComponent() override;  // 03

	std::int32_t GetItemCount(TESBoundObject* a_object) const;

	// 0x1e09f0: sets allowStolenItems (name is a guess)
	void Function1e09f0(bool a_allow);
	// 0x1e0a00: reads allowStolenItems (name is a guess)
	bool Function1e0a00() const;

	ContainerObject** containerObjects;  // 08
	std::uint32_t numContainerObjects;  // 10
	bool allowStolenItems;  // 14
	std::uint8_t unk15[3];  // 15
};
static_assert(sizeof(TESContainer) == 0x18, "layout");
