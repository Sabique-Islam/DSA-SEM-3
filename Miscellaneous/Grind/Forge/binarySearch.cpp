#include <iostream>

using namespace std;

void binarySearch(int arr[], int size, int target){
    int low = 0;
    int high = size-1;

    while(low <= high){

        int mid = (low+high)/2; // (high-low)/2 + low : "to avoid overflow"

        if(arr[mid] == target){
            cout << "Element found at index -> " << mid << endl;
            return;
        }
        else if(arr[mid] < target){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    cout << "Element not found..." << endl;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target = 5;

    binarySearch(arr, size, target);
    
    return 0;
}