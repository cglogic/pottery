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

#ifndef POTTERY_COMPARE_INTERNAL
#error "This is an internal header. Do not include it."
#endif

#include "pottery/pottery_dependencies.h"
#include "pottery/platform/pottery_platform_pragma_push.t.h"



/*
 * Configuration
 */

// context
#if POTTERY_CONTAINER_TYPES_HAS_CONTEXT
#define POTTERY_COMPARE_CONTEXT_ARG pottery_compare_context_t context,
#define POTTERY_COMPARE_CONTEXT_VAL context,
#define POTTERY_COMPARE_CONTEXT_MAYBE_UNUSED (void)context
#else
#define POTTERY_COMPARE_CONTEXT_ARG    /* nothing */
#define POTTERY_COMPARE_CONTEXT_VAL    /* nothing */
#define POTTERY_COMPARE_CONTEXT_MAYBE_UNUSED /* nothing */
#endif

// by value comparisons
#ifndef POTTERY_COMPARE_BY_VALUE
    #define POTTERY_COMPARE_BY_VALUE 0
#endif
#if POTTERY_COMPARE_BY_VALUE && !POTTERY_CONTAINER_TYPES_HAS_VALUE
    #error "BY_VALUE comparisons require a VALUE_TYPE."
#endif

// order
#if POTTERY_COMPARE_BY_VALUE || \
        defined(POTTERY_COMPARE_LESS) || \
        defined(POTTERY_COMPARE_LESS_OR_EQUAL) || \
        defined(POTTERY_COMPARE_GREATER) || \
        defined(POTTERY_COMPARE_GREATER_OR_EQUAL) || \
        defined(POTTERY_COMPARE_THREE_WAY)
    #define POTTERY_COMPARE_CAN_ORDER 1
#else
    #define POTTERY_COMPARE_CAN_ORDER 0
#endif

// equal
#if POTTERY_COMPARE_CAN_ORDER || \
        defined(POTTERY_COMPARE_EQUAL) || \
        defined(POTTERY_COMPARE_NOT_EQUAL)
    #define POTTERY_COMPARE_CAN_EQUAL 1
#else
    #define POTTERY_COMPARE_CAN_EQUAL 0
#endif

// temporary renaming hack. compare won't deal with entries soon
#define pottery_compare_ref pottery_compare_entry_ref



/*
 * Renaming
 */

#ifdef POTTERY_COMPARE_EXTERNAL_CONTAINER_TYPES
    #define POTTERY_COMPARE_CONTAINER_TYPES_PREFIX POTTERY_COMPARE_EXTERNAL_CONTAINER_TYPES
#else
    #define POTTERY_COMPARE_CONTAINER_TYPES_PREFIX POTTERY_COMPARE_PREFIX
#endif
//!!! AUTOGENERATED:container_types/rename.m.h SRC:pottery_compare DEST:POTTERY_COMPARE_CONTAINER_TYPES_PREFIX
    // This block is auto-generated. Do not modify until END_AUTOGENERATED.
    // Renames container_types template identifiers from pottery_compare to POTTERY_COMPARE_CONTAINER_TYPES_PREFIX

    #define pottery_compare_value_t POTTERY_CONCAT(POTTERY_COMPARE_CONTAINER_TYPES_PREFIX, _value_t)
    #define pottery_compare_ref_t POTTERY_CONCAT(POTTERY_COMPARE_CONTAINER_TYPES_PREFIX, _ref_t)
    #define pottery_compare_const_ref_t POTTERY_CONCAT(POTTERY_COMPARE_CONTAINER_TYPES_PREFIX, _const_ref_t)
    #define pottery_compare_entry_t POTTERY_CONCAT(POTTERY_COMPARE_CONTAINER_TYPES_PREFIX, _entry_t)
    #define pottery_compare_key_t POTTERY_CONCAT(POTTERY_COMPARE_CONTAINER_TYPES_PREFIX, _key_t)
    #define pottery_compare_context_t POTTERY_CONCAT(POTTERY_COMPARE_CONTAINER_TYPES_PREFIX, _context_t)

    #define pottery_compare_entry_ref POTTERY_CONCAT(POTTERY_COMPARE_CONTAINER_TYPES_PREFIX, _entry_ref)
    #define pottery_compare_ref_key POTTERY_CONCAT(POTTERY_COMPARE_CONTAINER_TYPES_PREFIX, _ref_key)
    #define pottery_compare_ref_equal POTTERY_CONCAT(POTTERY_COMPARE_CONTAINER_TYPES_PREFIX, _ref_equal)
//!!! END_AUTOGENERATED

//!!! AUTOGENERATED:compare/rename.m.h SRC:pottery_compare DEST:POTTERY_COMPARE_PREFIX
    // This block is auto-generated. Do not modify until END_AUTOGENERATED.
    // Renames compare identifiers from pottery_compare to POTTERY_COMPARE_PREFIX

    #define pottery_compare_three_way POTTERY_CONCAT(POTTERY_COMPARE_PREFIX, _three_way)
    #define pottery_compare_equal POTTERY_CONCAT(POTTERY_COMPARE_PREFIX, _equal)
    #define pottery_compare_not_equal POTTERY_CONCAT(POTTERY_COMPARE_PREFIX, _not_equal)
    #define pottery_compare_less POTTERY_CONCAT(POTTERY_COMPARE_PREFIX, _less)
    #define pottery_compare_less_or_equal POTTERY_CONCAT(POTTERY_COMPARE_PREFIX, _less_or_equal)
    #define pottery_compare_greater POTTERY_CONCAT(POTTERY_COMPARE_PREFIX, _greater)
    #define pottery_compare_greater_or_equal POTTERY_CONCAT(POTTERY_COMPARE_PREFIX, _greater_or_equal)

    #define pottery_compare_min POTTERY_CONCAT(POTTERY_COMPARE_PREFIX, _min)
    #define pottery_compare_max POTTERY_CONCAT(POTTERY_COMPARE_PREFIX, _max)
    #define pottery_compare_clamp POTTERY_CONCAT(POTTERY_COMPARE_PREFIX, _clamp)
    #define pottery_compare_median POTTERY_CONCAT(POTTERY_COMPARE_PREFIX, _median)
//!!! END_AUTOGENERATED
