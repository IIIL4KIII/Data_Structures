#ifndef BIN_TREE_H
#define BIN_TREE_H

#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int key;
    struct node* left, * right;
} node;

node* create_node(int key);
node* insert(node* root, int key);
node* max(node* root);
node* min(node* root);
node* predecessor(node* root, node* edge);
node* successor(node* root, node* edge);
node* search(node* root, int key);


void in_order(node* root);
void pre_order(node* root);
void pos_order(node* root);


int height(node* root);
int num_nodes(node* root);


#endif