cmake_minimum_required(VERSION 3.24)
project(untitled1 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled1 main.c src/malloc.c src/malloc.h src/free.c src/free.h src/calloc.c src/calloc.h src/realloc.c src/realloc.h src/general.h)
