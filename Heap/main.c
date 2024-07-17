#include "heap.h"

int main (void) {
    heap* H = create_heap(15);
    insertion_heap(H, 10);
    insertion_heap(H, 432);
    insertion_heap(H, 123);
    insertion_heap(H, 142);
    insertion_heap(H, 543);
    insertion_heap(H, 53342);
    insertion_heap(H, 42);
    insertion_heap(H, 675);
    insertion_heap(H, 678);
    insertion_heap(H, 654);
    insertion_heap(H, 5463);
    insertion_heap(H, 423);

    print_heap(H);
    remotion_heap(H, 2);
    remotion_heap(H, 1);
    remotion_heap(H, 4);
    remotion_heap(H, 0);
    print_heap(H);
}