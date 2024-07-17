#include "bintree.h"

int main (void) {
    tree_node* tree;
    int vec_size;
    while (1) {
        tree = NULL;
        scanf("%d", &vec_size);
        if (vec_size <= 0)
            break;

        int V[vec_size];
        for (int i = 0; i < vec_size; i++)
            scanf("%d", &V[i]);

        tree = insert_tree(V, tree, 0, vec_size);
        
        euler_walk(tree);
        destroy_tree(tree);
        printf("\n");
    }
}