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
#ifndef FOSSIL_APP_H
#define FOSSIL_APP_H

#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"

/**
 * Generate a FizzBuzz output for a given integer.
 *
 * @param n      The integer to process.
 * @param output The output buffer to write the result to.
 */
void fizzbuzz(int n, char *output);

/**
 * Process a file containing integers and print the FizzBuzz output for each one.
 *
 * @param filename The name of the file to process.
 */
void process_file(const char *filename);

#ifdef __cplusplus
}
#endif

#endif // FOSSIL_APP_H
