#ifndef DEQUE_H
#define DEQUE_H

#include <stdio.h>
#include <stdlib.h>


typedef struct deque {
    int *V;
    int first;
    unsigned size;
    unsigned cap;
} deque;


deque* create_deque(int capacity);


void push(deque* D, int key);
void pop(deque* D);
void eject(deque* D);
void print_deque(deque* D);
void last(deque* D);
void first(deque* D);


#endif
