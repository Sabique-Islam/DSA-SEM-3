#include <stdio.h>
#include <limits.h>

/*

A leader in an array is an element whose value is strictly greater than all elements to its right in the given array. 
The rightmost element is always a leader.
The elements in the leader array must appear in the order they appear in the nums array.

*/

//Not working

int* leader(int arr[], int size){
    int max = INT_MIN;
    int index = 0;
    int leaderArr[size];
    for(int i=size-1; i>=0; i--){
        if(arr[i] > max){
            leaderArr[i] = arr[i];
            max = arr[i];
        }
    }
    return leaderArr;
}

int main(){
    int arr[] = {1, 2, 5, 3, 1, 2};
    int size = sizeof(arr)/sizeof(arr[0]);
    int* answer = leader(arr, size);

    for(int i=0; i<size; i++){
        printf("%d ", answer[i]);
    }
    printf("\n");

    return 0;
}