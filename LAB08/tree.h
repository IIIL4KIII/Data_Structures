#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* right, *left;
} node;

typedef struct queueNode {
    node* treeNode;
    struct queueNode* next;
} queueNode;

typedef struct queue {
    struct queueNode* start, *end;
} queue;

node* createNode(int data);
node* tree(int* A, int first, int last);

queue* createQueue(void);
node* dequeue(queue* Q);


int minimum(int* A, int first, int last);

void enqueue(queue* Q, node* root);
void killQueue(queue* Q);
void breadth(node* root);
void killTree(node* root);

#endif