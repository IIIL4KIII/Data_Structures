#include "hash_table.h"


int main (void) {
    char command;
    char cadeia[251];
    hash_table* T = NULL;
    while (1) {
        scanf("%c", &command);
        getchar();
        if (command == 'f') {
            break;
        } else if (command == 'c') {
            int n = 0;
            scanf("%d", &n);
            getchar();
            if (T != NULL)
                destroy_table(T);

            int size = n/0.7;           
            T = create_table(size);
        } else if (command == 'i') {
            fgets(cadeia, 251, stdin);
            cadeia[strcspn(cadeia, "\n")] = 0;
            if (T != NULL) 
                insert_element(T, cadeia, T->count); 
        } else if (command == 'b') {
            fgets(cadeia, 251, stdin);
            cadeia[strcspn(cadeia, "\n")] = 0;
            if (T != NULL) {
                int s_elemet = search(T, cadeia);
                if (s_elemet != -1)
                    printf("[%s] esta na tabela, timestamp %d\n", cadeia, s_elemet);
                else    
                    printf("[%s] nao esta na tabela\n", cadeia);
            }
        } else if (command == 'r') {
            fgets(cadeia, 251, stdin);
            cadeia[strcspn(cadeia, "\n")] = 0;
            if (T != NULL)
                remove_element(T, cadeia);
        }
    }

    destroy_table(T);
}