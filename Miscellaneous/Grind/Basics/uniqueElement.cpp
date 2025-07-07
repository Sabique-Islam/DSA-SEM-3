#include <iostream>

using namespace std;

int uniqueElement(int arr[], int size){
    int element = 0;
    for(int i=0; i<size; i++){
        element ^= arr[i]; // num^num = 0, 0^num = num
    }
    return element;
}

int main(){
    int arr[] = {1,1,2,2,3,3,4,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);

    int unique = uniqueElement(arr, size);

    cout << "Unique element --> " << unique << endl;
    
    return 0;
}