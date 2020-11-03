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

// helper to allocate an array of values
static inline
pottery_ohm_value_t* pottery_ohm_impl_alloc(pottery_ohm_t* ohm, size_t size) {
    (void)ohm;
    void* ptr = pottery_ohm_alloc_malloc_array(
            POTTERY_OPEN_HASH_MAP_CONTEXT_VAL(ohm)
            pottery_alignof(pottery_ohm_value_t),
            size,
            sizeof(pottery_ohm_value_t));
    return pottery_cast(pottery_ohm_value_t*, ptr);
}

// helper to free an array of values
static inline
void pottery_ohm_impl_free(pottery_ohm_t* ohm, pottery_ohm_value_t* values) {
    (void)ohm;
    pottery_ohm_alloc_free(
            POTTERY_OPEN_HASH_MAP_CONTEXT_VAL(ohm)
            pottery_alignof(pottery_ohm_value_t),
            values);
}

// TODO take context argument
POTTERY_OPEN_HASH_MAP_EXTERN
pottery_error_t pottery_ohm_init(pottery_ohm_t* ohm) {
    // default to 16 buckets
    size_t log_2_size = 4;
    size_t size = pottery_cast(size_t, 1 << log_2_size);
    pottery_ohm_value_t* values = pottery_ohm_impl_alloc(ohm, size);
    if (values == pottery_null)
        return POTTERY_ERROR_ALLOC;
    pottery_ohm_table_configure(&ohm->table, ohm, values, log_2_size, 0
            #if POTTERY_OPEN_HASH_MAP_TOMBSTONES
            , 0
            #endif
            );
    for (size_t i = 0; i < size; ++i)
        pottery_ohm_table_ref_set_empty(&ohm->table, ohm->table.first + i);
    return POTTERY_OK;
}

POTTERY_OPEN_HASH_MAP_EXTERN
void pottery_ohm_destroy(pottery_ohm_t* ohm) {

    #if POTTERY_LIFECYCLE_CAN_DESTROY
    pottery_ohm_ref_t ref = pottery_ohm_table_begin(&ohm->table);
    for (; pottery_ohm_table_ref_exists(&ohm->table, ref); pottery_ohm_table_next(&ohm->table, &ref))
        pottery_ohm_lifecycle_destroy(/*TODO:context*/ ref);

    #else
    // If we don't have a destroy expression, you must manually empty the hash
    // map before destroying it.
    pottery_assert(pottery_ohm_count(ohm) == 0);
    #endif

    pottery_ohm_impl_free(ohm, ohm->table.first);
}

static
pottery_error_t pottery_ohm_grow_if_needed(pottery_ohm_t* ohm) {
    size_t count = pottery_ohm_table_count(&ohm->table);
    size_t old_size = pottery_cast(size_t, 1 << ohm->table.log_2_size);

    // We grow at a load factor of 2/3. Figure out a good load factor later.
    if (count < old_size - old_size / 3) {
        // no need to grow
        return POTTERY_OK;
    }

    // allocate a new table with double the size
    size_t new_log_2_size = ohm->table.log_2_size + 1;
    size_t new_size = pottery_cast(size_t, 1 << new_log_2_size);
    pottery_ohm_value_t* new_values = pottery_ohm_impl_alloc(ohm, new_size);
    if (new_values == pottery_null)
        return POTTERY_ERROR_ALLOC;

    // replace our table
    pottery_ohm_value_t* old_values = ohm->table.first;
    pottery_ohm_table_t old_table = ohm->table;
    pottery_ohm_table_configure(&ohm->table, ohm, new_values, new_log_2_size, 0
            #if POTTERY_OPEN_HASH_MAP_TOMBSTONES
            , 0
            #endif
            );

    // clear the new values
    for (size_t i = 0; i < new_size; ++i)
        pottery_ohm_table_ref_set_empty(&ohm->table, new_values + i);

    // re-insert all values from old table into new one
    pottery_ohm_ref_t ref = pottery_ohm_table_begin(&ohm->table);
    for (; pottery_ohm_table_ref_exists(&old_table, ref); pottery_ohm_table_next(&old_table, &ref)) {
        pottery_ohm_ref_t target = pottery_ohm_table_emplace(&ohm->table, pottery_ohm_table_key(&old_table, ref), pottery_null);
        pottery_ohm_lifecycle_move(/*TODO:context*/ target, ref);
    }

    pottery_ohm_impl_free(ohm, old_values);
    return POTTERY_OK;
}

static
void pottery_ohm_shrink_if_needed(pottery_ohm_t* ohm) {
    // TODO
}

POTTERY_OPEN_HASH_MAP_EXTERN
pottery_ohm_ref_t pottery_ohm_emplace(pottery_ohm_t* ohm,
        pottery_ohm_key_t key, bool* /*nullable*/ created)
{
    // If we're full we grow regardless of whether the element already exists
    // in order to make sure there's enough room for it.
    if (POTTERY_OK != pottery_ohm_grow_if_needed(ohm))
        return pottery_ohm_table_end(&ohm->table);
    return pottery_ohm_table_emplace(&ohm->table, key, created);
}

POTTERY_OPEN_HASH_MAP_EXTERN
void pottery_ohm_displace(pottery_ohm_t* ohm, pottery_ohm_ref_t ref) {
    pottery_ohm_table_displace(&ohm->table, ref);
    pottery_ohm_shrink_if_needed(ohm);
}

POTTERY_OPEN_HASH_MAP_EXTERN
void pottery_ohm_remove(pottery_ohm_t* ohm, pottery_ohm_ref_t ref) {
    pottery_ohm_table_remove(&ohm->table, ref);
    pottery_ohm_shrink_if_needed(ohm);
}

POTTERY_OPEN_HASH_MAP_EXTERN
bool pottery_ohm_remove_key(pottery_ohm_t* ohm, pottery_ohm_key_t key) {
    bool removed = pottery_ohm_table_remove_key(&ohm->table, key);
    if (removed)
        pottery_ohm_shrink_if_needed(ohm);
    return removed;
}