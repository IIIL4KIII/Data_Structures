#include "list.h"

// Realiza a criacao da lista
LinkedList* createList(void) {
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;

    return list;
}

// Cria um no
node* createNode(int data) {
    node* newData = (node*) malloc(sizeof(node));
    newData->data = data;
    newData->next = NULL;
    newData->previos = NULL;

    return newData;
}

// Insere no fim
void insert(LinkedList* list, int data) {
    node* newData = createNode(data);

    if (list->head == NULL) {
        list->head = list->tail = newData;
        newData->index = 0;
    } else {   // Coloca diretamente no fim utilizando o rabo, sem necessitar percorrer toda lista
        node* aux = list->tail;
        newData->index = aux->index + 1;
        newData->previos = aux;
        aux->next = newData;
        list->tail = newData;
    }
}

// Imprime os elementos dos vetores
void printList(LinkedList* list) {
    for(node* aux = list->head; aux != NULL; aux = aux->next) 
        printf("%d ", aux->data);

    printf("\n");
}

// Procura o elemento a partir do comeco da lista
node* beginningSearch(LinkedList* list, int position) {
    node* aux = list->head;
    int count = 1;
    for (; aux->next != NULL && aux->index != position; aux = aux->next, count++);

    printf("%d %d\n", aux->data, count);

    return aux;
}

// Procura o elemento a partir do final da lista
node* endingSearch(LinkedList* list, int position) {
    node* aux = list->tail;
    int count = 1;
    for(; aux->previos != NULL && aux->index != position; aux = aux->previos, count++);

    printf("%d %d\n", aux->data, count);

    return aux;
}

// Procura o elemento a partir do ultimo no encontrado
node* lastNodeSearch(node* Node, int position) {
    node* aux = Node;
    int count = 1;

    if (aux->index <= position) { // Vai para direita
        for (; aux->next != NULL && aux->index != position; aux = aux->next, count++);
        printf("%d %d\n", aux->data, count);
        return aux;
    } else {
        for (; aux->previos != NULL && aux->index != position; aux = aux->previos, count++);
        printf("%d %d\n", aux->data, count);
        return aux;
    }

}

// Decisao de onde comecar a busca na lista a partir da diferenca entre os pontos
node* fastestChoice(LinkedList* list, node* Node, int position) {
    node* aux = Node, *lastNode = list->tail;

    int endDistance = lastNode->index - position;
    if (Node == NULL) {
        if (position >= endDistance)
            aux = endingSearch(list, position);
        else
            aux = beginningSearch(list, position);
    } else {
        int nodeDistance;
        nodeDistance = abs(aux->index - position);

        if (position <= endDistance && position <= nodeDistance)
            aux = beginningSearch(list, position);
        else if (endDistance <= position && endDistance <= nodeDistance)
            aux = endingSearch(list, position);
        else 
            aux = lastNodeSearch(aux, position);
    }

    return aux;
}

// Destri a lista
void destroy(LinkedList** list) {
    LinkedList *L = *list;

    node* pointer = L->head;
    node* aux = NULL;

    while (pointer != NULL) {
        aux = pointer;
        pointer = pointer->next;
        free(aux);
    }

    free(L);

    *list = NULL;
}