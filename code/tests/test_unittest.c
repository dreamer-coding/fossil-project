/*
 * -----------------------------------------------------------------------------
 * Project: Fossil Logic
 *
 * This file is part of the Fossil Logic project, which aims to develop high-
 * performance, cross-platform applications and libraries. The code contained
 * herein is subject to the terms and conditions defined in the project license.
 *
 * Author: Michael Gene Brockus (Dreamer)
 *
 * Copyright (C) 2024 Fossil Logic. All rights reserved.
 * -----------------------------------------------------------------------------
 */
#include <fossil/unittest/framework.h>
#include <fossil/xassume.h>

#include "fossil/app.h"

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilities
// * * * * * * * * * * * * * * * * * * * * * * * *
// Setup steps for things like test fixtures and
// mock objects are set here.
// * * * * * * * * * * * * * * * * * * * * * * * *

// Placeholder for test setup

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(test_fizzbuzz_1) {
    char output[10];
    fizzbuzz(1, output);
    ASSUME_ITS_EQUAL_CSTR("1", output);
}

FOSSIL_TEST(test_fizzbuzz_3) {
    char output[10];
    fizzbuzz(3, output);
    ASSUME_ITS_EQUAL_CSTR("Fizz", output);
}

FOSSIL_TEST(test_fizzbuzz_5) {
    char output[10];
    fizzbuzz(5, output);
    ASSUME_ITS_EQUAL_CSTR("Buzz", output);
}

FOSSIL_TEST(test_fizzbuzz_15) {
    char output[10];
    fizzbuzz(15, output);
    ASSUME_ITS_EQUAL_CSTR("FizzBuzz", output);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_some_tests) {    
    ADD_TEST(test_fizzbuzz_1);
    ADD_TEST(test_fizzbuzz_3);
    ADD_TEST(test_fizzbuzz_5);
    ADD_TEST(test_fizzbuzz_15);
} // end of tests
