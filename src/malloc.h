#ifndef MEMORY_ALLOCATORS_MALLOC_H
#define MEMORY_ALLOCATORS_MALLOC_H

#include "general.h"

// Обьявляем malloc
void *malloc(size_t size);

// Обьявляем get_free_block
header_t *get_free_block(size_t size);

#endif //MEMORY_ALLOCATORS_MALLOC_H
