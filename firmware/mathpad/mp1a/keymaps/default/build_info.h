/* Copyright 2025 Summacogni OU
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef BUILD_INFO_H
#define BUILD_INFO_H

// Include generated build info if it exists
#ifdef __has_include
    #if __has_include("build_info_generated.h")
        #include "build_info_generated.h"
    #endif
#else
    // Fallback for older compilers - just try to include it
    #include "build_info_generated.h"
#endif

// Build information macros with fallback defaults
// These are used if build_info_generated.h doesn't exist or doesn't define them

#ifndef BUILD_DATE
#define BUILD_DATE "unknown"
#endif

#ifndef BUILD_TIME
#define BUILD_TIME "unknown"
#endif

#ifndef GIT_COMMIT_HASH
#define GIT_COMMIT_HASH "unknown"
#endif

#ifndef COMPILER_VERSION
#define COMPILER_VERSION "unknown"
#endif

#ifndef BUILD_FLAGS
#define BUILD_FLAGS "unknown"
#endif

#endif // BUILD_INFO_H
