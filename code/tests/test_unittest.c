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

FOSSIL_FIXTURE(project_fixture);
fossil_crabdb_t *db;

FOSSIL_SETUP(project_fixture) {
    db = fossil_crabdb_create(); // Initialize your database
}

FOSSIL_TEARDOWN(project_fixture) {
    fossil_crabdb_erase(db); // Clean up database after each test
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(test_create_and_insert_crabql) {
    // Load and execute the .crabql file
    ASSUME_ITS_EQUAL_I32(CRABDB_OK, execute_crabql_file("create_and_insert.crabql", db));

    // Verify inserted data
    char *value = NULL;
    ASSUME_ITS_EQUAL_I32(CRABDB_OK, fossil_crabdb_get(db, "dinos", "T-Rex", &value));
    ASSUME_NOT_CNULL(value);
    ASSUME_ITS_EQUAL_CSTR("A large carnivorous dinosaur", value);
    fossil_crabdb_free(value);

    ASSUME_ITS_EQUAL_I32(CRABDB_OK, fossil_crabdb_get(db, "dinos", "Triceratops", &value));
    ASSUME_NOT_CNULL(value);
    ASSUME_ITS_EQUAL_CSTR("A herbivorous dinosaur with three horns", value);
    fossil_crabdb_free(value);

    ASSUME_ITS_EQUAL_I32(CRABDB_OK, fossil_crabdb_get(db, "dinos", "Velociraptor", &value));
    ASSUME_NOT_CNULL(value);
    ASSUME_ITS_EQUAL_CSTR("A small, fast, and agile dinosaur", value);
    fossil_crabdb_free(value);
}

FOSSIL_TEST(test_update_and_get_crabql) {
    // Set up initial state
    fossil_crabdb_insert(db, "dinos", "T-Rex", "A large carnivorous dinosaur");

    // Load and execute the .crabql file
    ASSUME_ITS_EQUAL_I32(CRABDB_OK, execute_crabql_file("update_and_get.crabql", db));

    // Verify updates
    char *value = NULL;
    ASSUME_ITS_EQUAL_I32(CRABDB_OK, fossil_crabdb_get(db, "dinos", "T-Rex", &value));
    ASSUME_NOT_CNULL(value);
    ASSUME_ITS_EQUAL_CSTR("The largest known carnivorous dinosaur", value);
    fossil_crabdb_free(value);

    ASSUME_ITS_EQUAL_I32(CRABDB_OK, fossil_crabdb_get(db, "dinos", "Triceratops", &value));
    ASSUME_NOT_CNULL(value);
    ASSUME_ITS_EQUAL_CSTR("A herbivorous dinosaur with three horns", value);
    fossil_crabdb_free(value);
}

FOSSIL_TEST(test_delete_and_query_crabql) {
    // Set up initial state
    fossil_crabdb_insert(db, "dinos", "Velociraptor", "A small, fast, and agile dinosaur");

    // Load and execute the .crabql file
    ASSUME_ITS_EQUAL_I32(CRABDB_OK, execute_crabql_file("delete_and_query.crabql", db));

    // Verify deletions and queries
    char *value = NULL;
    ASSUME_ITS_EQUAL_I32(CRABDB_ERR_KEY_NOT_FOUND, fossil_crabdb_get(db, "dinos", "Velociraptor", &value));
    ASSUME_ITS_CNULL(value);

    ASSUME_ITS_EQUAL_I32(CRABDB_OK, fossil_crabdb_get(db, "dinos", "T-Rex", &value));
    ASSUME_NOT_CNULL(value);
    ASSUME_ITS_EQUAL_CSTR("A large carnivorous dinosaur", value);
    fossil_crabdb_free(value);
}

FOSSIL_TEST(test_namespace_operations_crabql) {
    // Load and execute the .crabql file
    ASSUME_ITS_EQUAL_I32(CRABDB_OK, execute_crabql_file("namespace_operations.crabql", db));

    // Verify namespace creation and deletion
    char *value = NULL;
    ASSUME_ITS_EQUAL_I32(CRABDB_ERR_NS_NOT_FOUND, fossil_crabdb_get(db, "prehistoric", "dinosaurs", &value));
    ASSUME_ITS_CNULL(value);
}

FOSSIL_TEST(test_complex_operations_crabql) {
    // Load and execute the .crabql file
    ASSUME_ITS_EQUAL_I32(CRABDB_OK, execute_crabql_file("complex_operations.crabql", db));

    // Verify operations in the mesozoic namespace
    char *value = NULL;
    ASSUME_ITS_EQUAL_I32(CRABDB_OK, fossil_crabdb_get(db, "mesozoic", "Jurassic", &value));
    ASSUME_NOT_CNULL(value);
    ASSUME_ITS_EQUAL_CSTR("A dinosaur known for its distinctive plates along its back", value);
    fossil_crabdb_free(value);

    ASSUME_ITS_EQUAL_I32(CRABDB_ERR_KEY_NOT_FOUND, fossil_crabdb_get(db, "mesozoic", "Cretaceous", &value));
    ASSUME_ITS_CNULL(value);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_some_tests) {    
    ADD_TESTF(test_create_and_insert_crabql, project_fixture);
    ADD_TESTF(test_update_and_get_crabql, project_fixture);
    ADD_TESTF(test_delete_and_query_crabql, project_fixture);
    ADD_TESTF(test_namespace_operations_crabql, project_fixture);
    ADD_TESTF(test_complex_operations_crabql, project_fixture);
} // end of tests
