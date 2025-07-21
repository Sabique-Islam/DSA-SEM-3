#include <stdio.h>

int maxConsecutiveOnes(int arr[], int size){
    int maxCount = 0;
    int count = 0;

    for(int i = 0; i<size; i++){
        if(arr[i]==1){
            count += 1;
        }
        else{
            count = 0;
        }
        if(count > maxCount){
            maxCount = count;
        }
    }
    return maxCount;
}

int main(){
    int arr[] = {1, 1, 0, 1, 1, 1, 0, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    int result = maxConsecutiveOnes(arr, size);
    
    printf("Maximum consecutive ones: %d\n", result);
    
    return 0;
}