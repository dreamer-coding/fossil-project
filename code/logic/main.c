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

/*
 * This is the main entry point for the application. This file is responsible
 * for calling the main function of the application. This also allows the
 * flexability of testing application logic without getting an error for having
 * multiple main functions, at the end of the day Fossil Test runs the test cases
 * in its own main function.
 */
extern int fossil_app_main(int argc, char** argv);

/*
 * This is the main entry point for the application. This file is responsible
 * for calling the main function of the application. This also allows the
 * flexability of testing application logic without getting an error for having
 * multiple main functions, at the end of the day Fossil Test runs the test cases
 * in its own main function.
 */
int main(int argc, char** argv) {
    return fossil_app_main(argc, argv);
} // end of fun
