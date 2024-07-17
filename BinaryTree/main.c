#include "bintree.h"

int main (void) {
    tree_node* tree = NULL;

    int number;
    char command[15];
    printf("\nDigite o comando dentre os listados:\n");
    options();
    while (1) {
        fgets(command, 15, stdin);
        if (strstr(command, "inserir")) {
            tree = insertion(tree);
        } else if (strstr(command, "remover")) {
            tree = removal(tree);
        } else if (strstr(command, "info_tree")) {
            info_tree(tree);
        } else if (strstr(command, "procurar")) {
            search_tree(tree);
        } else if (strstr(command, "finalizar")) {
            delete_tree(tree);
            break;  
        } else if (strstr(command, "sucessor")) {   
            successor_info(tree);
        } else if (strstr(command, "predecessor")) {   
            predecessor_info(tree);
        } else if (strstr(command, "impressao")) {
            print_tree(tree);
        } else if (strstr(command, "opcoes")) {
            options();
        } else if (strstr(command, "same_tree")) {
            tree_node* T2 = NULL;
            T2 = insert_tree(T2, 22);
            T2 = insert_tree(T2, 44);
            T2 = insert_tree(T2, 223);
            T2 = insert_tree(T2, 54);
            T2 = insert_tree(T2, 34);
            T2 = insert_tree(T2, 65);
            T2 = insert_tree(T2, 765);
            T2 = insert_tree(T2, 12);
            printf("IMPRESSAO 2D DE T2.\n");
            print_2D(T2);
            int flag = same_tree(tree, T2, 1);
            if (flag == 1)
                printf("As árvore são iguais.\n");
            else
                printf("As árvore são diferentes.\n");
        } else if (strstr(command, "sec_max")) {
            tree_node* sec_max = second_max(tree);
            int ver = in_order_verification(tree);
            if (ver == 1)
                printf("É uma árvore de busca binária.\n");
            else
                printf("Não é uma árvore de busca binária.\n");
            if (sec_max == NULL)
                printf("A árvore está vazia.\n");
            else 
                printf("O segunda maior elemento da árvore é %d.\n", sec_max->data);
        } else {
            printf("Comando inválido, tente novamente.\n");
        }
    }
}