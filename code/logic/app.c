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
#include "fossil/app.h"

/**
 * Generate a FizzBuzz output for a given integer.
 *
 * @param n      The integer to process.
 * @param output The output buffer to write the result to.
 */
void fizzbuzz(int n, char *output) {
    if (n % 3 == 0 && n % 5 == 0) {
        sprintf(output, "FizzBuzz");
    } else if (n % 3 == 0) {
        sprintf(output, "Fizz");
    } else if (n % 5 == 0) {
        sprintf(output, "Buzz");
    } else {
        sprintf(output, "%d", n);
    }
} // end of fun

/**
 * Process a file containing integers and print the FizzBuzz output for each one.
 *
 * @param filename The name of the file to process.
 */
void process_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    int n;
    while (fscanf(file, "%d", &n) != EOF) {
        char output[10];
        fizzbuzz(n, output);
        printf("%s\n", output);
    }

    fclose(file);
} // end of fun

/**
 * Entry point for the FossilApp.
 * Initializes the FossilApp structure with the provided name, argc, and argv,
 * then calls the main app code function to start the app.
 *
 * @param name The name of the application.
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line arguments.
 * @return     The result of the app code execution.
 */
int fossil_app_main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    process_file(argv[1]);

    return EXIT_SUCCESS;
} // end of fun
