# Shared inline reference-lifetime pilot

Build: sse-steam-1-7-104. Target image is pinned in builds/target.json.
Owner: awarebayes. Engineer and source drafter: GPT-6.1 Sol high, 2026-11-15.
Exposure: mixed (binary-analysis and community-headers). No clean-room claim.

The selected host entries reuse reference-count release operations. Names and partial
class declarations are stand-ins, except where explicitly attributed to the MIT-licensed
CharmedBaryon/CommonLibSSE-NG revision b93280e832f263dbef44e44cbe2936622a02f91a.
Source comments identify adapted algorithms and preserve the complete licence notice.
The census associates recurring instruction bodies with potential consumers; that is
an optimization lead, not evidence that a whole consumer function matches.

Private attempts use the stock verifier and unchanged comparator. One-host results
are preliminary and do not meet the acceptance rule. No matched status or behavior,
name correctness or whole-class layout claim follows from this pilot.
Reproduce from each selected unit's private task with the stock attempt command;
acceptance additionally requires native Windows confirmation, admitted independent
review, the sampling safeguard and integration through the batching lane.

Pilot source units (all names guessed, owner unknown):

- BSInlineHost1473f0, RVA 0x1473f0, 48 bytes.
- BSInlineHost152030, RVA 0x152030, 48 bytes.
- BSInlineHost19ae90, RVA 0x19ae90, 48 bytes.
- BSInlineHost19aef0, RVA 0x19aef0, 48 bytes.
- BSInlineHost1b2940, RVA 0x1b2940, 48 bytes.
- BSInlineHost1b2970, RVA 0x1b2970, 48 bytes.
- BSInlineHost1b29a0, RVA 0x1b29a0, 48 bytes.
- BSInlineHost1b29d0, RVA 0x1b29d0, 48 bytes.
- BSInlineHost1c6810, RVA 0x1c6810, 48 bytes.
- BSInlineHost1d1d90, RVA 0x1d1d90, 48 bytes.
- BSInlineHost1f7950, RVA 0x1f7950, 48 bytes.
- BSInlineHost202320, RVA 0x202320, 48 bytes.
- BSInlineHost202350, RVA 0x202350, 48 bytes.
- BSInlineHost202380, RVA 0x202380, 48 bytes.
- BSInlineHost2023b0, RVA 0x2023b0, 48 bytes.
- BSInlineHost2023e0, RVA 0x2023e0, 48 bytes.
- BSInlineHost202410, RVA 0x202410, 48 bytes.
- BSInlineHost20b030, RVA 0x20b030, 48 bytes.
- BSInlineHost20b060, RVA 0x20b060, 48 bytes.
- BSInlineHost213910, RVA 0x213910, 48 bytes.
- BSInlineHost21ec20, RVA 0x21ec20, 48 bytes.
- BSInlineHost21ec50, RVA 0x21ec50, 48 bytes.
- BSInlineHost21ec80, RVA 0x21ec80, 48 bytes.
- BSInlineHost21ecb0, RVA 0x21ecb0, 48 bytes.
- BSInlineHost220e30, RVA 0x220e30, 48 bytes.
- BSInlineHost220e60, RVA 0x220e60, 48 bytes.
- BSInlineHost226970, RVA 0x226970, 48 bytes.
- BSInlineHost24da90, RVA 0x24da90, 48 bytes.

Second-box expansion (112 direct owning-pointer destructors and 14 owning-pointer
subobject destructors; each remains reconstructed pending native confirmation):

