#ifndef _CHUNK_
#define _CHUNK_ "0.1"

#include "spec.h"
#include "tree/tree.h"
#ifdef _SPEC_
#ifdef _TREE_H_

chunk_num_t chunk_holder_arr_len(chunk_holder_t** arr, chunk_num_t child_addr_size) {
    chunk_num_t n = 0;
    while (*arr != _spec_NULL) {
        n++;
        arr += child_addr_size;
    }
    return n;
}

#endif // _TREE_H_
#endif // _SPEC_
#endif // _CHUNK_