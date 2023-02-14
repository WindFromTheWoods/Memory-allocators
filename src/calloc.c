#include "calloc.h"
#include "malloc.h"

void* calloc(size_t num, size_t nsize)
{
    if (num == 0 || nsize == 0)
    {
        return NULL;
    }

    size_t size = num * nsize;
    if (nsize != size / num)
    {
        return NULL;
    }

    void* block = malloc(size);
    if (block == NULL)
    {
        return NULL;
    }

    memset(block, 0, size);
    return block;
}
