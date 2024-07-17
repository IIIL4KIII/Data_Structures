#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node {
    int key;
    int height;
    struct tree_node* left, *right;
} tree_node;


tree_node* create_edge(int key);
tree_node* insert_edge(tree_node* root, int key);
tree_node* min_edge(tree_node* root);
tree_node* predecessor(tree_node* root, tree_node* edge);
tree_node* max_edge(tree_node* root);
tree_node* left_rot(tree_node* root);
tree_node* right_rot(tree_node* root);


int tree_balance(tree_node* root);
int max(int a, int b);
int height(tree_node* root);

void in_order(tree_node* root);
void print(tree_node* root, tree_node* origin, const char* dir);
void in_order_mod(tree_node* root, tree_node* father, const char* dir);

#endif