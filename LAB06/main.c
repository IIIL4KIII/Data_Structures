#include "lab06.h"

int main (void) {
    linkedList* List = createLinkedList();
    // Leitura dos elementos da lista A
    readA(List);
    getchar();
    while (1) {
        char command;
        int firstRange, lastRange, position;
        scanf("%c ", &command);
        if (command == 's') { // Se a linha começar com s então o programa deve extrair uma sublista de A e substituir A pela sublista.
            scanf("A[%d..%d] ", &firstRange, &lastRange);
            List = sublist(List, firstRange, lastRange);
        } else if (command == '+') {
            scanf("A[%d..%d] %d ", &firstRange, &lastRange, &position);
            List = addToList(List, firstRange, lastRange, position);
        }  else if (command == 'f')
            break;

        printList(List);
    }
    node* aux = List->head;
    destroyList(aux);
    free(List);
}


