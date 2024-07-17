#include "ptcn_tree.h"

/*Cria uma árvore PTCN vazia, 
se já existir uma árvore sendo processada,
todos os nós devem ser removidos.*/
tree_node* create_empty_tree(tree_node* root) {
    if (root != NULL)
        destroy_tree(root);
    
    return NULL;
}


void destroy_tree(tree_node* root) {
    if (root == NULL)
        return;
    destroy_tree(root->left);
    destroy_tree(root->right);
    free(root);
}


void in_order(tree_node* root) {
    if (root == NULL) 
        return;
    in_order(root->left);
    printf("%d ", root->key);
    in_order(root->right);   
}

/*A remoção é feita como na ABB,
sendo que a remoção de nó com dois filhos sempre usa o sucessor*/
tree_node* remove_tree(tree_node* root, int key) {
    if (root == NULL)
        return NULL;
    
    if (key < root->key)
        root->left = remove_tree(root->left, key);
    else if (key > root->key)
        root->right = remove_tree(root->right, key);
    else if (root->key == key) {
        if (root->right == NULL && root->left == NULL) {
            free(root);
            return NULL;
        } else if (root->left == NULL) {
            tree_node* aux = root;
            root = root->right;
            free(aux);
        } else if (root->right == NULL) {
            tree_node* aux = root;
            root = root->left;
            free(aux);
        } else {
            tree_node* aux = min_tree(root->right);
            root->key = aux->key;
            root->right = remove_tree(root->right, aux->key);
        }
    }

    return root;
}


tree_node* min_tree(tree_node* root) {
    if (root == NULL || root->left == NULL)
        return root;

    return min_tree(root->left);
}


tree_node* search_tree(tree_node* root, int key) {
    if (root == NULL || root->key == key)
        return root;
    
    if (key < root->key)
        return search_tree(root->left, key);
    else 
        return search_tree(root->right, key);
}

/*A inserção é feita como na ABB, a única diferença é
 a atualização dos valores da altura na volta recursiva.*/
tree_node* insert_tree(tree_node* root, int key, int timestamp) {
    if (root == NULL) {
        tree_node* new = create_edge(key, timestamp);
        return new;
    }

    if (key < root->key)
        root->left = insert_tree(root->left, key, timestamp);
    else if (key > root->key)
        root->right = insert_tree(root->right, key, timestamp);
    else
        return root;

    root->height = height(root);

    return root;
}


int PTCN(tree_node* root) {
    if (root == NULL)
        return 1;
    int bf = balance_factor(root);
    if (bf < -2 || bf > 2)
        return 0;
    return PTCN(root->left) && PTCN(root->right);
}


tree_node* create_edge(int key, int timestamp) {
    tree_node* new_edge = (tree_node*) malloc(sizeof(tree_node));
    if (new_edge == NULL) {
        printf("memoria insuficiente.\n");
        return new_edge;
    }
    new_edge->key = key;
    new_edge->height = 0;
    new_edge->timestamp = timestamp;
    new_edge->left = new_edge->right = NULL;

    return new_edge;
}


int max (int a, int b) {
    return (a > b) ? a : b;
}


int num_nodes(tree_node* root) {
    if (root == NULL)
        return 0;
    return num_nodes(root->left) + num_nodes(root->right) + 1;
}


int height(tree_node* root) {
    int h_left, h_right;
    if (root == NULL)
        return 0;
    
    h_left = height(root->left);
    h_right = height(root->right);
    
    return 1 + (h_left > h_right ? h_left : h_right);
}


int balance_factor(tree_node* root) {
    if (root == NULL)
        return 0;
    
    return height(root->left) - height(root->right);
}


int num_leaves(tree_node* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;
    else
        return num_leaves(root->left) + num_leaves(root->right);
}


