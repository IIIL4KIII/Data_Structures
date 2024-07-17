#include "bintree.h"

tree_node* create_tree (int data) {
    tree_node* node = (tree_node*) malloc(sizeof(tree_node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}


tree_node* insert_tree(tree_node* root, int data) {
    if (root == NULL) {
        tree_node* new_data = create_tree(data);
        root = new_data;
        return root;
    }
    
    if (data < root->data) 
        root->left = insert_tree(root->left, data);
    else 
        root->right = insert_tree(root->right, data);

    return root;
}


void pre_order (tree_node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        pre_order(root->left);
        pre_order(root->right);
    }
}


void in_order (tree_node* root) {
    if (root != NULL) {
        in_order(root->left);
        printf("%d ", root->data);
        in_order(root->right);
    }
}


void pos_order (tree_node* root) {
    if (root != NULL) {
        pos_order(root->left);
        pos_order(root->right);
        printf("%d ", root->data);
    }
}


tree_node* maximum (tree_node* root) {
    if (root == NULL || root->right == NULL)
        return root;
    return maximum(root->right);
}


tree_node* minimum (tree_node* root) {
    if(root == NULL || root->left == NULL)
        return root;
    return minimum(root->left);
}


tree_node* search(tree_node* root, int data) {
    if (root == NULL || root->data == data)
        return root;
    
    tree_node* left = search(root->left, data);
    if (left != NULL)
        return left;
    return search(root->right,data);
}


tree_node* remove_tree(tree_node* root, int data) {
    if (root == NULL)
        return root;
    else if (data < root->data) 
        root->left = remove_tree(root->left, data);
    else if (data > root->data)
        root->right = remove_tree(root->right, data);
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if (root->left == NULL) {
            tree_node* aux = root;
            root = root->right;
            free(aux);
            return root;
        } else if (root->right == NULL) {
            tree_node* aux = root;
            root = root->left;
            free(aux);
            return root;
        } else {
            tree_node* aux = minimum(root->right);
            root->data = aux->data;
            root->right = remove_tree(root->right, aux->data);
        }
    }

    return root;
}


int number_of_nodes(tree_node* root) {
    if (root == NULL)
        return 0;
    return number_of_nodes(root->left) + number_of_nodes(root->right) + 1;
}


int height_tree(tree_node* root) {
    int h_left, h_right;
    if (root == NULL)
        return 0;
    h_left = height_tree(root->left);
    h_right = height_tree(root->right);
    return 1 + (h_left > h_right ? h_left : h_right);
}


void delete_tree(tree_node* root) {
    if (root == NULL)
        return;

    delete_tree(root->left);
    delete_tree(root->right);
    free(root);
}


void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


void options(void) {
    printf("\nPara vizualizar as opções, digite \"opcao\". Os comando da árvore seguem:\n(1) inserir.\n(2) remover.\n(3) info_tree.\n(4) procurar.\n(5) impressao.\n(6) sucessor.\n(7) predecessor.\n(8) finalizar.\n\n");
}


list_node* create_list_node (tree_node* tree) {
    list_node* new_data = (list_node*) malloc(sizeof(list_node));
    new_data->tree = tree;
    new_data->next = NULL;

    return new_data;
}


void enqueue (queue* Q, tree_node* tree) {
    list_node* new_node = create_list_node(tree);

    if (Q->begin == NULL) {
        Q->begin = new_node;
        Q->end = new_node;
    } else {
        list_node* aux = Q->end;
        aux->next = new_node;
        Q->end = new_node;
    }
}


tree_node* dequeue(queue* Q) {
    if (Q->begin == NULL)
        return NULL;
    list_node* aux = Q->begin;
    tree_node* tree = aux->tree;

    Q->begin = Q->begin->next;
    if (Q->begin == NULL) 
        Q->end = NULL;
    
    return tree;
}


void kill_list(list_node* node) {
    if (node != NULL) {
        kill_list(node->next);
        free(node);
    }
}


void kill_queue (queue* Q) {
    list_node* aux = Q->begin;
    kill_list(aux);
    Q->begin = Q->end = NULL;
    free(Q);
}


void breadth (tree_node* root) {
    queue* Q = empty_queue();
    enqueue(Q, root);
    while (Q->begin != NULL) {
        tree_node* ptr = dequeue(Q);
        printf("%d ", ptr->data);
        if (ptr->left != NULL)
            enqueue(Q, ptr->left);
        if (ptr->right != NULL)
            enqueue(Q, ptr->right);
    }

    kill_queue(Q);
}


