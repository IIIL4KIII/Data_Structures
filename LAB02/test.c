#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void) {
    int size;
    scanf("%d", &size);
    int V[size], num = 0, i = 0;
    for (int i = 0; i < size; i++) {
        scanf("%d", &V[i]);
    }
        

    printf("\n\n\n\n");
    for (int i = 0; i < size; i++)
        printf("%d ", V[i]);
}