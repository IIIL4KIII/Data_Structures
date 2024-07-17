#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct element {
    char* str;
    int timestamp;
} T_element;


typedef struct hash_table {
    T_element** table;
    int size;
    int count;   
} hash_table;


unsigned long djb2 (unsigned char* str);


hash_table* create_table(int n);


void insert_element (hash_table* T, char* str, int timestamp);
void remove_element(hash_table* T, char* str);
void destroy_table(hash_table* T);
void resize_table(hash_table* T, float factor);
void resize_check(hash_table* T);

char *strdup(const char *str);


int h1 (unsigned long k, int m);
int h2 (unsigned long k, int m);
int double_h(char* str, int i, int m);
int search (hash_table* T, char* str);


#endif