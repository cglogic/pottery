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

#ifndef POTTERY_OPEN_HASH_MAP_IMPL
#error "This is an internal header. Do not include it."
#endif

// The value is the user type stored in each bucket.
#ifdef POTTERY_OPEN_HASH_MAP_VALUE_TYPE
typedef POTTERY_OPEN_HASH_MAP_VALUE_TYPE pottery_ohm_value_t;
#endif

// The ref is an abstract handle to an element and bucket in the hash table.
#ifdef POTTERY_OPEN_HASH_MAP_REF_TYPE
#error "TODO it doesn't make sense to have a custom ref type"
typedef POTTERY_OPEN_HASH_MAP_REF_TYPE pottery_ohm_ref_t;
#else
typedef pottery_ohm_value_t* pottery_ohm_ref_t;
#endif

// The key type is an abstract handle to a key used for lookups in the hash
// table. Each element in the hash table has a unique key.
#ifdef POTTERY_OPEN_HASH_MAP_KEY_TYPE
typedef POTTERY_OPEN_HASH_MAP_KEY_TYPE pottery_ohm_key_t;
#else
typedef pottery_ohm_ref_t pottery_ohm_key_t;
#endif

#ifdef POTTERY_OPEN_HASH_MAP_CONTEXT_TYPE
typedef POTTERY_OPEN_HASH_MAP_CONTEXT_TYPE pottery_ohm_context_t;
#endif

#if POTTERY_OPEN_HASH_MAP_HAS_METADATA
typedef enum pottery_ohm_bucket_state_t {

    // We use zero as the empty state so we can zero-allocate our metadata and
    // not have to clear it.
    #if POTTERY_OPEN_HASH_MAP_INTERNAL_EMPTY
    pottery_ohm_bucket_state_empty = 0,
    #endif

    // This is not necessarily a value since the user might have declared only
    // in-band tombstones and not in-band empty or vice versa.
    pottery_ohm_bucket_state_other = 1,

    #if POTTERY_OPEN_HASH_MAP_INTERNAL_TOMBSTONE
    pottery_ohm_bucket_state_tombstone = 2,
    #endif
} pottery_ohm_bucket_state_t;
#endif

typedef struct pottery_ohm_t pottery_ohm_t;

static inline
void pottery_ohm_ref_move(POTTERY_OPEN_HASH_MAP_TABLE_CONTEXT_ARG
        pottery_ohm_ref_t to, pottery_ohm_ref_t from);

static inline
void pottery_ohm_ref_destroy(POTTERY_OPEN_HASH_MAP_TABLE_CONTEXT_ARG
        pottery_ohm_ref_t ref);

static inline
pottery_ohm_key_t pottery_ohm_ref_key(POTTERY_OPEN_HASH_MAP_TABLE_CONTEXT_ARG
        pottery_ohm_ref_t ref);

static inline
bool pottery_ohm_ref_key_equal(POTTERY_OPEN_HASH_MAP_TABLE_CONTEXT_ARG
        pottery_ohm_key_t left, pottery_ohm_key_t right);

static inline
size_t pottery_ohm_ref_key_hash(POTTERY_OPEN_HASH_MAP_TABLE_CONTEXT_ARG
        pottery_ohm_key_t key);

static inline
bool pottery_ohm_ref_is_empty(POTTERY_OPEN_HASH_MAP_TABLE_CONTEXT_ARG
        pottery_ohm_ref_t ref);

static inline
void pottery_ohm_ref_set_empty(POTTERY_OPEN_HASH_MAP_TABLE_CONTEXT_ARG
        pottery_ohm_ref_t ref);

#if POTTERY_OPEN_HASH_MAP_TOMBSTONES
static inline
bool pottery_ohm_ref_is_tombstone(POTTERY_OPEN_HASH_MAP_TABLE_CONTEXT_ARG
        pottery_ohm_ref_t ref);

static inline
void pottery_ohm_ref_set_tombstone(POTTERY_OPEN_HASH_MAP_TABLE_CONTEXT_ARG
        pottery_ohm_ref_t ref);
#endif

static inline
bool pottery_ohm_ref_is_value(POTTERY_OPEN_HASH_MAP_TABLE_CONTEXT_ARG
        pottery_ohm_ref_t ref);
