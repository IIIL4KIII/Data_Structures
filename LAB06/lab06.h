#ifndef LAB06_H
#define LAB06_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* previos;
} node;

typedef struct linkedList {
    node* head;
} linkedList;

node* createNode(int data);
void insertEnd (linkedList* list, int data);
void printList (linkedList* list);
void readA (linkedList* list);
void destroyList (node* list);
linkedList* createLinkedList(void);
linkedList* sublist (linkedList* list, int beginning, int ending);
linkedList* addToList (linkedList* list, int beginning, int ending, int position);

#endif