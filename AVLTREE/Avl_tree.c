#include "Avl_tree.h"

tree_node* create_edge(int key) {
    tree_node* new_data = (tree_node*) malloc(sizeof(tree_node));
    if (!new_data)
        return NULL;

    new_data->key = key;
    new_data->left = new_data->right = NULL;

    return new_data;
}


int max (int a, int b) {
    return (a > b) ? a : b;
}


int tree_balance(tree_node* root) {
    if (root == NULL)
        return 0;
    
    return height(root->left) - height(root->right);
}


tree_node* right_rot(tree_node* edge) {
    tree_node* aux = edge->left;
    tree_node* aux2 = aux->right;

    aux->right = edge;
    edge->left = aux2;

    edge->height = max(height(edge->left), height(edge->right)) + 1;
    aux->height = max(height(aux->left), height(aux->right)) + 1;

    return aux;
}


tree_node* left_rot(tree_node* edge) {
    tree_node* aux = edge->right;
    tree_node* aux2 = aux->left;

    aux->left = edge;
    edge->right = aux2;

    edge->height = max(height(edge->left), height(edge->right)) + 1;
    aux->height = max(height(aux->left), height(aux->right)) + 1;

    return aux;
}


tree_node* insert_edge(tree_node* root, int key) {
    if (root == NULL) {
        tree_node* new_data = create_edge(key);
        new_data->height = 0;
        return new_data;
    }

    if (key < root->key) 
        root->left = insert_edge(root->left, key);
    else if (key > root->key)
        root->right = insert_edge(root->right, key);
    else   
        return root;

    
    root->height = 1 + max(height(root->left), height(root->right));
    int balance = tree_balance(root);

    if (balance > 1 && key < root->left->key)
        return right_rot(root);
    
    if (balance < -1 && key > root->right->key)
        return left_rot(root);

    if (balance > 1 && key > root->left->key) {
        root->left = left_rot(root->left);
        return right_rot(root);
    }

    if (balance < -1 && key < root->right->key) {
        root->right = right_rot(root->right);
        return left_rot(root);
    }
    
    return root;
}


void in_order (tree_node* root) {
    if (root != NULL) {
        in_order(root->left);
        printf("%d ", root->key);
        in_order(root->right);
    }
}


tree_node* predecessor(tree_node* root, tree_node* edge) {
    if (root->left != NULL)
        return min_edge(root->left);

    tree_node* pred = NULL;
    while (root != NULL) {
        if (edge->key > root->key) {
            pred = root;
            root = root->right;
        } else if ( edge->key < root->key)
            root = root->left;
        else
            break;
    }

    return pred;
}


tree_node* min_edge(tree_node* root) {
    if (root == NULL || root->left == NULL)
        return root;

    return min_edge(root->left);
}


tree_node* max_edge(tree_node* root) {
    if (root == NULL || root->right == NULL)
        return root;
    
    return max_edge(root->right);
}


int height(tree_node* root) {
    int h_left, h_right;
    if (root == NULL)
        return 0;
    
    h_left = height(root->left);
    h_right = height(root->right);
    return 1 + (h_left > h_right ? h_left : h_right);
}


// Ta errado
void print(tree_node* root, tree_node* origin, const char* dir) {
    if (origin != NULL)
        printf("(%d %s) ", root->key, dir);
    
    printf("%d ", root->key);
}


void in_order_mod(tree_node* root, tree_node* father, const char* dir) {
    if (root == NULL)
        return;
    
    printf("(%d pai) ", root->key);
    in_order_mod(root->left, root, "esq");
    print(root, father, dir);
    in_order_mod(root->right, root, "dir");
}


