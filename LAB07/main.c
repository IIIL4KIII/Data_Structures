#include "list.h"

int main (void) {
    int numberOfNodes;
    scanf("%d", &numberOfNodes);
    LinkedList* list = createList();

    int data;
    for (int i = 0; i < numberOfNodes; i++) {
        scanf("%d", &data);
        insert(list, data);
    }
    printList(list);

    int numberOfSearches;
    scanf("%d", &numberOfSearches);

    node* lastVisit;
    int position;
    for (int i = 0; i < numberOfSearches; i++) {
        scanf("%d", &position);
        if (i == 0) 
            lastVisit = fastestChoice(list, NULL, position);
        else
            lastVisit = fastestChoice(list, lastVisit, position);
    }

    destroy(&list);

}