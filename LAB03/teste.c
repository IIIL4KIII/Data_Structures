#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// Transforma o vetor em letras minusculas
char* LOWER (char* V) {
    for (int i = 0; V[i] != '\0'; i++)
        *(V + i) = tolower(*(V + i));

    return V;
}

// Encontra o maior elemento do vetor
int maximum (int* Vector, int size) {
    int max = Vector[0];
    for (int i = 1; i < size; i++) {
        if (max < Vector[i]) {
            max = Vector[i];
        }
    }

    return max;
}


int main (void) {
    int numberOfkeywords = 0, numberOfExcuse = 0, excuseSet = 1;

    while (scanf("%i %i", &numberOfkeywords, &numberOfExcuse) != EOF) {
        char keyword[numberOfkeywords][21];
        char phrase[numberOfExcuse][101];

        getchar();

        for (int i = 0; i < numberOfkeywords; i++) 
            scanf("%s", keyword[i]);
        
        getchar();
        
        int count[numberOfExcuse];
        for (int i = 0; i  < numberOfExcuse; i++)
            count[i] = 0;
        
        // Procura pela palavra chave transformando a desculpa em letras minuscula.
        for (int i = 0; i < numberOfExcuse; i++) {
            fgets(phrase[i], 101, stdin);
            char actualPhrase[101];
            strcpy(actualPhrase, phrase[i]);
            for (int j = 0; j < numberOfkeywords; j++) {
                char* flag = LOWER(actualPhrase);
                // Verifica se ha palavras repetidas.
                while (flag) {
                    flag = strstr(flag, keyword[j]);

                    if (flag != NULL) {
                        count[i] += 1;
                        flag++;
                    }

                }
            }
        }

        printf("Conjunto de desculpas #%i\n", excuseSet);
        int max = maximum (count, numberOfExcuse);

        for (int i = 0; i < numberOfExcuse; i++) {
            if (max == count[i] && max != 0) {
                printf("%s", phrase[i]);
            }
        }

        printf("\n");
        excuseSet++;
    }
}

