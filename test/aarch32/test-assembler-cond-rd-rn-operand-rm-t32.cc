// Copyright 2016, VIXL authors
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//   * Redistributions of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//   * Redistributions in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//   * Neither the name of ARM Limited nor the names of its contributors may be
//     used to endorse or promote products derived from this software without
//     specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


// -----------------------------------------------------------------------------
// This file is auto generated from the
// test/aarch32/config/template-assembler-aarch32.cc.in template file using
// tools/generate_tests.py.
//
// PLEASE DO NOT EDIT.
// -----------------------------------------------------------------------------


#include "test-runner.h"

#include "test-utils.h"
#include "test-utils-aarch32.h"

#include "aarch32/assembler-aarch32.h"
#include "aarch32/macro-assembler-aarch32.h"

#define BUF_SIZE (4096)

namespace vixl {
namespace aarch32 {

// List of instruction mnemonics.
#define FOREACH_INSTRUCTION(M) \
  M(adc)                       \
  M(adcs)                      \
  M(add)                       \
  M(adds)                      \
  M(and_)                      \
  M(ands)                      \
  M(bic)                       \
  M(bics)                      \
  M(eor)                       \
  M(eors)                      \
  M(orn)                       \
  M(orns)                      \
  M(orr)                       \
  M(orrs)                      \
  M(rsb)                       \
  M(rsbs)                      \
  M(sbc)                       \
  M(sbcs)                      \
  M(sub)                       \
  M(subs)                      \
  M(sxtab)                     \
  M(sxtab16)                   \
  M(sxtah)                     \
  M(uxtab)                     \
  M(uxtab16)                   \
  M(uxtah)                     \
  M(asr)                       \
  M(asrs)                      \
  M(lsl)                       \
  M(lsls)                      \
  M(lsr)                       \
  M(lsrs)                      \
  M(ror)                       \
  M(rors)


// Values to be passed to the assembler to produce the instruction under test.
struct Operands {
  Condition cond;
  Register rd;
  Register rn;
  Register rm;
};

// This structure contains all data needed to test one specific
// instruction.
struct TestData {
  // The `operands` field represents what to pass to the assembler to
  // produce the instruction.
  Operands operands;
  // True if we need to generate an IT instruction for this test to be valid.
  bool in_it_block;
  // The condition to give the IT instruction, this will be set to "al" by
  // default.
  Condition it_condition;
  // Description of the operands, used for error reporting.
  const char* operands_description;
  // Unique identifier, used for generating traces.
  const char* identifier;
};

struct TestResult {
  size_t size;
  const byte* encoding;
};

// Each element of this array produce one instruction encoding.
static const TestData kTests[] =
    {{{al, r12, r9, r11}, false, al, "al r12 r9 r11", "al_r12_r9_r11"},
     {{al, r3, r4, r10}, false, al, "al r3 r4 r10", "al_r3_r4_r10"},
     {{al, r2, r0, r12}, false, al, "al r2 r0 r12", "al_r2_r0_r12"},
     {{al, r9, r9, r13}, false, al, "al r9 r9 r13", "al_r9_r9_r13"},
     {{al, r11, r2, r4}, false, al, "al r11 r2 r4", "al_r11_r2_r4"},
     {{al, r7, r3, r7}, false, al, "al r7 r3 r7", "al_r7_r3_r7"},
     {{al, r11, r6, r9}, false, al, "al r11 r6 r9", "al_r11_r6_r9"},
     {{al, r8, r7, r11}, false, al, "al r8 r7 r11", "al_r8_r7_r11"},
     {{al, r14, r12, r14}, false, al, "al r14 r12 r14", "al_r14_r12_r14"},
     {{al, r8, r5, r8}, false, al, "al r8 r5 r8", "al_r8_r5_r8"},
     {{al, r4, r4, r2}, false, al, "al r4 r4 r2", "al_r4_r4_r2"},
     {{al, r10, r6, r7}, false, al, "al r10 r6 r7", "al_r10_r6_r7"},
     {{al, r9, r13, r7}, false, al, "al r9 r13 r7", "al_r9_r13_r7"},
     {{al, r6, r8, r5}, false, al, "al r6 r8 r5", "al_r6_r8_r5"},
     {{al, r5, r10, r6}, false, al, "al r5 r10 r6", "al_r5_r10_r6"},
     {{al, r14, r7, r11}, false, al, "al r14 r7 r11", "al_r14_r7_r11"},
     {{al, r11, r4, r14}, false, al, "al r11 r4 r14", "al_r11_r4_r14"},
     {{al, r5, r6, r4}, false, al, "al r5 r6 r4", "al_r5_r6_r4"},
     {{al, r4, r9, r0}, false, al, "al r4 r9 r0", "al_r4_r9_r0"},
     {{al, r5, r0, r8}, false, al, "al r5 r0 r8", "al_r5_r0_r8"},
     {{al, r6, r2, r10}, false, al, "al r6 r2 r10", "al_r6_r2_r10"},
     {{al, r0, r11, r14}, false, al, "al r0 r11 r14", "al_r0_r11_r14"},
     {{al, r3, r10, r1}, false, al, "al r3 r10 r1", "al_r3_r10_r1"},
     {{al, r13, r7, r8}, false, al, "al r13 r7 r8", "al_r13_r7_r8"},
     {{al, r12, r5, r2}, false, al, "al r12 r5 r2", "al_r12_r5_r2"},
     {{al, r7, r14, r7}, false, al, "al r7 r14 r7", "al_r7_r14_r7"},
     {{al, r6, r6, r10}, false, al, "al r6 r6 r10", "al_r6_r6_r10"},
     {{al, r2, r0, r2}, false, al, "al r2 r0 r2", "al_r2_r0_r2"},
     {{al, r8, r14, r11}, false, al, "al r8 r14 r11", "al_r8_r14_r11"},
     {{al, r10, r14, r2}, false, al, "al r10 r14 r2", "al_r10_r14_r2"},
     {{al, r14, r11, r6}, false, al, "al r14 r11 r6", "al_r14_r11_r6"},
     {{al, r9, r2, r11}, false, al, "al r9 r2 r11", "al_r9_r2_r11"},
     {{al, r9, r9, r10}, false, al, "al r9 r9 r10", "al_r9_r9_r10"},
     {{al, r11, r9, r13}, false, al, "al r11 r9 r13", "al_r11_r9_r13"},
     {{al, r14, r12, r7}, false, al, "al r14 r12 r7", "al_r14_r12_r7"},
     {{al, r9, r4, r7}, false, al, "al r9 r4 r7", "al_r9_r4_r7"},
     {{al, r0, r7, r8}, false, al, "al r0 r7 r8", "al_r0_r7_r8"},
     {{al, r12, r4, r4}, false, al, "al r12 r4 r4", "al_r12_r4_r4"},
     {{al, r7, r9, r7}, false, al, "al r7 r9 r7", "al_r7_r9_r7"},
     {{al, r1, r13, r13}, false, al, "al r1 r13 r13", "al_r1_r13_r13"},
     {{al, r13, r11, r11}, false, al, "al r13 r11 r11", "al_r13_r11_r11"},
     {{al, r0, r0, r7}, false, al, "al r0 r0 r7", "al_r0_r0_r7"},
     {{al, r2, r12, r1}, false, al, "al r2 r12 r1", "al_r2_r12_r1"},
     {{al, r8, r2, r5}, false, al, "al r8 r2 r5", "al_r8_r2_r5"},
     {{al, r6, r0, r1}, false, al, "al r6 r0 r1", "al_r6_r0_r1"},
     {{al, r9, r13, r0}, false, al, "al r9 r13 r0", "al_r9_r13_r0"},
     {{al, r12, r5, r1}, false, al, "al r12 r5 r1", "al_r12_r5_r1"},
     {{al, r14, r3, r4}, false, al, "al r14 r3 r4", "al_r14_r3_r4"},
     {{al, r5, r9, r2}, false, al, "al r5 r9 r2", "al_r5_r9_r2"},
     {{al, r8, r9, r10}, false, al, "al r8 r9 r10", "al_r8_r9_r10"},
     {{al, r0, r11, r12}, false, al, "al r0 r11 r12", "al_r0_r11_r12"},
     {{al, r2, r8, r4}, false, al, "al r2 r8 r4", "al_r2_r8_r4"},
     {{al, r13, r6, r9}, false, al, "al r13 r6 r9", "al_r13_r6_r9"},
     {{al, r2, r12, r9}, false, al, "al r2 r12 r9", "al_r2_r12_r9"},
     {{al, r12, r0, r3}, false, al, "al r12 r0 r3", "al_r12_r0_r3"},
     {{al, r13, r1, r1}, false, al, "al r13 r1 r1", "al_r13_r1_r1"},
     {{al, r14, r6, r7}, false, al, "al r14 r6 r7", "al_r14_r6_r7"},
     {{al, r8, r6, r6}, false, al, "al r8 r6 r6", "al_r8_r6_r6"},
     {{al, r14, r9, r11}, false, al, "al r14 r9 r11", "al_r14_r9_r11"},
     {{al, r6, r3, r3}, false, al, "al r6 r3 r3", "al_r6_r3_r3"},
     {{al, r6, r8, r14}, false, al, "al r6 r8 r14", "al_r6_r8_r14"},
     {{al, r8, r3, r6}, false, al, "al r8 r3 r6", "al_r8_r3_r6"},
     {{al, r12, r6, r11}, false, al, "al r12 r6 r11", "al_r12_r6_r11"},
     {{al, r5, r8, r14}, false, al, "al r5 r8 r14", "al_r5_r8_r14"},
     {{al, r4, r10, r8}, false, al, "al r4 r10 r8", "al_r4_r10_r8"},
     {{al, r4, r12, r14}, false, al, "al r4 r12 r14", "al_r4_r12_r14"},
     {{al, r14, r8, r10}, false, al, "al r14 r8 r10", "al_r14_r8_r10"},
     {{al, r2, r10, r8}, false, al, "al r2 r10 r8", "al_r2_r10_r8"},
     {{al, r0, r14, r7}, false, al, "al r0 r14 r7", "al_r0_r14_r7"},
     {{al, r9, r13, r9}, false, al, "al r9 r13 r9", "al_r9_r13_r9"},
     {{al, r7, r0, r14}, false, al, "al r7 r0 r14", "al_r7_r0_r14"},
     {{al, r14, r4, r9}, false, al, "al r14 r4 r9", "al_r14_r4_r9"},
     {{al, r1, r1, r11}, false, al, "al r1 r1 r11", "al_r1_r1_r11"},
     {{al, r11, r6, r1}, false, al, "al r11 r6 r1", "al_r11_r6_r1"},
     {{al, r2, r8, r2}, false, al, "al r2 r8 r2", "al_r2_r8_r2"},
     {{al, r1, r8, r4}, false, al, "al r1 r8 r4", "al_r1_r8_r4"},
     {{al, r2, r3, r3}, false, al, "al r2 r3 r3", "al_r2_r3_r3"},
     {{al, r4, r8, r8}, false, al, "al r4 r8 r8", "al_r4_r8_r8"},
     {{al, r6, r4, r1}, false, al, "al r6 r4 r1", "al_r6_r4_r1"},
     {{al, r1, r10, r3}, false, al, "al r1 r10 r3", "al_r1_r10_r3"},
     {{al, r11, r14, r8}, false, al, "al r11 r14 r8", "al_r11_r14_r8"},
     {{al, r1, r6, r3}, false, al, "al r1 r6 r3", "al_r1_r6_r3"},
     {{al, r3, r13, r10}, false, al, "al r3 r13 r10", "al_r3_r13_r10"},
     {{al, r6, r13, r8}, false, al, "al r6 r13 r8", "al_r6_r13_r8"},
     {{al, r12, r3, r13}, false, al, "al r12 r3 r13", "al_r12_r3_r13"},
     {{al, r8, r2, r4}, false, al, "al r8 r2 r4", "al_r8_r2_r4"},
     {{al, r10, r1, r7}, false, al, "al r10 r1 r7", "al_r10_r1_r7"},
     {{al, r11, r7, r12}, false, al, "al r11 r7 r12", "al_r11_r7_r12"},
     {{al, r4, r4, r7}, false, al, "al r4 r4 r7", "al_r4_r4_r7"},
     {{al, r1, r7, r9}, false, al, "al r1 r7 r9", "al_r1_r7_r9"},
     {{al, r14, r3, r0}, false, al, "al r14 r3 r0", "al_r14_r3_r0"},
     {{al, r10, r4, r7}, false, al, "al r10 r4 r7", "al_r10_r4_r7"},
     {{al, r4, r9, r11}, false, al, "al r4 r9 r11", "al_r4_r9_r11"},
     {{al, r2, r2, r0}, false, al, "al r2 r2 r0", "al_r2_r2_r0"},
     {{al, r1, r6, r12}, false, al, "al r1 r6 r12", "al_r1_r6_r12"},
     {{al, r0, r5, r6}, false, al, "al r0 r5 r6", "al_r0_r5_r6"},
     {{al, r8, r11, r10}, false, al, "al r8 r11 r10", "al_r8_r11_r10"},
     {{al, r10, r4, r3}, false, al, "al r10 r4 r3", "al_r10_r4_r3"},
     {{al, r1, r0, r3}, false, al, "al r1 r0 r3", "al_r1_r0_r3"},
     {{al, r11, r8, r6}, false, al, "al r11 r8 r6", "al_r11_r8_r6"},
     {{al, r8, r9, r0}, false, al, "al r8 r9 r0", "al_r8_r9_r0"},
     {{al, r5, r8, r7}, false, al, "al r5 r8 r7", "al_r5_r8_r7"},
     {{al, r9, r4, r1}, false, al, "al r9 r4 r1", "al_r9_r4_r1"},
     {{al, r1, r11, r12}, false, al, "al r1 r11 r12", "al_r1_r11_r12"},
     {{al, r5, r5, r11}, false, al, "al r5 r5 r11", "al_r5_r5_r11"},
     {{al, r4, r6, r13}, false, al, "al r4 r6 r13", "al_r4_r6_r13"},
     {{al, r14, r1, r11}, false, al, "al r14 r1 r11", "al_r14_r1_r11"},
     {{al, r11, r0, r12}, false, al, "al r11 r0 r12", "al_r11_r0_r12"},
     {{al, r9, r2, r0}, false, al, "al r9 r2 r0", "al_r9_r2_r0"},
     {{al, r11, r5, r10}, false, al, "al r11 r5 r10", "al_r11_r5_r10"},
     {{al, r1, r11, r2}, false, al, "al r1 r11 r2", "al_r1_r11_r2"},
     {{al, r14, r2, r9}, false, al, "al r14 r2 r9", "al_r14_r2_r9"},
     {{al, r4, r10, r3}, false, al, "al r4 r10 r3", "al_r4_r10_r3"},
     {{al, r1, r5, r11}, false, al, "al r1 r5 r11", "al_r1_r5_r11"},
     {{al, r3, r10, r4}, false, al, "al r3 r10 r4", "al_r3_r10_r4"},
     {{al, r1, r7, r10}, false, al, "al r1 r7 r10", "al_r1_r7_r10"},
     {{al, r14, r8, r14}, false, al, "al r14 r8 r14", "al_r14_r8_r14"},
     {{al, r12, r11, r4}, false, al, "al r12 r11 r4", "al_r12_r11_r4"},
     {{al, r7, r9, r6}, false, al, "al r7 r9 r6", "al_r7_r9_r6"},
     {{al, r8, r8, r9}, false, al, "al r8 r8 r9", "al_r8_r8_r9"},
     {{al, r12, r5, r0}, false, al, "al r12 r5 r0", "al_r12_r5_r0"},
     {{al, r6, r11, r12}, false, al, "al r6 r11 r12", "al_r6_r11_r12"},
     {{al, r9, r5, r11}, false, al, "al r9 r5 r11", "al_r9_r5_r11"},
     {{al, r6, r14, r6}, false, al, "al r6 r14 r6", "al_r6_r14_r6"},
     {{al, r0, r3, r7}, false, al, "al r0 r3 r7", "al_r0_r3_r7"},
     {{al, r9, r5, r10}, false, al, "al r9 r5 r10", "al_r9_r5_r10"},
     {{al, r4, r1, r6}, false, al, "al r4 r1 r6", "al_r4_r1_r6"},
     {{al, r6, r1, r13}, false, al, "al r6 r1 r13", "al_r6_r1_r13"},
     {{al, r13, r1, r4}, false, al, "al r13 r1 r4", "al_r13_r1_r4"},
     {{al, r10, r11, r9}, false, al, "al r10 r11 r9", "al_r10_r11_r9"},
     {{al, r14, r13, r7}, false, al, "al r14 r13 r7", "al_r14_r13_r7"},
     {{al, r5, r3, r13}, false, al, "al r5 r3 r13", "al_r5_r3_r13"},
     {{al, r8, r9, r6}, false, al, "al r8 r9 r6", "al_r8_r9_r6"},
     {{al, r9, r10, r5}, false, al, "al r9 r10 r5", "al_r9_r10_r5"},
     {{al, r12, r11, r7}, false, al, "al r12 r11 r7", "al_r12_r11_r7"},
     {{al, r5, r13, r12}, false, al, "al r5 r13 r12", "al_r5_r13_r12"},
     {{al, r9, r13, r8}, false, al, "al r9 r13 r8", "al_r9_r13_r8"},
     {{al, r5, r3, r9}, false, al, "al r5 r3 r9", "al_r5_r3_r9"},
     {{al, r8, r5, r14}, false, al, "al r8 r5 r14", "al_r8_r5_r14"},
     {{al, r8, r10, r10}, false, al, "al r8 r10 r10", "al_r8_r10_r10"},
     {{al, r2, r6, r4}, false, al, "al r2 r6 r4", "al_r2_r6_r4"},
     {{al, r10, r7, r1}, false, al, "al r10 r7 r1", "al_r10_r7_r1"},
     {{al, r4, r0, r5}, false, al, "al r4 r0 r5", "al_r4_r0_r5"},
     {{al, r7, r12, r9}, false, al, "al r7 r12 r9", "al_r7_r12_r9"},
     {{al, r11, r11, r10}, false, al, "al r11 r11 r10", "al_r11_r11_r10"},
     {{al, r3, r9, r13}, false, al, "al r3 r9 r13", "al_r3_r9_r13"},
     {{al, r10, r4, r4}, false, al, "al r10 r4 r4", "al_r10_r4_r4"},
     {{al, r13, r1, r11}, false, al, "al r13 r1 r11", "al_r13_r1_r11"},
     {{al, r2, r13, r0}, false, al, "al r2 r13 r0", "al_r2_r13_r0"},
     {{al, r11, r4, r1}, false, al, "al r11 r4 r1", "al_r11_r4_r1"},
     {{al, r1, r3, r10}, false, al, "al r1 r3 r10", "al_r1_r3_r10"},
     {{al, r4, r13, r2}, false, al, "al r4 r13 r2", "al_r4_r13_r2"},
     {{al, r4, r8, r0}, false, al, "al r4 r8 r0", "al_r4_r8_r0"},
     {{al, r9, r6, r1}, false, al, "al r9 r6 r1", "al_r9_r6_r1"},
     {{al, r14, r14, r10}, false, al, "al r14 r14 r10", "al_r14_r14_r10"},
     {{al, r9, r9, r2}, false, al, "al r9 r9 r2", "al_r9_r9_r2"},
     {{al, r14, r3, r12}, false, al, "al r14 r3 r12", "al_r14_r3_r12"},
     {{al, r9, r4, r0}, false, al, "al r9 r4 r0", "al_r9_r4_r0"},
     {{al, r10, r10, r11}, false, al, "al r10 r10 r11", "al_r10_r10_r11"},
     {{al, r0, r1, r13}, false, al, "al r0 r1 r13", "al_r0_r1_r13"},
     {{al, r10, r8, r13}, false, al, "al r10 r8 r13", "al_r10_r8_r13"},
     {{al, r8, r0, r2}, false, al, "al r8 r0 r2", "al_r8_r0_r2"},
     {{al, r2, r0, r7}, false, al, "al r2 r0 r7", "al_r2_r0_r7"},
     {{al, r11, r12, r10}, false, al, "al r11 r12 r10", "al_r11_r12_r10"},
     {{al, r0, r5, r3}, false, al, "al r0 r5 r3", "al_r0_r5_r3"},
     {{al, r3, r2, r0}, false, al, "al r3 r2 r0", "al_r3_r2_r0"},
     {{al, r12, r10, r1}, false, al, "al r12 r10 r1", "al_r12_r10_r1"},
     {{al, r3, r2, r14}, false, al, "al r3 r2 r14", "al_r3_r2_r14"},
     {{al, r4, r12, r1}, false, al, "al r4 r12 r1", "al_r4_r12_r1"},
     {{al, r14, r8, r3}, false, al, "al r14 r8 r3", "al_r14_r8_r3"},
     {{al, r4, r14, r12}, false, al, "al r4 r14 r12", "al_r4_r14_r12"},
     {{al, r3, r3, r4}, false, al, "al r3 r3 r4", "al_r3_r3_r4"},
     {{al, r10, r13, r4}, false, al, "al r10 r13 r4", "al_r10_r13_r4"},
     {{al, r9, r2, r12}, false, al, "al r9 r2 r12", "al_r9_r2_r12"},
     {{al, r5, r13, r7}, false, al, "al r5 r13 r7", "al_r5_r13_r7"},
     {{al, r13, r12, r9}, false, al, "al r13 r12 r9", "al_r13_r12_r9"},
     {{al, r4, r4, r5}, false, al, "al r4 r4 r5", "al_r4_r4_r5"},
     {{al, r1, r8, r12}, false, al, "al r1 r8 r12", "al_r1_r8_r12"},
     {{al, r1, r8, r6}, false, al, "al r1 r8 r6", "al_r1_r8_r6"},
     {{al, r14, r11, r4}, false, al, "al r14 r11 r4", "al_r14_r11_r4"},
     {{al, r14, r9, r3}, false, al, "al r14 r9 r3", "al_r14_r9_r3"},
     {{al, r11, r5, r9}, false, al, "al r11 r5 r9", "al_r11_r5_r9"},
     {{al, r3, r10, r10}, false, al, "al r3 r10 r10", "al_r3_r10_r10"},
     {{al, r6, r13, r14}, false, al, "al r6 r13 r14", "al_r6_r13_r14"},
     {{al, r1, r8, r14}, false, al, "al r1 r8 r14", "al_r1_r8_r14"},
     {{al, r10, r1, r10}, false, al, "al r10 r1 r10", "al_r10_r1_r10"},
     {{al, r8, r1, r1}, false, al, "al r8 r1 r1", "al_r8_r1_r1"},
     {{al, r10, r10, r4}, false, al, "al r10 r10 r4", "al_r10_r10_r4"},
     {{al, r9, r11, r13}, false, al, "al r9 r11 r13", "al_r9_r11_r13"},
     {{al, r14, r8, r8}, false, al, "al r14 r8 r8", "al_r14_r8_r8"},
     {{al, r13, r4, r10}, false, al, "al r13 r4 r10", "al_r13_r4_r10"},
     {{al, r14, r3, r1}, false, al, "al r14 r3 r1", "al_r14_r3_r1"},
     {{al, r5, r11, r14}, false, al, "al r5 r11 r14", "al_r5_r11_r14"},
     {{al, r2, r6, r6}, false, al, "al r2 r6 r6", "al_r2_r6_r6"},
     {{al, r14, r1, r14}, false, al, "al r14 r1 r14", "al_r14_r1_r14"},
     {{al, r5, r10, r0}, false, al, "al r5 r10 r0", "al_r5_r10_r0"},
     {{al, r11, r2, r5}, false, al, "al r11 r2 r5", "al_r11_r2_r5"},
     {{al, r4, r9, r1}, false, al, "al r4 r9 r1", "al_r4_r9_r1"},
     {{al, r12, r7, r2}, false, al, "al r12 r7 r2", "al_r12_r7_r2"},
     {{al, r10, r12, r9}, false, al, "al r10 r12 r9", "al_r10_r12_r9"},
     {{al, r2, r3, r12}, false, al, "al r2 r3 r12", "al_r2_r3_r12"},
     {{al, r7, r6, r3}, false, al, "al r7 r6 r3", "al_r7_r6_r3"},
     {{al, r11, r11, r8}, false, al, "al r11 r11 r8", "al_r11_r11_r8"},
     {{al, r6, r14, r10}, false, al, "al r6 r14 r10", "al_r6_r14_r10"},
     {{al, r13, r2, r4}, false, al, "al r13 r2 r4", "al_r13_r2_r4"},
     {{al, r5, r5, r4}, false, al, "al r5 r5 r4", "al_r5_r5_r4"},
     {{al, r9, r1, r2}, false, al, "al r9 r1 r2", "al_r9_r1_r2"},
     {{al, r3, r10, r14}, false, al, "al r3 r10 r14", "al_r3_r10_r14"},
     {{al, r1, r9, r0}, false, al, "al r1 r9 r0", "al_r1_r9_r0"},
     {{al, r4, r10, r12}, false, al, "al r4 r10 r12", "al_r4_r10_r12"},
     {{al, r8, r9, r2}, false, al, "al r8 r9 r2", "al_r8_r9_r2"},
     {{al, r0, r14, r0}, false, al, "al r0 r14 r0", "al_r0_r14_r0"},
     {{al, r14, r11, r11}, false, al, "al r14 r11 r11", "al_r14_r11_r11"},
     {{al, r9, r12, r5}, false, al, "al r9 r12 r5", "al_r9_r12_r5"},
     {{al, r11, r8, r3}, false, al, "al r11 r8 r3", "al_r11_r8_r3"},
     {{al, r13, r11, r8}, false, al, "al r13 r11 r8", "al_r13_r11_r8"},
     {{al, r4, r13, r12}, false, al, "al r4 r13 r12", "al_r4_r13_r12"},
     {{al, r10, r13, r6}, false, al, "al r10 r13 r6", "al_r10_r13_r6"},
     {{al, r14, r7, r13}, false, al, "al r14 r7 r13", "al_r14_r7_r13"},
     {{al, r10, r2, r12}, false, al, "al r10 r2 r12", "al_r10_r2_r12"},
     {{al, r6, r9, r4}, false, al, "al r6 r9 r4", "al_r6_r9_r4"},
     {{al, r9, r8, r2}, false, al, "al r9 r8 r2", "al_r9_r8_r2"},
     {{al, r14, r5, r5}, false, al, "al r14 r5 r5", "al_r14_r5_r5"},
     {{al, r11, r14, r4}, false, al, "al r11 r14 r4", "al_r11_r14_r4"},
     {{al, r8, r0, r12}, false, al, "al r8 r0 r12", "al_r8_r0_r12"},
     {{al, r11, r6, r5}, false, al, "al r11 r6 r5", "al_r11_r6_r5"},
     {{al, r11, r13, r9}, false, al, "al r11 r13 r9", "al_r11_r13_r9"},
     {{al, r14, r2, r0}, false, al, "al r14 r2 r0", "al_r14_r2_r0"},
     {{al, r7, r7, r10}, false, al, "al r7 r7 r10", "al_r7_r7_r10"},
     {{al, r10, r12, r2}, false, al, "al r10 r12 r2", "al_r10_r12_r2"},
     {{al, r9, r10, r9}, false, al, "al r9 r10 r9", "al_r9_r10_r9"},
     {{al, r11, r0, r9}, false, al, "al r11 r0 r9", "al_r11_r0_r9"},
     {{al, r3, r5, r7}, false, al, "al r3 r5 r7", "al_r3_r5_r7"},
     {{al, r0, r8, r0}, false, al, "al r0 r8 r0", "al_r0_r8_r0"},
     {{al, r1, r11, r4}, false, al, "al r1 r11 r4", "al_r1_r11_r4"},
     {{al, r1, r14, r3}, false, al, "al r1 r14 r3", "al_r1_r14_r3"},
     {{al, r12, r12, r13}, false, al, "al r12 r12 r13", "al_r12_r12_r13"},
     {{al, r14, r13, r1}, false, al, "al r14 r13 r1", "al_r14_r13_r1"},
     {{al, r8, r7, r4}, false, al, "al r8 r7 r4", "al_r8_r7_r4"},
     {{al, r13, r12, r7}, false, al, "al r13 r12 r7", "al_r13_r12_r7"},
     {{al, r5, r12, r14}, false, al, "al r5 r12 r14", "al_r5_r12_r14"},
     {{al, r2, r2, r14}, false, al, "al r2 r2 r14", "al_r2_r2_r14"},
     {{al, r6, r5, r9}, false, al, "al r6 r5 r9", "al_r6_r5_r9"},
     {{al, r8, r1, r3}, false, al, "al r8 r1 r3", "al_r8_r1_r3"},
     {{al, r9, r10, r1}, false, al, "al r9 r10 r1", "al_r9_r10_r1"},
     {{al, r0, r6, r7}, false, al, "al r0 r6 r7", "al_r0_r6_r7"},
     {{al, r13, r9, r1}, false, al, "al r13 r9 r1", "al_r13_r9_r1"},
     {{al, r11, r4, r8}, false, al, "al r11 r4 r8", "al_r11_r4_r8"},
     {{al, r10, r1, r5}, false, al, "al r10 r1 r5", "al_r10_r1_r5"},
     {{al, r7, r4, r6}, false, al, "al r7 r4 r6", "al_r7_r4_r6"},
     {{al, r14, r3, r13}, false, al, "al r14 r3 r13", "al_r14_r3_r13"},
     {{al, r9, r0, r1}, false, al, "al r9 r0 r1", "al_r9_r0_r1"},
     {{al, r6, r10, r10}, false, al, "al r6 r10 r10", "al_r6_r10_r10"},
     {{al, r13, r8, r8}, false, al, "al r13 r8 r8", "al_r13_r8_r8"},
     {{al, r1, r1, r2}, false, al, "al r1 r1 r2", "al_r1_r1_r2"},
     {{al, r8, r1, r9}, false, al, "al r8 r1 r9", "al_r8_r1_r9"},
     {{al, r4, r7, r5}, false, al, "al r4 r7 r5", "al_r4_r7_r5"},
     {{al, r2, r13, r1}, false, al, "al r2 r13 r1", "al_r2_r13_r1"},
     {{al, r9, r9, r5}, false, al, "al r9 r9 r5", "al_r9_r9_r5"},
     {{al, r11, r12, r8}, false, al, "al r11 r12 r8", "al_r11_r12_r8"},
     {{al, r7, r0, r3}, false, al, "al r7 r0 r3", "al_r7_r0_r3"},
     {{al, r3, r4, r13}, false, al, "al r3 r4 r13", "al_r3_r4_r13"},
     {{al, r7, r7, r9}, false, al, "al r7 r7 r9", "al_r7_r7_r9"},
     {{al, r2, r9, r5}, false, al, "al r2 r9 r5", "al_r2_r9_r5"},
     {{al, r13, r2, r0}, false, al, "al r13 r2 r0", "al_r13_r2_r0"},
     {{al, r8, r4, r2}, false, al, "al r8 r4 r2", "al_r8_r4_r2"},
     {{al, r7, r11, r11}, false, al, "al r7 r11 r11", "al_r7_r11_r11"},
     {{al, r6, r1, r2}, false, al, "al r6 r1 r2", "al_r6_r1_r2"},
     {{al, r10, r5, r7}, false, al, "al r10 r5 r7", "al_r10_r5_r7"},
     {{al, r8, r14, r2}, false, al, "al r8 r14 r2", "al_r8_r14_r2"},
     {{al, r12, r13, r5}, false, al, "al r12 r13 r5", "al_r12_r13_r5"},
     {{al, r0, r4, r8}, false, al, "al r0 r4 r8", "al_r0_r4_r8"},
     {{al, r9, r11, r12}, false, al, "al r9 r11 r12", "al_r9_r11_r12"},
     {{al, r6, r10, r5}, false, al, "al r6 r10 r5", "al_r6_r10_r5"},
     {{al, r8, r10, r1}, false, al, "al r8 r10 r1", "al_r8_r10_r1"},
     {{al, r13, r12, r4}, false, al, "al r13 r12 r4", "al_r13_r12_r4"},
     {{al, r14, r2, r11}, false, al, "al r14 r2 r11", "al_r14_r2_r11"},
     {{al, r1, r10, r7}, false, al, "al r1 r10 r7", "al_r1_r10_r7"},
     {{al, r0, r1, r9}, false, al, "al r0 r1 r9", "al_r0_r1_r9"},
     {{al, r0, r12, r11}, false, al, "al r0 r12 r11", "al_r0_r12_r11"},
     {{al, r0, r5, r13}, false, al, "al r0 r5 r13", "al_r0_r5_r13"},
     {{al, r9, r8, r12}, false, al, "al r9 r8 r12", "al_r9_r8_r12"},
     {{al, r13, r3, r14}, false, al, "al r13 r3 r14", "al_r13_r3_r14"},
     {{al, r5, r2, r10}, false, al, "al r5 r2 r10", "al_r5_r2_r10"},
     {{al, r5, r9, r3}, false, al, "al r5 r9 r3", "al_r5_r9_r3"},
     {{al, r10, r1, r8}, false, al, "al r10 r1 r8", "al_r10_r1_r8"},
     {{al, r14, r1, r9}, false, al, "al r14 r1 r9", "al_r14_r1_r9"},
     {{al, r7, r13, r2}, false, al, "al r7 r13 r2", "al_r7_r13_r2"},
     {{al, r9, r7, r8}, false, al, "al r9 r7 r8", "al_r9_r7_r8"},
     {{al, r4, r7, r13}, false, al, "al r4 r7 r13", "al_r4_r7_r13"},
     {{al, r6, r9, r12}, false, al, "al r6 r9 r12", "al_r6_r9_r12"},
     {{al, r14, r2, r8}, false, al, "al r14 r2 r8", "al_r14_r2_r8"},
     {{al, r12, r9, r8}, false, al, "al r12 r9 r8", "al_r12_r9_r8"},
     {{al, r13, r5, r8}, false, al, "al r13 r5 r8", "al_r13_r5_r8"},
     {{al, r13, r11, r3}, false, al, "al r13 r11 r3", "al_r13_r11_r3"},
     {{al, r4, r1, r9}, false, al, "al r4 r1 r9", "al_r4_r1_r9"},
     {{al, r10, r11, r13}, false, al, "al r10 r11 r13", "al_r10_r11_r13"},
     {{al, r11, r13, r5}, false, al, "al r11 r13 r5", "al_r11_r13_r5"},
     {{al, r4, r3, r13}, false, al, "al r4 r3 r13", "al_r4_r3_r13"},
     {{al, r12, r6, r3}, false, al, "al r12 r6 r3", "al_r12_r6_r3"},
     {{al, r12, r5, r3}, false, al, "al r12 r5 r3", "al_r12_r5_r3"},
     {{al, r3, r7, r2}, false, al, "al r3 r7 r2", "al_r3_r7_r2"},
     {{al, r6, r9, r10}, false, al, "al r6 r9 r10", "al_r6_r9_r10"},
     {{al, r6, r2, r1}, false, al, "al r6 r2 r1", "al_r6_r2_r1"},
     {{al, r13, r13, r1}, false, al, "al r13 r13 r1", "al_r13_r13_r1"},
     {{al, r10, r10, r12}, false, al, "al r10 r10 r12", "al_r10_r10_r12"},
     {{al, r5, r5, r3}, false, al, "al r5 r5 r3", "al_r5_r5_r3"},
     {{al, r8, r10, r14}, false, al, "al r8 r10 r14", "al_r8_r10_r14"},
     {{al, r4, r12, r6}, false, al, "al r4 r12 r6", "al_r4_r12_r6"},
     {{al, r1, r12, r5}, false, al, "al r1 r12 r5", "al_r1_r12_r5"},
     {{al, r14, r1, r12}, false, al, "al r14 r1 r12", "al_r14_r1_r12"},
     {{al, r5, r3, r10}, false, al, "al r5 r3 r10", "al_r5_r3_r10"},
     {{al, r6, r11, r8}, false, al, "al r6 r11 r8", "al_r6_r11_r8"},
     {{al, r1, r5, r7}, false, al, "al r1 r5 r7", "al_r1_r5_r7"},
     {{al, r7, r14, r8}, false, al, "al r7 r14 r8", "al_r7_r14_r8"},
     {{al, r7, r10, r11}, false, al, "al r7 r10 r11", "al_r7_r10_r11"},
     {{al, r0, r14, r11}, false, al, "al r0 r14 r11", "al_r0_r14_r11"},
     {{al, r0, r12, r5}, false, al, "al r0 r12 r5", "al_r0_r12_r5"},
     {{al, r2, r2, r3}, false, al, "al r2 r2 r3", "al_r2_r2_r3"},
     {{al, r1, r4, r7}, false, al, "al r1 r4 r7", "al_r1_r4_r7"},
     {{al, r10, r10, r1}, false, al, "al r10 r10 r1", "al_r10_r10_r1"},
     {{al, r7, r6, r10}, false, al, "al r7 r6 r10", "al_r7_r6_r10"},
     {{al, r10, r14, r9}, false, al, "al r10 r14 r9", "al_r10_r14_r9"},
     {{al, r11, r14, r14}, false, al, "al r11 r14 r14", "al_r11_r14_r14"},
     {{al, r9, r13, r6}, false, al, "al r9 r13 r6", "al_r9_r13_r6"},
     {{al, r3, r8, r13}, false, al, "al r3 r8 r13", "al_r3_r8_r13"},
     {{al, r14, r6, r8}, false, al, "al r14 r6 r8", "al_r14_r6_r8"},
     {{al, r14, r4, r4}, false, al, "al r14 r4 r4", "al_r14_r4_r4"},
     {{al, r9, r5, r3}, false, al, "al r9 r5 r3", "al_r9_r5_r3"},
     {{al, r2, r4, r14}, false, al, "al r2 r4 r14", "al_r2_r4_r14"},
     {{al, r14, r2, r12}, false, al, "al r14 r2 r12", "al_r14_r2_r12"},
     {{al, r11, r6, r2}, false, al, "al r11 r6 r2", "al_r11_r6_r2"},
     {{al, r0, r9, r12}, false, al, "al r0 r9 r12", "al_r0_r9_r12"},
     {{al, r3, r1, r14}, false, al, "al r3 r1 r14", "al_r3_r1_r14"},
     {{al, r10, r14, r1}, false, al, "al r10 r14 r1", "al_r10_r14_r1"},
     {{al, r2, r7, r13}, false, al, "al r2 r7 r13", "al_r2_r7_r13"},
     {{al, r11, r2, r13}, false, al, "al r11 r2 r13", "al_r11_r2_r13"},
     {{al, r4, r11, r12}, false, al, "al r4 r11 r12", "al_r4_r11_r12"},
     {{al, r14, r12, r0}, false, al, "al r14 r12 r0", "al_r14_r12_r0"},
     {{al, r6, r9, r8}, false, al, "al r6 r9 r8", "al_r6_r9_r8"},
     {{al, r4, r10, r11}, false, al, "al r4 r10 r11", "al_r4_r10_r11"},
     {{al, r1, r2, r2}, false, al, "al r1 r2 r2", "al_r1_r2_r2"},
     {{al, r1, r8, r5}, false, al, "al r1 r8 r5", "al_r1_r8_r5"},
     {{al, r14, r13, r6}, false, al, "al r14 r13 r6", "al_r14_r13_r6"},
     {{al, r5, r12, r10}, false, al, "al r5 r12 r10", "al_r5_r12_r10"},
     {{al, r14, r0, r9}, false, al, "al r14 r0 r9", "al_r14_r0_r9"},
     {{al, r4, r6, r6}, false, al, "al r4 r6 r6", "al_r4_r6_r6"},
     {{al, r3, r7, r11}, false, al, "al r3 r7 r11", "al_r3_r7_r11"},
     {{al, r12, r9, r2}, false, al, "al r12 r9 r2", "al_r12_r9_r2"},
     {{al, r1, r1, r1}, false, al, "al r1 r1 r1", "al_r1_r1_r1"},
     {{al, r11, r5, r14}, false, al, "al r11 r5 r14", "al_r11_r5_r14"},
     {{al, r9, r4, r6}, false, al, "al r9 r4 r6", "al_r9_r4_r6"},
     {{al, r10, r11, r2}, false, al, "al r10 r11 r2", "al_r10_r11_r2"},
     {{al, r14, r6, r2}, false, al, "al r14 r6 r2", "al_r14_r6_r2"},
     {{al, r9, r4, r3}, false, al, "al r9 r4 r3", "al_r9_r4_r3"},
     {{al, r3, r3, r8}, false, al, "al r3 r3 r8", "al_r3_r3_r8"},
     {{al, r14, r10, r10}, false, al, "al r14 r10 r10", "al_r14_r10_r10"},
     {{al, r2, r11, r6}, false, al, "al r2 r11 r6", "al_r2_r11_r6"},
     {{al, r8, r12, r0}, false, al, "al r8 r12 r0", "al_r8_r12_r0"},
     {{al, r8, r1, r13}, false, al, "al r8 r1 r13", "al_r8_r1_r13"},
     {{al, r10, r8, r3}, false, al, "al r10 r8 r3", "al_r10_r8_r3"},
     {{al, r12, r12, r8}, false, al, "al r12 r12 r8", "al_r12_r12_r8"},
     {{al, r2, r2, r11}, false, al, "al r2 r2 r11", "al_r2_r2_r11"},
     {{al, r8, r5, r5}, false, al, "al r8 r5 r5", "al_r8_r5_r5"},
     {{al, r3, r14, r8}, false, al, "al r3 r14 r8", "al_r3_r14_r8"},
     {{al, r13, r10, r14}, false, al, "al r13 r10 r14", "al_r13_r10_r14"},
     {{al, r12, r6, r8}, false, al, "al r12 r6 r8", "al_r12_r6_r8"},
     {{al, r6, r2, r5}, false, al, "al r6 r2 r5", "al_r6_r2_r5"},
     {{al, r12, r8, r14}, false, al, "al r12 r8 r14", "al_r12_r8_r14"},
     {{al, r10, r6, r2}, false, al, "al r10 r6 r2", "al_r10_r6_r2"},
     {{al, r2, r4, r1}, false, al, "al r2 r4 r1", "al_r2_r4_r1"},
     {{al, r4, r0, r12}, false, al, "al r4 r0 r12", "al_r4_r0_r12"},
     {{al, r13, r7, r4}, false, al, "al r13 r7 r4", "al_r13_r7_r4"},
     {{al, r14, r11, r7}, false, al, "al r14 r11 r7", "al_r14_r11_r7"},
     {{al, r4, r4, r0}, false, al, "al r4 r4 r0", "al_r4_r4_r0"},
     {{al, r1, r10, r2}, false, al, "al r1 r10 r2", "al_r1_r10_r2"},
     {{al, r2, r4, r8}, false, al, "al r2 r4 r8", "al_r2_r4_r8"},
     {{al, r2, r2, r12}, false, al, "al r2 r2 r12", "al_r2_r2_r12"},
     {{al, r2, r4, r5}, false, al, "al r2 r4 r5", "al_r2_r4_r5"},
     {{al, r9, r3, r12}, false, al, "al r9 r3 r12", "al_r9_r3_r12"},
     {{al, r1, r7, r4}, false, al, "al r1 r7 r4", "al_r1_r7_r4"},
     {{al, r13, r7, r12}, false, al, "al r13 r7 r12", "al_r13_r7_r12"},
     {{al, r12, r14, r0}, false, al, "al r12 r14 r0", "al_r12_r14_r0"},
     {{al, r13, r12, r14}, false, al, "al r13 r12 r14", "al_r13_r12_r14"},
     {{al, r9, r6, r0}, false, al, "al r9 r6 r0", "al_r9_r6_r0"},
     {{al, r1, r12, r4}, false, al, "al r1 r12 r4", "al_r1_r12_r4"},
     {{al, r5, r8, r12}, false, al, "al r5 r8 r12", "al_r5_r8_r12"},
     {{al, r13, r11, r9}, false, al, "al r13 r11 r9", "al_r13_r11_r9"},
     {{al, r0, r2, r7}, false, al, "al r0 r2 r7", "al_r0_r2_r7"},
     {{al, r5, r3, r7}, false, al, "al r5 r3 r7", "al_r5_r3_r7"},
     {{al, r0, r3, r12}, false, al, "al r0 r3 r12", "al_r0_r3_r12"},
     {{al, r14, r9, r4}, false, al, "al r14 r9 r4", "al_r14_r9_r4"},
     {{al, r14, r9, r0}, false, al, "al r14 r9 r0", "al_r14_r9_r0"},
     {{al, r3, r8, r0}, false, al, "al r3 r8 r0", "al_r3_r8_r0"},
     {{al, r3, r5, r8}, false, al, "al r3 r5 r8", "al_r3_r5_r8"},
     {{al, r3, r1, r8}, false, al, "al r3 r1 r8", "al_r3_r1_r8"},
     {{al, r9, r2, r8}, false, al, "al r9 r2 r8", "al_r9_r2_r8"},
     {{al, r3, r13, r8}, false, al, "al r3 r13 r8", "al_r3_r13_r8"},
     {{al, r10, r2, r4}, false, al, "al r10 r2 r4", "al_r10_r2_r4"},
     {{al, r1, r5, r9}, false, al, "al r1 r5 r9", "al_r1_r5_r9"},
     {{al, r8, r12, r3}, false, al, "al r8 r12 r3", "al_r8_r12_r3"},
     {{al, r7, r14, r2}, false, al, "al r7 r14 r2", "al_r7_r14_r2"},
     {{al, r14, r7, r4}, false, al, "al r14 r7 r4", "al_r14_r7_r4"},
     {{al, r6, r0, r6}, false, al, "al r6 r0 r6", "al_r6_r0_r6"},
     {{al, r10, r3, r9}, false, al, "al r10 r3 r9", "al_r10_r3_r9"},
     {{al, r7, r9, r12}, false, al, "al r7 r9 r12", "al_r7_r9_r12"},
     {{al, r2, r3, r4}, false, al, "al r2 r3 r4", "al_r2_r3_r4"},
     {{al, r12, r4, r3}, false, al, "al r12 r4 r3", "al_r12_r4_r3"},
     {{al, r13, r11, r2}, false, al, "al r13 r11 r2", "al_r13_r11_r2"},
     {{al, r12, r7, r5}, false, al, "al r12 r7 r5", "al_r12_r7_r5"},
     {{al, r12, r1, r1}, false, al, "al r12 r1 r1", "al_r12_r1_r1"},
     {{al, r9, r5, r13}, false, al, "al r9 r5 r13", "al_r9_r5_r13"},
     {{al, r6, r8, r3}, false, al, "al r6 r8 r3", "al_r6_r8_r3"},
     {{al, r10, r0, r10}, false, al, "al r10 r0 r10", "al_r10_r0_r10"},
     {{al, r4, r3, r5}, false, al, "al r4 r3 r5", "al_r4_r3_r5"},
     {{al, r10, r2, r1}, false, al, "al r10 r2 r1", "al_r10_r2_r1"},
     {{al, r0, r11, r13}, false, al, "al r0 r11 r13", "al_r0_r11_r13"},
     {{al, r1, r0, r5}, false, al, "al r1 r0 r5", "al_r1_r0_r5"},
     {{al, r10, r10, r0}, false, al, "al r10 r10 r0", "al_r10_r10_r0"},
     {{al, r8, r9, r8}, false, al, "al r8 r9 r8", "al_r8_r9_r8"},
     {{al, r4, r9, r3}, false, al, "al r4 r9 r3", "al_r4_r9_r3"},
     {{al, r9, r4, r14}, false, al, "al r9 r4 r14", "al_r9_r4_r14"},
     {{al, r4, r14, r3}, false, al, "al r4 r14 r3", "al_r4_r14_r3"},
     {{al, r5, r8, r2}, false, al, "al r5 r8 r2", "al_r5_r8_r2"},
     {{al, r10, r11, r3}, false, al, "al r10 r11 r3", "al_r10_r11_r3"},
     {{al, r6, r8, r1}, false, al, "al r6 r8 r1", "al_r6_r8_r1"},
     {{al, r8, r9, r3}, false, al, "al r8 r9 r3", "al_r8_r9_r3"},
     {{al, r6, r6, r13}, false, al, "al r6 r6 r13", "al_r6_r6_r13"},
     {{al, r7, r10, r0}, false, al, "al r7 r10 r0", "al_r7_r10_r0"},
     {{al, r6, r14, r14}, false, al, "al r6 r14 r14", "al_r6_r14_r14"},
     {{al, r7, r4, r2}, false, al, "al r7 r4 r2", "al_r7_r4_r2"},
     {{al, r0, r7, r0}, false, al, "al r0 r7 r0", "al_r0_r7_r0"},
     {{al, r10, r7, r11}, false, al, "al r10 r7 r11", "al_r10_r7_r11"},
     {{al, r1, r8, r8}, false, al, "al r1 r8 r8", "al_r1_r8_r8"},
     {{al, r9, r4, r8}, false, al, "al r9 r4 r8", "al_r9_r4_r8"},
     {{al, r14, r5, r2}, false, al, "al r14 r5 r2", "al_r14_r5_r2"},
     {{al, r6, r12, r2}, false, al, "al r6 r12 r2", "al_r6_r12_r2"},
     {{al, r1, r11, r8}, false, al, "al r1 r11 r8", "al_r1_r11_r8"},
     {{al, r6, r5, r14}, false, al, "al r6 r5 r14", "al_r6_r5_r14"},
     {{al, r12, r1, r2}, false, al, "al r12 r1 r2", "al_r12_r1_r2"},
     {{al, r8, r3, r3}, false, al, "al r8 r3 r3", "al_r8_r3_r3"},
     {{al, r13, r8, r7}, false, al, "al r13 r8 r7", "al_r13_r8_r7"},
     {{al, r14, r11, r13}, false, al, "al r14 r11 r13", "al_r14_r11_r13"},
     {{al, r1, r14, r14}, false, al, "al r1 r14 r14", "al_r1_r14_r14"},
     {{al, r12, r4, r0}, false, al, "al r12 r4 r0", "al_r12_r4_r0"},
     {{al, r0, r2, r3}, false, al, "al r0 r2 r3", "al_r0_r2_r3"},
     {{al, r1, r5, r6}, false, al, "al r1 r5 r6", "al_r1_r5_r6"},
     {{al, r7, r6, r4}, false, al, "al r7 r6 r4", "al_r7_r6_r4"},
     {{al, r0, r9, r2}, false, al, "al r0 r9 r2", "al_r0_r9_r2"},
     {{al, r7, r3, r14}, false, al, "al r7 r3 r14", "al_r7_r3_r14"},
     {{al, r0, r5, r11}, false, al, "al r0 r5 r11", "al_r0_r5_r11"},
     {{al, r12, r12, r5}, false, al, "al r12 r12 r5", "al_r12_r12_r5"},
     {{al, r12, r11, r6}, false, al, "al r12 r11 r6", "al_r12_r11_r6"},
     {{al, r2, r6, r8}, false, al, "al r2 r6 r8", "al_r2_r6_r8"},
     {{al, r6, r10, r9}, false, al, "al r6 r10 r9", "al_r6_r10_r9"},
     {{al, r2, r11, r1}, false, al, "al r2 r11 r1", "al_r2_r11_r1"},
     {{al, r11, r2, r7}, false, al, "al r11 r2 r7", "al_r11_r2_r7"},
     {{al, r7, r14, r13}, false, al, "al r7 r14 r13", "al_r7_r14_r13"},
     {{al, r10, r5, r10}, false, al, "al r10 r5 r10", "al_r10_r5_r10"},
     {{al, r5, r6, r1}, false, al, "al r5 r6 r1", "al_r5_r6_r1"},
     {{al, r7, r4, r1}, false, al, "al r7 r4 r1", "al_r7_r4_r1"},
     {{al, r7, r12, r0}, false, al, "al r7 r12 r0", "al_r7_r12_r0"},
     {{al, r3, r6, r8}, false, al, "al r3 r6 r8", "al_r3_r6_r8"},
     {{al, r0, r0, r8}, false, al, "al r0 r0 r8", "al_r0_r0_r8"},
     {{al, r12, r1, r11}, false, al, "al r12 r1 r11", "al_r12_r1_r11"},
     {{al, r14, r3, r14}, false, al, "al r14 r3 r14", "al_r14_r3_r14"},
     {{al, r12, r0, r14}, false, al, "al r12 r0 r14", "al_r12_r0_r14"},
     {{al, r5, r10, r9}, false, al, "al r5 r10 r9", "al_r5_r10_r9"},
     {{al, r3, r7, r12}, false, al, "al r3 r7 r12", "al_r3_r7_r12"},
     {{al, r10, r8, r7}, false, al, "al r10 r8 r7", "al_r10_r8_r7"},
     {{al, r8, r14, r4}, false, al, "al r8 r14 r4", "al_r8_r14_r4"},
     {{al, r6, r7, r7}, false, al, "al r6 r7 r7", "al_r6_r7_r7"},
     {{al, r13, r2, r14}, false, al, "al r13 r2 r14", "al_r13_r2_r14"},
     {{al, r1, r11, r11}, false, al, "al r1 r11 r11", "al_r1_r11_r11"},
     {{al, r5, r0, r13}, false, al, "al r5 r0 r13", "al_r5_r0_r13"},
     {{al, r7, r6, r11}, false, al, "al r7 r6 r11", "al_r7_r6_r11"},
     {{al, r4, r1, r14}, false, al, "al r4 r1 r14", "al_r4_r1_r14"},
     {{al, r10, r4, r9}, false, al, "al r10 r4 r9", "al_r10_r4_r9"},
     {{al, r5, r6, r6}, false, al, "al r5 r6 r6", "al_r5_r6_r6"},
     {{al, r14, r8, r13}, false, al, "al r14 r8 r13", "al_r14_r8_r13"},
     {{al, r13, r1, r12}, false, al, "al r13 r1 r12", "al_r13_r1_r12"},
     {{al, r2, r7, r11}, false, al, "al r2 r7 r11", "al_r2_r7_r11"},
     {{al, r10, r4, r12}, false, al, "al r10 r4 r12", "al_r10_r4_r12"},
     {{al, r3, r10, r12}, false, al, "al r3 r10 r12", "al_r3_r10_r12"},
     {{al, r0, r9, r5}, false, al, "al r0 r9 r5", "al_r0_r9_r5"},
     {{al, r8, r9, r4}, false, al, "al r8 r9 r4", "al_r8_r9_r4"},
     {{al, r11, r0, r7}, false, al, "al r11 r0 r7", "al_r11_r0_r7"},
     {{al, r11, r5, r7}, false, al, "al r11 r5 r7", "al_r11_r5_r7"},
     {{al, r7, r4, r14}, false, al, "al r7 r4 r14", "al_r7_r4_r14"},
     {{al, r14, r5, r10}, false, al, "al r14 r5 r10", "al_r14_r5_r10"},
     {{al, r11, r9, r0}, false, al, "al r11 r9 r0", "al_r11_r9_r0"},
     {{al, r9, r8, r4}, false, al, "al r9 r8 r4", "al_r9_r8_r4"},
     {{al, r9, r0, r3}, false, al, "al r9 r0 r3", "al_r9_r0_r3"},
     {{al, r11, r4, r4}, false, al, "al r11 r4 r4", "al_r11_r4_r4"},
     {{al, r2, r5, r7}, false, al, "al r2 r5 r7", "al_r2_r5_r7"},
     {{al, r14, r1, r8}, false, al, "al r14 r1 r8", "al_r14_r1_r8"},
     {{al, r12, r11, r10}, false, al, "al r12 r11 r10", "al_r12_r11_r10"},
     {{al, r6, r7, r14}, false, al, "al r6 r7 r14", "al_r6_r7_r14"},
     {{al, r6, r13, r12}, false, al, "al r6 r13 r12", "al_r6_r13_r12"},
     {{al, r11, r11, r13}, false, al, "al r11 r11 r13", "al_r11_r11_r13"}};

// These headers each contain an array of `TestResult` with the reference output
// values. The reference arrays are names `kReference{mnemonic}`.
#include "aarch32/traces/assembler-cond-rd-rn-operand-rm-t32-adc.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-rm-t32-adcs.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-rm-t32-add.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-rm-t32-adds.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-rm-t32-and.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-rm-t32-ands.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-rm-t32-bic.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-rm-t32-bics.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-rm-t32-eor.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-rm-t32-eors.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-rm-t32-orn.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-rm-t32-orns.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-rm-t32-orr.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-rm-t32-orrs.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-rm-t32-rsb.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-rm-t32-rsbs.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-rm-t32-sbc.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-rm-t32-sbcs.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-rm-t32-sub.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-rm-t32-subs.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-rm-t32-sxtab.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-rm-t32-sxtab16.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-rm-t32-sxtah.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-rm-t32-uxtab.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-rm-t32-uxtab16.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-rm-t32-uxtah.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-rm-t32-asr.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-rm-t32-asrs.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-rm-t32-lsl.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-rm-t32-lsls.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-rm-t32-lsr.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-rm-t32-lsrs.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-rm-t32-ror.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-rm-t32-rors.h"


// The maximum number of errors to report in detail for each test.
static const unsigned kErrorReportLimit = 8;

typedef void (MacroAssembler::*Fn)(Condition cond,
                                   Register rd,
                                   Register rn,
                                   const Operand& op);

static void TestHelper(Fn instruction,
                       const char* mnemonic,
                       const TestResult reference[]) {
  unsigned total_error_count = 0;
  MacroAssembler masm(BUF_SIZE);

  masm.UseT32();

  for (unsigned i = 0; i < ARRAY_SIZE(kTests); i++) {
    // Values to pass to the macro-assembler.
    Condition cond = kTests[i].operands.cond;
    Register rd = kTests[i].operands.rd;
    Register rn = kTests[i].operands.rn;
    Register rm = kTests[i].operands.rm;
    Operand op(rm);

    int32_t start = masm.GetCursorOffset();
    {
      // We never generate more that 4 bytes, as IT instructions are only
      // allowed for narrow encodings.
      AssemblerAccurateScope scope(&masm,
                                   4,
                                   AssemblerAccurateScope::kMaximumSize);
      if (kTests[i].in_it_block) {
        masm.it(kTests[i].it_condition);
      }
      (masm.*instruction)(cond, rd, rn, op);
    }
    int32_t end = masm.GetCursorOffset();

    const byte* result_ptr =
        masm.GetBuffer().GetOffsetAddress<const byte*>(start);
    VIXL_ASSERT(start < end);
    uint32_t result_size = end - start;

    if (Test::generate_test_trace()) {
      // Print the result bytes.
      printf("static const byte kInstruction_%s_%s[] = {\n",
             mnemonic,
             kTests[i].identifier);
      for (uint32_t j = 0; j < result_size; j++) {
        if (j == 0) {
          printf("  0x%02" PRIx8, result_ptr[j]);
        } else {
          printf(", 0x%02" PRIx8, result_ptr[j]);
        }
      }
      // This comment is meant to be used by external tools to validate
      // the encoding. We can parse the comment to figure out what
      // instruction this corresponds to.
      if (kTests[i].in_it_block) {
        printf(" // It %s; %s %s\n};\n",
               kTests[i].it_condition.GetName(),
               mnemonic,
               kTests[i].operands_description);
      } else {
        printf(" // %s %s\n};\n", mnemonic, kTests[i].operands_description);
      }
    } else {
      // Check we've emitted the exact same encoding as present in the
      // trace file. Only print up to `kErrorReportLimit` errors.
      if (((result_size != reference[i].size) ||
           (memcmp(result_ptr, reference[i].encoding, reference[i].size) !=
            0)) &&
          (++total_error_count <= kErrorReportLimit)) {
        printf("Error when testing \"%s\" with operands \"%s\":\n",
               mnemonic,
               kTests[i].operands_description);
        printf("  Expected: ");
        for (uint32_t j = 0; j < reference[i].size; j++) {
          if (j == 0) {
            printf("0x%02" PRIx8, reference[i].encoding[j]);
          } else {
            printf(", 0x%02" PRIx8, reference[i].encoding[j]);
          }
        }
        printf("\n");
        printf("  Found:    ");
        for (uint32_t j = 0; j < result_size; j++) {
          if (j == 0) {
            printf("0x%02" PRIx8, result_ptr[j]);
          } else {
            printf(", 0x%02" PRIx8, result_ptr[j]);
          }
        }
        printf("\n");
      }
    }
  }

  masm.FinalizeCode();

  if (Test::generate_test_trace()) {
    // Finalize the trace file by writing the final `TestResult` array
    // which links all generated instruction encodings.
    printf("static const TestResult kReference%s[] = {\n", mnemonic);
    for (unsigned i = 0; i < ARRAY_SIZE(kTests); i++) {
      printf("  {\n");
      printf("    ARRAY_SIZE(kInstruction_%s_%s),\n",
             mnemonic,
             kTests[i].identifier);
      printf("    kInstruction_%s_%s,\n", mnemonic, kTests[i].identifier);
      printf("  },\n");
    }
    printf("};\n");
  } else {
    if (total_error_count > kErrorReportLimit) {
      printf("%u other errors follow.\n",
             total_error_count - kErrorReportLimit);
    }
    // Crash if the test failed.
    VIXL_CHECK(total_error_count == 0);
  }
}

// Instantiate tests for each instruction in the list.
#define TEST(mnemonic)                                                      \
  static void Test_##mnemonic() {                                           \
    TestHelper(&MacroAssembler::mnemonic, #mnemonic, kReference##mnemonic); \
  }                                                                         \
  static Test test_##mnemonic(                                              \
      "AARCH32_ASSEMBLER_COND_RD_RN_OPERAND_RM_T32_" #mnemonic,             \
      &Test_##mnemonic);
FOREACH_INSTRUCTION(TEST)
#undef TEST

}  // aarch32
}  // vixl
