#include <stdio.h>

int singleNumber(int* nums, int numsSize) {
    int xorNums = 0;
    for(int i=0; i<numsSize; i++){
        xorNums = xorNums^(nums[i]);
    }
    return xorNums;
}

int main(){


    return 0;
}