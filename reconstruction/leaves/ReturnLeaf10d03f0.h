// Build: sse-steam-1-7-104; RVA 0x10d03f0; 3 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: binary-analysis; no external implementation reused.
// Drafted by tools/storage_free_return_template_v1.py (GPT-6.1 Sol).
// Labels: v2
// ReturnLeaf10d03f0, Invoke, value: GUESS(low) STANDIN
// Original signature and owner unknown; no storage or class-layout claim.
// Only Invoke is compared; a pass proves no name or runtime behavior.
// Origin: {"family": "storage-free-return", "template_digest": "a8a90867b70ae0309b00917f220b3f99a6deba78c20f494c38604218b6292263", "version": "1"}
#pragma once
class ReturnLeaf10d03f0 {
public:
    unsigned int Invoke();
};
