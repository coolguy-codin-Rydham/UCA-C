#include <stdio.h>
#include <assert.h>
#include <sys/time.h>
#include <stdlib.h>
#include <time.h>

void exch(int arr[], int i, int j){
  int temp = arr[i];
  arr[i]=arr[j];
  arr[j]=temp;
}

void quick_sort_recursive(int arr[], int left, int right){
  if(left>=right)return;

  int pivot = arr[left];
  int i= left+1;
  for(int j=left+1;j<=right;j++){
    if(arr[j] < pivot) exch(arr, i++, j);
  }
  exch(arr, left, --i);
  quick_sort_recursive(arr, left, i-1);
  quick_sort_recursive(arr, i+1, right);

}

void quick_sort(int arr[], int n){
  quick_sort_recursive(arr, 0, n-1);
}

long long time_elapsed(int n)
{
    int *arr = (int *)malloc(n * sizeof(int));

    srand(time(NULL));

    for(int i=0;i<n;i++) arr[i] = rand();

    struct timeval before;
    gettimeofday(&before, NULL);
    long long before_millis = before.tv_sec*1000LL + before.tv_usec/1000;

    // selection_sort(arr, n);
    quick_sort(arr, n);

     struct timeval after;
    gettimeofday(&after, NULL);
    long long after_millis = after.tv_sec*1000LL + after.tv_usec/1000;

    free(arr);

    return after_millis-before_millis;


}
long long time_elapsed_worst_case(int n)
{
    int *arr = (int *)malloc(n * sizeof(int));

    // srand(time(NULL));

    for(int i=n-1;i>0;i--) arr[i] = i;

    struct timeval before;
    gettimeofday(&before, NULL);
    long long before_millis = before.tv_sec*1000LL + before.tv_usec/1000;

    // selection_sort(arr, n);
    quick_sort(arr, n);

     struct timeval after;
    gettimeofday(&after, NULL);
    long long after_millis = after.tv_sec*1000LL + after.tv_usec/1000;

    free(arr);

    return after_millis-before_millis;


}


void test_sample_input(){
    int arr[] = {5, 3, 1, 9, 7};
    int expected_output[] = {1, 3, 5, 7, 9};
    // selection_sort(arr, 5);
    quick_sort(arr, 5);
    for(int i=0;i<5;i++){
        assert(arr[i]==expected_output[i]);
    }
    printf("Success");
}


int main(){

// test_sample_input();


    long long t1 = time_elapsed(32000);
    long long t2 = time_elapsed(64000);

    printf("%f\n", t2*1.0/t1);

    long long t3 = time_elapsed(32000);
    long long t4 = time_elapsed(64000);

    printf("%f", t4*1.0/t3);



  return 0;
}
