#include "Bin_search.h"


int main (void) {
    int *Vec = (int*) malloc(sizeof(int) * VEC_SIZE);
    for (int i = 0; i < VEC_SIZE; i++)
        *(Vec + i) = 2 * i;

    int* Vec_numbers = (int*) malloc(sizeof(int) * 100);

    int rand_number;

    for (int i = 0; i < 100; i++) {
        rand_number = rand() % 1000 + 1;
        *(Vec_numbers + i) = rand_number;
    }

    int is_in;
    printf("Utilizando a busca binária comum.\n");
    for (int i = 0; i < 100; i++) {
        is_in = bin_search(Vec, 0, VEC_SIZE, Vec_numbers[i]);
        if (is_in)
            printf("O elemento %d está no vetor.\n", Vec_numbers[i]);
        else 
            printf("O elemento %d não está no vetor.\n", Vec_numbers[i]);
    }

    printf("\nUtilizando a busca binária otimizada.\n");
    for (int i = 0; i < 100; i++) {
        is_in = bin_search_better(Vec, 0, VEC_SIZE, Vec_numbers[i]);
        if (is_in)
            printf("O elemento %d está no vetor.\n", Vec_numbers[i]);
        else 
            printf("O elemento %d não está no vetor.\n", Vec_numbers[i]);
    }
    
    free(Vec);
    free(Vec_numbers);
}
