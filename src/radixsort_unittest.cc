// Copyright 2018, Allan Knight.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Allan Knight nor the names of other
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// A unit tester for EX05-String in CS140 at Santa Barbara City College.
//
// Author: ahknight@pipeline.sbcc.edu (Allan Knight)


// Includes for google test and the unit under test.

#include <climits>

#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <functional>
#include <random>

#include "gtest/gtest.h"

#include "radixsort.h"
#include "GTestNoDeath.h"

namespace {

    using edu::vcccd::vc::csv15::radixsort;

// Tests edu::sbcc:cs140::String.

    using std::istringstream;
    using std::ostringstream;
    using std::string;

    typedef uint64_t uint;

    using namespace ::testing_internal;

    class RadixSortTest : public ::testing::Test {
    protected:
        static const uint MAX_TESTED_SCORE = 20;
        static const uint MAX_OVERALL_SCORE = 25;
        static uint _testScore;

    protected:
        static void TearDownTestCase() {
            if (_testScore == MAX_TESTED_SCORE) {
                std::cout << std::endl << "Your unit test score is "
                          << _testScore << " out of "
                          << MAX_TESTED_SCORE << std::endl;
            } else {
                std::cout << "Your unit test score is "
                          << _testScore << " out of "
                          << MAX_TESTED_SCORE << " ("<< (int)(_testScore - MAX_TESTED_SCORE)
                          << ")" << std::endl;
            }

            std::cout << "The assignment is worth a total of " << MAX_OVERALL_SCORE
                      << " where the remaining points" << std::endl;
            std::cout << "comes from grading related to documentation, algorithms, and other"
                      << std::endl;
            std::cout << "criteria." << std::endl << std::endl;
        }
    };

    uint RadixSortTest::_testScore = 0;

    constexpr static size_t BASECASE_SIZE = 20;

    TEST_F(RadixSortTest, BaseCase) {
        // This test is named "Identity", it checks that the basic identity
        // complex number, i, has the correct values for real and imaginary
        // parts.

        std::random_device rd;
        std::mt19937 g(rd());
        std::uniform_int_distribution<uint32_t> distribution(1, 100);
        uint32_t data[BASECASE_SIZE];
        for (uint32_t &datum: data) {
            datum = distribution(g);
        }
        radixsort(data, BASECASE_SIZE);
        for (size_t i = 0; i < BASECASE_SIZE-1; i++) {
            ASSERT_LE(data[i], data[i+1]);
        }

        _testScore += 5;
    }

    TEST_F(RadixSortTest, LargeNumbersCheckMSV) {
        // This test is named "Identity", it checks that the basic identity
        // complex number, i, has the correct values for real and imaginary
        // parts.

        std::random_device rd;
        std::mt19937 g(rd());
        std::uniform_int_distribution<uint32_t> distribution(1000000000, 2000000000);
        uint32_t data[BASECASE_SIZE];
        for (uint32_t &datum: data) {
            datum = distribution(g);
        }
        radixsort(data, BASECASE_SIZE);
        for (size_t i = 0; i < BASECASE_SIZE-1; i++) {
            ASSERT_LE(data[i], data[i+1]);
        }

        _testScore += 5;
    }

    TEST_F(RadixSortTest, LargeNumbersCheckLSV) {
        // This test is named "Identity", it checks that the basic identity
        // complex number, i, has the correct values for real and imaginary
        // parts.

        std::random_device rd;
        std::mt19937 g(rd());
        std::uniform_int_distribution<uint32_t> distribution(1000, 9999);
        uint32_t data[BASECASE_SIZE] {
            99990000,
            99990000,
            99990000,
            99990000,
            99990000,
            66660000,
            66660000,
            66660000,
            66660000,
            66660000,
            33330000,
            33330000,
            33330000,
            33330000,
            33330000,
            00000000,
            00000000,
            00000000,
            00000000,
            00000000
        };
        for (uint32_t &datum: data) {
            datum += distribution(g);
        }
        radixsort(data, BASECASE_SIZE);
        for (size_t i = 0; i < BASECASE_SIZE-1; i++) {
            ASSERT_LE(data[i], data[i+1]);
        }

        _testScore += 5;
    }

    TEST_F(RadixSortTest, NullPtrCheck) {
        ASSERT_NO_DEATH(radixsort<int>(nullptr, 100000), "");

        _testScore += 5;
    }

}