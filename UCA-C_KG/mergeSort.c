#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

void exch(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void merge(int arr[], int aux[], int left, int mid, int right){
    for(int k=left; k<=right;k++) aux[k] = arr[k];

    int i=left, j = mid+1;

    for(int k = left; k<=right; k++){
        if(i>mid) arr[k] = aux[j++];
        else if(j>right) arr[k] = aux[i++];
        else if(aux[i] <= aux[j]) arr[k] = aux[i++];
        else arr[k] = aux[j++];
    }

}

void merge_sort_recursive(int arr[], int aux[], int left, int right){
    if(left>=right)return ;

    int mid = left+(right-left)/2;

    merge_sort_recursive(arr, aux, left, mid);
    merge_sort_recursive(arr, aux, mid+1, right);
    merge(arr, aux, left, mid, right);
}
void merge_sort(int arr[], int n){
    int *aux = (int *)malloc(n*sizeof(int));

    merge_sort_recursive(arr, aux, 0, n-1);

    free(aux);
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
    merge_sort(arr, n);

     struct timeval after;
    gettimeofday(&after, NULL);
    long long after_millis = after.tv_sec*1000LL + after.tv_usec/1000;

    return after_millis-before_millis;


}


void test_sample_input(){
    int arr[] = {5, 3, 1, 9, 7};
    int expected_output[] = {1, 3, 5, 7, 9};
    // selection_sort(arr, 5);
    merge_sort(arr, 5);
    for(int i=0;i<5;i++){
        assert(arr[i]==expected_output[i]);
    }
    printf("Success");
}



int main(int argc, char const *argv[])
{
    long long a = time_elapsed(32000);
    long long b = time_elapsed(64000);
    long long c = b/a;

    printf("%lld", c);

    return 0;
}