queue* empty_queue(void) {
    queue* Q = (queue*) malloc(sizeof(queue));
    Q->begin = NULL;
    Q->end = NULL;

    return Q;
}


tree_node* tree_successor(tree_node* root, tree_node* edge) {
    if (edge->right != NULL)
        return minimum(edge->right);

    tree_node* successor = NULL;
    while (root != NULL) {
        if (edge->data < root->data) {
            successor = root;
            root = root->left;
        } else if (edge->data > root->data)
            root = root->right;
        else 
            break;
    }

    return successor;
}


tree_node* tree_predecessor(tree_node* root, tree_node* edge) {
    if (edge->left != NULL)
        return minimum(edge->left);
    
    tree_node* predecessor = NULL;
    while (root != NULL) {
        if (edge->data > root->data) {
            predecessor = root;
            root = root->right;
        } else if (edge->data < root->data)
            root = root->left;
        else
            break;
    }

    return predecessor;
}


int is_complete(tree_node* root) {
    if (root == NULL)
        return 0;
    
    int h = height_tree(root);
    int n_edge = number_of_nodes(root);

    if (n_edge == (pow(2, h + 1) - 1))
        return 1;
    else
        return 0;
}


void print_left (tree_node* root) {
    if (root == NULL)
        return;

    if (root->left) {
        printf("%d ", root->data);
        print_left(root->left);
    } else if (root->right) {
        printf("%d ", root->data);
        print_left(root->right);
    }
}


void print_right (tree_node* root) {
    if (root == NULL)
        return;

    if (root->right) {
        print_right(root->right);
        printf("%d ", root->data);
    } else if (root->left) {
        print_right(root->left);
        printf("%d ", root->data);
    }
}


void print_leaves(tree_node* root) {
    if (root == NULL)
        return;

    print_leaves(root->left);
    if (root->left == NULL && root->right == NULL) 
        printf("%d ",  root->data);
    
    print_leaves(root->right);
}


void print_boundary(tree_node* root) {
    if (root == NULL)
        return;

    printf("Envoltório: [ %d ", root->data);
    print_left(root->left);
    print_leaves(root->left);
    print_leaves(root->right);
    print_right(root->right);
    printf("]\n");
}


void print_tree(tree_node* tree) {
    printf("Escolha a forma de impressão da árvore:\n(1) pre_ordem.\n(2) in_ordem.\n(3) pos_ordem.\n(4) breadth.\n(5) envoltorio.\n(6) 2D.\n");
    char command[15];
    fgets(command, 15, stdin);
    if (strstr(command, "pre_ordem")) {
        if (tree == NULL)
            printf("A árvore é vazia.\n");
        else {
            printf("Pré-Ordem: [ ");
            pre_order(tree);
            printf("]\n");
        }
    } else if (strstr(command, "in_ordem")) {
        if (tree == NULL)
            printf("A árvore é vazia.\n");
        else {
            printf("Em-Ordem: [ ");
            in_order(tree);
            printf("]\n");
        }
     } else if (strstr(command, "pos_ordem")) {
        if (tree == NULL)
            printf("A árvore é vazia.\n");
        else {
            printf("Pós-Ordem: [ ");
            pos_order(tree);
            printf("]\n");
        }
     } else if (strstr(command, "breadth")){
        if (tree == NULL)
            printf("A árvore é vazia.\n");
        else {
            printf("Breadth: [ ");
            breadth(tree);
            printf("]\n");
        }
    } else if (strstr(command, "envoltorio")) {
        if (tree == NULL)
            printf("A árvore é vazia.\n");
        else 
            print_boundary(tree);
    } else if (strstr(command, "2D")) {
        print_2D(tree);
    }
}


void print_2DUtil(tree_node* root, int space) {
    if (root == NULL)
        return;

    space += COUNT;

    print_2DUtil(root->right, space);

    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d ", root->data);

    print_2DUtil(root->left, space);
}


void print_2D(tree_node* root) {
    print_2DUtil(root, 0);
    printf("\n");
}


