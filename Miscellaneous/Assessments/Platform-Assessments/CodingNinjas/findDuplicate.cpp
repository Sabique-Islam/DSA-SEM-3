#include <iostream>

using namespace std; 

int findDuplicate(vector<int> &arr){
    int result = 0;

    for(int i=0; i<arr.size(); i++){
        result ^= arr[i];
    }
    // bcoz array has element from 1 to n-1
    for(int i=1; i<arr.size(); i++){
        result ^= i;
    }

    return result;
}

int main(){

    vector<int> arr = {1,2,3,4,5,6,7,8,9,9};
    cout << findDuplicate(arr) << endl;

    return 0;
}