#include <stdio.h>
#include <stdbool.h>

bool isSorted(int arr[], int size){
    for(int i = 0; i<size-1; i++){
        if(arr[i]>arr[i+1])
            return false;
    }
    return true;
}

int main(){

    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr)/sizeof(arr[0]);
    if(isSorted(arr, size)){
        printf("Array is sorted.\n");
    } else {
        printf("Array is not sorted.\n");
    }

    return 0;
}