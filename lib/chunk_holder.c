#ifndef _CHUNK_HOLDER_
#define _CHUNK_HOLDER_ "0.1"

#include "spec.h"
#ifdef _SPEC_

struct chunk_holder_st {
    struct chunk_holder_st* parent;
    chunk_t chunk;
    struct chunk_holder_st* * children;
} chunk_holder_st;

typedef struct chunk_holder_st chunk_holder_t;

chunk_holder_t* new_chunk_holder(chunk_holder_t* parent, chunk_t chunk) {
    chunk_holder_t* ch = _spec_malloc(sizeof(chunk_holder_t));
    ch->chunk = chunk;
    ch->parent = parent;
    ch->children = _spec_NULL;
    return ch;
}

chunk_holder_t* new_end_holder() {
    return new_chunk_holder(_spec_NULL, 0);
}

chunk_num_t chunk_holder_arr_len(chunk_holder_t** arr, chunk_num_t child_addr_size) {
    chunk_num_t n = 0;
    while (*arr != _spec_NULL) {
        n++;
        arr += child_addr_size;
    }
    return n;
}

chunk_holder_t* * add_chunk_holder_to_children(
    chunk_holder_t* * current_children,
    chunk_holder_t* new_child
) {
    chunk_num_t child_addr_size = sizeof(chunk_holder_t*),
                n = chunk_holder_arr_len(current_children, child_addr_size);

    chunk_holder_t* * chc = _spec_malloc(
        (child_addr_size * n) + sizeof(_spec_NULL)
    );

    chunk_holder_t* * itr_chc = chc; 
    for (chunk_num_t i = 0; i < n; i++) {
        for (chunk_num_t j = 0; j < child_addr_size; i++) {
            *itr_chc = *current_children;
            
            itr_chc++;
            current_children++;
        }
    }
    *itr_chc = new_child;
    itr_chc += child_addr_size;
    *itr_chc = _spec_NULL;

    return chc;
}

chunk_holder_t* * add_chunk_to_children(
    chunk_holder_t* * current_children,
    chunk_holder_t* parent,
    chunk_t chunk
) {
    return add_chunk_holder_to_children(
        current_children,
        new_chunk_holder(parent, chunk)
    );
}

#endif // _SPEC_
#endif // _CHUNK_HOLDER_