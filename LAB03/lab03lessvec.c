#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char C = 'a';
    int resultado = isalpha(C);
    printf("%d\n", resultado);
}