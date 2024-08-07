#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <assert.h>

void merge(int arr[], int n, int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int *L = (int *)malloc(sizeof(int) * n1);
    int *R = (int *)malloc(sizeof(int) * n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[start + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }

    free(L);
    free(R);
}

void mergeSort(int arr[], int n, int start, int end) {
    if (start >= end) return;
    int mid = start + (end - start) / 2;

    mergeSort(arr, n, start, mid);
    mergeSort(arr, n, mid + 1, end);
    merge(arr, n, start, mid, end);
}

void selection_sort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void helper() {
    int n = 1280000;
    int *arr = (int *)malloc(n * sizeof(int));

    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }

    struct timeval before;
    gettimeofday(&before, NULL);
    long long before_millis = before.tv_sec * 1000LL + before.tv_usec / 1000;

    // mergeSort(arr, n, 0, n - 1);
    // selection_sort(arr, n);
    quick_sort(arr, n, 0, n-1);
    struct timeval after;
    gettimeofday(&after, NULL);
    long long after_millis = after.tv_sec * 1000LL + after.tv_usec / 1000;

    printf("Time taken to sort the array: %lld ms\n", after_millis - before_millis);

    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
}

int main() {
   helper();
    return 0;
}
