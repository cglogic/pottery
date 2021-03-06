/*
 * MIT License
 *
 * Copyright (c) 2020 Nicholas Fraser
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef POTTERY_ARRAY_ACCESS_INTERNAL
#error "This is an internal header. Do not include it."
#endif

#include "pottery/pottery_dependencies.h"
#include "pottery/platform/pottery_platform_pragma_push.t.h"

#ifdef POTTERY_ARRAY_ACCESS_INHERENT_COUNT
#error "A previous instantiation of the array access template was not cleaned up."
#endif



/*
 * Configuration
 */

// must have one of value, ref or entry type
#if !defined(POTTERY_ARRAY_ACCESS_VALUE_TYPE) && \
    !defined(POTTERY_ARRAY_ACCESS_REF_TYPE) && \
    !defined(POTTERY_ARRAY_ACCESS_ENTRY_TYPE)
#error "At least one of VALUE_TYPE, REF_TYPE and ENTRY_TYPE must be defined."
#endif

// inherent base is enabled by defining BEGIN
#if defined(POTTERY_ARRAY_ACCESS_BEGIN)
    #define POTTERY_ARRAY_ACCESS_INHERENT_BASE 1
#else
    #define POTTERY_ARRAY_ACCESS_INHERENT_BASE 0
#endif

// inherent count is enabled by defining END or COUNT
#if defined(POTTERY_ARRAY_ACCESS_END) || defined(POTTERY_ARRAY_ACCESS_COUNT)
    #define POTTERY_ARRAY_ACCESS_INHERENT_COUNT 1
#else
    #define POTTERY_ARRAY_ACCESS_INHERENT_COUNT 0
#endif

// required configs in case standard C array fallback is not possible
#if !defined(POTTERY_ARRAY_ACCESS_VALUE_TYPE)
    #if !defined(POTTERY_ARRAY_ACCESS_SELECT)
        #error "ARRAY_ACCESS_SELECT is required without a VALUE_TYPE."
    #endif
    #if !defined(POTTERY_ARRAY_ACCESS_INDEX)
        #error "ARRAY_ACCESS_INDEX is required without a VALUE_TYPE."
    #endif
#endif



/*
 * Common Function Arguments
 */

//!!! AUTOGENERATED:array_access/args.m.h CONFIG:POTTERY_ARRAY_ACCESS NAME:pottery_array_access
    // This block is auto-generated. Do not modify until END_AUTOGENERATED.
    // Defines wrappers for common function arguments for functions that access
    // arrays via the array_access template.

    // ARGS are function arguments
    // VALS are the matching values
    // SOLE means they are the only arguments to the function (so no trailing comma)
    // UNUSED casts them to void to silence unused parameter warnings

    #ifdef POTTERY_ARRAY_ACCESS_CONTEXT_TYPE
        #if !POTTERY_ARRAY_ACCESS_INHERENT_BASE
            #define POTTERY_ARRAY_ACCESS_SOLE_ARGS pottery_array_access_context_t context, pottery_array_access_entry_t base
            #define POTTERY_ARRAY_ACCESS_SOLE_VALS context, base
            #define POTTERY_ARRAY_ACCESS_ARGS_UNUSED (void)context, (void)base
        #else
            #define POTTERY_ARRAY_ACCESS_SOLE_ARGS pottery_array_access_context_t context
            #define POTTERY_ARRAY_ACCESS_SOLE_VALS context
            #define POTTERY_ARRAY_ACCESS_ARGS_UNUSED (void)context
        #endif
    #else
        #if !POTTERY_ARRAY_ACCESS_INHERENT_BASE
            #define POTTERY_ARRAY_ACCESS_SOLE_ARGS pottery_array_access_entry_t base
            #define POTTERY_ARRAY_ACCESS_SOLE_VALS base
            #define POTTERY_ARRAY_ACCESS_ARGS_UNUSED (void)base
        #else
            #define POTTERY_ARRAY_ACCESS_SOLE_ARGS void
            #define POTTERY_ARRAY_ACCESS_SOLE_VALS /*nothing*/
            #define POTTERY_ARRAY_ACCESS_ARGS_UNUSED /*nothing*/
        #endif
    #endif
    #if defined(POTTERY_ARRAY_ACCESS_CONTEXT_TYPE) || !POTTERY_ARRAY_ACCESS_INHERENT_BASE
        #define POTTERY_ARRAY_ACCESS_ARGS POTTERY_ARRAY_ACCESS_SOLE_ARGS ,
        #define POTTERY_ARRAY_ACCESS_VALS POTTERY_ARRAY_ACCESS_SOLE_VALS ,
    #else
        #define POTTERY_ARRAY_ACCESS_ARGS /*nothing*/
        #define POTTERY_ARRAY_ACCESS_VALS /*nothing*/
    #endif
//!!! END_AUTOGENERATED



/*
 * Renaming
 */

//!!! AUTOGENERATED:array_access/rename.m.h SRC:pottery_array_access DEST:POTTERY_ARRAY_ACCESS_PREFIX
    // This block is auto-generated. Do not modify until END_AUTOGENERATED.
    // Renames array_access identifiers from pottery_array_access to POTTERY_ARRAY_ACCESS_PREFIX

    #define pottery_array_access_value_t POTTERY_CONCAT(POTTERY_ARRAY_ACCESS_PREFIX, _value_t)
    #define pottery_array_access_ref_t POTTERY_CONCAT(POTTERY_ARRAY_ACCESS_PREFIX, _ref_t)
    #define pottery_array_access_entry_t POTTERY_CONCAT(POTTERY_ARRAY_ACCESS_PREFIX, _entry_t)
    #define pottery_array_access_context_t POTTERY_CONCAT(POTTERY_ARRAY_ACCESS_PREFIX, _context_t)

    #define pottery_array_access_begin POTTERY_CONCAT(POTTERY_ARRAY_ACCESS_PREFIX, _begin)
    #define pottery_array_access_end POTTERY_CONCAT(POTTERY_ARRAY_ACCESS_PREFIX, _end)
    #define pottery_array_access_count POTTERY_CONCAT(POTTERY_ARRAY_ACCESS_PREFIX, _count)

    #define pottery_array_access_select POTTERY_CONCAT(POTTERY_ARRAY_ACCESS_PREFIX, _select)
    #define pottery_array_access_index POTTERY_CONCAT(POTTERY_ARRAY_ACCESS_PREFIX, _index)

    #define pottery_array_access_shift POTTERY_CONCAT(POTTERY_ARRAY_ACCESS_PREFIX, _shift)
    #define pottery_array_access_offset POTTERY_CONCAT(POTTERY_ARRAY_ACCESS_PREFIX, _offset)
    #define pottery_array_access_next POTTERY_CONCAT(POTTERY_ARRAY_ACCESS_PREFIX, _next)
    #define pottery_array_access_previous POTTERY_CONCAT(POTTERY_ARRAY_ACCESS_PREFIX, _previous)

    #define pottery_array_access_ref POTTERY_CONCAT(POTTERY_ARRAY_ACCESS_PREFIX, _ref)
    #define pottery_array_access_equal POTTERY_CONCAT(POTTERY_ARRAY_ACCESS_PREFIX, _equal)
    #define pottery_array_access_exists POTTERY_CONCAT(POTTERY_ARRAY_ACCESS_PREFIX, _exists)
//!!! END_AUTOGENERATED
