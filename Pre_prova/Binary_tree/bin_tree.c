#include "bin_tree.h"

node* create_node(int key) {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->key = key;
    new_node->left = new_node->right = NULL;

    return new_node;
}


node* insert(node* root, int key) {
    if (root == NULL)
        return create_node(key);
    
    if (key < root->key) 
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    
    return root;
}


void in_order(node* root) {
    if (root == NULL)
        return;
    in_order(root->left);
    printf("%d, ", root->key);
    in_order(root->right);
}


node* max(node* root) {
    if (root == NULL || root->right == NULL)
        return root;
    return max(root->right);
}


node* min(node* root) {
    if (root == NULL || root->left == NULL)
        return root;
    return min(root->left);
}


int height (node* root) {
    int h_left, h_right;
    if (root == NULL)
        return 0;
    h_left = height(root->left);
    h_right = height(root->right);

    return 1 + (h_left > h_right ? h_left : h_right);
}


int num_nodes(node* root) {
    if (root == NULL)
        return 0;

    return num_nodes(root->left) + num_nodes(root->right) + 1;
}


node* successor(node* root, node* edge) {
    if (edge->right != NULL)
        return min(edge->right);

    node* successor = NULL;
    while(root != NULL) {
        if (edge->key < root->key) {
            successor = root;
            root = root->left;
        } else if (edge->key > root->key)
            root = root->right;
        else
            break;
    }
}


node* predecessor(node* root, node* edge) {
    if (edge->left != NULL)
        return max(edge->left);

    node* predecessor = NULL;
    while(root != NULL) {
        if (edge->key > root->key) {
            predecessor = root;
            root = root->right;
        } else if (edge->key < root->key)
            root = root->left;
        else
            break;
    }
}


void pos_order(node* root) {
    if (root == NULL)
        return;
    pos_order(root->left);
    pos_order(root->right);
    printf("%d, ", root->key);
}


void pre_order(node* root) {
    if (root == NULL)
        return;
    printf("%d, ", root->key);
    pre_order(root->left);
    pre_order(root->right);
}


node* search(node* root, int key) {
    if (root == NULL || root->key == key)
        return root;
    
    node* left = search(root->left, key);
    if (left != NULL)
        return left;

    return search(root->right, key);
}


node* remove_tree(node* root, int key) {
    if (root == NULL)
        return root;
    
    if (key < root->key)
        root->left = remove_tree(root->left, key);
    else if (key > root->key)
        root->right = remove_tree(root->right, key);
    else {
        if (root->left == NULL && root->right == NULL) 
            free(root);
        else if (root->left == NULL) {
            node* aux = root;
            root = root->right;
            free(aux);
        } else if (root->right == NULL) {
            node* aux = root;
            root = root->left;
            free(aux);
        } else {
            node* aux = min(root->right);
            root->key = aux->key;
            root->right = remove_tree(root->right, key);
        }

    }

    return root;
}


void destroy_tree (node* root) {
    if (root == NULL)
        return;

    destroy_tree(root->left);
    destroy_tree(root->right);
    free(root);
}

