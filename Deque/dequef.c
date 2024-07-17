#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

#include "dequef.h"


/**
   Create an empty deque of floats.

   capacity is both the initial and minimum capacity.
   factor is the resizing factor, larger than 1.0.

   On success it returns the address of a new dequef.
   On failure it returns NULL.
**/
dequef* df_alloc(long capacity, double factor) {
   if (capacity <= 0 || factor <= 1.0)
      return NULL;

   dequef* deque = (dequef*) malloc(sizeof(dequef));
   deque->data = (float*) malloc(capacity * sizeof(float));

   deque->first = deque->size = 0;
   deque->cap = deque->mincap = capacity;
   deque->factor = factor;

   return deque;
}



/**
  Release a dequef and its data.
**/
void df_free(dequef* D) {
   free(D->data);
   free(D);
}



/**
   The size of the deque.
**/
long df_size(dequef* D) {
   return D->size;
}


/**
 
 **/
int df_resize(dequef* D, long new_cap) {
   if (new_cap < D->cap)
      new_cap = D->cap;
   
   float* new_data = (float*) malloc(new_cap * sizeof(float));
   for (long i = 0; i < D->size; i++) 
      new_data[i] = D->data[(D->first + i) % D->cap];
   
   free(D->data);
   D->data = new_data;
   D->first = 0;
   D->cap = D->mincap = new_cap;

   return 1;      
}



/**
   Add x to the end of D.

   If the array is full, it first tries to increase the array size to
   capacity*factor.

   On success it returns 1.
   If attempting to resize the array fails then it returns 0 and D remains unchanged.
**/
int df_push(dequef* D, float x) {
   if (D->size == D->cap) {
      if (df_resize(D, D->cap * D->factor) == 0)
         return 0;
   }

   D->data[(D->first + D->size) % D->cap] = x;
   D->size++;

   return 1;
}



/**
   Remove a float from the end of D.

   If the deque has capacity/(factor^2) it tries to reduce the array size to
   capacity/factor.  If capacity/factor is smaller than the minimum capacity,
   the minimum capacity is used instead.  If it is not possible to resize, then
   the array size remains unchanged.

   This function returns the float removed from D.
   If D was empty prior to invocation, the returned float is meaningless.
**/
float df_pop(dequef* D) {
   float data = D->data[(D->first + D->size - 1) % D->cap];
   D->size--;

   if (D->size < D->cap / (D->factor * D->factor)) {
      long newCap = (long) (D->cap / D->factor);
      if (newCap < D->mincap)
         newCap = D->mincap;
      
      df_resize(D, newCap);
   }

   return data;
}



/**
   Add x to the beginning of D.

   If the array is full, it first tries to increase the array size to
   capacity*factor.

   On success it returns 1.
   If attempting to resize the array fails then it returns 0 and D remains unchanged.
**/
int df_inject(dequef* D, float x) {
   if (D->size == D->cap) {
      if (df_resize(D, D->cap * D->factor) == 0)
         return 0;
   }

   D->first = (D->first - 1 + D->cap) % D->cap;
   D->data[D->first] = x;
   D->size++;

   return 1;
}



/**
   Remove a float from the beginning of D.

   If the deque has capacity/(factor^2) elements, this function tries to reduce
   the array size to capacity/factor.  If capacity/factor is smaller than the
   minimum capacity, the minimum capacity is used instead.

   If it is not possible to resize, then the array size remains unchanged.

   This function returns the float removed from D.
   If D was empty prior to invocation, the returned float is meaningless.
**/
float df_eject(dequef* D) {
   float data = D->data[D->first];
   D->first = (D->first + 1) % D->cap;
   D->size--;

   if (D->size < D->cap / (D->factor * D->factor)) {
      long newCap = (long) (D->cap / D->factor);
      if (newCap < D->mincap)
         newCap = D->mincap;
      
      df_resize(D, newCap);
   }

   return data;
}



/**
   Set D[i] to x.

   If i is not in [0,|D|-1]] then D remains unchanged.
**/
void df_set(dequef* D, long i, float x) {
   if (i < 0 || i >= D->size)
      return;

   long index = (D->first + i) % D->cap;
   D->data[index] = x;
}



/**
   Return D[i].

   If i is not in [0,|D|-1]] the returned float is meaningless.
**/
float df_get(dequef* D, long i) {
   if (i < 0 || i >= D->size)
      return 0.0;

   long index = (D->first + i) % D->cap;
   return D->data[index];
}



/**
   Print the elements of D in a line.
**/
void df_print(dequef* D) {
   printf("deque (%ld): ", D->size);
   for (long i = 0; i < D->size; i++)
      printf("%.1f ", df_get(D, i));
   
   printf("\n");
}
