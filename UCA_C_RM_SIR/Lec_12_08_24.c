#include <stdio.h>
#include <stdlib.h>

int add(int a, int b){
    return a+b;
}

int subtract(int a, int b){
    return a-b;
}

int mul(int a, int b){
    return a*b;
}

int divide(int a, int b){
    if(b==0){
        return -1;
    }
    return a/b;
}

void performOperation(int (*operation)(int, int), int a, int b){
    printf("%d\n", operation(a, b));
}


//This way you can return an array
// int* arr(){
//     int *arry = (int *)malloc(sizeof(int)*4);

//     arry[0] = 10;
//     arry[1] = 11;
//     arry[2] = 12;
//     arry[3] = 13;

//     return arry;

// }

void sort(int arr[], int size, int (*compare)(int , int));
int compareAsc(int a, int b);
int compareDsc(int a, int b);
void printArray(int arr[], int size);

int compareAsc(int a, int b){
    return a<b;
}
int compareDsc(int a, int b){
    return a>b;
}
void sort(int arr[], int size, int (*compare)(int , int)){
    for(int i=0; i<size-1; i++){
        for(int j=i+1; j<size; j++){
            if(compare(arr[i], arr[j]) == 1){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void printArray(int arr[], int size){
    for(int i=0;i<size;i++){
        printf("%d ", arr[i]);
    }
}

typedef struct{
    
}

int main(){
    
    // int(*fun_ptr)(int, int) = NULL;

    // fun_ptr = add;
    // printf("%d\n", fun_ptr(5, 3));
    // fun_ptr = subtract;
    // printf("%d\n", fun_ptr(5, 3));
    // fun_ptr = mul;
    // printf("%d\n", fun_ptr(5, 3));
    // fun_ptr = div;
    // printf("%d\n", fun_ptr(5, 3));

    performOperation(add, 5, 3);
    performOperation(subtract, 5, 3);
    performOperation(mul, 5, 3);
    performOperation(divide, 5, 3);

    // int *myArray = arr();

    // for(int i=0;i<4;i++){
    //     printf("%d\n", myArray[i]);
    // }
    // free(myArray);

    return 0;
}