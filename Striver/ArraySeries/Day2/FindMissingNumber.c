#include <stdio.h>

int missingNumber(int* nums, int numsSize) {
    int xorN = 0, xorNums = 0;
    for(int i=0; i<numsSize; i++){
        xorNums = xorNums^(nums[i]);
        xorN = xorN^(i);
    }
    xorN = (xorN)^(numsSize);
    return xorN^xorNums;
}

int main(){


    return 0;
}