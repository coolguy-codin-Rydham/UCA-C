#include <stdio.h>
#include <stdlib.h>
int main(){
  FILE *fileptr;
  fileptr = fopen("hello.txt", "r");
  if(fileptr == NULL){
     printf("Error Opening File");
     return 1;     
  }

  return 0;
}
