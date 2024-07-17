#ifndef HASH_H
#define HASH_H
#include <stdio.h>
#include <stdlib.h>


typedef struct T_element {
    int key;
}T_element;


typedef struct hash_table {
    T_element* table;
    int size;
    int count;
} hash_table;


hash_table* create_table(int m);

void insert_htable(hash_table* T, int key);
int double_hash(int k, int i, int m);
int h2 (int k, int m);
int h1 (int k, int m);
int quad_hash(int k, int i, int m, int c1, int c2);
int unitary_hash(int k, int i, int m);


#endif