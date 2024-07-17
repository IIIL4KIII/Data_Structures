#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    long int line;
    long int column;
    long long int value;
} triplet;

typedef struct {
    long int line;
    long long int value;
} tuple;

// Funcao utilizada para ordenar o vetor de structs em ordem crescente em relacao a linha e coluna.
int compare(const void* v1, const void* v2) {
    if ((*(triplet*) v1).line < (*(triplet*) v2).line)
        return -1;
    else if ((*(triplet*) v1).line > (*(triplet*) v2).line)
        return 1;
    else {
        if ((*(triplet*) v1).column < (*(triplet*) v2).column)
            return -1;
        else
            if ((*(triplet*) v1).column > (*(triplet*) v2).column)
                return 1;
            else
                return 0;
    }
}

int max(triplet * V, int size) {
    long long int maximum = V[0].line;
    for (int i = 0; i < size; i++) {
        if (V[i].line > maximum) 
            maximum = V[i].line;
    }

    return maximum;
}

int main (void) {
    int kElements;

    scanf("%i", &kElements);

    triplet* coordVec = (triplet *)malloc(kElements * sizeof(triplet));
    tuple* A = (tuple *) malloc(kElements * sizeof(tuple));
    long int* C = (long int *)malloc(kElements * sizeof(long int));

    // Verificar possíveis erros depois pois não estou inicializando os vetores iguais a zero.
    // Colocando as posicoes e valores no vetor de coordenadas o qual representa a matriz.
    for (int i = 0; i < kElements; i++)
        scanf("%li %li %lli", &coordVec[i].line, &coordVec[i].column, &coordVec[i].value);
        

    // Apesar do vetor estar ordenado, preciso verificar possiveis bugs caso algum valor da matriz seja modificado ja na entrada
    qsort(coordVec, kElements, sizeof(triplet), compare);
    // Encontra a quantidade maxima de linhas que a matriz possui.
    int m = max(coordVec, kElements) + 1;
    int* R = (int *) malloc((m + 1) * sizeof(int));

    for (int i = 0; i < kElements; i++) {
        A[i].value = coordVec[i].value;
        A[i].line = coordVec[i].line;
        C[i] = coordVec[i].column;
    }

    // Ta muito mal escrito, dar uma olhada depois || Construção do vetor R, Dependendo não precisa usar a tuple, usa long int.
    int currentRow = 0;
    R[currentRow] = 0; // Primeiro elemento da primeira linha

    for (int i = 0; i < kElements; i++) {
        while (coordVec[i].line > currentRow) {
            currentRow++;
            R[currentRow] = i; // Próximo início de linha
        }
    }
    R[m] = kElements;
    
    long int val1, val2;

    while (1) {
        scanf("%li %li", &val1, &val2);
        if(val1 == -1 && val2 == -1)
            break;
        printf("(%li,%li) = ", val1, val2);
        long long int value = 0;
        if (val1 >= 0 && val1 < m && val2 >= 1 && val2 <= C[R[val1 + 1] - 1]){
            int start = R[val1], end = R[val1 + 1] - 1;

            int low = start, high = end, mid;

            while (low <= high) {
                mid = low + (high + -low) / 2;
                if (C[mid] == val2) {
                    value = A[mid].value;
                    break;
                } 
                else if (C[mid] < val2)
                    low = mid + 1;
                else 
                    high = mid - 1;
            }
        }
        printf("%lli\n", value);
        
    }

    // Liberando a memória dos vetores.
    free(R);
    free(A);
    free(C);
    free(coordVec);
}


