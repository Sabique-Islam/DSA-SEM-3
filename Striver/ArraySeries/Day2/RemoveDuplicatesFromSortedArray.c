#include <stdio.h>

int removeDuplicates(int arr[], int size){
    int i = 0;
    for(int j = 1; j < size; j++){
        if(arr[j] != arr[i]){
            arr[i+1] = arr[j];
            i++;
        }
    }
    return i + 1;
}

int main(){

    int arr[] = {1, 1, 2, 2, 3, 4, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int newSize = removeDuplicates(arr, size);

    printf("New Size -> %d\n", newSize);
    return 0;
}