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

#ifndef POTTERY_SHELL_SORT_IMPL
#error "This is an internal header. Do not include it."
#endif

#include "pottery/pottery_dependencies.h"
#include "pottery/platform/pottery_platform_pragma_push.t.h"



/*
 * Configuration
 */

#ifndef POTTERY_SHELL_SORT_EXTERN
    #define POTTERY_SHELL_SORT_EXTERN /*nothing*/
#endif

// Context forwarding
#ifdef POTTERY_SHELL_SORT_CONTEXT_TYPE
    #define POTTERY_SHELL_SORT_CONTEXT_VAL(state) state.context,
#else
    #define POTTERY_SHELL_SORT_CONTEXT_VAL(state) /*nothing*/
#endif



/*
 * Renaming
 */

#define POTTERY_SHELL_SORT_NAME(name) \
    POTTERY_CONCAT(POTTERY_SHELL_SORT_PREFIX, name)

#define pottery_shell_sort_ref_t POTTERY_SHELL_SORT_NAME(_ref_t)
#define pottery_shell_sort_value_t POTTERY_SHELL_SORT_NAME(_value_t)
#define pottery_shell_sort_context_t POTTERY_SHELL_SORT_NAME(_context_t)
#define pottery_shell_sort POTTERY_SHELL_SORT_PREFIX
#define pottery_shell_sort_insertion_sort POTTERY_SHELL_SORT_NAME(_insertion_sort)
#define pottery_shell_sort_access POTTERY_SHELL_SORT_NAME(_access)
#define pottery_shell_sort_state_t POTTERY_SHELL_SORT_NAME(_state_t)



// lifecycle functions
#ifdef POTTERY_SHELL_SORT_EXTERNAL_LIFECYCLE
    #define POTTERY_SHELL_SORT_LIFECYCLE_PREFIX POTTERY_SHELL_SORT_EXTERNAL_LIFECYCLE
#else
    #define POTTERY_SHELL_SORT_LIFECYCLE_PREFIX POTTERY_SHELL_SORT_NAME(_lifecycle)
#endif
//!!! AUTOGENERATED:lifecycle/rename.m.h SRC:pottery_shell_sort_lifecycle DEST:POTTERY_SHELL_SORT_LIFECYCLE_PREFIX
    // This block is auto-generated. Do not modify until END_AUTOGENERATED.
    // Renames lifecycle identifiers from pottery_shell_sort_lifecycle to POTTERY_SHELL_SORT_LIFECYCLE_PREFIX

    // types
    #define pottery_shell_sort_lifecycle_value_t POTTERY_CONCAT(POTTERY_SHELL_SORT_LIFECYCLE_PREFIX, _value_t)
    #define pottery_shell_sort_lifecycle_ref_t POTTERY_CONCAT(POTTERY_SHELL_SORT_LIFECYCLE_PREFIX, _ref_t)
    #define pottery_shell_sort_lifecycle_const_ref_t POTTERY_CONCAT(POTTERY_SHELL_SORT_LIFECYCLE_PREFIX, _const_ref_t)
    #define pottery_shell_sort_lifecycle_context_t POTTERY_CONCAT(POTTERY_SHELL_SORT_LIFECYCLE_PREFIX, _context_t)

    // fundamental operations
    #define pottery_shell_sort_lifecycle_init_steal POTTERY_CONCAT(POTTERY_SHELL_SORT_LIFECYCLE_PREFIX, _init_steal)
    #define pottery_shell_sort_lifecycle_init_copy POTTERY_CONCAT(POTTERY_SHELL_SORT_LIFECYCLE_PREFIX, _init_copy)
    #define pottery_shell_sort_lifecycle_init POTTERY_CONCAT(POTTERY_SHELL_SORT_LIFECYCLE_PREFIX, _init)
    #define pottery_shell_sort_lifecycle_destroy POTTERY_CONCAT(POTTERY_SHELL_SORT_LIFECYCLE_PREFIX, _destroy)
    #define pottery_shell_sort_lifecycle_swap POTTERY_CONCAT(POTTERY_SHELL_SORT_LIFECYCLE_PREFIX, _swap)
    #define pottery_shell_sort_lifecycle_move POTTERY_CONCAT(POTTERY_SHELL_SORT_LIFECYCLE_PREFIX, _move)
    #define pottery_shell_sort_lifecycle_steal POTTERY_CONCAT(POTTERY_SHELL_SORT_LIFECYCLE_PREFIX, _steal)
    #define pottery_shell_sort_lifecycle_copy POTTERY_CONCAT(POTTERY_SHELL_SORT_LIFECYCLE_PREFIX, _copy)

    // bulk operations
    #define pottery_shell_sort_lifecycle_destroy_bulk POTTERY_CONCAT(POTTERY_SHELL_SORT_LIFECYCLE_PREFIX, _destroy_bulk)
    #define pottery_shell_sort_lifecycle_move_bulk POTTERY_CONCAT(POTTERY_SHELL_SORT_LIFECYCLE_PREFIX, _move_bulk)
    #define pottery_shell_sort_lifecycle_move_bulk_restrict POTTERY_CONCAT(POTTERY_SHELL_SORT_LIFECYCLE_PREFIX, _move_bulk_restrict)
    #define pottery_shell_sort_lifecycle_move_bulk_restrict_impl POTTERY_CONCAT(POTTERY_SHELL_SORT_LIFECYCLE_PREFIX, _move_bulk_restrict_impl)
    #define pottery_shell_sort_lifecycle_move_bulk_up POTTERY_CONCAT(POTTERY_SHELL_SORT_LIFECYCLE_PREFIX, _move_bulk_up)
    #define pottery_shell_sort_lifecycle_move_bulk_up_impl POTTERY_CONCAT(POTTERY_SHELL_SORT_LIFECYCLE_PREFIX, _move_bulk_up_impl)
    #define pottery_shell_sort_lifecycle_move_bulk_down POTTERY_CONCAT(POTTERY_SHELL_SORT_LIFECYCLE_PREFIX, _move_bulk_down)
    #define pottery_shell_sort_lifecycle_move_bulk_down_impl POTTERY_CONCAT(POTTERY_SHELL_SORT_LIFECYCLE_PREFIX, _move_bulk_down_impl)
