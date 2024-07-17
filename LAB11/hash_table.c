#include "hash_table.h"

unsigned long djb2 (unsigned char* str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++)) 
        hash = ((hash << 5) + hash) ^ c;
    
    return hash;
}


hash_table* create_table (int m) {
    hash_table* T = (hash_table*) malloc(sizeof(hash_table));       // É alocado memória para oapontador da tabela hash, que possui um apontador para apontador que é nosso vetor do tipo hash_node, e algumas informacoes sobre a tabela
    T->size = m;                                                    // informacao importante para o redimensionamento.
    T->count = 0;
    T->table =  (T_element**) calloc(m, sizeof(T_element*));          // É alocado memória para a tabela hash (vetor).
   
    // for (int i = 0; i < m; i++) 
    //     T->table[i] = NULL;                                         // Forma utilizada para deixar a tabela "vazia".
    
    return T;
}


void destroy_table(hash_table* T) {
    for (int i = 0; i < T->size; i++) {
        if (T->table[i] != NULL) {
            free(T->table[i]->str);
            free(T->table[i]);
        }
    }

    free(T->table);
    free(T);
}


int h1 (unsigned long k, int m) {                                  // h(x) = k mod m
    return k % m;
}


int h2 (unsigned long k, int m) {
    return 1 + (k % (m - 1));
}


int double_h(char* str, int i, int m) {
    unsigned long k = djb2((unsigned char*) str);
    return (h1(k, m) + i * h2(k + i, m)) % m; 
} 


void remove_element(hash_table* T, char* str) {
    for (int i = 0; i < T->size; i++) {
        int hash = double_h(str, i, T->size);
        T_element* sear_element = T->table[hash];
        if (sear_element != NULL && strcmp(sear_element->str, str) == 0) {
            free(sear_element->str);
            free(sear_element);
            T->table[hash] = NULL;
            T->count--;

            for (int j = i + 1; j < T->size; j++) {
                int next_hash = double_h(str, j, T->size);
                T_element* next_element = T->table[next_hash];
                if (next_element == NULL)
                    break;
                
                T->table[next_hash] = NULL;
                T->count--;

                insert_element(T, next_element->str, next_element->timestamp);

                free(next_element->str);
                free(next_element);
            }

            return;
        }
    }
}


void insert_element(hash_table* T, char* str, int timestamp) {
    resize_check(T);

    for (int i = 0; i < T->size; i++) {
        int hash = double_h(str, i, T->size);
        T_element* new_element = T->table[hash];

        if (new_element == NULL) {
            new_element = (T_element*) malloc(sizeof(T_element));
            new_element->str = strdup(str);
            new_element->timestamp = timestamp;
            T->table[hash] = new_element;
            T->count++;
            return;
        } else if (strcmp(new_element->str, str) == 0)
            return;
    }
}


int search (hash_table* T, char* str) {
    for (int i = 0; i < T->size; i++) {
        int hash = double_h(str, i, T->size);
        T_element* searched_elem = T->table[hash];
        
        if (searched_elem == NULL)
            return -1;
        else if (strcmp(searched_elem->str, str) == 0)
            return searched_elem->timestamp;
    }

    return -1;
}


void resize_table(hash_table* T, float factor) {
    int new_size = (int) (T->size * factor);
    if (new_size <= 0)
        new_size = 1;
    hash_table* new_table = create_table(new_size);

    for (int i = 0; i < T->size; i++) {
        T_element* element = T->table[i];
        if (element != NULL)
            insert_element(new_table, element->str, element->timestamp);
    }
    free(T->table);

    T->size = new_table->size;
    T->count = new_table->count;
    T->table = new_table->table;

    free(new_table);
}


void resize_check(hash_table* T) {
    if ((float) T->count/T->size >= 0.7) 
        resize_table(T, 1.4);
}