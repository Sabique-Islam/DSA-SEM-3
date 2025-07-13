#include <iostream>

using namespace std;

int firstOccurence(int arr[], int size, int target){
    int left = 0;
    int right = size - 1;
    int mid = left + (right - left)/2;
    int ans = -1;

    while (left<=right){
        if (arr[mid]==target){
            ans = mid;
            right = mid - 1;
        }else if (arr[mid] > target){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
        mid = left + (right - left)/2;
    }
    return ans;
}

int lastOccurence(int arr[], int size, int target){
    int left = 0;
    int right = size - 1;
    int mid = left + (right - left)/2;
    int ans = -1;

    while (left<=right){
        if (arr[mid]==target){
            ans = mid;
            left = mid + 1;
        }else if (arr[mid] > target){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
        mid = left + (right - left)/2;
    }
    return ans;
}

int occurence(int arr[], int size, int target){
    int first = firstOccurence(arr, size, target);
    if (first == -1) return 0;

    int last = lastOccurence(arr, size, target);
    return last - first + 1;
}

int main(){ 
    int arr[] = {1,2,3,3,3,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target = 3;

    int index = firstOccurence(arr, size, target);
    if (index == -1){
        cout << "Element not found..." << endl;
    }else{
        cout << "Element found at index -> " << index << endl;
    }

    index = lastOccurence(arr, size, target);
    if (index == -1){
        cout << "Element not found..." << endl;
    }else{
        cout << "Element found at index -> " << index << endl;
    }

    int count = occurence(arr, size, target);
    if (count == 0){
        cout << "Element not found..." << endl;
    }else{
        cout << "Element found " << count << " times..." << endl;
    }

    return 0;
}