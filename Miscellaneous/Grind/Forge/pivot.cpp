#include <iostream>

using namespace std;

int binarySearch(int arr[], int low, int high, int target){

    while(low <= high){

        int mid = (low+high)/2; // (high-low)/2 + low : "to avoid overflow"

        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] < target){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;
}

int pivot(int arr[], int size){
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;

    while(start < end){
        if(arr[mid] >= arr[0]){
            start = mid + 1;
        }else{
            end = mid;
        }
        mid = start + (end - start) / 2;
    }
    return start; // or end
}

int findPosition(int arr[], int size, int target){
    int pivotIndex = pivot(arr, size);

    if(target >= arr[pivotIndex] && target <= arr[size-1]){ // second line
        return binarySearch(arr, pivotIndex, size-1, target);
    }
    else{ // first line
        return binarySearch(arr, 0, pivotIndex-1, target);
    }
}

int main(){
    int arr[] = {3, 4, 5, 1, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Pivot Index: " << pivot(arr, size) << endl;

    int target = 1;
    int position = findPosition(arr, size, target);
    if(position){
        cout << "Element " << target << " found at index: " << position << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }

    return 0;
}