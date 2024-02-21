#include "../lib/tree.c"
#include <stdio.h>
#include <stdlib.h>

int main() {
    chunk_holder_t *ch = new_chunk_holder(NULL, 100);
    printf("%d\n", ch->chunk);

    return 0;
}