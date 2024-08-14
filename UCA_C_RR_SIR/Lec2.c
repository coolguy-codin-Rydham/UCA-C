#include <stdio.h>

void numOfOddOccurrenceElements(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[arr[i]] *= -1;
    }

    for (int i = 0; i < n; i++)
    {
        if(arr[i]<0)printf("%d ", i);
    }
}

int main()
{
    int arr[] = {1, 2, 2, 3, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    numOfOddOccurrenceElements(arr, n);

    return 0;
}