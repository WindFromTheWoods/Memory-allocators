#include "realloc.h"
#include "free.h"
#include "malloc.h"

void* realloc(void* block, size_t size)
{
    if (block == NULL || size == 0)
    {
        return malloc(size);
    }

    header_t* header = (header_t*)block - 1;
    if (header->s.size >= size)
    {
        return block;
    }

    void* ret = malloc(size);
    if (ret != NULL)
    {
        memcpy(ret, block, header->s.size);
        free(block);
    }

    return ret;
}
