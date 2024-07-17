#include "hash_table.h"

hash_table* create_table(int m) {
    hash_table* T = (hash_table*) malloc(sizeof(hash_table));
    T->size = m;
    T->count = 0;
    T->table = (T_element*) calloc(m, sizeof(T_element*));

    return T;
}


int h1 (int k, int m) {
    return k % m;
}

int h2 (int k, int m) {
    return 1 + (k % m);
}


int double_hash(int k, int i, int m) {
    return (h1(k, m) + i * h2(k, m)) % m;
}


int quad_hash(int k, int i, int m, int c1, int c2) {
    return (h1(k, m) + i * c1 + i * i * c2) % m;
}


int unitary_hash(int k, int i, int m) {
    return (h1(k, m) + i) % m;
}


void insert_htable(hash_table* T, int key) {
    for (int i = 0; i < T->size; i++) {
        int hash = double_hash(key, i, T->size);

        if (T->table[hash].key == 0) {
            T->table[hash].key = key;
            T->count++;
            return;
        }
    }
}

