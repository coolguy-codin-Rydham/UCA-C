#include<stdio.h>


void bubbleSort(int arr[], int n){
    for(int i=n;i>=0;i--){
        for(int j=0;j<i;j++){
	   if(arr[j]>arr[j+1]){
		   int temp = arr[j];
		   arr[j]=arr[j+1];
		   arr[j+1]=temp;
	   }
   	 }
    }	       
}

int binarySearch(int arr[], int n, int target){

    bubbleSort(arr, n);
    int start = 0;
    int end = n-1;  
    while(start<=end){
        int mid = start+(end-start)/2;

        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>target){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }


    return -1;
}




int main(){
    int arr[] = {1,4,5,2,3};

    int target = 4;

    printf("%d", binarySearch(arr, 5, target));

    return 0;


}


