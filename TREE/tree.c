#include "tree.h"

node* createTree(int data, node* left, node* right) {
    node* root = (node*) malloc(sizeof(node));
    root->data = data;
    root->left = left;
    root->right = right;

    return root;
}   

node* searchNode(node* root, int data) {
    node* left;
    if (root == NULL || root->data == data)
        return root;
    left = searchNode(root->left, data);
    if (left != NULL)
        return left;
    return searchNode(root->right, data);
}   

int search(node* root, int data) {
    if (root == NULL)
        return 0;
    else if (root->data == data)
        return 1;
    else if (data <= root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}

int numberOfNode(node* root) {
    if (root == NULL)
        return 0;
    return numberOfNode(root->left) + numberOfNode(root->right) + 1;
}

int height(node* root) {
    int hLeft, hRight;
    if (root == NULL)
        return 0;
    hLeft = height(root->left);
    hRight = height(root->right);
    return 1 + (hLeft > hRight ? hLeft : hRight);
}

void preOrder(node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void posOrder(node* root) {
    if (root != NULL) {
        posOrder(root->left);
        posOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

node* min(node* root) {
    if (root == NULL || root->left == NULL)
        return root;
    return min(root->left);
}

node* max(node* root) {
    if (root == NULL || root->right == NULL)
        return root;
    return max(root->right);
}

node* createNode(int data) {
    node* root = (node*) malloc(sizeof(node));
    root->data = data;
    root->left = root->right = NULL;
    return root;
}

node* insert(node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }

    if (data <= root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}