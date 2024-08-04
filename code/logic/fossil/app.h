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

#include "common.h"

#include "fossil/crabdb/framework.h"

fossil_crabdb_error_t execute_crabql_file(fossil_crabdb_t *db, const char *filepath);

#endif // FOSSIL_APP_H
