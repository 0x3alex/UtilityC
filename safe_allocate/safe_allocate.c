#include "include/safe_allocate.h"
#include <stdlib.h>

void *safe_alloc(int amount, size_t size) {
    void *p = calloc(amount,size);
    if(p == NULL) {
        exit(-1);
    }
    return p;
}

void *safe_realloc(void *p, int new_size);