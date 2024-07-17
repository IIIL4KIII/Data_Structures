#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// Transforma o vetor em letras minusculas
void toLower(char *str) {
    while (*str != '\0') {
        *str = tolower(*str);
        str++;
    }
}


int main (void) {
    int numberOfkeywords = 0, numberOfExcuse = 0, excuseSet = 1;

    while (scanf("%i %i", &numberOfkeywords, &numberOfExcuse) != EOF) {
        char keyword[numberOfkeywords][21];
        char phrase[numberOfExcuse][101];

        getchar();

        for (int i = 0; i < numberOfkeywords; i++) 
            fgets(keyword[i], 21, stdin);

        for (int i = 0; i < numberOfkeywords; i++)
            keyword[i][strlen(keyword[i]) - 1] = '\0';
        
        int count[numberOfExcuse];
        for (int i = 0; i  < numberOfExcuse; i++)
            count[i] = 0;
        
        // Procura pela palavra chave transformando a desculpa em letras minuscula.
        for (int i = 0; i < numberOfExcuse; i++) {
            fgets(phrase[i], 101, stdin);
            char actualPhrase[101];
            strcpy(actualPhrase, phrase[i]);
            toLower(actualPhrase);
            for (int j = 0; j < numberOfkeywords; j++) {
                char* ptr = actualPhrase;
                char* ptr2 = strstr(ptr, keyword[j]);
                while ((ptr = strstr(ptr, keyword[j])) != NULL) {
                    if (isalpha(*(ptr + strlen(keyword[j]))) != 2 && isalpha(*(ptr2 - 1)) != 2) {
                        ptr2 = strstr(ptr, keyword[j]);
                        count[i]++;
                        ptr++;
                    } else {
                        ptr++;
                    }
                }
            }
        }

        printf("Conjunto de desculpas #%i\n", excuseSet);
        int max = 0;
        for (int i = 0; i < numberOfExcuse; i++) {
            if (count[i] > max) {
                max = count[i];
            }
        }

        for (int i = 0; i < numberOfExcuse; i++) {
            if (max == count[i] && max != 0) {
                printf("%s", phrase[i]);
            }
        }

        printf("\n");
        excuseSet++;
    }

    return 0;
}