- BSInlineHost28e380, RVA 0x28e380, 48 bytes.
- BSInlineHost2a8b40, RVA 0x2a8b40, 48 bytes.
- BSInlineHost2a8b70, RVA 0x2a8b70, 48 bytes.
- BSInlineHost2b5f90, RVA 0x2b5f90, 48 bytes.
- BSInlineHost2b5fc0, RVA 0x2b5fc0, 48 bytes.
- BSInlineHost2b5ff0, RVA 0x2b5ff0, 48 bytes.
- BSInlineHost2d13d0, RVA 0x2d13d0, 48 bytes.
- BSInlineHost2d1400, RVA 0x2d1400, 48 bytes.
- BSInlineHost2d1430, RVA 0x2d1430, 48 bytes.
- BSInlineHost2f8040, RVA 0x2f8040, 48 bytes.
- BSInlineHost2f8070, RVA 0x2f8070, 48 bytes.
- BSInlineHost2f84d0, RVA 0x2f84d0, 48 bytes.
- BSInlineHost321bb0, RVA 0x321bb0, 48 bytes.
- BSInlineHost383be0, RVA 0x383be0, 48 bytes.
- BSInlineHost3eb630, RVA 0x3eb630, 48 bytes.
- BSInlineHost3eb660, RVA 0x3eb660, 48 bytes.
- BSInlineHost3f9150, RVA 0x3f9150, 48 bytes.
- BSInlineHost3fb390, RVA 0x3fb390, 48 bytes.
- BSInlineHost3ffbb0, RVA 0x3ffbb0, 48 bytes.
- BSInlineHost403190, RVA 0x403190, 48 bytes.
- BSInlineHost40bc20, RVA 0x40bc20, 48 bytes.
- BSInlineHost40d230, RVA 0x40d230, 48 bytes.
- BSInlineHost40e9c0, RVA 0x40e9c0, 48 bytes.
- BSInlineHost419770, RVA 0x419770, 48 bytes.
- BSInlineHost41cc00, RVA 0x41cc00, 48 bytes.
- BSInlineHost41cc30, RVA 0x41cc30, 48 bytes.
- BSInlineHost42b0d0, RVA 0x42b0d0, 48 bytes.
- BSInlineHost435c20, RVA 0x435c20, 48 bytes.
- BSInlineHost436b60, RVA 0x436b60, 48 bytes.
- BSInlineHost4411b0, RVA 0x4411b0, 48 bytes.
- BSInlineHost4b6490, RVA 0x4b6490, 48 bytes.
- BSInlineHost4b85d0, RVA 0x4b85d0, 48 bytes.
- BSInlineHost4b8610, RVA 0x4b8610, 48 bytes.
- BSInlineHost4c0150, RVA 0x4c0150, 48 bytes.
- BSInlineHost4d30b0, RVA 0x4d30b0, 48 bytes.
- BSInlineHost4d30e0, RVA 0x4d30e0, 48 bytes.
- BSInlineHost50d8a0, RVA 0x50d8a0, 48 bytes.
- BSInlineHost512d70, RVA 0x512d70, 48 bytes.
- BSInlineHost52ec20, RVA 0x52ec20, 48 bytes.
- BSInlineHost52ec50, RVA 0x52ec50, 48 bytes.
- BSInlineHost52ec80, RVA 0x52ec80, 48 bytes.
- BSInlineHost52ecb0, RVA 0x52ecb0, 48 bytes.
- BSInlineHost52ece0, RVA 0x52ece0, 48 bytes.
- BSInlineHost55ec20, RVA 0x55ec20, 48 bytes.
- BSInlineHost5648b0, RVA 0x5648b0, 48 bytes.
- BSInlineHost5c6430, RVA 0x5c6430, 48 bytes.
- BSInlineHost5e1c20, RVA 0x5e1c20, 48 bytes.
- BSInlineHost6babf0, RVA 0x6babf0, 48 bytes.
- BSInlineHost6bac20, RVA 0x6bac20, 48 bytes.
- BSInlineHost71c360, RVA 0x71c360, 48 bytes.
- BSInlineHost71c390, RVA 0x71c390, 48 bytes.
- BSInlineHost71c3c0, RVA 0x71c3c0, 48 bytes.
- BSInlineHost768680, RVA 0x768680, 48 bytes.
- BSInlineHost7686b0, RVA 0x7686b0, 48 bytes.
- BSInlineHost7c4970, RVA 0x7c4970, 48 bytes.
- BSInlineHost816bc0, RVA 0x816bc0, 48 bytes.
- BSInlineHost816bf0, RVA 0x816bf0, 48 bytes.
- BSInlineHost816c20, RVA 0x816c20, 48 bytes.
- BSInlineHost816c50, RVA 0x816c50, 48 bytes.
- BSInlineHost822980, RVA 0x822980, 48 bytes.
- BSInlineHost82b730, RVA 0x82b730, 48 bytes.
- BSInlineHost84d8d0, RVA 0x84d8d0, 48 bytes.
- BSInlineHost855420, RVA 0x855420, 48 bytes.
- BSInlineHost860910, RVA 0x860910, 48 bytes.
- BSInlineHost865cb0, RVA 0x865cb0, 48 bytes.
- BSInlineHost8727e0, RVA 0x8727e0, 48 bytes.
- BSInlineHost8788f0, RVA 0x8788f0, 48 bytes.
- BSInlineHost89c8c0, RVA 0x89c8c0, 48 bytes.
- BSInlineHost89c8f0, RVA 0x89c8f0, 48 bytes.
- BSInlineHost8a6740, RVA 0x8a6740, 48 bytes.
- BSInlineHost8b6780, RVA 0x8b6780, 48 bytes.
- BSInlineHost8ba2a0, RVA 0x8ba2a0, 48 bytes.
- BSInlineHost8bb060, RVA 0x8bb060, 48 bytes.
- BSInlineHost8bb4d0, RVA 0x8bb4d0, 48 bytes.
- BSInlineHost8bb800, RVA 0x8bb800, 48 bytes.
- BSInlineHost8bbb00, RVA 0x8bbb00, 48 bytes.
- BSInlineHost8bc1d0, RVA 0x8bc1d0, 48 bytes.
- BSInlineHost8bc7b0, RVA 0x8bc7b0, 48 bytes.
- BSInlineHost8c18b0, RVA 0x8c18b0, 48 bytes.
- BSInlineHost8c18e0, RVA 0x8c18e0, 48 bytes.
- BSInlineHost8c3d50, RVA 0x8c3d50, 48 bytes.
- BSInlineHost8d6770, RVA 0x8d6770, 48 bytes.
- BSInlineHost8dd740, RVA 0x8dd740, 48 bytes.
- BSInlineHost8e74f0, RVA 0x8e74f0, 48 bytes.
- BSInlineHost966b90, RVA 0x966b90, 48 bytes.
- BSInlineHostee1220, RVA 0xee1220, 48 bytes.
- BSInlineHosteeba70, RVA 0xeeba70, 48 bytes.
- BSInlineHostefbe30, RVA 0xefbe30, 48 bytes.
- BSInlineHostefce10, RVA 0xefce10, 48 bytes.
- BSInlineHostf05860, RVA 0xf05860, 48 bytes.
- BSInlineHostf0a6f0, RVA 0xf0a6f0, 48 bytes.
- BSInlineHostf131d0, RVA 0xf131d0, 48 bytes.
- BSInlineHostf5afa0, RVA 0xf5afa0, 48 bytes.
- BSInlineHostf5afd0, RVA 0xf5afd0, 48 bytes.
- BSInlineHostf5b000, RVA 0xf5b000, 48 bytes.
- BSInlineHostf5b030, RVA 0xf5b030, 48 bytes.
- BSInlineHostf5b060, RVA 0xf5b060, 48 bytes.
- BSInlineHostf5b090, RVA 0xf5b090, 48 bytes.
- BSInlineHostf5d460, RVA 0xf5d460, 48 bytes.
- BSInlineHostf61170, RVA 0xf61170, 48 bytes.
- BSInlineHostf622b0, RVA 0xf622b0, 48 bytes.
- BSInlineHostf64440, RVA 0xf64440, 48 bytes.
- BSInlineHostf67020, RVA 0xf67020, 48 bytes.
- BSInlineHostf72890, RVA 0xf72890, 48 bytes.
- BSInlineHostf75550, RVA 0xf75550, 48 bytes.
- BSInlineHostf7dd40, RVA 0xf7dd40, 48 bytes.
- BSInlineHostf85e80, RVA 0xf85e80, 48 bytes.
- BSInlineHostf9a080, RVA 0xf9a080, 48 bytes.
- BSInlineHostf9c070, RVA 0xf9c070, 48 bytes.
- BSInlineHostfb46f0, RVA 0xfb46f0, 48 bytes.
- BSInlineHostfcda20, RVA 0xfcda20, 48 bytes.
- BSInlineHostfd2940, RVA 0xfd2940, 48 bytes.
- BSInlineHostffe200, RVA 0xffe200, 48 bytes.
- BSInlineHostffe230, RVA 0xffe230, 48 bytes.
- BSInlineHost1054e00, RVA 0x1054e00, 48 bytes.
- BSInlineHost1068f10, RVA 0x1068f10, 48 bytes.
- BSInlineHost10690f0, RVA 0x10690f0, 48 bytes.
- BSInlineHost107a9e0, RVA 0x107a9e0, 48 bytes.
- BSInlineHost107aa10, RVA 0x107aa10, 48 bytes.
- BSInlineHost10870c0, RVA 0x10870c0, 48 bytes.
- BSInlineHost1099370, RVA 0x1099370, 48 bytes.
- BSInlineHost12114f0, RVA 0x12114f0, 48 bytes.
- BSInlineHost14ed280, RVA 0x14ed280, 48 bytes.
- BSInlineHost1534b20, RVA 0x1534b20, 48 bytes.
- BSInlineHost153b090, RVA 0x153b090, 48 bytes.
- BSInlineHost15754d0, RVA 0x15754d0, 48 bytes.
