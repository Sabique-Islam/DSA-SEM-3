#include <stdio.h>

int* moveZeroes(int* nums, int numsSize) {
    int j = 0;
    for(int i=0; i<numsSize; i++){
        if(nums[i]!=0){
            nums[j++] = nums[i];
        }
    }
    while (j<numsSize){
        nums[j++] = 0;
    }
    return nums;
}

int main(){
    int arr[] = {0, 1, 0, 3, 12};
    int size = sizeof(arr)/sizeof(arr[0]);
    int* result = moveZeroes(arr, size);
    printf("Array after moving zeros to the end: ");
    for(int i=0; i<size; i++){
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}