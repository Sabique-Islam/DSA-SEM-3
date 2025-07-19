#include <stdio.h>

int *leftRotate(int arr[], int size){
    int temp = arr[0];
    for(int i=1; i<size; i++){
        arr[i-1] = arr[i];
    }
    arr[size-1] = temp;
    return arr;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr)/sizeof(arr[0]);
    int *rotatedArr = leftRotate(arr, size);

    printf("Left Rotated Array: ");
    for(int i=0; i<size; i++){
        printf("%d ", rotatedArr[i]);
    }
    printf("\n");
    return 0;
}