void info_tree(tree_node* tree) {

    printf("Informação sobre a árvore:\n");
    int yes = is_complete(tree);
    if (yes == 1)
        printf("A árvore está completa.\n");
    else if (yes == 0)
        printf("A árvore não está completa.\n");

    int n_nodes = number_of_nodes(tree);
    printf("A árvore possui %d nós\n", n_nodes);

    int height = height_tree(tree);
    printf("A árvore tem altura %d\n", height);

    tree_node* max = maximum(tree);
    if (max == NULL)
        printf("A árvore não possui máximo.\n");
    else if (max != NULL)
        printf("máximo: %d.\n", max->data);

    tree_node* min = minimum(tree);
    if (min == NULL)
        printf("A árvore não possui mínimo.");
    else if (min != NULL)
        printf("mínimo: %d.\n", min->data);

    options();
}


tree_node* insertion(tree_node* tree) {
    printf("Para parar de inserir digite -1.\n");
    int number;
    while (1) {
        scanf("%d", &number);
        if (number == -1)
            break;
        clear_input_buffer();
        tree = insert_tree(tree, number);
    }
    printf("Inserção concluída.\n");
    getchar();

    return tree;
}


tree_node* removal(tree_node* tree) {
    printf("Para parar de remover digite -1.\n");
    int number;
    while (1) {
        scanf("%d", &number);
        if (number == -1)
            break;
        clear_input_buffer();
        tree = remove_tree(tree, number);
        if (tree == NULL)
            printf("O elemento não está na árvore.\n");
        else 
            printf("O elemento %d foi removido.\n", number);
    }
    printf("Operação remoção concluída.\n");
    getchar();

    return tree;
}   


void predecessor_info (tree_node* tree) {
    printf("Para parar de procurar o predecessor, digite -1.\n");
    int predecessor;
    while (1) {
        scanf("%d", &predecessor);
        if (predecessor == -1)
            break;
        clear_input_buffer();
        tree_node* edge = search(tree, predecessor);
        if (edge == NULL)
            printf("O elemento não está na árvore.\n");
        else {
            tree_node* pred = tree_predecessor(tree, edge);
            if (pred == NULL)
                printf("O elemento não tem sucessor !\n");
            else
                printf("O predecessor do elemento %d é %d.\n", predecessor, pred->data);
        }
    }

    printf("Operação predecessor concluída.\n");
    getchar();
}


void successor_info(tree_node* tree) {
    printf("Para parar de procurar o sucessor, digite -1.\n");
    int sucessor;
    while (1) {
        scanf("%d", &sucessor);
        if (sucessor == -1)
            break;
        clear_input_buffer();
        tree_node* edge = search(tree, sucessor);
        if (edge == NULL)
            printf("O elemento não está na árvore.\n");
        else {
            tree_node* succ = tree_successor(tree, edge);
            if (succ == NULL)
                printf("O elemento não tem sucessor !\n");
            else
                printf("O sucessor do elemento %d é %d.\n", sucessor, succ->data);
        }
    }
    printf("Operação sucessor concluída.\n");
    getchar();
}


void search_tree(tree_node* tree) {
    printf("Para parar de procurar digite -1\n");
    int number;
    while (1) {
        scanf("%d", &number);
        if (number == -1)
            break;
        clear_input_buffer();
        tree_node* search_node = search(tree, number);
        if (search_node == NULL)
            printf("O valor %d não foi encontrado.\n", number);
        else
            printf("O valor %d foi encontrado.\n", search_node->data);
    }
    printf("As buscas foram concluídas.\n");
    getchar();
}


int same_tree(tree_node* T1, tree_node* T2, int same) {
    if (T1 != NULL && T2 != NULL && same == 1) {
        same = same_tree(T1->left, T2->left, 1);
        printf("T1: %d, T2: %d.\n", T1->data, T2->data);
        if (T1->data != T2->data)
            same = 0;
        same = same_tree(T1->right, T2->right, same);
        return same;
    }

    if (same != 0)
        return 1;
    else 
        return 0;
}


tree_node* second_max(tree_node* root) {
    if (root == NULL || root->right->right == NULL)
        return root;
    return second_max(root->right);
}


int in_order_verification(tree_node* root) {
    int p;
    if (root != NULL) {
        if (root->left != NULL && root->left->data > root->data)
            return 0;
        if (root->right != NULL && root->right->data < root->data)
            return 0;
        p = in_order_verification(root->left);
        p = in_order_verification(root->right);
        return 1;
    }

    return p;
}