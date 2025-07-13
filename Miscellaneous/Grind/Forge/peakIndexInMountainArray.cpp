#include <iostream>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr){
    int start = 0;
    int end = arr.size() - 1;
    int mid = start + (end - start)/2;

    while(start<end){
        if(arr[mid]<arr[mid+1]){
            start = mid + 1;
        }else if(arr[mid]>arr[mid+1]){
            end = mid;
        }
        mid = start + (end - start)/2;
    }
    return mid;
}

int main(){

    vector<int> arr = {0, 2, 1, 0};
    cout << "Peak Index in Mountain Array: " << peakIndexInMountainArray(arr) << endl;

    return 0;
}