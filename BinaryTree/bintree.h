#ifndef BINTREE_H
#define BINTREE_H
#define COUNT 10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct tree_node {
    int data;
    struct tree_node* right, *left;
} tree_node;


typedef struct list_node {
    tree_node* tree;
    struct list_node* next;
} list_node;


typedef struct queue {
    struct list_node* begin, *end;
} queue;


tree_node* create_tree(int data);
tree_node* insert_tree(tree_node* root, int data);
tree_node* minimum(tree_node* root);
tree_node* maximum(tree_node* root);
tree_node* search(tree_node* root, int data);
tree_node* remove_tree(tree_node* root, int data);
tree_node* dequeue(queue* Q);
tree_node* tree_successor(tree_node* root, tree_node* edge);
tree_node* tree_predecessor(tree_node* root, tree_node* edge);
tree_node* insertion(tree_node* tree);
tree_node* removal(tree_node* tree);
tree_node* second_max(tree_node* root);


queue* empty_queue(void);


void pre_order(tree_node* root);
void in_order(tree_node* root);
void pos_order(tree_node* root);
void delete_tree(tree_node* root);
void clear_input_buffer();
void options(void);
void kill_list(list_node* node);
void kill_queue(queue* list);
void breadth(tree_node* root);
void enqueue (queue* Q, tree_node* tree);
void print_left(tree_node* root);
void print_right(tree_node* root);
void print_leaves(tree_node* root);
void print_boundary(tree_node* root);
void print_tree(tree_node* root);
void info_tree(tree_node* tree);
void predecessor_info(tree_node* tree);
void successor_info(tree_node* tree);
void search_tree(tree_node* tree);
void print_2D(tree_node* root);
void print_2DUtil(tree_node* root, int space);


int height_tree(tree_node* root);
int number_of_nodes(tree_node* root);
int is_complete(tree_node* root);
int same_tree(tree_node* T1, tree_node* T2, int same);
int in_order_verification(tree_node* root);


#endif