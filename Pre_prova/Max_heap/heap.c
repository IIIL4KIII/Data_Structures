#include "heap.h"


heap* create_heap(int capacity) {
    heap* H = (heap*) malloc(sizeof(heap));
    H->V = (int*) malloc(capacity * sizeof(int));
    H->cap = capacity;
    H->size = 0;

    return H;
}


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void insert_heap(heap* H, int key) {
    if (H->cap == H->size)
        return;
    
    H->V[H->size] = key;
    heap_up(H, H->size);
    H->size++;
}


void heap_up (heap* H, int index) {
    if (index && H->V[(index - 1) /2 ] < H->V[index]) {
        swap(&H->V[(index - 1) / 2], &H->V[index]);
        heap_up(H, (index - 1) / 2);
    }
}


void remove_heap(heap* H, int index) {
    if (H->size == 0)
        return;
    
    H->V[0] = H->V[H->size - 1];
    H->size--;
    heap_down(H, 0);
}


void heap_down(heap* H, int index) {
    int largest = index;
    int l_child = 2 * index + 1;
    int r_child = 2 * index + 2;

    if (l_child < H->size && H->V[l_child] > H->V[largest])
        largest = l_child;

    if (r_child < H->size && H->V[r_child] > H->V[largest])
        largest = r_child;

    if (largest != index) {
        swap(&H->V[index], &H->V[largest]);
        heap_down(H, largest);
    }
}


