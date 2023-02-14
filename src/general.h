#ifndef MEMORY_ALLOCATORS_GENERAL_H
#define MEMORY_ALLOCATORS_GENERAL_H

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

// Создаем заглушку
typedef char ALIGN[16];

// Сделал Union - чтобы имитировать выравнивание памяти до 16 байт
union header {
    struct {
        size_t size;
        unsigned is_free;
        union header *next;
    } s;
    ALIGN stub; // Заглушка что бы забить остаток памяти до 16 байт
};
typedef union header header_t;

header_t *head, *tail;

// Обьявляем маллок для синхронизации процессов
pthread_mutex_t global_malloc_lock;

#endif //MEMORY_ALLOCATORS_GENERAL_H
