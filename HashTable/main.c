#include "hash_table.h"


int main (void) {
    hash_table* T = create_table(13);
    insert_htable(T, 32);
    insert_htable(T, 44);
    insert_htable(T, 73);
    insert_htable(T, 57);
    insert_htable(T, 65);
    insert_htable(T, 28);
    insert_htable(T, 16);
    insert_htable(T, 47);

    printf("[ ");
    for (int i = 0; i < T->size; i++)
        printf("%d, ", T->table[i].key);
    printf("]\n");
}