#ifndef BINTREE_H
#define BINTREE_h

#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node {
    int key;
    struct tree_node* left, * right;
} tree_node;

tree_node* create_edge(int key);
tree_node* insert_tree(int* V, tree_node* root, int start, int size);


void euler_walk(tree_node* root);
void destroy_tree(tree_node* root);


#endif