#include "tree.h"

int main(void) {
    node* root = NULL;
    int size, data;
    scanf("%d", &size);
    for(int i = 0; i < size; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }

    preOrder(root);
    printf("\n");
}