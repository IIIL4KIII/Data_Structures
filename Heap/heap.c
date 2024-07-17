#include "heap.h"

heap* create_heap(int capacity) {
    heap* H = (heap*) malloc(sizeof(heap));
    H->cap = capacity;
    H->size = 0;
    H->V = (int*) malloc(capacity * sizeof(int));

    return H;
}


void swap (int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}


void insertion_heap(heap* H, int key) {
    if (H->size >= H->cap)
        return;

    H->V[H->size] = key;
    heap_up(H, H->size);
    H->size++;
}


void heap_up(heap* H, int index) {
    if (index && H->V[(index - 1)/2] < H->V[index]) {
        swap(&H->V[(index - 1) / 2], &H->V[index]);
        heap_up(H, (index - 1) / 2);
    }
}

void heap_down(heap* H, int index) {
    int largest = index;
    int left_child = 2 * index + 1;
    int right_child = 2 * index + 2;

    if (left_child < H->size && H->V[left_child] > H->V[largest])
        largest = left_child;
    
    if (right_child < H->size && H->V[right_child] > H->V[largest])
        largest = right_child;

    if (largest != index) {
        swap(&H->V[index], &H->V[largest]);
        heap_down(H, largest);
    }
}


void remotion_heap(heap* H, int index) {
    if (H->size == 0)
        return;
    
    int root = H->V[0];
    H->V[0] = H->V[H->size - 1];
    H->size--;
    heap_down(H, 0);
}


void print_heap(heap* H) {
    printf("[ ");
    for (int i = 0; i < H->size; i++)
        printf("%d, ", H->V[i]);
    printf("]\n");
}


