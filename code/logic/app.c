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
 * @brief Execute a .crabql file.
 * 
 * @param db Pointer to the fossil_crabdb_t database.
 * @param filepath Path to the .crabql file.
 * @return Error code indicating the result of the operation.
 */
fossil_crabdb_error_t execute_crabql_file(fossil_crabdb_t *db, const char *filepath) {
    if (!db || !filepath) return CRABDB_ERR_INVALID_QUERY;

    FILE *file = fopen(filepath, "r");
    if (!file) return CRABDB_ERR_INVALID_QUERY;

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        // Remove newline character
        line[strcspn(line, "\n")] = '\0';

        // Find the command and arguments
        char *command = strtok(line, "(");
        if (!command) continue;

        char *args = strtok(NULL, ")");
        if (!args) continue;

        // Trim spaces from the command
        while (isspace((unsigned char)*command)) command++;
        char *end = command + strlen(command) - 1;
        while (end > command && isspace((unsigned char)*end)) end--;
        end[1] = '\0';

        // Tokenize the arguments
        char *token;
        char *tokens[10]; // Assuming a max of 10 arguments
        int token_count = 0;
        token = strtok(args, ",");
        while (token) {
            while (isspace((unsigned char)*token)) token++;
            char *end = token + strlen(token) - 1;
            while (end > token && isspace((unsigned char)*end)) end--;
            end[1] = '\0';
            tokens[token_count++] = token;
            token = strtok(NULL, ",");
        }

        fossil_crabdb_error_t result = parse_and_execute(db, command, tokens, token_count);
        if (result != CRABDB_OK) {
            printf("Error executing command '%s': %d\n", command, result);
        }
    }

    fclose(file);
    return CRABDB_OK;
}

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
    fossil_crabdb_t db = {0}; // Initialize the database

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <crabql-file>\n", argv[0]);
        return 1;
    }

    if (execute_crabql_file(&db, argv[1]) != CRABDB_OK) {
        fprintf(stderr, "Failed to execute .crabql file\n");
        return 1;
    }

    // Clean up
    fossil_crabdb_erase(&db);

    return 0;
} // end of func
