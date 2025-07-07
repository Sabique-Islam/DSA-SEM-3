#include <iostream>
using namespace std;

void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector <int> arrIntersection(vector <int> &arr1, int n, vector <int> &arr2, int m){
    vector <int> intersection;
    int i = 0, j = 0;

    while(i < n && j < m){
        if(arr1[i] == arr2[j]){
            intersection.push_back(arr1[i]);
            i++;
            j++;
        } else if(arr1[i] < arr2[j]){
            i++;
        } else {
            j++;
        }
    }

    return intersection;
}

int main(){
    vector <int> arr1 = {1, 2, 3, 4, 5};
    vector <int> arr2 = {3, 4, 5, 6, 7};

    int n = arr1.size();
    int m = arr2.size();

    vector <int> intersection = arrIntersection(arr1, n, arr2, m);
    
    cout << "Intersection of the arrays: ";
    printArray(intersection.data(), intersection.size());

    return 0;
}