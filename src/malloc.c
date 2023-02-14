#include "malloc.h"

header_t* get_free_block(size_t size)
{
    header_t* curr = head;

    while (curr != NULL)
    {
        if (curr->s.is_free && curr->s.size >= size)
        {
            return curr;
        }

        curr = curr->s.next;
    }

    return NULL;
}

void* malloc(size_t size)
{
    if (size == 0)
    {
        return NULL;
    }

    pthread_mutex_lock(&global_malloc_lock);
    header_t* header = get_free_block(size);

    if (header != NULL)
    {
        header->s.is_free = 0;
        pthread_mutex_unlock(&global_malloc_lock);
        return (void*)(header + 1);
    }

    size_t total_size = sizeof(header_t) + size;
    void* block = sbrk(total_size);

    if (block == (void*)-1)
    {
        pthread_mutex_unlock(&global_malloc_lock);
        return NULL;
    }

    header = block;
    header->s.size = size;
    header->s.is_free = 0;
    header->s.next = NULL;

    if (tail != NULL)
    {
        tail->s.next = header;
    }
    else
    {
        head = header;
    }

    tail = header;
    pthread_mutex_unlock(&global_malloc_lock);
    return (void*)(header + 1);
}
