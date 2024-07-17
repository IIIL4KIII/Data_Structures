#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node* next, *prev;
} node;

typedef struct linked_list {
    node* head, *tail;
} llist;


node* create_node(int key);


llist* create_list(void);
llist* copy_list (llist* L);


void insert(llist* L, int key);
void remove_list (llist* L, int key);
void order_remotion(llist* L1, llist* L2);
void index_remotion(llist* L, int index);
void print_list(llist* L);
void insert_tail (llist* L, int key);



#endif