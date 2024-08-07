#include <stdio.h>


int main(){
    int a = 130;
    int *b = &a;    // It reads 4 bytes now which is needed
    char *c = &a;  // it reads only 1 byte of memory. 


    // char* tells the compiler what to reac afterwards


    printf("%d\n\n", *b);   
    printf("%d\n\n", *c);   // this overflows

    return 0;
}