#include "linked_list.h"


node* create_node(int key) {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->key = key;
    new_node->prev = new_node->next = NULL;

    return new_node;
}


llist* create_list(void) {
    llist* L = (llist*) malloc(sizeof(llist));
    L->head = L->tail = NULL;

    return L;
}


void insert(llist* L, int key) {
    node* new_node = create_node(key);
    if (L->head == NULL)
        L->head = L->tail = new_node;
    else {
        node* aux = L->head;
        new_node->next = aux;
        aux->prev = new_node;
        L->head = new_node;
    }
}


void remove_list (llist* L, int key) {
    if (L->head == NULL)
        return;
    
    node* aux = L->head;
    for (;aux != NULL && aux->key != key; aux = aux->next);

    if (aux != NULL) {      // O elemento foi encontrado.
        if (aux->prev == NULL) {    // É o primeiro elemento
            L->head = aux->next;
            free(aux);
        } else if (aux->next == NULL) {  // É o último elemento.
            L->tail = aux->prev;
            free(aux);
        } else {        // Está entre dois nós
            node* aux2 = aux->prev;
            aux2->next = aux->next;
            aux->next->prev = aux2;
            free(aux);
        }
    }
}


llist* copy_list (llist* L) {
    llist* copy = create_list();
    node* aux = L->head;
    for(; aux != NULL; aux = aux->next)
        insert(copy, aux->key);

    return copy;
}


void order_remotion(llist* L1, llist* L2) {
    node* aux = L2->head;
    for(int count = 0; aux != NULL; aux = aux->next, count++) 
        index_remotion(L1, aux->key - count);
    
}


void index_remotion(llist* L, int index) {
    if (L->head == NULL)
        return;
    
    node* aux;
    int i = 0;
    for (aux = L->head; aux != NULL && i < index - 1; i++, aux = aux->next);

    if (aux != NULL) {
        if (aux->prev == NULL) {
            L->head = aux->next;
            free(aux);
        } else if (aux->next == NULL) {
            L->tail = aux->prev;
            free(aux);
        } else {
            node* temp = aux->prev;
            temp->next = aux->next;
            aux->next->prev = temp;
            free(aux);
        }
    }
}


void print_list(llist* L) {
    node* aux;
    for (aux = L->head; aux != NULL; aux = aux->next)
        printf("%d, ", aux->key);
    printf("\n");
}


void insert_tail (llist* L, int key) {
    node* new_node = create_node(key);

    if (L->head == NULL)
        L->head = L->tail = new_node;
    else {
        node* aux;
        for (aux = L->head; aux->next != NULL; aux = aux->next);
        aux->next = new_node;
        new_node->prev = aux;
        L->tail = new_node;
    }
}
