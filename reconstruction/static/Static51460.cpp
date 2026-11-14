// Build: sse-steam-1-7-104
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/o2-os.json
// Source exposure: binary-analysis; possible sibling implementation exposure disclosed below.
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/staging/blk_00cc0000_o2.cpp:13192 (ContextScope helper).
// ContextScope lineage is uncertain; conservatively treated as adapted from that sibling source.
// ContextScope: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence); no licence is granted by its authors.
// Its README attributes some names to an Xbox 360 development-build PDB and Havok/Gamebryo source.
// Reuse is under the maintainer decision in LEGAL.md, not an infrastructure licence grant.
// Sibling material is not evidence about this target's names, addresses or behaviour.
// Drafted by GPT-6.1 Sol (recipe and generator).
// Owning system unknown. Referenced object names are stand-ins unless labelled otherwise.
// Only the generated initializer and its EH cleanup funclets are compared; the registered teardown is a reference binding.
// Labels: v2
// RVA 0x51460; 116 bytes
// object: GUESS(low) STANDIN
// Origin: {"family": "parked-context-resource-initializer", "template_digest": "02571f87257eb9942ea525b9d2619227010017450b4b244c7e68260b5f290f08", "version": "2"}
#include "Static51460.h"
static Static51460 object;
