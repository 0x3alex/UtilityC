#ifndef SAFE_ALLOCATE
#define SAFE_ALLOCATE
#include <stdlib.h>

void *safe_alloc(int amount, size_t size);

void *safe_realloc(void *p, int new_size);

#endif