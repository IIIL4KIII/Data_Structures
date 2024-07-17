#include "lab06.h"

/*Cria um no contendo alocando espaco no heap, atribui a informacao/dados a esse no 
e faz o apontador para proximo ja ir para NULL.
*/
node* createNode(int data) {
    node* newData = (node*) malloc(sizeof(node));
    newData->data = data;
    newData->next = NULL;
    newData->previos = NULL;
    return newData;
}

// Cria uma lista vazia a qual a cabeca/comeco aponta para NULL
linkedList* createLinkedList (void) {
    linkedList* list = (linkedList*) malloc(sizeof(linkedList));
    list->head = NULL;

    return list; 
}

/* Verifica se a lista esta vazia, se sim, faz a lista apontar para esse no que eh o primeiro elemento da lista, 
senao procura pelo fim da lista/ NULL faz o ultimo elemento apontar a esse novo elemento.
*/
void insertEnd (linkedList* list, int data) {
    node* newData = createNode(data);
    if (list->head == NULL) 
        list->head = newData;
    else {
        node* auxPointer;
        for (auxPointer = list->head; auxPointer->next != NULL; auxPointer = auxPointer->next); 
        auxPointer->next = newData;
        newData->previos = auxPointer;
    }
}

void printList (linkedList* list) {
    printf("A: { ");
    for (node* auxPointer = list->head; auxPointer != NULL; auxPointer = auxPointer->next) {
        if (auxPointer->next != NULL)
            printf("%d, ", auxPointer->data);
        else
            printf("%d ", auxPointer->data);
    }
    printf("}\n");
}

// Realiza a leitura para montar a lista encadeada em relacao a entrada A.
void readA (linkedList* list) {
    while (getchar() != '{');

    int element;
    char trash;
    while (scanf("%d%c", &element, &trash) == 2) {
        insertEnd(list, element);

        if (trash == '}')
            break;
    }
}

// Da free nos nós que estão alocados na memória
void destroyList (node* list) {
    if (list != NULL) {
        destroyList (list->next);
        free(list);
    }
}

// Remove os elementos não selecionado a esquerda e a direita
linkedList* sublist (linkedList* list, int beginning, int ending) {
    node* aux = list->head;
    for(int j = 0; j < beginning && aux->next != NULL; j++)
        aux = aux->next;

    linkedList* newList = createLinkedList();
    if (beginning < ending) {
        for (int i = beginning; i < ending + 1 && aux != NULL; aux = aux->next, i++) 
            insertEnd(newList, aux->data);
    } else if (beginning > ending) {
        for (int i = ending; i < beginning + 1 && aux != NULL; aux = aux->previos, i++)
            insertEnd(newList, aux->data);
    } else 
        insertEnd(newList, aux->data);
        
    aux = list->head;
    destroyList(aux);
    list->head = NULL;
    free(list);               // Verificar possiveis bugs.

    return newList;
}

linkedList* addToList (linkedList* list, int beginning, int ending, int position) {
    node* aux = list->head;
    for (int  j = 0; j < beginning; j++)
        aux = aux->next;

    linkedList* auxList = createLinkedList();
    if (beginning < ending) {
        for (int i = beginning; i < ending + 1 && aux != NULL; aux = aux->next, i++)
            insertEnd(auxList, aux->data);
    } else if (beginning > ending) {
        for (int i = ending; i < beginning + 1 && aux != NULL; aux = aux->previos, i++)
            insertEnd(auxList, aux->data);
    } else 
        insertEnd(auxList, aux->data);

    node* auxNext = list->head;
    aux = auxNext;
    for (int  j = 0; j < position; j++){
        aux = auxNext;
        auxNext = auxNext->next;
    }
    node* auxNewListFirst = auxList->head;
    node* auxNewListLast = NULL;
    for (auxNewListLast = auxList->head; auxNewListLast->next != NULL; auxNewListLast = auxNewListLast->next);
    if (position == 0) {   //Caso seja a primeira posicao
        auxNewListLast->next = auxNext;
        auxNext->previos = auxNewListLast;
        list->head = auxNewListFirst;
    } else if (auxNext == NULL) { // Caso seja a ultima posicao
        auxNewListFirst->previos = aux;
        aux->next = auxNewListFirst;
    } else {                // Caso esteja no meio
        auxNewListFirst->previos = aux;
        aux->next = auxNewListFirst;
        auxNewListLast->next = auxNext;
        auxNext->previos = auxNewListLast;
    } 
    auxList = NULL;
    free(auxList);

    return list;
}

