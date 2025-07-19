#include <stdio.h>

int largestElement(int arr[], int size){
    int largest = arr[0];
    for(int i=1; i<size; i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
    }
    return largest;
}

int main(){
    int arr[] = {1, 2, 8, 4, 5};
    int size = sizeof(arr)/sizeof(arr[0]);
    int largest = largestElement(arr, size);
    printf("%d\n", largest);

    return 0;
}