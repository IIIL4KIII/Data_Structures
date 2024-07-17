#include "linked_list.h"


int main (void){ 
    llist* L = create_list();

    insert(L, 25);
    insert(L, 43);
    insert(L, 454);
    insert(L, 657);
    insert(L, 56);
    insert(L, 78);
    insert(L, 34);

    node* aux = L->head;
    print_list(L);

    remove_list(L, 43);
    print_list(L);


    llist* L1 = create_list(), * L2 = create_list();
    insert_tail(L1,1);
    insert_tail(L1,2);
    insert_tail(L1,3);
    insert_tail(L1,4);
    insert_tail(L1,5);
    print_list(L1);
    insert_tail(L2,2);
    insert_tail(L2,4);
    insert_tail(L2,8);
    print_list(L2);

    order_remotion(L1, L2);

    print_list(L1);



}