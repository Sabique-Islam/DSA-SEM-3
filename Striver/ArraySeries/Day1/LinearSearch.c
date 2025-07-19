#include <stdio.h>

int linearSearch(int arr[], int size, int target){
    for(int i=0; i<size; i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

int main(){

    int arr[] = {1, 2, 3, 3, 3};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target = 3;
    int index = linearSearch(arr, size, target);
    if(index != -1){
        printf("Element found at index: %d\n", index);
    } else {
        printf("Element not found in the array.\n");
    }
    return 0;
}