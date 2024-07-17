#include "bintree.h"

tree_node* create_edge(int key) {
    tree_node* new_edge = (tree_node*) malloc(sizeof(tree_node));
    new_edge->key = key;
    new_edge->left = new_edge->right = NULL;

    return new_edge;
}


tree_node* insert_tree(int * V, tree_node* root, int start, int size) {
    if (start < size) {
        tree_node* aux = create_edge(V[start]);
        root = aux;

        root->left = insert_tree(V, root->left, 2 * start + 1, size);
        root->right = insert_tree(V, root->right, 2 * start + 2, size);
    }
    
    return root;
}


void euler_walk(tree_node* root) {
    if (root == NULL || root->key == -1) {
        return;
    }

    printf("%d ", root->key);

    if (root->left != NULL && root->left->key != -1) {
        euler_walk(root->left);
        printf("%d ", root->key);
    }

    if (root->right != NULL && root->right->key != -1) {
        euler_walk(root->right);
        printf("%d ", root->key);
    }
    
}


void destroy_tree(tree_node* root) {
    if (root == NULL)
        return;
    
    destroy_tree(root->left);
    destroy_tree(root->right);
    free(root);
}

