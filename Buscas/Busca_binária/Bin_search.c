#include "Bin_search.h"

int bin_search(int* V, int left, int right, int data) {
    if (left > right)
        return 0;

    int mean = (left + right) / 2;

    if (V[mean] == data)
        return V[mean];
    else if (data < V[mean])
        bin_search(V, left, mean - 1, data);
    else    
        bin_search(V, mean + 1, right, data);
}


int bin_search_better(int* V, int left, int right, int data) {
    if (left == right) {
        if (V[left] == data)
            return left;
        else 
            return 0;
    } else {
        int mean = (left + right) / 2 + 1;
        if (data < V[mean])
            return bin_search_better(V, left, mean - 1, data);
        else
            return bin_search_better(V, mean, right, data);
    }
}