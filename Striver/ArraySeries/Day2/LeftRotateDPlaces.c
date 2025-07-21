#include <stdio.h>

void leftRotate(int* nums, int numsSize, int k) {
    int minK = k%numsSize;
    int j = 0;
    int temp[minK];

    for(int i=0; i<minK; i++){
        temp[i] = nums[i];
    }

    for(int i=minK; i<numsSize; i++){
        nums[i-minK] = nums[i];
    }

    for(int i=numsSize-minK; i<numsSize; i++){
        nums[i] = temp[j];
        j++;
    }
}

int main(){

    int nums[] = {1, 2, 3, 4, 5};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int k = 2;
    leftRotate(nums, numsSize, k);

    for(int i=0; i<numsSize; i++){
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}