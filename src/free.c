//
// Created by EviiiiiL on 14.02.2023.
//

#include "free.h"

void free(void *block)
{
    header_t *header, *tmp;
    void *programbreak;

    if (!block)
        return;

    pthread_mutex_lock(&global_malloc_lock);
    header = (header_t*)block - 1;

    if (header->s.is_free) {
        pthread_mutex_unlock(&global_malloc_lock);
        return;
    }

    programbreak = sbrk(0);
    if ((char*)block + header->s.size == programbreak)
    {
        if (head == tail)
        {
            head = tail = NULL;
        }
        else
        {
            tmp = head;
            while (tmp)
            {
                if(tmp->s.next == tail)
                {
                    tmp->s.next = NULL;
                    tail = tmp;
                }
                tmp = tmp->s.next;
            }
        }

        sbrk(0 - sizeof(header_t) - header->s.size);
        pthread_mutex_unlock(&global_malloc_lock);
        return;
    }

    header->s.is_free = 1;
    pthread_mutex_unlock(&global_malloc_lock);
}
