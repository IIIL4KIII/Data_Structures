#include "Avl_tree.h"

int main (void) {
    tree_node* tree = NULL;
    
    tree = insert_edge(tree, 1);
    tree = insert_edge(tree, 8);
    tree = insert_edge(tree, 4);
    tree = insert_edge(tree, 5);
    tree = insert_edge(tree, 6);
    tree = insert_edge(tree, 3);
    tree = insert_edge(tree, 9);
    
    in_order(tree);
    printf("\n");
    tree_node* min = min_edge(tree);
    printf("Menor valor: %d\n", min->key);
    in_order_mod(tree, NULL, NULL);
}