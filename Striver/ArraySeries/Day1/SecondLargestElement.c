#include <stdio.h>
#include <limits.h>

int largest(int arr[], int size){
    int large = INT_MIN;

    for(int i=0; i<size; i++){
        if(arr[i]>large){
            large = arr[i];
        }
    }
    return large;
}

int secondLargestNumber(int arr[], int size){
    int secondLargest = INT_MIN;
    int large = largest(arr, size);

    for(int i=0; i<size; i++){
        if(arr[i]>secondLargest && arr[i]<large){
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}

int main(){
    int arr[] = {1};
    int size = sizeof(arr)/sizeof(arr[0]);
    int secondLargestElement = secondLargestNumber(arr, size);
    if(secondLargestElement == INT_MIN) {
        return -1;
    }
    printf("%d\n", secondLargestElement);

    return 0;
}