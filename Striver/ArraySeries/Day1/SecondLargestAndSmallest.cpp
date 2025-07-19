#include <iostream>
#include <vector>

using namespace std;

int secondSmallest(vector<int> &a, int n) {
    int largest = INT_MAX, secondLargest = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (a[i] < largest) {
            secondLargest = largest;
            largest = a[i];
        } else if (a[i] < secondLargest && a[i] > largest) {
            secondLargest = a[i];
        }
    }
    return (secondLargest == INT_MAX) ? -1 : secondLargest;
}

int secondLargest(vector<int> &a, int n) {
    int smallest = INT_MIN, secondSmallest = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (a[i] > smallest) {
            secondSmallest = smallest;
            smallest = a[i];
        } else if (a[i] > secondSmallest && a[i] < smallest) {
            secondSmallest = a[i];
        }
    }
    return (secondSmallest == INT_MIN) ? -1 : secondSmallest;
}

vector<int> getSecondOrderElements(int n, vector<int> a){
    int secondSmall = secondSmallest(a, n);
    int secondLarge = secondLargest(a, n);
    
    return {secondSmall, secondLarge};
}

int main(){

    vector<int> arr = {1, 2, 3, 4, 5, 8, 10, 23, 47, 100, 2, 6, 7, 7, 7, 7, 7};
    int size = arr.size();
    vector<int> result = getSecondOrderElements(size, arr);
    
    cout << "Second Smallest: " << result[0] << endl;
    cout << "Second Largest: " << result[1] << endl;
    
    return 0;
}