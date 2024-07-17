#include "tree.h"

node* createNode(int data) {
    node* root = (node*) malloc(sizeof(node));
    root->data = data;
    root->right = root->left = NULL;
    return root;
}

// Constroi a arvore a partir do menor elemento do vetor.
node* tree(int* A, int first, int last) {
    if (first > last)
        return NULL;
    
    int min = minimum(A, first, last);
    node* root = createNode(min);

    if (first == last)
        return root;

    root->left = tree(A, first, min - 1);
    root->right = tree(A, min + 1, last);

    return root;
}

// Encontra o menor elemento no vetor.
int minimum (int* A, int first, int last) {
    int min = A[first], index = first;
    for(int i = first + 1; i <= last; i++) {
        if (A[i] < min) {
            min = A[i];
            index = i;
        }
    }
    return index;
}

// Adiciona um no da arvore na fila
queue* createQueue(void) {
    queue* Q = (queue*) malloc(sizeof(queue));
    Q->start = Q->end = NULL;
    return Q;
}   

void enqueue(queue* Q, node* treeNode) {
    queueNode* newData = (queueNode*) malloc(sizeof(queueNode));
    newData->treeNode = treeNode;
    newData->next = NULL;

    if (Q->start == NULL) 
        Q->start = newData;
    else 
        Q->end->next = newData;
    
    Q->end = newData;
}

// Desinfilera e retorna o no da frente da fila
node* dequeue(queue* Q) {
    if (Q->start == NULL)
        return NULL;

    queueNode* firstQNode = Q->start;
    node* treeNode = firstQNode->treeNode;
    Q->start = Q->start->next;
    if (Q->start == NULL)
        Q->end = NULL;
    free(firstQNode);

    return treeNode;
}

// Destroi a fila utilizada para o percurso em largura.
void killQueue(queue* Q) {
    while (Q->start != NULL) {
        dequeue(Q);
    }

    free(Q);
}

// Algoritmo ensinado para percorrer a arvore em largura e imprimir os nos em nivel.
void breadth(node* root) {
    queue* Q = createQueue();
    enqueue(Q, root);
    enqueue(Q, NULL);   // Marcador de nivel

    while (Q->start != NULL) {
        node* current = dequeue(Q);
        if (current == NULL) {
            printf("\n");
            if (Q->start != NULL) 
                enqueue(Q, NULL);  // Novo marcador de nivel
        } else {
            printf("%d ", current->data);
            if (current->left != NULL) 
                enqueue(Q, current->left);
            if (current->right != NULL)
                enqueue(Q, current->right);
        }
    }
    
    killQueue(Q);
}

// Funcao para destruir a arvore binaria
void killTree(node* root) {
    if (root != NULL) {
        killTree(root->left);
        killTree(root->right);
        free(root);
    }
}