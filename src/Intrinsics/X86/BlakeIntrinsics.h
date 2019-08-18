// Copyright (c) 2019, Zpalmtree
//
// Please see the included LICENSE file for more information.

// Copyright (c) 2017, YANDEX LLC
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without modification, are permitted provided 
// that the following conditions are met:
// 
// 1. Redistributions of source code must retain the above copyright notice, this list of conditions and 
// the following disclaimer.
// 
// 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and 
// the following disclaimer in the documentation and/or other materials provided with the distribution.
// 
// 3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote 
// products derived from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, 
// INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#pragma once

#include <cstdint>

#include "Blake2/Blake2b.h"
#include "cpu_features/include/cpuinfo_x86.h"
#include "Intrinsics/X86/IncludeIntrinsics.h"

static const cpu_features::X86Features features = cpu_features::GetX86Info().features;

static const bool hasAVX512 = features.avx512f;
static const bool hasAVX2 = features.avx2;
static const bool hasSSE41 = features.sse4_1;
static const bool hasSSSE3 = features.ssse3;
static const bool hasSSE2 = features.sse2;

static const __m128i IV128[4] = {
    _mm_set_epi64x(0xbb67ae8584caa73bULL, 0x6a09e667f3bcc908ULL),
    _mm_set_epi64x(0xa54ff53a5f1d36f1ULL, 0x3c6ef372fe94f82bULL),
    _mm_set_epi64x(0x9b05688c2b3e6c1fULL, 0x510e527fade682d1ULL),
    _mm_set_epi64x(0x5be0cd19137e2179ULL, 0x1f83d9abfb41bd6bULL)
};

void compressAVX512(
    std::vector<uint64_t> &hash,
    std::vector<uint64_t> &chunk,
    std::vector<uint64_t> &compressXorFlags);
