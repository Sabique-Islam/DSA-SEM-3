#include <iostream>

using namespace std;

void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void altSwap(int arr[], int size){
    for(int i=0; i<size-1; i+=2){
        swap(arr[i], arr[i+1]); 
    }
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int size = sizeof(arr)/sizeof(arr[0]);

    altSwap(arr, size);
    printArray(arr, size);

    return 0;
}