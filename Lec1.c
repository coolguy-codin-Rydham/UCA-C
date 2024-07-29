#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <assert.h>
void exch(int arr[], int i, int j)
{
    int temp = arr[j];
    arr[j]= arr[i];
    arr[i] = temp;
}


void selection_sort(int arr[], int n)
{
    int i, j;
    for(i=0;i<n;i++)
    {
        int min = i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[i])min =j;
        }
        exch(arr, i, min);
    }
}

void print_array(int arr[], int n){
    int i;
    for(int i=0;i<n;i++) printf("%d ", arr[i]);
    
}

long long time_elapsed(int n)
{
    int *arr = (int *)malloc(n * sizeof(int));

    srand(time(NULL));

    for(int i=0;i<n;i++) arr[i] = rand();

    struct timeval before;
    gettimeofday(&before, NULL);
    long long before_millis = before.tv_sec*1000LL + before.tv_usec/1000;

    selection_sort(arr, n);

     struct timeval after;
    gettimeofday(&after, NULL);
    long long after_millis = after.tv_sec*1000LL + after.tv_usec/1000;

    return after_millis-before_millis;


}

void test_sample_input(){
    int arr[] = {5, 3, 1, 9, 7};
    int expected_output[] = {1, 3, 5, 7, 9};

    selection_sort(arr, 5);

    for(int i=0;i<5;i++)assert(arr[i]==expected_output[i]);

    printf("Success");
}


int main()
{


    // struct timeval before;
    // gettimeofday(&before, NULL);
    // long long before_millis = before.tv_sec*1000LL + before.tv_usec/1000;
    // printf("Hello");

    // struct timeval after;
    // gettimeofday(&after, NULL);
    // long long after_millis = after.tv_sec*1000LL + after.tv_usec/1000;

    // printf("Printf ran in : %llu millis seconds", after_millis-before_millis);
    // test_sample_input();


    long long t1 = time_elapsed(32000);
    long long t2 = time_elapsed(64000);

    printf("%lf", t2*1.0/t1);
    return 0;
}