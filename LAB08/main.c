#include "tree.h"

int main(void) {
    int stop;
    scanf("%d", &stop);
    while (stop != 0) {
        int A[stop];
        for (int i = 0; i < stop; i++)
            scanf("%d", &A[i]);
        
        node* root = tree(A, 0, stop - 1);
        breadth(root);
        printf("\n");

        scanf("%d", &stop);
        killTree(root);
    }

}