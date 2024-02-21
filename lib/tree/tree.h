#ifndef _TREE_H_
#define _TREE_H_ "0.1"

#include "../spec.h"
#ifdef _SPEC_

struct chunk_holder_st {
    struct chunk_holder_st* parent;
    chunk_t chunk;
    struct chunk_holder_st* * children;
} chunk_holder_st;

typedef struct chunk_holder_st chunk_holder_t;

#endif // _SPEC_
#endif // _TREE_H_