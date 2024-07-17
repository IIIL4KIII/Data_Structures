#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct heap {
    int * V;
    unsigned cap;
    unsigned size;
} heap;


heap* create_heap(int capacity);

void swap(int* x, int* y);
void insertion_heap(heap* H, int key);
void heap_up(heap* H, int index);
void remotion_heap(heap* H, int index);
void heap_down(heap* H, int index);
void print_heap(heap* H);


#endif