//!!! END_AUTOGENERATED



// compare functions
#ifdef POTTERY_SHELL_SORT_EXTERNAL_COMPARE
    #define POTTERY_SHELL_SORT_COMPARE_PREFIX POTTERY_SHELL_SORT_EXTERNAL_COMPARE
#else
    #define POTTERY_SHELL_SORT_COMPARE_PREFIX POTTERY_SHELL_SORT_NAME(_compare)
#endif
//!!! AUTOGENERATED:compare/rename.m.h SRC:pottery_shell_sort_compare DEST:POTTERY_SHELL_SORT_COMPARE_PREFIX
    // This block is auto-generated. Do not modify until END_AUTOGENERATED.
    // Renames compare identifiers from pottery_shell_sort_compare to POTTERY_SHELL_SORT_COMPARE_PREFIX

    #define pottery_shell_sort_compare_ref_t POTTERY_CONCAT(POTTERY_SHELL_SORT_COMPARE_PREFIX, _ref_t)
    #define pottery_shell_sort_compare_value_t POTTERY_CONCAT(POTTERY_SHELL_SORT_COMPARE_PREFIX, _value_t)
    #define pottery_shell_sort_compare_context_t POTTERY_CONCAT(POTTERY_SHELL_SORT_COMPARE_PREFIX, _context_t)

    #define pottery_shell_sort_compare_three_way POTTERY_CONCAT(POTTERY_SHELL_SORT_COMPARE_PREFIX, _three_way)
    #define pottery_shell_sort_compare_equal POTTERY_CONCAT(POTTERY_SHELL_SORT_COMPARE_PREFIX, _equal)
    #define pottery_shell_sort_compare_not_equal POTTERY_CONCAT(POTTERY_SHELL_SORT_COMPARE_PREFIX, _not_equal)
    #define pottery_shell_sort_compare_less POTTERY_CONCAT(POTTERY_SHELL_SORT_COMPARE_PREFIX, _less)
    #define pottery_shell_sort_compare_less_or_equal POTTERY_CONCAT(POTTERY_SHELL_SORT_COMPARE_PREFIX, _less_or_equal)
    #define pottery_shell_sort_compare_greater POTTERY_CONCAT(POTTERY_SHELL_SORT_COMPARE_PREFIX, _greater)
    #define pottery_shell_sort_compare_greater_or_equal POTTERY_CONCAT(POTTERY_SHELL_SORT_COMPARE_PREFIX, _greater_or_equal)

    #define pottery_shell_sort_compare_min POTTERY_CONCAT(POTTERY_SHELL_SORT_COMPARE_PREFIX, _min)
    #define pottery_shell_sort_compare_max POTTERY_CONCAT(POTTERY_SHELL_SORT_COMPARE_PREFIX, _max)
    #define pottery_shell_sort_compare_clamp POTTERY_CONCAT(POTTERY_SHELL_SORT_COMPARE_PREFIX, _clamp)
    #define pottery_shell_sort_compare_median POTTERY_CONCAT(POTTERY_SHELL_SORT_COMPARE_PREFIX, _median)
//!!! END_AUTOGENERATED
