#include "bin_tree.h"

int main (void) {
    node* T = NULL;

    T = insert(T, 24);
    T = insert(T, 43);
    T = insert(T, 76);
    T = insert(T, 98);
    T = insert(T, 34);
    T = insert(T, 654);
    T = insert(T, 45);
    T = insert(T, 65);

    in_order(T);
}