#include "deque.h"


deque* create_deque (int capacity) {
    deque* D = (deque*) malloc(sizeof(deque));
    D->V = (int*) malloc(capacity * sizeof(int));
    D->cap = capacity;
    D->size = D->first = 0;

    return D;
}


void push(deque* D, int key) {
    if (D->size < D->cap) {
        int last = (D->first + D->size ) % D->cap;
        D->V[last] = key;
        D->size++;
    } else {
        printf("O vetor está cheio.\n");
    }
}


void eject(deque* D) {
    if (D->size == 0)
        return;

    D->first = (D->first + 1) % D->cap;
    D->size--;
}


void pop(deque* D) {
    if (D->size == 0)
        return;
    
    D->size--;
}


void kill_deque(deque* D) {
    free(D->V);
    free(D);
}


void print_deque(deque* D) {
    printf("[ ");
    for (int i = 0; i < D->size; i++) 
        printf("%d, ", D->V[(D->first + i) % D->cap]);
    
    printf("]\n");
}


void last (deque* D) {
    if (D->size == 0)  
        return;
    int last = (D->first + D->size -1 ) % D->cap;
    printf("O último elemento do vetor é: %d.\n", D->V[last]);
}


void first(deque* D) {
    if (D->size == 0)
        return;
    printf("O primeiro elemento do vetor é: %d.\n", D->V[D->first]);
}

