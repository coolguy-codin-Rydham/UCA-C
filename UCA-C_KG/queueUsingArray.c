#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include "queue.h"

int *array;
int N = 0;
int max_size = 1;
int curr = 0;

void resize_array(){
   int *new_array = (int *)malloc(sizeof(int)*max_size);
   int *temp = array;
   for(int i=0;i<N-curr;i++) new_array[i] = array[i+curr];
   array = new_array;
   N=N-curr;
   curr =0;
   free(temp);
}

void push ( int n )  {
   if(N==0) array = (int *)malloc(sizeof(int)*max_size);
   if(N-curr==max_size) {
      max_size *= 2;
      resize_array();
   }
   array[N++] = n;
}

int pop(){
   if(N==curr){
      printf("Queue is Empty\n");
      return INT_MIN;
   }
   int item = array[curr++];

   if(N-curr<=max_size/4 && max_size>1){
      max_size /=2;
      resize_array();
   }
   return item;
}

bool isEmpty(){
   return N==curr;
}

int size(){
   return N-curr;
}

void printArray(){
   for(int i=curr;i<N;i++){
      printf("%d ", array[i]);
   }
   printf("\n");
}

int main(){

   push(8);
   push(9);
   pop();
   push(10);

   printArray();

   return 0;

}

