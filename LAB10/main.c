#include "ptcn_tree.h"

int main(void) {
    char command[15];
    int number;
    /*Timestamp é um inteiro que recebe valor zero quando a árvore é criada e
    é incrementado uma unidade depois de cada comando de inserir ou remover,
    sendo bem sucedido ou não*/
    int timestamp = 0;

    tree_node* tree = NULL;
    while (1) {
        scanf("%s", command);
        if (strstr(command, "terminar"))
            break;
        else if (strstr(command, "criar")) {
            tree = create_empty_tree(tree);
            timestamp = 0;
        } else if (strstr(command, "inserir")) {
            scanf(" %d", &number);
            tree_node* is_in = search_tree(tree, number);   // Se is_in != NULL, quer dizer que o elemento já está ná árvore, logo não haverá inserção.
            if (is_in == NULL) 
                tree = insert_tree(tree, number, timestamp); 
            /* Se ao inserir o elemento, a árvore deixou de ser PTCN, ou seja PTCN(tree) == 0,
            e anteriormente este elemento não estava na árvore (is_in == NULL), então ele deverá ser removido.*/
            if (PTCN(tree) == 0 && is_in == NULL)           
                tree = remove_tree(tree, number);
  
            timestamp++;
        } else if (strstr(command, "remover")) {
            scanf(" %d", &number);
            tree_node* is_in = search_tree(tree, number);
            int temp_timestamp = 0;
            if (is_in != NULL) {                    // Se o elemento não está na árvore, ela deve permanecer inalterada
                temp_timestamp = is_in->timestamp;
                tree = remove_tree(tree, number);
            }
            if (PTCN(tree) == 0 && is_in != NULL)   // Se ao remover o elemento, a árvore deixa de ser PTCN, então esse elemento deve ser inserido novamente, de forma a não deixar de ser PTCN.
                tree = insert_tree(tree, number, temp_timestamp);
            timestamp++;
        } else if (strstr(command, "buscar")) {
            scanf(" %d", &number);
            tree_node* search = search_tree(tree, number);
            if (search == NULL)
                printf("nao ha chave %d\n", number);
            else 
                printf("chave %d: inserida no tempo %d\n", number, search->timestamp);
        } else if (strstr(command, "imprimir")) {
            if (tree == NULL)
                printf("arvore vazia\n");
            else {
                printf("em-ordem: ");
                in_order(tree);
                printf("\n");
            }
        } else if (strstr(command, "info")) {
            int nodes = num_nodes(tree), leaves = num_leaves(tree), h = height(tree);
            if (h > 0)
                h = h - 1;
            printf("nos: %d, folhas: %d, altura: %d\n", nodes, leaves, h);
        }
    }

    destroy_tree(tree);
}