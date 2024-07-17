#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void) {
    int nElements;
    scanf("%d ", &nElements);
    int Rsize = ceil(sqrt(nElements));
    int S[nElements], R[Rsize];

    // Lendo alocando os inteiros em um novo vetor.
    for (int i = 0; i < nElements; i++) {
        scanf("%d", &S[i]);
    }

    // Setando o vetor de contagem para zero.
    for (int i = 0; i < Rsize; i++)
        R[i] = 0;

    // Calculando as somas de R.
    for(int i = 0; i < Rsize; i++) {
        for (int r = 0; r < Rsize && i*Rsize + r < nElements; r++) {
            R[i] += S[i*Rsize + r];
        }
    }

    int left, right;
    char command;

    // Analisa os commandos e chama a funcao se necessario
    while (scanf("%c %d %d", &command, &left, &right) != EOF) {
        if (command == 's') {
            int sum = 0;
            sum = Sum(S, R, left, right, Rsize);
            printf("%d\n", sum);
        } else if (command == 'a') {
            S[left] = right;
            int blockPosition = left / Rsize;
            R[blockPosition] = 0;
            for (int r = 0; r < Rsize && blockPosition*Rsize + r < nElements; r++) {
                R[blockPosition] += S[blockPosition*Rsize + r];
            }
        }
    }

}