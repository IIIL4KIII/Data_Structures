#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* right, *left;
} node;

node* createTree(int data, node* left, node* right);
node* searchNode(node* root, int data);
node* createNode(int data);
node* insert(node* root, int data);
node* min(node* root);
node* max(node* root);

int numberOfNode(node* root);
int height(node* root);
int search(node* root, int data);

void preOrder(node* root);
void posOrder(node* root);
void inOrder(node* root);

#endif