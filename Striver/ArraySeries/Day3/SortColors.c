void swap(int *num1, int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void sortColors(int* nums, int numsSize) {
    int low = 0;
    int mid = 0;
    int high = numsSize-1;

    while(mid<=high){
        if(nums[mid] == 0){
            swap(&nums[low], &nums[mid]);
            low++;
            mid++;
        }else if(nums[mid] == 1){
            mid++;
        }else if(nums[mid] == 2){
            swap(&nums[mid], &nums[high]);
            high--;
        }
    }
}