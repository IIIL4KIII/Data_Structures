#ifndef PTCN_TREE_H
#define PTCN_TREE_H
#define COUNT 10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree_node {
    int key;
    int height;
    int timestamp;
    struct tree_node* left, *right;
} tree_node;

tree_node* create_empty_tree(tree_node* root);
tree_node* create_edge(int key, int timestamp);
tree_node* min_tree(tree_node* root);
tree_node* max_tree(tree_node* root);
tree_node* remove_tree(tree_node* root, int key);
tree_node* insert_tree(tree_node* root, int key, int timestamp);
tree_node* search_tree(tree_node* root, int key);


void destroy_tree(tree_node* root);
void in_order(tree_node* root);


int height(tree_node* root);
int balance_factor(tree_node* root);
int num_nodes(tree_node* root);
int num_leaves(tree_node* root);
int PTCN(tree_node* root);



#endif