#include "deque.h"

int main (void) {
    deque* D = create_deque(12);
    push(D, 12);
    push(D, 34);
    push(D, 56);
    push(D, 76);
    push(D, 67);
    push(D, 92);
    push(D, 89);

    print_deque(D);

    pop(D);
    pop(D);

    print_deque(D);

    eject(D);
    eject(D);

    print_deque(D);
    first(D);
    last(D);
}