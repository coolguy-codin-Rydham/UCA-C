#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
int mountain(int arr[], int n){
    int start = 0;
    int end = n-1;
    int ans = INT_MIN;
    while(start<=end){
        int mid = start+(end-start)/2;
        if(arr[mid-1]<arr[mid] && arr[mid+1]<arr[mid]){
            ans = mid;
            break;
        }
        else if(arr[mid]>arr[mid+1] && arr[mid]<arr[mid-1]){
            end = mid;
        }
        else if(arr[mid-1]<arr[mid] && arr[mid]<arr[mid+1]){
            start = mid;
        }
    }

    return ans;
}
int reverse(int a) {
    int rev = 0;
    bool isNegative = (a < 0); 

    if (isNegative) {
        a = -a;
    }

    while (a > 0) {
        int rem = a % 10;
        a /= 10;
        if(rev>(INT_MAX-rem)/10){
            return 0;
        }
        rev = rev * 10 + rem;
    }

    if (isNegative) {
        rev = -rev; 
    }

    return rev;
}


int main(){

    // int arr[] = {0,5,6,10,8,7,2};

    // printf("%d", mountain(arr, 7));

    int a =  -2147483647;
    printf("%d\n", reverse(a));

    return 0;

}