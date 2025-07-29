#include <limits.h>

int maxSubArray(int* nums, int size) {
    int sum = 0;
    int max = INT_MIN;

    for(int i=0; i<size; i++){
        sum += nums[i];
        if(sum>max){
            max = sum;
        }
        if(sum<0) sum = 0;
    }
    return max;
}