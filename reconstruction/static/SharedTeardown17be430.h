// Build: sse-steam-1-7-104; RVA 0x17be430; 78 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: binary-analysis; original minimal lifetime declaration.
// Drafted by tools/shared_teardown_template_v1.py (GPT-6.1 Sol).
// Labels: v2
// SharedTeardown17be430, object, value: GUESS(low) STANDIN
// Original owner and pointee type unknown; shared_ptr<void> erases the pointee.
// Only the compiler-generated static teardown is compared, not initialization.
// Storage and release use the pinned toolchain standard library through <memory>.
// No external implementation is copied into this unit; no behavior/name claim.
// Origin: {"family": "standard-shared-owner-teardown", "template_digest": "1a6941c366ce206bac7775adcb5dd3ff0615db596d3a58f1262f098ecf9765fe", "version": "1"}
#pragma once
#include <memory>
struct SharedTeardown17be430 { std::shared_ptr<void> value; };
