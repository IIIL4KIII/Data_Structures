#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct node {
    int data;
    int index;
    struct node* next;
    struct node* previos;
} node;

typedef struct LinkedList {
    node* head;
    node*tail;
} LinkedList;

LinkedList* createList(void);
node* beginningSearch(LinkedList* list, int data);
node* endingSearch(LinkedList* list, int data);
node* lastNodeSearch(node* Node, int position);
node* fastestChoice(LinkedList* list, node* Node, int data);
void insert(LinkedList* list, int data);
void printList(LinkedList* list);
void destroy(LinkedList** list);

#endif
