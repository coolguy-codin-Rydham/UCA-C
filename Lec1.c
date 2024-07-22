#include <stdio.h>
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

void test_sample_input(){
    int arr[] = {5, 3, 1, 9, 7};
    int expected_output[] = {1, 3, 5, 7, 9};

    selection_sort(arr, 5);

    for(int i=0;i<5;i++)assert(arr[i]==expected_output[i]);

    printf("Success");
}


int main()
{
    test_sample_input();
    return 0;
}